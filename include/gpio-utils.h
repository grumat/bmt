#pragma once

#include "gpio.h"

namespace Bmt
{
namespace Gpio
{

// Up to 4 bits that can enumerates a binary sequence out to GPIO lines
template <
	typename Bit0							/// Definition for bit 0 (defaults to unused pin, i.e an inputs)
	, typename Bit1							/// Definition for bit 1 (defaults to unused pin, i.e an inputs)
	, typename Bit2 = Gpio::Unchanged<2>	/// Definition for bit 2 (defaults to unused pin, i.e an inputs)
	, typename Bit3 = Gpio::Unchanged<3>	/// Definition for bit 3 (defaults to unused pin, i.e an inputs)
>
class AnyCounter
{
public:
	/// The GPIO port peripheral
	static constexpr Port kPort_ = Bit0::kPort_;
	/// The base address for the GPIO peripheral registers
	static constexpr uint32_t kPortBase_ = (GPIOA_BASE + uint32_t(kPort_) * 0x400);
	/// Values for the BSRR register
	static constexpr uint32_t kValues[16] =
	{
		Bit0::kBsrrValue_ | Bit1::kBsrrValue_ | Bit2::kBsrrValue_ | Bit3::kBsrrValue_,
		Bit0::kBitValue_  | Bit1::kBsrrValue_ | Bit2::kBsrrValue_ | Bit3::kBsrrValue_,
		Bit0::kBsrrValue_ | Bit1::kBitValue_  | Bit2::kBsrrValue_ | Bit3::kBsrrValue_,
		Bit0::kBitValue_  | Bit1::kBitValue_  | Bit2::kBsrrValue_ | Bit3::kBsrrValue_,
		Bit0::kBsrrValue_ | Bit1::kBsrrValue_ | Bit2::kBitValue_  | Bit3::kBsrrValue_,
		Bit0::kBitValue_  | Bit1::kBsrrValue_ | Bit2::kBitValue_  | Bit3::kBsrrValue_,
		Bit0::kBsrrValue_ | Bit1::kBitValue_  | Bit2::kBitValue_  | Bit3::kBsrrValue_,
		Bit0::kBitValue_  | Bit1::kBitValue_  | Bit2::kBitValue_  | Bit3::kBsrrValue_,
		Bit0::kBsrrValue_ | Bit1::kBsrrValue_ | Bit2::kBsrrValue_ | Bit3::kBitValue_,
		Bit0::kBitValue_  | Bit1::kBsrrValue_ | Bit2::kBsrrValue_ | Bit3::kBitValue_,
		Bit0::kBsrrValue_ | Bit1::kBitValue_  | Bit2::kBsrrValue_ | Bit3::kBitValue_,
		Bit0::kBitValue_  | Bit1::kBitValue_  | Bit2::kBsrrValue_ | Bit3::kBitValue_,
		Bit0::kBsrrValue_ | Bit1::kBsrrValue_ | Bit2::kBitValue_  | Bit3::kBitValue_,
		Bit0::kBitValue_  | Bit1::kBsrrValue_ | Bit2::kBitValue_  | Bit3::kBitValue_,
		Bit0::kBsrrValue_ | Bit1::kBitValue_  | Bit2::kBitValue_  | Bit3::kBitValue_,
		Bit0::kBitValue_  | Bit1::kBitValue_  | Bit2::kBitValue_  | Bit3::kBitValue_,
	};
	/// Mask to limit the enumeration
	static constexpr uint32_t kTop_ = 
		(Bit3::kBitValue_ != 0) ? 15
		: (Bit2::kBitValue_ != 0) ? 7
		: (Bit1::kBitValue_ != 0) ? 3
		: (Bit0::kBitValue_ != 0) ? 1
		: 0
		;
	// Bits are in ascending order (can optimize code)
	static constexpr bool kIsSequential_ =
		Bit0::kPin_ + 1 == Bit1::kPin_
		&& (Bit2::kBitValue_ == 0 || Bit1::kPin_ + 1 == Bit2::kPin_)
		&& (Bit3::kBitValue_ == 0 || Bit2::kPin_ + 1 == Bit3::kPin_)
		;

	// Fails when first template argument is an unused bit
	static_assert(kPort_ != Port::kUnusedPort, "Bit0 does not define a valid GPIO port");
	// Compilation will fail here if GPIO port number of pin does not match the peripheral!!!
	static_assert(
		(Bit0::kPort_ == kPort_)
		&& (Bit1::kPort_ == Port::kUnusedPort || Bit1::kPort_ == kPort_)
		&& (Bit2::kPort_ == Port::kUnusedPort || Bit2::kPort_ == kPort_)
		&& (Bit3::kPort_ == Port::kUnusedPort || Bit3::kPort_ == kPort_)
		, "Inconsistent port number"
		);
	// At least two bits are required to form an enumerated group
	static_assert(kTop_ >= 3, "enumeration requires a group of 2, 3 or 4 bits");

	/// Access to the hardware IO data structure
	ALWAYS_INLINE static volatile GPIO_TypeDef & Io() { return *(volatile GPIO_TypeDef*)kPortBase_; }

	/// Apply an enum value in the range of 0-15
	ALWAYS_INLINE static void Write(const uint32_t val)
	{
		// Base address of the peripheral registers
		volatile GPIO_TypeDef& port = Io();
		// Use bit-set-reset register to apply output
		port.BSRR = kValues[val & kTop_];
	}
	/// Apply an enum value in the range of 0-15 (negative logic)
	ALWAYS_INLINE static void WriteComplement(const uint32_t val)
	{
		// Base address of the peripheral registers
		volatile GPIO_TypeDef& port = Io();
		// Use bit-set-reset register to apply output
		port.BSRR = kValues[kTop_ - (val & kTop_)];
	}
	// Reads data
	ALWAYS_INLINE static uint32_t Read()
	{
		// Base address of the peripheral registers
		volatile GPIO_TypeDef& port = Io();
		uint32_t tmp = port.IDR;
		// Optimizes for ordered pin sequence
		if (kIsSequential_)
			return (tmp >> Bit0::kPin_) & kTop_;
		else
		{
			uint32_t res = 0;
			if (tmp & Bit0::kBitValue_)
				res |= 0b0001;
			if (tmp & Bit1::kBitValue_)
				res |= 0b0010;
			if (tmp & Bit2::kBitValue_)
				res |= 0b0100;
			if (tmp & Bit3::kBitValue_)
				res |= 0b1000;
			return res;
		}
	}
};


// Combine two port configuration for setup
template <
	typename P0
	, typename P1
>
struct PortMerge
{
	// Apply configuration and set default output levels
	ALWAYS_INLINE constexpr static void Setup()
	{
		P0::Setup();
		P1::Setup();
	}
	// Apply configuration and keep current output levels
	ALWAYS_INLINE constexpr static void SetupPinMode()
	{
		P0::SetupPinMode();
		P1::SetupPinMode();
	}
	// Enter tri-state (not recomended: it is recomended to define a set with the desired "inactive" state)
	ALWAYS_INLINE constexpr static void TriState()
	{
		P0::TriState();
		P1::TriState();
	}
};


// Combines two or more pins and apply exac the same states
template <
	typename Bit0
	, typename Bit1
	, typename Bit2 = Gpio::Unchanged<2>
	, typename Bit3 = Gpio::Unchanged<3>
>
struct PinCopy
{
	/// Combined bit value constant
	static constexpr uint32_t kBitValue_ =
		Bit0::kBitValue_ | Bit1::kBitValue_
		| Bit2::kBitValue_ | Bit3::kBitValue_
		;

	/// Sets pin up. The pin will be high as long as it is configured as GPIO output
	ALWAYS_INLINE constexpr static void SetHigh()
	{
		if (kBitValue_ != 0)
		{
			volatile GPIO_TypeDef& port = Bit0::Io();
			port.BSRR = kBitValue_;
		}
	};

	/// Sets pin down. The pin will be low as long as it is configured as GPIO output
	ALWAYS_INLINE constexpr static void SetLow()
	{
		if (kBitValue_ != 0)
		{
			volatile GPIO_TypeDef& port = Bit0::Io();
			port.BRR = kBitValue_;
		}
	}

	/// Sets the pin to the given level. Note that optimizing compiler simplifies literal constants
	ALWAYS_INLINE constexpr static void Set(const bool value)
	{
		if (value)
			SetHigh();
		else
			SetLow();
	}

	/// Reads current Pin electrical state
	ALWAYS_INLINE constexpr static bool Get()
	{
		if (kBitValue_ != 0)
		{
			volatile GPIO_TypeDef& port = Bit0::Io();
			return (port.IDR & kBitValue_) != 0;
		}
		else
			return false;
	}
	/// Reads current Pin electrical state
	ALWAYS_INLINE constexpr static uint16_t GetRaw()
	{
		if (kBitValue_ != 0)
		{
			volatile GPIO_TypeDef& port = Bit0::Io();
			return (port.IDR & kBitValue_);
		}
		else
			return 0;
	}

	/// Checks if current pin electrical state is high
	ALWAYS_INLINE constexpr static bool IsHigh()
	{
		if (kBitValue_ != 0)
		{
			volatile GPIO_TypeDef& port = Bit0::Io();
			return (port.IDR & kBitValue_) != 0;
		}
		else
			return false;	// an unused pin always returns false here
	}

	/// Checks if current pin electrical state is low
	ALWAYS_INLINE constexpr static bool IsLow()
	{
		if (kBitValue_ != 0)
		{
			volatile GPIO_TypeDef& port = Bit0::Io();
			return (port.IDR & kBitValue_) == 0;
		}
		else
			return false;	// an unused pin always returns false here
	}

	/// Toggles pin state
	ALWAYS_INLINE constexpr static void Toggle()
	{
		if (kBitValue_ != 0)
		{
			volatile GPIO_TypeDef& port = Bit0::Io();
			port.ODR ^= kBitValue_;
		}
	}
};


}	// namespace Gpio
}	// namespace Bmt
