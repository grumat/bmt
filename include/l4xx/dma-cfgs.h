#pragma once

namespace Bmt
{
namespace Dma
{

using IdNone = AnyID<Itf::k1, Chan::kNone, PerifSel::k0>;
#ifdef ADC1_BASE
/// A template class to map ADC1 to DMA channel
using IdAdc1 = AnyID<Itf::k1, Chan::k1, PerifSel::k0>;
/// A template class to map ADC1 to DMA channel (alternate)
using IdAdc1_2 = AnyID<Itf::k2, Chan::k3, PerifSel::k0>;
#endif	// ADC1_BASE

#ifdef ADC2_BASE
/// A template class to map ADC2 to DMA channel
using IdAdc2 = AnyID<Itf::k1, Chan::k2, PerifSel::k0>;
/// A template class to map ADC2 to DMA channel (alternate)
using IdAdc2_2 = AnyID<Itf::k2, Chan::k4, PerifSel::k0>;
#endif	// ADC2_BASE

#ifdef ADC3_BASE
/// A template class to map ADC3 to DMA channel
using IdAdc3 = AnyID<Itf::k1, Chan::k3, PerifSel::k0>;
/// A template class to map ADC3 to DMA channel (alternate)
using IdAdc3_2 = AnyID<Itf::k2, Chan::k5, PerifSel::k0>;
#endif	// ADC3_BASE

#ifdef AES_BASE
/// A template class to map AES IN to DMA channel
using IdAesIn = AnyID<Itf::k2, Chan::k1, PerifSel::k6>;
/// A template class to map AES IN to DMA channel (alternate)
using IdAesIn_2 = AnyID<Itf::k2, Chan::k5, PerifSel::k6>;
/// A template class to map AES OUT to DMA channel
using IdAesOut = AnyID<Itf::k2, Chan::k2, PerifSel::k6>;
/// A template class to map AES OUT to DMA channel (alternate)
using IdAesOut_2 = AnyID<Itf::k2, Chan::k3, PerifSel::k6>;
#endif	// AES_BASE

#ifdef DAC_BASE
/// A template class to map DAC CH1 to DMA channel
using IdDacCh1 = AnyID<Itf::k1, Chan::k3, PerifSel::k6>;
/// A template class to map DAC CH1 to DMA channel (alternate)
using IdDacCh1_2 = AnyID<Itf::k2, Chan::k4, PerifSel::k3>;
/// A template class to map DAC CH2 to DMA channel
using IdDacCh2 = AnyID<Itf::k1, Chan::k4, PerifSel::k5>;
/// A template class to map DAC CH2 to DMA channel (alternate)
using IdDacCh2_2 = AnyID<Itf::k2, Chan::k5, PerifSel::k3>;
#endif	// DAC_BASE

#ifdef DCMI_BASE
/// A template class to map DCMI to DMA channel
using IdDcmi = AnyID<Itf::k2, Chan::k6, PerifSel::k0>;
/// A template class to map DCMI to DMA channel (alternate)
using IdDcmi_2 = AnyID<Itf::k2, Chan::k5, PerifSel::k4>;
#endif	// DCMI_BASE

#ifdef DFSDM1_BASE
/// A template class to map DFSDM1 FLT0 to DMA channel
using IdDfsdm1Flt0 = AnyID<Itf::k1, Chan::k4, PerifSel::k0>;
/// A template class to map DFSDM1 FLT1 to DMA channel
using IdDfsdm1Flt1 = AnyID<Itf::k1, Chan::k5, PerifSel::k0>;
/// A template class to map DFSDM1 FLT2 to DMA channel
using IdDfsdm1Flt2 = AnyID<Itf::k1, Chan::k6, PerifSel::k0>;
/// A template class to map DFSDM1 FLT3 to DMA channel
using IdDfsdm1Flt3 = AnyID<Itf::k1, Chan::k7, PerifSel::k0>;
#endif	// DFSDM1_BASE

#ifdef HASH_BASE
/// A template class to map HASH IN to DMA channel
using IdHashIn = AnyID<Itf::k2, Chan::k7, PerifSel::k6>;
#endif	// HASH_BASE

#ifdef I2C1_BASE
/// A template class to map I2C1 RX to DMA channel
using IdI2c1Rx = AnyID<Itf::k1, Chan::k7, PerifSel::k3>;
/// A template class to map I2C1 RX to DMA channel (alternate)
using IdI2c1Rx_2 = AnyID<Itf::k2, Chan::k6, PerifSel::k5>;
/// A template class to map I2C1 TX to DMA channel
using IdI2c1Tx = AnyID<Itf::k1, Chan::k6, PerifSel::k3>;
/// A template class to map I2C1 TX to DMA channel (alternate)
using IdI2c1Tx_2 = AnyID<Itf::k2, Chan::k7, PerifSel::k5>;
#endif	// I2C1_BASE

#ifdef I2C2_BASE
/// A template class to map I2C2 RX to DMA channel
using IdI2c2Rx = AnyID<Itf::k1, Chan::k5, PerifSel::k3>;
/// A template class to map I2C2 TX to DMA channel
using IdI2c2Tx = AnyID<Itf::k1, Chan::k4, PerifSel::k3>;
#endif	// I2C2_BASE

#ifdef I2C3_BASE
/// A template class to map I2C3 RX to DMA channel
using IdI2c3Rx = AnyID<Itf::k1, Chan::k3, PerifSel::k3>;
/// A template class to map I2C3 TX to DMA channel
using IdI2c3Tx = AnyID<Itf::k1, Chan::k2, PerifSel::k3>;
#endif	// I2C3_BASE

#ifdef I2C4_BASE
/// A template class to map I2C4 RX to DMA channel
using IdI2c4Rx = AnyID<Itf::k2, Chan::k1, PerifSel::k0>;
/// A template class to map I2C4 TX to DMA channel
using IdI2c4Tx = AnyID<Itf::k2, Chan::k2, PerifSel::k0>;
#endif	// I2C4_BASE

#ifdef LPUART1_BASE
/// A template class to map LPUART1 RX to DMA channel
using IdLpuart1Rx = AnyID<Itf::k2, Chan::k7, PerifSel::k4>;
/// A template class to map LPUART1 TX to DMA channel
using IdLpuart1Tx = AnyID<Itf::k2, Chan::k6, PerifSel::k4>;
#endif	// LPUART1_BASE

#ifdef QUADSPI_BASE
/// A template class to map QUADSPI to DMA channel
using IdQuadspi = AnyID<Itf::k1, Chan::k5, PerifSel::k5>;
/// A template class to map QUADSPI to DMA channel (alternate)
using IdQuadspi_2 = AnyID<Itf::k2, Chan::k7, PerifSel::k3>;
#endif	// QUADSPI_BASE

#ifdef SAI1_BASE
/// A template class to map SAI1 A to DMA channel
using IdSai1A = AnyID<Itf::k2, Chan::k1, PerifSel::k1>;
/// A template class to map SAI1 A to DMA channel (alternate)
using IdSai1A_2 = AnyID<Itf::k2, Chan::k6, PerifSel::k1>;
/// A template class to map SAI1 B to DMA channel
using IdSai1B = AnyID<Itf::k2, Chan::k2, PerifSel::k1>;
/// A template class to map SAI1 B to DMA channel (alternate)
using IdSai1B_2 = AnyID<Itf::k2, Chan::k7, PerifSel::k1>;
#endif	// SAI1_BASE

#ifdef SAI2_BASE
/// A template class to map SAI2 A to DMA channel
using IdSai2A = AnyID<Itf::k1, Chan::k6, PerifSel::k1>;
/// A template class to map SAI2 A to DMA channel (alternate)
using IdSai2A_2 = AnyID<Itf::k2, Chan::k3, PerifSel::k1>;
/// A template class to map SAI2 B to DMA channel
using IdSai2B = AnyID<Itf::k1, Chan::k7, PerifSel::k1>;
/// A template class to map SAI2 B to DMA channel (alternate)
using IdSai2B_2 = AnyID<Itf::k2, Chan::k4, PerifSel::k1>;
#endif	// SAI2_BASE

#ifdef SDMMC1_BASE
/// A template class to map SDMMC1 to DMA channel
using IdSdmmc1 = AnyID<Itf::k2, Chan::k4, PerifSel::k7>;
/// A template class to map SDMMC1 to DMA channel (alternate)
using IdSdmmc1_2 = AnyID<Itf::k2, Chan::k5, PerifSel::k7>;
#endif	// SDMMC1_BASE

#ifdef SPI1_BASE
/// A template class to map SPI1 RX to DMA channel
using IdSpi1Rx = AnyID<Itf::k1, Chan::k2, PerifSel::k1>;
/// A template class to map SPI1 RX to DMA channel (alternate)
using IdSpi1Rx_2 = AnyID<Itf::k2, Chan::k3, PerifSel::k4>;
/// A template class to map SPI1 TX to DMA channel
using IdSpi1Tx = AnyID<Itf::k1, Chan::k3, PerifSel::k1>;
/// A template class to map SPI1 TX to DMA channel (alternate)
using IdSpi1Tx_2 = AnyID<Itf::k2, Chan::k4, PerifSel::k4>;
#endif	// SPI1_BASE

#ifdef SPI2_BASE
/// A template class to map SPI2 RX to DMA channel
using IdSpi2Rx = AnyID<Itf::k1, Chan::k4, PerifSel::k1>;
/// A template class to map SPI2 TX to DMA channel
using IdSpi2Tx = AnyID<Itf::k1, Chan::k5, PerifSel::k1>;
#endif	// SPI2_BASE

#ifdef SPI3_BASE
/// A template class to map SPI3 RX to DMA channel
using IdSpi3Rx = AnyID<Itf::k2, Chan::k1, PerifSel::k3>;
/// A template class to map SPI3 TX to DMA channel
using IdSpi3Tx = AnyID<Itf::k2, Chan::k2, PerifSel::k3>;
#endif	// SPI3_BASE

#ifdef SWPMI1_BASE
/// A template class to map SWPMI1 RX to DMA channel
using IdSwpmi1Rx = AnyID<Itf::k2, Chan::k1, PerifSel::k4>;
/// A template class to map SWPMI1 TX to DMA channel
using IdSwpmi1Tx = AnyID<Itf::k2, Chan::k2, PerifSel::k4>;
#endif	// SWPMI1_BASE

#ifdef TIM1_BASE
/// A template class to map TIM1 CH1 to DMA channel
using IdTim1Ch1 = AnyID<Itf::k1, Chan::k2, PerifSel::k7>;
/// A template class to map TIM1 CH2 to DMA channel
using IdTim1Ch2 = AnyID<Itf::k1, Chan::k3, PerifSel::k7>;
/// A template class to map TIM1 CH3 to DMA channel
using IdTim1Ch3 = AnyID<Itf::k1, Chan::k7, PerifSel::k7>;
/// A template class to map TIM1 CH4 to DMA channel
using IdTim1Ch4 = AnyID<Itf::k1, Chan::k4, PerifSel::k7>;
/// A template class to map TIM1 COM to DMA channel
using IdTim1Com = AnyID<Itf::k1, Chan::k4, PerifSel::k7>;
/// A template class to map TIM1 TRIG to DMA channel
using IdTim1Trig = AnyID<Itf::k1, Chan::k4, PerifSel::k7>;
/// A template class to map TIM1 UP to DMA channel
using IdTim1Up = AnyID<Itf::k1, Chan::k6, PerifSel::k7>;
#endif	// TIM1_BASE

#ifdef TIM2_BASE
/// A template class to map TIM2 CH1 to DMA channel
using IdTim2Ch1 = AnyID<Itf::k1, Chan::k5, PerifSel::k4>;
/// A template class to map TIM2 CH2 to DMA channel
using IdTim2Ch2 = AnyID<Itf::k1, Chan::k7, PerifSel::k4>;
/// A template class to map TIM2 CH3 to DMA channel
using IdTim2Ch3 = AnyID<Itf::k1, Chan::k1, PerifSel::k4>;
/// A template class to map TIM2 CH4 to DMA channel
using IdTim2Ch4 = AnyID<Itf::k1, Chan::k7, PerifSel::k4>;
/// A template class to map TIM2 UP to DMA channel
using IdTim2Up = AnyID<Itf::k1, Chan::k2, PerifSel::k4>;
#endif	// TIM2_BASE

#ifdef TIM3_BASE
/// A template class to map TIM3 CH1 to DMA channel
using IdTim3Ch1 = AnyID<Itf::k1, Chan::k6, PerifSel::k5>;
/// A template class to map TIM3 CH3 to DMA channel
using IdTim3Ch3 = AnyID<Itf::k1, Chan::k2, PerifSel::k5>;
/// A template class to map TIM3 CH4 to DMA channel
using IdTim3Ch4 = AnyID<Itf::k1, Chan::k3, PerifSel::k5>;
/// A template class to map TIM3 TRIG to DMA channel
using IdTim3Trig = AnyID<Itf::k1, Chan::k6, PerifSel::k5>;
/// A template class to map TIM3 UP to DMA channel
using IdTim3Up = AnyID<Itf::k1, Chan::k3, PerifSel::k5>;
#endif	// TIM3_BASE

#ifdef TIM4_BASE
/// A template class to map TIM4 CH1 to DMA channel
using IdTim4Ch1 = AnyID<Itf::k1, Chan::k1, PerifSel::k6>;
/// A template class to map TIM4 CH2 to DMA channel
using IdTim4Ch2 = AnyID<Itf::k1, Chan::k4, PerifSel::k6>;
/// A template class to map TIM4 CH3 to DMA channel
using IdTim4Ch3 = AnyID<Itf::k1, Chan::k5, PerifSel::k6>;
/// A template class to map TIM4 UP to DMA channel
using IdTim4Up = AnyID<Itf::k1, Chan::k7, PerifSel::k6>;
#endif	// TIM4_BASE

#ifdef TIM5_BASE
/// A template class to map TIM5 CH1 to DMA channel
using IdTim5Ch1 = AnyID<Itf::k2, Chan::k5, PerifSel::k5>;
/// A template class to map TIM5 CH2 to DMA channel
using IdTim5Ch2 = AnyID<Itf::k2, Chan::k4, PerifSel::k5>;
/// A template class to map TIM5 CH3 to DMA channel
using IdTim5Ch3 = AnyID<Itf::k2, Chan::k2, PerifSel::k5>;
/// A template class to map TIM5 CH4 to DMA channel
using IdTim5Ch4 = AnyID<Itf::k2, Chan::k1, PerifSel::k5>;
/// A template class to map TIM5 TRIG to DMA channel
using IdTim5Trig = AnyID<Itf::k2, Chan::k1, PerifSel::k5>;
/// A template class to map TIM5 UP to DMA channel
using IdTim5Up = AnyID<Itf::k2, Chan::k2, PerifSel::k5>;
#endif	// TIM5_BASE

#ifdef TIM6_BASE
/// A template class to map TIM6 UP to DMA channel
using IdTim6Up = AnyID<Itf::k1, Chan::k3, PerifSel::k6>;
/// A template class to map TIM6 UP to DMA channel (alternate)
using IdTim6Up_2 = AnyID<Itf::k2, Chan::k4, PerifSel::k3>;
#endif	// TIM6_BASE

#ifdef TIM7_BASE
/// A template class to map TIM7 UP to DMA channel
using IdTim7Up = AnyID<Itf::k1, Chan::k4, PerifSel::k5>;
/// A template class to map TIM7 UP to DMA channel (alternate)
using IdTim7Up_2 = AnyID<Itf::k2, Chan::k5, PerifSel::k3>;
#endif	// TIM7_BASE

#ifdef TIM8_BASE
/// A template class to map TIM8 CH1 to DMA channel
using IdTim8Ch1 = AnyID<Itf::k2, Chan::k6, PerifSel::k7>;
/// A template class to map TIM8 CH2 to DMA channel
using IdTim8Ch2 = AnyID<Itf::k2, Chan::k7, PerifSel::k7>;
/// A template class to map TIM8 CH3 to DMA channel
using IdTim8Ch3 = AnyID<Itf::k2, Chan::k1, PerifSel::k7>;
/// A template class to map TIM8 CH4 to DMA channel
using IdTim8Ch4 = AnyID<Itf::k2, Chan::k2, PerifSel::k7>;
/// A template class to map TIM8 COM to DMA channel
using IdTim8Com = AnyID<Itf::k2, Chan::k2, PerifSel::k7>;
/// A template class to map TIM8 TRIG to DMA channel
using IdTim8Trig = AnyID<Itf::k2, Chan::k2, PerifSel::k7>;
/// A template class to map TIM8 UP to DMA channel
using IdTim8Up = AnyID<Itf::k2, Chan::k1, PerifSel::k7>;
#endif	// TIM8_BASE

#ifdef TIM15_BASE
/// A template class to map TIM15 CH1 to DMA channel
using IdTim15Ch1 = AnyID<Itf::k1, Chan::k5, PerifSel::k7>;
/// A template class to map TIM15 COM to DMA channel
using IdTim15Com = AnyID<Itf::k1, Chan::k5, PerifSel::k7>;
/// A template class to map TIM15 TRIG to DMA channel
using IdTim15Trig = AnyID<Itf::k1, Chan::k5, PerifSel::k7>;
/// A template class to map TIM15 UP to DMA channel
using IdTim15Up = AnyID<Itf::k1, Chan::k5, PerifSel::k7>;
#endif	// TIM15_BASE

#ifdef TIM16_BASE
/// A template class to map TIM16 CH1 to DMA channel
using IdTim16Ch1 = AnyID<Itf::k1, Chan::k3, PerifSel::k4>;
/// A template class to map TIM16 CH1 to DMA channel (alternate)
using IdTim16Ch1_2 = AnyID<Itf::k1, Chan::k6, PerifSel::k4>;
/// A template class to map TIM16 UP to DMA channel
using IdTim16Up = AnyID<Itf::k1, Chan::k3, PerifSel::k4>;
/// A template class to map TIM16 UP to DMA channel (alternate)
using IdTim16Up_2 = AnyID<Itf::k1, Chan::k6, PerifSel::k4>;
#endif	// TIM16_BASE

#ifdef TIM17_BASE
/// A template class to map TIM17 CH1 to DMA channel
using IdTim17Ch1 = AnyID<Itf::k1, Chan::k1, PerifSel::k5>;
/// A template class to map TIM17 CH1 to DMA channel (alternate)
using IdTim17Ch1_2 = AnyID<Itf::k1, Chan::k7, PerifSel::k5>;
/// A template class to map TIM17 UP to DMA channel
using IdTim17Up = AnyID<Itf::k1, Chan::k1, PerifSel::k5>;
/// A template class to map TIM17 UP to DMA channel (alternate)
using IdTim17Up_2 = AnyID<Itf::k1, Chan::k7, PerifSel::k5>;
#endif	// TIM17_BASE

#ifdef UART4_BASE
/// A template class to map UART4 RX to DMA channel
using IdUart4Rx = AnyID<Itf::k2, Chan::k5, PerifSel::k2>;
/// A template class to map UART4 TX to DMA channel
using IdUart4Tx = AnyID<Itf::k2, Chan::k3, PerifSel::k2>;
#endif	// UART4_BASE

#ifdef UART5_BASE
/// A template class to map UART5 RX to DMA channel
using IdUart5Rx = AnyID<Itf::k2, Chan::k2, PerifSel::k2>;
/// A template class to map UART5 TX to DMA channel
using IdUart5Tx = AnyID<Itf::k2, Chan::k1, PerifSel::k2>;
#endif	// UART5_BASE

#ifdef USART1_BASE
/// A template class to map USART1 RX to DMA channel
using IdUsart1Rx = AnyID<Itf::k1, Chan::k5, PerifSel::k2>;
/// A template class to map USART1 RX to DMA channel (alternate)
using IdUsart1Rx_2 = AnyID<Itf::k2, Chan::k7, PerifSel::k2>;
/// A template class to map USART1 TX to DMA channel
using IdUsart1Tx = AnyID<Itf::k1, Chan::k4, PerifSel::k2>;
/// A template class to map USART1 TX to DMA channel (alternate)
using IdUsart1Tx_2 = AnyID<Itf::k2, Chan::k6, PerifSel::k2>;
#endif	// USART1_BASE

#ifdef USART2_BASE
/// A template class to map USART2 RX to DMA channel
using IdUsart2Rx = AnyID<Itf::k1, Chan::k6, PerifSel::k2>;
/// A template class to map USART2 TX to DMA channel
using IdUsart2Tx = AnyID<Itf::k1, Chan::k7, PerifSel::k2>;
#endif	// USART2_BASE

#ifdef USART3_BASE
/// A template class to map USART3 RX to DMA channel
using IdUsart3Rx = AnyID<Itf::k1, Chan::k3, PerifSel::k2>;
/// A template class to map USART3 TX to DMA channel
using IdUsart3Tx = AnyID<Itf::k1, Chan::k2, PerifSel::k2>;
#endif	// USART3_BASE


#ifdef ADC1_BASE
/// A template class to configure ADC1 with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyAdc1 : public AnyChannel <
	IdAdc1
	, kDir
	, PtrPolicy::kShortPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure ADC1 with DMA transfer (alternate)
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyAdc1_2 : public AnyChannel <
	IdAdc1_2
	, kDir
	, PtrPolicy::kShortPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// ADC1_BASE

#ifdef ADC2_BASE
/// A template class to configure ADC2 with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyAdc2 : public AnyChannel <
	IdAdc2
	, kDir
	, PtrPolicy::kShortPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure ADC2 with DMA transfer (alternate)
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyAdc2_2 : public AnyChannel <
	IdAdc2_2
	, kDir
	, PtrPolicy::kShortPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// ADC2_BASE

#ifdef ADC3_BASE
/// A template class to configure ADC3 with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyAdc3 : public AnyChannel <
	IdAdc3
	, kDir
	, PtrPolicy::kShortPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure ADC3 with DMA transfer (alternate)
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyAdc3_2 : public AnyChannel <
	IdAdc3_2
	, kDir
	, PtrPolicy::kShortPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// ADC3_BASE

#ifdef AES_BASE
/// A template class to configure AES IN with DMA transfer
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kLongPtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kLongPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyAesIn : public AnyChannel <
	IdAesIn
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure AES IN with DMA transfer (alternate)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kLongPtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kLongPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyAesIn_2 : public AnyChannel <
	IdAesIn_2
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure AES OUT with DMA transfer
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kLongPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kLongPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyAesOut : public AnyChannel <
	IdAesOut
	, kCircular ? Dir::kMemToPerCircular : Dir::kMemToPer
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure AES OUT with DMA transfer (alternate)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kLongPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kLongPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyAesOut_2 : public AnyChannel <
	IdAesOut_2
	, kCircular ? Dir::kMemToPerCircular : Dir::kMemToPer
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// AES_BASE

#ifdef DAC_BASE
/// A template class to configure DAC CH1 with DMA transfer
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDacCh1 : public AnyChannel <
	IdDacCh1
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure DAC CH1 with DMA transfer (alternate)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDacCh1_2 : public AnyChannel <
	IdDacCh1_2
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure DAC CH2 with DMA transfer
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDacCh2 : public AnyChannel <
	IdDacCh2
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure DAC CH2 with DMA transfer (alternate)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDacCh2_2 : public AnyChannel <
	IdDacCh2_2
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// DAC_BASE

#ifdef DCMI_BASE
/// A template class to configure DCMI with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyDcmi : public AnyChannel <
	IdDcmi
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure DCMI with DMA transfer (alternate)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyDcmi_2 : public AnyChannel <
	IdDcmi_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// DCMI_BASE

#ifdef DFSDM1_BASE
/// A template class to configure DFSDM1 FLT0 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyDfsdm1Flt0 : public AnyChannel <
	IdDfsdm1Flt0
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure DFSDM1 FLT1 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyDfsdm1Flt1 : public AnyChannel <
	IdDfsdm1Flt1
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure DFSDM1 FLT2 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyDfsdm1Flt2 : public AnyChannel <
	IdDfsdm1Flt2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure DFSDM1 FLT3 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyDfsdm1Flt3 : public AnyChannel <
	IdDfsdm1Flt3
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// DFSDM1_BASE

#ifdef HASH_BASE
/// A template class to configure HASH IN with DMA transfer
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kLongPtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kLongPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyHashIn : public AnyChannel <
	IdHashIn
	, kCircular ? Dir::kMemToPerCircular : Dir::kMemToPer
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// HASH_BASE

#ifdef I2C1_BASE
/// A template class to configure I2C1 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyI2c1Rx : public AnyChannel <
	IdI2c1Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure I2C1 RX with DMA transfer (alternate)
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyI2c1Rx_2 : public AnyChannel <
	IdI2c1Rx_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure I2C1 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnyI2c1Tx : public AnyChannel <
	IdI2c1Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure I2C1 TX with DMA transfer (alternate)
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnyI2c1Tx_2 : public AnyChannel <
	IdI2c1Tx_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// I2C1_BASE

#ifdef I2C2_BASE
/// A template class to configure I2C2 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyI2c2Rx : public AnyChannel <
	IdI2c2Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure I2C2 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnyI2c2Tx : public AnyChannel <
	IdI2c2Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// I2C2_BASE

#ifdef I2C3_BASE
/// A template class to configure I2C3 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyI2c3Rx : public AnyChannel <
	IdI2c3Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure I2C3 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnyI2c3Tx : public AnyChannel <
	IdI2c3Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// I2C3_BASE

#ifdef I2C4_BASE
/// A template class to configure I2C4 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyI2c4Rx : public AnyChannel <
	IdI2c4Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure I2C4 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnyI2c4Tx : public AnyChannel <
	IdI2c4Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// I2C4_BASE

#ifdef LPUART1_BASE
/// A template class to configure LPUART1 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyLpuart1Rx : public AnyChannel <
	IdLpuart1Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure LPUART1 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnyLpuart1Tx : public AnyChannel <
	IdLpuart1Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// LPUART1_BASE

#ifdef QUADSPI_BASE
/// A template class to configure QUADSPI with DMA transfer
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyQuadspi : public AnyChannel <
	IdQuadspi
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure QUADSPI with DMA transfer (alternate)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyQuadspi_2 : public AnyChannel <
	IdQuadspi_2
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// QUADSPI_BASE

#ifdef SAI1_BASE
/// A template class to configure SAI1 A with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySai1A : public AnyChannel <
	IdSai1A
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SAI1 A with DMA transfer (alternate)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySai1A_2 : public AnyChannel <
	IdSai1A_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SAI1 B with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySai1B : public AnyChannel <
	IdSai1B
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SAI1 B with DMA transfer (alternate)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySai1B_2 : public AnyChannel <
	IdSai1B_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// SAI1_BASE

#ifdef SAI2_BASE
/// A template class to configure SAI2 A with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySai2A : public AnyChannel <
	IdSai2A
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SAI2 A with DMA transfer (alternate)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySai2A_2 : public AnyChannel <
	IdSai2A_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SAI2 B with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySai2B : public AnyChannel <
	IdSai2B
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SAI2 B with DMA transfer (alternate)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySai2B_2 : public AnyChannel <
	IdSai2B_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// SAI2_BASE

#ifdef SDMMC1_BASE
/// A template class to configure SDMMC1 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySdmmc1 : public AnyChannel <
	IdSdmmc1
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SDMMC1 with DMA transfer (alternate)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySdmmc1_2 : public AnyChannel <
	IdSdmmc1_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// SDMMC1_BASE

#ifdef SPI1_BASE
/// A template class to configure SPI1 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnySpi1Rx : public AnyChannel <
	IdSpi1Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SPI1 RX with DMA transfer (alternate)
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnySpi1Rx_2 : public AnyChannel <
	IdSpi1Rx_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SPI1 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnySpi1Tx : public AnyChannel <
	IdSpi1Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SPI1 TX with DMA transfer (alternate)
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnySpi1Tx_2 : public AnyChannel <
	IdSpi1Tx_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// SPI1_BASE

#ifdef SPI2_BASE
/// A template class to configure SPI2 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnySpi2Rx : public AnyChannel <
	IdSpi2Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SPI2 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnySpi2Tx : public AnyChannel <
	IdSpi2Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// SPI2_BASE

#ifdef SPI3_BASE
/// A template class to configure SPI3 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnySpi3Rx : public AnyChannel <
	IdSpi3Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SPI3 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnySpi3Tx : public AnyChannel <
	IdSpi3Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// SPI3_BASE

#ifdef SWPMI1_BASE
/// A template class to configure SWPMI1 RX with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySwpmi1Rx : public AnyChannel <
	IdSwpmi1Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SWPMI1 TX with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySwpmi1Tx : public AnyChannel <
	IdSwpmi1Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// SWPMI1_BASE

#ifdef TIM1_BASE
/// A template class to configure TIM1 CH1 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Ch1 : public AnyChannel <
	IdTim1Ch1
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM1 CH2 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Ch2 : public AnyChannel <
	IdTim1Ch2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM1 CH3 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Ch3 : public AnyChannel <
	IdTim1Ch3
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM1 CH4 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Ch4 : public AnyChannel <
	IdTim1Ch4
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM1 COM with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Com : public AnyChannel <
	IdTim1Com
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM1 TRIG with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Trig : public AnyChannel <
	IdTim1Trig
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM1 UP with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim1Up : public AnyChannel <
	IdTim1Up
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// TIM1_BASE

#ifdef TIM2_BASE
/// A template class to configure TIM2 CH1 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim2Ch1 : public AnyChannel <
	IdTim2Ch1
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM2 CH2 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim2Ch2 : public AnyChannel <
	IdTim2Ch2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM2 CH3 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim2Ch3 : public AnyChannel <
	IdTim2Ch3
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM2 CH4 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim2Ch4 : public AnyChannel <
	IdTim2Ch4
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM2 UP with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim2Up : public AnyChannel <
	IdTim2Up
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// TIM2_BASE

#ifdef TIM3_BASE
/// A template class to configure TIM3 CH1 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim3Ch1 : public AnyChannel <
	IdTim3Ch1
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM3 CH3 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim3Ch3 : public AnyChannel <
	IdTim3Ch3
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM3 CH4 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim3Ch4 : public AnyChannel <
	IdTim3Ch4
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM3 TRIG with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim3Trig : public AnyChannel <
	IdTim3Trig
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM3 UP with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim3Up : public AnyChannel <
	IdTim3Up
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// TIM3_BASE

#ifdef TIM4_BASE
/// A template class to configure TIM4 CH1 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim4Ch1 : public AnyChannel <
	IdTim4Ch1
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM4 CH2 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim4Ch2 : public AnyChannel <
	IdTim4Ch2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM4 CH3 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim4Ch3 : public AnyChannel <
	IdTim4Ch3
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM4 UP with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim4Up : public AnyChannel <
	IdTim4Up
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// TIM4_BASE

#ifdef TIM5_BASE
/// A template class to configure TIM5 CH1 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim5Ch1 : public AnyChannel <
	IdTim5Ch1
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM5 CH2 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim5Ch2 : public AnyChannel <
	IdTim5Ch2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM5 CH3 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim5Ch3 : public AnyChannel <
	IdTim5Ch3
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM5 CH4 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim5Ch4 : public AnyChannel <
	IdTim5Ch4
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM5 TRIG with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim5Trig : public AnyChannel <
	IdTim5Trig
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM5 UP with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim5Up : public AnyChannel <
	IdTim5Up
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// TIM5_BASE

#ifdef TIM6_BASE
/// A template class to configure TIM6 UP with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim6Up : public AnyChannel <
	IdTim6Up
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM6 UP with DMA transfer (alternate)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim6Up_2 : public AnyChannel <
	IdTim6Up_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// TIM6_BASE

#ifdef TIM7_BASE
/// A template class to configure TIM7 UP with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim7Up : public AnyChannel <
	IdTim7Up
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM7 UP with DMA transfer (alternate)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim7Up_2 : public AnyChannel <
	IdTim7Up_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// TIM7_BASE

#ifdef TIM8_BASE
/// A template class to configure TIM8 CH1 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim8Ch1 : public AnyChannel <
	IdTim8Ch1
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM8 CH2 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim8Ch2 : public AnyChannel <
	IdTim8Ch2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM8 CH3 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim8Ch3 : public AnyChannel <
	IdTim8Ch3
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM8 CH4 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim8Ch4 : public AnyChannel <
	IdTim8Ch4
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM8 COM with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim8Com : public AnyChannel <
	IdTim8Com
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM8 TRIG with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim8Trig : public AnyChannel <
	IdTim8Trig
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM8 UP with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim8Up : public AnyChannel <
	IdTim8Up
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// TIM8_BASE

#ifdef TIM15_BASE
/// A template class to configure TIM15 CH1 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim15Ch1 : public AnyChannel <
	IdTim15Ch1
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM15 COM with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim15Com : public AnyChannel <
	IdTim15Com
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM15 TRIG with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim15Trig : public AnyChannel <
	IdTim15Trig
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM15 UP with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim15Up : public AnyChannel <
	IdTim15Up
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// TIM15_BASE

#ifdef TIM16_BASE
/// A template class to configure TIM16 CH1 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim16Ch1 : public AnyChannel <
	IdTim16Ch1
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM16 CH1 with DMA transfer (alternate)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim16Ch1_2 : public AnyChannel <
	IdTim16Ch1_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM16 UP with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim16Up : public AnyChannel <
	IdTim16Up
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM16 UP with DMA transfer (alternate)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim16Up_2 : public AnyChannel <
	IdTim16Up_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// TIM16_BASE

#ifdef TIM17_BASE
/// A template class to configure TIM17 CH1 with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim17Ch1 : public AnyChannel <
	IdTim17Ch1
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM17 CH1 with DMA transfer (alternate)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim17Ch1_2 : public AnyChannel <
	IdTim17Ch1_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM17 UP with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim17Up : public AnyChannel <
	IdTim17Up
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM17 UP with DMA transfer (alternate)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim17Up_2 : public AnyChannel <
	IdTim17Up_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// TIM17_BASE

#ifdef UART4_BASE
/// A template class to configure UART4 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUart4Rx : public AnyChannel <
	IdUart4Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure UART4 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUart4Tx : public AnyChannel <
	IdUart4Tx
	, kDir
	, kSrcPtr
	, PtrPolicy::kBytePtr
	, kPrio
>
{ };
#endif	// UART4_BASE

#ifdef UART5_BASE
/// A template class to configure UART5 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUart5Rx : public AnyChannel <
	IdUart5Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure UART5 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUart5Tx : public AnyChannel <
	IdUart5Tx
	, kDir
	, kSrcPtr
	, PtrPolicy::kBytePtr
	, kPrio
>
{ };
#endif	// UART5_BASE

#ifdef USART1_BASE
/// A template class to configure USART1 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart1Rx : public AnyChannel <
	IdUsart1Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure USART1 RX with DMA transfer (alternate)
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart1Rx_2 : public AnyChannel <
	IdUsart1Rx_2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure USART1 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart1Tx : public AnyChannel <
	IdUsart1Tx
	, kDir
	, kSrcPtr
	, PtrPolicy::kBytePtr
	, kPrio
>
{ };

/// A template class to configure USART1 TX with DMA transfer (alternate)
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart1Tx_2 : public AnyChannel <
	IdUsart1Tx_2
	, kDir
	, kSrcPtr
	, PtrPolicy::kBytePtr
	, kPrio
>
{ };
#endif	// USART1_BASE

#ifdef USART2_BASE
/// A template class to configure USART2 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart2Rx : public AnyChannel <
	IdUsart2Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure USART2 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart2Tx : public AnyChannel <
	IdUsart2Tx
	, kDir
	, kSrcPtr
	, PtrPolicy::kBytePtr
	, kPrio
>
{ };
#endif	// USART2_BASE

#ifdef USART3_BASE
/// A template class to configure USART3 RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart3Rx : public AnyChannel <
	IdUsart3Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure USART3 TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUsart3Tx : public AnyChannel <
	IdUsart3Tx
	, kDir
	, kSrcPtr
	, PtrPolicy::kBytePtr
	, kPrio
>
{ };
#endif	// USART3_BASE



}	// namespace Dma
}	// namespace Bmt
