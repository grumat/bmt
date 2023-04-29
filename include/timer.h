#pragma once

#include "dma.h"

#if defined(STM32L4)
#	include "l4xx/timer.h"
#elif defined(STM32G4)
#	include "g4xx/timer.h"
#elif defined(STM32F1)
#	include "f1xx/timer.h"
#else
#	error Unsupported target MCU
#endif

