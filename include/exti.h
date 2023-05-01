#pragma once

#include "mcu-system.h"
#include "gpio.h"


#if defined(STM32L4)
#	include "l4xx/exti.h"
#elif defined(STM32G4)
#	include "g4xx/exti.h"
#elif defined(STM32F1)
#	include "f1xx/exti.h"
#else
#	error Unsupported target MCU
#endif

