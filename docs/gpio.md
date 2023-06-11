# <big>The `Bmt::Gpio` Name-Space</big>

The template classes exposed by this namespace shows the real advantage 
of combining templates with the `constexpr` C++ keyword.

A good example of an blue-pill application using the LCD1602 and a LED:
```cpp
using namespace Bmt;

// A data-type to setup the Port A GPIO
typedef Gpio::AnyPortSetup<
	Gpio::Port::PA,
	Gpio::Unused<0>,					// unused pin (input + pull-down)
	Gpio::AnyOut<Gpio::Port::PA, 1>,	// LCD1602 RS pin
	Gpio::AnyOut<Gpio::Port::PA, 2>,	// LCD1602 RW pin
	Gpio::AnyOut<Gpio::Port::PA, 3>,	// LCD1602 EN pin
	Gpio::AnyOut<Gpio::Port::PA, 4>,	// LCD1602 D4 pin
	Gpio::AnyOut<Gpio::Port::PA, 5>,	// LCD1602 D5 pin
	Gpio::AnyOut<Gpio::Port::PA, 6>,	// LCD1602 D6 pin
	Gpio::AnyOut<Gpio::Port::PA, 7>,	// LCD1602 D7 pin
	Gpio::Unused<8>,					// unused pin (input + pull-down)
	Gpio::Unused<9>,					// unused pin (input + pull-down)
	Gpio::Unused<10>,					// unused pin (input + pull-down)
	Gpio::Unused<11>,					// unused pin (input + pull-down)
	Gpio::Unused<12>,					// unused pin (input + pull-down)
	Gpio::Unchanged<13>,				// unchanged pin used for debugger
	Gpio::Unchanged<14>,				// unchanged pin used for debugger
	Gpio::Unchanged<15>					// unchanged pin used for debugger
> InitPA;

// Port B is entirely unused
typedef Gpio::AnyPortSetup <
	Gpio::Port::PB
> InitPB;

//! LED is connected to PC13 on BluePill
typedef Gpio::AnyOut<Gpio::Port::PC, 13> Led;
typedef Gpio::AnyPortSetup <
	Gpio::Port::PC,
	Gpio::Unused<0>,		// unused pin (input + pull-down)
	Gpio::Unused<1>,		// unused pin (input + pull-down)
	Gpio::Unused<2>,		// unused pin (input + pull-down)
	Gpio::Unused<3>,		// unused pin (input + pull-down)
	Gpio::Unused<4>,		// unused pin (input + pull-down)
	Gpio::Unused<5>,		// unused pin (input + pull-down)
	Gpio::Unused<6>,		// unused pin (input + pull-down)
	Gpio::Unused<7>,		// unused pin (input + pull-down)
	Gpio::Unused<8>,		// unused pin (input + pull-down)
	Gpio::Unused<9>,		// unused pin (input + pull-down)
	Gpio::Unused<10>,		// unused pin (input + pull-down)
	Gpio::Unused<11>,		// unused pin (input + pull-down)
	Gpio::Unused<12>,		// unused pin (input + pull-down)
	Led,					// LED on PC13
	Gpio::Unchanged<14>,
	Gpio::Unchanged<15>
> InitPC;
```

At the center of this design is the `AnyPinGroup<>` template, which is 
the base template for `AnyPortSetup<>`. You can see a definition of this 
data-type as a working state of a pin group of your GPIO, when your 
design enters some specific context.

For example, on the **glossy-msp430** project, you have an initial state 
where firmware assigns default functions for each GPIO pin. Later, 
prompting for a command received by the PC, it establishes a JTAG 
connection to a target MSP430 chip using many MCU resources, such as SPI, 
Timers, DMA and the classic bit-banging on some pins.

Because of the nature of a JTAG connection, the firmware starts this bus 
using Hi-Z. During the target reset, some pins are are bit-banged while 
others are kept in Hi-Z. Finally, when the JTAG target is captured, all 
bus pins enters low impedance.

![images/jtag-debug.svg](images/jtag-debug.svg)

<div hidden>
```
@startuml jtag-debug
[*] --> HiZ : Boot
HiZ : All GPIO pins are left on Hi-Z
HiZ : or weak pull up/down resistor
HiZ --> JtagCapture : PC asks connection
JtagCapture : A limited set of pins are used
JtagCapture : other pins are left unchanged
JtagCapture --> JtagControl : Connection success
JtagControl : The full set of JTAG pins are active
JtagControl --> JtagControl : Debug session
JtagControl --> HiZ : Disconnect
@enduml
```
</div>

Imagine now that through the `AnyPinGroup<>` template you define each of 
these states and through a simple `MyType::Enable()` call alls GPIO pins 
are configured using the least possible number of instructions, almost 
exactly if you code everything in assembly and lots of manual 
bit-constant calculation for the values involved for each case.

In C++, you work with many `typedef`, combining them as much as possible, 
which are *abstractions* that compute in *compile-time* each of the 
constant involved on a specific operation.

Lets dive into details, starting from the ground up.

# Elementary Data-Types

The following data-types are all strongly typed enumerations, which are 
shared among all supported devices.  
The are used for the configuration of individual pins. 

> Some of the combinations may not make sense for your specific hardware, 
> since modern parts have more features.

## The `Gpio::Port` Enumeration

This is the enumeration that identifies one of your GPIO unit, which 
depends on your hardware.  
The definition of the data type is:

```cpp
/// All possible GPIO peripherals
enum class Port
{
	PA = 0,		///< Port A
	PB = 1,		///< Port B
	PC = 2,		///< Port C
#ifdef GPIOD
	PD = 3,		///< Port D
#endif
#ifdef GPIOE
	PE = 4,		///< Port E
#endif
#ifdef GPIOF
	PF = 5,		///< Port F
#endif
#ifdef GPIOG
	PG = 6,		///< Port G
#endif
#ifdef GPIOH
	PH = 7,		///< Port H
#endif
	kUnusedPort = -1
};
```

Through the use of conditional compilation, it translates implemented 
GPIO instances to a strongly typed enumeration.

> Note that the conditional compilation depends on the BSP file you are 
> including and the device macro. See the installation guide for details 
> on this.


## The `Mode` Enumeration

This is the `Mode` enumeration:

```cpp
/// GPIO pin mode of operation
enum class Mode
{
	kInput = 0,				///< Input pin
	kAnalog,				///< Analog pin
	kOutput,				///< General purpose output (push/pull)
	kOpenDrain,				///< General purpose output (Open drain)
	kAlternate,				///< Alternate function (push/pull)
	kOpenDrainAlt,			///< Alternate function (Open drain)
};
```

This enumeration specifies the mode of operation of a single GPIO pin. 
There are thorough documentation on the device data-sheet, which may have 
subtle differences depending on the specific part.

In general:
- `kInput` is used to configure a pin to read digital states.
- `kAnalog` is used to configure the pin for an analog function, 
typically the ADC.
- `kOutput` is used to configure a pin as output. The state is defined by 
software and is typically used when bit-banging a pin.
- `kOpenDrain` works like `kOutput`, but the output drivers are 
configured as open drain. In such operating mode it is required a pull-up 
resistor, which should be provided in the hardware design or the 
alternative weak pull-up of the MCU. There is another enumeration to 
configure the behavior of the internal pull-up resistor.
- `kAlternate` is used to activate alternate mode, which means that the 
pin will be controlled by any of the allowed embedded peripheral.  
Usually another parameter complete this mode, which varies slightly 
depending on the MCU model. In general newer MCUs have more flexible 
peripheral selection options.
- `kOpenDrainAlt` is exactly the same as the previous option, but the 
output drivers are configured as open drain. Please note that the use of 
weak pull-up resistor will reduce the speed of the bus. This can be an 
issue when longer lines/wires are used.


## The `Speed` Enumeration

On the STM32 you are allowed to configure the bus speed, using this 
enumeration:

```cpp
/// Output pin speed configuration (device specific)
enum class Speed
{
	kInput = 0,				///< Input pin
	kSlow = 0,				///< Low speed
	kMedium = 1,			///< Intermediate speed
	kFast = 2,				///< Lowest speed and lowest energy consumption
	kFastest = 3			///< Maximum speed and highest energy consumption (> 50 Mhz)
};
```

Note that the speed configures how strong the output drivers will control 
the pin. Lines with more load capacitance require stronger outputs, to 
ensure that they are properly discharged. Note that short PCB paths tends 
to work without hassle and require less strength. 

> Its is important to note that this configuration may have an impact on 
> power consumption. If you are designing a low power device, consider 
> tuning these parameter, to improve battery performance.


## The `PuPd` Enumeration

This enumeration controls the use of the embedded pull-up and down 
resistors on each pin:

```cpp
/// Pull-up or Pull-down feature
enum class PuPd
{
	kFloating = 0,			///< Floating pin
	kPullUp,				///< Activates internal Pull-up
	kPullDown,				///< Activates internal Pull-down
};
```

In general this affects the input behavior of the internal pull up and 
down resistors. On older models this affects the behavior of the pins 
only when configured as input. Newer models can control the presence of 
the resistor load also when pin is configured as output.  
Check device data-sheet for more details.

## The `Level` Enumeration

```cpp
/// Pin voltage/logical level
enum class Level
{
	kLow = 0,				///< Drive pin to low voltage level
	kHigh = 1				///< Drive pin to high voltage level
};
```

This information indicates what is the output level of the pin. When the 
pin is configured as input this parameter has no effect.


# Pin Remapping Feature

The GPIO of a STM32 MCU allows for many possible uses. The normal way is 
the typical bit-banging, but when you want to interface a peripheral with 
the outer world you have to remap a pin to connect to a different source.

Depending on the STM32 model there are quite different possibilities to 
remap a GPIO pin. Older models are less flexible while newer models 
have powerful multiplexers.

In general a template called `AnyAFR<>` will represent the remapping 
hardware present on your device.

As already mentioned this definition differs substantially according to 
your target device.

In general it is not important to know how to specify a data-type based 
on the `AnyAFR<>` template, since all possible definitions are already 
provided.  
For every implemented target you will find the **\<family>/pinremap.h** file 
with all possible instances.

We will cover teach particular family in the next subtopics.


## STM32F1xx Family

For the STM32F103 you have the following type definition:

```cpp
template<
	const uint32_t CONF			///< The specific configuration bits
	, const uint32_t MASK		///< The mask to clear the configuration bits
	>
struct AnyAFR
{
	//...

	/// Enables the alternate function
	static void Enable(void);
	/// Disables the alternate function
	static void Disable(void);
};

/// No pin remapping (for regular GPIO function)
typedef AnyAFR<0x00000000U, 0xFFFFFFFF> AfNoRemap;

```

In general for this family two parameters are used with configuration and 
mask for the `AFR` register, while a specific combination is considered 
as *no remapping*, the reserved `AfNoRemap` symbol.

You can always `Enable()` or `Disable()` a configuration, which is 
rarely needed since this is covered by the `AnyPinGroup<>` template, 
covered later on this document.

The interesting part is the **f1xx/pinremap.h** file, which contains all 
definitions, and we list a brief excerpt here:

```cpp
#pragma once

namespace Bmt
{
namespace Gpio
{

// SPI1
/// SPI1 alternate configuration 1 using PA4, PA5, PA6 and PA7
typedef AnyAFR<0x00000000U, ~AFIO_MAPR_SPI1_REMAP_Msk> AfSpi1_PA4_5_6_7;
/// SPI1 alternate configuration 2 using PA15, PB3, PB4 and PB5
typedef AnyAFR<AFIO_MAPR_SPI1_REMAP, ~AFIO_MAPR_SPI1_REMAP_Msk> AfSpi1_PA15_PB3_4_5;

//...

// USART1
/// USART1 alternate configuration 1 using PA9 and PA10
typedef AnyAFR<0x00000000U, ~AFIO_MAPR_USART1_REMAP_Msk> AfUsart1_PA9_10;

//...

/// 2-pin JTAG bus active (3-pin with optional SWO)
typedef AnyAFR<AFIO_MAPR_SWJ_CFG_JTAGDISABLE, ~AFIO_MAPR_SWJ_CFG_Msk> AfSwd3;
/// No emulation active
typedef AnyAFR<AFIO_MAPR_SWJ_CFG_DISABLE, ~AFIO_MAPR_SWJ_CFG_Msk> AfSwd2;

}	// namespace Gpio
}	// namespace Bmt
```

So in general you have specific data type definitions listed on this file 
for each possible configuration.

So, for example, you can activate the 3-pin SWD debug interface by 
calling:

```cpp
AfSwd3::Enable();
```

In general you will not need to call individually each possible 
configuration, since we can solve this in a single *batch*, as we will 
cover later in the `AnyPinGroup<>` template documentation.


## STM32L4xx and STM32G4xx Family

For the STM32L432 and STM32G431 you have the following type definition:

```cpp
/// Alternate function value
enum class AF : uint8_t
{
	k0,
	k1,
	//...
	k15,
};

/// A template class for Alternate GPIO Function initialization
template<
	const Gpio::Port kPort		///< The specific configuration bits
	, const uint8_t kPin		///< Port bit for the configuration
	, const AF kAfr				///< The value for AFRx register
	>
struct AnyAFR
{
	//...

	/// Enables the alternate function
	static void Enable(void);
	/// Disables the alternate function (don't care)
	static void Disable(void);
};

// Used to deactivate remapping
typedef AnyAFR<Port::kUnusedPort, 0, AF::k0> AfNoRemap;
```

The template definition for this family is quite different from the older 
brothers, and features a dedicated and independent multiplexer for each 
GPIO pin, so an additional information was added.

Similar to the previous family, the `AfNoRemap` symbol is reserved to 
indicate a ordinary GPIO pin.

While the `Enable()` command acts like in the previous family, the 
`Disable()` has no effect, since the remapping feature is controlled 
directly on the GPIO registers (i.e, there is no dedicated remapping 
unit).

As with the previous family, you will find the **l4xx/pinremap.h** file 
with a huge list of available configurations:

```cpp
#pragma once

namespace Bmt
{
namespace Gpio
{

// SYS
typedef AnyAFR<Port::PA, 8, AF::k0>		AfMCO_PA8;
typedef AnyAFR<Port::PA, 14, AF::k0>	AfJTCK_PA14;
typedef AnyAFR<Port::PA, 15, AF::k0>	AfJTDI_PA15;

//...

// I2C1
typedef AnyAFR<Port::PA, 9, AF::k4>		AfI2C1_SCL_PA9;
typedef AnyAFR<Port::PB, 6, AF::k4>		AfI2C1_SCL_PB6;
typedef AnyAFR<Port::PB, 8, AF::k4>		AfI2C1_SCL_PB8;

//...

typedef AnyAFR<Port::PI, 10, AF::k15>	AfEVENTOUT_PI10;
typedef AnyAFR<Port::PI, 11, AF::k15>	AfEVENTOUT_PI11;
#endif	// defined(GPIOI_BASE)


}	// namespace Gpio
}	// namespace Bmt
```

Because of the nature of this hardware implementation, each pin has to be 
configured individually, which is really not practical, without the use 
of the `AnyPinGroup<>` template class covered later in this document.


# The `AnyPin<>` Template Class

This is a template class that completely defines the behavior of GPIO pin. 
This is the template definition for the STM32F1xx family:

```cpp
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin					///< The pin of the port
	, const Mode kMode = Mode::kInput		///< Mode to configure the port
	, const Speed kSpeed = Speed::kInput	///< Speed for the pin
	, const PuPd kPuPd = PuPd::kFloating	///< Additional pin configuration (applies to input pin)
	, const Level kLevel = Level::kLow		///< Initial pin level (applies to output pin)
	, typename Map = AfNoRemap				///< Pin remapping feature (pinremap.h)
>
class AnyPin : public Private::Implementation_<
	Private::Impl::kNormal
	, kPort
	, kPin
	, kMode
	, kSpeed
	, kPuPd
	, kLevel
	, Map
>
{};
```

When using the **bmt** library you are encourage to create data-types for 
each pin you have assigned in your hardware design.
This data-types describe the settings of your pin. Later when grouping 
pins, the library will merge bits and masks to produce an optimized 
access to the hardware registers.

The `AnyPin<>` template lets you specify the pin function in every 
possible detail. Some combinations may not work due to hardware 
limitation.

A set of attributes and methods is available when using an override of 
this class, covered on the next sub-topics.


## Available Methods


## Constants Defined For the Data-Type

A series of constants are defined to implement the pin functionality:

| Constant      | Data Type         | Description                           |
|:--------------|:------------------|:--------------------------------------|
| `kPort_`      | `Bmt::Gpio::Port` | GPIO port                             |
| `kPortBase_`  | `uint32_t`        | Base address of the port HW registers |
| `kPin_`       | `uint8_t`         | The pin number                        |
| `kSpeed_`     | `Bmt::Gpio::Speed`| The pin speed                         |
| `kMode_`      | `Bmt::Gpio::Mode` | The pin mode                          |
| `kPuPd_`      | `Bmt::Gpio::PuPd` | The Pul-up/Pull-down configuration    |
| `kIsInput_`   | `bool`            | `true` for input pins                 |
| `kIsPuPd_`    | `bool`            | `false` for floating pins             |
| `kCrBits_`    | `uint8_t`         | Raw value for **CR*x*** register      |
| `kCRL_`       | `uint32_t`        | Value for **CRL** register            |
| `kCRH_`       | `uint32_t`        | Value for **CRH** register            |
| `kCRL_Mask_`  | `uint32_t`        | Mask value for **CRL** register       |
| `kCRH_Mask_`  | `uint32_t`        | Mask value for **CRH** register       |
| `kBitValue_`  | `uint16_t`        | Bit value                             |
| `kBsrrValue_` | `uint32_t`        | Value for **BSRR** register           |
| `kODR_`       | `uint16_t`        | Value for **ODR** register            |
| `kODR_Mask_`  | `uint16_t`        | Mask value for **ODR** register       |
| `kAfConf_`    | `uint32_t`        | Value for the **AFR** register        |
| `kAfMask_`    | `uint32_t`        | Mask value for the **AFR** register   |

> These values are probably of no use for most cases.


# The `AnyPin<>` Template Class Specializations

Since the universality of this template, other template specialization 
exists to cover usual project requirements, listed below:


## The `AnyAnalog<>` Template

This is a reduced form of the `AnyPin<>`, optimized for Analog pins, 
which looks like this:

```cpp
//! Template for analog pins
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin					///< The pin of the port
	, typename Map = AfNoRemap				///< Pin remapping feature (pinremap.h)
>
class AnyAnalog : public Private::Implementation_<
	Private::Impl::kNormal
	, kPort
	, kPin
	, Mode::kAnalog
	, Speed::kInput
	, PuPd::kFloating
	, Level::kLow
	, Map
>
{};
```


## The `AnyIn<>` Template

This is a specialized template to initialize a pin as **Input**: 

```cpp
//! Template for input pins
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin					///< The pin of the port
	, const PuPd kPuPd = PuPd::kFloating	///< Additional pin configuration 
											///< (applies to input pin)
	, typename Map = AfNoRemap				///< Pin remapping feature (pinremap.h)
>
class AnyIn : public Private::Implementation_<
	Private::Impl::kNormal
	, kPort
	, kPin
	, Mode::kInput
	, Speed::kInput
	, kPuPd
	, Level::kLow
	, Map
>
{};
```

The following example specifies the PA8 pin as floating input for TIM1 
CH1 function:

```cpp
/// A configuration to map TIM1 CH1 floating pin on PA8
typedef AnyPin<Port::PA, 8, PuPd::kFloating, AfTim1_PA12_8_9_10_11_PB12_13_14_15>
	TimCh1In;
```

> A similar setting is already available on the **gpio-types.h** file.

You can always activate this pin configuration with a simple command like:

```cpp
TimCh1In::Enable();
```


## The `Floating<>` Template

This is a specialization of the `AnyIn<>` template to initialize a pin as 
a **floating input**: 

```cpp
/// A template class to configure a port pin as a floating input pin
template <
	const Port kPort			///< The GPIO port
	, const uint8_t kPin		///< The GPIO pin number
	, typename Map = AfNoRemap	///< Pin remapping feature (pinremap.h)
>
class Floating : public AnyIn<kPort, kPin, PuPd::kFloating, Map>
{
};
```

Repeating the last example, using this template class we can repeat the 
definition less verbosely:

```cpp
/// A configuration to map TIM1 CH1 floating pin on PA8
typedef Floating<Port::PA, 8, AfTim1_PA12_8_9_10_11_PB12_13_14_15>
	TimCh1In;
```


## The `AnyInPu<>` Template

This is a specialization of the `AnyIn<>` template to initialize a pin as 
an **input** with the internal **weak pull-up** resistor active: 

```cpp
/// A template class to configure a port pin as digital input having a pull-up
template <
	const Port kPort
	, const uint8_t kPin
	, typename Map = AfNoRemap	///< Pin remapping feature (pinremap.h)
>
class AnyInPu : public AnyIn<kPort, kPin, PuPd::kPullUp, Map>
{
};
```


## The `AnyInPd<>` Template

```cpp
/// A template class to configure a port pin as digital input having a pull-down
template <
	const Port kPort
	, const uint8_t kPin
	, typename Map = AfNoRemap	///< Pin remapping feature (pinremap.h)
>
class AnyInPd : public AnyIn<kPort, kPin, PuPd::kPullDown, Map>
{
};
```


## The `AnyOut<>` Template

```cpp
//! Template for output pins
template<
	const Port kPort					///< The GPIO port
	, const uint8_t kPin				///< The pin of the port
	, const Speed kSpeed = Speed::kFast	///< Speed for the pin
	, const Level kLevel = Level::kLow	///< Initial pin level (applies to output pin)
	, const Mode kMode = Mode::kOutput	///< Mode to configure the port
	, typename Map = AfNoRemap			///< Pin remapping feature (pinremap.h)
>
class AnyOut : public Private::Implementation_<
	Private::Impl::kNormal
	, kPort
	, kPin
	, kMode
	, kSpeed
	, PuPd::kFloating
	, kLevel
	, Map
>
{
};
```


## The `AnyFastOut0<>` Template

```cpp
//! Template for fast output pins at logic level low
template<
	const Port kPort							///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, typename Map = AfNoRemap					///< Pin remapping feature (pinremap.h)
>
class AnyFastOut0 : public AnyOut<
	kPort
	, kPin
	, Speed::kFast
	, Level::kLow
	, Mode::kOutput
	, Map
>
{
};
```


## The `AnyFastOut1<>` Template

```cpp
//! Template for fast output pins at logic level hi
template<
	const Port kPort							///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, typename Map = AfNoRemap					///< Pin remapping feature (pinremap.h)
>
class AnyFastOut1 : public AnyOut<
	kPort
	, kPin
	, Speed::kFast
	, Level::kHigh
	, Mode::kOutput
	, Map
>
{
};
```


## The `AnyOutOD<>` Template

```cpp
//! Template for open drain output pins
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, const Speed kSpeed = Speed::kFast			///< Speed for the pin
	, const Level kLevel = Level::kLow			///< Initial pin level (applies to output pin)
	, typename Map = AfNoRemap					///< Pin remapping feature (pinremap.h)
>
class AnyOutOD : public AnyOut<
	kPort
	, kPin
	, kSpeed
	, kLevel
	, Mode::kOpenDrain
	, Map
>
{
};
```


## The `AnyAltOut<>` Template

```cpp
//! Template for generic alternate output pins
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, typename Map								///< Pin remapping feature (pinremap.h)
	, const Speed kSpeed = Speed::kFast			///< Speed for the pin
	, const Level kLevel = Level::kLow			///< Initial pin level (applies to output pin)
	, const PuPd kPuPd = PuPd::kFloating		///< Additional pin configuration
	, const Mode kMode = Mode::kAlternate		///< Mode to configure the port
>
class AnyAltOut : public Private::Implementation_<
	Private::Impl::kNormal
	, kPort
	, kPin
	, kMode
	, kSpeed
	, kPuPd
	, kLevel
	, Map
>
{
};
```


## The `AnyAltOutPP<>` Template

```cpp
//! Template for Push-Pull alternate output pins
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, typename Map								///< Pin remapping feature (pinremap.h)
	, const Speed kSpeed = Speed::kFast			///< Speed for the pin
	, const Level kLevel = Level::kLow			///< Initial pin level (applies to output pin)
>
class AnyAltOutPP : public AnyAltOut <
	kPort
	, kPin
	, Map
	, kSpeed
	, kLevel
	, PuPd::kFloating
	, Mode::kAlternate
>
{
};
```


## The `AnyAltOutOD<>` Template

```cpp
//! Template for Open-Drain alternate output pins
template<
	const Port kPort						///< The GPIO port
	, const uint8_t kPin						///< The pin of the port
	, typename Map								///< Pin remapping feature (pinremap.h)
	, const Speed kSpeed = Speed::kFast			///< Speed for the pin
	, const Level kLevel = Level::kLow			///< Initial pin level (applies to output pin)
>
class AnyAltOutOD : public AnyAltOut <
	kPort
	, kPin
	, Map
	, kSpeed
	, kLevel
	, PuPd::kPullUp		// unsupported by this hardware
	, Mode::kOpenDrainAlt
>
{
};
```


## The `<>` Template

```cpp
```




For example,
the **f1xx/gpio-types.h** file contains almost every available function 
of this MCU model, ready to be used. Lets take the definition of the SCK 
pin of the SPI1 peripheral. On the default configuration, this pin is 
tied to the PA5 pin.

```cpp
/// A default configuration to map SPI1 SCK on PA5 pin (master)
typedef AnyAltOut<Port::PA, 5, AfSpi1_PA4_5_6_7> SPI1_SCK_PA5;
```

