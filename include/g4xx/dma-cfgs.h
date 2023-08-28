#pragma once

namespace Bmt
{
namespace Dma
{


typedef AnyID<Itf::k1, Chan::kNone, PerifSel::kMem2Mem> IdNone;

/* The type definitions below are, wherever possible, based on DMA settings of STM32L4xx. */

#ifdef ADC1_BASE
/// A template class to map ADC1 to DMA1 channel 1
typedef AnyID<Itf::k1, Chan::k1, PerifSel::kAdc1> IdAdc1;
/// A template class to map ADC1 to DMA2 channel 3 (alternate)
typedef AnyID<Itf::k2, Chan::k3, PerifSel::kAdc1> IdAdc1_2;
#endif	// ADC1_BASE

#ifdef ADC2_BASE
/// A template class to map ADC2 to DMA1 channel 2
typedef AnyID<Itf::k1, Chan::k2, PerifSel::kAdc2> IdAdc2;
/// A template class to map ADC2 to DMA2 channel 4 (alternate)
typedef AnyID<Itf::k2, Chan::k4, PerifSel::kAdc2> IdAdc2_2;
#endif	// ADC2_BASE

#ifdef ADC3_BASE
/// A template class to map ADC3 to DMA1 channel 3
typedef AnyID<Itf::k1, Chan::k3, PerifSel::kAdc3> IdAdc3;
/// A template class to map ADC3 to DMA2 channel 5 (alternate)
typedef AnyID<Itf::k2, Chan::k5, PerifSel::kAdc3> IdAdc3_2;
#endif	// ADC3_BASE

#ifdef ADC4_BASE
/// A template class to map ADC4 to DMA2 channel 3
typedef AnyID<Itf::k2, Chan::k3, PerifSel::kAdc4> IdAdc4;
#endif	// ADC4_BASE

#ifdef ADC5_BASE
/// A template class to map ADC5 to DMA1 channel 1
typedef AnyID<Itf::k1, Chan::k1, PerifSel::kAdc5> IdAdc5;
#endif	// ADC5_BASE

#ifdef AES_BASE
/// A template class to map AES IN to DMA2 channel 1
typedef AnyID<Itf::k2, Chan::k1, PerifSel::kAesIn> IdAesIn;
/// A template class to map AES IN to DMA2 channel 5 (alternate)
typedef AnyID<Itf::k2, Chan::k5, PerifSel::kAesIn> IdAesIn_2;
/// A template class to map AES OUT to DMA2 channel 2
typedef AnyID<Itf::k2, Chan::k2, PerifSel::kAesOut> IdAesOut;
/// A template class to map AES OUT to DMA2 channel 3 (alternate)
typedef AnyID<Itf::k2, Chan::k3, PerifSel::kAesOut> IdAesOut_2;
#endif	// AES_BASE

#ifdef CORDIC_BASE
/// A template class to map CORDIC READ to DMA2 channel 3
typedef AnyID<Itf::k2, Chan::k3, PerifSel::kCordicRead> IdCordicRead;
/// A template class to map CORDIC WRITE to DMA1 channel 1
typedef AnyID<Itf::k1, Chan::k1, PerifSel::kCordicWrite> IdCordicWrite;
#endif	// CORDIC_BASE

#ifdef DAC1_BASE
/// A template class to map DAC1 CHANNEL1 to DMA1 channel 3
typedef AnyID<Itf::k1, Chan::k3, PerifSel::kDac1Channel1> IdDac1Channel1;
/// A template class to map DAC1 CHANNEL1 to DMA2 channel 4 (alternate)
typedef AnyID<Itf::k2, Chan::k4, PerifSel::kDac1Channel1> IdDac1Channel1_2;
/// A template class to map DAC1 CHANNEL2 to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kDac1Channel2> IdDac1Channel2;
/// A template class to map DAC1 CHANNEL2 to DMA2 channel 5 (alternate)
typedef AnyID<Itf::k2, Chan::k5, PerifSel::kDac1Channel2> IdDac1Channel2_2;
#endif	// DAC1_BASE

#ifdef DAC2_BASE
/// A template class to map DAC2 CHANNEL1 to DMA2 channel 4
typedef AnyID<Itf::k2, Chan::k4, PerifSel::kDac2Channel1> IdDac2Channel1;
#endif	// DAC2_BASE

#ifdef DAC3_BASE
/// A template class to map DAC3 CHANNEL1 to DMA2 channel 6
typedef AnyID<Itf::k2, Chan::k6, PerifSel::kDac3Channel1> IdDac3Channel1;
/// A template class to map DAC3 CHANNEL2 to DMA2 channel 4
typedef AnyID<Itf::k2, Chan::k4, PerifSel::kDac3Channel2> IdDac3Channel2;
#endif	// DAC3_BASE

#ifdef DAC4_BASE
/// A template class to map DAC4 CHANNEL1 to DMA2 channel 6
typedef AnyID<Itf::k2, Chan::k6, PerifSel::kDac4Channel1> IdDac4Channel1;
/// A template class to map DAC4 CHANNEL2 to DMA2 channel 4
typedef AnyID<Itf::k2, Chan::k4, PerifSel::kDac4Channel2> IdDac4Channel2;
#endif	// DAC4_BASE

#ifdef FMAC_BASE
/// A template class to map FMAC READ to DMA2 channel 6
typedef AnyID<Itf::k2, Chan::k6, PerifSel::kFmacRead> IdFmacRead;
/// A template class to map FMAC WRITE to DMA2 channel 4
typedef AnyID<Itf::k2, Chan::k4, PerifSel::kFmacWrite> IdFmacWrite;
#endif	// FMAC_BASE

/// A template class to map GENERATOR0 to DMA2 channel 6
typedef AnyID<Itf::k2, Chan::k6, PerifSel::kGenerator0> IdGenerator0;
/// A template class to map GENERATOR1 to DMA2 channel 4
typedef AnyID<Itf::k2, Chan::k4, PerifSel::kGenerator1> IdGenerator1;
/// A template class to map GENERATOR2 to DMA1 channel 1
typedef AnyID<Itf::k1, Chan::k1, PerifSel::kGenerator2> IdGenerator2;
/// A template class to map GENERATOR3 to DMA2 channel 3
typedef AnyID<Itf::k2, Chan::k3, PerifSel::kGenerator3> IdGenerator3;

#ifdef HRTIM1_BASE
/// A template class to map HRTIM1 A to DMA2 channel 5
typedef AnyID<Itf::k2, Chan::k5, PerifSel::kHrtim1A> IdHrtim1A;
/// A template class to map HRTIM1 B to DMA2 channel 7
typedef AnyID<Itf::k2, Chan::k7, PerifSel::kHrtim1B> IdHrtim1B;
/// A template class to map HRTIM1 C to DMA1 channel 2
typedef AnyID<Itf::k1, Chan::k2, PerifSel::kHrtim1C> IdHrtim1C;
/// A template class to map HRTIM1 D to DMA1 channel 6
typedef AnyID<Itf::k1, Chan::k6, PerifSel::kHrtim1D> IdHrtim1D;
/// A template class to map HRTIM1 E to DMA1 channel 7
typedef AnyID<Itf::k1, Chan::k7, PerifSel::kHrtim1E> IdHrtim1E;
/// A template class to map HRTIM1 F to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kHrtim1F> IdHrtim1F;
/// A template class to map HRTIM1 M to DMA2 channel 1
typedef AnyID<Itf::k2, Chan::k1, PerifSel::kHrtim1M> IdHrtim1M;
#endif	// HRTIM1_BASE

#ifdef I2C1_BASE
/// A template class to map I2C1 RX to DMA1 channel 7
typedef AnyID<Itf::k1, Chan::k7, PerifSel::kI2c1Rx> IdI2c1Rx;
/// A template class to map I2C1 RX to DMA2 channel 6 (alternate)
typedef AnyID<Itf::k2, Chan::k6, PerifSel::kI2c1Rx> IdI2c1Rx_2;
/// A template class to map I2C1 TX to DMA1 channel 6
typedef AnyID<Itf::k1, Chan::k6, PerifSel::kI2c1Tx> IdI2c1Tx;
/// A template class to map I2C1 TX to DMA2 channel 7 (alternate)
typedef AnyID<Itf::k2, Chan::k7, PerifSel::kI2c1Tx> IdI2c1Tx_2;
#endif	// I2C1_BASE

#ifdef I2C2_BASE
/// A template class to map I2C2 RX to DMA1 channel 5
typedef AnyID<Itf::k1, Chan::k5, PerifSel::kI2c2Rx> IdI2c2Rx;
/// A template class to map I2C2 TX to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kI2c2Tx> IdI2c2Tx;
#endif	// I2C2_BASE

#ifdef I2C3_BASE
/// A template class to map I2C3 RX to DMA1 channel 3
typedef AnyID<Itf::k1, Chan::k3, PerifSel::kI2c3Rx> IdI2c3Rx;
/// A template class to map I2C3 TX to DMA1 channel 2
typedef AnyID<Itf::k1, Chan::k2, PerifSel::kI2c3Tx> IdI2c3Tx;
#endif	// I2C3_BASE

#ifdef I2C4_BASE
/// A template class to map I2C4 RX to DMA2 channel 1
typedef AnyID<Itf::k2, Chan::k1, PerifSel::kI2c4Rx> IdI2c4Rx;
/// A template class to map I2C4 TX to DMA2 channel 2
typedef AnyID<Itf::k2, Chan::k2, PerifSel::kI2c4Tx> IdI2c4Tx;
#endif	// I2C4_BASE

#ifdef LPUART1_BASE
/// A template class to map LPUART1 RX to DMA2 channel 7
typedef AnyID<Itf::k2, Chan::k7, PerifSel::kLpuart1Rx> IdLpuart1Rx;
/// A template class to map LPUART1 TX to DMA2 channel 6
typedef AnyID<Itf::k2, Chan::k6, PerifSel::kLpuart1Tx> IdLpuart1Tx;
#endif	// LPUART1_BASE

/// A template class to map MEM2MEM to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kMem2Mem> IdMem2Mem;

#ifdef QUADSPI_BASE
/// A template class to map QUADSPI to DMA1 channel 5
typedef AnyID<Itf::k1, Chan::k5, PerifSel::kQuadspi> IdQuadspi;
/// A template class to map QUADSPI to DMA2 channel 7 (alternate)
typedef AnyID<Itf::k2, Chan::k7, PerifSel::kQuadspi> IdQuadspi_2;
#endif	// QUADSPI_BASE

#ifdef SAI1_BASE
/// A template class to map SAI1 A to DMA2 channel 1
typedef AnyID<Itf::k2, Chan::k1, PerifSel::kSai1A> IdSai1A;
/// A template class to map SAI1 A to DMA2 channel 6 (alternate)
typedef AnyID<Itf::k2, Chan::k6, PerifSel::kSai1A> IdSai1A_2;
/// A template class to map SAI1 B to DMA2 channel 2
typedef AnyID<Itf::k2, Chan::k2, PerifSel::kSai1B> IdSai1B;
/// A template class to map SAI1 B to DMA2 channel 7 (alternate)
typedef AnyID<Itf::k2, Chan::k7, PerifSel::kSai1B> IdSai1B_2;
#endif	// SAI1_BASE

#ifdef SPI1_BASE
/// A template class to map SPI1 RX to DMA1 channel 2
typedef AnyID<Itf::k1, Chan::k2, PerifSel::kSpi1Rx> IdSpi1Rx;
/// A template class to map SPI1 RX to DMA2 channel 3 (alternate)
typedef AnyID<Itf::k2, Chan::k3, PerifSel::kSpi1Rx> IdSpi1Rx_2;
/// A template class to map SPI1 TX to DMA1 channel 3
typedef AnyID<Itf::k1, Chan::k3, PerifSel::kSpi1Tx> IdSpi1Tx;
/// A template class to map SPI1 TX to DMA2 channel 4 (alternate)
typedef AnyID<Itf::k2, Chan::k4, PerifSel::kSpi1Tx> IdSpi1Tx_2;
#endif	// SPI1_BASE

#ifdef SPI2_BASE
/// A template class to map SPI2 RX to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kSpi2Rx> IdSpi2Rx;
/// A template class to map SPI2 TX to DMA1 channel 5
typedef AnyID<Itf::k1, Chan::k5, PerifSel::kSpi2Tx> IdSpi2Tx;
#endif	// SPI2_BASE

#ifdef SPI3_BASE
/// A template class to map SPI3 RX to DMA2 channel 1
typedef AnyID<Itf::k2, Chan::k1, PerifSel::kSpi3Rx> IdSpi3Rx;
/// A template class to map SPI3 TX to DMA2 channel 2
typedef AnyID<Itf::k2, Chan::k2, PerifSel::kSpi3Tx> IdSpi3Tx;
#endif	// SPI3_BASE

#ifdef SPI4_BASE
/// A template class to map SPI4 RX to DMA2 channel 5
typedef AnyID<Itf::k2, Chan::k5, PerifSel::kSpi4Rx> IdSpi4Rx;
/// A template class to map SPI4 TX to DMA1 channel 2
typedef AnyID<Itf::k1, Chan::k2, PerifSel::kSpi4Tx> IdSpi4Tx;
#endif	// SPI4_BASE

#ifdef TIM1_BASE
/// A template class to map TIM1 CH1 to DMA1 channel 2
typedef AnyID<Itf::k1, Chan::k2, PerifSel::kTim1Ch1> IdTim1Ch1;
/// A template class to map TIM1 CH2 to DMA1 channel 3
typedef AnyID<Itf::k1, Chan::k3, PerifSel::kTim1Ch2> IdTim1Ch2;
/// A template class to map TIM1 CH3 to DMA1 channel 7
typedef AnyID<Itf::k1, Chan::k7, PerifSel::kTim1Ch3> IdTim1Ch3;
/// A template class to map TIM1 CH4 to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kTim1Ch4> IdTim1Ch4;
/// A template class to map TIM1 COM to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kTim1Com> IdTim1Com;
/// A template class to map TIM1 TRIG to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kTim1Trig> IdTim1Trig;
/// A template class to map TIM1 UP to DMA1 channel 6
typedef AnyID<Itf::k1, Chan::k6, PerifSel::kTim1Up> IdTim1Up;
#endif	// TIM1_BASE

#ifdef TIM2_BASE
/// A template class to map TIM2 CH1 to DMA1 channel 5
typedef AnyID<Itf::k1, Chan::k5, PerifSel::kTim2Ch1> IdTim2Ch1;
/// A template class to map TIM2 CH2 to DMA1 channel 7
typedef AnyID<Itf::k1, Chan::k7, PerifSel::kTim2Ch2> IdTim2Ch2;
/// A template class to map TIM2 CH3 to DMA1 channel 1
typedef AnyID<Itf::k1, Chan::k1, PerifSel::kTim2Ch3> IdTim2Ch3;
/// A template class to map TIM2 CH4 to DMA1 channel 7
typedef AnyID<Itf::k1, Chan::k7, PerifSel::kTim2Ch4> IdTim2Ch4;
/// A template class to map TIM2 UP to DMA1 channel 2
typedef AnyID<Itf::k1, Chan::k2, PerifSel::kTim2Up> IdTim2Up;
#endif	// TIM2_BASE

#ifdef TIM3_BASE
/// A template class to map TIM3 CH1 to DMA1 channel 6
typedef AnyID<Itf::k1, Chan::k6, PerifSel::kTim3Ch1> IdTim3Ch1;
/// A template class to map TIM3 CH2 to DMA2 channel 5
typedef AnyID<Itf::k2, Chan::k5, PerifSel::kTim3Ch2> IdTim3Ch2;
/// A template class to map TIM3 CH3 to DMA1 channel 2
typedef AnyID<Itf::k1, Chan::k2, PerifSel::kTim3Ch3> IdTim3Ch3;
/// A template class to map TIM3 CH4 to DMA1 channel 3
typedef AnyID<Itf::k1, Chan::k3, PerifSel::kTim3Ch4> IdTim3Ch4;
/// A template class to map TIM3 TRIG to DMA1 channel 6
typedef AnyID<Itf::k1, Chan::k6, PerifSel::kTim3Trig> IdTim3Trig;
/// A template class to map TIM3 UP to DMA1 channel 3
typedef AnyID<Itf::k1, Chan::k3, PerifSel::kTim3Up> IdTim3Up;
#endif	// TIM3_BASE

#ifdef TIM4_BASE
/// A template class to map TIM4 CH1 to DMA1 channel 1
typedef AnyID<Itf::k1, Chan::k1, PerifSel::kTim4Ch1> IdTim4Ch1;
/// A template class to map TIM4 CH2 to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kTim4Ch2> IdTim4Ch2;
/// A template class to map TIM4 CH3 to DMA1 channel 5
typedef AnyID<Itf::k1, Chan::k5, PerifSel::kTim4Ch3> IdTim4Ch3;
/// A template class to map TIM4 CH4 to DMA1 channel 2
typedef AnyID<Itf::k1, Chan::k2, PerifSel::kTim4Ch4> IdTim4Ch4;
/// A template class to map TIM4 UP to DMA1 channel 7
typedef AnyID<Itf::k1, Chan::k7, PerifSel::kTim4Up> IdTim4Up;
#endif	// TIM4_BASE

#ifdef TIM5_BASE
/// A template class to map TIM5 CH1 to DMA2 channel 5
typedef AnyID<Itf::k2, Chan::k5, PerifSel::kTim5Ch1> IdTim5Ch1;
/// A template class to map TIM5 CH2 to DMA2 channel 4
typedef AnyID<Itf::k2, Chan::k4, PerifSel::kTim5Ch2> IdTim5Ch2;
/// A template class to map TIM5 CH3 to DMA2 channel 2
typedef AnyID<Itf::k2, Chan::k2, PerifSel::kTim5Ch3> IdTim5Ch3;
/// A template class to map TIM5 CH4 to DMA2 channel 1
typedef AnyID<Itf::k2, Chan::k1, PerifSel::kTim5Ch4> IdTim5Ch4;
/// A template class to map TIM5 TRIG to DMA2 channel 1
typedef AnyID<Itf::k2, Chan::k1, PerifSel::kTim5Trig> IdTim5Trig;
/// A template class to map TIM5 UP to DMA2 channel 2
typedef AnyID<Itf::k2, Chan::k2, PerifSel::kTim5Up> IdTim5Up;
#endif	// TIM5_BASE

#ifdef TIM6_BASE
/// A template class to map TIM6 UP to DMA1 channel 3
typedef AnyID<Itf::k1, Chan::k3, PerifSel::kTim6Up> IdTim6Up;
/// A template class to map TIM6 UP to DMA2 channel 4 (alternate)
typedef AnyID<Itf::k2, Chan::k4, PerifSel::kTim6Up> IdTim6Up_2;
#endif	// TIM6_BASE

#ifdef TIM7_BASE
/// A template class to map TIM7 UP to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kTim7Up> IdTim7Up;
/// A template class to map TIM7 UP to DMA2 channel 5 (alternate)
typedef AnyID<Itf::k2, Chan::k5, PerifSel::kTim7Up> IdTim7Up_2;
#endif	// TIM7_BASE

#ifdef TIM8_BASE
/// A template class to map TIM8 CH1 to DMA2 channel 6
typedef AnyID<Itf::k2, Chan::k6, PerifSel::kTim8Ch1> IdTim8Ch1;
/// A template class to map TIM8 CH2 to DMA2 channel 7
typedef AnyID<Itf::k2, Chan::k7, PerifSel::kTim8Ch2> IdTim8Ch2;
/// A template class to map TIM8 CH3 to DMA2 channel 1
typedef AnyID<Itf::k2, Chan::k1, PerifSel::kTim8Ch3> IdTim8Ch3;
/// A template class to map TIM8 CH4 to DMA2 channel 2
typedef AnyID<Itf::k2, Chan::k2, PerifSel::kTim8Ch4> IdTim8Ch4;
/// A template class to map TIM8 COM to DMA2 channel 2
typedef AnyID<Itf::k2, Chan::k2, PerifSel::kTim8Com> IdTim8Com;
/// A template class to map TIM8 TRIG to DMA2 channel 2
typedef AnyID<Itf::k2, Chan::k2, PerifSel::kTim8Trig> IdTim8Trig;
/// A template class to map TIM8 UP to DMA2 channel 1
typedef AnyID<Itf::k2, Chan::k1, PerifSel::kTim8Up> IdTim8Up;
#endif	// TIM8_BASE

#ifdef TIM15_BASE
/// A template class to map TIM15 CH1 to DMA1 channel 5
typedef AnyID<Itf::k1, Chan::k5, PerifSel::kTim15Ch1> IdTim15Ch1;
/// A template class to map TIM15 COM to DMA1 channel 5
typedef AnyID<Itf::k1, Chan::k5, PerifSel::kTim15Com> IdTim15Com;
/// A template class to map TIM15 TRIG to DMA1 channel 5
typedef AnyID<Itf::k1, Chan::k5, PerifSel::kTim15Trig> IdTim15Trig;
/// A template class to map TIM15 UP to DMA1 channel 5
typedef AnyID<Itf::k1, Chan::k5, PerifSel::kTim15Up> IdTim15Up;
#endif	// TIM15_BASE

#ifdef TIM16_BASE
/// A template class to map TIM16 CH1 to DMA1 channel 3
typedef AnyID<Itf::k1, Chan::k3, PerifSel::kTim16Ch1> IdTim16Ch1;
/// A template class to map TIM16 CH1 to DMA1 channel 6 (alternate)
typedef AnyID<Itf::k1, Chan::k6, PerifSel::kTim16Ch1> IdTim16Ch1_2;
/// A template class to map TIM16 UP to DMA1 channel 3
typedef AnyID<Itf::k1, Chan::k3, PerifSel::kTim16Up> IdTim16Up;
/// A template class to map TIM16 UP to DMA1 channel 6 (alternate)
typedef AnyID<Itf::k1, Chan::k6, PerifSel::kTim16Up> IdTim16Up_2;
#endif	// TIM16_BASE

#ifdef TIM17_BASE
/// A template class to map TIM17 CH1 to DMA1 channel 1
typedef AnyID<Itf::k1, Chan::k1, PerifSel::kTim17Ch1> IdTim17Ch1;
/// A template class to map TIM17 CH1 to DMA1 channel 7 (alternate)
typedef AnyID<Itf::k1, Chan::k7, PerifSel::kTim17Ch1> IdTim17Ch1_2;
/// A template class to map TIM17 UP to DMA1 channel 1
typedef AnyID<Itf::k1, Chan::k1, PerifSel::kTim17Up> IdTim17Up;
/// A template class to map TIM17 UP to DMA1 channel 7 (alternate)
typedef AnyID<Itf::k1, Chan::k7, PerifSel::kTim17Up> IdTim17Up_2;
#endif	// TIM17_BASE

#ifdef TIM20_BASE
/// A template class to map TIM20 CH1 to DMA2 channel 5
typedef AnyID<Itf::k2, Chan::k5, PerifSel::kTim20Ch1> IdTim20Ch1;
/// A template class to map TIM20 CH2 to DMA1 channel 2
typedef AnyID<Itf::k1, Chan::k2, PerifSel::kTim20Ch2> IdTim20Ch2;
/// A template class to map TIM20 CH3 to DMA2 channel 1
typedef AnyID<Itf::k2, Chan::k1, PerifSel::kTim20Ch3> IdTim20Ch3;
/// A template class to map TIM20 CH4 to DMA1 channel 7
typedef AnyID<Itf::k1, Chan::k7, PerifSel::kTim20Ch4> IdTim20Ch4;
/// A template class to map TIM20 COM to DMA1 channel 6
typedef AnyID<Itf::k1, Chan::k6, PerifSel::kTim20Com> IdTim20Com;
/// A template class to map TIM20 TRIG to DMA2 channel 7
typedef AnyID<Itf::k2, Chan::k7, PerifSel::kTim20Trig> IdTim20Trig;
/// A template class to map TIM20 UP to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kTim20Up> IdTim20Up;
#endif	// TIM20_BASE

#ifdef UART4_BASE
/// A template class to map UART4 RX to DMA2 channel 5
typedef AnyID<Itf::k2, Chan::k5, PerifSel::kUart4Rx> IdUart4Rx;
/// A template class to map UART4 TX to DMA2 channel 3
typedef AnyID<Itf::k2, Chan::k3, PerifSel::kUart4Tx> IdUart4Tx;
#endif	// UART4_BASE

#ifdef UART5_BASE
/// A template class to map UART5 RX to DMA2 channel 2
typedef AnyID<Itf::k2, Chan::k2, PerifSel::kUart5Rx> IdUart5Rx;
/// A template class to map UART5 TX to DMA2 channel 1
typedef AnyID<Itf::k2, Chan::k1, PerifSel::kUart5Tx> IdUart5Tx;
#endif	// UART5_BASE

#ifdef UCPD1_BASE
/// A template class to map UCPD1 RX to DMA2 channel 5
typedef AnyID<Itf::k2, Chan::k5, PerifSel::kUcpd1Rx> IdUcpd1Rx;
/// A template class to map UCPD1 TX to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kUcpd1Tx> IdUcpd1Tx;
#endif	// UCPD1_BASE

#ifdef USART1_BASE
/// A template class to map USART1 RX to DMA1 channel 5
typedef AnyID<Itf::k1, Chan::k5, PerifSel::kUsart1Rx> IdUsart1Rx;
/// A template class to map USART1 RX to DMA2 channel 7 (alternate)
typedef AnyID<Itf::k2, Chan::k7, PerifSel::kUsart1Rx> IdUsart1Rx_2;
/// A template class to map USART1 TX to DMA1 channel 4
typedef AnyID<Itf::k1, Chan::k4, PerifSel::kUsart1Tx> IdUsart1Tx;
/// A template class to map USART1 TX to DMA2 channel 6 (alternate)
typedef AnyID<Itf::k2, Chan::k6, PerifSel::kUsart1Tx> IdUsart1Tx_2;
#endif	// USART1_BASE

#ifdef USART2_BASE
/// A template class to map USART2 RX to DMA1 channel 6
typedef AnyID<Itf::k1, Chan::k6, PerifSel::kUsart2Rx> IdUsart2Rx;
/// A template class to map USART2 TX to DMA1 channel 7
typedef AnyID<Itf::k1, Chan::k7, PerifSel::kUsart2Tx> IdUsart2Tx;
#endif	// USART2_BASE

#ifdef USART3_BASE
/// A template class to map USART3 RX to DMA1 channel 3
typedef AnyID<Itf::k1, Chan::k3, PerifSel::kUsart3Rx> IdUsart3Rx;
/// A template class to map USART3 TX to DMA1 channel 2
typedef AnyID<Itf::k1, Chan::k2, PerifSel::kUsart3Tx> IdUsart3Tx;
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
