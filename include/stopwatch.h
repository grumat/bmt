#pragma once

#include "systick.h"
#include "timer.h"

namespace Bmt
{
namespace Timer
{


// A stopwatch for very short single shot times (uses polling)
template<
	typename Timer,					// A timer to serve ticks
	const Ticks kPeriod = Ticks(0)	// Auto-reload feature
>
	class ALIGNED MicroStopWatch
	{
	public:
		MicroStopWatch()
			: t0_(Timer::GetRawValue())
			, t1_(kPeriod)
		{ }
		MicroStopWatch(Ticks ticks)
			: t0_(Timer::GetRawValue())
			, t1_(ticks)
		{ }
		MicroStopWatch(Msec ms)
			: t0_(Timer::GetRawValue())
			, t1_(Timer::ToTicks(ms))
		{ }
		MicroStopWatch(Usec us)
			: t0_(Timer::GetRawValue())
			, t1_(Timer::ToTicks(us))
		{ }
		// Starts counting in µs
		template<Usec kUS> constexpr void Start()
		{
			t0_ = Timer::GetRawValue();
			t1_ = Timer::template U2T<kUS>::kTicks; // full 32-bit resolution supported
		}
		// Starts counting in ms
		template<Msec kMS> constexpr void Start()
		{
			t0_ = Timer::GetRawValue();
			t1_ = Timer::template M2T<kMS>::kTicks; // full 32-bit resolution supported
		}
		// Same as Start()
		template<Usec kUS> constexpr void Restart()
		{
			t0_ = Timer::GetRawValue();
			t1_ = Timer::template U2T<kUS>::kTicks; // full 32-bit resolution supported
		}
		// Same as Start()
		template<Msec kMS> constexpr void Restart()
		{
			t0_ = Timer::GetRawValue();
			t1_ = Timer::template M2T<kMS>::kTicks; // full 32-bit resolution supported
		}
		// Adds a time offset to the current duration without stopping current time
		template<Usec kUS> constexpr void Append()
		{
			t1_ = Ticks((uint32_t)t1_ + (uint32_t)Timer::template U2T<kUS>::kTicks);
		}
		// Adds a time offset to the current duration without stopping current time
		template<Msec kMS> constexpr void Append()
		{
			t1_ = Ticks((uint32_t)t1_ + (uint32_t)Timer::template M2T<kMS>::kTicks);
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
					t1_ = Ticks((uint32_t)t1_ - (uint32_t)ticks);
					return true;
				}
				else
					t1_ = kPeriod;	// auto reload feature
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
		template<Usec kUS> constexpr void Delay()
		{
			Restart<kUS>();
			Wait();
		}
		template<Msec kMS> constexpr void Delay()
		{
			Restart<kMS>();
			Wait();
		}
		ALWAYS_INLINE void Delay(const Msec kMS)
		{
			t0_ = Timer::GetRawValue();
			t1_ = Ticks(kMS * Timer::template M2T<Msec(1)>::kTicks);
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
		PolledStopWatch(Msec total_ms)
			: ms_((uint32_t)total_ms)
		{
			SUPER::template Start<Usec(1000)>();
		}
		// Check if time was not elapsed (call at least 10 times a second!!!)
		bool IsNotElapsed() NO_INLINE
		{
			// Removes all accumulated microseconds
			while (ms_ > 0)
			{
				if (SUPER::IsNotElapsed() == false)
				{
					SUPER::template Append<Usec(1000)>();
					--ms_;
				}
			}
			// returns state
			return ms_ > 0;
		}
	public:
		// Adds a duration to current current state
		void Append(Msec total_ms)
		{
			ms_ += (uint32_t)total_ms;
		}
		// Sets a new duration, initial base time will continue from the 
		// initial mark
		void Continue(Msec total_ms)
		{
			ms_ = (uint32_t)total_ms;
		}
		// Restarts counter. A new time base is used
		void Restart(Msec total_ms)
		{
			SUPER::template Start<Usec(1000)>();
			ms_ = (uint32_t)total_ms;
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
