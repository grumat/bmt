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
enum SysTickUnits : uint32_t;

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
class ALIGNED AnySysTick
{
public:
	/// Constant with the Tick frequency
	static constexpr uint32_t kFrequency_ = kFrequency;
	/// Timer reload constant
	static constexpr uint32_t kReload_ = SysClk::kFrequency_ / kFrequency - 1;
	/// How to poll delays
	static constexpr SysTickPollType kSysTickPollType_ = kSysTickPollType;

	/// The tick counter value
	static inline volatile uint32_t sys_tick_;

	/// Initialize the tick timer
	ALWAYS_INLINE static void Init(void)
	{
		sys_tick_ = 0;
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
	ALWAYS_INLINE static SysTickUnits GetRawValue()
	{
		return (SysTickUnits)SysTick->VAL;
	}
	// Returns distance of raw counter to an initial reference (interval has to be less than kFrequency_ period)
	ALWAYS_INLINE static SysTickUnits GetDif(SysTickUnits t0)
	{
		SysTickUnits t1 = GetRawValue();
		// SysTick is a down-counter!!!
		int32_t dif = (t0 - t1);
		if(dif < 0)
			return (SysTickUnits)(dif + kReload_ + 1);
		else
			return (SysTickUnits)dif;
	}

// High resolution short delays (necessarily below kFrequency_ period)
public:
	/// Conversion from us to timer ticks
	template<const uint32_t kUS>
	struct U2T
	{
		static constexpr SysTickUnits kTicks = (SysTickUnits)(((uint64_t)kUS * SysClk::kFrequency_) / 1000000);
	};
	/// Delays CPU by a given timer tick value
	void DelayTicks(SysTickUnits ticks) NO_INLINE
	{
		uint32_t t0 = GetRawValue();
		while ((int32_t)(GetRawValue() - t0) < (int32_t)ticks)
		{
		}
	}
	/// Constant delay of CPU in us (optimized code)
	/*!
	Only very short periods should be used. Put it into a CriticalSection if 
	timing is at a premium. Interrupts will certainly add sensitive jitter on 
	time precision.
	*/
	template<const uint32_t kUS> ALWAYS_INLINE void DelayUS()
	{
		static constexpr SysTickUnits kTicks = U2T<kUS>::kTicks;
		// Delay time to big for timer resolution 
		static_assert(kTicks < kReload_/2, "This timer may run very fast, so we rely on 50% of the range only");
		// Hold CPU flow as long as time has not elapsed
		DelayTicks(kTicks);
	}

protected:
	/// ISR can access this class
	friend void SysTick_Handler(void);
	/// Simple tick counter is implemented here
	ALWAYS_INLINE static void Handler()
	{
		++sys_tick_;
	}

public:
	/// A stopwatch class using the tick timer
	class StopWatch
	{
	public:
		/// ctor starts the stop watch
		ALWAYS_INLINE StopWatch() { Start(); }
		// Start the stop watch at the moment t0 expressed in milliseconds (i.e.
		// calling Time() immediately afterwards returns t0). This can be used to
		// restart an existing stopwatch.
		ALWAYS_INLINE void Start()
		{
			t0_ = sys_tick_;
		}
		/// Elapsed time in ms
		ALWAYS_INLINE uint32_t GetEllapsedTime() const
		{
			return sys_tick_ - t0_;
		}
		/// Delay CPU
		void Delay(uint32_t ms)
		{
			/// Hold CPU flow as long as time has not elapsed
			while (GetEllapsedTime() < ms)
			{
				/// Halt the CPU for low power use
				if (kSysTickPollType_ == kPollWfi)
					__WFI();
				else if (kSysTickPollType_ == kPollWfe)
					__WFE();
			}
		}

	private:
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
class ALIGNED AnySysTickEx : public AnySysTick<SysClk, kFrequency, kSysTickPollType>
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
This class cannot interoperate with AnySysTick/AnySysTickEx.
Either one or the other approach should be used, completely.
The first is designed for a collaborative, low-power, interrupt-driven design, 
while this class is for a firmware that relies on energy inefficient polling.
Needless to say, that time precision is the great gain here.
*/
template<
	typename SysClk			///< System clock
>
class ALIGNED SysTickCounter
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
	ALWAYS_INLINE static uint32_t GetRawValue()
	{
		return SysTick->VAL;
	}

// Time conversion
public:
	/// Computes the total amount of ticks for the given milliseconds (low performance option when used with constants)
	static SysTickUnits ToTicks(uint32_t ms) NO_INLINE
	{
		const uint32_t ticks = (ms * (kFrequency_ / 1000));
		assert(ticks < 0x00FFFF80);
		return (SysTickUnits)ticks;
	}

	/// Conversion from ms to timer ticks
	template<const uint32_t kMS>
	struct M2T
	{
		static constexpr SysTickUnits kTicks = (SysTickUnits)(((uint64_t)kMS * kFrequency_) / 1000);
	};

	/// Conversion from us to timer ticks
	template<const uint32_t kUS>
	struct U2T
	{
		static constexpr SysTickUnits kTicks = (SysTickUnits)(((uint64_t)kUS * kFrequency_) / 1000000);
	};

public:
	/// A stopwatch class using the tick counter
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
			t0_ = GetRawValue();
		}
		/// Elapsed time in ms
		ALWAYS_INLINE SysTickUnits GetElapsedTicks() const
		{
			int32_t dif = t0_ - GetRawValue();	// down-counter
			if (dif < 0)
				dif += kTimerOverflow_;
			return (SysTickUnits)dif;
		}
		/// Delays CPU by a given timer tick value
		void DelayTicks(SysTickUnits ticks) NO_INLINE
		{
			while (GetElapsedTicks() < ticks)
			{ }
		}
		/// Delay CPU using ms value (worst case scenario)
		void Delay(uint32_t ms) NO_INLINE
		{
			static constexpr SysTickUnits k1ms = M2T<1>::kTicks;
			while(ms >= 1)
			{
				Delay<k1ms>();
				int32_t tmp = t0_ - k1ms;
				if (tmp >= 0)
					t0_ = tmp;
				else
					t0_ = tmp + kTimerOverflow_;
				ms -= 1;
			}
		}
		/// Constant delay of CPU in ms (optimized code)
		template<const uint32_t kMS> constexpr void Delay()
		{
			const SysTickUnits kTicks = M2T<kMS>::kTicks;
			// Delay time to big for timer resolution 
			static_assert(kTicks <= 0x00FFFF80, "Overflow will happen (a margin was included since this timer works on stamina)");
			// Hold CPU flow as long as time has not elapsed
			DelayTicks(kTicks);
		}
		/// Constant delay of CPU in us (optimized code)
		template<const uint32_t kUS> constexpr void DelayUS()
		{
			const SysTickUnits kTicks = U2T<kUS>::kTicks;
			// Delay time to big for timer resolution 
			static_assert(kTicks <= 0x00FFFF80, "Overflow will happen (a margin was included since this timer works on stamina)");
			// Hold CPU flow as long as time has not elapsed
			DelayTicks(kTicks);
		}

	protected:
		// The clock value when the stop watch was last started. Its units vary
		// depending on the platform.
		uint32_t t0_;
	};
	// Similar to StopWatch but supports very long intervals
	class ALIGNED LongStopWatch : public StopWatch
	{
	public:
		LongStopWatch(uint32_t total_ms) : ms_(total_ms) {}
		// Check if time was not elapsed (call at least 10 times a second!!!)
		bool IsNotElapsed() NO_INLINE
		{
			static constexpr SysTickUnits k1ms = M2T<1>::kTicks;
			// Removes all accumulated microseconds
			while ((ms_ > 0)
				&& (StopWatch::GetElapsedTicks() > k1ms)
				)
			{
				// SysTick is a down-counter!!!
				if (StopWatch::t0_ >= k1ms)
					StopWatch::t0_ -= k1ms;
				else
					StopWatch::t0_ = (StopWatch::t0_ - k1ms) + kTimerOverflow_;
				--ms_;
			}
			// returns state
			return ms_ > 0;
		}
		// Sets a new duration, initial base time will continue from the 
		// initial mark
		void Continue(uint32_t total_ms)
		{
			ms_ = total_ms;
		}
		// Adds a duration to current current state
		void Append(uint32_t total_ms)
		{
			ms_ += total_ms;
		}
		// Restarts counter. A new time base is used
		void Restart(uint32_t total_ms)
		{
			StopWatch::Start();
			ms_ = total_ms;
		}

	private:
		uint32_t ms_;
	};
};


}	// namespace Timer
}	// namespace Bmt
