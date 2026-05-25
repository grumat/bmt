# <big>The `Bmt::Adc` Name-Space</big>

The `Adc` namespace provides template types for configuring the
analog-to-digital converter on STM32F1xx.  All register values are computed at
compile time via fold expressions, reducing runtime overhead to a handful of
register writes.

The library handles ADC1 (all variants), ADC2 (when `ADC2_BASE` is defined),
and ADC3 (when `ADC3_BASE` is defined) via peripheral-existence dispatch.

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

| Enumerator | Availability                |
|------------|-----------------------------|
| `k1`       | All F1xx variants           |
| `k2`       | Parts defining `ADC2_BASE`  |
| `k3`       | Parts defining `ADC3_BASE`  |

Example:
```cpp
Adc::Unit::k1   // ADC1
```

---

### `Peripheral<Unit>`

Typed wrapper around a single ADC hardware block.  Each specialization
exposes:

| Member             | Description                          |
|--------------------|--------------------------------------|
| `kEnBit`           | Bit mask in `RCC_APB2ENR`            |
| `kRstBit`          | Bit mask in `RCC_APB2RSTR`           |
| `kBase`            | `volatile ADC_TypeDef *` pointer     |
| `kIrq`             | CMSIS `IRQn_Type` enum value         |
| `RccTrait_`        | Compatible with `Clocks::Enabler`    |
| `Common()`         | Returns `ADC_Common_TypeDef *` (k1, k2 only) |

Example — explicit clock control:
```cpp
using Adc1 = Adc::Peripheral<Adc::Unit::k1>;
Clocks::Enabler<Adc1>::Enable();     // set RCC_APB2ENR_ADC1EN
Clocks::Enabler<Adc1>::Reset();      // pulse RCC_APB2RSTR_ADC1RST
```

#### IRQ note

- `Peripheral<Unit::k1>` and `k2` use `ADC1_2_IRQn`.  On single-ADC parts
  (F100, F101, F102) the CMSIS header provides a `#define ADC1_2_IRQn ADC1_IRQn`
  alias, so the name compiles everywhere.
- `Peripheral<Unit::k3>` uses `ADC3_IRQn` (only defined for high-density F103).

#### Common register note

`Common()` returns a pointer to the shared `ADC_Common_TypeDef` block at the
ADC1 base address.  This is useful only for dual-ADC synchronous mode
(controlled via `CR1.DUALMOD`).  Not available for ADC3.

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
| `kChan`            | Channel number 0–17             |
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

| Constant      | Register | Description                       |
|---------------|----------|-----------------------------------|
| `kSqr1`       | `SQR1`   | SQ[13..16] fields (bits 0–19)    |
| `kSqr2`       | `SQR2`   | SQ[7..12] fields (bits 0–29)     |
| `kSqr3`       | `SQR3`   | SQ[1..6] fields (bits 0–29)      |
| `kLenField`   | `SQR1`   | L[3:0] = length − 1 (bits 20–23) |
| `kSmpr1`      | `SMPR1`  | SMP[10..17] fields (bits 0–23)   |
| `kSmpr2`      | `SMPR2`  | SMP[0..9] fields (bits 0–29)     |
| `kLen`        | —        | Number of channels (`size_t`)     |

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

| Field          | Register | Bit(s) | Default | Description                          |
|----------------|----------|--------|---------|--------------------------------------|
| `kScan`        | `CR1`    | 8      | `false` | Scan mode (multi-channel sequences)  |
| `kCont`        | `CR2`    | 1      | `false` | Continuous conversion                |
| `kDma`         | `CR2`    | 8      | `false` | DMA transfer enable                  |
| `kAlignLeft`   | `CR2`    | 11     | `false` | Left-aligned data (0 = right)        |
| `kExtTrig`     | `CR2`    | 20     | `false` | External trigger enable              |
| `kExtTrigSel`  | `CR2`    | 17–19  | 0       | External trigger source (0–7)        |
| `kPowerDown`   | —        | —      | `false` | Clear ADON after init                |

#### `Init(volatile ADC_TypeDef *adc)`

Writes `CR1` and `CR2`.  Unset bits are zeroed (clearing any pre-existing
configuration).

#### Template convenience overload

```cpp
template <typename P>
static void Init();     // calls Init(P::kBase)
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

1. **RCC enable + reset** — via `Clocks::Enabler<P>::Init()`
2. **CR1 / CR2** — via `Config::Init(P::kBase)`
3. **SQR + SMPR** — via `Sequence::Init()`
4. **Power up** — set `ADON` bit
5. **Calibrate** — poll `RSTCAL` then `CAL` (busy-wait per RM0008 sequence)
6. **Power down** — if `Config::kPowerDown` is true, clear `ADON`

After `Init()` the ADC is powered up (`ADON` set) and ready to convert.  Start
a conversion by writing `SWSTART` to `CR2`:

```cpp
ADC1->CR2 |= ADC_CR2_SWSTART;
// or if using P:
// Adc::Peripheral<Adc::Unit::k1>::kBase->CR2 |= ADC_CR2_SWSTART;
```

Wait for `ADC_SR_EOC` before reading `DR`.

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
registers directly via `P::kBase`):

| Feature                | Registers                       |
|------------------------|---------------------------------|
| Injected group         | `JSQR`, `JDR1–4`, `JEXTSEL`    |
| Analog watchdog        | `CR1.AWDCH`, `CR1.AWDIE`, `HTR`, `LTR` |
| Dual ADC sync mode     | `CR1.DUALMOD`, `ADC_Common_TypeDef` |
| Temperature sensor / VREFINT | `CR2.TSVREFE` (enable, then use ch 16/17) |
| Interrupt configuration | NVIC priority (user sets via CMSIS) |

These can all be controlled by writing directly to the `ADC_TypeDef`
registers through the `kBase` pointer.
