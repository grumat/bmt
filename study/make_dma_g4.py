# This script reads the DMA mapping from stm32g4xx_hal_dma.h file and produces a 
# header file with defines.
# The script was designed to automatically produce DMA device definitions 
# for the STM32G4xxx devices

import re
import os
import csv


FILE="stm32g4xx_hal_dma.h"
FILE_L4="dma_l4xx.csv"
OFILE="dma_g4xx.h"

PERIFS = [
	(r"(ADC)(\d\d?)",				'<pm>,s16,<d16++>'),
	(r"(AES)(\d?)_(IN)",			'pm,<s32++>,<d32>'),
	(r"(AES)(\d?)_(OUT)",			'mp,<s32>,<d32++>'),
	(r"(CORDIC)(\d?)_(READ)",		'<pm>,<s32>,<d32++>'),
	(r"(CORDIC)(\d?)_(WRITE)",		'<mp>,<s32++>,<d32>'),
	(r"(DAC)(\d\d?)_(\w+)",			'pm,<s16>,<d16++>'),
	(r"(FMAC)(\d?)_(READ)",			'<pm>,<s32>,<d32++>'),
	(r"(FMAC)(\d?)_(WRITE)",		'<mp>,<s32++>,<d32>'),
	(r"(GENERATOR)(\d\d?)",			'ok'),
	(r"(HRTIM)(\d\d?)_(.+)",		'<s>,<d>'),
	(r"(I2C)(\d\d?)_(RX)",			'<pm>,<s8>,<d8++>'),
	(r"(I2C)(\d\d?)_(TX)",			'<mp>,<s8++>,<d8>'),
	(r"(LPUART)(\d\d?)_(RX)",		'<pm>,<s8>,<d8++>'),
	(r"(LPUART)(\d\d?)_(TX)",		'<mp>,<s8++>,<d8>'),
	(r"(MEM2MEM)",					'ok,<pm>,s16,<d16++>'),
	(r"(QUADSPI)(\d?)",				'pm,<s8>,<d8++>'),
	(r"(SAI)(\d\d?)_(.+)",			'<s>,<d>'),
	(r"(SPI)(\d?\d?)_(RX)",			'<pm>,<s8>,<d8++>'),
	(r"(SPI)(\d?\d?)_(TX)",			'<mp>,<s8++>,<d8>'),
	(r"(TIM)(\d\d?)_(.+)",			'<s>,<d>'),
	(r"(UCPD)(\d\d?)_(RX)",			'<pm>,<s8>,<d8++>'),
	(r"(UCPD)(\d\d?)_(TX)",			'<mp>,<s8++>,<d8>'),
	(r"(US?ART)(\d\d?)_(RX)",		'<pm>,<s8>,<d8++>'),
	(r"(US?ART)(\d\d?)_(TX)",		'<mp>,<s8++>,d8'),
]

L4TOG4 = [
	(r"DAC_CH(\d)", 0),
]

class Periph:
	def __init__(self, name :str, mux :int) -> None:
		for r in PERIFS:
			m = re.match(r[0], name)
			if m:
				v = r[1]
				break
		if m:
			self.perif = m[1]
			if m.lastindex > 1:
				self.unit = m[2] or ""
				if m.lastindex > 2:
					self.trig = m[3]
				else:
					self.trig = None
			else:
				self.unit = ""
				self.trig = None
		else:
			raise Exception(1, "Unknown peripheral {0}".format(name))
		self.mux = mux
		self.variant = v.split(',')
		self.dmachans = []
	def SortName(self):
		"Returns a C++ compatible name"
		s = self.perif.capitalize()
		s += str(self.unit).zfill(2)
		if self.trig:
			s += self.trig.capitalize()
		return s
	def Macro(self):
		if "ok" in self.variant:
			return ""
		s = self.Perif()
		s += "_BASE"
		return s
	def Perif(self):
		s = self.perif
		s += str(self.unit)
		return s
	def Label(self):
		s = self.Perif()
		if self.trig:
			s += '_' + self.trig
		return s
	def Describe(self):
		s = self.Perif()
		if self.trig:
			s += ' ' + self.trig
		return s
	def CppName(self, opt : int):
		"Returns a C++ compatible name"
		if self.perif == "MEM2MEM":
			return "Mem2Mem"
		s = self.perif.capitalize()
		s += str(self.unit)
		if self.trig:
			s += self.trig.capitalize()
		if opt > 0:
			s += '_' + str(opt+1)
		return s
	def CppEnumName(self):
		return 'k' + self.CppName(0)
	def CppIdName(self, opt : int):
		return 'Id' + self.CppName(opt)
	def CppTrigName(self, opt : int):
		return 'Any' + self.CppName(opt)
	def TypDefId(self, itf, ch):
		s = 'AnyID<'
		s += 'Itf::k' + str(itf)
		s += ', Chan::k' + str(ch)
		s += ', PerifSel::' + self.CppEnumName()
		s += '>'
		return s
	def IsTimer(self):
		return self.perif == "TIM"


def ReadFile() -> list:
	p = re.compile(r"#define\s+DMA_REQUEST_(\w+)\s+(\d+)U.*$")
	all = []
	with open(FILE, 'r') as fh:
		for line in fh:
			m = p.match(line)
			if m:
				o = Periph(m[1], int(m[2]))
				all.append(o)

	return all

def RenameCompat(label : str):
	for r, a in L4TOG4:
		m = re.match(r, label)
		if m:
			if a == 0:
				label = 'DAC1_CHANNEL' + m[1]
				break
			else:
				raise Exception(1, "Unknown action {0}/{1}".format(r, a))
	return label

def ReadFileL4(trigs : list) -> list:
	with open(FILE_L4, 'r') as csv_file:
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
						k = RenameCompat(k)
						m = None
						for t in trigs:
							if t.Label() == k:
								m = t
								break
						if not m:
							print ("Unknown peripheral {0}".format(k))
						else:
							t.dmachans.append((dma, i+1))
	return None

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

def CollectDmaChanns(trigs : list):
	dmas = {}
	for t in trigs:
		for d in t.dmachans:
			if d not in dmas:
				dmas[d] = [t.Perif()]
			else:
				dmas[d].append(t.Perif())
	return dmas

def AssignDmaChanns(trig : list, dmas : dict, order : list):
	last = None
	for n in order:
		for t in trig:
			# Skip elements with assigned dma
			if t.dmachans:
				continue
			# Follows the sort order
			if t.SortName() == n:
				n2 = t.Perif()
				# Selects DMA channels with less count
				s = None
				kk = None
				for k, v in dmas.items():
					if (last != k) and (n2 not in v):
						if (not s) or (len(s) > len(v)):
							s = v
							kk = k
				if not s:
					raise Exception(1, "Unable to locate suitable DMA for {0}".format(n2))
				dmas[kk] = n2
				t.dmachans.append(kk)
				last = kk
				break
	return None

class TimDma :
	def __init__(self, t : Periph, dma : str) -> None:
		self.tim = t
		group = (dma[0], dma[1], t.mux)
		self.group = {}
		self.group[t.trig] = group
	def Append(self, t : Periph, dma : str):
		group = (dma[0], dma[1], t.mux)
		self.group[t.trig] = group

class Generator:
	def __init__(self, fh) -> None:
		self.fh = fh
		self.macro = ""
		self.begin = False
	def Begin(self, macro, wide=False):
		if self.macro != macro:
			self.Flush()
			self.macro = macro
			if macro:
				self.fh.write("#ifdef {0}\n".format(macro))
		elif wide:
			self.fh.write("\n")
	def Flush(self):
		if self.macro:
			self.fh.write("#endif	// {0}\n".format(self.macro))
			self.macro = ""
		if self.begin:
			self.fh.write("\n")
		self.begin = True
	def MakeDmaHeader(self):
		self.fh.write("""#pragma once

namespace Bmt
{
namespace Dma
{

""")


	def MakeDmaDefaultID(self):
		self.fh.write("typedef AnyID<Itf::k1, Chan::kNone, PerifSel::kMem2Mem> IdNone;\n\n")
		self.fh.write("/* The type definitions below are, wherever possible, based on DMA settings of STM32L4xx. */\n")


	def MakeDmaFooter(self):
		self.fh.write("""

}	// namespace Dma
}	// namespace Bmt
""")
		
	def BeginEnum(self):
		self.fh.write("\n")
		self.fh.write("enum class PerifSel : uint8_t\n")
		self.fh.write("{\n")
	def EndEnum(self):
		self.fh.write("};\n")
		self.fh.write("\n")

	def MakeEnum(self, t : Periph):
		self.Begin(t.Macro())
		self.fh.write("\t{0} = {1},\t// {2}\n".format(t.CppEnumName(), t.mux, t.Describe()))

	def MakeId(self, t : Periph):
		self.Begin(t.Macro())
		for opt, dma in enumerate(t.dmachans):
			self.fh.write("/// A template class to map {0} to DMA{1} channel {2}".format(t.Describe(), dma[0], dma[1]))
			if opt == 1:
				self.fh.write(" (alternate)")
			elif opt > 2:
				self.fh.write(" (alternate {0})".format(opt))
			self.fh.write("\n")
			self.fh.write("typedef {0} {1};\n".format(t.TypDefId(dma[0], dma[1]), t.CppIdName(opt)))

	def MakeTrigger(self, t : Periph):
		self.Begin(t.Macro(), True)
		for opt, dma in enumerate(t.dmachans):
			self.fh.write("/// A template class to configure {0} with DMA transfer (DMA{1} CH{2})".format(t.Describe(), dma[0], dma[1]))
			if opt == 1:
				self.fh.write(" (alternate)")
			elif opt > 1:
				self.fh.write(" (alternate {0})".format(opt))
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
			self.fh.write("class {0} : public AnyChannel <\n".format(t.CppTrigName(opt)))
			self.fh.write("\t{0}\n".format(t.CppIdName(opt)))
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

	def MakeTimDmaHeader(self):
		self.fh.write("""// This was added for backward compatibility. G4 features a powerful MUX and this 
// file should be ignored for native projects

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
	with open(OFILE, 'wt') as fh:
		g = Generator(fh)
		g.MakeDmaHeader()
		g.BeginEnum()
		for n in insts:
			for t in trigs:
				if n == t.SortName():
					g.MakeEnum(t)
					break
		g.Flush()
		g.EndEnum()
		fh.write("\n")
		if 1:
			g.MakeDmaDefaultID()
			for n in insts:
				for t in trigs:
					if n == t.SortName():
						g.MakeId(t)
						break
			g.Flush()
		if 1:
			for n in insts:
				for t in trigs:
					if 'ok' in t.variant:
						continue
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
				if t.IsTimer():
					for dma in t.dmachans:
						if t.unit not in tims:
							tims[t.unit] = TimDma(t, dma)
							order.append(t.unit)
						else:
							tims[t.unit].Append(t, dma)
					break
	with open("tim_dma_id.g4.inl", 'wt') as fh:
		g = Generator(fh)
		g.MakeTimDmaHeader()
		for k in order:
			g.MakeTimDma(tims[k])
		g.Flush()
		g.MakeTimDmaFooter()


trigs = ReadFile()
ReadFileL4(trigs)
channs = CollectDmaChanns(trigs)
insts = IdentifyInstances(trigs)
AssignDmaChanns(trigs, channs, insts)
PrintNames(trigs, insts)
MakeTimDmaId(trigs, insts)

