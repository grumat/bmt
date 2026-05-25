#pragma once

#include <cstdint>
#include <type_traits>
#include "../shared/RccEnabler.h"
#include "../compiler.h"


/*
CMSIS header (stm32f1xx.h) must be included before this file.
Provides: ADC_TypeDef, ADC_Common_TypeDef, ADC1/2/3_BASE,
ADC_CR1_SCAN, ADC_CR2_CONT/DMA/ALIGN/EXTSEL/EXTTRIG/CAL/RSTCAL/ADON/SWSTART,
ADC_SMPR1/2_*, ADC_SQR1/2/3_*, RCC_APB2ENR_ADC1EN/2EN/3EN,
RCC_APB2RSTR_ADC1RST/2RST/3RST, ADC1_2_IRQn, ADC3_IRQn.
*/


namespace Bmt
{
namespace Adc
{

// ---------------------------------------------------------------------------
// Peripheral<U> — typed wrapper around a single ADC block
// ---------------------------------------------------------------------------

template <Unit U>
struct Peripheral;

template <>
struct Peripheral<Unit::k1>
{
	static constexpr uint32_t kEnBit  = RCC_APB2ENR_ADC1EN;
	static constexpr uint32_t kRstBit = RCC_APB2RSTR_ADC1RST;

	// Address stored as an integer: the ADCx macros expand to a reinterpret_cast
	// which is not a constant expression, so it cannot initialise a constexpr
	// pointer. Cast at point of use via GetDevice() (folds to a constant, no
	// dynamic init). Same convention as Timer's kBaseAddr_.
	static constexpr uintptr_t kBase_ = ADC1_BASE;
	ALWAYS_INLINE static volatile ADC_TypeDef *GetDevice()
	{
		return reinterpret_cast<volatile ADC_TypeDef *>(kBase_);
	}

	// ADC1_2_IRQn is the enum name on dual-ADC parts; on single-ADC parts the
	// CMSIS header #define's ADC1_2_IRQn -> ADC1_IRQn.  Either way it compiles.
	static constexpr IRQn_Type kIrq = ADC1_2_IRQn;

	using RccTrait_ = Clocks::RccTrait<
		Clocks::RccBit<Clocks::RccReg::kApb2En, kEnBit>,
		Clocks::RccBit<Clocks::RccReg::kApb2Rst, kRstBit>>;

	// Shared common registers (SR, CR1, CR2) for ADC1/ADC2 — always at ADC1
	// base on F1xx.
	ALWAYS_INLINE static volatile ADC_Common_TypeDef *Common()
	{
		return reinterpret_cast<volatile ADC_Common_TypeDef *>(ADC1_BASE);
	}
};

#ifdef ADC2_BASE
template <>
struct Peripheral<Unit::k2>
{
	static constexpr uint32_t kEnBit  = RCC_APB2ENR_ADC2EN;
	static constexpr uint32_t kRstBit = RCC_APB2RSTR_ADC2RST;

	static constexpr uintptr_t kBase_ = ADC2_BASE;
	ALWAYS_INLINE static volatile ADC_TypeDef *GetDevice()
	{
		return reinterpret_cast<volatile ADC_TypeDef *>(kBase_);
	}
	static constexpr IRQn_Type kIrq = ADC1_2_IRQn;

	using RccTrait_ = Clocks::RccTrait<
		Clocks::RccBit<Clocks::RccReg::kApb2En, kEnBit>,
		Clocks::RccBit<Clocks::RccReg::kApb2Rst, kRstBit>>;

	ALWAYS_INLINE static volatile ADC_Common_TypeDef *Common()
	{
		return reinterpret_cast<volatile ADC_Common_TypeDef *>(ADC1_BASE);
	}
};
#endif

#ifdef ADC3_BASE
template <>
struct Peripheral<Unit::k3>
{
	static constexpr uint32_t kEnBit  = RCC_APB2ENR_ADC3EN;
	static constexpr uint32_t kRstBit = RCC_APB2RSTR_ADC3RST;

	static constexpr uintptr_t kBase_ = ADC3_BASE;
	ALWAYS_INLINE static volatile ADC_TypeDef *GetDevice()
	{
		return reinterpret_cast<volatile ADC_TypeDef *>(kBase_);
	}
	static constexpr IRQn_Type kIrq = ADC3_IRQn;

	using RccTrait_ = Clocks::RccTrait<
		Clocks::RccBit<Clocks::RccReg::kApb2En, kEnBit>,
		Clocks::RccBit<Clocks::RccReg::kApb2Rst, kRstBit>>;

	// ADC3 has no common register block on F1xx.
};
#endif


// ---------------------------------------------------------------------------
// Chan<U, kChan, kSmpl> — typed ADC channel + sampling time
//
// The GPIO pin is configured separately via Gpio::AnyAnalog<Port, Pin> (or
// the ADC12_INx aliases in gpio-types.h).  This type is pure ADC-domain:
// it describes the analog channel number and sampling time, not the pad.
// ---------------------------------------------------------------------------

template <
	Unit U,
	uint8_t kChan,
	Smpl kSmpl = Smpl::k28_5
>
struct Chan
{
	using P = Peripheral<U>;
	static constexpr uint8_t kChan_ = kChan;
	static constexpr uint8_t kSmpl_ = static_cast<uint8_t>(kSmpl);

	static_assert(kChan <= 17, "F1xx ADC channels are 0..17");
};


// ---------------------------------------------------------------------------
// Private helpers
// ---------------------------------------------------------------------------

namespace Private
{

/// Extract Peripheral<U> from the first channel, or fall back to ADC1.
template <typename...> struct FirstP_;
template <typename T, typename... Rest>
struct FirstP_<T, Rest...> { using type = typename T::P; };
template <> struct FirstP_<> { using type = Peripheral<Unit::k1>; };


/// SQR field per channel/rank position.
template <typename Ch, size_t kPos>
struct SqField_
{
	static constexpr uint32_t kSqr3 =
		kPos < 6 ? (uint32_t{Ch::kChan_} << (kPos * 5)) : 0;

	static constexpr uint32_t kSqr2 =
		(kPos >= 6 && kPos < 12) ? (uint32_t{Ch::kChan_} << ((kPos - 6) * 5)) : 0;

	static constexpr uint32_t kSqr1 =
		kPos >= 12 ? (uint32_t{Ch::kChan_} << ((kPos - 12) * 5)) : 0;
};


/// Fold helper: OR of a pack of register fragment values.
template <uint32_t... kVs>
struct OrFold_
{
	static constexpr uint32_t kValue = (0 | ... | kVs);
};


/// Validate all Chan types share the same Peripheral<U>.
template <typename...> struct AllSamePeriph_ : std::true_type {};
template <typename T, typename... Rest>
struct AllSamePeriph_<T, Rest...>
	: std::conjunction<std::is_same<typename T::P, typename Rest::P>...>
{
};

} // namespace Private


// ---------------------------------------------------------------------------
// AnySequence<Chs...> — variadic regular sequence (max 16 ranks)
// ---------------------------------------------------------------------------

template <typename... Chs>
struct AnySequence
{
	static constexpr size_t kLen = sizeof...(Chs);
	static_assert(kLen <= 16, "ADC regular sequence max 16 ranks");

	static_assert(Private::AllSamePeriph_<Chs...>::value,
		"All channels in AnySequence must share the same Unit");

	using P = typename Private::FirstP_<Chs...>::type;

	// --- Build SQR1/SQR2/SQR3 from rank-indexed channel numbers ------------
	template <size_t... Is>
	static consteval auto BuildSqr1_(std::index_sequence<Is...>)
		-> uint32_t
	{
		return Private::OrFold_<Private::SqField_<Chs, Is>::kSqr1...>::kValue;
	}

	template <size_t... Is>
	static consteval auto BuildSqr2_(std::index_sequence<Is...>)
		-> uint32_t
	{
		return Private::OrFold_<Private::SqField_<Chs, Is>::kSqr2...>::kValue;
	}

	template <size_t... Is>
	static consteval auto BuildSqr3_(std::index_sequence<Is...>)
		-> uint32_t
	{
		return Private::OrFold_<Private::SqField_<Chs, Is>::kSqr3...>::kValue;
	}

	static constexpr uint32_t kSqr1 =
		BuildSqr1_(std::index_sequence_for<Chs...>{});
	static constexpr uint32_t kSqr2 =
		BuildSqr2_(std::index_sequence_for<Chs...>{});
	static constexpr uint32_t kSqr3 =
		BuildSqr3_(std::index_sequence_for<Chs...>{});

	// Sequence length field (L[3:0]) in SQR1 bits 20-23.
	static constexpr uint32_t kLenField =
		kLen == 0 ? 0 : ((kLen - 1) << 20);

	// --- Build SMPR1 (ch 10-17) and SMPR2 (ch 0-9) by channel number -------
	static constexpr auto kSmpr1 = []{
		uint32_t v = 0;
		((v |= Chs::kChan_ >= 10
			? (uint32_t{Chs::kSmpl_} << ((Chs::kChan_ - 10) * 3))
			: 0), ...);
		return v;
	}();

	static constexpr auto kSmpr2 = []{
		uint32_t v = 0;
		((v |= Chs::kChan_ < 10
			? (uint32_t{Chs::kSmpl_} << (Chs::kChan_ * 3))
			: 0), ...);
		return v;
	}();

	// -----------------------------------------------------------------------
	// Init — write SQR and SMPR registers
	// -----------------------------------------------------------------------

	ALWAYS_INLINE static void Init()
	{
		volatile auto *adc = P::GetDevice();

		adc->SQR1  = kSqr1 | kLenField;	// SQ[13..16] + L
		adc->SQR2  = kSqr2;				// SQ[7..12]
		adc->SQR3  = kSqr3;				// SQ[1..6]
		adc->SMPR1 = kSmpr1;				// SMP[10..17]
		adc->SMPR2 = kSmpr2;				// SMP[0..9]
	}
};


// ---------------------------------------------------------------------------
// AnyConfig — CR1 / CR2 bitfield struct
// ---------------------------------------------------------------------------

struct AnyConfig
{
	static constexpr bool kScan      = false;	// CR1.SCAN
	static constexpr bool kCont      = false;	// CR2.CONT
	static constexpr bool kDma       = false;	// CR2.DMA
	static constexpr bool kAlignLeft = false;	// CR2.ALIGN (0 = right)
	static constexpr bool kExtTrig   = false;	// CR2.EXTTRIG
	static constexpr uint8_t kExtTrigSel = 0;	// CR2.EXTSEL[2:0]

	// If true, ADON is cleared after init (ADC is powered down after config).
	static constexpr bool kPowerDown = false;

	ALWAYS_INLINE static void Init(volatile ADC_TypeDef *adc)
	{
		uint32_t cr1 = 0;
		uint32_t cr2 = 0;

		if constexpr (kScan)                      cr1 |= ADC_CR1_SCAN;
		if constexpr (kCont)                      cr2 |= ADC_CR2_CONT;
		if constexpr (kDma)                       cr2 |= ADC_CR2_DMA;
		if constexpr (kAlignLeft)                 cr2 |= ADC_CR2_ALIGN;

		// On F1 a regular-group conversion only triggers when EXTTRIG=1. With a
		// hardware trigger, EXTSEL selects the source; otherwise select SWSTART
		// (EXTSEL=0b111) so Adc::StartConversion() (which writes CR2.SWSTART)
		// actually starts a conversion. Leaving EXTTRIG clear — as the previous
		// code did by default — made the SWSTART helper a no-op.
		cr2 |= ADC_CR2_EXTTRIG;
		if constexpr (kExtTrig)
			cr2 |= (uint32_t{kExtTrigSel} << ADC_CR2_EXTSEL_Pos);
		else
			cr2 |= ADC_CR2_EXTSEL;	// 0b111 = SWSTART regular-group trigger

		adc->CR1 = cr1;
		adc->CR2 = cr2;
	}

	/// Convenience overload for a typed peripheral.
	template <typename P>
	ALWAYS_INLINE static void Init()
	{
		Init(P::GetDevice());
	}
};


// ---------------------------------------------------------------------------
// AnySetup<Config, Sequence> — one-shot boot initializer
// ---------------------------------------------------------------------------

template <typename Cfg, typename Seq>
struct AnySetup
{
	using P = typename Seq::P;

	ALWAYS_INLINE static void Init()
	{
		// 1. Enable + reset ADC clock.
		Clocks::Enabler<P>::Init();

		// 2. Write CR1 / CR2.
		Cfg::template Init<P>();

		// 3. Write SQR + SMPR.
		Seq::Init();

		// 4. Power up ADC.
		volatile auto *adc = P::GetDevice();
		adc->CR2 |= ADC_CR2_ADON;

		// 5. Calibrate: reset calibration flag, then calibrate.
		adc->CR2 |= ADC_CR2_RSTCAL;
		while (adc->CR2 & ADC_CR2_RSTCAL) { }
		adc->CR2 |= ADC_CR2_CAL;
		while (adc->CR2 & ADC_CR2_CAL) { }

		// 6. Optionally power down (leave ADON set for normal operation).
		if constexpr (Cfg::kPowerDown)
			adc->CR2 &= ~ADC_CR2_ADON;
	}
};


// ---------------------------------------------------------------------------
// Convenience helpers — portable start/read for a single conversion
// ---------------------------------------------------------------------------

/// Start a single conversion (software trigger).
ALWAYS_INLINE void StartConversion(volatile ADC_TypeDef *adc)
{
	adc->CR2 |= ADC_CR2_SWSTART;
}

/// Wait for EOC and return the conversion result.
ALWAYS_INLINE uint16_t ReadData(volatile ADC_TypeDef *adc)
{
	while (!(adc->SR & ADC_SR_EOC)) { }
	return uint16_t(adc->DR);
}


} // namespace Adc
} // namespace Bmt
