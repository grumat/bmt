#pragma once

namespace Bmt
{
namespace Gpio
{

namespace Private
{


/// Used for specific implementation behavior
enum class Impl
{
	kNormal,	///< Normal Pin functionality
	kUnused,	///< Pin that can be initialized to a passive state, only.
	kUnchanged,	///< No change allowed (use it to setup a partial group of pins)
};


/// Private template definition, for internal use only
template<
	const Impl kImpl							///< Behavior of this implementation
	, const Port kPort							///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, const Mode kMode = Mode::kInput			///< Mode to configure the port
	, const Speed kSpeed = Speed::kInput		///< Speed for the pin
	, const PuPd kPuPd = PuPd::kFloating		///< Additional pin configuration
	, const Level kLevel = Level::kLow			///< Initial pin level
	, typename Map = AfNoRemap					///< Pin remapping feature (pinremap.h)
>
class Implementation_
{
public:
	/// A constant to record the mapping type
	typedef Map MapType;
	/// Constant storing the GPIO port number
	static constexpr Port kPort_ = kPort;
	/// Base address of the port peripheral
	static constexpr uint32_t kPortBase_ = (GPIOA_BASE + uint32_t(kPort_) * 0x400);
	/// The pin number constant value
	static constexpr uint8_t kPin_ = kPin;
	/// Constant storing desired port speed
	static constexpr Speed kSpeed_ = kSpeed;
	/// Constant storing the port configuration
	static constexpr Mode kMode_ = kMode;
	/// Constant storing desired Pull-Up/Pull-Down configuration
	static constexpr PuPd kPuPd_ = kPuPd;
	/// Input function flag
	static constexpr bool kIsInput_ = kMode_ == Mode::kInput || kMode_ == Mode::kAnalog;
	/// Input function flag
	static constexpr bool kIsPuPd_ = kPuPd_ != PuPd::kFloating && (kMode_ == Mode::kInput || kImpl == Impl::kUnused);
	/// Configuration register combo
	static constexpr uint8_t kCrBits_ = 
		(
			kIsInput_ ? 0b0000
			: kSpeed_ >= Speed::kFast ? 0b0011
			: kSpeed_ == Speed::kMedium ? 0x0001
			: 0b0010
		) + (
			kImpl == Impl::kUnused 									? 0b1000
			: kMode_ == Mode::kOpenDrain							? 0b0100
			: kMode_ == Mode::kAlternate							? 0b1000
			: kMode_ == Mode::kOpenDrainAlt							? 0b1100
			: kMode_ == Mode::kInput && kPuPd_ == PuPd::kFloating	? 0b0100
			: kMode_ == Mode::kInput								? 0b1000
																	: 0b0000
		)
		;
	/// Constant value for CRL hardware register
	static constexpr uint32_t kCRL_ = 
		(kImpl == Impl::kUnchanged)	? 0UL
		: (kPin >= 8)				? 0UL
		/*default*/					: kCrBits_ << (kPin_ << 2)
		;
	/// Constant mask value for CRL hardware register
	static constexpr uint32_t kCRL_Mask_ = 
		(kImpl == Impl::kUnchanged) ? ~0UL
		: (kPin >= 8)				? ~0UL
		/*default*/					: ~(0x0FUL << (kPin << 2))
		;
	/// Constant value for CRH hardware register
	static constexpr uint32_t kCRH_ = 
		(kImpl == Impl::kUnchanged)	? 0UL
		: (kPin < 8)				? 0UL
		/*default*/					: kCrBits_ << ((kPin - 8) << 2)
		;
	/// Constant mask value for CRH hardware register
	static constexpr uint32_t kCRH_Mask_ = 
		(kImpl == Impl::kUnchanged)	? ~0UL
		: (kPin < 8)				? ~0UL
		/*default*/					: ~(0x0FUL << ((kPin - 8) << 2))
		;
	/// Effective bit constant value
	static constexpr uint16_t kBitValue_ = 
		(kImpl == Impl::kUnchanged)	? 0UL
		/*default*/					: 1UL << kPin
		;
	/// Value that clears the bit on the GPIOx_BSRR register
	static constexpr uint32_t kBsrrValue_ = 
		(kImpl == Impl::kUnchanged) ? 0UL
		/*default*/					: 1 << (kPin + 16)
		;
	/// Constant for the initial bit level
	static constexpr uint16_t kODR_ = 
		(kImpl == Impl::kUnchanged)	? 0UL
		: kIsPuPd_					? uint16_t(kPuPd_ == PuPd::kPullUp) << kPin
		/*output*/					: uint16_t(kLevel) << kPin
		;
	/// Constant to setup ODR mask
	static constexpr uint16_t kODR_Mask_ = 
		(kImpl == Impl::kUnchanged) ? (uint16_t)~0U
		/*normal*/					: (uint16_t)~(1 << kPin)
		;
	/// Alternate Function configuration constant
	static constexpr uint32_t kAfConf_ = 
		(kImpl == Impl::kNormal)	? Map::kConf_ 
		/*no bits*/					: 0x00000000U
		;
	/// Alternate Function configuration mask constant (inverted)
	static constexpr uint32_t kAfMask_ = 
		(kImpl == Impl::kNormal)	? Map::kMask_ 
		/*no change*/				: 0xFFFFFFFFU
		;

	/// Access to the peripheral memory space
	constexpr static volatile GPIO_TypeDef* Io() { return (volatile GPIO_TypeDef*)kPortBase_; }

	// Pull resistors are not allowed
	static_assert(kMode_ != Mode::kAnalog || kPuPd_ == PuPd::kFloating, "Pull-up/down not allowed in Analog mode");
	static_assert(kImpl != Impl::kUnused || kPuPd_ != PuPd::kFloating, "Unused pins should specify PU/PD");

	/// Apply default configuration for the pin.
	constexpr static void SetupPinMode()
	{
		if (kImpl != Impl::kUnchanged)
		{
			volatile GPIO_TypeDef* port = Io();
			if (kCRL_Mask_ != ~0UL)
				port->CRL = (port->CRL & kCRL_Mask_) | kCRL_;
			if (kCRH_Mask_ != ~0UL)
				port->CRH = (port->CRH & kCRH_Mask_) | kCRH_;
		}
	}
	/// Apply default configuration for the pin.
	constexpr static void Setup()
	{
		if (kImpl != Impl::kUnchanged)
		{
			SetupPinMode();
			Map::Enable();
			if (kODR_Mask_ != (uint16_t)~0U)
			{
				volatile GPIO_TypeDef* port = Io();
				port->ODR = (port->ODR & kODR_Mask_) | kODR_;
			}
		}
	}
	/// Apply a custom configuration to the pin
	constexpr static void Setup(Mode mode, Speed speed, PuPd pupd)
	{
		if (kImpl == Impl::kNormal)
		{
			/// Input function flag
			const bool is_input = mode == Mode::kInput || mode == Mode::kAnalog;
			/// Configuration register combo
			const uint32_t cr_bits =
				(
					is_input ? 0b0000
					: speed == Speed::kFast 	? 0b0011
					: speed == Speed::kMedium 	? 0x0001
												: 0b0010
				) + (
					mode == Mode::kOpenDrain 			? 0b0100
					: mode == Mode::kAlternate 			? 0b1000
					: mode == Mode::kOpenDrainAlt 		? 0b1100
					: mode == Mode::kInput && pupd == PuPd::kFloating ? 0b0100
					: mode == Mode::kInput				? 0b1000
														: 0b0000
				)
				;
			volatile GPIO_TypeDef* port = Io();
			/// Pin number defines if CRL or CRH is used
			if (kPin < 8)
			{
				const uint32_t crl = cr_bits << (kPin << 2);
				port->CRL = (port->CRL & kCRL_Mask_) | crl;
			}
			else
			{
				const uint32_t crh = cr_bits << ((kPin - 8) << 2);
				port->CRH = (port->CRH & kCRH_Mask_) | crh;
			}
			if (is_input && pupd == PuPd::kPullUp)
				Set(true);
			else if (is_input && pupd == PuPd::kPullDown)
				Set(false);
		}
	}

	/// Sets pin up. The pin will be high as long as it is configured as GPIO output
	constexpr static void SetHigh(void)
	{
		if (kODR_Mask_ != (uint16_t)~0U)
		{
			volatile GPIO_TypeDef* port = Io();
			port->BSRR = kBitValue_;
		}
	};

	/// Sets pin down. The pin will be low as long as it is configured as GPIO output
	constexpr static void SetLow(void)
	{
		if (kODR_Mask_ != (uint16_t)~0U)
		{
			volatile GPIO_TypeDef* port = Io();
			port->BRR = kBitValue_;
		}
	}

	/// Sets the pin to the given level. Note that optimizing compiler simplifies literal constants
	constexpr static void Set(const bool value)
	{
		if (value)
			SetHigh();
		else
			SetLow();
	}

	/// Reads current Pin electrical state
	constexpr static bool Get(void)
	{
		if (kODR_Mask_ != (uint16_t)~0U)
		{
			volatile GPIO_TypeDef* port = Io();
			return (port->IDR & kBitValue_) != 0;
		}
		else
			return false;
	}

	/// Checks if current pin electrical state is high
	constexpr static bool IsHigh(void)
	{
		if (kODR_Mask_ != (uint16_t)~0U)
		{
			volatile GPIO_TypeDef *port = Io();
			return (port->IDR & kBitValue_) != 0;
		}
		else
			return false;	// an unused pin always returns false here
	}
	
	/// Checks if current pin electrical state is low
	constexpr static bool IsLow(void)
	{
		if (kODR_Mask_ != (uint16_t)~0U)
		{
			volatile GPIO_TypeDef *port = Io();
			return (port->IDR & kBitValue_) == 0;
		}
		else
			return false;	// an unused pin always returns false here
	}

	/// Toggles pin state
	constexpr static void Toggle(void)
	{
		if (kODR_Mask_ != (uint16_t)~0U)
		{
			volatile GPIO_TypeDef *port = Io();
			port->ODR ^= kBitValue_;
		}
	}
};


}	// namespace Private


/*!
**	@brief Defines/Sets up a single GPIO pin
**
**	This template sets up a single GPIO pin. Methods allows one to bit bang pin
**	or read its input state.
**
**	An additional powerful feature is to combine all need GPIO pin definition
**	together into a AnyPortSetup<> data type, which is able to setup the
**	entire GPIO port in a couple of CPU instructions.
**
**	Example:
**		// Sets a data-type to drive an SPI1 CLK output
**		typedef AnyPin<Port::PA, 5, Mode::kOutput, Speed::kFast, Level::kHigh> MY_SPI_CLK;
**
**	Also see the shortcut templates that reduces the clutter to declare common
**	IO forms: AnyIn<>, Floating<>, AnyInPu<> and AnyInPd<>.
**
**	Device specific peripherals are also mapped into handy data-types, like for
**	example: SPI1_SCK_PA5, ADC12_IN0 and TIM2_CH2_PA1.
**
**	@tparam kPort: the GPIO port.
**	@tparam kPin: The GPIO pin number.
**	@tparam kMode: Defines pin direction or output configuration.
**	@tparam kPuPd: Defines pull up/Pull down activity.
**	@tparam kLevel: Defines the level of the pin to be initialized.
**	@tparam Map: A data-type that allows STM32 Pin Remap. Definitions are found on remap.h.
*/
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin					///< The pin of the port
	, const Mode kMode = Mode::kInput		///< Mode to configure the port
	, const Speed kSpeed = Speed::kInput	///< Speed for the pin
	, const PuPd kPuPd = PuPd::kFloating	///< Additional pin configuration (applies to input pin)
	, const Level kLevel = Level::kLow		///< Initial pin level (applies to output pin)
	, typename Map = AfNoRemap				///< Pin remapping feature (pinremap.h)
>
class AnyPin : public Private::Implementation_<
	Private::Impl::kNormal
	, kPort
	, kPin
	, kMode
	, kSpeed
	, kPuPd
	, kLevel
	, Map
>
{};


/// A template class representing an unused pin
template<
	const uint8_t kPin						///< the pin number
	, const PuPd kPuPd = PuPd::kPullDown	///< Always configured as input; PD/PU selectable
>
class Unused : public Private::Implementation_
	<
	Private::Impl::kUnused
	, Port::kUnusedPort
	, kPin
	, Mode::kInput
	, Speed::kInput
	, kPuPd
	>
{
};


/// A template pin configuration for a pin that should not be affected
template<
	const uint8_t kPin						///< Pin number is required
>
class Unchanged : public Private::Implementation_
	<
	Private::Impl::kUnchanged
	, Port::kUnusedPort
	, kPin
	>
{
};


//! Template for input pins
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin					///< The pin of the port
	, typename Map = AfNoRemap				///< Pin remapping feature (pinremap.h)
>
class AnyAnalog : public Private::Implementation_<
	Private::Impl::kNormal
	, kPort
	, kPin
	, Mode::kAnalog
	, Speed::kInput
	, PuPd::kFloating
	, Level::kLow
	, Map
>
{};


//! Template for input pins
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, const PuPd kPuPd = PuPd::kFloating		///< Additional pin configuration (applies to input pin)
	, typename Map = AfNoRemap					///< Pin remapping feature (pinremap.h)
>
class AnyIn : public Private::Implementation_<
	Private::Impl::kNormal
	, kPort
	, kPin
	, Mode::kInput
	, Speed::kInput
	, kPuPd
	, Level::kLow
	, Map
>
{};


/// A template class to configure a port pin as a floating input pin
template <
	const Port kPort		///< The GPIO port
	, const uint8_t kPin		///< The GPIO pin number
	, typename Map = AfNoRemap	///< Pin remapping feature (pinremap.h)
>
class Floating : public AnyIn<kPort, kPin, PuPd::kFloating, Map>
{
};


/// A template class to configure a port pin as digital input having a pull-up
template <
	const Port kPort
	, const uint8_t kPin
	, typename Map = AfNoRemap	///< Pin remapping feature (pinremap.h)
>
class AnyInPu : public AnyIn<kPort, kPin, PuPd::kPullUp, Map>
{
};


/// A template class to configure a port pin as digital input having a pull-down
template <
	const Port kPort
	, const uint8_t kPin
	, typename Map = AfNoRemap	///< Pin remapping feature (pinremap.h)
>
class AnyInPd : public AnyIn<kPort, kPin, PuPd::kPullDown, Map>
{
};


//! Template for output pins
template<
	const Port kPort							///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, const Speed kSpeed = Speed::kFast			///< Speed for the pin
	, const Level kLevel = Level::kLow			///< Initial pin level (applies to output pin)
	, const Mode kMode = Mode::kOutput			///< Mode to configure the port
	, typename Map = AfNoRemap					///< Pin remapping feature (pinremap.h)
>
class AnyOut : public Private::Implementation_<
	Private::Impl::kNormal
	, kPort
	, kPin
	, kMode
	, kSpeed
	, PuPd::kFloating
	, kLevel
	, Map
>
{
private:
	constexpr void Validate_()
	{
		static_assert(kMode >= Mode::kOutput, "template requires an output pin configuration");
	}
};


//! Template for fast output pins at logic level low
template<
	const Port kPort							///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, typename Map = AfNoRemap					///< Pin remapping feature (pinremap.h)
>
class AnyFastOut0 : public AnyOut<
	kPort
	, kPin
	, Speed::kFast
	, Level::kLow
	, Mode::kOutput
	, Map
>
{
};


//! Template for fast output pins at logic level hi
template<
	const Port kPort							///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, typename Map = AfNoRemap					///< Pin remapping feature (pinremap.h)
>
class AnyFastOut1 : public AnyOut<
	kPort
	, kPin
	, Speed::kFast
	, Level::kHigh
	, Mode::kOutput
	, Map
>
{
};


//! Template for open drain output pins
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, const Speed kSpeed = Speed::kFast			///< Speed for the pin
	, const Level kLevel = Level::kLow			///< Initial pin level (applies to output pin)
	, typename Map = AfNoRemap					///< Pin remapping feature (pinremap.h)
>
class AnyOutOD : public AnyOut<
	kPort
	, kPin
	, kSpeed
	, kLevel
	, Mode::kOpenDrain
	, Map
>
{
};


//! Template for generic alternate output pins
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, typename Map								///< Pin remapping feature (pinremap.h)
	, const Speed kSpeed = Speed::kFast			///< Speed for the pin
	, const Level kLevel = Level::kLow			///< Initial pin level (applies to output pin)
	, const PuPd kPuPd = PuPd::kFloating		///< Additional pin configuration
	, const Mode kMode = Mode::kAlternate		///< Mode to configure the port
>
class AnyAltOut : public Private::Implementation_<
	Private::Impl::kNormal
	, kPort
	, kPin
	, kMode
	, kSpeed
	, kPuPd
	, kLevel
	, Map
>
{
private:
	constexpr void Validate_()
	{
		static_assert(kMode >= Mode::kAlternate, "template requires an alternate output pin configuration");
	}
};


//! Template for Push-Pull alternate output pins
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, typename Map								///< Pin remapping feature (pinremap.h)
	, const Speed kSpeed = Speed::kFast			///< Speed for the pin
	, const Level kLevel = Level::kLow			///< Initial pin level (applies to output pin)
>
class AnyAltOutPP : public AnyAltOut <
	kPort
	, kPin
	, Map
	, kSpeed
	, kLevel
	, PuPd::kFloating
	, Mode::kAlternate
>
{
};


//! Template for Open-Drain alternate output pins
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, typename Map								///< Pin remapping feature (pinremap.h)
	, const Speed kSpeed = Speed::kFast			///< Speed for the pin
	, const Level kLevel = Level::kLow			///< Initial pin level (applies to output pin)
>
class AnyAltOutOD : public AnyAltOut <
	kPort
	, kPin
	, Map
	, kSpeed
	, kLevel
	, PuPd::kPullUp		// unsupported by this hardware
	, Mode::kOpenDrainAlt
>
{
};


/// A template class for a group of related pins to be operated all at once
/*!
Pretty same as AnyPortSetup<> template, although not all pins have to be 
defined. The only requirement is that pin numbers have to be unique. 
Although recommended pins must not be ordered.
*/
template <
	const Port kPort					/// The GPIO port number
	, typename Pin0 = Unchanged<0>		/// Definition for any pin, any order
	, typename Pin1 = Unchanged<1>		/// Definition for any pin, any order
	, typename Pin2 = Unchanged<2>		/// Definition for any pin, any order
	, typename Pin3 = Unchanged<3>		/// Definition for any pin, any order
	, typename Pin4 = Unchanged<4>		/// Definition for any pin, any order
	, typename Pin5 = Unchanged<5>		/// Definition for any pin, any order
	, typename Pin6 = Unchanged<6>		/// Definition for any pin, any order
	, typename Pin7 = Unchanged<7>		/// Definition for any pin, any order
	, typename Pin8 = Unchanged<8>		/// Definition for any pin, any order
	, typename Pin9 = Unchanged<9>		/// Definition for any pin, any order
	, typename Pin10 = Unchanged<10>	/// Definition for any pin, any order
	, typename Pin11 = Unchanged<11>	/// Definition for any pin, any order
	, typename Pin12 = Unchanged<12>	/// Definition for any pin, any order
	, typename Pin13 = Unchanged<13>	/// Definition for any pin, any order
	, typename Pin14 = Unchanged<14>	/// Definition for any pin, any order
	, typename Pin15 = Unchanged<15>	/// Definition for any pin, any order
	>
class AnyPinGroup
{
public:
	/// The GPIO port peripheral
	static constexpr Port kPort_ = kPort;
	/// The base address for the GPIO peripheral registers
	static constexpr uint32_t kPortBase_ = (GPIOA_BASE + uint32_t(kPort_) * 0x400);
	/// Combined constant value for CRL hardware register
	static constexpr uint32_t kCRL_ =
		Pin0::kCRL_ | Pin1::kCRL_
		| Pin2::kCRL_ | Pin3::kCRL_
		| Pin4::kCRL_ | Pin5::kCRL_
		| Pin6::kCRL_ | Pin7::kCRL_
		| Pin8::kCRL_ | Pin9::kCRL_
		| Pin10::kCRL_ | Pin11::kCRL_
		| Pin12::kCRL_ | Pin13::kCRL_
		| Pin14::kCRL_ | Pin15::kCRL_
		;
	/// Combined constant mask value for CRL hardware register
	static constexpr uint32_t kCRL_Mask_ =
		Pin0::kCRL_Mask_ & Pin1::kCRL_Mask_
		& Pin2::kCRL_Mask_ & Pin3::kCRL_Mask_
		& Pin4::kCRL_Mask_ & Pin5::kCRL_Mask_
		& Pin6::kCRL_Mask_ & Pin7::kCRL_Mask_
		& Pin8::kCRL_Mask_ & Pin9::kCRL_Mask_
		& Pin10::kCRL_Mask_ & Pin11::kCRL_Mask_
		& Pin12::kCRL_Mask_ & Pin13::kCRL_Mask_
		& Pin14::kCRL_Mask_ & Pin15::kCRL_Mask_
		;
	/// Combined constant value for CRH hardware register (negative logic)
	static constexpr uint32_t kCRH_ =
		Pin0::kCRH_ | Pin1::kCRH_
		| Pin2::kCRH_ | Pin3::kCRH_
		| Pin4::kCRH_ | Pin5::kCRH_
		| Pin6::kCRH_ | Pin7::kCRH_
		| Pin8::kCRH_ | Pin9::kCRH_
		| Pin10::kCRH_ | Pin11::kCRH_
		| Pin12::kCRH_ | Pin13::kCRH_
		| Pin14::kCRH_ | Pin15::kCRH_
		;
	/// Combined constant mask value for CRH hardware register
	static constexpr uint32_t kCRH_Mask_ =
		Pin0::kCRH_Mask_ & Pin1::kCRH_Mask_
		& Pin2::kCRH_Mask_ & Pin3::kCRH_Mask_
		& Pin4::kCRH_Mask_ & Pin5::kCRH_Mask_
		& Pin6::kCRH_Mask_ & Pin7::kCRH_Mask_
		& Pin8::kCRH_Mask_ & Pin9::kCRH_Mask_
		& Pin10::kCRH_Mask_ & Pin11::kCRH_Mask_
		& Pin12::kCRH_Mask_ & Pin13::kCRH_Mask_
		& Pin14::kCRH_Mask_ & Pin15::kCRH_Mask_
		;
	/// Constant for the initial bit level
	static constexpr uint16_t kODR_ =
		Pin0::kODR_ | Pin1::kODR_
		| Pin2::kODR_ | Pin3::kODR_
		| Pin4::kODR_ | Pin5::kODR_
		| Pin6::kODR_ | Pin7::kODR_
		| Pin8::kODR_ | Pin9::kODR_
		| Pin10::kODR_ | Pin11::kODR_
		| Pin12::kODR_ | Pin13::kODR_
		| Pin14::kODR_ | Pin15::kODR_
		;
	/// Combined constant mask value for ODR hardware register
	static constexpr uint16_t kODR_Mask_ =
		Pin0::kODR_Mask_ & Pin1::kODR_Mask_
		& Pin2::kODR_Mask_ & Pin3::kODR_Mask_
		& Pin4::kODR_Mask_ & Pin5::kODR_Mask_
		& Pin6::kODR_Mask_ & Pin7::kODR_Mask_
		& Pin8::kODR_Mask_ & Pin9::kODR_Mask_
		& Pin10::kODR_Mask_ & Pin11::kODR_Mask_
		& Pin12::kODR_Mask_ & Pin13::kODR_Mask_
		& Pin14::kODR_Mask_ & Pin15::kODR_Mask_
		;
	/// Combined Alternate Function configuration constant
	static constexpr uint32_t kAfConf_ =
		Pin0::kAfConf_ | Pin1::kAfConf_
		| Pin2::kAfConf_ | Pin3::kAfConf_
		| Pin4::kAfConf_ | Pin5::kAfConf_
		| Pin6::kAfConf_ | Pin7::kAfConf_
		| Pin8::kAfConf_ | Pin9::kAfConf_
		| Pin10::kAfConf_ | Pin11::kAfConf_
		| Pin12::kAfConf_ | Pin13::kAfConf_
		| Pin14::kAfConf_ | Pin15::kAfConf_
		;
	/// Combined Alternate Function configuration mask constant (inverted)
	static constexpr uint32_t kAfMask_ =
		Pin0::kAfMask_ & Pin1::kAfMask_
		& Pin2::kAfMask_ & Pin3::kAfMask_
		& Pin4::kAfMask_ & Pin5::kAfMask_
		& Pin6::kAfMask_ & Pin7::kAfMask_
		& Pin8::kAfMask_ & Pin9::kAfMask_
		& Pin10::kAfMask_ & Pin11::kAfMask_
		& Pin12::kAfMask_ & Pin13::kAfMask_
		& Pin14::kAfMask_ & Pin15::kAfMask_
		;

	/// Access to the hardware IO data structure
	constexpr static volatile GPIO_TypeDef& Io() { return *(volatile GPIO_TypeDef*)kPortBase_; }

	// Validates the PIN0
	static_assert(Pin0::kPort_ == Port::kUnusedPort 
		|| (
			Pin0::kPort_ == kPort_
			&& (Pin0::kPin_ != Pin1::kPin_ || Pin1::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin2::kPin_ || Pin2::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin3::kPin_ || Pin3::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin4::kPin_ || Pin4::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin5::kPin_ || Pin5::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin6::kPin_ || Pin6::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin7::kPin_ || Pin7::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin8::kPin_ || Pin8::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin9::kPin_ || Pin9::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin10::kPin_ || Pin10::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin11::kPin_ || Pin11::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin12::kPin_ || Pin12::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin0::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN0: Inconsistent port number or pin number collision");
	// Validates the PIN1
	static_assert(Pin1::kPort_ == Port::kUnusedPort 
		|| (
			Pin1::kPort_ == kPort_
			&& (Pin1::kPin_ != Pin2::kPin_ || Pin2::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin3::kPin_ || Pin3::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin4::kPin_ || Pin4::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin5::kPin_ || Pin5::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin6::kPin_ || Pin6::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin7::kPin_ || Pin7::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin8::kPin_ || Pin8::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin9::kPin_ || Pin9::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin10::kPin_ || Pin10::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin11::kPin_ || Pin11::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin12::kPin_ || Pin12::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin1::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN1: Inconsistent port number or pin number collision");
	// Validates the PIN2
	static_assert(Pin2::kPort_ == Port::kUnusedPort 
		|| (
			Pin2::kPort_ == kPort_
			&& (Pin2::kPin_ != Pin3::kPin_ || Pin3::kPort_ == Port::kUnusedPort)
			&& (Pin2::kPin_ != Pin4::kPin_ || Pin4::kPort_ == Port::kUnusedPort)
			&& (Pin2::kPin_ != Pin5::kPin_ || Pin5::kPort_ == Port::kUnusedPort)
			&& (Pin2::kPin_ != Pin6::kPin_ || Pin6::kPort_ == Port::kUnusedPort)
			&& (Pin2::kPin_ != Pin7::kPin_ || Pin7::kPort_ == Port::kUnusedPort)
			&& (Pin2::kPin_ != Pin8::kPin_ || Pin8::kPort_ == Port::kUnusedPort)
			&& (Pin2::kPin_ != Pin9::kPin_ || Pin9::kPort_ == Port::kUnusedPort)
			&& (Pin2::kPin_ != Pin10::kPin_ || Pin10::kPort_ == Port::kUnusedPort)
			&& (Pin2::kPin_ != Pin11::kPin_ || Pin11::kPort_ == Port::kUnusedPort)
			&& (Pin2::kPin_ != Pin12::kPin_ || Pin12::kPort_ == Port::kUnusedPort)
			&& (Pin2::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin2::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin2::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN2: Inconsistent port number or pin number collision");
	// Validates the PIN3
	static_assert(Pin3::kPort_ == Port::kUnusedPort 
		|| (
			Pin3::kPort_ == kPort_
			&& (Pin3::kPin_ != Pin4::kPin_ || Pin4::kPort_ == Port::kUnusedPort)
			&& (Pin3::kPin_ != Pin5::kPin_ || Pin5::kPort_ == Port::kUnusedPort)
			&& (Pin3::kPin_ != Pin6::kPin_ || Pin6::kPort_ == Port::kUnusedPort)
			&& (Pin3::kPin_ != Pin7::kPin_ || Pin7::kPort_ == Port::kUnusedPort)
			&& (Pin3::kPin_ != Pin8::kPin_ || Pin8::kPort_ == Port::kUnusedPort)
			&& (Pin3::kPin_ != Pin9::kPin_ || Pin9::kPort_ == Port::kUnusedPort)
			&& (Pin3::kPin_ != Pin10::kPin_ || Pin10::kPort_ == Port::kUnusedPort)
			&& (Pin3::kPin_ != Pin11::kPin_ || Pin11::kPort_ == Port::kUnusedPort)
			&& (Pin3::kPin_ != Pin12::kPin_ || Pin12::kPort_ == Port::kUnusedPort)
			&& (Pin3::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin3::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin3::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN3: Inconsistent port number or pin number collision");
	// Validates the PIN4
	static_assert(Pin4::kPort_ == Port::kUnusedPort 
		|| (
			Pin4::kPort_ == kPort_
			&& (Pin4::kPin_ != Pin5::kPin_ || Pin5::kPort_ == Port::kUnusedPort)
			&& (Pin4::kPin_ != Pin6::kPin_ || Pin6::kPort_ == Port::kUnusedPort)
			&& (Pin4::kPin_ != Pin7::kPin_ || Pin7::kPort_ == Port::kUnusedPort)
			&& (Pin4::kPin_ != Pin8::kPin_ || Pin8::kPort_ == Port::kUnusedPort)
			&& (Pin4::kPin_ != Pin9::kPin_ || Pin9::kPort_ == Port::kUnusedPort)
			&& (Pin4::kPin_ != Pin10::kPin_ || Pin10::kPort_ == Port::kUnusedPort)
			&& (Pin4::kPin_ != Pin11::kPin_ || Pin11::kPort_ == Port::kUnusedPort)
			&& (Pin4::kPin_ != Pin12::kPin_ || Pin12::kPort_ == Port::kUnusedPort)
			&& (Pin4::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin4::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin4::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN4: Inconsistent port number or pin number collision");
	// Validates the PIN5
	static_assert(Pin5::kPort_ == Port::kUnusedPort 
		|| (
			Pin5::kPort_ == kPort_
			&& (Pin5::kPin_ != Pin6::kPin_ || Pin6::kPort_ == Port::kUnusedPort)
			&& (Pin5::kPin_ != Pin7::kPin_ || Pin7::kPort_ == Port::kUnusedPort)
			&& (Pin5::kPin_ != Pin8::kPin_ || Pin8::kPort_ == Port::kUnusedPort)
			&& (Pin5::kPin_ != Pin9::kPin_ || Pin9::kPort_ == Port::kUnusedPort)
			&& (Pin5::kPin_ != Pin10::kPin_ || Pin10::kPort_ == Port::kUnusedPort)
			&& (Pin5::kPin_ != Pin11::kPin_ || Pin11::kPort_ == Port::kUnusedPort)
			&& (Pin5::kPin_ != Pin12::kPin_ || Pin12::kPort_ == Port::kUnusedPort)
			&& (Pin5::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin5::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin5::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN5: Inconsistent port number or pin number collision");
	// Validates the PIN6
	static_assert(Pin6::kPort_ == Port::kUnusedPort 
		|| (
			Pin6::kPort_ == kPort_
			&& (Pin6::kPin_ != Pin7::kPin_ || Pin7::kPort_ == Port::kUnusedPort)
			&& (Pin6::kPin_ != Pin8::kPin_ || Pin8::kPort_ == Port::kUnusedPort)
			&& (Pin6::kPin_ != Pin9::kPin_ || Pin9::kPort_ == Port::kUnusedPort)
			&& (Pin6::kPin_ != Pin10::kPin_ || Pin10::kPort_ == Port::kUnusedPort)
			&& (Pin6::kPin_ != Pin11::kPin_ || Pin11::kPort_ == Port::kUnusedPort)
			&& (Pin6::kPin_ != Pin12::kPin_ || Pin12::kPort_ == Port::kUnusedPort)
			&& (Pin6::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin6::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin6::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN6: Inconsistent port number or pin number collision");
	// Validates the PIN7
	static_assert(Pin7::kPort_ == Port::kUnusedPort 
		|| (
			Pin7::kPort_ == kPort_
			&& (Pin7::kPin_ != Pin8::kPin_ || Pin8::kPort_ == Port::kUnusedPort)
			&& (Pin7::kPin_ != Pin9::kPin_ || Pin9::kPort_ == Port::kUnusedPort)
			&& (Pin7::kPin_ != Pin10::kPin_ || Pin10::kPort_ == Port::kUnusedPort)
			&& (Pin7::kPin_ != Pin11::kPin_ || Pin11::kPort_ == Port::kUnusedPort)
			&& (Pin7::kPin_ != Pin12::kPin_ || Pin12::kPort_ == Port::kUnusedPort)
			&& (Pin7::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin7::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin7::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN7: Inconsistent port number or pin number collision");
	// Validates the PIN8
	static_assert(Pin8::kPort_ == Port::kUnusedPort 
		|| (
			Pin8::kPort_ == kPort_
			&& (Pin8::kPin_ != Pin9::kPin_ || Pin9::kPort_ == Port::kUnusedPort)
			&& (Pin8::kPin_ != Pin10::kPin_ || Pin10::kPort_ == Port::kUnusedPort)
			&& (Pin8::kPin_ != Pin11::kPin_ || Pin11::kPort_ == Port::kUnusedPort)
			&& (Pin8::kPin_ != Pin12::kPin_ || Pin12::kPort_ == Port::kUnusedPort)
			&& (Pin8::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin8::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin8::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN8: Inconsistent port number or pin number collision");
	// Validates the PIN9
	static_assert(Pin9::kPort_ == Port::kUnusedPort 
		|| (
			Pin9::kPort_ == kPort_
			&& (Pin9::kPin_ != Pin10::kPin_ || Pin10::kPort_ == Port::kUnusedPort)
			&& (Pin9::kPin_ != Pin11::kPin_ || Pin11::kPort_ == Port::kUnusedPort)
			&& (Pin9::kPin_ != Pin12::kPin_ || Pin12::kPort_ == Port::kUnusedPort)
			&& (Pin9::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin9::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin9::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN9: Inconsistent port number or pin number collision");
	// Validates the PIN10
	static_assert(Pin10::kPort_ == Port::kUnusedPort 
		|| (
			Pin10::kPort_ == kPort_
			&& (Pin10::kPin_ != Pin11::kPin_ || Pin11::kPort_ == Port::kUnusedPort)
			&& (Pin10::kPin_ != Pin12::kPin_ || Pin12::kPort_ == Port::kUnusedPort)
			&& (Pin10::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin10::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin10::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN10: Inconsistent port number or pin number collision");
	// Validates the PIN11
	static_assert(Pin11::kPort_ == Port::kUnusedPort 
		|| (
			Pin11::kPort_ == kPort_
			&& (Pin11::kPin_ != Pin12::kPin_ || Pin12::kPort_ == Port::kUnusedPort)
			&& (Pin11::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin11::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin11::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN11: Inconsistent port number or pin number collision");
	// Validates the PIN12
	static_assert(Pin12::kPort_ == Port::kUnusedPort 
		|| (
			Pin12::kPort_ == kPort_
			&& (Pin12::kPin_ != Pin13::kPin_ || Pin13::kPort_ == Port::kUnusedPort)
			&& (Pin12::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin12::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN12: Inconsistent port number or pin number collision");
	// Validates the PIN13
	static_assert(Pin13::kPort_ == Port::kUnusedPort 
		|| (
			Pin13::kPort_ == kPort_
			&& (Pin13::kPin_ != Pin14::kPin_ || Pin14::kPort_ == Port::kUnusedPort)
			&& (Pin13::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN13: Inconsistent port number or pin number collision");
	// Validates the PIN14
	static_assert(Pin14::kPort_ == Port::kUnusedPort
		|| (
			Pin14::kPort_ == kPort_
			&& (Pin14::kPin_ != Pin15::kPin_ || Pin15::kPort_ == Port::kUnusedPort)
		)
		, "PIN14: Inconsistent port number or pin number collision");
	// Validates the PIN15
	static_assert(Pin15::kPort_ == Port::kUnusedPort || Pin15::kPort_ == kPort_
		, "PIN15: Inconsistent port number or pin number collision");

	//! Apply state of pin group merging with previous GPI contents
	constexpr static void Enable()
	{
		// Apply Alternate Function configuration
		AnyAFR<kAfConf_, kAfMask_>::Enable();
		// Base address of the peripheral registers
		volatile GPIO_TypeDef& port = Io();
		if (kCRL_Mask_ == 0UL)
			port.CRL = kCRL_;
		else if (kCRL_Mask_ != ~0UL)
			port.CRL = (port.CRL & kCRL_Mask_) | kCRL_;
		if (kCRH_Mask_ == 0UL)
			port.CRH = kCRH_;
		else if (kCRH_Mask_ != ~0UL)
			port.CRH = (port.CRH & kCRH_Mask_) | kCRH_;
		if (kODR_Mask_ == 0U)
			port.ODR = kODR_;
		else if (kODR_Mask_ != (uint16_t)~0U)
			port.ODR = (port.ODR & kODR_Mask_) | kODR_;
	}
	//! Not an ideal approach, but float everything
	constexpr static void Disable()
	{
		// Base address of the peripheral registers
		volatile GPIO_TypeDef& port = Io();
		RCC->APB2ENR |= (1 << (uint32_t(kPort_) + RCC_APB2ENR_IOPAEN_Pos));
		volatile uint32_t delay = RCC->APB2ENR & (1 << (uint32_t(kPort_) + RCC_APB2ENR_IOPAEN_Pos));
		port.CRL = 0x44444444;
		port.CRH = 0x44444444;
		// Remove bits applying inverted Alternate Function configuration mask constant
		AFIO->MAPR &= kAfMask_;
		RCC->APB2ENR &= ~(1 << (uint32_t(kPort_) + RCC_APB2ENR_IOPAEN_Pos));
	}

protected:
	// Enables clock on the RCC peripheral
	constexpr static void EnableClock()
	{
		// Base address of the peripheral registers
		// Don't turn alternate function clock on if not required
		if (kAfMask_ == ~0UL)
			RCC->APB2ENR |= (1 << (uint32_t(kPort_) + RCC_APB2ENR_IOPAEN_Pos));
		else
			RCC->APB2ENR |= (1 << (uint32_t(kPort_) + RCC_APB2ENR_IOPAEN_Pos)) | RCC_APB2ENR_AFIOEN;
	}
};


/// A template class to configure a GPIO port at once (optimizes code footprint)
/*!
Usual port program happens bit by bit, which tends to produce too much unnecessary code.
By combining pin templates with this class it is possible to group multiple GPIO pins
into a single operation. By grouping pins that cooperates logicall into a group it is
possible to prepare predefined states according to a function group.

Example:

This configuration is a sample code to setup the GPIO for the USART1 through PA9/PA10
and a LED on PA0.
\code{.cpp}
/// Pin for green LED
typedef AnyOut<Port::PA, 0, Speed::kOutput2MHz, Level::kHigh> GREEN_LED;
/// Initial configuration for PORTA
typedef AnyPortSetup <Port::PA
	, GREEN_LED			///< bit bang
	, Unused<1>		///< not used
	, Unused<2>		///< not used
	, Unused<3>		///< not used
	, Unused<4>		///< not used
	, Unused<5>		///< not used
	, Unused<6>		///< not used
	, Unused<7>		///< not used
	, Unused<8>		///< not used
	, USART1_TX_PA9		///< GDB UART port
	, USART1_RX_PA10	///< GDB UART port
	, Unused<11>		///< USB-
	, Unused<12>		///< USB+
	, Unused<13>		///< STM32 TMS/SWDIO
	, Unused<14>		///< STM32 TCK/SWCLK
	, Unused<15>		///< STM32 TDI
> PORTA;

void MyHardwareInit()
{
	// Configure ports
	PORTA::Init();
}
\endcode
*/
template <
	const Port kPort				/// The GPIO port number
	, typename Pin0 = Unused<0>		/// Definition for bit 0 (defaults to unused pin, i.e an inputs)
	, typename Pin1 = Unused<1>		/// Definition for bit 1 (defaults to unused pin, i.e an inputs)
	, typename Pin2 = Unused<2>		/// Definition for bit 2 (defaults to unused pin, i.e an inputs)
	, typename Pin3 = Unused<3>		/// Definition for bit 3 (defaults to unused pin, i.e an inputs)
	, typename Pin4 = Unused<4>		/// Definition for bit 4 (defaults to unused pin, i.e an inputs)
	, typename Pin5 = Unused<5>		/// Definition for bit 5 (defaults to unused pin, i.e an inputs)
	, typename Pin6 = Unused<6>		/// Definition for bit 6 (defaults to unused pin, i.e an inputs)
	, typename Pin7 = Unused<7>		/// Definition for bit 7 (defaults to unused pin, i.e an inputs)
	, typename Pin8 = Unused<8>		/// Definition for bit 8 (defaults to unused pin, i.e an inputs)
	, typename Pin9 = Unused<9>		/// Definition for bit 9 (defaults to unused pin, i.e an inputs)
	, typename Pin10 = Unused<10>	/// Definition for bit 10 (defaults to unused pin, i.e an inputs)
	, typename Pin11 = Unused<11>	/// Definition for bit 11 (defaults to unused pin, i.e an inputs)
	, typename Pin12 = Unused<12>	/// Definition for bit 12 (defaults to unused pin, i.e an inputs)
	, typename Pin13 = Unused<13>	/// Definition for bit 13 (defaults to unused pin, i.e an inputs)
	, typename Pin14 = Unused<14>	/// Definition for bit 14 (defaults to unused pin, i.e an inputs)
	, typename Pin15 = Unused<15>	/// Definition for bit 15 (defaults to unused pin, i.e an inputs)
>
class AnyPortSetup : public AnyPinGroup<
	kPort,
	Pin0,	Pin1,	Pin2,	Pin3,
	Pin4,	Pin5,	Pin6,	Pin7,
	Pin8,	Pin9,	Pin10,	Pin11,
	Pin12,	Pin13,	Pin14,	Pin15
	>
{
public:
	typedef AnyPinGroup<
		kPort,
		Pin0,	Pin1,	Pin2,	Pin3, 
		Pin4,	Pin5,	Pin6,	Pin7,
		Pin8,	Pin9,	Pin10,	Pin11,
		Pin12,	Pin13,	Pin14,	Pin15
	> SUPER;

	// Compilation will fail here if one GPIO pin number does not match its **position**
	static_assert(
		Pin0::kPin_ == 0 && Pin1::kPin_ == 1 && Pin2::kPin_ == 2 && Pin3::kPin_ == 3
		&& Pin4::kPin_ == 4 && Pin5::kPin_ == 5 && Pin6::kPin_ == 6 && Pin7::kPin_ == 7
		&& Pin8::kPin_ == 8 && Pin9::kPin_ == 9 && Pin10::kPin_ == 10 && Pin11::kPin_ == 11
		&& Pin12::kPin_ == 12 && Pin13::kPin_ == 13 && Pin14::kPin_ == 14 && Pin15::kPin_ == 15
		, "Inconsistent pin position"
		);

	/// Initialize to GPIO overwriting all previous configuration of the port
	/// This means that Unchanged<> pins have the same behavior as Unused<>.
	constexpr static void Init(void)
	{
		/*
		** Note all constants (i.e. constexpr) are resolved at compile time and unused code is stripped
		** out by compiler, even for an unoptimized build.
		*/

		SUPER::EnableClock();
		// Apply Alternate Function configuration
		AnyAFR<SUPER::kAfConf_, SUPER::kAfMask_>::Enable();
		// Apply
		SUPER::Enable();
	}
};

/// Keeps a copy of the current GPIO state and restores on scope exit
/*!
This class is useful to save current state of the GPIO registers and restore them 
on exit. This is useful when one wants to perform simple changes on the GPIO 
configuration for a short period and later restore to the previous state.

Note that this affects all bits of the port.
*/
template<const Port kPort>
class SaveGpio
{
public:
	static constexpr Port kPort_ = kPort;
	static constexpr uint32_t kPortBase_ = (GPIOA_BASE + uint32_t(kPort_) * 0x400);

	/// Access to the hardware IO data structure
	constexpr static volatile GPIO_TypeDef& Io() { return *(volatile GPIO_TypeDef*)kPortBase_; }

	/// Keeps a copy of the current GPIO state and restores on scope exit
	SaveGpio()
	{
		// Base address of the peripheral registers
		volatile GPIO_TypeDef& port = Io();
		// Make a copy of the hardware registers
		odr_ = port.ODR;
		crl_ = port.CRL;
		crh_ = port.CRH;
		mapr_ = AFIO->MAPR;
	}
	~SaveGpio()
	{
		// Base address of the peripheral registers
		volatile GPIO_TypeDef& port = Io();
		// REstores all hardware registers
		port.ODR = odr_;
		port.CRL = crl_;
		port.CRH = crh_;
		AFIO->MAPR = mapr_;
	}

protected:
	/// Copy of the ODR hardware register
	uint32_t odr_;
	/// Copy of the CRL hardware register
	uint32_t crl_;
	/// Copy of the CRH hardware register
	uint32_t crh_;
	/// Copy of the MAPR hardware register
	uint32_t mapr_;
};


}	// namespace Gpio
}	// namespace Bmt
