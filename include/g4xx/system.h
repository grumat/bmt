#pragma once

namespace Bmt
{
namespace System
{

enum class FlashOpts : uint32_t
{
	kDefault = 0,
	kNoDataCache = 1,
	kNoInstrCache = 2,
	kNoPrefetch = 4,
};
constexpr FlashOpts operator&(FlashOpts o1, FlashOpts o2)
{
	return FlashOpts((uint32_t)o1 & (uint32_t)o2);
}
constexpr FlashOpts operator|(FlashOpts o1, FlashOpts o2)
{
	return FlashOpts((uint32_t)o1 | (uint32_t)o2);
}


template<
	const uint32_t kFreq = 8000000UL, 	//!< Frequency
	const Power::Mode kPower = Power::Mode::kRange1,
	const FlashOpts kOpts = FlashOpts::kDefault
>
class WaitState
{
public:
	// Frequency of the clock source
	static constexpr uint32_t kFrequency_ = kFreq;
	static constexpr Power::Mode kPower_ = kPower;
	static constexpr bool kPrefetch_ = (kOpts & FlashOpts::kNoPrefetch) == FlashOpts::kDefault;
	static constexpr bool kICache_ = (kOpts & FlashOpts::kNoInstrCache) == FlashOpts::kDefault;
	static constexpr bool kDCache_ = (kOpts & FlashOpts::kNoDataCache) == FlashOpts::kDefault;

	static constexpr void Setup()
	{
		uint32_t tmp = 0;
		if (kPower_ == Power::Mode::kRange1)
		{
			if (kFrequency_ > 120000000UL)
				tmp = FLASH_ACR_LATENCY_4WS;
			else if (kFrequency_ > 90000000UL)
				tmp = FLASH_ACR_LATENCY_3WS;
			else if (kFrequency_ > 60000000UL)
				tmp = FLASH_ACR_LATENCY_2WS;
			else if (kFrequency_ > 30000000UL)
				tmp = FLASH_ACR_LATENCY_1WS;
			else
				tmp = FLASH_ACR_LATENCY_0WS;
		}
		else
		{
			if (kFrequency_ > 2600000UL)
				tmp = FLASH_ACR_LATENCY_3WS;
			else if (kFrequency_ > 24000000UL)
				tmp = FLASH_ACR_LATENCY_2WS;
			else if (kFrequency_ > 1200000UL)
				tmp = FLASH_ACR_LATENCY_1WS;
			else
				tmp = FLASH_ACR_LATENCY_0WS;
		}
		// Prefetch makes sense when having one or more wait-states
		if (tmp != 0 && kPrefetch_)
			tmp |= FLASH_ACR_PRFTEN;
		if (kICache_)
			tmp |= FLASH_ACR_ICEN;
		if (kDCache_)
			tmp |= FLASH_ACR_DCEN;
		FLASH->ACR = 
			(FLASH->ACR & 
				~(
					FLASH_ACR_LATENCY_Msk
					| FLASH_ACR_PRFTEN_Msk
					| FLASH_ACR_ICEN_Msk
					| FLASH_ACR_DCEN_Msk
				)
			) | tmp
			;
	}
};



/*
This should be added to the SystemInit() C function.
(a STM32 firmware startup requirement)
*/
static inline void Init()
{
	// FPU settings
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
	SCB->CPACR |= ((3UL << 20U) | (3UL << 22U));	// set CP10 and CP11 Full Access
#endif
}


}	// namespace System
}	// namespace Bmt
