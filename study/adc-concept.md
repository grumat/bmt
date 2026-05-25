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
