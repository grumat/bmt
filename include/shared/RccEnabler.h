#pragma once

#include <type_traits>


namespace Bmt
{
namespace Clocks
{

/// Identifies an RCC register that holds peripheral enable / reset bits.
/// Each MCU family defines the concrete enumerators it actually exposes;
/// the `Enabler` template only emits writes for registers it sees in use.
enum class RccReg : uint8_t
{
	kNone,		///< Sentinel for "no bit"
	kAhb1En,	kAhb1Rst,
	kAhb2En,	kAhb2Rst,
	kAhb3En,	kAhb3Rst,
	kApb1En,	kApb1Rst,
	kApb1En2,	kApb1Rst2,
	kApb2En,	kApb2Rst,
	kIopEn,		kIopRst,
};


/// Single-bit descriptor: which RCC register, which bit mask.
template <RccReg kReg, uint32_t kBit>
struct RccBit
{
	static constexpr RccReg  kReg_ = kReg;
	static constexpr uint32_t kBit_ = kBit;
};


/// Sentinel for peripherals with no reset bit (e.g. AFIO on F1, DMA on F1).
struct RccNoBit
{
	static constexpr RccReg  kReg_ = RccReg::kNone;
	static constexpr uint32_t kBit_ = 0;
};


/// Composite trait: enable-bit + optional reset-bit per peripheral.
/// Each peripheral template exposes `using RccTrait_ = RccTrait<EnBit, RstBit>;`.
template <typename EnBit, typename RstBit = RccNoBit>
struct RccTrait
{
	using Enable_ = EnBit;
	using Reset_  = RstBit;
};


namespace Private
{

// Pick the right register pointer for a given RccReg value.
// Unused branches collapse via `if constexpr` in callers.
ALWAYS_INLINE static volatile uint32_t *RccRegPtr(RccReg r)
{
	switch (r)
	{
#ifdef RCC_AHBENR_DMA1EN
	case RccReg::kAhb1En:  return &RCC->AHBENR;
#elif defined(RCC_AHB1ENR_DMA1EN)
	case RccReg::kAhb1En:  return &RCC->AHB1ENR;
#endif
#ifdef RCC_AHB1RSTR_DMA1RST
	case RccReg::kAhb1Rst: return &RCC->AHB1RSTR;
#endif
#ifdef RCC_AHB2ENR_GPIOAEN
	case RccReg::kAhb2En:  return &RCC->AHB2ENR;
#endif
#ifdef RCC_AHB2RSTR_GPIOARST
	case RccReg::kAhb2Rst: return &RCC->AHB2RSTR;
#endif
#ifdef RCC_AHB3ENR_FMCEN
	case RccReg::kAhb3En:  return &RCC->AHB3ENR;
#endif
#ifdef RCC_AHB3RSTR_FMCRST
	case RccReg::kAhb3Rst: return &RCC->AHB3RSTR;
#endif
#ifdef RCC_APB1ENR_TIM2EN
	case RccReg::kApb1En:  return &RCC->APB1ENR;
	case RccReg::kApb1Rst: return &RCC->APB1RSTR;
#elif defined(RCC_APB1ENR1_TIM2EN)
	case RccReg::kApb1En:  return &RCC->APB1ENR1;
	case RccReg::kApb1Rst: return &RCC->APB1RSTR1;
#	ifdef RCC_APB1ENR2_LPUART1EN
	case RccReg::kApb1En2: return &RCC->APB1ENR2;
	case RccReg::kApb1Rst2:return &RCC->APB1RSTR2;
#	endif
#endif
#ifdef RCC_APB2ENR_USART1EN
	case RccReg::kApb2En:  return &RCC->APB2ENR;
	case RccReg::kApb2Rst: return &RCC->APB2RSTR;
#endif
#ifdef RCC_IOPENR_GPIOAEN
	case RccReg::kIopEn:   return &RCC->IOPENR;
	case RccReg::kIopRst:  return &RCC->IOPRSTR;
#endif
	default: return nullptr;
	}
}

} // namespace Private


/*!
\brief Variadic compile-time RCC clock-enable / peripheral-reset combiner.

Takes any number of peripheral templates that each expose `using RccTrait_ = ...`
and emits one RMW per touched RCC register. Use cases:

- `Enabler<Tim1, Dma1, GpioA, GpioB>::Enable()` at boot — clocks all listed
  peripherals with the minimum number of register writes (one per bus).
- `Enabler<Tim1>::Reset()` — pulses APBxRSTR for that peripheral only.
  *Only safe at boot, before any `Setup()` has run on peripherals sharing the bus*,
  because the reset pulse wipes any configuration applied to other peripherals
  whose reset bit happens to be in the mask (it is not in this case, since only
  Tim1 is listed, but be careful when batching).
- `Enabler<...>::Init()` — `Enable(); Reset();` in one call. Equivalent to the
  legacy per-peripheral `Init()` pattern but for a whole group.

Items that have no reset bit (DMA on F1, AFIO on F1) silently contribute 0 to
the reset mask via `RccNoBit`.

Zero overhead: all masks are `constexpr`-folded; `if constexpr` collapses each
register branch to either a single `|=` / RMW pair or no code at all.
*/
template <typename... Items>
class Enabler
{
private:
	template <RccReg kReg>
	static constexpr uint32_t EnableMask()
	{
		return ((Items::RccTrait_::Enable_::kReg_ == kReg
				 ? Items::RccTrait_::Enable_::kBit_ : 0u) | ... | 0u);
	}

	template <RccReg kReg>
	static constexpr uint32_t ResetMask()
	{
		return ((Items::RccTrait_::Reset_::kReg_ == kReg
				 ? Items::RccTrait_::Reset_::kBit_ : 0u) | ... | 0u);
	}

	template <RccReg kReg>
	ALWAYS_INLINE static void DoEnable()
	{
		if constexpr (constexpr uint32_t m = EnableMask<kReg>(); m != 0)
		{
			volatile uint32_t *p = Private::RccRegPtr(kReg);
			*p |= m;
			// Read-back barrier: ST recommends reading the same register before
			// touching the peripheral (avoids accessing it before clock settles).
			volatile uint32_t delay = *p & m;
			(void)delay;
		}
	}

	template <RccReg kReg>
	ALWAYS_INLINE static void DoDisable()
	{
		if constexpr (constexpr uint32_t m = EnableMask<kReg>(); m != 0)
			*Private::RccRegPtr(kReg) &= ~m;
	}

	template <RccReg kReg>
	ALWAYS_INLINE static void DoReset()
	{
		if constexpr (constexpr uint32_t m = ResetMask<kReg>(); m != 0)
		{
			volatile uint32_t *p = Private::RccRegPtr(kReg);
			*p |= m;
			*p &= ~m;
		}
	}

public:
	/// Enable peripheral clocks for every Item, one RMW per touched RCC register.
	ALWAYS_INLINE static void Enable()
	{
		DoEnable<RccReg::kAhb1En>();
		DoEnable<RccReg::kAhb2En>();
		DoEnable<RccReg::kAhb3En>();
		DoEnable<RccReg::kApb1En>();
		DoEnable<RccReg::kApb1En2>();
		DoEnable<RccReg::kApb2En>();
		DoEnable<RccReg::kIopEn>();
	}

	/// Disable peripheral clocks (clear the enable bits).
	ALWAYS_INLINE static void Disable()
	{
		DoDisable<RccReg::kAhb1En>();
		DoDisable<RccReg::kAhb2En>();
		DoDisable<RccReg::kAhb3En>();
		DoDisable<RccReg::kApb1En>();
		DoDisable<RccReg::kApb1En2>();
		DoDisable<RccReg::kApb2En>();
		DoDisable<RccReg::kIopEn>();
	}

	/// Pulse APBxRSTR / AHBxRSTR for every Item that has a reset bit.
	/// CAUTION: only safe at boot, before any `Setup()` has run on peripherals
	/// sharing the same RSTR register that are not in this group — the pulse
	/// resets *all* bits set in the mask simultaneously.
	ALWAYS_INLINE static void Reset()
	{
		DoReset<RccReg::kAhb1Rst>();
		DoReset<RccReg::kAhb2Rst>();
		DoReset<RccReg::kAhb3Rst>();
		DoReset<RccReg::kApb1Rst>();
		DoReset<RccReg::kApb1Rst2>();
		DoReset<RccReg::kApb2Rst>();
		DoReset<RccReg::kIopRst>();
	}

	/// Convenience: `Enable(); Reset();` — matches legacy per-peripheral Init().
	ALWAYS_INLINE static void Init()
	{
		Enable();
		Reset();
	}
};


} // namespace Clocks
} // namespace Bmt
