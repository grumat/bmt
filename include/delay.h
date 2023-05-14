#pragma once

#include "clocks.h"

#if defined(STM32L4)
#	include "l4xx/delay.h"
#elif defined(STM32G4)
#	include "g4xx/delay.h"
#elif defined(STM32F1)
#	include "f1xx/delay.h"
#else
#	error Unsupported target MCU
#endif

