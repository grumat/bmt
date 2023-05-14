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


}	// namespace Gpio
}	// namespace Bmt
