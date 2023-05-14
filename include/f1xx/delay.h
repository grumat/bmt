#pragma once

namespace Bmt
{
namespace Timer
{

// Very short delays good for handling slow hardware
template<
	typename SysClk
>
class AnyDelay
{
public:
	// CPU frequency
	static constexpr uint32_t kFrequency_ = SysClk::kFrequency_;
	static constexpr uint32_t kWaitState_ = SysClk::WaitState::kWaitState_;
	// Very short delays (in nanoseconds)
	template<const uint32_t NS> ALWAYS_INLINE static void DelayNS()
	{
		// Time of the NOP instruction is much faster because no branch is used
		constexpr uint32_t kSCycle
			= kWaitState_ == 2 	? 1300000000ULL / kFrequency_
			: kWaitState_ == 1 	? 1200000000ULL / kFrequency_
			/* 0 wait states */ : 1200000000ULL / kFrequency_
			;
		// At least one instruction cycle is inherently consumed
		if (NS > kSCycle / 2)
		{
			constexpr uint32_t kNS = NS;
			// Duration of one iteration of the long loop cycle in ns
			constexpr uint32_t kLCycle
				= kWaitState_ == 2 	? 3000000000ULL / kFrequency_
				: kWaitState_ == 1 	? 3600000000ULL / kFrequency_
				/* 0 wait states */ : 3000000000ULL / kFrequency_
				;
			// Number of long cycles (with rounding compensation)
			constexpr uint32_t kLong = (kNS + (kLCycle / 2)) / kLCycle;
			// Number of short cycles (with rounding compensation)
			constexpr uint32_t kShort = kNS / kSCycle;

			if (kLong >= 2)
			{
				// long loop
				uint32_t cycles = kLong;
				asm volatile (
					"1:  subs %[cycles], %[cycles], #1 \n"
					"    bne 1b \n"
					: [cycles] "+r"(cycles)
					);
			}
			else
			{
				if (kShort > 9)
					__NOP();
				if (kShort > 8)
					__NOP();
				if (kShort > 7)
					__NOP();
				if (kShort > 6)
					__NOP();
				if (kShort > 5)
					__NOP();
				if (kShort > 4)
					__NOP();
				if (kShort > 3)
					__NOP();
				if (kShort > 2)
					__NOP();
				if (kShort > 1)
					__NOP();
				__NOP();
			}
		}
	}
};

}	// namespace Timer
}	// namespace Bmt
