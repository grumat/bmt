# <big>The `Bmt::Adc` Name-Space</big>

The `Adc` namespace provides template types for configuring the
analog-to-digital converter on STM32F1xx, STM32L4xx, and STM32G4xx.  All
register values are computed at compile time via fold expressions, reducing
runtime overhead to a handful of register writes.

The library handles ADC1 (all variants), ADC2 (when `ADC2_BASE` is defined),
and ADC3 (when `ADC3_BASE` is defined) via peripheral-existence dispatch.

Include the family-appropriate header:

```cpp
#include "adc.h"           // auto-selects f1xx/adc.h / l4xx/adc.h / g4xx/adc.h
```

### Family differences at a glance

| Feature         | F1xx                          | L4xx / G4xx                          |
|-----------------|-------------------------------|--------------------------------------|
| RCC bus         | APB2 (per-ADC bits)           | AHB2 (shared bit)                    |
| Control regs    | CR1 + CR2                     | CR + CFGR + CFGR2                    |
| Status reg      | SR                            | ISR                                  |
| SQR registers   | 3 (4+6+6 ranks)               | 4 (4+5+5+2 ranks)                    |
| SMPR1 / SMPR2   | ch10-17 / ch0-9               | ch0-9 / ch10-18                      |
| Resolution      | fixed 12-bit                  | configurable via `Res` enum          |
| External trig   | single `EXTTRIG` bit          | 2-bit `EXTEN` polarity field         |
| Oversampling    | —                             | CFGR2 (ROVSE, OVSR, OVSS)           |
| Kernel clock    | APB2 + ADCPRE (clock tree)    | CCR.CKMODE, set by `AnySetup` (`kCkMode`) |
| Startup         | ADON → RSTCAL → CAL           | CKMODE → ADVREGEN → ADCAL → ADEN → poll ADRDY |
| Conversion start| CR2.SWSTART                   | CR.ADSTART                           |

---

## ADC Single-Conversion Tutorial (BluePill Example)

This example reads one analog channel (PA0 = ADC1_IN0) on an STM32F103
BluePill in single-conversion mode and blinks an LED at a rate proportional
to the measured voltage.

### Step 1 — Include headers

```cpp
#include "f1xx/adc.h"
#include "f1xx/gpio-types.h"
#include "f1xx/clocks.h"
```

### Step 2 — Define the clock tree and peripheral enabler

```cpp
using namespace Bmt;

using Hse = Clocks::AnyHse<>;
using Pll = Clocks::AnyPll<Hse, 72000000UL>;

using PeripheralEnabler = Clocks::Enabler<
    Gpio::PortClock<Gpio::Port::PA>,
    Gpio::PortClock<Gpio::Port::PC>,
    Adc::Peripheral<Adc::Unit::k1>          // <-- enables ADC1 on APB2
>;

using SysClk = Clocks::AnySycClk<
    Pll,
    Clocks::AhbPrscl::k1,           // AHB 72 MHz
    Clocks::ApbPrscl::k2,           // APB1 36 MHz
    Clocks::ApbPrscl::k1,           // APB2 72 MHz
    Clocks::AdcPrscl::k8,           // ADC clock 9 MHz
    Clocks::SysClkOpts::kDefault,
    Clocks::Mco::kPllClkDiv2
>;
```

### Step 3 — Configure the ADC pin (analog mode)

```cpp
using Led = Gpio::AnyOut<Gpio::Port::PC, 13>;          // BluePill LED
using AdcPin = Gpio::ADC12_IN0;                         // PA0, analog mode

using InitPA = Gpio::AnyPortSetup<
    Gpio::Port::PA,
    AdcPin                                              // PA0 = analog input
>;

using InitPC = Gpio::AnyPortSetup<
    Gpio::Port::PC,
    Gpio::Unused<0>,
    Gpio::Unused<1>,
    Gpio::Unused<2>,
    Gpio::Unused<3>,
    Gpio::Unused<4>,
    Gpio::Unused<5>,
    Gpio::Unused<6>,
    Gpio::Unused<7>,
    Gpio::Unused<8>,
    Gpio::Unused<9>,
    Gpio::Unused<10>,
    Gpio::Unused<11>,
    Gpio::Unused<12>,
    Led,
    Gpio::Unchanged<14>,
    Gpio::Unchanged<15>
>;

using AllGpio = Gpio::PortMerge<InitPA, InitPC>;
```

### Step 4 — Configure and initialise the ADC

```cpp
// Single conversion, right-aligned, no scan, no DMA
using AdcConfig = Adc::AnyConfig;

// Sequence with one channel: ADC1_IN0, default sampling time (28.5 cycles)
using AdcSeq = Adc::AnySequence<
    Adc::Chan<Adc::Unit::k1, 0>
>;

using AdcSetup = Adc::AnySetup<AdcConfig, AdcSeq>;
```

### Step 5 — The main loop

```cpp
int main()
{
    SysClk::Init();
    PeripheralEnabler::Init();
    AllGpio::Init();

    AdcSetup::Init();           // RCC → config → calibrate → ADON

    while (true)
    {
        // Wait for end-of-conversion flag
        while (!(ADC1->SR & ADC_SR_EOC)) { }

        uint16_t value = ADC1->DR;     // read clears EOC flag

        // Simple LED blink rate based on ADC value
        for (volatile uint32_t d = 0; d < value * 100; ++d) { }
        Led::Toggle();
    }
}
```

---

## Reference

### `enum class Unit`

Typed ADC peripheral identity.

| Enumerator | Availability                     |
|------------|----------------------------------|
| `k1`       | All variants                     |
| `k2`       | Parts defining `ADC2_BASE`       |
| `k3`       | Parts defining `ADC3_BASE`       |

Example:
```cpp
Adc::Unit::k1   // ADC1
```

---

### `Peripheral<Unit>`

Typed wrapper around a single ADC hardware block.  Each specialization
exposes:

| Member             | Description                              |
|--------------------|------------------------------------------|
| `kEnBit`           | Bit mask in RCC enable register          |
| `kRstBit`          | Bit mask in RCC reset register           |
| `kBase_`           | Peripheral base address (`uintptr_t`)    |
| `GetDevice()`      | Returns `volatile ADC_TypeDef *` (cast of `kBase_`) |
| `kIrq`             | CMSIS `IRQn_Type` enum value             |
| `RccTrait_`        | Compatible with `Clocks::Enabler`        |
| `Common()`         | Returns `ADC_Common_TypeDef *` pointer   |

The bus and bit names differ by family but are encapsulated by `Peripheral`:

| Family | Enable bit | Reset bit | Common block |
|--------|-----------|-----------|-------------|
| F1xx   | `RCC_APB2ENR_ADC{1,2,3}EN` | `RCC_APB2RSTR_ADC{1,2,3}RST` | `ADC1_BASE` (offset 0x00) |
| L4xx   | `RCC_AHB2ENR_ADCEN` (shared) | `RCC_AHB2RSTR_ADCRST` (shared) | `ADC1_COMMON_BASE` (offset +0x300) |
| G4xx   | `RCC_AHB2ENR_ADC12EN` (shared) | `RCC_AHB2RSTR_ADC12RST` (shared) | `ADC12_COMMON_BASE` (offset +0x300) |

Example — explicit clock control:
```cpp
using Adc1 = Adc::Peripheral<Adc::Unit::k1>;
Clocks::Enabler<Adc1>::Enable();     // set the correct RCC bit
Clocks::Enabler<Adc1>::Reset();      // pulse the correct RCC reset
```

#### IRQ note

- `Peripheral<Unit::k1>` and `k2` use `ADC1_2_IRQn`.  On single-ADC parts
  (F100, F101, F102) the CMSIS header provides a `#define ADC1_2_IRQn ADC1_IRQn`
  alias, so the name compiles everywhere.
- `Peripheral<Unit::k3>` uses `ADC3_IRQn` (F103 hi-density, some L4xx parts).

---

### `Smpl` — Sampling Time Literals

```cpp
enum Smpl : uint8_t
{
    k1_5   = 0,     //  1.5  ADC clock cycles
    k7_5   = 1,     //  7.5  cycles
    k13_5  = 2,     // 13.5  cycles
    k28_5  = 3,     // 28.5  cycles (default)
    k41_5  = 4,     // 41.5  cycles
    k55_5  = 5,     // 55.5  cycles
    k71_5  = 6,     // 71.5  cycles
    k239_5 = 7,     // 239.5 cycles
};
```

Total conversion time = 12.5 cycles + SMP cycles.  Use larger values for
higher-impedance signal sources.

---

### `Chan<U, kChan, kSmpl>`

Binds an ADC channel number to a peripheral and sampling time.

| Template Parameter | Description                     |
|--------------------|---------------------------------|
| `U`                | `Unit` (which ADC)              |
| `kChan`            | Channel number (0–17 F1xx, 0–18 L4xx/G4xx) |
| `kSmpl`            | Sampling time (`Smpl`, default `k28_5`) |

Exposed type and constants:

| Member     | Description                        |
|------------|------------------------------------|
| `P`        | `Peripheral<U>` typedef            |
| `kChan_`   | Channel number (`uint8_t`)         |
| `kSmpl_`   | Sampling time raw value (`uint8_t`)|

The associated GPIO pin is configured to analog mode via the existing
`Gpio::AnyAnalog<Port, Pin>` or the pre-defined `ADC12_INx` aliases in
`gpio-types.h`.  `Chan` is a pure ADC-domain type and does not include pin
configuration.

Example:
```cpp
// ADC1 channel 3 with 71.5 cycle sampling time
using Ch = Adc::Chan<Adc::Unit::k1, 3, Adc::Smpl::k71_5>;
```

#### Channel-to-pin mapping (F103 medium-density)

| Channel | Pin  | gpio-types.h alias |
|---------|------|--------------------|
| 0       | PA0  | `ADC12_IN0`        |
| 1       | PA1  | `ADC12_IN1`        |
| 2       | PA2  | `ADC12_IN2`        |
| 3       | PA3  | `ADC12_IN3`        |
| 4       | PA4  | `ADC12_IN4`        |
| 5       | PA5  | `ADC12_IN5`        |
| 6       | PA6  | `ADC12_IN6`        |
| 7       | PA7  | `ADC12_IN7`        |
| 8       | PB0  | `ADC12_IN8`        |
| 9       | PB1  | `ADC12_IN9`        |
| 10      | PC0  | `ADC12_IN10`       |
| 11      | PC1  | `ADC12_IN11`       |
| 12      | PC2  | `ADC12_IN12`       |
| 13      | PC3  | `ADC12_IN13`       |
| 14      | PC4  | `ADC12_IN14`       |
| 15      | PC5  | `ADC12_IN15`       |

Higher-density F103 parts add channels 16 (temperature sensor) and 17
(VREFINT) which are internal and have no external pin.

---

### `AnySequence<Chs...>`

Variadic regular sequence.  Compiles SQR1/SQR2/SQR3 and SMPR1/SMPR2 register
values from the channel pack at compile time.

#### Template parameters

`Chs...` — one or more `Chan<U, N, Smpl>` types for the same ADC `Unit`.

#### Static constants

| Constant      | Register | Description                            |
|---------------|----------|----------------------------------------|
| `kSqr1`       | `SQR1`   | F1: SQ[13..16] @0; L4/G4: SQ[1..4] @6 |
| `kSqr2`       | `SQR2`   | SQ[7..12] (F1) / SQ[5..9] (L4/G4)     |
| `kSqr3`       | `SQR3`   | SQ[1..6] (F1) / SQ[10..14] (L4/G4)    |
| `kSqr4`       | `SQR4`   | L4/G4 only: SQ[15..16] @0              |
| `kLenField`   | `SQR1`   | L[3:0] = length − 1 (F1 @20, L4/G4 @0)|
| `kSmpr1`      | `SMPR1`  | F1: SMP[10..17]; L4/G4: SMP[0..9]     |
| `kSmpr2`      | `SMPR2`  | F1: SMP[0..9];   L4/G4: SMP[10..18]   |
| `kLen`        | —        | Number of channels (`size_t`)          |

**`Init()` writes all registers (5 on F1, 6 on L4/G4).**

#### `Init()`

Writes all five registers (`SQR1`–`SQR3`, `SMPR1`, `SMPR2`) to the peripheral
identified by the channels' `Unit`.

#### Static assertions

- `kLen <= 16` (hardware limit)
- All channels must share the same `Unit` (checked via `AllSamePeriph_`)

#### Examples

**Single channel sequence:**
```cpp
using Seq = Adc::AnySequence<Adc::Chan<Adc::Unit::k1, 0>>;
```

**Multi-channel scan sequence (4 channels):**
```cpp
using Seq = Adc::AnySequence<
    Adc::Chan<Adc::Unit::k1, 0>,       // rank 1
    Adc::Chan<Adc::Unit::k1, 1>,       // rank 2
    Adc::Chan<Adc::Unit::k1, 2>,       // rank 3
    Adc::Chan<Adc::Unit::k1, 3>        // rank 4
>;
// L field = 3  → 4 conversions per trigger
// SQ[1]=ch0, SQ[2]=ch1, SQ[3]=ch2, SQ[4]=ch3
```

**Mixed sampling times:**
```cpp
using Seq = Adc::AnySequence<
    Adc::Chan<Adc::Unit::k1, 0, Adc::Smpl::k1_5>,    // fast channel
    Adc::Chan<Adc::Unit::k1, 1, Adc::Smpl::k239_5>   // high-impedance
>;
// SMPR2: SMP[0]=0 (1.5 cyc), SMP[1]=7 (239.5 cyc)
```

---

### `AnyConfig`

CR1 / CR2 bitfield config struct.  All fields are `static constexpr` and
default to `false` / `0`.

| Field            | F1xx reg  | L4/G4 reg | Default | Description                          |
|------------------|-----------|-----------|---------|--------------------------------------|
| `kScan`          | `CR1` 8   | no-op     | `false` | Scan mode (multi-channel sequences)  |
| `kCont`          | `CR2` 1   | `CFGR` 13 | `false` | Continuous conversion                |
| `kDma`           | `CR2` 8   | `CFGR` 0  | `false` | DMA transfer enable                  |
| `kAlignLeft`     | `CR2` 11  | `CFGR` 15 | `false` | Left-aligned data (0 = right)        |
| `kExtTrig`→`kExtEn` | `CR2` 20 | `CFGR` 11–10 | `kDisabled` | External trigger polarity       |
| `kExtTrigSel`    | `CR2` 17–19 | `CFGR` 9–5 | 0     | External trigger source              |
| `kResolution`    | —         | `CFGR` 4–3 | `k12Bit` | Data resolution (L4/G4 only)        |
| `kAutoDelay`     | —         | `CFGR` 14 | `false` | Low-power auto-delay (L4/G4)        |
| `kOvrMod`        | —         | `CFGR` 12 | `false` | Overrun mode (L4/G4)                |
| `kOvs`           | —         | `CFGR2` 0 | `false` | Oversampling enable (L4/G4)         |
| `kOvsRatio`      | —         | `CFGR2` 4–2 | 0     | Oversampling ratio (L4/G4)          |
| `kOvsShift`      | —         | `CFGR2` 11–8 | 0    | Oversampling shift (L4/G4)          |
| `kCkMode`        | —         | `CCR` 17–16 | `kHclkDiv4` | Kernel-clock source (L4/G4, see `CkMode`) |
| `kPowerDown`     | —         | —        | `false` | Power down after init                |

F1 portability note: replace `kExtTrig = true` with `kExtEn = ExtEn::kRising`
on L4/G4.  The `kScan` field is retained as a no-op on L4/G4 for source
compatibility.

#### `CkMode` — ADC kernel-clock source (L4/G4 only)

On L4/G4 the ADC *conversion* clock is separate from the RCC bus-enable bit
that `Clocks::Enabler` toggles (that bit only gates the register interface).
After reset the async mux (`CCIPR.ADC{12}SEL`) selects no clock, so without
this setting `AnySetup::Init()` would block forever in the calibration / ADRDY
polls.  `AnySetup` writes `CCR.CKMODE` from `AnyConfig::kCkMode`:

```cpp
enum class CkMode : uint8_t
{
    kAsync    = 0,   // defer to RCC clock tree (CCIPR.ADC{12}SEL must be set up)
    kHclkDiv1 = 1,   // synchronous HCLK / 1
    kHclkDiv2 = 2,   // synchronous HCLK / 2
    kHclkDiv4 = 3,   // synchronous HCLK / 4  (default — self-contained)
};
```

The default `kHclkDiv4` makes the template self-sufficient.  Choose `kAsync`
only if you route an asynchronous ADC clock in the clock tree; `AnySetup` then
leaves `CKMODE` untouched.  (F1 has no `CKMODE`; its ADC clock comes from APB2
via `Clocks::AdcPrscl`.)

#### `Init(volatile ADC_TypeDef *adc)`

Writes `CR1`+`CR2` (F1) or `CR`+`CFGR`+`CFGR2` (L4/G4).  Unset bits are zeroed
(clearing any pre-existing configuration).

#### Template convenience overload

```cpp
template <typename P>
static void Init();     // calls Init(P::GetDevice())
```

#### Examples

**Single conversion, no scan:**
```cpp
using Cfg = Adc::AnyConfig;
// All defaults: scan=false, cont=false, dma=false, right-aligned
```

**Continuous scan mode with DMA:**
```cpp
struct MyConfig : Adc::AnyConfig
{
    static constexpr bool kScan = true;
    static constexpr bool kCont = true;
    static constexpr bool kDma  = true;
};
```

**External trigger (TIM1 CC1 event):**
```cpp
struct TrigCfg : Adc::AnyConfig
{
    static constexpr bool kExtTrig   = true;
    static constexpr uint8_t kExtTrigSel = 0;   // TIM1_CC1
};
```

---

### `AnySetup<Config, Sequence>`

One-shot boot initialiser.  Drives the complete ADC start-up sequence.

#### Template parameters

| Parameter  | Description               |
|------------|---------------------------|
| `Config`   | An `AnyConfig`-like type  |
| `Sequence` | An `AnySequence`-like type|

#### `Init()` sequence

| Step | F1xx                        | L4xx / G4xx                          |
|------|-----------------------------|--------------------------------------|
| 1    | RCC enable + reset          | RCC enable + reset                   |
| 2    | —                           | Select kernel clock (CCR.CKMODE)     |
| 3    | Write CR1 / CR2             | Write CR / CFGR / CFGR2              |
| 4    | Write SQR1-3 / SMPR1-2     | Write SQR1-4 / SMPR1-2              |
| 5    | ADON (power up)             | ADVREGEN (voltage regulator)         |
| 6    | —                           | spin ~10 µs                          |
| 7    | RSTCAL → CAL                | ADCAL (single-ended)                 |
| 8    | —                           | ADEN → wait ADRDY                    |
| 9    | conditionally clear ADON    | conditionally set ADDIS              |

After `Init()` the ADC is powered up and ready to convert.  Use the portable
helpers:

```cpp
#include "adc.h"
Adc::StartConversion(ADC1);    // CR2.SWSTART (F1) or CR.ADSTART (L4/G4)
uint16_t val = Adc::ReadData(ADC1);  // SR.EOC (F1) or ISR.EOC (L4/G4)
```

#### Example — full setup

```cpp
using Cfg = Adc::AnyConfig;   // single conversion, right-aligned
using Seq = Adc::AnySequence<Adc::Chan<Adc::Unit::k1, 0>>;

void InitAdc()
{
    Adc::AnySetup<Cfg, Seq>::Init();
}

void ReadPotentiometer()
{
    // Start conversion by software
    ADC1->CR2 |= ADC_CR2_SWSTART;

    // Poll EOC
    while (!(ADC1->SR & ADC_SR_EOC)) { }

    uint16_t val = ADC1->DR;    // 0–4095
    // use val ...
}
```

---

## Out of Scope

The following features are not wrapped by templates (users can access the
registers directly via `P::GetDevice()`):

| Feature                | Registers                       |
|------------------------|---------------------------------|
| Injected group         | `JSQR`, `JDR1–4`, `JEXTSEL`    |
| Analog watchdog        | `CR1.AWDCH`, `CR1.AWDIE`, `HTR`, `LTR` |
| Dual ADC sync mode     | `CR1.DUALMOD`, `ADC_Common_TypeDef` |
| Temperature sensor / VREFINT | `CR2.TSVREFE` (enable, then use ch 16/17) |
| Interrupt configuration | NVIC priority (user sets via CMSIS) |
| Differential mode      | `DIFSEL`, `CR.ADCALDIF` (G4 only) |
| Gain compensation      | `GCOMP` (G4 only)              |

These can all be controlled by writing directly to the `ADC_TypeDef`
registers through the `GetDevice()` pointer.
