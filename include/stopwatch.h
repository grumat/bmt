#pragma once

#include "systick.h"
#include "timer.h"

namespace Bmt
{
namespace Timer
{


// A stopwatch for very short single shot times (uses polling)
template<
	typename Timer		// A timer to serve ticks
>
	class ALIGNED MicroStopWatch
	{
	public:
		MicroStopWatch()
			: t1_(Ticks(0))
			, t0_(Ticks(0)) {}
		MicroStopWatch(Ticks ticks)
			: t0_(Timer::GetRawValue())
			, t1_(ticks)
		{ }
		// Starts counting in µs
		template<const int kUS> constexpr void StartUS()
		{
			t0_ = Timer::GetRawValue();
			t1_ = Timer::template U2T<kUS>::kTicks; // full 32-bit resolution supported
		}
		// Starts counting in ms
		template<const int kMS> constexpr void Start()
		{
			t0_ = Timer::GetRawValue();
			t1_ = Timer::template M2T<kMS>::kTicks; // full 32-bit resolution supported
		}
		// Same as Start()
		template<const int kUS> constexpr void RestartUS()
		{
			t0_ = Timer::GetRawValue();
			t1_ = Timer::template U2T<kUS>::kTicks; // full 32-bit resolution supported
		}
		// Same as Start()
		template<const int kMS> constexpr void Restart()
		{
			t0_ = Timer::GetRawValue();
			t1_ = Timer::template M2T<kMS>::kTicks; // full 32-bit resolution supported
		}
		// Adds a time offset to the current duration without stopping current time
		template<const int kUS> constexpr void AppendUS()
		{
			t1_ = Ticks(t1_ + Timer::template U2T<kUS>::kTicks);
		}
		// Checks if interval has elapsed.
		// Call this method in a rate below timer period for correct functionality
		bool IsNotElapsed()
		{
			// Updates t0_ and obtain ticks since last call
			Ticks ticks = Timer::GetElapsedTicksEx(t0_);
			if (t1_ != Ticks(0))
			{
				if (ticks < t1_)
				{
					t1_ = Ticks(t1_ - ticks);
					return true;
				}
				else
					t1_ = Ticks(0);
			}
			return false;
		}
		// Holds CPU until programmed time elapses
		void Wait()
		{
			while (IsNotElapsed())
			{
			}
		}
		template<const int kUS> constexpr void DelayUS()
		{
			RestartUS<kUS>();
			Wait();
		}
		template<const int kMS> constexpr void Delay()
		{
			Restart<kMS>();
			Wait();
		}
		ALWAYS_INLINE void Delay(const int kMS)
		{
			t0_ = Timer::GetRawValue();
			t1_ = Ticks(kMS * Timer::template M2T<1>::kTicks);
			Wait();
		}
	private:
		Ticks t1_;
		Ticks t0_;
	};

// A polled stopwatch with support for long milliseconds intervals
template<
	typename Timer		// A timer to serve ticks
>
	class ALIGNED PolledStopWatch : public MicroStopWatch<Timer>
	{
	public:
		typedef MicroStopWatch<Timer> SUPER;

	public:
		PolledStopWatch(uint32_t total_ms)
			: ms_(total_ms)
		{
			SUPER::template StartUS<1000>();
		}
		// Check if time was not elapsed (call at least 10 times a second!!!)
		bool IsNotElapsed() NO_INLINE
		{
			// Removes all accumulated microseconds
			while (ms_ > 0)
			{
				if (SUPER::IsNotElapsed() == false)
				{
					SUPER::template Append<1000>();
					--ms_;
				}
			}
			// returns state
			return ms_ > 0;
		}
	public:
		// Adds a duration to current current state
		void Append(uint32_t total_ms)
		{
			ms_ += total_ms;
		}
		// Sets a new duration, initial base time will continue from the 
		// initial mark
		void Continue(uint32_t total_ms)
		{
			ms_ = total_ms;
		}
		// Restarts counter. A new time base is used
		void Restart(uint32_t total_ms)
		{
			SUPER::template StartUS<1000>();
			ms_ = total_ms;
		}
		// Locks processor flow until stopwatch reaches desired time
		void Wait()
		{
			while (IsNotElapsed())
			{
			}
		}

	private:
		uint32_t ms_;
	};


}	// namespace Timer
}	// namespace Bmt
