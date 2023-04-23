#pragma once

#include "mcu-system.h"
#include "pinremap.h"

namespace Bmt
{
namespace Gpio
{


/// All possible GPIO peripherals
enum class Port
{
	PA = 0,		///< Port A
	PB = 1,		///< Port B
	PC = 2,		///< Port C
#ifdef GPIOD
	PD = 3,		///< Port D
#endif
#ifdef GPIOE
	PE = 4,		///< Port E
#endif
#ifdef GPIOF
	PF = 5,		///< Port F
#endif
#ifdef GPIOG
	PG = 6,		///< Port G
#endif
#ifdef GPIOH
	PH = 7,		///< Port H
#endif
	kUnusedPort = -1
};


/// GPIO pin mode of operation
enum class Mode
{
	kInput = 0,				///< Input pin
	kAnalog,				///< Analog pin
	kOutput,				///< General purpose output (push/pull)
	kOpenDrain,				///< General purpose output (Open drain)
	kAlternate,				///< Alternate function (push/pull)
	kOpenDrainAlt,			///< Alternate function (Open drain)
};


/// Output pin speed configuration (device specific)
enum class Speed
{
	kInput = 0,				///< Input pin
	kLow = 0,				///< Low speed
	kMedium = 1,			///< Intermediate speed
	kFast = 2,				///< Lowest speed and lowest energy consumption
	kFastest = 3			///< Maximum speed and highest energy consumption (> 50 Mhz)
};


/// Pull-up or Pull-down feature
enum class PuPd
{
	kFloating = 0,			///< Floating pin
	kPullUp,				///< Activates internal Pull-up
	kPullDown,				///< Activates internal Pull-down
};


/// Pin voltage/logical level
enum class Level
{
	kLow = 0,				///< Drive pin to low voltage level
	kHigh = 1				///< Drive pin to high voltage level
};


}	// namespace Gpio
}	// namespace Bmt


#if defined(STM32L4)
#	include "l4xx/gpio.h"
#	include "l4xx/gpio-types.h"
#elif defined(STM32G4)
#	include "g4xx/gpio.h"
#	include "g4xx/gpio-types.h"
#elif defined(STM32F1)
#	include "f1xx/gpio.h"
#	include "f1xx/gpio-types.h"
#else
#	error Unsupported target MCU
#endif

