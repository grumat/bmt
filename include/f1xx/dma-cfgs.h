#pragma once

namespace Bmt
{
namespace Dma
{

using IdNone = AnyID<Itf::k1, Chan::kNone>;
#ifdef ADC1_BASE
/// A template class to map ADC1 to DMA channel
using IdAdc1 = AnyID<Itf::k1, Chan::k1>;
#endif	// ADC1_BASE

#ifdef ADC3_BASE
/// A template class to map ADC3 to DMA channel
using IdAdc3 = AnyID<Itf::k2, Chan::k5>;
#endif	// ADC3_BASE

#ifdef DAC_BASE
/// A template class to map DAC Channel1 to DMA channel
using IdDacChannel1 = AnyID<Itf::k2, Chan::k3>;
/// A template class to map DAC Channel2 to DMA channel
using IdDacChannel2 = AnyID<Itf::k2, Chan::k4>;
#endif	// DAC_BASE

#ifdef I2C1_BASE
/// A template class to map I2C1 RX to DMA channel
using IdI2c1Rx = AnyID<Itf::k1, Chan::k7>;
/// A template class to map I2C1 TX to DMA channel
using IdI2c1Tx = AnyID<Itf::k1, Chan::k6>;
#endif	// I2C1_BASE

#ifdef I2C2_BASE
/// A template class to map I2C2 RX to DMA channel
using IdI2c2Rx = AnyID<Itf::k1, Chan::k5>;
/// A template class to map I2C2 TX to DMA channel
using IdI2c2Tx = AnyID<Itf::k1, Chan::k4>;
#endif	// I2C2_BASE

#ifdef I2S2_BASE
/// A template class to map I2S2 RX to DMA channel
using IdI2s2Rx = AnyID<Itf::k1, Chan::k4>;
/// A template class to map I2S2 TX to DMA channel
using IdI2s2Tx = AnyID<Itf::k1, Chan::k5>;
#endif	// I2S2_BASE

#ifdef I2S3_BASE
/// A template class to map I2S3 RX to DMA channel
using IdI2s3Rx = AnyID<Itf::k2, Chan::k1>;
/// A template class to map I2S3 TX to DMA channel
using IdI2s3Tx = AnyID<Itf::k2, Chan::k2>;
#endif	// I2S3_BASE

#ifdef SDIO_BASE
/// A template class to map SDIO to DMA channel
using IdSdio = AnyID<Itf::k2, Chan::k4>;
#endif	// SDIO_BASE

#ifdef SPI_BASE
/// A template class to map SPI RX to DMA channel
using IdSpiRx = AnyID<Itf::k2, Chan::k1>;
/// A template class to map SPI TX to DMA channel
using IdSpiTx = AnyID<Itf::k2, Chan::k2>;
#endif	// SPI_BASE

#ifdef SPI1_BASE
/// A template class to map SPI1 RX to DMA channel
using IdSpi1Rx = AnyID<Itf::k1, Chan::k2>;
/// A template class to map SPI1 TX to DMA channel
using IdSpi1Tx = AnyID<Itf::k1, Chan::k3>;
#endif	// SPI1_BASE

#ifdef SPI2_BASE
/// A template class to map SPI2 RX to DMA channel
using IdSpi2Rx = AnyID<Itf::k1, Chan::k4>;
/// A template class to map SPI2 TX to DMA channel
using IdSpi2Tx = AnyID<Itf::k1, Chan::k5>;
#endif	// SPI2_BASE

#ifdef SPI3_BASE
/// A template class to map SPI3 RX to DMA channel
using IdSpi3Rx = AnyID<Itf::k2, Chan::k1>;
/// A template class to map SPI3 TX to DMA channel
using IdSpi3Tx = AnyID<Itf::k2, Chan::k2>;
#endif	// SPI3_BASE

#ifdef TIM1_BASE
/// A template class to map TIM1 CH1 to DMA channel
using IdTim1Ch1 = AnyID<Itf::k1, Chan::k2>;
/// A template class to map TIM1 CH2 to DMA channel
using IdTim1Ch2 = AnyID<Itf::k1, Chan::k3>;
/// A template class to map TIM1 CH3 to DMA channel
using IdTim1Ch3 = AnyID<Itf::k1, Chan::k6>;
/// A template class to map TIM1 CH4 to DMA channel
using IdTim1Ch4 = AnyID<Itf::k1, Chan::k4>;
/// A template class to map TIM1 COM to DMA channel
using IdTim1Com = AnyID<Itf::k1, Chan::k4>;
/// A template class to map TIM1 TRIG to DMA channel
using IdTim1Trig = AnyID<Itf::k1, Chan::k4>;
/// A template class to map TIM1 UP to DMA channel
using IdTim1Up = AnyID<Itf::k1, Chan::k5>;
#endif	// TIM1_BASE

#ifdef TIM2_BASE
/// A template class to map TIM2 CH1 to DMA channel
using IdTim2Ch1 = AnyID<Itf::k1, Chan::k5>;
/// A template class to map TIM2 CH2 to DMA channel
using IdTim2Ch2 = AnyID<Itf::k1, Chan::k7>;
/// A template class to map TIM2 CH3 to DMA channel
using IdTim2Ch3 = AnyID<Itf::k1, Chan::k1>;
/// A template class to map TIM2 CH4 to DMA channel
using IdTim2Ch4 = AnyID<Itf::k1, Chan::k7>;
/// A template class to map TIM2 UP to DMA channel
using IdTim2Up = AnyID<Itf::k1, Chan::k2>;
#endif	// TIM2_BASE

#ifdef TIM3_BASE
/// A template class to map TIM3 CH1 to DMA channel
using IdTim3Ch1 = AnyID<Itf::k1, Chan::k6>;
/// A template class to map TIM3 CH3 to DMA channel
using IdTim3Ch3 = AnyID<Itf::k1, Chan::k2>;
/// A template class to map TIM3 CH4 to DMA channel
using IdTim3Ch4 = AnyID<Itf::k1, Chan::k3>;
/// A template class to map TIM3 TRIG to DMA channel
using IdTim3Trig = AnyID<Itf::k1, Chan::k6>;
/// A template class to map TIM3 UP to DMA channel
using IdTim3Up = AnyID<Itf::k1, Chan::k3>;
#endif	// TIM3_BASE

#ifdef TIM4_BASE
/// A template class to map TIM4 CH1 to DMA channel
using IdTim4Ch1 = AnyID<Itf::k1, Chan::k1>;
/// A template class to map TIM4 CH2 to DMA channel
using IdTim4Ch2 = AnyID<Itf::k1, Chan::k4>;
/// A template class to map TIM4 CH3 to DMA channel
using IdTim4Ch3 = AnyID<Itf::k1, Chan::k5>;
/// A template class to map TIM4 UP to DMA channel
using IdTim4Up = AnyID<Itf::k1, Chan::k7>;
#endif	// TIM4_BASE

#ifdef TIM5_BASE
/// A template class to map TIM5 CH1 to DMA channel
using IdTim5Ch1 = AnyID<Itf::k2, Chan::k5>;
/// A template class to map TIM5 CH2 to DMA channel
using IdTim5Ch2 = AnyID<Itf::k2, Chan::k4>;
/// A template class to map TIM5 CH3 to DMA channel
using IdTim5Ch3 = AnyID<Itf::k2, Chan::k2>;
/// A template class to map TIM5 CH4 to DMA channel
using IdTim5Ch4 = AnyID<Itf::k2, Chan::k1>;
/// A template class to map TIM5 TRIG to DMA channel
using IdTim5Trig = AnyID<Itf::k2, Chan::k1>;
/// A template class to map TIM5 UP to DMA channel
using IdTim5Up = AnyID<Itf::k2, Chan::k2>;
#endif	// TIM5_BASE

#ifdef TIM6_BASE
/// A template class to map TIM6 UP to DMA channel
using IdTim6Up = AnyID<Itf::k2, Chan::k3>;
#endif	// TIM6_BASE

#ifdef TIM7_BASE
/// A template class to map TIM7 UP to DMA channel
using IdTim7Up = AnyID<Itf::k2, Chan::k4>;
#endif	// TIM7_BASE

#ifdef TIM8_BASE
/// A template class to map TIM8 CH1 to DMA channel
using IdTim8Ch1 = AnyID<Itf::k2, Chan::k3>;
/// A template class to map TIM8 CH2 to DMA channel
using IdTim8Ch2 = AnyID<Itf::k2, Chan::k5>;
/// A template class to map TIM8 CH3 to DMA channel
using IdTim8Ch3 = AnyID<Itf::k2, Chan::k1>;
/// A template class to map TIM8 CH4 to DMA channel
using IdTim8Ch4 = AnyID<Itf::k2, Chan::k2>;
/// A template class to map TIM8 COM to DMA channel
using IdTim8Com = AnyID<Itf::k2, Chan::k2>;
/// A template class to map TIM8 TRIG to DMA channel
using IdTim8Trig = AnyID<Itf::k2, Chan::k2>;
/// A template class to map TIM8 UP to DMA channel
using IdTim8Up = AnyID<Itf::k2, Chan::k1>;
#endif	// TIM8_BASE

#ifdef TIM15_BASE
/// A template class to map TIM15 CH1 to DMA channel
using IdTim15Ch1 = AnyID<Itf::k1, Chan::k5>;
/// A template class to map TIM15 COM to DMA channel
using IdTim15Com = AnyID<Itf::k1, Chan::k5>;
/// A template class to map TIM15 TRIG to DMA channel
using IdTim15Trig = AnyID<Itf::k1, Chan::k5>;
/// A template class to map TIM15 UP to DMA channel
using IdTim15Up = AnyID<Itf::k1, Chan::k5>;
#endif	// TIM15_BASE

#ifdef TIM16_BASE
/// A template class to map TIM16 CH1 to DMA channel
using IdTim16Ch1 = AnyID<Itf::k1, Chan::k6>;
/// A template class to map TIM16 UP to DMA channel
using IdTim16Up = AnyID<Itf::k1, Chan::k6>;
#endif	// TIM16_BASE

#ifdef TIM17_BASE
/// A template class to map TIM17 CH1 to DMA channel
using IdTim17Ch1 = AnyID<Itf::k1, Chan::k7>;
/// A template class to map TIM17 UP to DMA channel
using IdTim17Up = AnyID<Itf::k1, Chan::k7>;
#endif	// TIM17_BASE

#ifdef UART4_BASE
/// A template class to map UART4 RX to DMA channel
using IdUart4Rx = AnyID<Itf::k2, Chan::k3>;
/// A template class to map UART4 TX to DMA channel
using IdUart4Tx = AnyID<Itf::k2, Chan::k5>;
#endif	// UART4_BASE

#ifdef UART5_BASE
/// A template class to map UART5 RX to DMA channel
using IdUart5Rx = AnyID<Itf::k2, Chan::k4>;
/// A template class to map UART5 TX to DMA channel
using IdUart5Tx = AnyID<Itf::k2, Chan::k1>;
#endif	// UART5_BASE

#ifdef USART1_BASE
/// A template class to map USART1 RX to DMA channel
using IdUsart1Rx = AnyID<Itf::k1, Chan::k5>;
/// A template class to map USART1 TX to DMA channel
using IdUsart1Tx = AnyID<Itf::k1, Chan::k4>;
#endif	// USART1_BASE

#ifdef USART2_BASE
/// A template class to map USART2 RX to DMA channel
using IdUsart2Rx = AnyID<Itf::k1, Chan::k6>;
/// A template class to map USART2 TX to DMA channel
using IdUsart2Tx = AnyID<Itf::k1, Chan::k7>;
#endif	// USART2_BASE

#ifdef USART3_BASE
/// A template class to map USART3 RX to DMA channel
using IdUsart3Rx = AnyID<Itf::k1, Chan::k3>;
/// A template class to map USART3 TX to DMA channel
using IdUsart3Tx = AnyID<Itf::k1, Chan::k2>;
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
#endif	// ADC1_BASE

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
#endif	// ADC3_BASE

#ifdef DAC_BASE
/// A template class to configure DAC Channel1 with DMA transfer
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDacChannel1 : public AnyChannel <
	IdDacChannel1
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure DAC Channel2 with DMA transfer
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDacChannel2 : public AnyChannel <
	IdDacChannel2
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// DAC_BASE

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

#ifdef I2S2_BASE
/// A template class to configure I2S2 RX with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyI2s2Rx : public AnyChannel <
	IdI2s2Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure I2S2 TX with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyI2s2Tx : public AnyChannel <
	IdI2s2Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// I2S2_BASE

#ifdef I2S3_BASE
/// A template class to configure I2S3 RX with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyI2s3Rx : public AnyChannel <
	IdI2s3Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure I2S3 TX with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyI2s3Tx : public AnyChannel <
	IdI2s3Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// I2S3_BASE

#ifdef SDIO_BASE
/// A template class to configure SDIO with DMA transfer
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnySdio : public AnyChannel <
	IdSdio
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// SDIO_BASE

#ifdef SPI_BASE
/// A template class to configure SPI RX with DMA transfer
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnySpiRx : public AnyChannel <
	IdSpiRx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SPI TX with DMA transfer
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnySpiTx : public AnyChannel <
	IdSpiTx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// SPI_BASE

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
