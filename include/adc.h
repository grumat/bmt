#pragma once

#include "mcu-system.h"


namespace Bmt
{
namespace Adc
{

// ---------------------------------------------------------------------------
// Unit — typed ADC peripheral identity (common to all STM32 families)
// ---------------------------------------------------------------------------

enum class Unit : uint8_t
{
	k1,

#ifdef ADC2_BASE
	k2,
#endif

#ifdef ADC3_BASE
	k3,
#endif
};


// ---------------------------------------------------------------------------
// Sampling time literals — 3-bit SMP field encoding
//
// The numeric cycles-per-value differ between families (consult the device
// reference manual), but the enum literals are portable.
//
//   k1_5   = 0
//   k7_5   = 1
//   k13_5  = 2
//   k28_5  = 3  (default)
//   k41_5  = 4
//   k55_5  = 5
//   k71_5  = 6
//   k239_5 = 7
// ---------------------------------------------------------------------------

enum Smpl : uint8_t
{
	k1_5   = 0,
	k7_5   = 1,
	k13_5  = 2,
	k28_5  = 3,
	k41_5  = 4,
	k55_5  = 5,
	k71_5  = 6,
	k239_5 = 7,
};


} // namespace Adc
} // namespace Bmt


// ---------------------------------------------------------------------------
// Family-specific ADC template implementations
// ---------------------------------------------------------------------------

#if defined(STM32L4)
#	include "l4xx/adc.h"
#elif defined(STM32G4)
#	include "g4xx/adc.h"
#elif defined(STM32F1)
#	include "f1xx/adc.h"
#else
#	error Unsupported target MCU
#endif
