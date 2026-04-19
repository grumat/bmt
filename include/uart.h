#pragma once

#include "fifo.h"
#include "mcu-system.h"
#include "critical_section.h"
#include "irq.h"


namespace Bmt
{

enum class Usart;

using IrqForwarder = void (*)(void*);

// Internal Library Header
template <Usart U>
struct UsartIntHandler
{
	static inline IrqForwarder func;
	static inline void* cookie;
};

}	// namespace Bmt


#if defined(STM32L4)
#	include "l4xx/uart.h"
#elif defined(STM32G4)
#	include "g4xx/uart.h"
#elif defined(STM32F1)
#	include "f1xx/uart.h"
#else
#	error Unsupported target MCU
#endif

