#pragma once

#include "../gpio.h"
#include "../gpio-utils.h"

namespace Bmt
{
namespace Kits
{
namespace Lcd1602
{

// Unchanged
enum class Options
{
	kDefault	= 0b00000000,	// Defaults to 2x16; 5x8 cell
	k1Line		= 0b00100000,	// Display has one line (1x16, 1x20, 1x40)
	k1202		= 0b00000000,	// 2x12 (@ 0x00, 0x40)
	k1602		= 0b00000000,	// 2x16 (@ 0x00, 0x40)
	k2002		= 0b00000000,	// 2x20 (@ 0x00, 0x40)
	k2402		= 0b00000000,	// 2x24 (@ 0x00, 0x40)
	k4002		= 0b00000000,	// 2x40 (@ 0x00, 0x40)
	k1604		= 0b00000001,	// 4x16 (@ 0x00, 0x40, 0x10, 0x50)
	k2004a		= 0b00000010,	// 4x20 (@ 0x00, 0x40, 0x14, 0x54)
	k2004b		= 0b00000011,	// 4x20 (@ 0x00, 0x20, 0x40, 0x60)
	k5x10Char	= 0b01000000,	// Display has 5x10 chars
	kSlowBus	= 0b10000000,	// Slower bus transactions good for long cables
};
// Bit merge
constexpr static Options operator|(Options lhs, Options rhs)
{
	return Options((uint8_t)lhs | (uint8_t)rhs);
}
// Bit test
constexpr static Options operator&(Options lhs, Options rhs)
{
	return Options((uint8_t)lhs & (uint8_t)rhs);
}

// Options for the FunctionSet command
enum class FuncSetOpts : uint8_t
{
	k8BitMode 	= 0b00010000,
	k4BitMode 	= 0b00000000,
	k2Line 		= 0b00001000,
	k1Line 		= 0b00000000,
	k5x8Char	= 0b00000000,
	k5x10Char	= 0b00000100,
	kUserMask_ 	= 0b00001100,
};
// Bit merge
constexpr static FuncSetOpts operator|(FuncSetOpts lhs, FuncSetOpts rhs)
{
	return FuncSetOpts((uint8_t)lhs | (uint8_t)rhs);
}
// Bit test
constexpr static FuncSetOpts operator&(FuncSetOpts lhs, FuncSetOpts rhs)
{
	return FuncSetOpts((uint8_t)lhs & (uint8_t)rhs);
}

// Options for the DisplayControl command
enum class DisplayOpts : uint8_t
{
	kDisplayOn	= 0b00000100,
	kDisplayOff	= 0b00000000,
	kCursorOn	= 0b00000010,
	kCursorOff	= 0b00000000,
	kBlinkOn	= 0b00000001,
	kBlinkOff	= 0b00000000,
};
// Bit merge
constexpr static DisplayOpts operator|(DisplayOpts lhs, DisplayOpts rhs)
{
	return DisplayOpts((uint8_t)lhs | (uint8_t)rhs);
}
// Bit test
constexpr static DisplayOpts operator&(DisplayOpts lhs, DisplayOpts rhs)
{
	return DisplayOpts((uint8_t)lhs & (uint8_t)rhs);
}

// Options for the CursorShift command
enum class ShiftOpts : uint8_t
{
	kLeft				= 0b00000000,	// move left
	kRight				= 0b00000100,	// move right
	kCursorOnly 		= 0b00000000,	// cursor movement only
	kCursorAndDisplay 	= 0b00001000,	// both, cursor and display moves
};
// Bit merge
constexpr static ShiftOpts operator|(ShiftOpts lhs, ShiftOpts rhs)
{
	return ShiftOpts((uint8_t)lhs | (uint8_t)rhs);
}
// Bit test
constexpr static ShiftOpts operator&(ShiftOpts lhs, ShiftOpts rhs)
{
	return ShiftOpts((uint8_t)lhs & (uint8_t)rhs);
}

// Options for the EntryModeSet command
enum class EntryModeOpts : uint8_t
{
	kIncrement	= 0b00000010,
	kDecrement	= 0b00000000,
	kShift		= 0b00000001,
	kNoShift	= 0b00000000,
};
// Bit merge
constexpr static EntryModeOpts operator|(EntryModeOpts lhs, EntryModeOpts rhs)
{
	return EntryModeOpts((uint8_t)lhs | (uint8_t)rhs);
}
// Bit test
constexpr static EntryModeOpts operator&(EntryModeOpts lhs, EntryModeOpts rhs)
{
	return EntryModeOpts((uint8_t)lhs & (uint8_t)rhs);
}

template <
	typename Delay,								//!< Short delays class to produce small nanosecond pauses
	typename PolledStopWatch,					//!< A timer class with a ms stopwatch
	const Gpio::Port kPort = Gpio::Port::PA,	//!< The GPIO port
	const Options kOpts = Options::kDefault,	//!< Default display options
	const uint8_t kRS = 1,						//!< RS line (always output)
	const uint8_t kRW = 2,						//!< RW line (always output)
	const uint8_t kEN = 3,						//!< EN line (always output)
	const uint8_t kD4 = 4,						//!< D4 line of the LCD1602
	const uint8_t kD5 = 5,						//!< D5 line of the LCD1602
	const uint8_t kD6 = 6,						//!< D6 line of the LCD1602
	const uint8_t kD7 = 7						//!< D7 line of the LCD1602
>
class AnyLcd1602
{
private:
	// see HD44780/ST7066U documentation
	enum Cmd : uint8_t
	{
		kClearDisplay	= 0b00000001,
		kReturnHome		= 0b00000010,
		kEntryModeSet 	= 0b00000100,
		kDisplayControl = 0b00001000,
		kCursorShift	= 0b00010000,
		kFunctionSet	= 0b00100000,
		kSetCgAddress	= 0b01000000,
		kSetRamAddress	= 0b10000000,
	};
	enum Ctrl : uint8_t
	{
		kWrInstruction	= 0b00,	// Send instructions to the display (LCD in, MCU out)
		kRdAddress		= 0b01,	// and busy flag (LCD out, MCU in)
		kWrData			= 0b10,	// Writes data to the RAM (LCD in, MCU out)
		kRdData			= 0b11,	// Reads data from the RAM (LCD out, MCU in)
	};
public:
	typedef Delay Delay_;
	typedef Gpio::AnyOut<kPort, kRS> RS_;
	typedef Gpio::AnyOut<kPort, kRW> RW_;
	typedef Gpio::AnyOut<kPort, kEN> EN_;
	typedef Gpio::AnyOut<kPort, kD4> D4_;
	typedef Gpio::AnyOut<kPort, kD5> D5_;
	typedef Gpio::AnyOut<kPort, kD6> D6_;
	typedef Gpio::AnyOut<kPort, kD7> D7_;
	typedef Gpio::AnyIn<kPort, kD4, Gpio::PuPd::kPullDown> D4in_;
	typedef Gpio::AnyIn<kPort, kD5, Gpio::PuPd::kPullDown> D5in_;
	typedef Gpio::AnyIn<kPort, kD6, Gpio::PuPd::kPullDown> D6in_;
	typedef Gpio::AnyIn<kPort, kD7, Gpio::PuPd::kPullDown> D7in_;
	// Output for control pins
	typedef Gpio::AnyCounter<RW_, RS_> Mode_;
	// Output control for data bus
	typedef Gpio::AnyCounter<D4_, D5_, D6_, D7_> DataBus_;
	// Output direction data-type
	typedef Gpio::AnyPinGroup<kPort, D4_, D5_, D6_, D7_> OutPin_;
	// Output direction data-type
	typedef Gpio::AnyPinGroup<kPort, D4in_, D5in_, D6in_, D7in_> InPins_;
	// Describes the hardware attached to controller
	static constexpr FuncSetOpts kFormat_
		= ((kOpts & Options::k1Line) == Options::k1Line ? FuncSetOpts::k1Line : FuncSetOpts::k2Line)
		| ((kOpts & Options::k5x10Char) == Options::k5x10Char ? FuncSetOpts::k5x10Char : FuncSetOpts::k5x8Char)
		;
	// Determines the base period of the bus transactions
	static constexpr uint32_t kSlopeWidth_ = (kOpts & Options::kSlowBus) == Options::kSlowBus
		? 1000 : 500;

	AnyLcd1602()
	{ }

	// Enables bus (not necessary if you initialized bus elsewhere)
	static void Enable()
	{
		typedef Gpio::AnyPinGroup<kPort, RS_, RW_, EN_, D4_, D5_, D6_, D7_> AllPins;
		AllPins::Enable();
	}
	// Ensure that 40ms have passed after power on, before calling this
	void InitLcd()
	{
		m_Poll.Wait();
		WaitBusy();
		FunctionSet(FuncSetOpts::k8BitMode);
		FunctionSet(FuncSetOpts::k8BitMode);
		FunctionSet(FuncSetOpts::k4BitMode);
		FunctionSet(FuncSetOpts::k4BitMode | kFormat_);
		DisplayControl(DisplayOpts::kDisplayOn);
		ClearDisplay();
		EntryModeSet(EntryModeOpts::kIncrement | EntryModeOpts::kNoShift);
		SetCursorPos(0, 0);
	}
	// Returns true if device is not able to receive any command
	/*
	If you write anything to the display CPU will be halted until unlock
	timer releases.
	NOTE: Internal timers uses ordinary polling technique and may fail if 
	internal timer wraps around. To avoid issues. You should 'ping' internal
	timer at a reasonable rate to avoid irregular delays.
	*/
	constexpr bool IsLocked()
	{
		if (m_Poll.IsNotElapsed())
			return true;
		return false;
	}
	// Clears the display (requires at least 1,5 ms)
	constexpr void ClearDisplay()
	{
		WriteInstruction(kClearDisplay);
		m_Poll.template RestartUS<1500>();
	}
	// Clears the display (requires at least 1,5 ms)
	constexpr void ReturnHome()
	{
		WriteInstruction(kReturnHome);
		m_Poll.template RestartUS<1500>();
	}
	// Sends the EntryModeSet command
	constexpr void EntryModeSet(EntryModeOpts opts)
	{
		uint8_t raw = (uint8_t)opts | kEntryModeSet;
		WriteInstruction(raw);
		m_Poll.template RestartUS<20>();
	}
	// Sends the DisplayControl command
	constexpr void DisplayControl(DisplayOpts opts)
	{
		uint8_t raw = (uint8_t)opts | kDisplayControl;
		WriteInstruction(raw);
		m_Poll.template RestartUS<20>();
	}
	// Sends the CursorShift command
	constexpr void CursorShift(ShiftOpts opts)
	{
		uint8_t raw = (uint8_t)opts | kCursorShift;
		WriteInstruction(raw);
		m_Poll.template RestartUS<20>();
	}
	// Set CGRAM Address to AC
	constexpr void SetCGRAM(const uint8_t addr)
	{
		uint8_t raw = (addr & 0b00111111) | kSetCgAddress;
		WriteInstruction(raw);
		m_Poll.template RestartUS<20>();
	}
	// Sets the cursor position
	void SetCursorPos(uint8_t x, uint8_t y)
	{
		constexpr uint8_t rmax
			= (kOpts & Options::k1Line) == Options::k1Line 		? 1
			: (kOpts & Options::k2004b) != Options::kDefault	? 4
			/* Defaults to 2 line display */					: 2
			;
		constexpr static uint8_t addr0[] =
		{
			0x00, 0x40, 0x10, 0x50
		};
		constexpr static uint8_t addr1[] =
		{
			0x00, 0x40, 0x14, 0x54
		};
		constexpr static uint8_t addr2[] =
		{
			0x00, 0x20, 0x40, 0x60
		};
		// Truncate y coordinate
		if (y >= rmax)
			y = 0;
		// Memory offset depends on hardware design
		if ((kOpts & Options::k2004b) == Options::k2004b)
			y = addr2[y];
		else if ((kOpts & Options::k2004b) == Options::k2004a)
			y = addr1[y];
		else
			y = addr0[y];
		x = x + y;				// final mem position
		WriteInstruction(x | kSetRamAddress);
		m_Poll.template RestartUS<15>();
	}
	// Writes an unformatted string to current cursor position
	ALWAYS_INLINE constexpr void Write(char ch)
	{
		WaitBusy();
		WriteData(ch);
	}
	// Writes an unformatted string to current cursor position
	ALWAYS_INLINE constexpr void Write(const char *s)
	{
		for(; *s; ++s)
			Write(*s);
	}

private:
	// Returns true if display is busy
	ALWAYS_INLINE static constexpr bool IsBusy()
	{
		uint8_t v = ReadAddress();
		return (v & 0x80) != 0;
	}
	// Halts CPU while display is busy
	static void WaitBusy() NO_INLINE
	{
		while(IsBusy())
		{}
	}
	void FunctionSet(FuncSetOpts opts) NO_INLINE
	{
		m_Poll.Wait();
		uint8_t raw = (uint8_t)opts | kFunctionSet;
		WriteInstruction4(raw >> 4);
		if ((opts & FuncSetOpts::k8BitMode) != FuncSetOpts::k8BitMode)
			WriteInstruction4(raw & 0xf);
		m_Poll.template RestartUS<37>();
	}
	ALWAYS_INLINE static constexpr void WriteInstruction4(const uint8_t v)
	{
		EN_::SetHigh();
		DataBus_::Write(v);
		Delay_::template DelayNS<kSlopeWidth_>();
		EN_::SetLow();
		Delay_::template DelayNS<kSlopeWidth_>();
	}
	void WriteInstruction(const uint8_t v) NO_INLINE
	{
		m_Poll.Wait();
		WaitBusy();
		Mode_::Write(Ctrl::kWrInstruction);
		WriteInstruction4(v >> 4);
		WriteInstruction4(v & 0x0f);
	}
	ALWAYS_INLINE static constexpr uint8_t ReadAddress4()
	{
		EN_::SetHigh();
		Delay_::template DelayNS<kSlopeWidth_>();
		uint8_t res = DataBus_::Read();
		EN_::SetLow();
		Delay_::template DelayNS<kSlopeWidth_>();
		return res;
	}
	static uint8_t ReadAddress() NO_INLINE
	{
		InPins_::Enable();
		Mode_::Write(Ctrl::kRdAddress);
		uint8_t v = ReadAddress4() << 4;
		v |= (ReadAddress4() & 0x0f);
		Mode_::Write(Ctrl::kWrInstruction);
		OutPin_::Enable();
		return v;
	}
	ALWAYS_INLINE static constexpr void WriteData4(const uint8_t v)
	{
		EN_::SetHigh();
		DataBus_::Write(v);
		Delay_::template DelayNS<kSlopeWidth_>();
		EN_::SetLow();
		Delay_::template DelayNS<kSlopeWidth_>();
	}
	void WriteData(const uint8_t v) NO_INLINE
	{
		Mode_::Write(Ctrl::kWrData);
		WriteData4(v >> 4);
		WriteData4(v & 0x0f);
		m_Poll.template RestartUS<20>();
		Mode_::Write(Ctrl::kWrInstruction);
	}
	ALWAYS_INLINE static constexpr uint8_t ReadData4()
	{
		EN_::SetHigh();
		Delay_::template DelayNS<kSlopeWidth_>();
		uint8_t res = DataBus_::Read();
		EN_::SetLow();
		Delay_::template DelayNS<kSlopeWidth_>();
		return res;
	}
	static uint8_t ReadData() NO_INLINE
	{
		InPins_::Enable();
		Mode_::Write(Ctrl::kRdData);
		uint8_t v = ReadData4() << 4;
		v |= (ReadData4() & 0x0f);
		Mode_::Write(Ctrl::kWrInstruction);
		OutPin_::Enable();
		return v;
	}

protected:
	PolledStopWatch m_Poll;
};

}	// namespace Lcd1602
}	// namespace Kits
}	// namespace Bmt
