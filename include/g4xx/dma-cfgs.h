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


typedef AnyID<Itf::k1, Chan::kNone, PerifSel::kMem2Mem> IdNone;

#if 0
template<
	const Itf kItf
	, const Chan kChan
	, const Dir kDir = Dir::kPerToMemCircular
	, const PtrPolicy kDstPtr = PtrPolicy::kShortPtrInc
	, const Prio kPrio = Prio::kMedium
>
class AnyAdc1 : public AnyChannel<
	AnyID<kItf, kChan, kAdc1>
	, kDir
	, kSrcPtr
	, kDstPtr
	, kPrio
>
{ };
#endif

}	// namespace Dma
}	// namespace Bmt
