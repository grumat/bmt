#pragma once

#include <cstdint>
#include <type_traits>
#include "../shared/RccEnabler.h"
#include "../compiler.h"


/*
CMSIS header (stm32g4xx.h) must be included before this file.
Provides: ADC_TypeDef, ADC_Common_TypeDef, ADC1/2_BASE, ADC12_COMMON_BASE,
ADC_CR_ADEN/ADSTART/ADVREGEN/ADCAL/ADDIS/ADCALDIF,
ADC_CFGR_DMAEN/CONT/RES/ALIGN/EXTEN/EXTSEL/OVRMOD/AUTDLY,
ADC_CFGR2_ROVSE/OVSR/OVSS,
ADC_ISR_EOC/ADRDY,
ADC_SMPR1/2_*, ADC_SQR1/2/3/4_*,
RCC_AHB2ENR_ADC12EN, RCC_AHB2RSTR_ADC12RST,
ADC1/2 pointer macros, ADC12_COMMON_BASE.
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
	// All ADCs share a single RCC enable / reset bit on G4.
	static constexpr uint32_t kEnBit  = RCC_AHB2ENR_ADC12EN;
	static constexpr uint32_t kRstBit = RCC_AHB2RSTR_ADC12RST;

	static constexpr auto *kBase = ADC1;
	static constexpr IRQn_Type kIrq = ADC1_IRQn;

	using RccTrait_ = Clocks::RccTrait<
		Clocks::RccBit<Clocks::RccReg::kAhb2En, kEnBit>,
		Clocks::RccBit<Clocks::RccReg::kAhb2Rst, kRstBit>>;

	// Common register block (CCR: clock mode, prescaler, VREF/TSEN/VBAT) at
	// ADC1 base + 0x300.
	ALWAYS_INLINE static volatile ADC_Common_TypeDef *Common()
	{
		return reinterpret_cast<volatile ADC_Common_TypeDef *>(ADC12_COMMON_BASE);
	}
};

#ifdef ADC2_BASE
template <>
struct Peripheral<Unit::k2>
{
	static constexpr uint32_t kEnBit  = RCC_AHB2ENR_ADC12EN;
	static constexpr uint32_t kRstBit = RCC_AHB2RSTR_ADC12RST;

	static constexpr auto *kBase = ADC2;
	static constexpr IRQn_Type kIrq = ADC1_2_IRQn;

	using RccTrait_ = Clocks::RccTrait<
		Clocks::RccBit<Clocks::RccReg::kAhb2En, kEnBit>,
		Clocks::RccBit<Clocks::RccReg::kAhb2Rst, kRstBit>>;

	ALWAYS_INLINE static volatile ADC_Common_TypeDef *Common()
	{
		return reinterpret_cast<volatile ADC_Common_TypeDef *>(ADC12_COMMON_BASE);
	}
};
#endif

#ifdef ADC3_BASE
template <>
struct Peripheral<Unit::k3>
{
	static constexpr uint32_t kEnBit  = RCC_AHB2ENR_ADC12EN;
	static constexpr uint32_t kRstBit = RCC_AHB2RSTR_ADC12RST;

	static constexpr auto *kBase = ADC3;
	static constexpr IRQn_Type kIrq = ADC3_IRQn;

	using RccTrait_ = Clocks::RccTrait<
		Clocks::RccBit<Clocks::RccReg::kAhb2En, kEnBit>,
		Clocks::RccBit<Clocks::RccReg::kAhb2Rst, kRstBit>>;

	ALWAYS_INLINE static volatile ADC_Common_TypeDef *Common()
	{
		return reinterpret_cast<volatile ADC_Common_TypeDef *>(ADC12_COMMON_BASE);
	}
};
#endif


// ---------------------------------------------------------------------------
// Chan<U, kChan, kSmpl> — typed ADC channel + sampling time
//
// The GPIO pin is configured separately via Gpio::AnyAnalog<Port, Pin> (or
// the ADCx_INy aliases in gpio-types.h).  This type is pure ADC-domain:
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

	static_assert(kChan <= 18, "G4xx ADC channels are 0..18");
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
/// G4 layout — 4 registers, 5-bit SQ field, 6-bit stride (gap at bit 5):
///   SQR1: SQ1@6,  SQ2@12, SQ3@18, SQ4@24     ranks 0-3
///   SQR2: SQ5@0,  SQ6@6,  SQ7@12, SQ8@18, SQ9@24  ranks 4-8
///   SQR3: SQ10@0, SQ11@6, SQ12@12, SQ13@18, SQ14@24  ranks 9-13
///   SQR4: SQ15@0, SQ16@6                   ranks 14-15
template <typename Ch, size_t kPos>
struct SqField_
{
	static constexpr uint32_t kSqr1 =
		kPos < 4 ? (uint32_t{Ch::kChan_} << (kPos * 6 + 6)) : 0;

	static constexpr uint32_t kSqr2 =
		(kPos >= 4 && kPos < 9) ? (uint32_t{Ch::kChan_} << ((kPos - 4) * 6)) : 0;

	static constexpr uint32_t kSqr3 =
		(kPos >= 9 && kPos < 14) ? (uint32_t{Ch::kChan_} << ((kPos - 9) * 6)) : 0;

	static constexpr uint32_t kSqr4 =
		kPos >= 14 ? (uint32_t{Ch::kChan_} << ((kPos - 14) * 6)) : 0;
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
// Resolution and external-trigger enums
// ---------------------------------------------------------------------------

/// ADC data resolution (CFGR.RES[1:0]).
enum class Res : uint8_t
{
	k12Bit = 0,
	k10Bit = 1,
	k8Bit  = 2,
	k6Bit  = 3,
};

/// External trigger polarity (CFGR.EXTEN[1:0]).
enum class ExtEn : uint8_t
{
	kDisabled = 0,
	kRising   = 1,
	kFalling  = 2,
	kBoth     = 3,
};


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

	// --- Build SQR1/SQR2/SQR3/SQR4 from rank-indexed channel numbers --------
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

	template <size_t... Is>
	static consteval auto BuildSqr4_(std::index_sequence<Is...>)
		-> uint32_t
	{
		return Private::OrFold_<Private::SqField_<Chs, Is>::kSqr4...>::kValue;
	}

	static constexpr uint32_t kSqr1 =
		BuildSqr1_(std::index_sequence_for<Chs...>{});
	static constexpr uint32_t kSqr2 =
		BuildSqr2_(std::index_sequence_for<Chs...>{});
	static constexpr uint32_t kSqr3 =
		BuildSqr3_(std::index_sequence_for<Chs...>{});
	static constexpr uint32_t kSqr4 =
		BuildSqr4_(std::index_sequence_for<Chs...>{});

	// Sequence length field (L[3:0]) in SQR1 bits 0-3.
	static constexpr uint32_t kLenField =
		kLen == 0 ? 0 : ((kLen - 1) << 0);

	// --- Build SMPR1 (ch 0-9) and SMPR2 (ch 10-18) by channel number -------
	// NOTE: G4 swaps SMPR1/SMPR2 relative to F1 (same as L4).
	static constexpr auto kSmpr1 = []{
		uint32_t v = 0;
		((v |= Chs::kChan_ < 10
			? (uint32_t{Chs::kSmpl_} << (Chs::kChan_ * 3))
			: 0), ...);
		return v;
	}();

	static constexpr auto kSmpr2 = []{
		uint32_t v = 0;
		((v |= Chs::kChan_ >= 10
			? (uint32_t{Chs::kSmpl_} << ((Chs::kChan_ - 10) * 3))
			: 0), ...);
		return v;
	}();

	// -----------------------------------------------------------------------
	// Init — write SQR and SMPR registers
	// -----------------------------------------------------------------------

	ALWAYS_INLINE static void Init()
	{
		volatile auto *adc = P::kBase;

		adc->SQR1  = kSqr1 | kLenField;	// SQ[1..4] + L
		adc->SQR2  = kSqr2;				// SQ[5..9]
		adc->SQR3  = kSqr3;				// SQ[10..14]
		adc->SQR4  = kSqr4;				// SQ[15..16]
		adc->SMPR1 = kSmpr1;				// SMP[0..9]
		adc->SMPR2 = kSmpr2;				// SMP[10..18]
	}
};


// ---------------------------------------------------------------------------
// AnyConfig — CR + CFGR + CFGR2 bitfield struct
// ---------------------------------------------------------------------------

struct AnyConfig
{
	// ── F1xx compat fields ──────────────────────────────────────────────
	static constexpr bool    kScan        = false;	// no-op (implicit on G4)
	static constexpr bool    kCont        = false;	// CFGR.CONT
	static constexpr bool    kDma         = false;	// CFGR.DMAEN
	static constexpr bool    kAlignLeft   = false;	// CFGR.ALIGN
	static constexpr ExtEn   kExtEn       = ExtEn::kDisabled;
	static constexpr uint8_t kExtTrigSel  = 0;		// CFGR.EXTSEL[4:0]

	// ── G4 additions ────────────────────────────────────────────────────
	static constexpr Res    kResolution  = Res::k12Bit;
	static constexpr bool   kAutoDelay   = false;	// CFGR.AUTDLY
	static constexpr bool   kOvrMod      = false;	// CFGR.OVRMOD

	// ── Oversampling (CFGR2) ────────────────────────────────────────────
	static constexpr bool    kOvs        = false;	// ROVSE
	static constexpr uint8_t kOvsRatio   = 0;		// OVSR[2:0]: 0=2x..7=256x
	static constexpr uint8_t kOvsShift   = 0;		// OVSS[3:0]: 0-8 bit shift

	// ── Power management ────────────────────────────────────────────────
	static constexpr bool kPowerDown     = false;	// set ADDIS after init

	ALWAYS_INLINE static void Init(volatile ADC_TypeDef *adc)
	{
		uint32_t cr    = 0;
		uint32_t cfgr  = 0;
		uint32_t cfgr2 = 0;

		if constexpr (kCont)              cfgr |= ADC_CFGR_CONT;
		if constexpr (kDma)               cfgr |= ADC_CFGR_DMAEN;
		if constexpr (kAlignLeft)         cfgr |= ADC_CFGR_ALIGN;
		if constexpr (kAutoDelay)         cfgr |= ADC_CFGR_AUTDLY;
		if constexpr (kOvrMod)            cfgr |= ADC_CFGR_OVRMOD;

		if constexpr (kExtEn != ExtEn::kDisabled)
		{
			cfgr |= (static_cast<uint32_t>(kExtEn) << ADC_CFGR_EXTEN_Pos);
			cfgr |= (uint32_t{kExtTrigSel} << ADC_CFGR_EXTSEL_Pos);
		}

		cfgr |= (static_cast<uint32_t>(kResolution) << ADC_CFGR_RES_Pos);

		if constexpr (kOvs)
		{
			cfgr2 |= ADC_CFGR2_ROVSE;
			cfgr2 |= (uint32_t{kOvsRatio} << ADC_CFGR2_OVSR_Pos);
			cfgr2 |= (uint32_t{kOvsShift} << ADC_CFGR2_OVSS_Pos);
		}

		adc->CR    = cr;
		adc->CFGR  = cfgr;
		adc->CFGR2 = cfgr2;
	}

	/// Convenience overload for a typed peripheral.
	template <typename P>
	ALWAYS_INLINE static void Init()
	{
		Init(P::kBase);
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
		// 1. Enable + reset ADC clock (shared AHB2 bit).
		Clocks::Enabler<P>::Init();

		// 2. Write CR / CFGR / CFGR2.
		Cfg::template Init<P>();

		// 3. Write SQR + SMPR.
		Seq::Init();

		volatile auto *adc = P::kBase;

		// 4. Enable the voltage regulator (must settle before calibration).
		adc->CR |= ADC_CR_ADVREGEN;
		for (volatile uint32_t d = 0; d < 100; ++d) { }

		// 5. Calibrate (single-ended).
		adc->CR |= ADC_CR_ADCAL;
		while (adc->CR & ADC_CR_ADCAL) { }

		// 6. Enable ADC; wait for ADRDY.
		adc->CR |= ADC_CR_ADEN;
		while (!(adc->ISR & ADC_ISR_ADRDY)) { }

		// 7. Optionally power down.
		if constexpr (Cfg::kPowerDown)
			adc->CR |= ADC_CR_ADDIS;
	}
};


// ---------------------------------------------------------------------------
// Convenience helpers — portable start/read for a single conversion
// ---------------------------------------------------------------------------

/// Start a single conversion (software trigger).
ALWAYS_INLINE void StartConversion(volatile ADC_TypeDef *adc)
{
	adc->CR |= ADC_CR_ADSTART;
}

/// Wait for EOC and return the conversion result.
ALWAYS_INLINE uint16_t ReadData(volatile ADC_TypeDef *adc)
{
	while (!(adc->ISR & ADC_ISR_EOC)) { }
	return uint16_t(adc->DR);
}


} // namespace Adc
} // namespace Bmt
