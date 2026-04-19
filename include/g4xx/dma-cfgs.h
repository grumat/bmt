#pragma once

namespace Bmt
{
namespace Dma
{


enum class PerifSel : uint8_t
{
#ifdef ADC1_BASE
	kAdc1 = 5,	// ADC1
#endif	// ADC1_BASE

#ifdef ADC2_BASE
	kAdc2 = 36,	// ADC2
#endif	// ADC2_BASE

#ifdef ADC3_BASE
	kAdc3 = 37,	// ADC3
#endif	// ADC3_BASE

#ifdef ADC4_BASE
	kAdc4 = 38,	// ADC4
#endif	// ADC4_BASE

#ifdef ADC5_BASE
	kAdc5 = 39,	// ADC5
#endif	// ADC5_BASE

#ifdef AES_BASE
	kAesIn = 91,	// AES IN
	kAesOut = 92,	// AES OUT
#endif	// AES_BASE

#ifdef CORDIC_BASE
	kCordicRead = 112,	// CORDIC READ
	kCordicWrite = 113,	// CORDIC WRITE
#endif	// CORDIC_BASE

#ifdef DAC1_BASE
	kDac1Channel1 = 6,	// DAC1 CHANNEL1
	kDac1Channel2 = 7,	// DAC1 CHANNEL2
#endif	// DAC1_BASE

#ifdef DAC2_BASE
	kDac2Channel1 = 41,	// DAC2 CHANNEL1
#endif	// DAC2_BASE

#ifdef DAC3_BASE
	kDac3Channel1 = 102,	// DAC3 CHANNEL1
	kDac3Channel2 = 103,	// DAC3 CHANNEL2
#endif	// DAC3_BASE

#ifdef DAC4_BASE
	kDac4Channel1 = 104,	// DAC4 CHANNEL1
	kDac4Channel2 = 105,	// DAC4 CHANNEL2
#endif	// DAC4_BASE

#ifdef FMAC_BASE
	kFmacRead = 110,	// FMAC READ
	kFmacWrite = 111,	// FMAC WRITE
#endif	// FMAC_BASE

	kGenerator0 = 1,	// GENERATOR0
	kGenerator1 = 2,	// GENERATOR1
	kGenerator2 = 3,	// GENERATOR2
	kGenerator3 = 4,	// GENERATOR3

#ifdef HRTIM1_BASE
	kHrtim1A = 96,	// HRTIM1 A
	kHrtim1B = 97,	// HRTIM1 B
	kHrtim1C = 98,	// HRTIM1 C
	kHrtim1D = 99,	// HRTIM1 D
	kHrtim1E = 100,	// HRTIM1 E
	kHrtim1F = 101,	// HRTIM1 F
	kHrtim1M = 95,	// HRTIM1 M
#endif	// HRTIM1_BASE

#ifdef I2C1_BASE
	kI2c1Rx = 16,	// I2C1 RX
	kI2c1Tx = 17,	// I2C1 TX
#endif	// I2C1_BASE

#ifdef I2C2_BASE
	kI2c2Rx = 18,	// I2C2 RX
	kI2c2Tx = 19,	// I2C2 TX
#endif	// I2C2_BASE

#ifdef I2C3_BASE
	kI2c3Rx = 20,	// I2C3 RX
	kI2c3Tx = 21,	// I2C3 TX
#endif	// I2C3_BASE

#ifdef I2C4_BASE
	kI2c4Rx = 22,	// I2C4 RX
	kI2c4Tx = 23,	// I2C4 TX
#endif	// I2C4_BASE

#ifdef LPUART1_BASE
	kLpuart1Rx = 34,	// LPUART1 RX
	kLpuart1Tx = 35,	// LPUART1 TX
#endif	// LPUART1_BASE

	kMem2Mem = 0,	// MEM2MEM

#ifdef QUADSPI_BASE
	kQuadspi = 40,	// QUADSPI
#endif	// QUADSPI_BASE

#ifdef SAI1_BASE
	kSai1A = 108,	// SAI1 A
	kSai1B = 109,	// SAI1 B
#endif	// SAI1_BASE

#ifdef SPI1_BASE
	kSpi1Rx = 10,	// SPI1 RX
	kSpi1Tx = 11,	// SPI1 TX
#endif	// SPI1_BASE

#ifdef SPI2_BASE
	kSpi2Rx = 12,	// SPI2 RX
	kSpi2Tx = 13,	// SPI2 TX
#endif	// SPI2_BASE

#ifdef SPI3_BASE
	kSpi3Rx = 14,	// SPI3 RX
	kSpi3Tx = 15,	// SPI3 TX
#endif	// SPI3_BASE

#ifdef SPI4_BASE
	kSpi4Rx = 106,	// SPI4 RX
	kSpi4Tx = 107,	// SPI4 TX
#endif	// SPI4_BASE

#ifdef TIM1_BASE
	kTim1Ch1 = 42,	// TIM1 CH1
	kTim1Ch2 = 43,	// TIM1 CH2
	kTim1Ch3 = 44,	// TIM1 CH3
	kTim1Ch4 = 45,	// TIM1 CH4
	kTim1Com = 48,	// TIM1 COM
	kTim1Trig = 47,	// TIM1 TRIG
	kTim1Up = 46,	// TIM1 UP
#endif	// TIM1_BASE

#ifdef TIM2_BASE
	kTim2Ch1 = 56,	// TIM2 CH1
	kTim2Ch2 = 57,	// TIM2 CH2
	kTim2Ch3 = 58,	// TIM2 CH3
	kTim2Ch4 = 59,	// TIM2 CH4
	kTim2Up = 60,	// TIM2 UP
#endif	// TIM2_BASE

#ifdef TIM3_BASE
	kTim3Ch1 = 61,	// TIM3 CH1
	kTim3Ch2 = 62,	// TIM3 CH2
	kTim3Ch3 = 63,	// TIM3 CH3
	kTim3Ch4 = 64,	// TIM3 CH4
	kTim3Trig = 66,	// TIM3 TRIG
	kTim3Up = 65,	// TIM3 UP
#endif	// TIM3_BASE

#ifdef TIM4_BASE
	kTim4Ch1 = 67,	// TIM4 CH1
	kTim4Ch2 = 68,	// TIM4 CH2
	kTim4Ch3 = 69,	// TIM4 CH3
	kTim4Ch4 = 70,	// TIM4 CH4
	kTim4Up = 71,	// TIM4 UP
#endif	// TIM4_BASE

#ifdef TIM5_BASE
	kTim5Ch1 = 72,	// TIM5 CH1
	kTim5Ch2 = 73,	// TIM5 CH2
	kTim5Ch3 = 74,	// TIM5 CH3
	kTim5Ch4 = 75,	// TIM5 CH4
	kTim5Trig = 77,	// TIM5 TRIG
	kTim5Up = 76,	// TIM5 UP
#endif	// TIM5_BASE

#ifdef TIM6_BASE
	kTim6Up = 8,	// TIM6 UP
#endif	// TIM6_BASE

#ifdef TIM7_BASE
	kTim7Up = 9,	// TIM7 UP
#endif	// TIM7_BASE

#ifdef TIM8_BASE
	kTim8Ch1 = 49,	// TIM8 CH1
	kTim8Ch2 = 50,	// TIM8 CH2
	kTim8Ch3 = 51,	// TIM8 CH3
	kTim8Ch4 = 52,	// TIM8 CH4
	kTim8Com = 55,	// TIM8 COM
	kTim8Trig = 54,	// TIM8 TRIG
	kTim8Up = 53,	// TIM8 UP
#endif	// TIM8_BASE

#ifdef TIM15_BASE
	kTim15Ch1 = 78,	// TIM15 CH1
	kTim15Com = 81,	// TIM15 COM
	kTim15Trig = 80,	// TIM15 TRIG
	kTim15Up = 79,	// TIM15 UP
#endif	// TIM15_BASE

#ifdef TIM16_BASE
	kTim16Ch1 = 82,	// TIM16 CH1
	kTim16Up = 83,	// TIM16 UP
#endif	// TIM16_BASE

#ifdef TIM17_BASE
	kTim17Ch1 = 84,	// TIM17 CH1
	kTim17Up = 85,	// TIM17 UP
#endif	// TIM17_BASE

#ifdef TIM20_BASE
	kTim20Ch1 = 86,	// TIM20 CH1
	kTim20Ch2 = 87,	// TIM20 CH2
	kTim20Ch3 = 88,	// TIM20 CH3
	kTim20Ch4 = 89,	// TIM20 CH4
	kTim20Com = 94,	// TIM20 COM
	kTim20Trig = 93,	// TIM20 TRIG
	kTim20Up = 90,	// TIM20 UP
#endif	// TIM20_BASE

#ifdef UART4_BASE
	kUart4Rx = 30,	// UART4 RX
	kUart4Tx = 31,	// UART4 TX
#endif	// UART4_BASE

#ifdef UART5_BASE
	kUart5Rx = 32,	// UART5 RX
	kUart5Tx = 33,	// UART5 TX
#endif	// UART5_BASE

#ifdef UCPD1_BASE
	kUcpd1Rx = 114,	// UCPD1 RX
	kUcpd1Tx = 115,	// UCPD1 TX
#endif	// UCPD1_BASE

#ifdef USART1_BASE
	kUsart1Rx = 24,	// USART1 RX
	kUsart1Tx = 25,	// USART1 TX
#endif	// USART1_BASE

#ifdef USART2_BASE
	kUsart2Rx = 26,	// USART2 RX
	kUsart2Tx = 27,	// USART2 TX
#endif	// USART2_BASE

#ifdef USART3_BASE
	kUsart3Rx = 28,	// USART3 RX
	kUsart3Tx = 29,	// USART3 TX
#endif	// USART3_BASE

};


using IdNone = AnyID<Itf::k1, Chan::kNone, PerifSel::kMem2Mem>;

/* The type definitions below are, wherever possible, based on DMA settings of STM32L4xx. */

#ifdef ADC1_BASE
/// A template class to map ADC1 to DMA1 channel 1
using IdAdc1 = AnyID<Itf::k1, Chan::k1, PerifSel::kAdc1>;
/// A template class to map ADC1 to DMA2 channel 3 (alternate)
using IdAdc1_2 = AnyID<Itf::k2, Chan::k3, PerifSel::kAdc1>;
#endif	// ADC1_BASE

#ifdef ADC2_BASE
/// A template class to map ADC2 to DMA1 channel 2
using IdAdc2 = AnyID<Itf::k1, Chan::k2, PerifSel::kAdc2>;
/// A template class to map ADC2 to DMA2 channel 4 (alternate)
using IdAdc2_2 = AnyID<Itf::k2, Chan::k4, PerifSel::kAdc2>;
#endif	// ADC2_BASE

#ifdef ADC3_BASE
/// A template class to map ADC3 to DMA1 channel 3
using IdAdc3 = AnyID<Itf::k1, Chan::k3, PerifSel::kAdc3>;
/// A template class to map ADC3 to DMA2 channel 5 (alternate)
using IdAdc3_2 = AnyID<Itf::k2, Chan::k5, PerifSel::kAdc3>;
#endif	// ADC3_BASE

#ifdef ADC4_BASE
/// A template class to map ADC4 to DMA2 channel 3
using IdAdc4 = AnyID<Itf::k2, Chan::k3, PerifSel::kAdc4>;
#endif	// ADC4_BASE

#ifdef ADC5_BASE
/// A template class to map ADC5 to DMA1 channel 1
using IdAdc5 = AnyID<Itf::k1, Chan::k1, PerifSel::kAdc5>;
#endif	// ADC5_BASE

#ifdef AES_BASE
/// A template class to map AES IN to DMA2 channel 1
using IdAesIn = AnyID<Itf::k2, Chan::k1, PerifSel::kAesIn>;
/// A template class to map AES IN to DMA2 channel 5 (alternate)
using IdAesIn_2 = AnyID<Itf::k2, Chan::k5, PerifSel::kAesIn>;
/// A template class to map AES OUT to DMA2 channel 2
using IdAesOut = AnyID<Itf::k2, Chan::k2, PerifSel::kAesOut>;
/// A template class to map AES OUT to DMA2 channel 3 (alternate)
using IdAesOut_2 = AnyID<Itf::k2, Chan::k3, PerifSel::kAesOut>;
#endif	// AES_BASE

#ifdef CORDIC_BASE
/// A template class to map CORDIC READ to DMA2 channel 3
using IdCordicRead = AnyID<Itf::k2, Chan::k3, PerifSel::kCordicRead>;
/// A template class to map CORDIC WRITE to DMA1 channel 1
using IdCordicWrite = AnyID<Itf::k1, Chan::k1, PerifSel::kCordicWrite>;
#endif	// CORDIC_BASE

#ifdef DAC1_BASE
/// A template class to map DAC1 CHANNEL1 to DMA1 channel 3
using IdDac1Channel1 = AnyID<Itf::k1, Chan::k3, PerifSel::kDac1Channel1>;
/// A template class to map DAC1 CHANNEL1 to DMA2 channel 4 (alternate)
using IdDac1Channel1_2 = AnyID<Itf::k2, Chan::k4, PerifSel::kDac1Channel1>;
/// A template class to map DAC1 CHANNEL2 to DMA1 channel 4
using IdDac1Channel2 = AnyID<Itf::k1, Chan::k4, PerifSel::kDac1Channel2>;
/// A template class to map DAC1 CHANNEL2 to DMA2 channel 5 (alternate)
using IdDac1Channel2_2 = AnyID<Itf::k2, Chan::k5, PerifSel::kDac1Channel2>;
#endif	// DAC1_BASE

#ifdef DAC2_BASE
/// A template class to map DAC2 CHANNEL1 to DMA2 channel 4
using IdDac2Channel1 = AnyID<Itf::k2, Chan::k4, PerifSel::kDac2Channel1>;
#endif	// DAC2_BASE

#ifdef DAC3_BASE
/// A template class to map DAC3 CHANNEL1 to DMA2 channel 6
using IdDac3Channel1 = AnyID<Itf::k2, Chan::k6, PerifSel::kDac3Channel1>;
/// A template class to map DAC3 CHANNEL2 to DMA2 channel 4
using IdDac3Channel2 = AnyID<Itf::k2, Chan::k4, PerifSel::kDac3Channel2>;
#endif	// DAC3_BASE

#ifdef DAC4_BASE
/// A template class to map DAC4 CHANNEL1 to DMA2 channel 6
using IdDac4Channel1 = AnyID<Itf::k2, Chan::k6, PerifSel::kDac4Channel1>;
/// A template class to map DAC4 CHANNEL2 to DMA2 channel 4
using IdDac4Channel2 = AnyID<Itf::k2, Chan::k4, PerifSel::kDac4Channel2>;
#endif	// DAC4_BASE

#ifdef FMAC_BASE
/// A template class to map FMAC READ to DMA2 channel 6
using IdFmacRead = AnyID<Itf::k2, Chan::k6, PerifSel::kFmacRead>;
/// A template class to map FMAC WRITE to DMA2 channel 4
using IdFmacWrite = AnyID<Itf::k2, Chan::k4, PerifSel::kFmacWrite>;
#endif	// FMAC_BASE

/// A template class to map GENERATOR0 to DMA2 channel 6
using IdGenerator0 = AnyID<Itf::k2, Chan::k6, PerifSel::kGenerator0>;
/// A template class to map GENERATOR1 to DMA2 channel 4
using IdGenerator1 = AnyID<Itf::k2, Chan::k4, PerifSel::kGenerator1>;
/// A template class to map GENERATOR2 to DMA1 channel 1
using IdGenerator2 = AnyID<Itf::k1, Chan::k1, PerifSel::kGenerator2>;
/// A template class to map GENERATOR3 to DMA2 channel 3
using IdGenerator3 = AnyID<Itf::k2, Chan::k3, PerifSel::kGenerator3>;
#ifdef HRTIM1_BASE
/// A template class to map HRTIM1 A to DMA2 channel 5
using IdHrtim1A = AnyID<Itf::k2, Chan::k5, PerifSel::kHrtim1A>;
/// A template class to map HRTIM1 B to DMA2 channel 7
using IdHrtim1B = AnyID<Itf::k2, Chan::k7, PerifSel::kHrtim1B>;
/// A template class to map HRTIM1 C to DMA1 channel 2
using IdHrtim1C = AnyID<Itf::k1, Chan::k2, PerifSel::kHrtim1C>;
/// A template class to map HRTIM1 D to DMA1 channel 6
using IdHrtim1D = AnyID<Itf::k1, Chan::k6, PerifSel::kHrtim1D>;
/// A template class to map HRTIM1 E to DMA1 channel 7
using IdHrtim1E = AnyID<Itf::k1, Chan::k7, PerifSel::kHrtim1E>;
/// A template class to map HRTIM1 F to DMA1 channel 4
using IdHrtim1F = AnyID<Itf::k1, Chan::k4, PerifSel::kHrtim1F>;
/// A template class to map HRTIM1 M to DMA2 channel 1
using IdHrtim1M = AnyID<Itf::k2, Chan::k1, PerifSel::kHrtim1M>;
#endif	// HRTIM1_BASE

#ifdef I2C1_BASE
/// A template class to map I2C1 RX to DMA1 channel 7
using IdI2c1Rx = AnyID<Itf::k1, Chan::k7, PerifSel::kI2c1Rx>;
/// A template class to map I2C1 RX to DMA2 channel 6 (alternate)
using IdI2c1Rx_2 = AnyID<Itf::k2, Chan::k6, PerifSel::kI2c1Rx>;
/// A template class to map I2C1 TX to DMA1 channel 6
using IdI2c1Tx = AnyID<Itf::k1, Chan::k6, PerifSel::kI2c1Tx>;
/// A template class to map I2C1 TX to DMA2 channel 7 (alternate)
using IdI2c1Tx_2 = AnyID<Itf::k2, Chan::k7, PerifSel::kI2c1Tx>;
#endif	// I2C1_BASE

#ifdef I2C2_BASE
/// A template class to map I2C2 RX to DMA1 channel 5
using IdI2c2Rx = AnyID<Itf::k1, Chan::k5, PerifSel::kI2c2Rx>;
/// A template class to map I2C2 TX to DMA1 channel 4
using IdI2c2Tx = AnyID<Itf::k1, Chan::k4, PerifSel::kI2c2Tx>;
#endif	// I2C2_BASE

#ifdef I2C3_BASE
/// A template class to map I2C3 RX to DMA1 channel 3
using IdI2c3Rx = AnyID<Itf::k1, Chan::k3, PerifSel::kI2c3Rx>;
/// A template class to map I2C3 TX to DMA1 channel 2
using IdI2c3Tx = AnyID<Itf::k1, Chan::k2, PerifSel::kI2c3Tx>;
#endif	// I2C3_BASE

#ifdef I2C4_BASE
/// A template class to map I2C4 RX to DMA2 channel 1
using IdI2c4Rx = AnyID<Itf::k2, Chan::k1, PerifSel::kI2c4Rx>;
/// A template class to map I2C4 TX to DMA2 channel 2
using IdI2c4Tx = AnyID<Itf::k2, Chan::k2, PerifSel::kI2c4Tx>;
#endif	// I2C4_BASE

#ifdef LPUART1_BASE
/// A template class to map LPUART1 RX to DMA2 channel 7
using IdLpuart1Rx = AnyID<Itf::k2, Chan::k7, PerifSel::kLpuart1Rx>;
/// A template class to map LPUART1 TX to DMA2 channel 6
using IdLpuart1Tx = AnyID<Itf::k2, Chan::k6, PerifSel::kLpuart1Tx>;
#endif	// LPUART1_BASE

/// A template class to map MEM2MEM to DMA1 channel 4
using IdMem2Mem = AnyID<Itf::k1, Chan::k4, PerifSel::kMem2Mem>;
#ifdef QUADSPI_BASE
/// A template class to map QUADSPI to DMA1 channel 5
using IdQuadspi = AnyID<Itf::k1, Chan::k5, PerifSel::kQuadspi>;
/// A template class to map QUADSPI to DMA2 channel 7 (alternate)
using IdQuadspi_2 = AnyID<Itf::k2, Chan::k7, PerifSel::kQuadspi>;
#endif	// QUADSPI_BASE

#ifdef SAI1_BASE
/// A template class to map SAI1 A to DMA2 channel 1
using IdSai1A = AnyID<Itf::k2, Chan::k1, PerifSel::kSai1A>;
/// A template class to map SAI1 A to DMA2 channel 6 (alternate)
using IdSai1A_2 = AnyID<Itf::k2, Chan::k6, PerifSel::kSai1A>;
/// A template class to map SAI1 B to DMA2 channel 2
using IdSai1B = AnyID<Itf::k2, Chan::k2, PerifSel::kSai1B>;
/// A template class to map SAI1 B to DMA2 channel 7 (alternate)
using IdSai1B_2 = AnyID<Itf::k2, Chan::k7, PerifSel::kSai1B>;
#endif	// SAI1_BASE

#ifdef SPI1_BASE
/// A template class to map SPI1 RX to DMA1 channel 2
using IdSpi1Rx = AnyID<Itf::k1, Chan::k2, PerifSel::kSpi1Rx>;
/// A template class to map SPI1 RX to DMA2 channel 3 (alternate)
using IdSpi1Rx_2 = AnyID<Itf::k2, Chan::k3, PerifSel::kSpi1Rx>;
/// A template class to map SPI1 TX to DMA1 channel 3
using IdSpi1Tx = AnyID<Itf::k1, Chan::k3, PerifSel::kSpi1Tx>;
/// A template class to map SPI1 TX to DMA2 channel 4 (alternate)
using IdSpi1Tx_2 = AnyID<Itf::k2, Chan::k4, PerifSel::kSpi1Tx>;
#endif	// SPI1_BASE

#ifdef SPI2_BASE
/// A template class to map SPI2 RX to DMA1 channel 4
using IdSpi2Rx = AnyID<Itf::k1, Chan::k4, PerifSel::kSpi2Rx>;
/// A template class to map SPI2 TX to DMA1 channel 5
using IdSpi2Tx = AnyID<Itf::k1, Chan::k5, PerifSel::kSpi2Tx>;
#endif	// SPI2_BASE

#ifdef SPI3_BASE
/// A template class to map SPI3 RX to DMA2 channel 1
using IdSpi3Rx = AnyID<Itf::k2, Chan::k1, PerifSel::kSpi3Rx>;
/// A template class to map SPI3 TX to DMA2 channel 2
using IdSpi3Tx = AnyID<Itf::k2, Chan::k2, PerifSel::kSpi3Tx>;
#endif	// SPI3_BASE

#ifdef SPI4_BASE
/// A template class to map SPI4 RX to DMA2 channel 5
using IdSpi4Rx = AnyID<Itf::k2, Chan::k5, PerifSel::kSpi4Rx>;
/// A template class to map SPI4 TX to DMA1 channel 2
using IdSpi4Tx = AnyID<Itf::k1, Chan::k2, PerifSel::kSpi4Tx>;
#endif	// SPI4_BASE

#ifdef TIM1_BASE
/// A template class to map TIM1 CH1 to DMA1 channel 2
using IdTim1Ch1 = AnyID<Itf::k1, Chan::k2, PerifSel::kTim1Ch1>;
/// A template class to map TIM1 CH2 to DMA1 channel 3
using IdTim1Ch2 = AnyID<Itf::k1, Chan::k3, PerifSel::kTim1Ch2>;
/// A template class to map TIM1 CH3 to DMA1 channel 7
using IdTim1Ch3 = AnyID<Itf::k1, Chan::k7, PerifSel::kTim1Ch3>;
/// A template class to map TIM1 CH4 to DMA1 channel 4
using IdTim1Ch4 = AnyID<Itf::k1, Chan::k4, PerifSel::kTim1Ch4>;
/// A template class to map TIM1 COM to DMA1 channel 4
using IdTim1Com = AnyID<Itf::k1, Chan::k4, PerifSel::kTim1Com>;
/// A template class to map TIM1 TRIG to DMA1 channel 4
using IdTim1Trig = AnyID<Itf::k1, Chan::k4, PerifSel::kTim1Trig>;
/// A template class to map TIM1 UP to DMA1 channel 6
using IdTim1Up = AnyID<Itf::k1, Chan::k6, PerifSel::kTim1Up>;
#endif	// TIM1_BASE

#ifdef TIM2_BASE
/// A template class to map TIM2 CH1 to DMA1 channel 5
using IdTim2Ch1 = AnyID<Itf::k1, Chan::k5, PerifSel::kTim2Ch1>;
/// A template class to map TIM2 CH2 to DMA1 channel 7
using IdTim2Ch2 = AnyID<Itf::k1, Chan::k7, PerifSel::kTim2Ch2>;
/// A template class to map TIM2 CH3 to DMA1 channel 1
using IdTim2Ch3 = AnyID<Itf::k1, Chan::k1, PerifSel::kTim2Ch3>;
/// A template class to map TIM2 CH4 to DMA1 channel 7
using IdTim2Ch4 = AnyID<Itf::k1, Chan::k7, PerifSel::kTim2Ch4>;
/// A template class to map TIM2 UP to DMA1 channel 2
using IdTim2Up = AnyID<Itf::k1, Chan::k2, PerifSel::kTim2Up>;
#endif	// TIM2_BASE

#ifdef TIM3_BASE
/// A template class to map TIM3 CH1 to DMA1 channel 6
using IdTim3Ch1 = AnyID<Itf::k1, Chan::k6, PerifSel::kTim3Ch1>;
/// A template class to map TIM3 CH2 to DMA2 channel 5
using IdTim3Ch2 = AnyID<Itf::k2, Chan::k5, PerifSel::kTim3Ch2>;
/// A template class to map TIM3 CH3 to DMA1 channel 2
using IdTim3Ch3 = AnyID<Itf::k1, Chan::k2, PerifSel::kTim3Ch3>;
/// A template class to map TIM3 CH4 to DMA1 channel 3
using IdTim3Ch4 = AnyID<Itf::k1, Chan::k3, PerifSel::kTim3Ch4>;
/// A template class to map TIM3 TRIG to DMA1 channel 6
using IdTim3Trig = AnyID<Itf::k1, Chan::k6, PerifSel::kTim3Trig>;
/// A template class to map TIM3 UP to DMA1 channel 3
using IdTim3Up = AnyID<Itf::k1, Chan::k3, PerifSel::kTim3Up>;
#endif	// TIM3_BASE

#ifdef TIM4_BASE
/// A template class to map TIM4 CH1 to DMA1 channel 1
using IdTim4Ch1 = AnyID<Itf::k1, Chan::k1, PerifSel::kTim4Ch1>;
/// A template class to map TIM4 CH2 to DMA1 channel 4
using IdTim4Ch2 = AnyID<Itf::k1, Chan::k4, PerifSel::kTim4Ch2>;
/// A template class to map TIM4 CH3 to DMA1 channel 5
using IdTim4Ch3 = AnyID<Itf::k1, Chan::k5, PerifSel::kTim4Ch3>;
/// A template class to map TIM4 CH4 to DMA1 channel 2
using IdTim4Ch4 = AnyID<Itf::k1, Chan::k2, PerifSel::kTim4Ch4>;
/// A template class to map TIM4 UP to DMA1 channel 7
using IdTim4Up = AnyID<Itf::k1, Chan::k7, PerifSel::kTim4Up>;
#endif	// TIM4_BASE

#ifdef TIM5_BASE
/// A template class to map TIM5 CH1 to DMA2 channel 5
using IdTim5Ch1 = AnyID<Itf::k2, Chan::k5, PerifSel::kTim5Ch1>;
/// A template class to map TIM5 CH2 to DMA2 channel 4
using IdTim5Ch2 = AnyID<Itf::k2, Chan::k4, PerifSel::kTim5Ch2>;
/// A template class to map TIM5 CH3 to DMA2 channel 2
using IdTim5Ch3 = AnyID<Itf::k2, Chan::k2, PerifSel::kTim5Ch3>;
/// A template class to map TIM5 CH4 to DMA2 channel 1
using IdTim5Ch4 = AnyID<Itf::k2, Chan::k1, PerifSel::kTim5Ch4>;
/// A template class to map TIM5 TRIG to DMA2 channel 1
using IdTim5Trig = AnyID<Itf::k2, Chan::k1, PerifSel::kTim5Trig>;
/// A template class to map TIM5 UP to DMA2 channel 2
using IdTim5Up = AnyID<Itf::k2, Chan::k2, PerifSel::kTim5Up>;
#endif	// TIM5_BASE

#ifdef TIM6_BASE
/// A template class to map TIM6 UP to DMA1 channel 3
using IdTim6Up = AnyID<Itf::k1, Chan::k3, PerifSel::kTim6Up>;
/// A template class to map TIM6 UP to DMA2 channel 4 (alternate)
using IdTim6Up_2 = AnyID<Itf::k2, Chan::k4, PerifSel::kTim6Up>;
#endif	// TIM6_BASE

#ifdef TIM7_BASE
/// A template class to map TIM7 UP to DMA1 channel 4
using IdTim7Up = AnyID<Itf::k1, Chan::k4, PerifSel::kTim7Up>;
/// A template class to map TIM7 UP to DMA2 channel 5 (alternate)
using IdTim7Up_2 = AnyID<Itf::k2, Chan::k5, PerifSel::kTim7Up>;
#endif	// TIM7_BASE

#ifdef TIM8_BASE
/// A template class to map TIM8 CH1 to DMA2 channel 6
using IdTim8Ch1 = AnyID<Itf::k2, Chan::k6, PerifSel::kTim8Ch1>;
/// A template class to map TIM8 CH2 to DMA2 channel 7
using IdTim8Ch2 = AnyID<Itf::k2, Chan::k7, PerifSel::kTim8Ch2>;
/// A template class to map TIM8 CH3 to DMA2 channel 1
using IdTim8Ch3 = AnyID<Itf::k2, Chan::k1, PerifSel::kTim8Ch3>;
/// A template class to map TIM8 CH4 to DMA2 channel 2
using IdTim8Ch4 = AnyID<Itf::k2, Chan::k2, PerifSel::kTim8Ch4>;
/// A template class to map TIM8 COM to DMA2 channel 2
using IdTim8Com = AnyID<Itf::k2, Chan::k2, PerifSel::kTim8Com>;
/// A template class to map TIM8 TRIG to DMA2 channel 2
using IdTim8Trig = AnyID<Itf::k2, Chan::k2, PerifSel::kTim8Trig>;
/// A template class to map TIM8 UP to DMA2 channel 1
using IdTim8Up = AnyID<Itf::k2, Chan::k1, PerifSel::kTim8Up>;
#endif	// TIM8_BASE

#ifdef TIM15_BASE
/// A template class to map TIM15 CH1 to DMA1 channel 5
using IdTim15Ch1 = AnyID<Itf::k1, Chan::k5, PerifSel::kTim15Ch1>;
/// A template class to map TIM15 COM to DMA1 channel 5
using IdTim15Com = AnyID<Itf::k1, Chan::k5, PerifSel::kTim15Com>;
/// A template class to map TIM15 TRIG to DMA1 channel 5
using IdTim15Trig = AnyID<Itf::k1, Chan::k5, PerifSel::kTim15Trig>;
/// A template class to map TIM15 UP to DMA1 channel 5
using IdTim15Up = AnyID<Itf::k1, Chan::k5, PerifSel::kTim15Up>;
#endif	// TIM15_BASE

#ifdef TIM16_BASE
/// A template class to map TIM16 CH1 to DMA1 channel 3
using IdTim16Ch1 = AnyID<Itf::k1, Chan::k3, PerifSel::kTim16Ch1>;
/// A template class to map TIM16 CH1 to DMA1 channel 6 (alternate)
using IdTim16Ch1_2 = AnyID<Itf::k1, Chan::k6, PerifSel::kTim16Ch1>;
/// A template class to map TIM16 UP to DMA1 channel 3
using IdTim16Up = AnyID<Itf::k1, Chan::k3, PerifSel::kTim16Up>;
/// A template class to map TIM16 UP to DMA1 channel 6 (alternate)
using IdTim16Up_2 = AnyID<Itf::k1, Chan::k6, PerifSel::kTim16Up>;
#endif	// TIM16_BASE

#ifdef TIM17_BASE
/// A template class to map TIM17 CH1 to DMA1 channel 1
using IdTim17Ch1 = AnyID<Itf::k1, Chan::k1, PerifSel::kTim17Ch1>;
/// A template class to map TIM17 CH1 to DMA1 channel 7 (alternate)
using IdTim17Ch1_2 = AnyID<Itf::k1, Chan::k7, PerifSel::kTim17Ch1>;
/// A template class to map TIM17 UP to DMA1 channel 1
using IdTim17Up = AnyID<Itf::k1, Chan::k1, PerifSel::kTim17Up>;
/// A template class to map TIM17 UP to DMA1 channel 7 (alternate)
using IdTim17Up_2 = AnyID<Itf::k1, Chan::k7, PerifSel::kTim17Up>;
#endif	// TIM17_BASE

#ifdef TIM20_BASE
/// A template class to map TIM20 CH1 to DMA2 channel 5
using IdTim20Ch1 = AnyID<Itf::k2, Chan::k5, PerifSel::kTim20Ch1>;
/// A template class to map TIM20 CH2 to DMA1 channel 2
using IdTim20Ch2 = AnyID<Itf::k1, Chan::k2, PerifSel::kTim20Ch2>;
/// A template class to map TIM20 CH3 to DMA2 channel 1
using IdTim20Ch3 = AnyID<Itf::k2, Chan::k1, PerifSel::kTim20Ch3>;
/// A template class to map TIM20 CH4 to DMA1 channel 7
using IdTim20Ch4 = AnyID<Itf::k1, Chan::k7, PerifSel::kTim20Ch4>;
/// A template class to map TIM20 COM to DMA1 channel 6
using IdTim20Com = AnyID<Itf::k1, Chan::k6, PerifSel::kTim20Com>;
/// A template class to map TIM20 TRIG to DMA2 channel 7
using IdTim20Trig = AnyID<Itf::k2, Chan::k7, PerifSel::kTim20Trig>;
/// A template class to map TIM20 UP to DMA1 channel 4
using IdTim20Up = AnyID<Itf::k1, Chan::k4, PerifSel::kTim20Up>;
#endif	// TIM20_BASE

#ifdef UART4_BASE
/// A template class to map UART4 RX to DMA2 channel 5
using IdUart4Rx = AnyID<Itf::k2, Chan::k5, PerifSel::kUart4Rx>;
/// A template class to map UART4 TX to DMA2 channel 3
using IdUart4Tx = AnyID<Itf::k2, Chan::k3, PerifSel::kUart4Tx>;
#endif	// UART4_BASE

#ifdef UART5_BASE
/// A template class to map UART5 RX to DMA2 channel 2
using IdUart5Rx = AnyID<Itf::k2, Chan::k2, PerifSel::kUart5Rx>;
/// A template class to map UART5 TX to DMA2 channel 1
using IdUart5Tx = AnyID<Itf::k2, Chan::k1, PerifSel::kUart5Tx>;
#endif	// UART5_BASE

#ifdef UCPD1_BASE
/// A template class to map UCPD1 RX to DMA2 channel 5
using IdUcpd1Rx = AnyID<Itf::k2, Chan::k5, PerifSel::kUcpd1Rx>;
/// A template class to map UCPD1 TX to DMA1 channel 4
using IdUcpd1Tx = AnyID<Itf::k1, Chan::k4, PerifSel::kUcpd1Tx>;
#endif	// UCPD1_BASE

#ifdef USART1_BASE
/// A template class to map USART1 RX to DMA1 channel 5
using IdUsart1Rx = AnyID<Itf::k1, Chan::k5, PerifSel::kUsart1Rx>;
/// A template class to map USART1 RX to DMA2 channel 7 (alternate)
using IdUsart1Rx_2 = AnyID<Itf::k2, Chan::k7, PerifSel::kUsart1Rx>;
/// A template class to map USART1 TX to DMA1 channel 4
using IdUsart1Tx = AnyID<Itf::k1, Chan::k4, PerifSel::kUsart1Tx>;
/// A template class to map USART1 TX to DMA2 channel 6 (alternate)
using IdUsart1Tx_2 = AnyID<Itf::k2, Chan::k6, PerifSel::kUsart1Tx>;
#endif	// USART1_BASE

#ifdef USART2_BASE
/// A template class to map USART2 RX to DMA1 channel 6
using IdUsart2Rx = AnyID<Itf::k1, Chan::k6, PerifSel::kUsart2Rx>;
/// A template class to map USART2 TX to DMA1 channel 7
using IdUsart2Tx = AnyID<Itf::k1, Chan::k7, PerifSel::kUsart2Tx>;
#endif	// USART2_BASE

#ifdef USART3_BASE
/// A template class to map USART3 RX to DMA1 channel 3
using IdUsart3Rx = AnyID<Itf::k1, Chan::k3, PerifSel::kUsart3Rx>;
/// A template class to map USART3 TX to DMA1 channel 2
using IdUsart3Tx = AnyID<Itf::k1, Chan::k2, PerifSel::kUsart3Tx>;
#endif	// USART3_BASE


#ifdef ADC1_BASE
/// A template class to configure ADC1 with DMA transfer (DMA1 CH1)
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
/// A template class to configure ADC1 with DMA transfer (DMA2 CH3) (alternate)
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
/// A template class to configure ADC2 with DMA transfer (DMA1 CH2)
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
/// A template class to configure ADC2 with DMA transfer (DMA2 CH4) (alternate)
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
/// A template class to configure ADC3 with DMA transfer (DMA1 CH3)
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
/// A template class to configure ADC3 with DMA transfer (DMA2 CH5) (alternate)
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

#ifdef ADC4_BASE
/// A template class to configure ADC4 with DMA transfer (DMA2 CH3)
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyAdc4 : public AnyChannel <
	IdAdc4
	, kDir
	, PtrPolicy::kShortPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// ADC4_BASE

#ifdef ADC5_BASE
/// A template class to configure ADC5 with DMA transfer (DMA1 CH1)
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyAdc5 : public AnyChannel <
	IdAdc5
	, kDir
	, PtrPolicy::kShortPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// ADC5_BASE

#ifdef AES_BASE
/// A template class to configure AES IN with DMA transfer (DMA2 CH1)
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
/// A template class to configure AES IN with DMA transfer (DMA2 CH5) (alternate)
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

/// A template class to configure AES OUT with DMA transfer (DMA2 CH2)
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
/// A template class to configure AES OUT with DMA transfer (DMA2 CH3) (alternate)
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

#ifdef CORDIC_BASE
/// A template class to configure CORDIC READ with DMA transfer (DMA2 CH3)
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kLongPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kLongPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyCordicRead : public AnyChannel <
	IdCordicRead
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure CORDIC WRITE with DMA transfer (DMA1 CH1)
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kLongPtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kLongPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyCordicWrite : public AnyChannel <
	IdCordicWrite
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// CORDIC_BASE

#ifdef DAC1_BASE
/// A template class to configure DAC1 CHANNEL1 with DMA transfer (DMA1 CH3)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDac1Channel1 : public AnyChannel <
	IdDac1Channel1
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
/// A template class to configure DAC1 CHANNEL1 with DMA transfer (DMA2 CH4) (alternate)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDac1Channel1_2 : public AnyChannel <
	IdDac1Channel1_2
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure DAC1 CHANNEL2 with DMA transfer (DMA1 CH4)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDac1Channel2 : public AnyChannel <
	IdDac1Channel2
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
/// A template class to configure DAC1 CHANNEL2 with DMA transfer (DMA2 CH5) (alternate)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDac1Channel2_2 : public AnyChannel <
	IdDac1Channel2_2
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// DAC1_BASE

#ifdef DAC2_BASE
/// A template class to configure DAC2 CHANNEL1 with DMA transfer (DMA2 CH4)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDac2Channel1 : public AnyChannel <
	IdDac2Channel1
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// DAC2_BASE

#ifdef DAC3_BASE
/// A template class to configure DAC3 CHANNEL1 with DMA transfer (DMA2 CH6)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDac3Channel1 : public AnyChannel <
	IdDac3Channel1
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure DAC3 CHANNEL2 with DMA transfer (DMA2 CH4)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDac3Channel2 : public AnyChannel <
	IdDac3Channel2
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// DAC3_BASE

#ifdef DAC4_BASE
/// A template class to configure DAC4 CHANNEL1 with DMA transfer (DMA2 CH6)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDac4Channel1 : public AnyChannel <
	IdDac4Channel1
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure DAC4 CHANNEL2 with DMA transfer (DMA2 CH4)
template<
	const bool kCircular = true
	, const PtrPolicy kSrcPtr = PtrPolicy::kShortPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyDac4Channel2 : public AnyChannel <
	IdDac4Channel2
	, kCircular ? Dir::kPerToMemCircular : Dir::kPerToMem
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// DAC4_BASE

#ifdef FMAC_BASE
/// A template class to configure FMAC READ with DMA transfer (DMA2 CH6)
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kLongPtr
	, const PtrPolicy kDstPtr = PtrPolicy::kLongPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyFmacRead : public AnyChannel <
	IdFmacRead
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure FMAC WRITE with DMA transfer (DMA2 CH4)
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kLongPtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kLongPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyFmacWrite : public AnyChannel <
	IdFmacWrite
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// FMAC_BASE

#ifdef HRTIM1_BASE
/// A template class to configure HRTIM1 A with DMA transfer (DMA2 CH5)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyHrtim1A : public AnyChannel <
	IdHrtim1A
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure HRTIM1 B with DMA transfer (DMA2 CH7)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyHrtim1B : public AnyChannel <
	IdHrtim1B
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure HRTIM1 C with DMA transfer (DMA1 CH2)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyHrtim1C : public AnyChannel <
	IdHrtim1C
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure HRTIM1 D with DMA transfer (DMA1 CH6)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyHrtim1D : public AnyChannel <
	IdHrtim1D
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure HRTIM1 E with DMA transfer (DMA1 CH7)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyHrtim1E : public AnyChannel <
	IdHrtim1E
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure HRTIM1 F with DMA transfer (DMA1 CH4)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyHrtim1F : public AnyChannel <
	IdHrtim1F
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure HRTIM1 M with DMA transfer (DMA2 CH1)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyHrtim1M : public AnyChannel <
	IdHrtim1M
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// HRTIM1_BASE

#ifdef I2C1_BASE
/// A template class to configure I2C1 RX with DMA transfer (DMA1 CH7)
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
/// A template class to configure I2C1 RX with DMA transfer (DMA2 CH6) (alternate)
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

/// A template class to configure I2C1 TX with DMA transfer (DMA1 CH6)
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
/// A template class to configure I2C1 TX with DMA transfer (DMA2 CH7) (alternate)
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
/// A template class to configure I2C2 RX with DMA transfer (DMA1 CH5)
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

/// A template class to configure I2C2 TX with DMA transfer (DMA1 CH4)
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
/// A template class to configure I2C3 RX with DMA transfer (DMA1 CH3)
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

/// A template class to configure I2C3 TX with DMA transfer (DMA1 CH2)
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
/// A template class to configure I2C4 RX with DMA transfer (DMA2 CH1)
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

/// A template class to configure I2C4 TX with DMA transfer (DMA2 CH2)
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
/// A template class to configure LPUART1 RX with DMA transfer (DMA2 CH7)
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

/// A template class to configure LPUART1 TX with DMA transfer (DMA2 CH6)
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
/// A template class to configure QUADSPI with DMA transfer (DMA1 CH5)
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
/// A template class to configure QUADSPI with DMA transfer (DMA2 CH7) (alternate)
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
/// A template class to configure SAI1 A with DMA transfer (DMA2 CH1)
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
/// A template class to configure SAI1 A with DMA transfer (DMA2 CH6) (alternate)
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

/// A template class to configure SAI1 B with DMA transfer (DMA2 CH2)
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
/// A template class to configure SAI1 B with DMA transfer (DMA2 CH7) (alternate)
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

#ifdef SPI1_BASE
/// A template class to configure SPI1 RX with DMA transfer (DMA1 CH2)
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
/// A template class to configure SPI1 RX with DMA transfer (DMA2 CH3) (alternate)
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

/// A template class to configure SPI1 TX with DMA transfer (DMA1 CH3)
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
/// A template class to configure SPI1 TX with DMA transfer (DMA2 CH4) (alternate)
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
/// A template class to configure SPI2 RX with DMA transfer (DMA1 CH4)
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

/// A template class to configure SPI2 TX with DMA transfer (DMA1 CH5)
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
/// A template class to configure SPI3 RX with DMA transfer (DMA2 CH1)
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

/// A template class to configure SPI3 TX with DMA transfer (DMA2 CH2)
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

#ifdef SPI4_BASE
/// A template class to configure SPI4 RX with DMA transfer (DMA2 CH5)
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnySpi4Rx : public AnyChannel <
	IdSpi4Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure SPI4 TX with DMA transfer (DMA1 CH2)
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnySpi4Tx : public AnyChannel <
	IdSpi4Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// SPI4_BASE

#ifdef TIM1_BASE
/// A template class to configure TIM1 CH1 with DMA transfer (DMA1 CH2)
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

/// A template class to configure TIM1 CH2 with DMA transfer (DMA1 CH3)
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

/// A template class to configure TIM1 CH3 with DMA transfer (DMA1 CH7)
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

/// A template class to configure TIM1 CH4 with DMA transfer (DMA1 CH4)
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

/// A template class to configure TIM1 COM with DMA transfer (DMA1 CH4)
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

/// A template class to configure TIM1 TRIG with DMA transfer (DMA1 CH4)
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

/// A template class to configure TIM1 UP with DMA transfer (DMA1 CH6)
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
/// A template class to configure TIM2 CH1 with DMA transfer (DMA1 CH5)
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

/// A template class to configure TIM2 CH2 with DMA transfer (DMA1 CH7)
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

/// A template class to configure TIM2 CH3 with DMA transfer (DMA1 CH1)
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

/// A template class to configure TIM2 CH4 with DMA transfer (DMA1 CH7)
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

/// A template class to configure TIM2 UP with DMA transfer (DMA1 CH2)
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
/// A template class to configure TIM3 CH1 with DMA transfer (DMA1 CH6)
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

/// A template class to configure TIM3 CH2 with DMA transfer (DMA2 CH5)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim3Ch2 : public AnyChannel <
	IdTim3Ch2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM3 CH3 with DMA transfer (DMA1 CH2)
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

/// A template class to configure TIM3 CH4 with DMA transfer (DMA1 CH3)
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

/// A template class to configure TIM3 TRIG with DMA transfer (DMA1 CH6)
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

/// A template class to configure TIM3 UP with DMA transfer (DMA1 CH3)
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
/// A template class to configure TIM4 CH1 with DMA transfer (DMA1 CH1)
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

/// A template class to configure TIM4 CH2 with DMA transfer (DMA1 CH4)
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

/// A template class to configure TIM4 CH3 with DMA transfer (DMA1 CH5)
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

/// A template class to configure TIM4 CH4 with DMA transfer (DMA1 CH2)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim4Ch4 : public AnyChannel <
	IdTim4Ch4
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM4 UP with DMA transfer (DMA1 CH7)
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
/// A template class to configure TIM5 CH1 with DMA transfer (DMA2 CH5)
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

/// A template class to configure TIM5 CH2 with DMA transfer (DMA2 CH4)
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

/// A template class to configure TIM5 CH3 with DMA transfer (DMA2 CH2)
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

/// A template class to configure TIM5 CH4 with DMA transfer (DMA2 CH1)
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

/// A template class to configure TIM5 TRIG with DMA transfer (DMA2 CH1)
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

/// A template class to configure TIM5 UP with DMA transfer (DMA2 CH2)
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
/// A template class to configure TIM6 UP with DMA transfer (DMA1 CH3)
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
/// A template class to configure TIM6 UP with DMA transfer (DMA2 CH4) (alternate)
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
/// A template class to configure TIM7 UP with DMA transfer (DMA1 CH4)
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
/// A template class to configure TIM7 UP with DMA transfer (DMA2 CH5) (alternate)
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
/// A template class to configure TIM8 CH1 with DMA transfer (DMA2 CH6)
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

/// A template class to configure TIM8 CH2 with DMA transfer (DMA2 CH7)
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

/// A template class to configure TIM8 CH3 with DMA transfer (DMA2 CH1)
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

/// A template class to configure TIM8 CH4 with DMA transfer (DMA2 CH2)
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

/// A template class to configure TIM8 COM with DMA transfer (DMA2 CH2)
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

/// A template class to configure TIM8 TRIG with DMA transfer (DMA2 CH2)
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

/// A template class to configure TIM8 UP with DMA transfer (DMA2 CH1)
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
/// A template class to configure TIM15 CH1 with DMA transfer (DMA1 CH5)
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

/// A template class to configure TIM15 COM with DMA transfer (DMA1 CH5)
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

/// A template class to configure TIM15 TRIG with DMA transfer (DMA1 CH5)
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

/// A template class to configure TIM15 UP with DMA transfer (DMA1 CH5)
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
/// A template class to configure TIM16 CH1 with DMA transfer (DMA1 CH3)
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
/// A template class to configure TIM16 CH1 with DMA transfer (DMA1 CH6) (alternate)
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

/// A template class to configure TIM16 UP with DMA transfer (DMA1 CH3)
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
/// A template class to configure TIM16 UP with DMA transfer (DMA1 CH6) (alternate)
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
/// A template class to configure TIM17 CH1 with DMA transfer (DMA1 CH1)
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
/// A template class to configure TIM17 CH1 with DMA transfer (DMA1 CH7) (alternate)
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

/// A template class to configure TIM17 UP with DMA transfer (DMA1 CH1)
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
/// A template class to configure TIM17 UP with DMA transfer (DMA1 CH7) (alternate)
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

#ifdef TIM20_BASE
/// A template class to configure TIM20 CH1 with DMA transfer (DMA2 CH5)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim20Ch1 : public AnyChannel <
	IdTim20Ch1
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM20 CH2 with DMA transfer (DMA1 CH2)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim20Ch2 : public AnyChannel <
	IdTim20Ch2
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM20 CH3 with DMA transfer (DMA2 CH1)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim20Ch3 : public AnyChannel <
	IdTim20Ch3
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM20 CH4 with DMA transfer (DMA1 CH7)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim20Ch4 : public AnyChannel <
	IdTim20Ch4
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM20 COM with DMA transfer (DMA1 CH6)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim20Com : public AnyChannel <
	IdTim20Com
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM20 TRIG with DMA transfer (DMA2 CH7)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim20Trig : public AnyChannel <
	IdTim20Trig
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure TIM20 UP with DMA transfer (DMA1 CH4)
template<
	const Dir kDir
	, const PtrPolicy kSrcPtr
	, const PtrPolicy kDstPtr
	, const Prio kPrio = Prio::kMedium
>
class AnyTim20Up : public AnyChannel <
	IdTim20Up
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// TIM20_BASE

#ifdef UART4_BASE
/// A template class to configure UART4 RX with DMA transfer (DMA2 CH5)
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

/// A template class to configure UART4 TX with DMA transfer (DMA2 CH3)
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
/// A template class to configure UART5 RX with DMA transfer (DMA2 CH2)
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

/// A template class to configure UART5 TX with DMA transfer (DMA2 CH1)
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

#ifdef UCPD1_BASE
/// A template class to configure UCPD1 RX with DMA transfer (DMA2 CH5)
template<
	const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtr
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyUcpd1Rx : public AnyChannel <
	IdUcpd1Rx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };

/// A template class to configure UCPD1 TX with DMA transfer (DMA1 CH4)
template<
	const Dir kDir = Dir::kMemToPerCircular
	, const PtrPolicy kSrcPtr = PtrPolicy::kBytePtrInc
	, const PtrPolicy kDstPtr = PtrPolicy::kBytePtr
	, const Prio kPrio = Prio::kMedium
>
class AnyUcpd1Tx : public AnyChannel <
	IdUcpd1Tx
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif	// UCPD1_BASE

#ifdef USART1_BASE
/// A template class to configure USART1 RX with DMA transfer (DMA1 CH5)
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
/// A template class to configure USART1 RX with DMA transfer (DMA2 CH7) (alternate)
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

/// A template class to configure USART1 TX with DMA transfer (DMA1 CH4)
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
/// A template class to configure USART1 TX with DMA transfer (DMA2 CH6) (alternate)
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
/// A template class to configure USART2 RX with DMA transfer (DMA1 CH6)
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

/// A template class to configure USART2 TX with DMA transfer (DMA1 CH7)
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
/// A template class to configure USART3 RX with DMA transfer (DMA1 CH3)
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

/// A template class to configure USART3 TX with DMA transfer (DMA1 CH2)
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
