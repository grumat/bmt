#pragma once

#include "clocks.h"
#include "exti.h"

/// Application defined `tick handler` defined on the App
extern "C" void SysTick_Handler(void);

namespace Bmt
{
namespace Timer
{

/// A type safe uint32_t for systimer tick units
enum class Ticks : uint32_t;
/// A type safe uint32_t for microseconds unit
enum class Usec : uint32_t;
/// A type safe uint32_t for milliseconds unit
enum class Msec : uint32_t;

/// How a time delay shall be done
enum SysTickPollType
{
	kPollRun		//!< Continuous polling during delay
	, kPollWfi		//!< Sleep until interrupted
	, kPollWfe		//!< Sleep until event occurs
};

/// Tick timer class template
template<
	typename SysClk						///< System clock
	, const uint32_t kFrequency = 1000	///< Tick frequency
	, const SysTickPollType kSysTickPollType = kPollRun	/// How to perform delays
>
class AnySysTick
{
public:
	/// Constant with the Tick frequency
	static constexpr uint32_t kFrequency_ = kFrequency;
	/// Timer reload constant
	static constexpr uint32_t kReload_ = SysClk::kFrequency_ / kFrequency - 1;
	/// How to poll delays
	static constexpr SysTickPollType kSysTickPollType_ = kSysTickPollType;

	/// The tick counter value
	static inline volatile uint32_t soft_tick_;

	/// Initialize the tick timer
	ALWAYS_INLINE static void Init(void)
	{
		soft_tick_ = 0;
		SysTick->LOAD = kReload_;
		SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
		EnableIRQ();
	}
	/// Enables the ISR driven by the timer interrupt request
	ALWAYS_INLINE static void EnableIRQ(void)
	{
		SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
	}
	/// Disables timer interrupt request
	ALWAYS_INLINE static void DisableIRQ(void)
	{
		SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
	}
	/// Returns the current counter raw value
	ALWAYS_INLINE static Ticks GetRawValue()
	{
		return (Ticks)SysTick->VAL;
	}

// High resolution short delays (necessarily below kFrequency_ period)
public:
	/// Conversion from us to timer ticks
	template<Usec kUS>
	struct U2T
	{
		static constexpr Ticks kTicks = (Ticks)(((uint64_t)kUS * SysClk::kFrequency_) / 1000000);
	};
	/// Delays CPU by a given timer tick value
	void DelayTicks(Ticks ticks) NO_INLINE
	{
		uint32_t t0 = (uint32_t)GetRawValue();
		while ((int32_t)((uint32_t)GetRawValue() - t0) < (int32_t)ticks)
		{
		}
	}
	/// Constant delay of CPU in us (optimized code)
	/*!
	Only very short periods should be used. Put it into a CriticalSection if 
	timing is at a premium. Interrupts will certainly add sensitive jitter on 
	time precision.
	*/
	template<Usec kUS> static constexpr void Delay()
	{
		constexpr Ticks kChunk = Ticks(kReload_ / 2);
		Ticks kTicks = U2T<kUS>::kTicks;
		while (kTicks < kChunk)
		{
			DelayTicks(kTicks);
			kTicks = Ticks((uint32_t)kTicks - (uint32_t)kChunk);
		}
		if((uint32_t)kTicks)
		{
			// Hold CPU flow as long as time has not elapsed
			DelayTicks(kTicks);
		}
	}
	/// Milliseconds delay; Works for tick frequencies strictly below 2000 Hz
	static constexpr void Delay(Msec ms_) NO_INLINE
	{
		uint32_t ms = (uint32_t)ms_;
		constexpr Ticks k500 = U2T<Usec(500)>::kTicks;
		for(; ms; --ms)
		{
			DelayTicks(k500);
			DelayTicks(k500);
		}
	}
	/// Elapsed time in hardware ticks
	ALWAYS_INLINE static Ticks GetElapsedTicks(Ticks t0)
	{
		int32_t dif = (uint32_t)t0 - (uint32_t)GetRawValue();	// down-counter
		if (dif < 0)
			dif += kReload_ + 1;
		return (Ticks)dif;
	}
	/// Elapsed time in hardware ticks and updates t0 to new base time
	ALWAYS_INLINE static Ticks GetElapsedTicksEx(Ticks& t0)
	{
		Ticks tn = GetRawValue();
		int32_t dif = (uint32_t&)t0 - (uint32_t)tn;	// down-counter
		if (dif < 0)
			dif += kReload_ + 1;
		t0 = tn;
		return (Ticks)dif;
	}

protected:
	/// ISR can access this class
	friend void SysTick_Handler(void);
	/// Simple tick counter is implemented here
	ALWAYS_INLINE static void Handler()
	{
		++soft_tick_;
	}

public:
	/// A stopwatch class using the soft tick timer
	class ALIGNED StopWatch
	{
	public:
		/// ctor starts the stop watch
		ALWAYS_INLINE StopWatch() { Start(); }
		// Start the stop watch at the moment t0 expressed in milliseconds (i.e.
		// calling Time() immediately afterwards returns t0). This can be used to
		// restart an existing stopwatch.
		ALWAYS_INLINE void Start()
		{
			t0_ = soft_tick_;
		}
		/// Elapsed time in ms
		ALWAYS_INLINE uint32_t GetElapsedTime() const
		{
			return soft_tick_ - t0_;
		}
		/// Delay CPU
		void Delay(uint32_t ms)
		{
			/// Hold CPU flow as long as time has not elapsed
			while (GetElapsedTime() < ms)
			{
				/// Halt the CPU for low power use
				if (kSysTickPollType_ == kPollWfi)
					__WFI();
				else if (kSysTickPollType_ == kPollWfe)
					__WFE();
			}
		}
	protected:
		// The clock value when the stop watch was last started. Its units vary
		// depending on the platform.
		uint32_t t0_;
	};
};


/*!
A Tick timer class that handles two counters. A tick counter and a slower soft 
counter typically used to control lower priority tasks.
*/
template<
	typename SysClk			///< System clock
	, const uint32_t kFrequency = 1000UL	///< Frequency of the tick counter
	, const uint32_t kSoftFreq = 200UL		///< Frequency of the soft-generated sub-frequency
	, const SysTickPollType kSysTickPollType = kPollWfi	///< How to halt the CPU
>
class AnySysTickEx : public AnySysTick<SysClk, kFrequency, kSysTickPollType>
{
public:
	/// Base class
	typedef AnySysTick<SysClk, kFrequency, kSysTickPollType> Base;
	/// Soft frequency
	static constexpr uint32_t kFrequency_ = kSoftFreq;
	/// Soft generated tick counter
	static inline volatile uint32_t soft_tick_;

	/// Initialize the timer
	ALWAYS_INLINE static void Init(void)
	{
		// A soft timer shall be slower as the tick timer
		static_assert(kSoftFreq < kFrequency, "Soft timer shall be slower than the hardware timer that drives it");
		Base::Init();
	}

protected:
	/// Counter for the soft timer
	static inline uint32_t soft_counter_;
	/// Tick handler has full access this class
	friend void SysTick_Handler(void);
	/// This implements the ISR Handler
	ALWAYS_INLINE static void Handler()
	{
		Base::Handler();
		soft_counter_ += kFrequency_;
		if (soft_counter_ >= Base::kFrequency_)
		{
			// remark: one of them will be optimized out by compiler
			if (Base::kFrequency_ % kFrequency_ == 0)
			{
				soft_counter_ = 0;
			}
			else
			{
				// Remove keeping remainder
				soft_counter_ -= Base::kFrequency_;
			}
			// update soft tick
			++soft_tick_;
		}
	}
};


/// Use of SysTick as a simple raw timer without interrupts
/*!
This class cannot inter-operate with AnySysTick/AnySysTickEx.
Either one or the other approach should be used, completely.
The first is designed for a collaborative, low-power, interrupt-driven design, 
while this class is for a firmware that relies on energy inefficient polling.
Needless to say, that time precision is the great gain here.
*/
template<
	typename SysClk			///< System clock
>
class SysTickCounter
{
public:
	/// Use CPUFreq/8 as time base
	static constexpr uint32_t kFrequency_ = SysClk::kFrequency_ / 8;
	/// Overflow for this timer working in full range
	static constexpr uint32_t kTimerOverflow_ = 0x01000000UL;


	/// Initialize the tick timer
	ALWAYS_INLINE static void Init(void)
	{
		SysTick->LOAD = 0x00FFFFFF;
		SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;		// CPU/8
	}
	/// Returns the current counter raw value
	ALWAYS_INLINE static Ticks GetRawValue()
	{
		return Ticks(SysTick->VAL);
	}
	/// Elapsed time in ms
	ALWAYS_INLINE static Ticks GetElapsedTicks(Ticks t0)
	{
		int32_t dif = (uint32_t)t0 - (uint32_t)GetRawValue();	// down-counter
		if (dif < 0)
			dif += kTimerOverflow_;
		return (Ticks)dif;
	}
	/// Elapsed time in ms and update t0
	ALWAYS_INLINE static Ticks GetElapsedTicksEx(Ticks &t0)
	{
		const Ticks tn = GetRawValue();
		int32_t dif = (uint32_t&)t0 - (uint32_t)tn;	// down-counter
		if (dif < 0)
			dif += kTimerOverflow_;
		t0 = tn;
		return (Ticks)dif;
	}
	/// Delays CPU by a given timer tick value
	static void DelayTicks(Ticks ticks)
	{
		Ticks t0 = GetRawValue();
		while(true)
		{
			Ticks dif = GetElapsedTicksEx(t0);
			if (dif < ticks)
				ticks = Ticks((uint32_t)ticks - (uint32_t)dif);
			else
				break;
		}
	}

// Time conversion
public:
	/// Computes the total amount of ticks for the given milliseconds (low performance option when used with constants)
	static constexpr Ticks ToTicks(Msec ms)
	{
		const uint32_t ticks = ((uint32_t)ms * (kFrequency_ / 1000));
		return (Ticks)ticks;
	}
	/// Computes the total amount of ticks for the given milliseconds (low performance option when used with constants)
	static constexpr Ticks ToTicks(Usec us)
	{
		const uint32_t ticks = ((uint32_t)us * (kFrequency_ / 1000000));
		return (Ticks)ticks;
	}

	/// Conversion from ms to timer ticks
	template<Msec kMS>
	struct M2T
	{
		static constexpr Ticks kTicks = (Ticks)(((uint64_t)kMS * kFrequency_) / 1000);
	};

	/// Conversion from us to timer ticks
	template<Usec kUS>
	struct U2T
	{
		static constexpr Ticks kTicks = (Ticks)(((uint64_t)kUS * kFrequency_) / 1000000);
	};
	/// Constant delay of CPU in us (optimized code)
	template<Usec kUS> static ALWAYS_INLINE constexpr void Delay()
	{
		constexpr Ticks kTicks = U2T<kUS>::kTicks;
		// Delay time to big for timer resolution 
		static_assert((uint32_t)kTicks < 0x00FFFF80, "This timer may run very fast, so we rely on 50% of the range only");
		// Hold CPU flow as long as time has not elapsed
		DelayTicks(kTicks);
	}
	/// Variable delay of CPU in us (avoid this variant, if possible)
	static ALWAYS_INLINE constexpr void Delay(Usec kUS)
	{
		const Ticks kTicks = ToTicks(kUS);
		// Hold CPU flow as long as time has not elapsed
		DelayTicks(kTicks);
	}
	/// Constant delay of CPU in ms (optimized code)
	template<Msec kMS> static ALWAYS_INLINE constexpr void Delay()
	{
		constexpr Ticks kTicks = M2T<kMS>::kTicks;
		// Delay time to big for timer resolution 
		static_assert((uint32_t)kTicks < 0x00FFFF80, "This timer may run very fast, so we rely on 50% of the range only");
		// Hold CPU flow as long as time has not elapsed
		DelayTicks(kTicks);
	}
	/// Variable delay of CPU in ms (avoid this variant, if possible)
	static ALWAYS_INLINE constexpr void Delay(Msec kMS)
	{
		const Ticks kTicks = ToTicks(kMS);
		// Hold CPU flow as long as time has not elapsed
		DelayTicks(kTicks);
	}
};


}	// namespace Timer
}	// namespace Bmt
