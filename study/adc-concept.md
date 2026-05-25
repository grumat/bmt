# ADC Template Design — F1xx

## Scope

First-class template types for ADC1 (all variants), ADC2 (`ADC2_BASE`), and ADC3
(`ADC3_BASE`). Follows existing bmt conventions: `RccTrait_`, variadic packs,
`constexpr` fold expressions, peripheral-existence dispatch.

## Variant matrix

| ADCs       | Variants         | CMSIS symbols                                 |
|------------|------------------|-----------------------------------------------|
| ADC1 only  | F100, F101, F102 | `ADC1_BASE`, `ADC1_IRQn` enum,                |
|            |                  | `#define ADC1_2_IRQn ADC1_IRQn`, `ADC1_COMMON`|
| ADC1+2     | F103 (lo/med),   | `ADC2_BASE`, `ADC1_2_IRQn` enum,              |
|            | F105, F107       | `#define ADC1_IRQn ADC1_2_IRQn`, `ADC12_COMMON`|
| ADC1+2+3   | F103 (hi-den)    | adds `ADC3_BASE`, `ADC3_IRQn=47`,             |
|            |                  | `RCC_APB2ENR_ADC3EN` bit 15                   |

## File layout

```
bmt/include/f1xx/adc.h   — all template types (single file, no .inl)
```

## Template types

### `enum class Unit`

Typed ADC identity. `k1` unconditional, `k2` / `k3` guarded by `#ifdef ADC2_BASE` / `#ifdef ADC3_BASE`.

### `Peripheral<Unit>`

Specialized per unit. Each exposes:
- `kEnBit`, `kRstBit` — RCC enable/reset masks
- `kBase` — `ADC_TypeDef*` (CMSIS `ADC1`/`ADC2`/`ADC3` pointer)
- `kIrq` — `ADC1_2_IRQn` for k1/k2 (works on all variants via `#define` alias),
  `ADC3_IRQn` for k3
- `using RccTrait_ = Clocks::RccTrait<Clocks::RccBit<RccReg::kApb2En, kEnBit>,
   Clocks::RccBit<RccReg::kApb2Rst, kRstBit>>`

Common registers (`ADC_Common_TypeDef`) are accessed at `(ADC1_BASE)` via
`reinterpret_cast` for k1/k2 only — k3 (ADC3) has no common block on F1xx.

### `Chan<U, kChan, kSmpl>`

- `U`: `Unit` identity
- `kChan`: ADC channel number (0–17, validated ≤ 17)
- `kSmpl`: 3-bit sampling time (0–7, default 3 = 28.5 cycles)

The associated GPIO pin is configured to analog mode independently via the
existing `Gpio::AnyAnalog<Port, Pin>` (or `ADC12_INx` aliases in
`gpio-types.h`). `Chan` is a pure ADC-domain type; it does not own the pin
config.

### `AnySequence<Chs...>`

Variadic pack of `Chan<>` for one ADC's regular sequence (max 16 ranks).
Computes SQR1/SQR2/SQR3 and SMPR1/SMPR2 register values at compile time via
fold expressions over the pack with a running rank counter:

- **SQR1** (bits 0–19: SQ[13..16], bits 20–23: L)
- **SQR2** (bits 0–29: SQ[7..12])
- **SQR3** (bits 0–29: SQ[1..6])
- **SMPR1** (bits 0–23: SMP[10..17]; fold by channel number, not rank)
- **SMPR2** (bits 0–29: SMP[0..9])

`Init()` writes all five registers. Static asserts: `kLen ≤ 16`, all `Chan`
share the same `Unit`, channel numbers valid.

### `AnyConfig`

Simple struct with `constexpr bool` fields for CR1/CR2 bits:
- `kScan` (SCAN bit)
- `kCont` (CONT bit)
- `kDma` (DMA bit)
- `kAlignLeft` (ALIGN bit, default `false` = right-aligned)
- `kExtTrigEn` (EXTTRIG bit)
- `kExtTrigSel` (EXTSEL 3-bit field)
- `kContinuouslyEnabled` — always-on ADON after init

`Init(volatile ADC_TypeDef*)` writes CR1 + CR2.

### `AnySetup<Config, Sequence>`

One-shot boot-time initializer. `Init()`:
1. RCC enable + reset (via `Clocks::Enabler`)
2. Config → `CR1`, `CR2`
3. Sequence → `SQR1..3`, `SMPR1..2`
4. Power up (`ADON`), poll `RSTCAL` + `CAL`
5. Leave `ADON` set

Follows the `Gpio::PortMerge` / `Clocks::Enabler` pattern — user calls
`Adc::AnySetup<Cfg, Seq>::Init()` once in `main()`.

## GPIO pin mode

Already handled by existing `Gpio::AnyAnalog<Port, Pin>` (defined in
`f1xx/gpio.h` line 429) and the `ADC12_IN0`–`ADC12_IN15` aliases in
`gpio-types.h`. Users add these to `AnyPortSetup` as before; no new pin config
type needed in the ADC header.

## RCC integration

Each `Peripheral<U>` exposes `RccTrait_` so that users can add
`Adc::Peripheral<Adc::Unit::k1>` to their `Clocks::Enabler` list alongside
`Gpio::PortClock<Gpio::Port::PA>`. The `Enabler` fold aggregates enable bits
by register — all ADC bits land in `RCC_APB2ENR` (same bus as GPIO on F1xx).

## Limitations (explicitly out of scope)

- Injected group (`JSQR`, `JDR1..4`, injected trigger) — no template support;
  users can write the registers directly via `P::kBase->JSQR`.
- Dual ADC synchronous mode (`ADC_CR1_DUALMOD`, `ADC_Common_TypeDef`).
- Analog watchdog (`AWDCH`, `AWDIE`).
- Temperature sensor / Vrefint (`TSVREFE`) — not gated in the channel template;
  users enable the bit via manual `P::kBase->CR2` write.
- Calibration is done once in `AnySetup::Init()`; no recalibration API.


---

# L4xx Port — Delta from F1xx

## File

```
bmt/include/l4xx/adc.h   — parallel to f1xx/adc.h, same template types
```

## Register layout differences

The L4 ADC peripheral was redesigned from F1.  Key register-level changes that
affect template internals:

| Function | F1xx register | L4xx register |
|----------|--------------|---------------|
| Control A | `CR1` (SCAN, DUALMOD) | `CR` (ADEN, ADVREGEN, ADCAL, ADSTART) |
| Control B | `CR2` (CONT, DMA, ALIGN, ADON, EXTTRIG, SWSTART) | `CFGR` (CONT, DMAEN, ALIGN, RES, EXTEN, EXTSEL) |
| Oversampling | — | `CFGR2` |
| Status | `SR` | `ISR` |
| Interrupt mask | — | `IER` |
| Watchdog thresholds | `HTR` / `LTR` | `TR1` / `TR2` / `TR3` |
| Offset registers | `JOFR1`–`JOFR4` | `OFR1`–`OFR4` |
| Regular sequence | `SQR1`–`SQR3` | `SQR1`–`SQR4` |
| Differential config | — | `DIFSEL` |
| Calibration factors | — | `CALFACT` |

## SQR register layout — 4 registers instead of 3

On F1xx the 16 sequencer ranks are packed into 3 registers (4+6+6).  On L4xx
they use 4 registers (4+5+5+2), and each SQ field is placed with a 6-bit
stride (5-bit field + 1-bit gap):

```
SQR1: L@0-3, SQ1@6,  SQ2@12, SQ3@18, SQ4@24     → ranks 0-3
SQR2: SQ5@0,  SQ6@6,  SQ7@12, SQ8@18, SQ9@24     → ranks 4-8
SQR3: SQ10@0, SQ11@6, SQ12@12, SQ13@18, SQ14@24  → ranks 9-13
SQR4: SQ15@0, SQ16@6                               → ranks 14-15
```

Rank-to-register mapping in `SqField_`:
- `i < 4`  → SQR1, bit position = `i * 6 + 6`
- `i < 9`  → SQR2, bit position = `(i - 4) * 6`
- `i < 14` → SQR3, bit position = `(i - 9) * 6`
- else     → SQR4, bit position = `(i - 14) * 6`

The `L` field remains in SQR1 bits 0-3.

## SMPR swap — SMPR1 = ch0-9, SMPR2 = ch10-18

F1xx and L4xx assign the two sampling-time registers differently:

| Register | F1xx          | L4xx          |
|----------|---------------|---------------|
| `SMPR1`  | ch 10–17      | **ch 0–9**    |
| `SMPR2`  | ch 0–9        | **ch 10–18**  |

L4 also adds channel 18 (temperature sensor / Vrefint / Vbat) in SMPR2 at
bits 26:24 — F1xx had only ch 0–17.

## RCC — single shared bit on AHB2

| Property | F1xx | L4xx |
|----------|------|------|
| Bus | APB2 | AHB2 |
| Per-ADC enable | `RCC_APB2ENR_ADC1EN`/`2EN`/`3EN` | Single `RCC_AHB2ENR_ADCEN` (bit 13) |
| Per-ADC reset | `RCC_APB2RSTR_ADC1RST`/`2RST`/`3RST` | Single `RCC_AHB2RSTR_ADCRST` (bit 13) |
| RCC bus enum | `Clocks::RccReg::kApb2En` | `Clocks::RccReg::kAhb2En` |

All three `Peripheral<U>` specializations map to the same shared bit on L4.
The `Clocks::Enabler` fold handles this correctly (repeated bits collapse to
one RMW).

## Common register struct

| F1xx | L4xx |
|------|------|
| `ADC_Common_TypeDef` at ADC1 base offset 0x00 | `ADC_Common_TypeDef` at ADC1 base + 0x300 |
| Contains `SR` + `CR1` + `CR2` + `DR` | Contains only `CCR` |
| Used for dual-ADC synchronisation | `CCR` holds clock mode, prescaler, VREF/TSEN/VBAT |

On L4, `Common()` returns the pointer to the CCR struct.  Users configure
clock mode and internal sensor paths via `Common()->CCR`.

## `AnyConfig` — enhanced fields

### New: `kResolution`

```cpp
enum class Res : uint8_t { k12Bit=0, k10Bit=1, k8Bit=2, k6Bit=3 };
static constexpr Res kResolution = Res::k12Bit;
```

Maps to `CFGR.RES[1:0]`.  F1xx is fixed 12-bit; this field has no effect on
F1 (but can be kept in code for source compatibility without harm).

### New: `kExtEn` replaces `kExtTrig`

F1xx uses a single `EXTTRIG` enable bit (CR2 bit 20).  L4xx uses a 2-bit
`EXTEN` field in CFGR (bits 11:10) selecting disabled / rising / falling /
both edges:

```cpp
enum class ExtEn : uint8_t {
    kDisabled=0, kRising=1, kFalling=2, kBoth=3
};
static constexpr ExtEn kExtEn = ExtEn::kDisabled;
```

When porting F1 code, replace `kExtTrig = true` with `kExtEn = ExtEn::kRising`.

### New: oversampling (`CFGR2`)

```cpp
static constexpr bool    kOvs       = false;    // OVSE enable
static constexpr uint8_t kOvsRatio  = 0;        // OVSR[2:0]: 0=2x..7=256x
static constexpr uint8_t kOvsShift  = 0;        // OVSS[3:0]: 0-8 bit shift
```

### New: `kAutoDelay` and `kOvrMod`

```cpp
static constexpr bool    kAutoDelay = false;     // CFGR.AUTDLY (low-power)
static constexpr bool    kOvrMod    = false;     // CFGR.OVRMOD (overrun mode)
```

### Retained as no-op: `kScan`

L4xx has no SCAN bit — scan mode is implicit when sequence length > 1.
`kScan` is kept in `AnyConfig` so F1 code compiles unchanged.  Setting it on
L4 has no effect.

### Register writes

`AnyConfig::Init()` writes `CR` + `CFGR` + `CFGR2` instead of F1's `CR1` +
`CR2`.

## `AnySetup` — L4 startup sequence

```
Step  F1xx                              L4xx
────  ────────────────────────────────  ───────────────────────────────
1     RCC enable + reset                RCC enable + reset (same)
2     Write CR1 / CR2                   Write CR / CFGR / CFGR2
3     Write SQR1-3 / SMPR1-2            Write SQR1-4 / SMPR1-2
4     ADON (power up)                   ADVREGEN (voltage regulator)
5     —                                 spin ~10 μs (tADCVREG settle)
6     RSTCAL (poll clear)               —
7     CAL (poll clear)                  ADCAL (poll clear)
8     —                                 ADEN (poll ADRDY flag)
9     conditionally clear ADON          conditionally set ADDIS
```

Key differences:
- **No RSTCAL** on L4 — calibration is started directly with `ADC_CR_ADCAL`.
- **ADVREGEN** must be set and the regulator allowed to settle (~10 μs) before
  calibration or enabling the ADC.
- **ADEN** replaces F1's `ADON` at CR bit 0.  After ADEN the hardware sets
  `ISR.ADRDY`; `AnySetup` polls ADRDY before returning.
- **ADSTART** replaces `SWSTART` — users start conversions via `CR.ADSTART`
  instead of `CR2.SWSTART`.

## Convenience helpers (both families)

```cpp
ALWAYS_INLINE static void StartConversion(volatile ADC_TypeDef *adc);
ALWAYS_INLINE static uint16_t ReadData(volatile ADC_TypeDef *adc);
```

These hide the F1-vs-L4 register differences for the common
start-and-read-one-value pattern:

| Helper | F1xx implementation | L4xx implementation |
|--------|--------------------|--------------------|
| `StartConversion` | `adc->CR2 \|= ADC_CR2_SWSTART` | `adc->CR \|= ADC_CR_ADSTART` |
| `ReadData` | `while(!(adc->SR & ADC_SR_EOC)); return adc->DR;` | `while(!(adc->ISR & ADC_ISR_EOC)); return adc->DR;` |

Both are defined in the family-specific header under `namespace Bmt::Adc`.
User code that calls these helpers is fully portable between F1xx and L4xx.

## L4 variant matrix

| ADCs       | Variants           | CMSIS symbols                         |
|------------|--------------------|---------------------------------------|
| ADC1 only  | L412, L422, L432   | `ADC1_BASE`, `ADC1_IRQn`             |
| ADC1+2+3   | L476, L496, L4A6   | `ADC2_BASE`, `ADC3_BASE`,             |
|            | L4R5, L4S5, ...    | `ADC1_2_IRQn`, `ADC3_IRQn`           |

All L4xx variants share the same `ADC_TypeDef` struct and register layout.
The `ADC2_BASE` / `ADC3_BASE` guards select which `Peripheral<>`
specialisations and `Unit` enumerators are available.

## Porting checklist (F1xx → L4xx)

| F1 code | L4 equivalent | Action |
|---------|---------------|--------|
| `AdcPrscl` in clock tree | same (already in `l4xx/clocks.h`) | none |
| `Peripheral<U>` in `Enabler` | same type, `RccTrait_` auto-selects AHB2 | none |
| `kExtTrig = true` | `kExtEn = ExtEn::kRising` | edit |
| `kDma = true` | same field name, bit moved | none |
| `ADC1->CR2 \|= ADC_CR2_SWSTART` | `Adc::StartConversion(ADC1)` | recommended |
| `ADC1->SR & ADC_SR_EOC` | hidden by `Adc::ReadData()` | recommended |
| `ADC1->DR` | same register | none |
| GPIO `ADC12_INx` aliases | same naming in `l4xx/gpio-types.h` | none |
| `AnyConfig` with `kScan` | no-op on L4, compiles unchanged | optional cleanup |
| `static_assert(N <= 17)` | `N <= 18` on L4 | auto (per-family header) |
