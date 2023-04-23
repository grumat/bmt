#pragma once

#include "otherlibs.h"
#include "power.h"

namespace Bmt
{


/// Core operations of the MCU
class McuCore
{
public:
	/// Enters Sleep mode (Assembler WFI instruction)
	const static void Sleep()
	{
		__WFI();
	}
	/// Aborts the program. Causes an exception.
	ALWAYS_INLINE static void Abort()
	{
		__BKPT(255);
	}
	/// General interrupt disable
	ALWAYS_INLINE static void DisableInterrupts()
	{
		__disable_irq();
	}
	/// General interrupt enable
	ALWAYS_INLINE static void EnableInterrupts()
	{
		__enable_irq();
	}
	/// Retrieves the exception number (inside an exception handler)
	ALWAYS_INLINE static uint32_t GetExceptionNum()
	{
		uint32_t result;
		asm volatile ("mrs %0, ipsr" : "=l"(result) : );
		return result & 0x1ff;
	}
	/// Checks if current MCU context is in a interrupt handler
	ALWAYS_INLINE static bool IsInterrupt()
	{
#if 1
		return GetExceptionNum() != 0;
#else 
		return (SCB->ICSR & SCB_ICSR_VECTACTIVE_Msk) != 0;
#endif
	}
	/// Lets an ISR keep MCU in sleep state after it services the ISR
	ALWAYS_INLINE static void SleepOnExit()
	{
		SCB->SCR |= (1 << SCB_SCR_SLEEPONEXIT_Pos);
	}
	/// Lets an ISR wake the MCU after it services the ISR
	ALWAYS_INLINE static void WakeOnExit()
	{
		SCB->SCR &= ~(1 << SCB_SCR_SLEEPONEXIT_Pos);
	}
};


#if defined(STM32L4)
#	include "l4xx/system.h"
#elif defined(STM32G4)
#	include "g4xx/system.h"
#elif defined(STM32F1)
#	include "f1xx/system.h"
#else
#	error Unsupported target MCU
#endif


/// Controls access to the backup domain by the object scope
/*!
Backup domain register is protected. This class disables this protection
within it's scope. The object scope controls the transaction.

\example
	// BLOCK: BkpDomainXact scope
	{
		BkpDomainXact xact;
		AnyLse<>::Init(xact);
	}
*/
class BkpDomainXact
{
public:
	BkpDomainXact()
	{
#ifdef PWR_CR1_DBP
		PWR->CR1 |= PWR_CR1_DBP;
#else
		PWR->CR |= PWR_CR_DBP;
#endif
	}
	~BkpDomainXact()
	{
#ifdef PWR_CR1_DBP
		PWR->CR1 &= ~PWR_CR1_DBP;
#else
		PWR->CR &= ~PWR_CR_DBP;
#endif
	}
};


#if DEBUG
/// Aborts program if condition is not met (DEBUG builds only)
ALWAYS_INLINE void ASSERT(bool expr) { if (expr == false) McuCore::Abort(); }
#else
/// Release version has no effect; even expression is not evaluated
ALWAYS_INLINE void ASSERT(bool expr) {}
#endif


}	// namespace Bmt
