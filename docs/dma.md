# <big>`Dma` Template Classes</big>

STM32 devices typically features at least one DMA controller with up to 8 
channels.  
The **bmt** library has a set of template classes to allow for a 
straightforward way to setup a DMA channel. 


# The `Dma::AnyID<>` Template Class

This is a very simple template class that is used to define a specific 
DMA channel. 

For legacy parts, like the STM32F103, this template class is defined as: 

```cpp
/// Key specifying a DMA channel selection for any served peripheral
template <
	Itf kItf
	, Chan kChan
> struct AnyID
{
	// ...
}
```

On newer models, an additional template argument is provided that will 
be used to setup the input multiplexer and it looks like this:

```cpp
/// Key specifying a DMA channel selection for any served peripheral
template <
	Itf kItf
	, Chan kChan
	, PerifSel kChSel
> struct AnyID
{
	// ...
}
```


## Template Arguments

Note that the meaning of each template argument varies according to STM32 
device family. Except for the SMT32G4xx family you will not need to 
handle with these arguments, since they are fixed by MCU hardware design 
and provided in the **dma-cfgs.h** file, covered later.
- **`kItf`**: This is the DMA interface. Usually on the MCU models 
supported by this library you have up to two DMA interfaces: 
**`Dma::Itf::k1`** or **`Dma::Itf::k2`**.
- **`kChan`**: Each DMA interface can have up to 8 DMA channels. This 
parameter specifies the DMA channel.
- **`kChSel`**: The meaning of this parameter depends on the family: 
  - **`STM32F1xx`**: Not present. Possibilities are hardwired and 
  conflicts between different devices are very common. Sometimes you need 
  to demote functionality, to promote more demanding peripherals. 
  - **`STM32L4xx`**: Indicates one of the 16 DMA channel input. Although 
  more flexible than previous generation, channels are still connected to 
  a limited set of predefined functions.
  - **`STM32G4xx`**: Last MCU generations have extremely flexible design 
  and no conflicts will happen except if you need more DMA channels than 
  offered by the device. In this family this parameter allows more than 
  100 different values. One value for each possible DMA trigger source. 

As already mentioned, all possibilities offered by the hardware are 
listed on the **dma-cfgs.h** file, except for the latest family, where 
two different approaches were used. This will be covered on a dedicated 
topic later.

> Later you will see how to associate this template-type with the DMA 
> channel, so that you can setup the transfer operation.


## The `dma-cfgs.h` File: STM32F1xx Family

Since the connection possibilities are limited by hardware design, the 
library provides the **dma-cfgs.h** file with all possible connections.

You have one file for each supported device family.

For the examples below we will use the **SPI1 RX** dma trigger to 
exemplify how the **bmt** library was designed. This trigger signal is 
issued when the **SPI1** peripheral receives data, and requests the DMA 
channel to move the data away to the programmed destination address 
without CPU interference. 

On the SMT32F103 family, this request is hardwired to the DMA1, channel 
2, which is the single way to serve it, without CPU interference.  
If you search the specific implementation file you will find the 
following type definition: 

```cpp
// ...
/// A template class to map SPI1 RX to DMA channel
typedef AnyID<Itf::k1, Chan::k2> IdSpi1Rx;
// ...
```

But because you have far more triggers than DMA channels, DMA channels 
are shared by more than one device. So if you continue searching you will 
find other signals associated to the DMA1 channels 2, like this:

```cpp
// ...
/// A template class to map USART3 TX to DMA channel
typedef AnyID<Itf::k1, Chan::k2> IdUsart3Tx;
// ...
```

This essentially means that you cannot operate both devices at the same 
time using DMA for data transfer. In this MCU generation trigger signals 
coming from different devices are simply OR-ed. So, you are not required 
to provide a value for a multiplexer to select the exact trigger source.

This changes on the next MCU generation, the **STM32L432**, where you 
have more DMA possibilities but are required to program a multiplexer to 
select the exact trigger source.


## The `dma-cfgs.h` File: STM32L4xx Family

For this series, the **SPI1 RX** has two DMA options: DMA1 and channel 2 
or DMA2 channel 3.

Looking for the type definition for this family you will see that an 
additional parameter is provided with the multiplexer value:

```cpp
// ...
/// A template class to map SPI1 RX to DMA channel
typedef AnyID<Itf::k1, Chan::k2, PerifSel::k1> IdSpi1Rx;
/// A template class to map SPI1 RX to DMA channel (alternate)
typedef AnyID<Itf::k2, Chan::k3, PerifSel::k4> IdSpi1Rx_2;
// ...
```

Semantics for the third parameter changes a lot on the newer generation, 
the STM32G4xxx, because a complete multiplexer is provided for each DMA 
channel, which allows you to associate any of the possible trigger with 
any of the available DMA channels.


## The `dma-cfgs.h` File: STM32G4xx Family

The newest device generation of the STM32 family features a DMAMUX 
peripheral that extends the flexibility of a DMA channel to operate with 
any of the embedded peripherals. So you can select one signal from a list 
of more than 100 different signal sources. 

So for these devices you are not limited to a very specific set of 
settings like in previous generations.

This difference can be seen on the definition of the **`Dma::PerifSel`** 
enumeration:

```cpp
enum class PerifSel : uint8_t
{
	kAdc1 = 5,	// ADC1
	// ...
	kSpi1Rx = 10,	// SPI1 RX
	kSpi1Tx = 11,	// SPI1 TX
	// ...
};
```

This enumeration indicates the identification of a single DMA trigger 
signal. 

So you can define a DMA channel identification, this way:

```cpp
/// Use DMA1 Channel 1 with the SPI1 RX trigger signal
typedef AnyID<Itf::k1, Chan::k1, PerifSel::kSpi1Rx> MySpi1RxDma;
```

For backwards compatibility, the library provides a mapping with 
configurations similar to the STM32L4xx family, so software targeted to 
the older family will compile without issues. Labels and input sources 
behaves like in the past. This feature enforces code portability between 
**STM32L4xx** and the new **STM32G4xx** series. 

For the example shown before, the **SPI1 RX** trigger, the compatibility 
data types found on the `dma-cfgs.h` file is:

```cpp
// ...
/// A template class to map SPI1 RX to DMA1 channel 2
typedef AnyID<Itf::k1, Chan::k2, PerifSel::kSpi1Rx> IdSpi1Rx;
/// A template class to map SPI1 RX to DMA2 channel 3 (alternate)
typedef AnyID<Itf::k2, Chan::k3, PerifSel::kSpi1Rx> IdSpi1Rx_2;
// ...
```


# The `Dma::AnyChannel<>` Template Class

This class represnets a DMA channel which is able to transfer data independently of the CPU


## A Software Analogy

From a C/C++ analogy a typical DMA operation can be compared to the 
`memcpy()` function, but more flexible and independent. So, the following 
hypothetical code is a reasonable analogy to the DMA hardware 
implementation: 

```cpp
// Hypothetical function that waits until a hardware trigger happens
extern bool WaitForTrigger();

// This runs async from CPU!
void DmaTransfer(uint8_t *dest, const uint8_t *src, uin16_t cnt)
{
	if (cnt != 0)
	{
		// Loops once per DMA trigger
		while(WaitForTriger() && cnt--)
			*dest++ = *src++;
	}
}
```


### Control of Pointer Increment

The first thing to note is that DMA allows you to configure if pointers 
are incremented for each transfer, so the following pointer operations 
are possible: 

```cpp
// 1) No pointer increment:
*dest = *src;
// 2) Only source pointer increments:
*dest = *src++;
// 3) Only destination pointer increments:
*dest++ = *src;
// 4) Both pointers will increment:
*dest++ = *src++;
```

This is a quite interesting feature, since hardware peripheral have fixed 
register addresses to perform I/O operation, while your buffer stores 
data sequentially.


### Size of Pointer

Another important characteristic of a data transfer is the size of each 
data transfer. You are allowed do choose a pointer size of 8, 16 or 
32-bits.

Besides, source and destination pointer sizes have not to be the same. 
While pointer increment uses the configured pointer size, the hardware 
provides data cast operations so that different pointer sizes can be 
freely used. 

```cpp
// source address
uin8_t *src = ...;
// destination address
uin16_t *dest = ...;
// number of transfers
uint16_t cnt = ...;
// copy data between different pointer sizes
while(cnt)
{
	*dest = (uint16_t)*src++;
	--cnt;
}
```

For each pointer, you have the `PtrPolicy` enumeration to control if the 
pointer increments and what size it has:

```cpp
/// Policy used for the source/target pointer
enum class PtrPolicy
{
	kBytePtr			///< Performs a *pByte operation
	, kBytePtrInc		///< Performs a *pByte++ operation
	, kShortPtr			///< Performs a *pShort operation
	, kShortPtrInc		///< Performs a *pShort++ operation
	, kLongPtr			///< Performs a *pLong operation
	, kLongPtrInc		///< Performs a *pLong++ operation
};
```

### Circular Buffers

An extra feature provided by the DMA hardware are circular buffers. 
Circular buffers are valid for the pointers configured in increment mode, 
as covered before. If you activate the circular mode, the cnt value is 
checked on every operation and when it reaches zero, all values are 
restarted. In other words, pointers and counters restarts to the initial 
value, and DMA operation does not ends, so that a new transfer can be 
handled normally. This behavior implements a circular buffer.  
No need to say that the old data is overwritten and hopefully your 
program has handled it before.


### Data Direction

Here we reach a concept that has no direct analogy with a C source code 
or data type: **Data direction**.

Because on the MCU you have different buses for memory and peripherals, 
which may run with different clocks, it is important for the DMA 
operation, to identify if transfers occurs to or from the peripheral. 

In the **bmt** library both concepts, data direction and circular buffer, 
are configured using the following enumeration: 

```cpp
// Data direction of the DMA operation
enum class Dir
{
	kMemToMem			// Memory to memory
	, kPerToMem			// Peripheral to memory
	, kPerToMemCircular	// Peripheral to memory circular mode
	, kMemToPer			// Memory to peripheral
	, kMemToPerCircular	// Memory to peripheral circular mode
};
```


### Priority

Since you have many DMA channels competing for the bus, you can provide a 
priority for the operation, in the case two or more channels compete for 
the resource.

The following enumeration defines DMA priorities:

```cpp
// The DMA priority
enum class Prio
{
	kLow				// Low channel priority
	, kMedium			// Medium channel priority
	, kHigh				// High channel priority
	, kVeryHigh			// Very high channel priority
};
```

> Note that these priorities configures an arbiter that is part of the 
> DMA core, not affecting the CPU. CPU and DMA uses a *round-robin* 
> access, which means that if both requires access to the same bus, they 
> will share it in alternated cycles.
>
> In general it means that, if your CPU is not busy with other duties, it 
> is better to use the CPU for block transfers, instead of DMA data and 
> put CPU in a *wait for end of transfer* loop.


## Template Definition of `AnyChannel<>`

This template class is defined like the following code snippet:

```cpp
/// Template class that describes a DMA configuration
template <
	typename kDmaID						// The DMA::AnyID<> resource identification
	, const Dir kDir					// Data direction for this channel
	, const PtrPolicy kSrcPtr			// Source Pointer behavior
	, const PtrPolicy kDstPtr			// Target Pointer behavior
	, const Prio kPrio = Prio::kMedium	// DMA transfer priority
	, const bool doInitNvic = false		// Should be the NVIC also initialized?
>
class AnyChannel
{
	// ...
}
```

The template parameters are the following:
- **`kDmaID`**: The identification of the DMA channel, the **`AnyID<>`** 
template, presented on the start of this document. 
- **`kSrcPtr`**: The policy used to operate the source pointer. With this 
parameter you can configure the data size of the pointer and if it will 
auto-increment on every transfer.
- **`kDstPtr`**: The policy used to operate the destination pointer. With 
this parameter you can configure the data size of the pointer and if it 
will auto-increment on every transfer. 
- **`kPrio`**: This argument specifies the priority used for the DMA 
channel in case the arbiter has to prioritize two or more DMA channels 
accessing the same bus at the same time.
- **`doInitNvic`**: This flag indicates if the NVIC (*Nested Vector 
Interrupt Controller*) has to be initialized by the **`Init()`** method. 
This is required only if using interrupts and the NVIC is still not 
initialized elsewhere. 


## Members of `AnyChannel<>`

These are the provided members of the **`AnyChannel<>`** template class: 
- **`DmaID_`**: same as the **`kDmaID`** template argument.
- **`kDma_`**: an `Itf` enumeration value, corresponding to the DMA 
device. 
- **`kChan_`**: a `Chan` enumeration value, corresponding to the DMA 
channel of the specified device. 
- **`GetDeviceRoot()`**: this is the base address of the hardware 
register file for the specified DMA device. 
- **`GetDevice()`**: this is the base address of the hardware register 
file for the specified DMA channel. 
- **`Init()`**: Use this method for the first-time initialization of the 
DMA device. Note that only a single call to this function is expected. 
When you use more than one channel of the same DMA device, use the 
**`Setup()`** method to initialize all other channels.
- **`Stop()`**: This method stops the DMA device completely, detaching 
it from the Cortex bus. It has the inverse effect of `Init()`. 
- **`Setup()`**: This method configures the DMA channel according to the 
given template parameters. The DMA channel is still disabled, allowing to 
be configured with pointer addresses. 
- **`Enable()`**: This method enables the DMA channel. Please make sure 
that source and destination pointers and transfer size were provided 
before enabling a DMA channel. 
- **`Disable()`**: Disables the DMA channel. 
- **`SetTransferCount()`**: Sets the number of transfers that will occur. 
- **`GetTransferCount()`**: Returns current transfer count. 
- **`SetSourceAddress()`**: Sets the source pointer address. 
- **`SetDestAddress()`**: Sets the destination pointer address. 
- **`Start()`**: Starts a transfer. In this variation, all parameters can 
be set at once. It combines **`SetTransferCount()`**, 
**`SetSourceAddress()`**, **`SetDestAddress()`** and **`Enable()`** in a 
single call. 
- **`EnableTransferErrorInt()`**: Enables transfer error interrupt. Note 
that the NVIC also has to be enabled for the interrupt to be handled. A 
handler for the Interrupt is also required, which has to follow a system 
reserved name, so the linker knows how to bind it.
- **`DisableTransferErrorInt()`**: Disables transfer error interrupt. 
- **`IsTransferError()`**: Checks if transfer error interrupt flag is 
signaled. 
- **`ClearTransferErrorFlag()`**: Clears the transfer error interrupt 
flag. 
- **`EnableHalfTransferInt()`**: Enables the half transfer interrupt. 
Note that the NVIC also has to be enabled for the interrupt to be 
handled. A handler for the Interrupt is also required, which has to 
follow a system reserved name, so the linker knows how to bind it.
- **`DisableHalfTransferInt()`**: Disables the half transfer interrupt. 
- **`IsHalfTransfer()`**: Checks if the half transfer interrupt flag is 
signaled.
- **`ClearHalfTransferFlag()`**: Clears the half transfer interrupt flag. 
- **`EnableTransferCompleteInt()`**: Enables the transfer complete 
interrupt. Note that the NVIC also has to be enabled for the interrupt to 
be handled. A handler for the Interrupt is also required, which has to 
follow a system reserved name, so the linker knows how to bind it.
- **`DisableTransferCompleteInt()`**: Disables the transfer complete 
interrupt.
- **`IsTransferComplete()`**: Checks if the transfer complete interrupt 
flag was signaled. 
- **`ClearTransferCompleteFlag()`**: Clears the transfer complete 
interrupt flag. 
- **`DisableAllInterrupts()`**: Disables all interrupts flags. 
- **`IsGlobalInterrupt()`**: Checks if global interrupt flag is signaled. 
- **`ClearGlobalInterruptFlag()`**: Clears the global interrupt flag. 
- **`ClearAllFlags()`**: Clears all interrupt flags for that channel. 
- **`WaitTransferComplete()`**: Waits until the transfer is complete, 
polling the `IsTransferComplete()` method. All flags are cleared at the 
end. 


### Notes About Writing Interrupt Handlers

First, each MCU has different interrupt mappings, which varies according 
to the number of embedded peripherals.

The best reference is the startup file. There you will find the 
definition of the interrupt vector and a set of *weak* interrupt 
handlers. 

These *weak* interrupt handlers will be linked only if you do not 
provide a replacement. 

These are the real definitions that controls the linker, so it knows how 
to bind everything. This is why this is the best source for that 
information. 

For example, inspecting the **`startup_stm32f103xb.s`** file, which is 
the startup file for all STM32F103xB parts you will find on the interrupt 
vector definition (called `g_pfnVectors`) the ISR entries for the DMA1:

```asm
  .section .isr_vector,"a",%progbits
  .type g_pfnVectors, %object
  .size g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
  ...
  .word DMA1_Channel1_IRQHandler
  .word DMA1_Channel2_IRQHandler
  .word DMA1_Channel3_IRQHandler
  .word DMA1_Channel4_IRQHandler
  .word DMA1_Channel5_IRQHandler
  .word DMA1_Channel6_IRQHandler
  .word DMA1_Channel7_IRQHandler
  ...
```

So if you want to handle interrupts for the Channel 1 of the DMA1 module, 
you would define a function, anywhere in your source code like this:

```cpp
extern "C" void __attribute__((interrupt)) DMA1_Channel1_IRQHandler()
{
}
```


## A Simple Example

The code snipped below shows how to setup a DMA channel, using the 
hardware provided trigger routing (depends on chip and peripheral), to 
perform a DMA transfer:

```cpp
// This DMA is triggered on every timer update
typedef Dma::AnyChannel<
	Dma::IdTim2Up					// Timer 2 update triggers the DMA
	, Dma::Dir::kMemToPer			// runs samples in a single shot then stop
	, Dma::PtrPolicy::kBytePtrInc	// source buffer are bytes
	, Dma::PtrPolicy::kLongPtr		// destination CCR register
> MyDma;

extern "C" void SystemInit()
{
	// Reset clock system before starting program
	System::Init();
	
	// Initialize TIM2 and other peripherals
	//...

	// Initialize the DMA
	MyDma::Init();
}

void MyDmaExample(const uint8_t *my_data, uint16_t count)
{
	//...

	// Initialize DMA to transfer values to CCR0 of PWM Output
	MyDma::Setup();
	// In this example PwmOut is an hypothetical data-type for another 
	// timer configured in PWM mode. Writing bytes to the CCR address of 
	// it, will setup new PWM ratio, according to current byte. The 
	// update period of the TIM2 governs the sample rate.
	MyDma::Start(my_data, PwmOut::GetCcrAddress(), count);

	//...
}
```

