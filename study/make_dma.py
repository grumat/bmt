# This script reads the DMA mapping from a CSV file and produces a header 
# file with defines.
# The script was designed to automatically produce DMA device definitions 
# for the STM32F1xxx and STM32L4xxx devices


import os
import sys
import re
import csv

#FORMAT="F1"
FORMAT="L4"

if FORMAT == "F1":
	FILE="dma_f1xx.csv"
elif FORMAT == "L4":
	FILE="dma_l4xx.csv"

PERIFS = [
	(r"(ADC)(\d\d?)",				'<pm>,s16,<d16++>'),
	(r"(AES)(\d?)_(IN)",			'pm,<s32++>,<d32>'),
	(r"(AES)(\d?)_(OUT)",			'mp,<s32>,<d32++>'),
	(r"(DAC)(\d?)_(.+)",			'pm,<s16>,<d16++>'),
	(r"(DCMI)(\d?)",				'<s>,<d>'),
	(r"(DFSDM)(\d\d?)_(FLT\d)",		'<s>,<d>'),
	(r"(HASH)(\d?)_(.+)",			'mp,<s32++>,<d32>'),
	(r"(I2C)(\d\d?)_(RX)",			'<pm>,<s8>,<d8++>'),
	(r"(I2C)(\d\d?)_(TX)",			'<mp>,<s8++>,<d8>'),
	(r"(I2S)(\d\d?)_(RX)",			'<s>,<d>'),
	(r"(I2S)(\d\d?)_(TX)",			'<s>,<d>'),
	(r"(LPUART)(\d\d?)_(RX)",		'<pm>,<s8>,<d8++>'),
	(r"(LPUART)(\d\d?)_(TX)",		'<mp>,<s8++>,<d8>'),
	(r"(QUADSPI)(\d?)",				'pm,<s8>,<d8++>'),
	(r"(SAI)(\d\d?)_(.+)",			'<s>,<d>'),
	(r"(SDIO)(\d?)",				'<s>,<d>'),
	(r"(SDMMC)(\d?)",				'<s>,<d>'),
	(r"(SPI)(\d?\d?)_(RX)",			'<pm>,<s8>,<d8++>'),
	(r"(SPI)(\d?\d?)_(TX)",			'<mp>,<s8++>,<d8>'),
	(r"(SWPMI)(\d\d?)_(.+)",		'<s>,<d>'),
	(r"(TIM)(\d\d?)_(.+)",			'<s>,<d>'),
	(r"(US?ART)(\d\d?)_(RX)",		'<pm>,<s8>,<d8++>'),
	(r"(US?ART)(\d\d?)_(TX)",		'<mp>,<s8++>,d8'),
]

class Periph:
	def __init__(self, name :str, dma :int, ch:int, sel:int) -> None:
		for r in PERIFS:
			m = re.match(r[0], name)
			if m:
				v = r[1]
				break
		if m:
			self.perif = m[1]
			self.unit = m[2] or ""
			if m.lastindex > 2:
				self.trig = m[3]
			else:
				self.trig = None
		else:
			raise Exception(1, "Unknown peripheral {0}".format(name))
		self.dma = dma
		self.ch = ch
		self.sel = sel
		self.variant = v.split(',')
		self.opt = 1
	def DmaItf(self):
		return "Itf::k"+str(self.dma)
	def DmaChan(self):
		return "Chan::k"+str(self.ch)
	def DmaSel(self):
		return "PerifSel::k"+str(self.sel)
	def Perif(self):
		s = self.perif
		s += str(self.unit)
		return s
	def Macro(self):
		s = self.Perif()
		s += "_BASE"
		return s
	def Describe(self):
		s = self.Perif()
		if self.trig:
			s += ' ' + self.trig
		return s
	def SortName(self):
		"Returns a C++ compatible name"
		s = self.perif.capitalize()
		s += str(self.unit).zfill(2)
		if self.trig:
			s += self.trig.capitalize()
		if self.opt > 1:
			s += '_' + str(self.opt).zfill(2)
		return s
	def CppName(self):
		"Returns a C++ compatible name"
		s = self.perif.capitalize()
		s += str(self.unit)
		if self.trig:
			s += self.trig.capitalize()
		if self.opt > 1:
			s += '_' + str(self.opt)
		return s
	def CppIdName(self):
		return 'Id' + self.CppName()
	def CppTrigName(self):
		return 'Any' + self.CppName()
	def TypDefId(self):
		s = 'AnyID<'
		s += self.DmaItf()
		s += ', ' + self.DmaChan()
		if FORMAT == "L4":
			s += ', ' + self.DmaSel()
		s += '>'
		return s
	def IsTimer(self):
		return self.perif == "TIM"


def ReadFile() -> list:
	all = []
	with open(FILE, 'r') as csv_file:
		dma = 0
		reader = csv.reader(csv_file, delimiter='\t')
		for row in reader:
			if row[0] in ('CxS','1111','Peripherals'):
				dma += 1
			else:
				r = int(row[0], 2)
				for i,c in enumerate(row[1:]):
					if not c:
						continue
					ks = c.split('/')
					for k in ks:
						o = Periph(k, dma, i+1, r)
						all.append(o)
	return all

def IdentifyInstances(trigs : list):
	m = []
	for t in trigs:
		n = t.SortName()
		while n in m:
			t.opt += 1
			n = t.SortName()
		m.append(n)
	m.sort()
	return m;

class TimDma :
	def __init__(self, t : Periph) -> None:
		self.tim = t
		group = (t.dma, t.ch, t.sel)
		self.group = {}
		self.group[t.trig] = group
	def Append(self, t : Periph):
		group = (t.dma, t.ch, t.sel)
		self.group[t.trig] = group

class Generator:
	def __init__(self, fh) -> None:
		self.fh = fh
		self.macro = ""
	def Begin(self, macro, wide=False):
		if self.macro != macro:
			self.Flush()
			self.macro = macro
			self.fh.write("#ifdef {0}\n".format(macro))
		elif wide:
			self.fh.write("\n")
	def Flush(self):
		if self.macro:
			self.fh.write("#endif	// {0}\n".format(self.macro))
			self.fh.write("\n")
			self.macro = ""
	def MakeId(self, t : Periph):
		self.Begin(t.Macro())
		self.fh.write("/// A template class to map {0} to DMA channel".format(t.Describe()))
		if t.opt == 2:
			self.fh.write(" (alternate)")
		elif t.opt > 2:
			self.fh.write(" (alternate {0})".format(t.opt-1))
		self.fh.write("\n")
		self.fh.write("typedef {0} {1};\n".format(t.TypDefId(), t.CppIdName()))
	def MakeTrigger(self, t : Periph):
		self.Begin(t.Macro(), True)
		self.fh.write("/// A template class to configure {0} with DMA transfer".format(t.Describe()))
		if t.opt == 2:
			self.fh.write(" (alternate)")
		elif t.opt > 2:
			self.fh.write(" (alternate {0})".format(t.opt-1))
		self.fh.write("\n")
		self.fh.write("template<\n")
		if ('pm' in t.variant) or ('mp' in t.variant):
			self.fh.write("\tconst bool kCircular = true\n")
		elif ('<pm>' in t.variant):
			self.fh.write("\tconst Dir kDir = Dir::kPerToMemCircular\n")
		elif ('<mp>' in t.variant):
			self.fh.write("\tconst Dir kDir = Dir::kMemToPerCircular\n")
		else:
			self.fh.write("\tconst Dir kDir\n")
		#
		if '<s8>' in t.variant:
			self.fh.write("\t, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr\n")
		elif '<s8++>' in t.variant:
			self.fh.write("\t, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc\n")
		elif '<s16>' in t.variant:
			self.fh.write("\t, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr\n")
		elif '<s16++>' in t.variant:
			self.fh.write("\t, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtrInc\n")
		elif '<s32>' in t.variant:
			self.fh.write("\t, const PtrPolicy kSrcPtr = PtrPolicy::kLongPtr\n")
		elif '<s32++>' in t.variant:
			self.fh.write("\t, const PtrPolicy kSrcPtr = PtrPolicy::kLongPtrInc\n")
		elif '<s>' in t.variant:
			self.fh.write("\t, const PtrPolicy kSrcPtr\n")
		#
		if '<d8>' in t.variant:
			self.fh.write("\t, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr\n")
		elif '<d8++>' in t.variant:
			self.fh.write("\t, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc\n")
		elif '<d16>' in t.variant:
			self.fh.write("\t, const PtrPolicy kDstPtr = PtrPolicy::kShortPtr\n")
		elif '<d16++>' in t.variant:
			self.fh.write("\t, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc\n")
		elif '<d32>' in t.variant:
			self.fh.write("\t, const PtrPolicy kDstPtr = PtrPolicy::kLongPtr\n")
		elif '<d32++>' in t.variant:
			self.fh.write("\t, const PtrPolicy kDstPtr = PtrPolicy::kLongPtrInc\n")
		elif '<d>' in t.variant:
			self.fh.write("\t, const PtrPolicy kDstPtr\n")
		#
		self.fh.write("\t, const Prio kPrio = Prio::kMedium\n")
		self.fh.write(">\n")
		self.fh.write("class {0} : public AnyChannel <\n".format(t.CppTrigName()))
		self.fh.write("\t{0}\n".format(t.CppIdName()))
		if 'pm' in t.variant:
			self.fh.write("\t, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem\n")
		elif 'mp' in t.variant:
			self.fh.write("\t, kCircular ? Dir::kMemToPerCircular : Dir::kMemToPer\n")
		else:
			self.fh.write("\t, kDir\n")
		#
		if 's8' in t.variant:
			self.fh.write("\t, PtrPolicy::kBytePtr\n")
		elif 's8++' in t.variant:
			self.fh.write("\t, PtrPolicy::kBytePtrInc\n")
		elif 's16' in t.variant:
			self.fh.write("\t, PtrPolicy::kShortPtr\n")
		elif 's16++' in t.variant:
			self.fh.write("\t, PtrPolicy::kShortPtrInc\n")
		elif 's32' in t.variant:
			self.fh.write("\t, PtrPolicy::kLongPtr\n")
		elif 's32++' in t.variant:
			self.fh.write("\t, PtrPolicy::kLongPtrInc\n")
		else:
			self.fh.write("\t, kSrcPtr\n")
		#
		if 'd8' in t.variant:
			self.fh.write("\t, PtrPolicy::kBytePtr\n")
		elif 'd8++' in t.variant:
			self.fh.write("\t, PtrPolicy::kBytePtrInc\n")
		elif 'd16' in t.variant:
			self.fh.write("\t, PtrPolicy::kShortPtr\n")
		elif 'd16++' in t.variant:
			self.fh.write("\t, PtrPolicy::kShortPtrInc\n")
		elif 'd32' in t.variant:
			self.fh.write("\t, PtrPolicy::kLongPtr\n")
		elif 'd32++' in t.variant:
			self.fh.write("\t, PtrPolicy::kLongPtrInc\n")
		else:
			self.fh.write("\t, kDstPtr\n")
		self.fh.write("\t, kPrio\n")
		self.fh.write(">\n")
		self.fh.write("{ };\n")

	def MakeDmaHeader(self):
		self.fh.write("""#pragma once

namespace Bmt
{
namespace Dma
{

""")
		if FORMAT == "L4":
			self.fh.write("typedef AnyID<Itf::k1, Chan::kNone, PerifSel::k0> IdNone;\n\n")
		else:
			self.fh.write("typedef AnyID<Itf::k1, Chan::kNone> IdNone;\n\n")


	def MakeDmaFooter(self):
		self.fh.write("""

}	// namespace Dma
}	// namespace Bmt
""")

	def MakeTimDmaHeader(self):
		self.fh.write("""
// Generic template for the DMA configuration for a given timer
template<
	const Unit kTimerNum
>
struct DmaInfo
{
	// Update Event
	typedef Dma::IdNone Update;
	// Trigger event
	typedef Dma::IdNone Trigger;
	// Communtation event
	typedef Dma::IdNone Commutation;
};

template<
	const Unit kTimerNum
	, const Channel kChannel
>
struct DmaChInfo : Dma::IdNone
{
};

""")
		
	def MakeTimDmaFooter(self):
		self.fh.write("""

""")
		
	def MakeTimDma(self, td : TimDma):
		self.Begin(td.tim.Macro())
		self.fh.write("// Template specialization for DMA settings of TIM{0}>\n".format(td.tim.unit))
		self.fh.write("template<> struct DmaInfo<kTim{0}>\n".format(td.tim.unit))
		self.fh.write("{\n")
		if "UP" in td.group:
			self.fh.write("\ttypedef Dma::IdTim{0}Up Update;\n".format(td.tim.unit))
		else:
			self.fh.write("\ttypedef Dma::IdNone Update;\n")
		if "TRIG" in td.group:
			self.fh.write("\ttypedef Dma::IdTim{0}Trig Trigger;\n".format(td.tim.unit))
		else:
			self.fh.write("\ttypedef Dma::IdNone Trigger;\n")
		if "COM" in td.group:
			self.fh.write("\ttypedef Dma::IdTim{0}Com Commutation;\n".format(td.tim.unit))
		else:
			self.fh.write("\ttypedef Dma::IdNone Commutation;\n")
		self.fh.write("};\n")
		self.fh.write("\n")
		for i in range(1, 5):
			s = "CH" + str(i)
			if s in td.group:
				self.fh.write("// Template specialization for DMA Channel settings for TIM{0}_{1}>\n".format(td.tim.unit, s))
				self.fh.write("template<> struct DmaChInfo<kTim{0}, Channel::k{2}> : Dma::IdTim{0}{1}\n".format(td.tim.unit, s.capitalize(), i))
				self.fh.write("{\n")
				self.fh.write("};\n")
				self.fh.write("\n")

def PrintNames(trigs : list, insts : list):
	with open(os.path.splitext(FILE)[0] + ".h", 'wt') as fh:
		g = Generator(fh)
		g.MakeDmaHeader()
		for n in insts:
			for t in trigs:
				if n == t.SortName():
					g.MakeId(t)
					break
		g.Flush()
		fh.write("\n")
		for n in insts:
			for t in trigs:
				if n == t.SortName():
					g.MakeTrigger(t)
					break
		g.Flush()
		g.MakeDmaFooter()


def MakeTimDmaId(trigs : list, insts : list):
	order = []
	tims = {}
	for n in insts:
		for t in trigs:
			if n == t.SortName():
				if t.IsTimer() and (t.opt == 1):
					if t.unit not in tims:
						tims[t.unit] = TimDma(t)
						order.append(t.unit)
					else:
						tims[t.unit].Append(t)
					break
	with open("tim_dma_id." + FORMAT.lower() + ".inl", 'wt') as fh:
		g = Generator(fh)
		g.MakeTimDmaHeader()
		for k in order:
			g.MakeTimDma(tims[k])
		g.Flush()
		g.MakeTimDmaFooter()


trigs = ReadFile()
insts = IdentifyInstances(trigs)
PrintNames(trigs, insts)
MakeTimDmaId(trigs, insts)

