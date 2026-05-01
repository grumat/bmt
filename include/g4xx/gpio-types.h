#pragma once

#include "pinremap.h"

namespace Bmt
{
namespace Gpio
{


//////////////////////////////////////////////////////////////////////
// SYS
//////////////////////////////////////////////////////////////////////
/// A default configuration to map MCO on PA8 pin
using MCO_PA8 = AnyAltOut<Port::PA, 8, AfMCO_PA8>;
#if defined(GPIOG_BASE)
/// A default configuration to map MCO on PG10 pin
using MCO_PG10 = AnyAltOut<Port::PG, 10, AfMCO_PG10>;
#endif	// defined(GPIOG_BASE)

/// A default configuration to map JTCK on PA14 pin
using JTCK_PA14 = AnyAltOut<Port::PA, 14, AfJTCK_PA14, Speed::kFast, Level::kLow, PuPd::kPullDown>;
/// A default configuration to map JTDI on PA15 pin
using JTDI_PA15 = AnyAltOut<Port::PA, 15, AfJTDI_PA15, Speed::kFast, Level::kLow, PuPd::kPullUp>;
/// A default configuration to map JTDO on PB3 pin
using JTDO_PB3 = AnyAltOut<Port::PB, 3, AfJTDO_PB3, Speed::kFast>;
/// A default configuration to map JTMS on PA13 pin
using JTMS_PA13 = AnyAltOut<Port::PA, 13, AfJTMS_PA13, Speed::kFastest, Level::kLow, PuPd::kPullUp>;
/// A default configuration to map JTRST on PB4 pin
using JTRST_PB4 = AnyAltOut<Port::PB, 4, AfJTRST_PB4, Speed::kSlow, Level::kLow, PuPd::kPullUp>;
/// A default configuration to map TRACESWO on PB3 pin
using TRACESWO_PB3 = AnyAltOut<Port::PB, 3, AfTRACESWO_PB3, Speed::kFast>;

#if defined(GPIOE_BASE)
/// A default configuration to map TRACECK on PE2 pin
using TRACECK_PE2 = AnyAltOut<Port::PE, 2, AfTRACECK_PE2, Speed::kFast>;
/// A default configuration to map TRACED0 on PE3 pin
using TRACED0_PE3 = AnyAltOut<Port::PE, 3, AfTRACED0_PE3, Speed::kFast>;
/// A default configuration to map TRACED1 on PE4 pin
using TRACED1_PE4 = AnyAltOut<Port::PE, 4, AfTRACED1_PE4, Speed::kFast>;
/// A default configuration to map TRACED2 on PE5 pin
using TRACED2_PE5 = AnyAltOut<Port::PE, 5, AfTRACED2_PE5, Speed::kFast>;
/// A default configuration to map TRACED3 on PE6 pin
using TRACED3_PE6 = AnyAltOut<Port::PE, 6, AfTRACED3_PE6, Speed::kFast>;
#endif	// defined(GPIOE_BASE)

/// A default configuration to map SWCLK on PA14 pin
using SWCLK_PA14 = AnyAltOut<Port::PA, 14, AfSWCLK_PA14, Speed::kFast, Level::kLow, PuPd::kPullDown>;
/// A default configuration to map SWDIO on PA13 pin
using SWDIO_PA13 = AnyAltOut<Port::PA, 13, AfSWDIO_PA13, Speed::kFastest, Level::kLow, PuPd::kPullUp>;

//////////////////////////////////////////////////////////////////////
// ADC1
//////////////////////////////////////////////////////////////////////
#if defined(ADC1_BASE)
/// A default configuration to map ADC1 IN1 on PA0 pin
using ADC1_IN1_PA0 = AnyAnalog<Port::PA, 0>;
/// A default configuration to map ADC1 IN11 on PB12 pin
using ADC1_IN11_PB12 = AnyAnalog<Port::PB, 12>;
/// A default configuration to map ADC1 IN12 on PB1 pin
using ADC1_IN12_PB1 = AnyAnalog<Port::PB, 1>;
/// A default configuration to map ADC1 IN14 on PB11 pin
using ADC1_IN14_PB11 = AnyAnalog<Port::PB, 11>;
/// A default configuration to map ADC1 IN15 on PB0 pin
using ADC1_IN15_PB0 = AnyAnalog<Port::PB, 0>;
/// A default configuration to map ADC1 IN2 on PA1 pin
using ADC1_IN2_PA1 = AnyAnalog<Port::PA, 1>;
/// A default configuration to map ADC1 IN3 on PA2 pin
using ADC1_IN3_PA2 = AnyAnalog<Port::PA, 2>;
/// A default configuration to map ADC1 IN4 on PA3 pin
using ADC1_IN4_PA3 = AnyAnalog<Port::PA, 3>;
/// A default configuration to map ADC1 IN5 on PB14 pin
using ADC1_IN5_PB14 = AnyAnalog<Port::PB, 14>;
/// A default configuration to map ADC1 IN6 on PC0 pin
using ADC1_IN6_PC0 = AnyAnalog<Port::PC, 0>;
/// A default configuration to map ADC1 IN7 on PC1 pin
using ADC1_IN7_PC1 = AnyAnalog<Port::PC, 1>;
/// A default configuration to map ADC1 IN8 on PC2 pin
using ADC1_IN8_PC2 = AnyAnalog<Port::PC, 2>;
/// A default configuration to map ADC1 IN9 on PC3 pin
using ADC1_IN9_PC3 = AnyAnalog<Port::PC, 3>;
#if defined(GPIOF_BASE)
/// A default configuration to map ADC1 IN10 on PF0 pin
using ADC1_IN10_PF0 = AnyAnalog<Port::PF, 0>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(ADC1_BASE)

//////////////////////////////////////////////////////////////////////
// ADC2
//////////////////////////////////////////////////////////////////////
#if defined(ADC2_BASE)
/// A default configuration to map ADC2 IN1 on PA0 pin
using ADC2_IN1_PA0 = AnyAnalog<Port::PA, 0>;
/// A default configuration to map ADC2 IN11 on PC5 pin
using ADC2_IN11_PC5 = AnyAnalog<Port::PC, 5>;
/// A default configuration to map ADC2 IN12 on PB2 pin
using ADC2_IN12_PB2 = AnyAnalog<Port::PB, 2>;
/// A default configuration to map ADC2 IN13 on PA5 pin
using ADC2_IN13_PA5 = AnyAnalog<Port::PA, 5>;
/// A default configuration to map ADC2 IN14 on PB11 pin
using ADC2_IN14_PB11 = AnyAnalog<Port::PB, 11>;
/// A default configuration to map ADC2 IN15 on PB15 pin
using ADC2_IN15_PB15 = AnyAnalog<Port::PB, 15>;
/// A default configuration to map ADC2 IN17 on PA4 pin
using ADC2_IN17_PA4 = AnyAnalog<Port::PA, 4>;
/// A default configuration to map ADC2 IN2 on PA1 pin
using ADC2_IN2_PA1 = AnyAnalog<Port::PA, 1>;
/// A default configuration to map ADC2 IN3 on PA6 pin
using ADC2_IN3_PA6 = AnyAnalog<Port::PA, 6>;
/// A default configuration to map ADC2 IN4 on PA7 pin
using ADC2_IN4_PA7 = AnyAnalog<Port::PA, 7>;
/// A default configuration to map ADC2 IN5 on PC4 pin
using ADC2_IN5_PC4 = AnyAnalog<Port::PC, 4>;
/// A default configuration to map ADC2 IN6 on PC0 pin
using ADC2_IN6_PC0 = AnyAnalog<Port::PC, 0>;
/// A default configuration to map ADC2 IN7 on PC1 pin
using ADC2_IN7_PC1 = AnyAnalog<Port::PC, 1>;
/// A default configuration to map ADC2 IN8 on PC2 pin
using ADC2_IN8_PC2 = AnyAnalog<Port::PC, 2>;
/// A default configuration to map ADC2 IN9 on PC3 pin
using ADC2_IN9_PC3 = AnyAnalog<Port::PC, 3>;
#if defined(GPIOF_BASE)
/// A default configuration to map ADC2 IN10 on PF1 pin
using ADC2_IN10_PF1 = AnyAnalog<Port::PF, 1>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(ADC2_BASE)

//////////////////////////////////////////////////////////////////////
// ADC3
//////////////////////////////////////////////////////////////////////
#if defined(ADC3_BASE)
/// A default configuration to map ADC3 IN1 on PB1 pin
using ADC3_IN1_PB1 = AnyAnalog<Port::PB, 1>;
/// A default configuration to map ADC3 IN12 on PB0 pin
using ADC3_IN12_PB0 = AnyAnalog<Port::PB, 0>;
/// A default configuration to map ADC3 IN5 on PB13 pin
using ADC3_IN5_PB13 = AnyAnalog<Port::PB, 13>;
#if defined(GPIOD_BASE)
/// A default configuration to map ADC3 IN10 on PD13 pin
using ADC3_IN10_PD13 = AnyAnalog<Port::PD, 13>;
/// A default configuration to map ADC3 IN11 on PD14 pin
using ADC3_IN11_PD14 = AnyAnalog<Port::PD, 14>;
/// A default configuration to map ADC3 IN7 on PD10 pin
using ADC3_IN7_PD10 = AnyAnalog<Port::PD, 10>;
/// A default configuration to map ADC3 IN8 on PD11 pin
using ADC3_IN8_PD11 = AnyAnalog<Port::PD, 11>;
/// A default configuration to map ADC3 IN9 on PD12 pin
using ADC3_IN9_PD12 = AnyAnalog<Port::PD, 12>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map ADC3 IN14 on PE10 pin
using ADC3_IN14_PE10 = AnyAnalog<Port::PE, 10>;
/// A default configuration to map ADC3 IN15 on PE11 pin
using ADC3_IN15_PE11 = AnyAnalog<Port::PE, 11>;
/// A default configuration to map ADC3 IN16 on PE12 pin
using ADC3_IN16_PE12 = AnyAnalog<Port::PE, 12>;
/// A default configuration to map ADC3 IN2 on PE9 pin
using ADC3_IN2_PE9 = AnyAnalog<Port::PE, 9>;
/// A default configuration to map ADC3 IN3 on PE13 pin
using ADC3_IN3_PE13 = AnyAnalog<Port::PE, 13>;
/// A default configuration to map ADC3 IN4 on PE7 pin
using ADC3_IN4_PE7 = AnyAnalog<Port::PE, 7>;
/// A default configuration to map ADC3 IN6 on PE8 pin
using ADC3_IN6_PE8 = AnyAnalog<Port::PE, 8>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(ADC3_BASE)

//////////////////////////////////////////////////////////////////////
// ADC4
//////////////////////////////////////////////////////////////////////
#if defined(ADC4_BASE)
/// A default configuration to map ADC4 IN3 on PB12 pin
using ADC4_IN3_PB12 = AnyAnalog<Port::PB, 12>;
/// A default configuration to map ADC4 IN4 on PB14 pin
using ADC4_IN4_PB14 = AnyAnalog<Port::PB, 14>;
/// A default configuration to map ADC4 IN5 on PB15 pin
using ADC4_IN5_PB15 = AnyAnalog<Port::PB, 15>;
#if defined(GPIOD_BASE)
/// A default configuration to map ADC4 IN10 on PD13 pin
using ADC4_IN10_PD13 = AnyAnalog<Port::PD, 13>;
/// A default configuration to map ADC4 IN11 on PD14 pin
using ADC4_IN11_PD14 = AnyAnalog<Port::PD, 14>;
/// A default configuration to map ADC4 IN12 on PD8 pin
using ADC4_IN12_PD8 = AnyAnalog<Port::PD, 8>;
/// A default configuration to map ADC4 IN13 on PD9 pin
using ADC4_IN13_PD9 = AnyAnalog<Port::PD, 9>;
/// A default configuration to map ADC4 IN7 on PD10 pin
using ADC4_IN7_PD10 = AnyAnalog<Port::PD, 10>;
/// A default configuration to map ADC4 IN8 on PD11 pin
using ADC4_IN8_PD11 = AnyAnalog<Port::PD, 11>;
/// A default configuration to map ADC4 IN9 on PD12 pin
using ADC4_IN9_PD12 = AnyAnalog<Port::PD, 12>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map ADC4 IN1 on PE14 pin
using ADC4_IN1_PE14 = AnyAnalog<Port::PE, 14>;
/// A default configuration to map ADC4 IN14 on PE10 pin
using ADC4_IN14_PE10 = AnyAnalog<Port::PE, 10>;
/// A default configuration to map ADC4 IN15 on PE11 pin
using ADC4_IN15_PE11 = AnyAnalog<Port::PE, 11>;
/// A default configuration to map ADC4 IN16 on PE12 pin
using ADC4_IN16_PE12 = AnyAnalog<Port::PE, 12>;
/// A default configuration to map ADC4 IN2 on PE15 pin
using ADC4_IN2_PE15 = AnyAnalog<Port::PE, 15>;
/// A default configuration to map ADC4 IN6 on PE8 pin
using ADC4_IN6_PE8 = AnyAnalog<Port::PE, 8>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(ADC4_BASE)

//////////////////////////////////////////////////////////////////////
// ADC5
//////////////////////////////////////////////////////////////////////
#if defined(ADC5_BASE)
/// A default configuration to map ADC5 IN1 on PA8 pin
using ADC5_IN1_PA8 = AnyAnalog<Port::PA, 8>;
/// A default configuration to map ADC5 IN2 on PA9 pin
using ADC5_IN2_PA9 = AnyAnalog<Port::PA, 9>;
#if defined(GPIOD_BASE)
/// A default configuration to map ADC5 IN10 on PD13 pin
using ADC5_IN10_PD13 = AnyAnalog<Port::PD, 13>;
/// A default configuration to map ADC5 IN11 on PD14 pin
using ADC5_IN11_PD14 = AnyAnalog<Port::PD, 14>;
/// A default configuration to map ADC5 IN12 on PD8 pin
using ADC5_IN12_PD8 = AnyAnalog<Port::PD, 8>;
/// A default configuration to map ADC5 IN13 on PD9 pin
using ADC5_IN13_PD9 = AnyAnalog<Port::PD, 9>;
/// A default configuration to map ADC5 IN7 on PD10 pin
using ADC5_IN7_PD10 = AnyAnalog<Port::PD, 10>;
/// A default configuration to map ADC5 IN8 on PD11 pin
using ADC5_IN8_PD11 = AnyAnalog<Port::PD, 11>;
/// A default configuration to map ADC5 IN9 on PD12 pin
using ADC5_IN9_PD12 = AnyAnalog<Port::PD, 12>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map ADC5 IN14 on PE10 pin
using ADC5_IN14_PE10 = AnyAnalog<Port::PE, 10>;
/// A default configuration to map ADC5 IN15 on PE11 pin
using ADC5_IN15_PE11 = AnyAnalog<Port::PE, 11>;
/// A default configuration to map ADC5 IN16 on PE12 pin
using ADC5_IN16_PE12 = AnyAnalog<Port::PE, 12>;
/// A default configuration to map ADC5 IN6 on PE8 pin
using ADC5_IN6_PE8 = AnyAnalog<Port::PE, 8>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(ADC5_BASE)

//////////////////////////////////////////////////////////////////////
// CAN1
//////////////////////////////////////////////////////////////////////
#if defined(CAN1_BASE)
/// A default configuration to map CAN1 RX on PA11 pin
using CAN1_RX_PA11 = AnyAltOut<Port::PA, 11, AfCAN1_RX_PA11>;
/// A default configuration to map CAN1 RX on PB8 pin
using CAN1_RX_PB8 = AnyAltOut<Port::PB, 8, AfCAN1_RX_PB8>;
/// A default configuration to map CAN1 TX on PA12 pin
using CAN1_TX_PA12 = AnyAltOut<Port::PA, 12, AfCAN1_TX_PA12>;
/// A default configuration to map CAN1 TX on PB9 pin
using CAN1_TX_PB9 = AnyAltOut<Port::PB, 9, AfCAN1_TX_PB9>;
#if defined(GPIOD_BASE)
/// A default configuration to map CAN1 RX on PD0 pin
using CAN1_RX_PD0 = AnyAltOut<Port::PD, 0, AfCAN1_RX_PD0>;
/// A default configuration to map CAN1 TX on PD1 pin
using CAN1_TX_PD1 = AnyAltOut<Port::PD, 1, AfCAN1_TX_PD1>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map CAN1 RXFD on PE0 pin
using CAN1_RXFD_PE0 = AnyAltOut<Port::PE, 0, AfCAN1_RXFD_PE0>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(CAN1_BASE)

//////////////////////////////////////////////////////////////////////
// CAN2
//////////////////////////////////////////////////////////////////////
#if defined(CAN2_BASE)
/// A default configuration to map CAN2 RX on PB5 pin
using CAN2_RX_PB5 = AnyAltOut<Port::PB, 5, AfCAN2_RX_PB5>;
/// A default configuration to map CAN2 RX on PB12 pin
using CAN2_RX_PB12 = AnyAltOut<Port::PB, 12, AfCAN2_RX_PB12>;
/// A default configuration to map CAN2 TX on PB6 pin
using CAN2_TX_PB6 = AnyAltOut<Port::PB, 6, AfCAN2_TX_PB6>;
/// A default configuration to map CAN2 TX on PB13 pin
using CAN2_TX_PB13 = AnyAltOut<Port::PB, 13, AfCAN2_TX_PB13>;
#endif	// defined(CAN2_BASE)

//////////////////////////////////////////////////////////////////////
// CAN3
//////////////////////////////////////////////////////////////////////
#if defined(CAN3_BASE)
/// A default configuration to map CAN3 RX on PA8 pin
using CAN3_RX_PA8 = AnyAltOut<Port::PA, 8, AfCAN3_RX_PA8>;
/// A default configuration to map CAN3 RX on PB3 pin
using CAN3_RX_PB3 = AnyAltOut<Port::PB, 3, AfCAN3_RX_PB3>;
/// A default configuration to map CAN3 TX on PA15 pin
using CAN3_TX_PA15 = AnyAltOut<Port::PA, 15, AfCAN3_TX_PA15>;
/// A default configuration to map CAN3 TX on PB4 pin
using CAN3_TX_PB4 = AnyAltOut<Port::PB, 4, AfCAN3_TX_PB4>;
#endif	// defined(CAN3_BASE)

//////////////////////////////////////////////////////////////////////
// COMP1
//////////////////////////////////////////////////////////////////////
#if defined(COMP1_BASE)
/// A default configuration to map COMP1 INM on PA0 pin
using COMP1_INM_PA0 = AnyAnalog<Port::PA, 0>;
/// A default configuration to map COMP1 INM on PA4 pin
using COMP1_INM_PA4 = AnyAnalog<Port::PA, 4>;
/// A default configuration to map COMP1 INP on PA1 pin
using COMP1_INP_PA1 = AnyAnalog<Port::PA, 1>;
/// A default configuration to map COMP1 INP on PB1 pin
using COMP1_INP_PB1 = AnyAnalog<Port::PB, 1>;
/// A default configuration to map COMP1 OUT on PA0 pin
using COMP1_OUT_PA0 = AnyAltOut<Port::PA, 0, AfCOMP1_OUT_PA0>;
/// A default configuration to map COMP1 OUT on PA6 pin
using COMP1_OUT_PA6 = AnyAltOut<Port::PA, 6, AfCOMP1_OUT_PA6>;
/// A default configuration to map COMP1 OUT on PA11 pin
using COMP1_OUT_PA11 = AnyAltOut<Port::PA, 11, AfCOMP1_OUT_PA11>;
/// A default configuration to map COMP1 OUT on PB8 pin
using COMP1_OUT_PB8 = AnyAltOut<Port::PB, 8, AfCOMP1_OUT_PB8>;
#if defined(GPIOF_BASE)
/// A default configuration to map COMP1 OUT on PF4 pin
using COMP1_OUT_PF4 = AnyAltOut<Port::PF, 4, AfCOMP1_OUT_PF4>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(COMP1_BASE)

//////////////////////////////////////////////////////////////////////
// COMP2
//////////////////////////////////////////////////////////////////////
#if defined(COMP2_BASE)
/// A default configuration to map COMP2 INM on PA2 pin
using COMP2_INM_PA2 = AnyAnalog<Port::PA, 2>;
/// A default configuration to map COMP2 INM on PA5 pin
using COMP2_INM_PA5 = AnyAnalog<Port::PA, 5>;
/// A default configuration to map COMP2 INP on PA3 pin
using COMP2_INP_PA3 = AnyAnalog<Port::PA, 3>;
/// A default configuration to map COMP2 INP on PA7 pin
using COMP2_INP_PA7 = AnyAnalog<Port::PA, 7>;
/// A default configuration to map COMP2 OUT on PA2 pin
using COMP2_OUT_PA2 = AnyAltOut<Port::PA, 2, AfCOMP2_OUT_PA2>;
/// A default configuration to map COMP2 OUT on PA7 pin
using COMP2_OUT_PA7 = AnyAltOut<Port::PA, 7, AfCOMP2_OUT_PA7>;
/// A default configuration to map COMP2 OUT on PA12 pin
using COMP2_OUT_PA12 = AnyAltOut<Port::PA, 12, AfCOMP2_OUT_PA12>;
/// A default configuration to map COMP2 OUT on PB9 pin
using COMP2_OUT_PB9 = AnyAltOut<Port::PB, 9, AfCOMP2_OUT_PB9>;
#endif	// defined(COMP2_BASE)

//////////////////////////////////////////////////////////////////////
// COMP3
//////////////////////////////////////////////////////////////////////
#if defined(COMP3_BASE)
/// A default configuration to map COMP3 INM on PC0 pin
using COMP3_INM_PC0 = AnyAnalog<Port::PC, 0>;
/// A default configuration to map COMP3 INP on PA0 pin
using COMP3_INP_PA0 = AnyAnalog<Port::PA, 0>;
/// A default configuration to map COMP3 INP on PC1 pin
using COMP3_INP_PC1 = AnyAnalog<Port::PC, 1>;
/// A default configuration to map COMP3 OUT on PB7 pin
using COMP3_OUT_PB7 = AnyAltOut<Port::PB, 7, AfCOMP3_OUT_PB7>;
/// A default configuration to map COMP3 OUT on PB15 pin
using COMP3_OUT_PB15 = AnyAltOut<Port::PB, 15, AfCOMP3_OUT_PB15>;
/// A default configuration to map COMP3 OUT on PC2 pin
using COMP3_OUT_PC2 = AnyAltOut<Port::PC, 2, AfCOMP3_OUT_PC2>;
#if defined(GPIOF_BASE)
/// A default configuration to map COMP3 INM on PF1 pin
using COMP3_INM_PF1 = AnyAnalog<Port::PF, 1>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(COMP3_BASE)

//////////////////////////////////////////////////////////////////////
// COMP4
//////////////////////////////////////////////////////////////////////
#if defined(COMP4_BASE)
/// A default configuration to map COMP4 INM on PB2 pin
using COMP4_INM_PB2 = AnyAnalog<Port::PB, 2>;
/// A default configuration to map COMP4 INP on PB0 pin
using COMP4_INP_PB0 = AnyAnalog<Port::PB, 0>;
/// A default configuration to map COMP4 OUT on PB1 pin
using COMP4_OUT_PB1 = AnyAltOut<Port::PB, 1, AfCOMP4_OUT_PB1>;
/// A default configuration to map COMP4 OUT on PB6 pin
using COMP4_OUT_PB6 = AnyAltOut<Port::PB, 6, AfCOMP4_OUT_PB6>;
/// A default configuration to map COMP4 OUT on PB14 pin
using COMP4_OUT_PB14 = AnyAltOut<Port::PB, 14, AfCOMP4_OUT_PB14>;
#if defined(GPIOE_BASE)
/// A default configuration to map COMP4 INM on PE8 pin
using COMP4_INM_PE8 = AnyAnalog<Port::PE, 8>;
/// A default configuration to map COMP4 INP on PE7 pin
using COMP4_INP_PE7 = AnyAnalog<Port::PE, 7>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(COMP4_BASE)

//////////////////////////////////////////////////////////////////////
// COMP5
//////////////////////////////////////////////////////////////////////
#if defined(COMP5_BASE)
/// A default configuration to map COMP5 INM on PB10 pin
using COMP5_INM_PB10 = AnyAnalog<Port::PB, 10>;
/// A default configuration to map COMP5 INP on PB13 pin
using COMP5_INP_PB13 = AnyAnalog<Port::PB, 13>;
/// A default configuration to map COMP5 OUT on PA9 pin
using COMP5_OUT_PA9 = AnyAltOut<Port::PA, 9, AfCOMP5_OUT_PA9>;
/// A default configuration to map COMP5 OUT on PC7 pin
using COMP5_OUT_PC7 = AnyAltOut<Port::PC, 7, AfCOMP5_OUT_PC7>;
#if defined(GPIOD_BASE)
/// A default configuration to map COMP5 INM on PD13 pin
using COMP5_INM_PD13 = AnyAnalog<Port::PD, 13>;
/// A default configuration to map COMP5 INP on PD12 pin
using COMP5_INP_PD12 = AnyAnalog<Port::PD, 12>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(COMP5_BASE)

//////////////////////////////////////////////////////////////////////
// COMP6
//////////////////////////////////////////////////////////////////////
#if defined(COMP6_BASE)
/// A default configuration to map COMP6 INM on PB15 pin
using COMP6_INM_PB15 = AnyAnalog<Port::PB, 15>;
/// A default configuration to map COMP6 INP on PB11 pin
using COMP6_INP_PB11 = AnyAnalog<Port::PB, 11>;
/// A default configuration to map COMP6 OUT on PA10 pin
using COMP6_OUT_PA10 = AnyAltOut<Port::PA, 10, AfCOMP6_OUT_PA10>;
/// A default configuration to map COMP6 OUT on PC6 pin
using COMP6_OUT_PC6 = AnyAltOut<Port::PC, 6, AfCOMP6_OUT_PC6>;
#if defined(GPIOD_BASE)
/// A default configuration to map COMP6 INM on PD10 pin
using COMP6_INM_PD10 = AnyAnalog<Port::PD, 10>;
/// A default configuration to map COMP6 INP on PD11 pin
using COMP6_INP_PD11 = AnyAnalog<Port::PD, 11>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(COMP6_BASE)

//////////////////////////////////////////////////////////////////////
// COMP7
//////////////////////////////////////////////////////////////////////
#if defined(COMP7_BASE)
/// A default configuration to map COMP7 INM on PB12 pin
using COMP7_INM_PB12 = AnyAnalog<Port::PB, 12>;
/// A default configuration to map COMP7 INP on PB14 pin
using COMP7_INP_PB14 = AnyAnalog<Port::PB, 14>;
/// A default configuration to map COMP7 OUT on PA8 pin
using COMP7_OUT_PA8 = AnyAltOut<Port::PA, 8, AfCOMP7_OUT_PA8>;
/// A default configuration to map COMP7 OUT on PC8 pin
using COMP7_OUT_PC8 = AnyAltOut<Port::PC, 8, AfCOMP7_OUT_PC8>;
#if defined(GPIOD_BASE)
/// A default configuration to map COMP7 INM on PD15 pin
using COMP7_INM_PD15 = AnyAnalog<Port::PD, 15>;
/// A default configuration to map COMP7 INP on PD14 pin
using COMP7_INP_PD14 = AnyAnalog<Port::PD, 14>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(COMP7_BASE)

//////////////////////////////////////////////////////////////////////
// DAC1
//////////////////////////////////////////////////////////////////////
#if defined(DAC1_BASE)
/// A default configuration to map DAC1 OUT1 on PA4 pin
using DAC1_OUT1_PA4 = AnyAnalog<Port::PA, 4>;
/// A default configuration to map DAC1 OUT2 on PA5 pin
using DAC1_OUT2_PA5 = AnyAnalog<Port::PA, 5>;
#endif	// defined(DAC1_BASE)

//////////////////////////////////////////////////////////////////////
// DAC2
//////////////////////////////////////////////////////////////////////
#if defined(DAC2_BASE)
/// A default configuration to map DAC2 OUT1 on PA6 pin
using DAC2_OUT1_PA6 = AnyAnalog<Port::PA, 6>;
#endif	// defined(DAC2_BASE)

//////////////////////////////////////////////////////////////////////
// FMC
//////////////////////////////////////////////////////////////////////
#if defined(FMC_BASE)
/// A default configuration to map FMC NL on PB7 pin
using FMC_NL_PB7 = AnyAltOut<Port::PB, 7, AfFMC_NL_PB7>;
#if defined(GPIOD_BASE)
/// A default configuration to map FMC A16 on PD11 pin
using FMC_A16_PD11 = AnyAltOut<Port::PD, 11, AfFMC_A16_PD11>;
/// A default configuration to map FMC A17 on PD12 pin
using FMC_A17_PD12 = AnyAltOut<Port::PD, 12, AfFMC_A17_PD12>;
/// A default configuration to map FMC A18 on PD13 pin
using FMC_A18_PD13 = AnyAltOut<Port::PD, 13, AfFMC_A18_PD13>;
/// A default configuration to map FMC CLK on PD3 pin
using FMC_CLK_PD3 = AnyAltOut<Port::PD, 3, AfFMC_CLK_PD3>;
/// A default configuration to map FMC D0 on PD14 pin
using FMC_D0_PD14 = AnyAltOut<Port::PD, 14, AfFMC_D0_PD14>;
/// A default configuration to map FMC D1 on PD15 pin
using FMC_D1_PD15 = AnyAltOut<Port::PD, 15, AfFMC_D1_PD15>;
/// A default configuration to map FMC D13 on PD8 pin
using FMC_D13_PD8 = AnyAltOut<Port::PD, 8, AfFMC_D13_PD8>;
/// A default configuration to map FMC D14 on PD9 pin
using FMC_D14_PD9 = AnyAltOut<Port::PD, 9, AfFMC_D14_PD9>;
/// A default configuration to map FMC D15 on PD10 pin
using FMC_D15_PD10 = AnyAltOut<Port::PD, 10, AfFMC_D15_PD10>;
/// A default configuration to map FMC D2 on PD0 pin
using FMC_D2_PD0 = AnyAltOut<Port::PD, 0, AfFMC_D2_PD0>;
/// A default configuration to map FMC D3 on PD1 pin
using FMC_D3_PD1 = AnyAltOut<Port::PD, 1, AfFMC_D3_PD1>;
/// A default configuration to map FMC NCE on PD7 pin
using FMC_NCE_PD7 = AnyAltOut<Port::PD, 7, AfFMC_NCE_PD7>;
/// A default configuration to map FMC NE1 on PD7 pin
using FMC_NE1_PD7 = AnyAltOut<Port::PD, 7, AfFMC_NE1_PD7>;
/// A default configuration to map FMC NOE on PD4 pin
using FMC_NOE_PD4 = AnyAltOut<Port::PD, 4, AfFMC_NOE_PD4>;
/// A default configuration to map FMC NWAIT on PD6 pin
using FMC_NWAIT_PD6 = AnyAltOut<Port::PD, 6, AfFMC_NWAIT_PD6>;
/// A default configuration to map FMC NWE on PD5 pin
using FMC_NWE_PD5 = AnyAltOut<Port::PD, 5, AfFMC_NWE_PD5>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map FMC A19 on PE3 pin
using FMC_A19_PE3 = AnyAltOut<Port::PE, 3, AfFMC_A19_PE3>;
/// A default configuration to map FMC A20 on PE4 pin
using FMC_A20_PE4 = AnyAltOut<Port::PE, 4, AfFMC_A20_PE4>;
/// A default configuration to map FMC A21 on PE5 pin
using FMC_A21_PE5 = AnyAltOut<Port::PE, 5, AfFMC_A21_PE5>;
/// A default configuration to map FMC A22 on PE6 pin
using FMC_A22_PE6 = AnyAltOut<Port::PE, 6, AfFMC_A22_PE6>;
/// A default configuration to map FMC A23 on PE2 pin
using FMC_A23_PE2 = AnyAltOut<Port::PE, 2, AfFMC_A23_PE2>;
/// A default configuration to map FMC D10 on PE13 pin
using FMC_D10_PE13 = AnyAltOut<Port::PE, 13, AfFMC_D10_PE13>;
/// A default configuration to map FMC D11 on PE14 pin
using FMC_D11_PE14 = AnyAltOut<Port::PE, 14, AfFMC_D11_PE14>;
/// A default configuration to map FMC D12 on PE15 pin
using FMC_D12_PE15 = AnyAltOut<Port::PE, 15, AfFMC_D12_PE15>;
/// A default configuration to map FMC D4 on PE7 pin
using FMC_D4_PE7 = AnyAltOut<Port::PE, 7, AfFMC_D4_PE7>;
/// A default configuration to map FMC D5 on PE8 pin
using FMC_D5_PE8 = AnyAltOut<Port::PE, 8, AfFMC_D5_PE8>;
/// A default configuration to map FMC D6 on PE9 pin
using FMC_D6_PE9 = AnyAltOut<Port::PE, 9, AfFMC_D6_PE9>;
/// A default configuration to map FMC D7 on PE10 pin
using FMC_D7_PE10 = AnyAltOut<Port::PE, 10, AfFMC_D7_PE10>;
/// A default configuration to map FMC D8 on PE11 pin
using FMC_D8_PE11 = AnyAltOut<Port::PE, 11, AfFMC_D8_PE11>;
/// A default configuration to map FMC D9 on PE12 pin
using FMC_D9_PE12 = AnyAltOut<Port::PE, 12, AfFMC_D9_PE12>;
/// A default configuration to map FMC NBL0 on PE0 pin
using FMC_NBL0_PE0 = AnyAltOut<Port::PE, 0, AfFMC_NBL0_PE0>;
/// A default configuration to map FMC NBL1 on PE1 pin
using FMC_NBL1_PE1 = AnyAltOut<Port::PE, 1, AfFMC_NBL1_PE1>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map FMC A0 on PF10 pin
using FMC_A0_PF10 = AnyAltOut<Port::PF, 10, AfFMC_A0_PF10>;
/// A default configuration to map FMC A1 on PF7 pin
using FMC_A1_PF7 = AnyAltOut<Port::PF, 7, AfFMC_A1_PF7>;
/// A default configuration to map FMC A2 on PF2 pin
using FMC_A2_PF2 = AnyAltOut<Port::PF, 2, AfFMC_A2_PF2>;
/// A default configuration to map FMC A24 on PF8 pin
using FMC_A24_PF8 = AnyAltOut<Port::PF, 8, AfFMC_A24_PF8>;
/// A default configuration to map FMC A25 on PF9 pin
using FMC_A25_PF9 = AnyAltOut<Port::PF, 9, AfFMC_A25_PF9>;
/// A default configuration to map FMC A3 on PF3 pin
using FMC_A3_PF3 = AnyAltOut<Port::PF, 3, AfFMC_A3_PF3>;
/// A default configuration to map FMC A4 on PF4 pin
using FMC_A4_PF4 = AnyAltOut<Port::PF, 4, AfFMC_A4_PF4>;
/// A default configuration to map FMC A5 on PF5 pin
using FMC_A5_PF5 = AnyAltOut<Port::PF, 5, AfFMC_A5_PF5>;
/// A default configuration to map FMC A6 on PF12 pin
using FMC_A6_PF12 = AnyAltOut<Port::PF, 12, AfFMC_A6_PF12>;
/// A default configuration to map FMC A7 on PF13 pin
using FMC_A7_PF13 = AnyAltOut<Port::PF, 13, AfFMC_A7_PF13>;
/// A default configuration to map FMC A8 on PF14 pin
using FMC_A8_PF14 = AnyAltOut<Port::PF, 14, AfFMC_A8_PF14>;
/// A default configuration to map FMC A9 on PF15 pin
using FMC_A9_PF15 = AnyAltOut<Port::PF, 15, AfFMC_A9_PF15>;
/// A default configuration to map FMC NE4 on PF11 pin
using FMC_NE4_PF11 = AnyAltOut<Port::PF, 11, AfFMC_NE4_PF11>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map FMC A10 on PG0 pin
using FMC_A10_PG0 = AnyAltOut<Port::PG, 0, AfFMC_A10_PG0>;
/// A default configuration to map FMC A11 on PG1 pin
using FMC_A11_PG1 = AnyAltOut<Port::PG, 1, AfFMC_A11_PG1>;
/// A default configuration to map FMC A12 on PG2 pin
using FMC_A12_PG2 = AnyAltOut<Port::PG, 2, AfFMC_A12_PG2>;
/// A default configuration to map FMC A13 on PG3 pin
using FMC_A13_PG3 = AnyAltOut<Port::PG, 3, AfFMC_A13_PG3>;
/// A default configuration to map FMC A14 on PG4 pin
using FMC_A14_PG4 = AnyAltOut<Port::PG, 4, AfFMC_A14_PG4>;
/// A default configuration to map FMC A15 on PG5 pin
using FMC_A15_PG5 = AnyAltOut<Port::PG, 5, AfFMC_A15_PG5>;
/// A default configuration to map FMC INT on PG6 pin
using FMC_INT_PG6 = AnyAltOut<Port::PG, 6, AfFMC_INT_PG6>;
/// A default configuration to map FMC INT on PG7 pin
using FMC_INT_PG7 = AnyAltOut<Port::PG, 7, AfFMC_INT_PG7>;
/// A default configuration to map FMC NCE on PG9 pin
using FMC_NCE_PG9 = AnyAltOut<Port::PG, 9, AfFMC_NCE_PG9>;
/// A default configuration to map FMC NE2 on PG9 pin
using FMC_NE2_PG9 = AnyAltOut<Port::PG, 9, AfFMC_NE2_PG9>;
/// A default configuration to map FMC NE3 on PG8 pin
using FMC_NE3_PG8 = AnyAltOut<Port::PG, 8, AfFMC_NE3_PG8>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(FMC_BASE)

//////////////////////////////////////////////////////////////////////
// HRTIM1
//////////////////////////////////////////////////////////////////////
#if defined(HRTIM1_BASE)
/// A default configuration to map HRTIM1 CHA1 on PA8 pin
using HRTIM1_CHA1_PA8 = AnyAltOut<Port::PA, 8, AfHRTIM1_CHA1_PA8>;
/// A default configuration to map HRTIM1 CHA2 on PA9 pin
using HRTIM1_CHA2_PA9 = AnyAltOut<Port::PA, 9, AfHRTIM1_CHA2_PA9>;
/// A default configuration to map HRTIM1 CHB1 on PA10 pin
using HRTIM1_CHB1_PA10 = AnyAltOut<Port::PA, 10, AfHRTIM1_CHB1_PA10>;
/// A default configuration to map HRTIM1 CHB2 on PA11 pin
using HRTIM1_CHB2_PA11 = AnyAltOut<Port::PA, 11, AfHRTIM1_CHB2_PA11>;
/// A default configuration to map HRTIM1 CHC1 on PB12 pin
using HRTIM1_CHC1_PB12 = AnyAltOut<Port::PB, 12, AfHRTIM1_CHC1_PB12>;
/// A default configuration to map HRTIM1 CHC2 on PB13 pin
using HRTIM1_CHC2_PB13 = AnyAltOut<Port::PB, 13, AfHRTIM1_CHC2_PB13>;
/// A default configuration to map HRTIM1 CHD1 on PB14 pin
using HRTIM1_CHD1_PB14 = AnyAltOut<Port::PB, 14, AfHRTIM1_CHD1_PB14>;
/// A default configuration to map HRTIM1 CHD2 on PB15 pin
using HRTIM1_CHD2_PB15 = AnyAltOut<Port::PB, 15, AfHRTIM1_CHD2_PB15>;
/// A default configuration to map HRTIM1 CHE1 on PC8 pin
using HRTIM1_CHE1_PC8 = AnyAltOut<Port::PC, 8, AfHRTIM1_CHE1_PC8>;
/// A default configuration to map HRTIM1 CHE2 on PC9 pin
using HRTIM1_CHE2_PC9 = AnyAltOut<Port::PC, 9, AfHRTIM1_CHE2_PC9>;
/// A default configuration to map HRTIM1 CHF1 on PC6 pin
using HRTIM1_CHF1_PC6 = AnyAltOut<Port::PC, 6, AfHRTIM1_CHF1_PC6>;
/// A default configuration to map HRTIM1 CHF2 on PC7 pin
using HRTIM1_CHF2_PC7 = AnyAltOut<Port::PC, 7, AfHRTIM1_CHF2_PC7>;
/// A default configuration to map HRTIM1 EEV1 on PC12 pin
using HRTIM1_EEV1_PC12 = AnyAltOut<Port::PC, 12, AfHRTIM1_EEV1_PC12>;
/// A default configuration to map HRTIM1 EEV10 on PC5 pin
using HRTIM1_EEV10_PC5 = AnyAltOut<Port::PC, 5, AfHRTIM1_EEV10_PC5>;
/// A default configuration to map HRTIM1 EEV10 on PC6 pin
using HRTIM1_EEV10_PC6 = AnyAltOut<Port::PC, 6, AfHRTIM1_EEV10_PC6>;
/// A default configuration to map HRTIM1 EEV2 on PC11 pin
using HRTIM1_EEV2_PC11 = AnyAltOut<Port::PC, 11, AfHRTIM1_EEV2_PC11>;
/// A default configuration to map HRTIM1 EEV3 on PB7 pin
using HRTIM1_EEV3_PB7 = AnyAltOut<Port::PB, 7, AfHRTIM1_EEV3_PB7>;
/// A default configuration to map HRTIM1 EEV4 on PB6 pin
using HRTIM1_EEV4_PB6 = AnyAltOut<Port::PB, 6, AfHRTIM1_EEV4_PB6>;
/// A default configuration to map HRTIM1 EEV5 on PB9 pin
using HRTIM1_EEV5_PB9 = AnyAltOut<Port::PB, 9, AfHRTIM1_EEV5_PB9>;
/// A default configuration to map HRTIM1 EEV6 on PB5 pin
using HRTIM1_EEV6_PB5 = AnyAltOut<Port::PB, 5, AfHRTIM1_EEV6_PB5>;
/// A default configuration to map HRTIM1 EEV7 on PB4 pin
using HRTIM1_EEV7_PB4 = AnyAltOut<Port::PB, 4, AfHRTIM1_EEV7_PB4>;
/// A default configuration to map HRTIM1 EEV8 on PB8 pin
using HRTIM1_EEV8_PB8 = AnyAltOut<Port::PB, 8, AfHRTIM1_EEV8_PB8>;
/// A default configuration to map HRTIM1 EEV9 on PB3 pin
using HRTIM1_EEV9_PB3 = AnyAltOut<Port::PB, 3, AfHRTIM1_EEV9_PB3>;
/// A default configuration to map HRTIM1 FLT1 on PA12 pin
using HRTIM1_FLT1_PA12 = AnyAltOut<Port::PA, 12, AfHRTIM1_FLT1_PA12>;
/// A default configuration to map HRTIM1 FLT2 on PA15 pin
using HRTIM1_FLT2_PA15 = AnyAltOut<Port::PA, 15, AfHRTIM1_FLT2_PA15>;
/// A default configuration to map HRTIM1 FLT3 on PB10 pin
using HRTIM1_FLT3_PB10 = AnyAltOut<Port::PB, 10, AfHRTIM1_FLT3_PB10>;
/// A default configuration to map HRTIM1 FLT4 on PB11 pin
using HRTIM1_FLT4_PB11 = AnyAltOut<Port::PB, 11, AfHRTIM1_FLT4_PB11>;
/// A default configuration to map HRTIM1 FLT5 on PB0 pin
using HRTIM1_FLT5_PB0 = AnyAltOut<Port::PB, 0, AfHRTIM1_FLT5_PB0>;
/// A default configuration to map HRTIM1 FLT5 on PC7 pin
using HRTIM1_FLT5_PC7 = AnyAltOut<Port::PC, 7, AfHRTIM1_FLT5_PC7>;
/// A default configuration to map HRTIM1 FLT6 on PC10 pin
using HRTIM1_FLT6_PC10 = AnyAltOut<Port::PC, 10, AfHRTIM1_FLT6_PC10>;
/// A default configuration to map HRTIM1 SCIN on PB2 pin
using HRTIM1_SCIN_PB2 = AnyAltOut<Port::PB, 2, AfHRTIM1_SCIN_PB2>;
/// A default configuration to map HRTIM1 SCIN on PB6 pin
using HRTIM1_SCIN_PB6 = AnyAltOut<Port::PB, 6, AfHRTIM1_SCIN_PB6>;
/// A default configuration to map HRTIM1 SCOUT on PB1 pin
using HRTIM1_SCOUT_PB1 = AnyAltOut<Port::PB, 1, AfHRTIM1_SCOUT_PB1>;
/// A default configuration to map HRTIM1 SCOUT on PB3 pin
using HRTIM1_SCOUT_PB3 = AnyAltOut<Port::PB, 3, AfHRTIM1_SCOUT_PB3>;
#endif	// defined(HRTIM1_BASE)

//////////////////////////////////////////////////////////////////////
// IR
//////////////////////////////////////////////////////////////////////
#if defined(TIM16_BASE)
/// A default configuration to map IR OUT on PA13 pin
using IR_OUT_PA13 = AnyAltOut<Port::PA, 13, AfIR_OUT_PA13>;
/// A default configuration to map IR OUT on PB9 pin
using IR_OUT_PB9 = AnyAltOut<Port::PB, 9, AfIR_OUT_PB9>;
#endif	// defined(TIM16_BASE)

//////////////////////////////////////////////////////////////////////
// I2C1
//////////////////////////////////////////////////////////////////////
#if defined(I2C1_BASE)
/// A default configuration to map I2C1 SCL on PA13 pin
using I2C1_SCL_PA13 = AnyAltOutOD<Port::PA, 13, AfI2C1_SCL_PA13>;
/// A default configuration to map I2C1 SCL on PA15 pin
using I2C1_SCL_PA15 = AnyAltOutOD<Port::PA, 15, AfI2C1_SCL_PA15>;
/// A default configuration to map I2C1 SCL on PB8 pin
using I2C1_SCL_PB8 = AnyAltOutOD<Port::PB, 8, AfI2C1_SCL_PB8>;
/// A default configuration to map I2C1 SDA on PA14 pin
using I2C1_SDA_PA14 = AnyAltOutOD<Port::PA, 14, AfI2C1_SDA_PA14>;
/// A default configuration to map I2C1 SDA on PB7 pin
using I2C1_SDA_PB7 = AnyAltOutOD<Port::PB, 7, AfI2C1_SDA_PB7>;
/// A default configuration to map I2C1 SDA on PB9 pin
using I2C1_SDA_PB9 = AnyAltOutOD<Port::PB, 9, AfI2C1_SDA_PB9>;
/// A default configuration to map I2C1 SMBA on PB5 pin
using I2C1_SMBA_PB5 = AnyAltOutOD<Port::PB, 5, AfI2C1_SMBA_PB5>;
#endif	// defined(I2C1_BASE)

//////////////////////////////////////////////////////////////////////
// I2C2
//////////////////////////////////////////////////////////////////////
#if defined(I2C2_BASE)
/// A default configuration to map I2C2 SCL on PA9 pin
using I2C2_SCL_PA9 = AnyAltOutOD<Port::PA, 9, AfI2C2_SCL_PA9>;
/// A default configuration to map I2C2 SCL on PC4 pin
using I2C2_SCL_PC4 = AnyAltOutOD<Port::PC, 4, AfI2C2_SCL_PC4>;
/// A default configuration to map I2C2 SDA on PA8 pin
using I2C2_SDA_PA8 = AnyAltOutOD<Port::PA, 8, AfI2C2_SDA_PA8>;
/// A default configuration to map I2C2 SMBA on PA10 pin
using I2C2_SMBA_PA10 = AnyAltOutOD<Port::PA, 10, AfI2C2_SMBA_PA10>;
/// A default configuration to map I2C2 SMBA on PB12 pin
using I2C2_SMBA_PB12 = AnyAltOutOD<Port::PB, 12, AfI2C2_SMBA_PB12>;
#if defined(GPIOF_BASE)
/// A default configuration to map I2C2 SCL on PF6 pin
using I2C2_SCL_PF6 = AnyAltOutOD<Port::PF, 6, AfI2C2_SCL_PF6>;
/// A default configuration to map I2C2 SDA on PF0 pin
using I2C2_SDA_PF0 = AnyAltOutOD<Port::PF, 0, AfI2C2_SDA_PF0>;
/// A default configuration to map I2C2 SMBA on PF2 pin
using I2C2_SMBA_PF2 = AnyAltOutOD<Port::PF, 2, AfI2C2_SMBA_PF2>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(I2C2_BASE)

//////////////////////////////////////////////////////////////////////
// I2C3
//////////////////////////////////////////////////////////////////////
#if defined(I2C3_BASE)
/// A default configuration to map I2C3 SCL on PA8 pin
using I2C3_SCL_PA8 = AnyAltOutOD<Port::PA, 8, AfI2C3_SCL_PA8>;
/// A default configuration to map I2C3 SCL on PC8 pin
using I2C3_SCL_PC8 = AnyAltOutOD<Port::PC, 8, AfI2C3_SCL_PC8>;
/// A default configuration to map I2C3 SDA on PB5 pin
using I2C3_SDA_PB5 = AnyAltOutOD<Port::PB, 5, AfI2C3_SDA_PB5>;
/// A default configuration to map I2C3 SDA on PC9 pin
using I2C3_SDA_PC9 = AnyAltOutOD<Port::PC, 9, AfI2C3_SDA_PC9>;
/// A default configuration to map I2C3 SDA on PC11 pin
using I2C3_SDA_PC11 = AnyAltOutOD<Port::PC, 11, AfI2C3_SDA_PC11>;
/// A default configuration to map I2C3 SMBA on PA9 pin
using I2C3_SMBA_PA9 = AnyAltOutOD<Port::PA, 9, AfI2C3_SMBA_PA9>;
/// A default configuration to map I2C3 SMBA on PB2 pin
using I2C3_SMBA_PB2 = AnyAltOutOD<Port::PB, 2, AfI2C3_SMBA_PB2>;
#if defined(GPIOF_BASE)
/// A default configuration to map I2C3 SCL on PF3 pin
using I2C3_SCL_PF3 = AnyAltOutOD<Port::PF, 3, AfI2C3_SCL_PF3>;
/// A default configuration to map I2C3 SDA on PF4 pin
using I2C3_SDA_PF4 = AnyAltOutOD<Port::PF, 4, AfI2C3_SDA_PF4>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map I2C3 SCL on PG7 pin
using I2C3_SCL_PG7 = AnyAltOutOD<Port::PG, 7, AfI2C3_SCL_PG7>;
/// A default configuration to map I2C3 SDA on PG8 pin
using I2C3_SDA_PG8 = AnyAltOutOD<Port::PG, 8, AfI2C3_SDA_PG8>;
/// A default configuration to map I2C3 SMBA on PG6 pin
using I2C3_SMBA_PG6 = AnyAltOutOD<Port::PG, 6, AfI2C3_SMBA_PG6>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(I2C3_BASE)

//////////////////////////////////////////////////////////////////////
// I2C4
//////////////////////////////////////////////////////////////////////
#if defined(I2C4_BASE)
/// A default configuration to map I2C4 SCL on PA13 pin
using I2C4_SCL_PA13 = AnyAltOutOD<Port::PA, 13, AfI2C4_SCL_PA13>;
/// A default configuration to map I2C4 SCL on PC6 pin
using I2C4_SCL_PC6 = AnyAltOutOD<Port::PC, 6, AfI2C4_SCL_PC6>;
/// A default configuration to map I2C4 SDA on PB7 pin
using I2C4_SDA_PB7 = AnyAltOutOD<Port::PB, 7, AfI2C4_SDA_PB7>;
/// A default configuration to map I2C4 SDA on PC7 pin
using I2C4_SDA_PC7 = AnyAltOutOD<Port::PC, 7, AfI2C4_SDA_PC7>;
/// A default configuration to map I2C4 SMBA on PA14 pin
using I2C4_SMBA_PA14 = AnyAltOutOD<Port::PA, 14, AfI2C4_SMBA_PA14>;
#if defined(GPIOD_BASE)
/// A default configuration to map I2C4 SMBA on PD11 pin
using I2C4_SMBA_PD11 = AnyAltOutOD<Port::PD, 11, AfI2C4_SMBA_PD11>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map I2C4 SCL on PF14 pin
using I2C4_SCL_PF14 = AnyAltOutOD<Port::PF, 14, AfI2C4_SCL_PF14>;
/// A default configuration to map I2C4 SDA on PF15 pin
using I2C4_SDA_PF15 = AnyAltOutOD<Port::PF, 15, AfI2C4_SDA_PF15>;
/// A default configuration to map I2C4 SMBA on PF13 pin
using I2C4_SMBA_PF13 = AnyAltOutOD<Port::PF, 13, AfI2C4_SMBA_PF13>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map I2C4 SCL on PG3 pin
using I2C4_SCL_PG3 = AnyAltOutOD<Port::PG, 3, AfI2C4_SCL_PG3>;
/// A default configuration to map I2C4 SDA on PG4 pin
using I2C4_SDA_PG4 = AnyAltOutOD<Port::PG, 4, AfI2C4_SDA_PG4>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(I2C4_BASE)

//////////////////////////////////////////////////////////////////////
// I2S2
//////////////////////////////////////////////////////////////////////
#if defined(I2S2_BASE)
/// A default configuration to map I2S2 CK on PB13 pin
using I2S2_CK_PB13 = AnyAltOutOD<Port::PB, 13, AfI2S2_CK_PB13>;
/// A default configuration to map I2S2 MCK on PA8 pin
using I2S2_MCK_PA8 = AnyAltOutOD<Port::PA, 8, AfI2S2_MCK_PA8>;
/// A default configuration to map I2S2 MCK on PC6 pin
using I2S2_MCK_PC6 = AnyAltOutOD<Port::PC, 6, AfI2S2_MCK_PC6>;
/// A default configuration to map I2S2 SD on PA11 pin
using I2S2_SD_PA11 = AnyAltOutOD<Port::PA, 11, AfI2S2_SD_PA11>;
/// A default configuration to map I2S2 SD on PB15 pin
using I2S2_SD_PB15 = AnyAltOutOD<Port::PB, 15, AfI2S2_SD_PB15>;
/// A default configuration to map I2S2 WS on PB12 pin
using I2S2_WS_PB12 = AnyAltOutOD<Port::PB, 12, AfI2S2_WS_PB12>;
#if defined(GPIOF_BASE)
/// A default configuration to map I2S2 CK on PF1 pin
using I2S2_CK_PF1 = AnyAltOutOD<Port::PF, 1, AfI2S2_CK_PF1>;
/// A default configuration to map I2S2 WS on PF0 pin
using I2S2_WS_PF0 = AnyAltOutOD<Port::PF, 0, AfI2S2_WS_PF0>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(I2S2_BASE)

//////////////////////////////////////////////////////////////////////
// I2S3
//////////////////////////////////////////////////////////////////////
#if defined(I2S3_BASE)
/// A default configuration to map I2S3 CK on PB3 pin
using I2S3_CK_PB3 = AnyAltOutOD<Port::PB, 3, AfI2S3_CK_PB3>;
/// A default configuration to map I2S3 CK on PC10 pin
using I2S3_CK_PC10 = AnyAltOutOD<Port::PC, 10, AfI2S3_CK_PC10>;
/// A default configuration to map I2S3 MCK on PA9 pin
using I2S3_MCK_PA9 = AnyAltOutOD<Port::PA, 9, AfI2S3_MCK_PA9>;
/// A default configuration to map I2S3 MCK on PC7 pin
using I2S3_MCK_PC7 = AnyAltOutOD<Port::PC, 7, AfI2S3_MCK_PC7>;
/// A default configuration to map I2S3 SD on PB5 pin
using I2S3_SD_PB5 = AnyAltOutOD<Port::PB, 5, AfI2S3_SD_PB5>;
/// A default configuration to map I2S3 SD on PC12 pin
using I2S3_SD_PC12 = AnyAltOutOD<Port::PC, 12, AfI2S3_SD_PC12>;
/// A default configuration to map I2S3 WS on PA4 pin
using I2S3_WS_PA4 = AnyAltOutOD<Port::PA, 4, AfI2S3_WS_PA4>;
/// A default configuration to map I2S3 WS on PA15 pin
using I2S3_WS_PA15 = AnyAltOutOD<Port::PA, 15, AfI2S3_WS_PA15>;
#endif	// defined(I2S3_BASE)

//////////////////////////////////////////////////////////////////////
// I2SCKIN
//////////////////////////////////////////////////////////////////////
#if defined(SPI_I2S_SUPPORT)
/// A default configuration to map I2SCKIN on PA12 pin
using I2SCKIN_PA12 = AnyAltOut<Port::PA, 12, AfI2SCKIN_PA12>;
/// A default configuration to map I2SCKIN on PC9 pin
using I2SCKIN_PC9 = AnyAltOut<Port::PC, 9, AfI2SCKIN_PC9>;
#endif	// defined(SPI_I2S_SUPPORT)

//////////////////////////////////////////////////////////////////////
// LPTIM1
//////////////////////////////////////////////////////////////////////
#if defined(LPTIM1_BASE)
/// A default configuration to map LPTIM1 ETR on PB6 pin
using LPTIM1_ETR_PB6 = AnyAltOut<Port::PB, 6, AfLPTIM1_ETR_PB6>;
/// A default configuration to map LPTIM1 ETR on PC3 pin
using LPTIM1_ETR_PC3 = AnyAltOut<Port::PC, 3, AfLPTIM1_ETR_PC3>;
/// A default configuration to map LPTIM1 IN1 on PB5 pin
using LPTIM1_IN1_PB5 = AnyAltOut<Port::PB, 5, AfLPTIM1_IN1_PB5>;
/// A default configuration to map LPTIM1 IN1 on PC0 pin
using LPTIM1_IN1_PC0 = AnyAltOut<Port::PC, 0, AfLPTIM1_IN1_PC0>;
/// A default configuration to map LPTIM1 IN2 on PB7 pin
using LPTIM1_IN2_PB7 = AnyAltOut<Port::PB, 7, AfLPTIM1_IN2_PB7>;
/// A default configuration to map LPTIM1 IN2 on PC2 pin
using LPTIM1_IN2_PC2 = AnyAltOut<Port::PC, 2, AfLPTIM1_IN2_PC2>;
/// A default configuration to map LPTIM1 OUT on PA14 pin
using LPTIM1_OUT_PA14 = AnyAltOut<Port::PA, 14, AfLPTIM1_OUT_PA14>;
/// A default configuration to map LPTIM1 OUT on PB2 pin
using LPTIM1_OUT_PB2 = AnyAltOut<Port::PB, 2, AfLPTIM1_OUT_PB2>;
/// A default configuration to map LPTIM1 OUT on PC1 pin
using LPTIM1_OUT_PC1 = AnyAltOut<Port::PC, 1, AfLPTIM1_OUT_PC1>;
#endif	// defined(LPTIM1_BASE)

//////////////////////////////////////////////////////////////////////
// LPUART1
//////////////////////////////////////////////////////////////////////
#if defined(LPUART1_BASE)
/// A default configuration to map LPUART1 CTS on PA6 pin
using LPUART1_CTS_PA6 = AnyAltOutOD<Port::PA, 6, AfLPUART1_CTS_PA6>;
/// A default configuration to map LPUART1 CTS on PB13 pin
using LPUART1_CTS_PB13 = AnyAltOutOD<Port::PB, 13, AfLPUART1_CTS_PB13>;
/// A default configuration to map LPUART1 RTS_DE on PB1 pin
using LPUART1_RTS_DE_PB1 = AnyAltOut<Port::PB, 1, AfLPUART1_RTS_DE_PB1>;
/// A default configuration to map LPUART1 RTS_DE on PB12 pin
using LPUART1_RTS_DE_PB12 = AnyAltOut<Port::PB, 12, AfLPUART1_RTS_DE_PB12>;
/// A default configuration to map LPUART1 RX on PA3 pin
using LPUART1_RX_PA3 = AnyAltOutOD<Port::PA, 3, AfLPUART1_RX_PA3>;
/// A default configuration to map LPUART1 RX on PB10 pin
using LPUART1_RX_PB10 = AnyAltOutOD<Port::PB, 10, AfLPUART1_RX_PB10>;
/// A default configuration to map LPUART1 RX on PC0 pin
using LPUART1_RX_PC0 = AnyAltOutOD<Port::PC, 0, AfLPUART1_RX_PC0>;
/// A default configuration to map LPUART1 TX on PA2 pin
using LPUART1_TX_PA2 = AnyAltOut<Port::PA, 2, AfLPUART1_TX_PA2>;
/// A default configuration to map LPUART1 TX on PB11 pin
using LPUART1_TX_PB11 = AnyAltOut<Port::PB, 11, AfLPUART1_TX_PB11>;
/// A default configuration to map LPUART1 TX on PC1 pin
using LPUART1_TX_PC1 = AnyAltOut<Port::PC, 1, AfLPUART1_TX_PC1>;
#if defined(GPIOG_BASE)
/// A default configuration to map LPUART1 CTS on PG5 pin
using LPUART1_CTS_PG5 = AnyAltOutOD<Port::PG, 5, AfLPUART1_CTS_PG5>;
/// A default configuration to map LPUART1 RTS_DE on PG6 pin
using LPUART1_RTS_DE_PG6 = AnyAltOut<Port::PG, 6, AfLPUART1_RTS_DE_PG6>;
/// A default configuration to map LPUART1 RX on PG8 pin
using LPUART1_RX_PG8 = AnyAltOutOD<Port::PG, 8, AfLPUART1_RX_PG8>;
/// A default configuration to map LPUART1 TX on PG7 pin
using LPUART1_TX_PG7 = AnyAltOut<Port::PG, 7, AfLPUART1_TX_PG7>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(LPUART1_BASE)

//////////////////////////////////////////////////////////////////////
// OPAMP1
//////////////////////////////////////////////////////////////////////
#if defined(OPAMP1_BASE)
/// A default configuration to map OPAMP1 VINM on PA3 pin
using OPAMP1_VINM_PA3 = AnyAnalog<Port::PA, 3>;
/// A default configuration to map OPAMP1 VINM on PC5 pin
using OPAMP1_VINM_PC5 = AnyAnalog<Port::PC, 5>;
/// A default configuration to map OPAMP1 VINP on PA1 pin
using OPAMP1_VINP_PA1 = AnyAnalog<Port::PA, 1>;
/// A default configuration to map OPAMP1 VINP on PA3 pin
using OPAMP1_VINP_PA3 = AnyAnalog<Port::PA, 3>;
/// A default configuration to map OPAMP1 VINP on PA7 pin
using OPAMP1_VINP_PA7 = AnyAnalog<Port::PA, 7>;
/// A default configuration to map OPAMP1 VOUT on PA2 pin
using OPAMP1_VOUT_PA2 = AnyAnalog<Port::PA, 2>;
#endif	// defined(OPAMP1_BASE)

//////////////////////////////////////////////////////////////////////
// OPAMP2
//////////////////////////////////////////////////////////////////////
#if defined(OPAMP2_BASE)
/// A default configuration to map OPAMP2 VINM on PA5 pin
using OPAMP2_VINM_PA5 = AnyAnalog<Port::PA, 5>;
/// A default configuration to map OPAMP2 VINM on PC5 pin
using OPAMP2_VINM_PC5 = AnyAnalog<Port::PC, 5>;
/// A default configuration to map OPAMP2 VINP on PA7 pin
using OPAMP2_VINP_PA7 = AnyAnalog<Port::PA, 7>;
/// A default configuration to map OPAMP2 VINP on PB0 pin
using OPAMP2_VINP_PB0 = AnyAnalog<Port::PB, 0>;
/// A default configuration to map OPAMP2 VINP on PB14 pin
using OPAMP2_VINP_PB14 = AnyAnalog<Port::PB, 14>;
/// A default configuration to map OPAMP2 VOUT on PA6 pin
using OPAMP2_VOUT_PA6 = AnyAnalog<Port::PA, 6>;
#if defined(GPIOD_BASE)
/// A default configuration to map OPAMP2 VINP on PD14 pin
using OPAMP2_VINP_PD14 = AnyAnalog<Port::PD, 14>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(OPAMP2_BASE)

//////////////////////////////////////////////////////////////////////
// OPAMP3
//////////////////////////////////////////////////////////////////////
#if defined(OPAMP3_BASE)
/// A default configuration to map OPAMP3 VINM on PB2 pin
using OPAMP3_VINM_PB2 = AnyAnalog<Port::PB, 2>;
/// A default configuration to map OPAMP3 VINM on PB10 pin
using OPAMP3_VINM_PB10 = AnyAnalog<Port::PB, 10>;
/// A default configuration to map OPAMP3 VINP on PA1 pin
using OPAMP3_VINP_PA1 = AnyAnalog<Port::PA, 1>;
/// A default configuration to map OPAMP3 VINP on PB0 pin
using OPAMP3_VINP_PB0 = AnyAnalog<Port::PB, 0>;
/// A default configuration to map OPAMP3 VINP on PB13 pin
using OPAMP3_VINP_PB13 = AnyAnalog<Port::PB, 13>;
/// A default configuration to map OPAMP3 VOUT on PB1 pin
using OPAMP3_VOUT_PB1 = AnyAnalog<Port::PB, 1>;
#endif	// defined(OPAMP3_BASE)

//////////////////////////////////////////////////////////////////////
// OPAMP4
//////////////////////////////////////////////////////////////////////
#if defined(OPAMP4_BASE)
/// A default configuration to map OPAMP4 VINM on PB10 pin
using OPAMP4_VINM_PB10 = AnyAnalog<Port::PB, 10>;
/// A default configuration to map OPAMP4 VINP on PB11 pin
using OPAMP4_VINP_PB11 = AnyAnalog<Port::PB, 11>;
/// A default configuration to map OPAMP4 VINP on PB13 pin
using OPAMP4_VINP_PB13 = AnyAnalog<Port::PB, 13>;
/// A default configuration to map OPAMP4 VOUT on PB12 pin
using OPAMP4_VOUT_PB12 = AnyAnalog<Port::PB, 12>;
#if defined(GPIOD_BASE)
/// A default configuration to map OPAMP4 VINM on PD8 pin
using OPAMP4_VINM_PD8 = AnyAnalog<Port::PD, 8>;
/// A default configuration to map OPAMP4 VINP on PD11 pin
using OPAMP4_VINP_PD11 = AnyAnalog<Port::PD, 11>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(OPAMP4_BASE)

//////////////////////////////////////////////////////////////////////
// OPAMP5
//////////////////////////////////////////////////////////////////////
#if defined(OPAMP5_BASE)
/// A default configuration to map OPAMP5 VINM on PA3 pin
using OPAMP5_VINM_PA3 = AnyAnalog<Port::PA, 3>;
/// A default configuration to map OPAMP5 VINM on PB15 pin
using OPAMP5_VINM_PB15 = AnyAnalog<Port::PB, 15>;
/// A default configuration to map OPAMP5 VINP on PB14 pin
using OPAMP5_VINP_PB14 = AnyAnalog<Port::PB, 14>;
/// A default configuration to map OPAMP5 VINP on PC3 pin
using OPAMP5_VINP_PC3 = AnyAnalog<Port::PC, 3>;
/// A default configuration to map OPAMP5 VOUT on PA8 pin
using OPAMP5_VOUT_PA8 = AnyAnalog<Port::PA, 8>;
#if defined(GPIOD_BASE)
/// A default configuration to map OPAMP5 VINP on PD12 pin
using OPAMP5_VINP_PD12 = AnyAnalog<Port::PD, 12>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(OPAMP5_BASE)

//////////////////////////////////////////////////////////////////////
// OPAMP6
//////////////////////////////////////////////////////////////////////
#if defined(OPAMP6_BASE)
/// A default configuration to map OPAMP6 VINM on PA1 pin
using OPAMP6_VINM_PA1 = AnyAnalog<Port::PA, 1>;
/// A default configuration to map OPAMP6 VINM on PB1 pin
using OPAMP6_VINM_PB1 = AnyAnalog<Port::PB, 1>;
/// A default configuration to map OPAMP6 VINP on PB12 pin
using OPAMP6_VINP_PB12 = AnyAnalog<Port::PB, 12>;
/// A default configuration to map OPAMP6 VINP on PB13 pin
using OPAMP6_VINP_PB13 = AnyAnalog<Port::PB, 13>;
/// A default configuration to map OPAMP6 VOUT on PB11 pin
using OPAMP6_VOUT_PB11 = AnyAnalog<Port::PB, 11>;
#if defined(GPIOD_BASE)
/// A default configuration to map OPAMP6 VINP on PD9 pin
using OPAMP6_VINP_PD9 = AnyAnalog<Port::PD, 9>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(OPAMP6_BASE)

//////////////////////////////////////////////////////////////////////
// QUADSPI1
//////////////////////////////////////////////////////////////////////
#if defined(QUADSPI)
/// A default configuration to map QUADSPI1 BK1_IO0 on PB1 pin
using QUADSPI1_BK1_IO0_PB1 = AnyAltOut<Port::PB, 1, AfQUADSPI1_BK1_IO0_PB1>;
/// A default configuration to map QUADSPI1 BK1_IO1 on PB0 pin
using QUADSPI1_BK1_IO1_PB0 = AnyAltOut<Port::PB, 0, AfQUADSPI1_BK1_IO1_PB0>;
/// A default configuration to map QUADSPI1 BK1_IO2 on PA7 pin
using QUADSPI1_BK1_IO2_PA7 = AnyAltOut<Port::PA, 7, AfQUADSPI1_BK1_IO2_PA7>;
/// A default configuration to map QUADSPI1 BK1_IO3 on PA6 pin
using QUADSPI1_BK1_IO3_PA6 = AnyAltOut<Port::PA, 6, AfQUADSPI1_BK1_IO3_PA6>;
/// A default configuration to map QUADSPI1 BK1_NCS on PA2 pin
using QUADSPI1_BK1_NCS_PA2 = AnyAltOut<Port::PA, 2, AfQUADSPI1_BK1_NCS_PA2>;
/// A default configuration to map QUADSPI1 BK1_NCS on PB11 pin
using QUADSPI1_BK1_NCS_PB11 = AnyAltOut<Port::PB, 11, AfQUADSPI1_BK1_NCS_PB11>;
/// A default configuration to map QUADSPI1 BK2_IO0 on PC1 pin
using QUADSPI1_BK2_IO0_PC1 = AnyAltOut<Port::PC, 1, AfQUADSPI1_BK2_IO0_PC1>;
/// A default configuration to map QUADSPI1 BK2_IO1 on PB2 pin
using QUADSPI1_BK2_IO1_PB2 = AnyAltOut<Port::PB, 2, AfQUADSPI1_BK2_IO1_PB2>;
/// A default configuration to map QUADSPI1 BK2_IO1 on PC2 pin
using QUADSPI1_BK2_IO1_PC2 = AnyAltOut<Port::PC, 2, AfQUADSPI1_BK2_IO1_PC2>;
/// A default configuration to map QUADSPI1 BK2_IO2 on PC3 pin
using QUADSPI1_BK2_IO2_PC3 = AnyAltOut<Port::PC, 3, AfQUADSPI1_BK2_IO2_PC3>;
/// A default configuration to map QUADSPI1 BK2_IO3 on PC4 pin
using QUADSPI1_BK2_IO3_PC4 = AnyAltOut<Port::PC, 4, AfQUADSPI1_BK2_IO3_PC4>;
/// A default configuration to map QUADSPI1 CLK on PA3 pin
using QUADSPI1_CLK_PA3 = AnyAltOut<Port::PA, 3, AfQUADSPI1_CLK_PA3>;
/// A default configuration to map QUADSPI1 CLK on PB10 pin
using QUADSPI1_CLK_PB10 = AnyAltOut<Port::PB, 10, AfQUADSPI1_CLK_PB10>;
#if defined(GPIOD_BASE)
/// A default configuration to map QUADSPI1 BK2_IO0 on PD4 pin
using QUADSPI1_BK2_IO0_PD4 = AnyAltOut<Port::PD, 4, AfQUADSPI1_BK2_IO0_PD4>;
/// A default configuration to map QUADSPI1 BK2_IO1 on PD5 pin
using QUADSPI1_BK2_IO1_PD5 = AnyAltOut<Port::PD, 5, AfQUADSPI1_BK2_IO1_PD5>;
/// A default configuration to map QUADSPI1 BK2_IO2 on PD6 pin
using QUADSPI1_BK2_IO2_PD6 = AnyAltOut<Port::PD, 6, AfQUADSPI1_BK2_IO2_PD6>;
/// A default configuration to map QUADSPI1 BK2_IO3 on PD7 pin
using QUADSPI1_BK2_IO3_PD7 = AnyAltOut<Port::PD, 7, AfQUADSPI1_BK2_IO3_PD7>;
/// A default configuration to map QUADSPI1 BK2_NCS on PD3 pin
using QUADSPI1_BK2_NCS_PD3 = AnyAltOut<Port::PD, 3, AfQUADSPI1_BK2_NCS_PD3>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map QUADSPI1 BK1_IO0 on PE12 pin
using QUADSPI1_BK1_IO0_PE12 = AnyAltOut<Port::PE, 12, AfQUADSPI1_BK1_IO0_PE12>;
/// A default configuration to map QUADSPI1 BK1_IO1 on PE13 pin
using QUADSPI1_BK1_IO1_PE13 = AnyAltOut<Port::PE, 13, AfQUADSPI1_BK1_IO1_PE13>;
/// A default configuration to map QUADSPI1 BK1_IO2 on PE14 pin
using QUADSPI1_BK1_IO2_PE14 = AnyAltOut<Port::PE, 14, AfQUADSPI1_BK1_IO2_PE14>;
/// A default configuration to map QUADSPI1 BK1_IO3 on PE15 pin
using QUADSPI1_BK1_IO3_PE15 = AnyAltOut<Port::PE, 15, AfQUADSPI1_BK1_IO3_PE15>;
/// A default configuration to map QUADSPI1 BK1_NCS on PE11 pin
using QUADSPI1_BK1_NCS_PE11 = AnyAltOut<Port::PE, 11, AfQUADSPI1_BK1_NCS_PE11>;
/// A default configuration to map QUADSPI1 CLK on PE10 pin
using QUADSPI1_CLK_PE10 = AnyAltOut<Port::PE, 10, AfQUADSPI1_CLK_PE10>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map QUADSPI1 BK1_IO0 on PF8 pin
using QUADSPI1_BK1_IO0_PF8 = AnyAltOut<Port::PF, 8, AfQUADSPI1_BK1_IO0_PF8>;
/// A default configuration to map QUADSPI1 BK1_IO1 on PF9 pin
using QUADSPI1_BK1_IO1_PF9 = AnyAltOut<Port::PF, 9, AfQUADSPI1_BK1_IO1_PF9>;
/// A default configuration to map QUADSPI1 BK1_IO2 on PF7 pin
using QUADSPI1_BK1_IO2_PF7 = AnyAltOut<Port::PF, 7, AfQUADSPI1_BK1_IO2_PF7>;
/// A default configuration to map QUADSPI1 BK1_IO3 on PF6 pin
using QUADSPI1_BK1_IO3_PF6 = AnyAltOut<Port::PF, 6, AfQUADSPI1_BK1_IO3_PF6>;
/// A default configuration to map QUADSPI1 CLK on PF10 pin
using QUADSPI1_CLK_PF10 = AnyAltOut<Port::PF, 10, AfQUADSPI1_CLK_PF10>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(QUADSPI)

//////////////////////////////////////////////////////////////////////
// RTC
//////////////////////////////////////////////////////////////////////
#if defined(RTC_BASE)
/// A default configuration to map RTC OUT2 on PB2 pin
using RTC_OUT2_PB2 = AnyAltOut<Port::PB, 2, AfRTC_OUT2_PB2>;
/// A default configuration to map RTC REFIN on PA1 pin
using RTC_REFIN_PA1 = AnyAltOut<Port::PA, 1, AfRTC_REFIN_PA1>;
/// A default configuration to map RTC REFIN on PB15 pin
using RTC_REFIN_PB15 = AnyAltOut<Port::PB, 15, AfRTC_REFIN_PB15>;
#endif	// defined(RTC_BASE)

//////////////////////////////////////////////////////////////////////
// SAI1
//////////////////////////////////////////////////////////////////////
#if defined(SAI1_BASE)
/// A default configuration to map SAI1 CK1 on PA3 pin
using SAI1_CK1_PA3 = AnyAltOut<Port::PA, 3, AfSAI1_CK1_PA3>;
/// A default configuration to map SAI1 CK1 on PB8 pin
using SAI1_CK1_PB8 = AnyAltOut<Port::PB, 8, AfSAI1_CK1_PB8>;
/// A default configuration to map SAI1 CK2 on PA8 pin
using SAI1_CK2_PA8 = AnyAltOut<Port::PA, 8, AfSAI1_CK2_PA8>;
/// A default configuration to map SAI1 D1 on PA10 pin
using SAI1_D1_PA10 = AnyAltOut<Port::PA, 10, AfSAI1_D1_PA10>;
/// A default configuration to map SAI1 D1 on PC3 pin
using SAI1_D1_PC3 = AnyAltOut<Port::PC, 3, AfSAI1_D1_PC3>;
/// A default configuration to map SAI1 D2 on PB9 pin
using SAI1_D2_PB9 = AnyAltOut<Port::PB, 9, AfSAI1_D2_PB9>;
/// A default configuration to map SAI1 D3 on PC5 pin
using SAI1_D3_PC5 = AnyAltOut<Port::PC, 5, AfSAI1_D3_PC5>;
/// A default configuration to map SAI1 FS_A on PA9 pin
using SAI1_FS_A_PA9 = AnyAltOut<Port::PA, 9, AfSAI1_FS_A_PA9>;
/// A default configuration to map SAI1 FS_A on PB9 pin
using SAI1_FS_A_PB9 = AnyAltOut<Port::PB, 9, AfSAI1_FS_A_PB9>;
/// A default configuration to map SAI1 FS_B on PA4 pin
using SAI1_FS_B_PA4 = AnyAltOut<Port::PA, 4, AfSAI1_FS_B_PA4>;
/// A default configuration to map SAI1 FS_B on PA14 pin
using SAI1_FS_B_PA14 = AnyAltOut<Port::PA, 14, AfSAI1_FS_B_PA14>;
/// A default configuration to map SAI1 FS_B on PB6 pin
using SAI1_FS_B_PB6 = AnyAltOut<Port::PB, 6, AfSAI1_FS_B_PB6>;
/// A default configuration to map SAI1 MCLK_A on PA3 pin
using SAI1_MCLK_A_PA3 = AnyAltOut<Port::PA, 3, AfSAI1_MCLK_A_PA3>;
/// A default configuration to map SAI1 MCLK_A on PB8 pin
using SAI1_MCLK_A_PB8 = AnyAltOut<Port::PB, 8, AfSAI1_MCLK_A_PB8>;
/// A default configuration to map SAI1 MCLK_B on PB4 pin
using SAI1_MCLK_B_PB4 = AnyAltOut<Port::PB, 4, AfSAI1_MCLK_B_PB4>;
/// A default configuration to map SAI1 SCK_A on PA8 pin
using SAI1_SCK_A_PA8 = AnyAltOut<Port::PA, 8, AfSAI1_SCK_A_PA8>;
/// A default configuration to map SAI1 SCK_A on PB10 pin
using SAI1_SCK_A_PB10 = AnyAltOut<Port::PB, 10, AfSAI1_SCK_A_PB10>;
/// A default configuration to map SAI1 SCK_B on PB3 pin
using SAI1_SCK_B_PB3 = AnyAltOut<Port::PB, 3, AfSAI1_SCK_B_PB3>;
/// A default configuration to map SAI1 SD_A on PA10 pin
using SAI1_SD_A_PA10 = AnyAltOut<Port::PA, 10, AfSAI1_SD_A_PA10>;
/// A default configuration to map SAI1 SD_A on PC1 pin
using SAI1_SD_A_PC1 = AnyAltOut<Port::PC, 1, AfSAI1_SD_A_PC1>;
/// A default configuration to map SAI1 SD_A on PC3 pin
using SAI1_SD_A_PC3 = AnyAltOut<Port::PC, 3, AfSAI1_SD_A_PC3>;
/// A default configuration to map SAI1 SD_B on PA13 pin
using SAI1_SD_B_PA13 = AnyAltOut<Port::PA, 13, AfSAI1_SD_B_PA13>;
/// A default configuration to map SAI1 SD_B on PB5 pin
using SAI1_SD_B_PB5 = AnyAltOut<Port::PB, 5, AfSAI1_SD_B_PB5>;
#if defined(GPIOD_BASE)
/// A default configuration to map SAI1 D1 on PD6 pin
using SAI1_D1_PD6 = AnyAltOut<Port::PD, 6, AfSAI1_D1_PD6>;
/// A default configuration to map SAI1 SD_A on PD6 pin
using SAI1_SD_A_PD6 = AnyAltOut<Port::PD, 6, AfSAI1_SD_A_PD6>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map SAI1 CK1 on PE2 pin
using SAI1_CK1_PE2 = AnyAltOut<Port::PE, 2, AfSAI1_CK1_PE2>;
/// A default configuration to map SAI1 CK2 on PE5 pin
using SAI1_CK2_PE5 = AnyAltOut<Port::PE, 5, AfSAI1_CK2_PE5>;
/// A default configuration to map SAI1 D1 on PE6 pin
using SAI1_D1_PE6 = AnyAltOut<Port::PE, 6, AfSAI1_D1_PE6>;
/// A default configuration to map SAI1 D2 on PE4 pin
using SAI1_D2_PE4 = AnyAltOut<Port::PE, 4, AfSAI1_D2_PE4>;
/// A default configuration to map SAI1 FS_A on PE4 pin
using SAI1_FS_A_PE4 = AnyAltOut<Port::PE, 4, AfSAI1_FS_A_PE4>;
/// A default configuration to map SAI1 FS_B on PE9 pin
using SAI1_FS_B_PE9 = AnyAltOut<Port::PE, 9, AfSAI1_FS_B_PE9>;
/// A default configuration to map SAI1 MCLK_A on PE2 pin
using SAI1_MCLK_A_PE2 = AnyAltOut<Port::PE, 2, AfSAI1_MCLK_A_PE2>;
/// A default configuration to map SAI1 MCLK_B on PE10 pin
using SAI1_MCLK_B_PE10 = AnyAltOut<Port::PE, 10, AfSAI1_MCLK_B_PE10>;
/// A default configuration to map SAI1 SCK_A on PE5 pin
using SAI1_SCK_A_PE5 = AnyAltOut<Port::PE, 5, AfSAI1_SCK_A_PE5>;
/// A default configuration to map SAI1 SCK_B on PE8 pin
using SAI1_SCK_B_PE8 = AnyAltOut<Port::PE, 8, AfSAI1_SCK_B_PE8>;
/// A default configuration to map SAI1 SD_A on PE6 pin
using SAI1_SD_A_PE6 = AnyAltOut<Port::PE, 6, AfSAI1_SD_A_PE6>;
/// A default configuration to map SAI1 SD_B on PE3 pin
using SAI1_SD_B_PE3 = AnyAltOut<Port::PE, 3, AfSAI1_SD_B_PE3>;
/// A default configuration to map SAI1 SD_B on PE7 pin
using SAI1_SD_B_PE7 = AnyAltOut<Port::PE, 7, AfSAI1_SD_B_PE7>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map SAI1 D3 on PF10 pin
using SAI1_D3_PF10 = AnyAltOut<Port::PF, 10, AfSAI1_D3_PF10>;
/// A default configuration to map SAI1 FS_B on PF9 pin
using SAI1_FS_B_PF9 = AnyAltOut<Port::PF, 9, AfSAI1_FS_B_PF9>;
/// A default configuration to map SAI1 MCLK_B on PF7 pin
using SAI1_MCLK_B_PF7 = AnyAltOut<Port::PF, 7, AfSAI1_MCLK_B_PF7>;
/// A default configuration to map SAI1 SCK_B on PF8 pin
using SAI1_SCK_B_PF8 = AnyAltOut<Port::PF, 8, AfSAI1_SCK_B_PF8>;
/// A default configuration to map SAI1 SD_B on PF6 pin
using SAI1_SD_B_PF6 = AnyAltOut<Port::PF, 6, AfSAI1_SD_B_PF6>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map SAI1 CK1 on PG7 pin
using SAI1_CK1_PG7 = AnyAltOut<Port::PG, 7, AfSAI1_CK1_PG7>;
/// A default configuration to map SAI1 MCLK_A on PG7 pin
using SAI1_MCLK_A_PG7 = AnyAltOut<Port::PG, 7, AfSAI1_MCLK_A_PG7>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(SAI1_BASE)

//////////////////////////////////////////////////////////////////////
// SPI1
//////////////////////////////////////////////////////////////////////
#if defined(SPI1_BASE)
/// A default configuration to map SPI1 MISO on PA6 pin
using SPI1_MISO_PA6 = AnyAltOut<Port::PA, 6, AfSPI1_MISO_PA6>;
/// A default configuration to map SPI1 MISO on PB4 pin
using SPI1_MISO_PB4 = AnyAltOut<Port::PB, 4, AfSPI1_MISO_PB4>;
/// A default configuration to map SPI1 MOSI on PA7 pin
using SPI1_MOSI_PA7 = AnyAltOut<Port::PA, 7, AfSPI1_MOSI_PA7>;
/// A default configuration to map SPI1 MOSI on PB5 pin
using SPI1_MOSI_PB5 = AnyAltOut<Port::PB, 5, AfSPI1_MOSI_PB5>;
/// A default configuration to map SPI1 NSS on PA4 pin
using SPI1_NSS_PA4 = AnyAltOut<Port::PA, 4, AfSPI1_NSS_PA4>;
/// A default configuration to map SPI1 NSS on PA15 pin
using SPI1_NSS_PA15 = AnyAltOut<Port::PA, 15, AfSPI1_NSS_PA15>;
/// A default configuration to map SPI1 SCK on PA5 pin
using SPI1_SCK_PA5 = AnyAltOut<Port::PA, 5, AfSPI1_SCK_PA5>;
/// A default configuration to map SPI1 SCK on PB3 pin
using SPI1_SCK_PB3 = AnyAltOut<Port::PB, 3, AfSPI1_SCK_PB3>;
#if defined(GPIOG_BASE)
/// A default configuration to map SPI1 MISO on PG3 pin
using SPI1_MISO_PG3 = AnyAltOut<Port::PG, 3, AfSPI1_MISO_PG3>;
/// A default configuration to map SPI1 MOSI on PG4 pin
using SPI1_MOSI_PG4 = AnyAltOut<Port::PG, 4, AfSPI1_MOSI_PG4>;
/// A default configuration to map SPI1 NSS on PG5 pin
using SPI1_NSS_PG5 = AnyAltOut<Port::PG, 5, AfSPI1_NSS_PG5>;
/// A default configuration to map SPI1 SCK on PG2 pin
using SPI1_SCK_PG2 = AnyAltOut<Port::PG, 2, AfSPI1_SCK_PG2>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(SPI1_BASE)

//////////////////////////////////////////////////////////////////////
// SPI2
//////////////////////////////////////////////////////////////////////
#if defined(SPI2_BASE)
/// A default configuration to map SPI2 MISO on PA10 pin
using SPI2_MISO_PA10 = AnyAltOut<Port::PA, 10, AfSPI2_MISO_PA10>;
/// A default configuration to map SPI2 MISO on PB14 pin
using SPI2_MISO_PB14 = AnyAltOut<Port::PB, 14, AfSPI2_MISO_PB14>;
/// A default configuration to map SPI2 MOSI on PA11 pin
using SPI2_MOSI_PA11 = AnyAltOut<Port::PA, 11, AfSPI2_MOSI_PA11>;
/// A default configuration to map SPI2 MOSI on PB15 pin
using SPI2_MOSI_PB15 = AnyAltOut<Port::PB, 15, AfSPI2_MOSI_PB15>;
/// A default configuration to map SPI2 NSS on PB12 pin
using SPI2_NSS_PB12 = AnyAltOut<Port::PB, 12, AfSPI2_NSS_PB12>;
/// A default configuration to map SPI2 SCK on PB13 pin
using SPI2_SCK_PB13 = AnyAltOut<Port::PB, 13, AfSPI2_SCK_PB13>;
#if defined(GPIOD_BASE)
/// A default configuration to map SPI2 NSS on PD15 pin
using SPI2_NSS_PD15 = AnyAltOut<Port::PD, 15, AfSPI2_NSS_PD15>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map SPI2 NSS on PF0 pin
using SPI2_NSS_PF0 = AnyAltOut<Port::PF, 0, AfSPI2_NSS_PF0>;
/// A default configuration to map SPI2 SCK on PF1 pin
using SPI2_SCK_PF1 = AnyAltOut<Port::PF, 1, AfSPI2_SCK_PF1>;
/// A default configuration to map SPI2 SCK on PF9 pin
using SPI2_SCK_PF9 = AnyAltOut<Port::PF, 9, AfSPI2_SCK_PF9>;
/// A default configuration to map SPI2 SCK on PF10 pin
using SPI2_SCK_PF10 = AnyAltOut<Port::PF, 10, AfSPI2_SCK_PF10>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(SPI2_BASE)

//////////////////////////////////////////////////////////////////////
// SPI3
//////////////////////////////////////////////////////////////////////
#if defined(SPI3_BASE)
/// A default configuration to map SPI3 MISO on PB4 pin
using SPI3_MISO_PB4 = AnyAltOut<Port::PB, 4, AfSPI3_MISO_PB4>;
/// A default configuration to map SPI3 MISO on PC11 pin
using SPI3_MISO_PC11 = AnyAltOut<Port::PC, 11, AfSPI3_MISO_PC11>;
/// A default configuration to map SPI3 MOSI on PB5 pin
using SPI3_MOSI_PB5 = AnyAltOut<Port::PB, 5, AfSPI3_MOSI_PB5>;
/// A default configuration to map SPI3 MOSI on PC12 pin
using SPI3_MOSI_PC12 = AnyAltOut<Port::PC, 12, AfSPI3_MOSI_PC12>;
/// A default configuration to map SPI3 NSS on PA4 pin
using SPI3_NSS_PA4 = AnyAltOut<Port::PA, 4, AfSPI3_NSS_PA4>;
/// A default configuration to map SPI3 NSS on PA15 pin
using SPI3_NSS_PA15 = AnyAltOut<Port::PA, 15, AfSPI3_NSS_PA15>;
/// A default configuration to map SPI3 SCK on PB3 pin
using SPI3_SCK_PB3 = AnyAltOut<Port::PB, 3, AfSPI3_SCK_PB3>;
/// A default configuration to map SPI3 SCK on PC10 pin
using SPI3_SCK_PC10 = AnyAltOut<Port::PC, 10, AfSPI3_SCK_PC10>;
#if defined(GPIOG_BASE)
/// A default configuration to map SPI3 SCK on PG9 pin
using SPI3_SCK_PG9 = AnyAltOut<Port::PG, 9, AfSPI3_SCK_PG9>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(SPI3_BASE)

//////////////////////////////////////////////////////////////////////
// SPI4
//////////////////////////////////////////////////////////////////////
#if defined(SPI4_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map SPI4 MISO on PE5 pin
using SPI4_MISO_PE5 = AnyAltOut<Port::PE, 5, AfSPI4_MISO_PE5>;
/// A default configuration to map SPI4 MISO on PE13 pin
using SPI4_MISO_PE13 = AnyAltOut<Port::PE, 13, AfSPI4_MISO_PE13>;
/// A default configuration to map SPI4 MOSI on PE6 pin
using SPI4_MOSI_PE6 = AnyAltOut<Port::PE, 6, AfSPI4_MOSI_PE6>;
/// A default configuration to map SPI4 MOSI on PE14 pin
using SPI4_MOSI_PE14 = AnyAltOut<Port::PE, 14, AfSPI4_MOSI_PE14>;
/// A default configuration to map SPI4 NSS on PE3 pin
using SPI4_NSS_PE3 = AnyAltOut<Port::PE, 3, AfSPI4_NSS_PE3>;
/// A default configuration to map SPI4 NSS on PE4 pin
using SPI4_NSS_PE4 = AnyAltOut<Port::PE, 4, AfSPI4_NSS_PE4>;
/// A default configuration to map SPI4 NSS on PE11 pin
using SPI4_NSS_PE11 = AnyAltOut<Port::PE, 11, AfSPI4_NSS_PE11>;
/// A default configuration to map SPI4 SCK on PE2 pin
using SPI4_SCK_PE2 = AnyAltOut<Port::PE, 2, AfSPI4_SCK_PE2>;
/// A default configuration to map SPI4 SCK on PE12 pin
using SPI4_SCK_PE12 = AnyAltOut<Port::PE, 12, AfSPI4_SCK_PE12>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(SPI4_BASE)

//////////////////////////////////////////////////////////////////////
// TIM1
//////////////////////////////////////////////////////////////////////
#if defined(TIM1_BASE)
/// A default configuration to map TIM1 BKIN on PA6 pin
using TIM1_BKIN_PA6 = AnyAltOut<Port::PA, 6, AfTIM1_BKIN_PA6>;
/// A default configuration to map TIM1 BKIN on PA14 pin
using TIM1_BKIN_PA14 = AnyAltOut<Port::PA, 14, AfTIM1_BKIN_PA14>;
/// A default configuration to map TIM1 BKIN on PA15 pin
using TIM1_BKIN_PA15 = AnyAltOut<Port::PA, 15, AfTIM1_BKIN_PA15>;
/// A default configuration to map TIM1 BKIN on PB8 pin
using TIM1_BKIN_PB8 = AnyAltOut<Port::PB, 8, AfTIM1_BKIN_PB8>;
/// A default configuration to map TIM1 BKIN on PB10 pin
using TIM1_BKIN_PB10 = AnyAltOut<Port::PB, 10, AfTIM1_BKIN_PB10>;
/// A default configuration to map TIM1 BKIN on PB12 pin
using TIM1_BKIN_PB12 = AnyAltOut<Port::PB, 12, AfTIM1_BKIN_PB12>;
/// A default configuration to map TIM1 BKIN on PC13 pin
using TIM1_BKIN_PC13 = AnyAltOut<Port::PC, 13, AfTIM1_BKIN_PC13>;
/// A default configuration to map TIM1 BKIN2 on PA11 pin
using TIM1_BKIN2_PA11 = AnyAltOut<Port::PA, 11, AfTIM1_BKIN2_PA11>;
/// A default configuration to map TIM1 BKIN2 on PC3 pin
using TIM1_BKIN2_PC3 = AnyAltOut<Port::PC, 3, AfTIM1_BKIN2_PC3>;
/// A default configuration to map TIM1 CH1 on PA8 pin
using TIM1_CH1_PA8 = AnyAltOut<Port::PA, 8, AfTIM1_CH1_PA8>;
/// A default configuration to map TIM1 CH1 on PC0 pin
using TIM1_CH1_PC0 = AnyAltOut<Port::PC, 0, AfTIM1_CH1_PC0>;
/// A default configuration to map TIM1 CH1N on PA7 pin
using TIM1_CH1N_PA7 = AnyAltOut<Port::PA, 7, AfTIM1_CH1N_PA7>;
/// A default configuration to map TIM1 CH1N on PA11 pin
using TIM1_CH1N_PA11 = AnyAltOut<Port::PA, 11, AfTIM1_CH1N_PA11>;
/// A default configuration to map TIM1 CH1N on PB13 pin
using TIM1_CH1N_PB13 = AnyAltOut<Port::PB, 13, AfTIM1_CH1N_PB13>;
/// A default configuration to map TIM1 CH1N on PC13 pin
using TIM1_CH1N_PC13 = AnyAltOut<Port::PC, 13, AfTIM1_CH1N_PC13>;
/// A default configuration to map TIM1 CH2 on PA9 pin
using TIM1_CH2_PA9 = AnyAltOut<Port::PA, 9, AfTIM1_CH2_PA9>;
/// A default configuration to map TIM1 CH2 on PC1 pin
using TIM1_CH2_PC1 = AnyAltOut<Port::PC, 1, AfTIM1_CH2_PC1>;
/// A default configuration to map TIM1 CH2N on PA12 pin
using TIM1_CH2N_PA12 = AnyAltOut<Port::PA, 12, AfTIM1_CH2N_PA12>;
/// A default configuration to map TIM1 CH2N on PB0 pin
using TIM1_CH2N_PB0 = AnyAltOut<Port::PB, 0, AfTIM1_CH2N_PB0>;
/// A default configuration to map TIM1 CH2N on PB14 pin
using TIM1_CH2N_PB14 = AnyAltOut<Port::PB, 14, AfTIM1_CH2N_PB14>;
/// A default configuration to map TIM1 CH3 on PA10 pin
using TIM1_CH3_PA10 = AnyAltOut<Port::PA, 10, AfTIM1_CH3_PA10>;
/// A default configuration to map TIM1 CH3 on PC2 pin
using TIM1_CH3_PC2 = AnyAltOut<Port::PC, 2, AfTIM1_CH3_PC2>;
/// A default configuration to map TIM1 CH3N on PB1 pin
using TIM1_CH3N_PB1 = AnyAltOut<Port::PB, 1, AfTIM1_CH3N_PB1>;
/// A default configuration to map TIM1 CH3N on PB9 pin
using TIM1_CH3N_PB9 = AnyAltOut<Port::PB, 9, AfTIM1_CH3N_PB9>;
/// A default configuration to map TIM1 CH3N on PB15 pin
using TIM1_CH3N_PB15 = AnyAltOut<Port::PB, 15, AfTIM1_CH3N_PB15>;
/// A default configuration to map TIM1 CH4 on PA11 pin
using TIM1_CH4_PA11 = AnyAltOut<Port::PA, 11, AfTIM1_CH4_PA11>;
/// A default configuration to map TIM1 CH4 on PC3 pin
using TIM1_CH4_PC3 = AnyAltOut<Port::PC, 3, AfTIM1_CH4_PC3>;
/// A default configuration to map TIM1 CH4N on PC5 pin
using TIM1_CH4N_PC5 = AnyAltOut<Port::PC, 5, AfTIM1_CH4N_PC5>;
/// A default configuration to map TIM1 ETR on PA12 pin
using TIM1_ETR_PA12 = AnyAltOut<Port::PA, 12, AfTIM1_ETR_PA12>;
/// A default configuration to map TIM1 ETR on PC4 pin
using TIM1_ETR_PC4 = AnyAltOut<Port::PC, 4, AfTIM1_ETR_PC4>;
#if defined(GPIOE_BASE)
/// A default configuration to map TIM1 BKIN on PE15 pin
using TIM1_BKIN_PE15 = AnyAltOut<Port::PE, 15, AfTIM1_BKIN_PE15>;
/// A default configuration to map TIM1 BKIN2 on PE14 pin
using TIM1_BKIN2_PE14 = AnyAltOut<Port::PE, 14, AfTIM1_BKIN2_PE14>;
/// A default configuration to map TIM1 CH1 on PE9 pin
using TIM1_CH1_PE9 = AnyAltOut<Port::PE, 9, AfTIM1_CH1_PE9>;
/// A default configuration to map TIM1 CH1N on PE8 pin
using TIM1_CH1N_PE8 = AnyAltOut<Port::PE, 8, AfTIM1_CH1N_PE8>;
/// A default configuration to map TIM1 CH2 on PE11 pin
using TIM1_CH2_PE11 = AnyAltOut<Port::PE, 11, AfTIM1_CH2_PE11>;
/// A default configuration to map TIM1 CH2N on PE10 pin
using TIM1_CH2N_PE10 = AnyAltOut<Port::PE, 10, AfTIM1_CH2N_PE10>;
/// A default configuration to map TIM1 CH3 on PE13 pin
using TIM1_CH3_PE13 = AnyAltOut<Port::PE, 13, AfTIM1_CH3_PE13>;
/// A default configuration to map TIM1 CH3N on PE12 pin
using TIM1_CH3N_PE12 = AnyAltOut<Port::PE, 12, AfTIM1_CH3N_PE12>;
/// A default configuration to map TIM1 CH4 on PE14 pin
using TIM1_CH4_PE14 = AnyAltOut<Port::PE, 14, AfTIM1_CH4_PE14>;
/// A default configuration to map TIM1 CH4N on PE15 pin
using TIM1_CH4N_PE15 = AnyAltOut<Port::PE, 15, AfTIM1_CH4N_PE15>;
/// A default configuration to map TIM1 ETR on PE7 pin
using TIM1_ETR_PE7 = AnyAltOut<Port::PE, 7, AfTIM1_ETR_PE7>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map TIM1 CH3N on PF0 pin
using TIM1_CH3N_PF0 = AnyAltOut<Port::PF, 0, AfTIM1_CH3N_PF0>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(TIM1_BASE)

//////////////////////////////////////////////////////////////////////
// TIM2
//////////////////////////////////////////////////////////////////////
#if defined(TIM2_BASE)
/// A default configuration to map TIM2 CH1 on PA0 pin
using TIM2_CH1_PA0 = AnyAltOut<Port::PA, 0, AfTIM2_CH1_PA0>;
/// A default configuration to map TIM2 CH1 on PA5 pin
using TIM2_CH1_PA5 = AnyAltOut<Port::PA, 5, AfTIM2_CH1_PA5>;
/// A default configuration to map TIM2 CH1 on PA15 pin
using TIM2_CH1_PA15 = AnyAltOut<Port::PA, 15, AfTIM2_CH1_PA15>;
/// A default configuration to map TIM2 CH2 on PA1 pin
using TIM2_CH2_PA1 = AnyAltOut<Port::PA, 1, AfTIM2_CH2_PA1>;
/// A default configuration to map TIM2 CH2 on PB3 pin
using TIM2_CH2_PB3 = AnyAltOut<Port::PB, 3, AfTIM2_CH2_PB3>;
/// A default configuration to map TIM2 CH3 on PA2 pin
using TIM2_CH3_PA2 = AnyAltOut<Port::PA, 2, AfTIM2_CH3_PA2>;
/// A default configuration to map TIM2 CH3 on PA9 pin
using TIM2_CH3_PA9 = AnyAltOut<Port::PA, 9, AfTIM2_CH3_PA9>;
/// A default configuration to map TIM2 CH3 on PB10 pin
using TIM2_CH3_PB10 = AnyAltOut<Port::PB, 10, AfTIM2_CH3_PB10>;
/// A default configuration to map TIM2 CH4 on PA3 pin
using TIM2_CH4_PA3 = AnyAltOut<Port::PA, 3, AfTIM2_CH4_PA3>;
/// A default configuration to map TIM2 CH4 on PA10 pin
using TIM2_CH4_PA10 = AnyAltOut<Port::PA, 10, AfTIM2_CH4_PA10>;
/// A default configuration to map TIM2 CH4 on PB11 pin
using TIM2_CH4_PB11 = AnyAltOut<Port::PB, 11, AfTIM2_CH4_PB11>;
/// A default configuration to map TIM2 ETR on PA0 pin
using TIM2_ETR_PA0 = AnyAltOut<Port::PA, 0, AfTIM2_ETR_PA0>;
/// A default configuration to map TIM2 ETR on PA5 pin
using TIM2_ETR_PA5 = AnyAltOut<Port::PA, 5, AfTIM2_ETR_PA5>;
/// A default configuration to map TIM2 ETR on PA15 pin
using TIM2_ETR_PA15 = AnyAltOut<Port::PA, 15, AfTIM2_ETR_PA15>;
#if defined(GPIOD_BASE)
/// A default configuration to map TIM2 CH1 on PD3 pin
using TIM2_CH1_PD3 = AnyAltOut<Port::PD, 3, AfTIM2_CH1_PD3>;
/// A default configuration to map TIM2 CH2 on PD4 pin
using TIM2_CH2_PD4 = AnyAltOut<Port::PD, 4, AfTIM2_CH2_PD4>;
/// A default configuration to map TIM2 CH3 on PD7 pin
using TIM2_CH3_PD7 = AnyAltOut<Port::PD, 7, AfTIM2_CH3_PD7>;
/// A default configuration to map TIM2 CH4 on PD6 pin
using TIM2_CH4_PD6 = AnyAltOut<Port::PD, 6, AfTIM2_CH4_PD6>;
/// A default configuration to map TIM2 ETR on PD3 pin
using TIM2_ETR_PD3 = AnyAltOut<Port::PD, 3, AfTIM2_ETR_PD3>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(TIM2_BASE)

//////////////////////////////////////////////////////////////////////
// TIM3
//////////////////////////////////////////////////////////////////////
#if defined(TIM3_BASE)
/// A default configuration to map TIM3 CH1 on PA6 pin
using TIM3_CH1_PA6 = AnyAltOut<Port::PA, 6, AfTIM3_CH1_PA6>;
/// A default configuration to map TIM3 CH1 on PB4 pin
using TIM3_CH1_PB4 = AnyAltOut<Port::PB, 4, AfTIM3_CH1_PB4>;
/// A default configuration to map TIM3 CH1 on PC6 pin
using TIM3_CH1_PC6 = AnyAltOut<Port::PC, 6, AfTIM3_CH1_PC6>;
/// A default configuration to map TIM3 CH2 on PA4 pin
using TIM3_CH2_PA4 = AnyAltOut<Port::PA, 4, AfTIM3_CH2_PA4>;
/// A default configuration to map TIM3 CH2 on PA7 pin
using TIM3_CH2_PA7 = AnyAltOut<Port::PA, 7, AfTIM3_CH2_PA7>;
/// A default configuration to map TIM3 CH2 on PB5 pin
using TIM3_CH2_PB5 = AnyAltOut<Port::PB, 5, AfTIM3_CH2_PB5>;
/// A default configuration to map TIM3 CH2 on PC7 pin
using TIM3_CH2_PC7 = AnyAltOut<Port::PC, 7, AfTIM3_CH2_PC7>;
/// A default configuration to map TIM3 CH3 on PB0 pin
using TIM3_CH3_PB0 = AnyAltOut<Port::PB, 0, AfTIM3_CH3_PB0>;
/// A default configuration to map TIM3 CH3 on PC8 pin
using TIM3_CH3_PC8 = AnyAltOut<Port::PC, 8, AfTIM3_CH3_PC8>;
/// A default configuration to map TIM3 CH4 on PB1 pin
using TIM3_CH4_PB1 = AnyAltOut<Port::PB, 1, AfTIM3_CH4_PB1>;
/// A default configuration to map TIM3 CH4 on PB7 pin
using TIM3_CH4_PB7 = AnyAltOut<Port::PB, 7, AfTIM3_CH4_PB7>;
/// A default configuration to map TIM3 CH4 on PC9 pin
using TIM3_CH4_PC9 = AnyAltOut<Port::PC, 9, AfTIM3_CH4_PC9>;
/// A default configuration to map TIM3 ETR on PB3 pin
using TIM3_ETR_PB3 = AnyAltOut<Port::PB, 3, AfTIM3_ETR_PB3>;
#if defined(GPIOD_BASE)
/// A default configuration to map TIM3 ETR on PD2 pin
using TIM3_ETR_PD2 = AnyAltOut<Port::PD, 2, AfTIM3_ETR_PD2>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map TIM3 CH1 on PE2 pin
using TIM3_CH1_PE2 = AnyAltOut<Port::PE, 2, AfTIM3_CH1_PE2>;
/// A default configuration to map TIM3 CH2 on PE3 pin
using TIM3_CH2_PE3 = AnyAltOut<Port::PE, 3, AfTIM3_CH2_PE3>;
/// A default configuration to map TIM3 CH3 on PE4 pin
using TIM3_CH3_PE4 = AnyAltOut<Port::PE, 4, AfTIM3_CH3_PE4>;
/// A default configuration to map TIM3 CH4 on PE5 pin
using TIM3_CH4_PE5 = AnyAltOut<Port::PE, 5, AfTIM3_CH4_PE5>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM3_BASE)

//////////////////////////////////////////////////////////////////////
// TIM4
//////////////////////////////////////////////////////////////////////
#if defined(TIM4_BASE)
/// A default configuration to map TIM4 CH1 on PA11 pin
using TIM4_CH1_PA11 = AnyAltOut<Port::PA, 11, AfTIM4_CH1_PA11>;
/// A default configuration to map TIM4 CH1 on PB6 pin
using TIM4_CH1_PB6 = AnyAltOut<Port::PB, 6, AfTIM4_CH1_PB6>;
/// A default configuration to map TIM4 CH2 on PA12 pin
using TIM4_CH2_PA12 = AnyAltOut<Port::PA, 12, AfTIM4_CH2_PA12>;
/// A default configuration to map TIM4 CH2 on PB7 pin
using TIM4_CH2_PB7 = AnyAltOut<Port::PB, 7, AfTIM4_CH2_PB7>;
/// A default configuration to map TIM4 CH3 on PA13 pin
using TIM4_CH3_PA13 = AnyAltOut<Port::PA, 13, AfTIM4_CH3_PA13>;
/// A default configuration to map TIM4 CH3 on PB8 pin
using TIM4_CH3_PB8 = AnyAltOut<Port::PB, 8, AfTIM4_CH3_PB8>;
/// A default configuration to map TIM4 CH4 on PB9 pin
using TIM4_CH4_PB9 = AnyAltOut<Port::PB, 9, AfTIM4_CH4_PB9>;
/// A default configuration to map TIM4 ETR on PA8 pin
using TIM4_ETR_PA8 = AnyAltOut<Port::PA, 8, AfTIM4_ETR_PA8>;
/// A default configuration to map TIM4 ETR on PB3 pin
using TIM4_ETR_PB3 = AnyAltOut<Port::PB, 3, AfTIM4_ETR_PB3>;
#if defined(GPIOD_BASE)
/// A default configuration to map TIM4 CH1 on PD12 pin
using TIM4_CH1_PD12 = AnyAltOut<Port::PD, 12, AfTIM4_CH1_PD12>;
/// A default configuration to map TIM4 CH2 on PD13 pin
using TIM4_CH2_PD13 = AnyAltOut<Port::PD, 13, AfTIM4_CH2_PD13>;
/// A default configuration to map TIM4 CH3 on PD14 pin
using TIM4_CH3_PD14 = AnyAltOut<Port::PD, 14, AfTIM4_CH3_PD14>;
/// A default configuration to map TIM4 CH4 on PD15 pin
using TIM4_CH4_PD15 = AnyAltOut<Port::PD, 15, AfTIM4_CH4_PD15>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map TIM4 ETR on PE0 pin
using TIM4_ETR_PE0 = AnyAltOut<Port::PE, 0, AfTIM4_ETR_PE0>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map TIM4 CH4 on PF6 pin
using TIM4_CH4_PF6 = AnyAltOut<Port::PF, 6, AfTIM4_CH4_PF6>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(TIM4_BASE)

//////////////////////////////////////////////////////////////////////
// TIM5
//////////////////////////////////////////////////////////////////////
#if defined(TIM5_BASE)
/// A default configuration to map TIM5 CH1 on PA0 pin
using TIM5_CH1_PA0 = AnyAltOut<Port::PA, 0, AfTIM5_CH1_PA0>;
/// A default configuration to map TIM5 CH1 on PB2 pin
using TIM5_CH1_PB2 = AnyAltOut<Port::PB, 2, AfTIM5_CH1_PB2>;
/// A default configuration to map TIM5 CH2 on PA1 pin
using TIM5_CH2_PA1 = AnyAltOut<Port::PA, 1, AfTIM5_CH2_PA1>;
/// A default configuration to map TIM5 CH2 on PC12 pin
using TIM5_CH2_PC12 = AnyAltOut<Port::PC, 12, AfTIM5_CH2_PC12>;
/// A default configuration to map TIM5 CH3 on PA2 pin
using TIM5_CH3_PA2 = AnyAltOut<Port::PA, 2, AfTIM5_CH3_PA2>;
/// A default configuration to map TIM5 CH4 on PA3 pin
using TIM5_CH4_PA3 = AnyAltOut<Port::PA, 3, AfTIM5_CH4_PA3>;
/// A default configuration to map TIM5 ETR on PB12 pin
using TIM5_ETR_PB12 = AnyAltOut<Port::PB, 12, AfTIM5_ETR_PB12>;
#if defined(GPIOD_BASE)
/// A default configuration to map TIM5 ETR on PD11 pin
using TIM5_ETR_PD11 = AnyAltOut<Port::PD, 11, AfTIM5_ETR_PD11>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map TIM5 CH3 on PE8 pin
using TIM5_CH3_PE8 = AnyAltOut<Port::PE, 8, AfTIM5_CH3_PE8>;
/// A default configuration to map TIM5 CH4 on PE9 pin
using TIM5_CH4_PE9 = AnyAltOut<Port::PE, 9, AfTIM5_CH4_PE9>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map TIM5 CH1 on PF6 pin
using TIM5_CH1_PF6 = AnyAltOut<Port::PF, 6, AfTIM5_CH1_PF6>;
/// A default configuration to map TIM5 CH2 on PF7 pin
using TIM5_CH2_PF7 = AnyAltOut<Port::PF, 7, AfTIM5_CH2_PF7>;
/// A default configuration to map TIM5 CH3 on PF8 pin
using TIM5_CH3_PF8 = AnyAltOut<Port::PF, 8, AfTIM5_CH3_PF8>;
/// A default configuration to map TIM5 CH4 on PF9 pin
using TIM5_CH4_PF9 = AnyAltOut<Port::PF, 9, AfTIM5_CH4_PF9>;
/// A default configuration to map TIM5 ETR on PF6 pin
using TIM5_ETR_PF6 = AnyAltOut<Port::PF, 6, AfTIM5_ETR_PF6>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(TIM5_BASE)

//////////////////////////////////////////////////////////////////////
// TIM8
//////////////////////////////////////////////////////////////////////
#if defined(TIM8_BASE)
/// A default configuration to map TIM8 BKIN on PA0 pin
using TIM8_BKIN_PA0 = AnyAltOut<Port::PA, 0, AfTIM8_BKIN_PA0>;
/// A default configuration to map TIM8 BKIN on PA6 pin
using TIM8_BKIN_PA6 = AnyAltOut<Port::PA, 6, AfTIM8_BKIN_PA6>;
/// A default configuration to map TIM8 BKIN on PA10 pin
using TIM8_BKIN_PA10 = AnyAltOut<Port::PA, 10, AfTIM8_BKIN_PA10>;
/// A default configuration to map TIM8 BKIN on PB7 pin
using TIM8_BKIN_PB7 = AnyAltOut<Port::PB, 7, AfTIM8_BKIN_PB7>;
/// A default configuration to map TIM8 BKIN2 on PB6 pin
using TIM8_BKIN2_PB6 = AnyAltOut<Port::PB, 6, AfTIM8_BKIN2_PB6>;
/// A default configuration to map TIM8 BKIN2 on PC9 pin
using TIM8_BKIN2_PC9 = AnyAltOut<Port::PC, 9, AfTIM8_BKIN2_PC9>;
/// A default configuration to map TIM8 CH1 on PA15 pin
using TIM8_CH1_PA15 = AnyAltOut<Port::PA, 15, AfTIM8_CH1_PA15>;
/// A default configuration to map TIM8 CH1 on PB6 pin
using TIM8_CH1_PB6 = AnyAltOut<Port::PB, 6, AfTIM8_CH1_PB6>;
/// A default configuration to map TIM8 CH1 on PC6 pin
using TIM8_CH1_PC6 = AnyAltOut<Port::PC, 6, AfTIM8_CH1_PC6>;
/// A default configuration to map TIM8 CH1N on PA7 pin
using TIM8_CH1N_PA7 = AnyAltOut<Port::PA, 7, AfTIM8_CH1N_PA7>;
/// A default configuration to map TIM8 CH1N on PB3 pin
using TIM8_CH1N_PB3 = AnyAltOut<Port::PB, 3, AfTIM8_CH1N_PB3>;
/// A default configuration to map TIM8 CH1N on PC10 pin
using TIM8_CH1N_PC10 = AnyAltOut<Port::PC, 10, AfTIM8_CH1N_PC10>;
/// A default configuration to map TIM8 CH2 on PA14 pin
using TIM8_CH2_PA14 = AnyAltOut<Port::PA, 14, AfTIM8_CH2_PA14>;
/// A default configuration to map TIM8 CH2 on PB8 pin
using TIM8_CH2_PB8 = AnyAltOut<Port::PB, 8, AfTIM8_CH2_PB8>;
/// A default configuration to map TIM8 CH2 on PC7 pin
using TIM8_CH2_PC7 = AnyAltOut<Port::PC, 7, AfTIM8_CH2_PC7>;
/// A default configuration to map TIM8 CH2N on PB0 pin
using TIM8_CH2N_PB0 = AnyAltOut<Port::PB, 0, AfTIM8_CH2N_PB0>;
/// A default configuration to map TIM8 CH2N on PB4 pin
using TIM8_CH2N_PB4 = AnyAltOut<Port::PB, 4, AfTIM8_CH2N_PB4>;
/// A default configuration to map TIM8 CH2N on PC11 pin
using TIM8_CH2N_PC11 = AnyAltOut<Port::PC, 11, AfTIM8_CH2N_PC11>;
/// A default configuration to map TIM8 CH3 on PB9 pin
using TIM8_CH3_PB9 = AnyAltOut<Port::PB, 9, AfTIM8_CH3_PB9>;
/// A default configuration to map TIM8 CH3 on PC8 pin
using TIM8_CH3_PC8 = AnyAltOut<Port::PC, 8, AfTIM8_CH3_PC8>;
/// A default configuration to map TIM8 CH3N on PB1 pin
using TIM8_CH3N_PB1 = AnyAltOut<Port::PB, 1, AfTIM8_CH3N_PB1>;
/// A default configuration to map TIM8 CH3N on PB5 pin
using TIM8_CH3N_PB5 = AnyAltOut<Port::PB, 5, AfTIM8_CH3N_PB5>;
/// A default configuration to map TIM8 CH3N on PC12 pin
using TIM8_CH3N_PC12 = AnyAltOut<Port::PC, 12, AfTIM8_CH3N_PC12>;
/// A default configuration to map TIM8 CH4 on PC9 pin
using TIM8_CH4_PC9 = AnyAltOut<Port::PC, 9, AfTIM8_CH4_PC9>;
/// A default configuration to map TIM8 CH4N on PC13 pin
using TIM8_CH4N_PC13 = AnyAltOut<Port::PC, 13, AfTIM8_CH4N_PC13>;
/// A default configuration to map TIM8 ETR on PA0 pin
using TIM8_ETR_PA0 = AnyAltOut<Port::PA, 0, AfTIM8_ETR_PA0>;
/// A default configuration to map TIM8 ETR on PB6 pin
using TIM8_ETR_PB6 = AnyAltOut<Port::PB, 6, AfTIM8_ETR_PB6>;
#if defined(GPIOD_BASE)
/// A default configuration to map TIM8 BKIN on PD2 pin
using TIM8_BKIN_PD2 = AnyAltOut<Port::PD, 2, AfTIM8_BKIN_PD2>;
/// A default configuration to map TIM8 BKIN2 on PD1 pin
using TIM8_BKIN2_PD1 = AnyAltOut<Port::PD, 1, AfTIM8_BKIN2_PD1>;
/// A default configuration to map TIM8 CH4 on PD1 pin
using TIM8_CH4_PD1 = AnyAltOut<Port::PD, 1, AfTIM8_CH4_PD1>;
/// A default configuration to map TIM8 CH4N on PD0 pin
using TIM8_CH4N_PD0 = AnyAltOut<Port::PD, 0, AfTIM8_CH4N_PD0>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(TIM8_BASE)

//////////////////////////////////////////////////////////////////////
// TIM15
//////////////////////////////////////////////////////////////////////
#if defined(TIM15_BASE)
/// A default configuration to map TIM15 BKIN on PA9 pin
using TIM15_BKIN_PA9 = AnyAltOut<Port::PA, 9, AfTIM15_BKIN_PA9>;
/// A default configuration to map TIM15 BKIN on PC5 pin
using TIM15_BKIN_PC5 = AnyAltOut<Port::PC, 5, AfTIM15_BKIN_PC5>;
/// A default configuration to map TIM15 CH1 on PA2 pin
using TIM15_CH1_PA2 = AnyAltOut<Port::PA, 2, AfTIM15_CH1_PA2>;
/// A default configuration to map TIM15 CH1 on PB14 pin
using TIM15_CH1_PB14 = AnyAltOut<Port::PB, 14, AfTIM15_CH1_PB14>;
/// A default configuration to map TIM15 CH1N on PA1 pin
using TIM15_CH1N_PA1 = AnyAltOut<Port::PA, 1, AfTIM15_CH1N_PA1>;
/// A default configuration to map TIM15 CH1N on PB15 pin
using TIM15_CH1N_PB15 = AnyAltOut<Port::PB, 15, AfTIM15_CH1N_PB15>;
/// A default configuration to map TIM15 CH2 on PA3 pin
using TIM15_CH2_PA3 = AnyAltOut<Port::PA, 3, AfTIM15_CH2_PA3>;
/// A default configuration to map TIM15 CH2 on PB15 pin
using TIM15_CH2_PB15 = AnyAltOut<Port::PB, 15, AfTIM15_CH2_PB15>;
#if defined(GPIOF_BASE)
/// A default configuration to map TIM15 CH1 on PF9 pin
using TIM15_CH1_PF9 = AnyAltOut<Port::PF, 9, AfTIM15_CH1_PF9>;
/// A default configuration to map TIM15 CH2 on PF10 pin
using TIM15_CH2_PF10 = AnyAltOut<Port::PF, 10, AfTIM15_CH2_PF10>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map TIM15 CH1N on PG9 pin
using TIM15_CH1N_PG9 = AnyAltOut<Port::PG, 9, AfTIM15_CH1N_PG9>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(TIM15_BASE)

//////////////////////////////////////////////////////////////////////
// TIM16
//////////////////////////////////////////////////////////////////////
#if defined(TIM16_BASE)
/// A default configuration to map TIM16 BKIN on PB5 pin
using TIM16_BKIN_PB5 = AnyAltOut<Port::PB, 5, AfTIM16_BKIN_PB5>;
/// A default configuration to map TIM16 CH1 on PA6 pin
using TIM16_CH1_PA6 = AnyAltOut<Port::PA, 6, AfTIM16_CH1_PA6>;
/// A default configuration to map TIM16 CH1 on PA12 pin
using TIM16_CH1_PA12 = AnyAltOut<Port::PA, 12, AfTIM16_CH1_PA12>;
/// A default configuration to map TIM16 CH1 on PB4 pin
using TIM16_CH1_PB4 = AnyAltOut<Port::PB, 4, AfTIM16_CH1_PB4>;
/// A default configuration to map TIM16 CH1 on PB8 pin
using TIM16_CH1_PB8 = AnyAltOut<Port::PB, 8, AfTIM16_CH1_PB8>;
/// A default configuration to map TIM16 CH1N on PA13 pin
using TIM16_CH1N_PA13 = AnyAltOut<Port::PA, 13, AfTIM16_CH1N_PA13>;
/// A default configuration to map TIM16 CH1N on PB6 pin
using TIM16_CH1N_PB6 = AnyAltOut<Port::PB, 6, AfTIM16_CH1N_PB6>;
#if defined(GPIOE_BASE)
/// A default configuration to map TIM16 CH1 on PE0 pin
using TIM16_CH1_PE0 = AnyAltOut<Port::PE, 0, AfTIM16_CH1_PE0>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM16_BASE)

//////////////////////////////////////////////////////////////////////
// TIM17
//////////////////////////////////////////////////////////////////////
#if defined(TIM17_BASE)
/// A default configuration to map TIM17 BKIN on PA10 pin
using TIM17_BKIN_PA10 = AnyAltOut<Port::PA, 10, AfTIM17_BKIN_PA10>;
/// A default configuration to map TIM17 BKIN on PB4 pin
using TIM17_BKIN_PB4 = AnyAltOut<Port::PB, 4, AfTIM17_BKIN_PB4>;
/// A default configuration to map TIM17 CH1 on PA7 pin
using TIM17_CH1_PA7 = AnyAltOut<Port::PA, 7, AfTIM17_CH1_PA7>;
/// A default configuration to map TIM17 CH1 on PB5 pin
using TIM17_CH1_PB5 = AnyAltOut<Port::PB, 5, AfTIM17_CH1_PB5>;
/// A default configuration to map TIM17 CH1 on PB9 pin
using TIM17_CH1_PB9 = AnyAltOut<Port::PB, 9, AfTIM17_CH1_PB9>;
/// A default configuration to map TIM17 CH1N on PB7 pin
using TIM17_CH1N_PB7 = AnyAltOut<Port::PB, 7, AfTIM17_CH1N_PB7>;
#if defined(GPIOE_BASE)
/// A default configuration to map TIM17 CH1 on PE1 pin
using TIM17_CH1_PE1 = AnyAltOut<Port::PE, 1, AfTIM17_CH1_PE1>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM17_BASE)

//////////////////////////////////////////////////////////////////////
// TIM20
//////////////////////////////////////////////////////////////////////
#if defined(TIM20_BASE)
/// A default configuration to map TIM20 CH1 on PB2 pin
using TIM20_CH1_PB2 = AnyAltOut<Port::PB, 2, AfTIM20_CH1_PB2>;
/// A default configuration to map TIM20 CH2 on PC2 pin
using TIM20_CH2_PC2 = AnyAltOut<Port::PC, 2, AfTIM20_CH2_PC2>;
/// A default configuration to map TIM20 CH3 on PC8 pin
using TIM20_CH3_PC8 = AnyAltOut<Port::PC, 8, AfTIM20_CH3_PC8>;
#if defined(GPIOE_BASE)
/// A default configuration to map TIM20 CH1 on PE2 pin
using TIM20_CH1_PE2 = AnyAltOut<Port::PE, 2, AfTIM20_CH1_PE2>;
/// A default configuration to map TIM20 CH1N on PE4 pin
using TIM20_CH1N_PE4 = AnyAltOut<Port::PE, 4, AfTIM20_CH1N_PE4>;
/// A default configuration to map TIM20 CH2 on PE3 pin
using TIM20_CH2_PE3 = AnyAltOut<Port::PE, 3, AfTIM20_CH2_PE3>;
/// A default configuration to map TIM20 CH2N on PE5 pin
using TIM20_CH2N_PE5 = AnyAltOut<Port::PE, 5, AfTIM20_CH2N_PE5>;
/// A default configuration to map TIM20 CH3N on PE6 pin
using TIM20_CH3N_PE6 = AnyAltOut<Port::PE, 6, AfTIM20_CH3N_PE6>;
/// A default configuration to map TIM20 CH4 on PE1 pin
using TIM20_CH4_PE1 = AnyAltOut<Port::PE, 1, AfTIM20_CH4_PE1>;
/// A default configuration to map TIM20 CH4N on PE0 pin
using TIM20_CH4N_PE0 = AnyAltOut<Port::PE, 0, AfTIM20_CH4N_PE0>;
/// A default configuration to map TIM20 ETR on PE0 pin
using TIM20_ETR_PE0 = AnyAltOut<Port::PE, 0, AfTIM20_ETR_PE0>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map TIM20 BKIN on PF7 pin
using TIM20_BKIN_PF7 = AnyAltOut<Port::PF, 7, AfTIM20_BKIN_PF7>;
/// A default configuration to map TIM20 BKIN on PF9 pin
using TIM20_BKIN_PF9 = AnyAltOut<Port::PF, 9, AfTIM20_BKIN_PF9>;
/// A default configuration to map TIM20 BKIN2 on PF8 pin
using TIM20_BKIN2_PF8 = AnyAltOut<Port::PF, 8, AfTIM20_BKIN2_PF8>;
/// A default configuration to map TIM20 BKIN2 on PF10 pin
using TIM20_BKIN2_PF10 = AnyAltOut<Port::PF, 10, AfTIM20_BKIN2_PF10>;
/// A default configuration to map TIM20 CH1 on PF12 pin
using TIM20_CH1_PF12 = AnyAltOut<Port::PF, 12, AfTIM20_CH1_PF12>;
/// A default configuration to map TIM20 CH1N on PF4 pin
using TIM20_CH1N_PF4 = AnyAltOut<Port::PF, 4, AfTIM20_CH1N_PF4>;
/// A default configuration to map TIM20 CH2 on PF13 pin
using TIM20_CH2_PF13 = AnyAltOut<Port::PF, 13, AfTIM20_CH2_PF13>;
/// A default configuration to map TIM20 CH2N on PF5 pin
using TIM20_CH2N_PF5 = AnyAltOut<Port::PF, 5, AfTIM20_CH2N_PF5>;
/// A default configuration to map TIM20 CH3 on PF2 pin
using TIM20_CH3_PF2 = AnyAltOut<Port::PF, 2, AfTIM20_CH3_PF2>;
/// A default configuration to map TIM20 CH3 on PF14 pin
using TIM20_CH3_PF14 = AnyAltOut<Port::PF, 14, AfTIM20_CH3_PF14>;
/// A default configuration to map TIM20 CH4 on PF3 pin
using TIM20_CH4_PF3 = AnyAltOut<Port::PF, 3, AfTIM20_CH4_PF3>;
/// A default configuration to map TIM20 CH4 on PF15 pin
using TIM20_CH4_PF15 = AnyAltOut<Port::PF, 15, AfTIM20_CH4_PF15>;
/// A default configuration to map TIM20 ETR on PF11 pin
using TIM20_ETR_PF11 = AnyAltOut<Port::PF, 11, AfTIM20_ETR_PF11>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map TIM20 BKIN on PG3 pin
using TIM20_BKIN_PG3 = AnyAltOut<Port::PG, 3, AfTIM20_BKIN_PG3>;
/// A default configuration to map TIM20 BKIN on PG6 pin
using TIM20_BKIN_PG6 = AnyAltOut<Port::PG, 6, AfTIM20_BKIN_PG6>;
/// A default configuration to map TIM20 BKIN2 on PG4 pin
using TIM20_BKIN2_PG4 = AnyAltOut<Port::PG, 4, AfTIM20_BKIN2_PG4>;
/// A default configuration to map TIM20 CH1N on PG0 pin
using TIM20_CH1N_PG0 = AnyAltOut<Port::PG, 0, AfTIM20_CH1N_PG0>;
/// A default configuration to map TIM20 CH2N on PG1 pin
using TIM20_CH2N_PG1 = AnyAltOut<Port::PG, 1, AfTIM20_CH2N_PG1>;
/// A default configuration to map TIM20 CH3N on PG2 pin
using TIM20_CH3N_PG2 = AnyAltOut<Port::PG, 2, AfTIM20_CH3N_PG2>;
/// A default configuration to map TIM20 CH4N on PG3 pin
using TIM20_CH4N_PG3 = AnyAltOut<Port::PG, 3, AfTIM20_CH4N_PG3>;
/// A default configuration to map TIM20 ETR on PG5 pin
using TIM20_ETR_PG5 = AnyAltOut<Port::PG, 5, AfTIM20_ETR_PG5>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(TIM20_BASE)

//////////////////////////////////////////////////////////////////////
// USART1
//////////////////////////////////////////////////////////////////////
#if defined(USART1_BASE)
/// A default configuration to map USART1 CK on PA8 pin
using USART1_CK_PA8 = AnyAltOut<Port::PA, 8, AfUSART1_CK_PA8>;
/// A default configuration to map USART1 CTS on PA11 pin
using USART1_CTS_PA11 = AnyAltOutOD<Port::PA, 11, AfUSART1_CTS_PA11>;
/// A default configuration to map USART1 RTS_DE on PA12 pin
using USART1_RTS_DE_PA12 = AnyAltOut<Port::PA, 12, AfUSART1_RTS_DE_PA12>;
/// A default configuration to map USART1 RX on PA10 pin
using USART1_RX_PA10 = AnyAltOutOD<Port::PA, 10, AfUSART1_RX_PA10>;
/// A default configuration to map USART1 RX on PB7 pin
using USART1_RX_PB7 = AnyAltOutOD<Port::PB, 7, AfUSART1_RX_PB7>;
/// A default configuration to map USART1 RX on PC5 pin
using USART1_RX_PC5 = AnyAltOutOD<Port::PC, 5, AfUSART1_RX_PC5>;
/// A default configuration to map USART1 TX on PA9 pin
using USART1_TX_PA9 = AnyAltOut<Port::PA, 9, AfUSART1_TX_PA9>;
/// A default configuration to map USART1 TX on PB6 pin
using USART1_TX_PB6 = AnyAltOut<Port::PB, 6, AfUSART1_TX_PB6>;
/// A default configuration to map USART1 TX on PC4 pin
using USART1_TX_PC4 = AnyAltOut<Port::PC, 4, AfUSART1_TX_PC4>;
#if defined(GPIOE_BASE)
/// A default configuration to map USART1 RX on PE1 pin
using USART1_RX_PE1 = AnyAltOutOD<Port::PE, 1, AfUSART1_RX_PE1>;
/// A default configuration to map USART1 TX on PE0 pin
using USART1_TX_PE0 = AnyAltOut<Port::PE, 0, AfUSART1_TX_PE0>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map USART1 TX on PG9 pin
using USART1_TX_PG9 = AnyAltOut<Port::PG, 9, AfUSART1_TX_PG9>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(USART1_BASE)

//////////////////////////////////////////////////////////////////////
// USART2
//////////////////////////////////////////////////////////////////////
#if defined(USART2_BASE)
/// A default configuration to map USART2 CK on PA4 pin
using USART2_CK_PA4 = AnyAltOut<Port::PA, 4, AfUSART2_CK_PA4>;
/// A default configuration to map USART2 CK on PB5 pin
using USART2_CK_PB5 = AnyAltOut<Port::PB, 5, AfUSART2_CK_PB5>;
/// A default configuration to map USART2 CTS on PA0 pin
using USART2_CTS_PA0 = AnyAltOutOD<Port::PA, 0, AfUSART2_CTS_PA0>;
/// A default configuration to map USART2 RTS_DE on PA1 pin
using USART2_RTS_DE_PA1 = AnyAltOut<Port::PA, 1, AfUSART2_RTS_DE_PA1>;
/// A default configuration to map USART2 RX on PA3 pin
using USART2_RX_PA3 = AnyAltOutOD<Port::PA, 3, AfUSART2_RX_PA3>;
/// A default configuration to map USART2 RX on PA15 pin
using USART2_RX_PA15 = AnyAltOutOD<Port::PA, 15, AfUSART2_RX_PA15>;
/// A default configuration to map USART2 RX on PB4 pin
using USART2_RX_PB4 = AnyAltOutOD<Port::PB, 4, AfUSART2_RX_PB4>;
/// A default configuration to map USART2 TX on PA2 pin
using USART2_TX_PA2 = AnyAltOut<Port::PA, 2, AfUSART2_TX_PA2>;
/// A default configuration to map USART2 TX on PA14 pin
using USART2_TX_PA14 = AnyAltOut<Port::PA, 14, AfUSART2_TX_PA14>;
/// A default configuration to map USART2 TX on PB3 pin
using USART2_TX_PB3 = AnyAltOut<Port::PB, 3, AfUSART2_TX_PB3>;
#if defined(GPIOD_BASE)
/// A default configuration to map USART2 CK on PD7 pin
using USART2_CK_PD7 = AnyAltOut<Port::PD, 7, AfUSART2_CK_PD7>;
/// A default configuration to map USART2 CTS on PD3 pin
using USART2_CTS_PD3 = AnyAltOutOD<Port::PD, 3, AfUSART2_CTS_PD3>;
/// A default configuration to map USART2 RTS_DE on PD4 pin
using USART2_RTS_DE_PD4 = AnyAltOut<Port::PD, 4, AfUSART2_RTS_DE_PD4>;
/// A default configuration to map USART2 RX on PD6 pin
using USART2_RX_PD6 = AnyAltOutOD<Port::PD, 6, AfUSART2_RX_PD6>;
/// A default configuration to map USART2 TX on PD5 pin
using USART2_TX_PD5 = AnyAltOut<Port::PD, 5, AfUSART2_TX_PD5>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(USART2_BASE)

//////////////////////////////////////////////////////////////////////
// USART3
//////////////////////////////////////////////////////////////////////
#if defined(USART3_BASE)
/// A default configuration to map USART3 CK on PB12 pin
using USART3_CK_PB12 = AnyAltOut<Port::PB, 12, AfUSART3_CK_PB12>;
/// A default configuration to map USART3 CK on PC12 pin
using USART3_CK_PC12 = AnyAltOut<Port::PC, 12, AfUSART3_CK_PC12>;
/// A default configuration to map USART3 CTS on PA13 pin
using USART3_CTS_PA13 = AnyAltOutOD<Port::PA, 13, AfUSART3_CTS_PA13>;
/// A default configuration to map USART3 CTS on PB13 pin
using USART3_CTS_PB13 = AnyAltOutOD<Port::PB, 13, AfUSART3_CTS_PB13>;
/// A default configuration to map USART3 RTS_DE on PB14 pin
using USART3_RTS_DE_PB14 = AnyAltOut<Port::PB, 14, AfUSART3_RTS_DE_PB14>;
/// A default configuration to map USART3 RX on PB8 pin
using USART3_RX_PB8 = AnyAltOutOD<Port::PB, 8, AfUSART3_RX_PB8>;
/// A default configuration to map USART3 RX on PB11 pin
using USART3_RX_PB11 = AnyAltOutOD<Port::PB, 11, AfUSART3_RX_PB11>;
/// A default configuration to map USART3 RX on PC11 pin
using USART3_RX_PC11 = AnyAltOutOD<Port::PC, 11, AfUSART3_RX_PC11>;
/// A default configuration to map USART3 TX on PB9 pin
using USART3_TX_PB9 = AnyAltOut<Port::PB, 9, AfUSART3_TX_PB9>;
/// A default configuration to map USART3 TX on PB10 pin
using USART3_TX_PB10 = AnyAltOut<Port::PB, 10, AfUSART3_TX_PB10>;
/// A default configuration to map USART3 TX on PC10 pin
using USART3_TX_PC10 = AnyAltOut<Port::PC, 10, AfUSART3_TX_PC10>;
#if defined(GPIOD_BASE)
/// A default configuration to map USART3 CK on PD10 pin
using USART3_CK_PD10 = AnyAltOut<Port::PD, 10, AfUSART3_CK_PD10>;
/// A default configuration to map USART3 CTS on PD11 pin
using USART3_CTS_PD11 = AnyAltOutOD<Port::PD, 11, AfUSART3_CTS_PD11>;
/// A default configuration to map USART3 RTS_DE on PD12 pin
using USART3_RTS_DE_PD12 = AnyAltOut<Port::PD, 12, AfUSART3_RTS_DE_PD12>;
/// A default configuration to map USART3 RX on PD9 pin
using USART3_RX_PD9 = AnyAltOutOD<Port::PD, 9, AfUSART3_RX_PD9>;
/// A default configuration to map USART3 TX on PD8 pin
using USART3_TX_PD8 = AnyAltOut<Port::PD, 8, AfUSART3_TX_PD8>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map USART3 RX on PE15 pin
using USART3_RX_PE15 = AnyAltOutOD<Port::PE, 15, AfUSART3_RX_PE15>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map USART3 RTS on PF6 pin
using USART3_RTS_PF6 = AnyAltOut<Port::PF, 6, AfUSART3_RTS_PF6>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(USART3_BASE)

//////////////////////////////////////////////////////////////////////
// UART4
//////////////////////////////////////////////////////////////////////
#if defined(UART4_BASE)
/// A default configuration to map UART4 CTS on PB7 pin
using UART4_CTS_PB7 = AnyAltOutOD<Port::PB, 7, AfUART4_CTS_PB7>;
/// A default configuration to map UART4 RTS_DE on PA15 pin
using UART4_RTS_DE_PA15 = AnyAltOut<Port::PA, 15, AfUART4_RTS_DE_PA15>;
/// A default configuration to map UART4 RX on PC11 pin
using UART4_RX_PC11 = AnyAltOutOD<Port::PC, 11, AfUART4_RX_PC11>;
/// A default configuration to map UART4 TX on PC10 pin
using UART4_TX_PC10 = AnyAltOut<Port::PC, 10, AfUART4_TX_PC10>;
#endif	// defined(UART4_BASE)

//////////////////////////////////////////////////////////////////////
// UART5
//////////////////////////////////////////////////////////////////////
#if defined(UART5_BASE)
/// A default configuration to map UART5 CTS on PB5 pin
using UART5_CTS_PB5 = AnyAltOutOD<Port::PB, 5, AfUART5_CTS_PB5>;
/// A default configuration to map UART5 RTS_DE on PB4 pin
using UART5_RTS_DE_PB4 = AnyAltOut<Port::PB, 4, AfUART5_RTS_DE_PB4>;
/// A default configuration to map UART5 TX on PC12 pin
using UART5_TX_PC12 = AnyAltOut<Port::PC, 12, AfUART5_TX_PC12>;
#if defined(GPIOD_BASE)
/// A default configuration to map UART5 RX on PD2 pin
using UART5_RX_PD2 = AnyAltOutOD<Port::PD, 2, AfUART5_RX_PD2>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(UART5_BASE)

//////////////////////////////////////////////////////////////////////
// USB
//////////////////////////////////////////////////////////////////////
#if defined(USB_BASE)
/// A default configuration to map USB CRS_SYNC on PA10 pin
using USB_CRS_SYNC_PA10 = AnyAltOut<Port::PA, 10, AfUSB_CRS_SYNC_PA10>;
/// A default configuration to map USB CRS_SYNC on PB3 pin
using USB_CRS_SYNC_PB3 = AnyAltOut<Port::PB, 3, AfUSB_CRS_SYNC_PB3>;
#endif	// defined(USB_BASE)

//////////////////////////////////////////////////////////////////////
// UCPD1
//////////////////////////////////////////////////////////////////////
#if defined(UCPD1_BASE)
/// A default configuration to map UCPD1 FRSTX on PA2 pin
using UCPD1_FRSTX_PA2 = AnyAltOut<Port::PA, 2, AfUCPD1_FRSTX_PA2>;
/// A default configuration to map UCPD1 FRSTX on PA5 pin
using UCPD1_FRSTX_PA5 = AnyAltOut<Port::PA, 5, AfUCPD1_FRSTX_PA5>;
/// A default configuration to map UCPD1 FRSTX on PA7 pin
using UCPD1_FRSTX_PA7 = AnyAltOut<Port::PA, 7, AfUCPD1_FRSTX_PA7>;
/// A default configuration to map UCPD1 FRSTX on PB0 pin
using UCPD1_FRSTX_PB0 = AnyAltOut<Port::PB, 0, AfUCPD1_FRSTX_PB0>;
/// A default configuration to map UCPD1 FRSTX on PC12 pin
using UCPD1_FRSTX_PC12 = AnyAltOut<Port::PC, 12, AfUCPD1_FRSTX_PC12>;
#endif	// defined(UCPD1_BASE)

//////////////////////////////////////////////////////////////////////
// EVENTOUT
//////////////////////////////////////////////////////////////////////
/// A default configuration to map EVENTOUT on PA0 pin
using EVENTOUT_PA0 = AnyAltOut<Port::PA, 0, AfEVENTOUT_PA0>;
/// A default configuration to map EVENTOUT on PA1 pin
using EVENTOUT_PA1 = AnyAltOut<Port::PA, 1, AfEVENTOUT_PA1>;
/// A default configuration to map EVENTOUT on PA2 pin
using EVENTOUT_PA2 = AnyAltOut<Port::PA, 2, AfEVENTOUT_PA2>;
/// A default configuration to map EVENTOUT on PA3 pin
using EVENTOUT_PA3 = AnyAltOut<Port::PA, 3, AfEVENTOUT_PA3>;
/// A default configuration to map EVENTOUT on PA4 pin
using EVENTOUT_PA4 = AnyAltOut<Port::PA, 4, AfEVENTOUT_PA4>;
/// A default configuration to map EVENTOUT on PA5 pin
using EVENTOUT_PA5 = AnyAltOut<Port::PA, 5, AfEVENTOUT_PA5>;
/// A default configuration to map EVENTOUT on PA6 pin
using EVENTOUT_PA6 = AnyAltOut<Port::PA, 6, AfEVENTOUT_PA6>;
/// A default configuration to map EVENTOUT on PA7 pin
using EVENTOUT_PA7 = AnyAltOut<Port::PA, 7, AfEVENTOUT_PA7>;
/// A default configuration to map EVENTOUT on PA8 pin
using EVENTOUT_PA8 = AnyAltOut<Port::PA, 8, AfEVENTOUT_PA8>;
/// A default configuration to map EVENTOUT on PA9 pin
using EVENTOUT_PA9 = AnyAltOut<Port::PA, 9, AfEVENTOUT_PA9>;
/// A default configuration to map EVENTOUT on PA10 pin
using EVENTOUT_PA10 = AnyAltOut<Port::PA, 10, AfEVENTOUT_PA10>;
/// A default configuration to map EVENTOUT on PA11 pin
using EVENTOUT_PA11 = AnyAltOut<Port::PA, 11, AfEVENTOUT_PA11>;
/// A default configuration to map EVENTOUT on PA12 pin
using EVENTOUT_PA12 = AnyAltOut<Port::PA, 12, AfEVENTOUT_PA12>;
/// A default configuration to map EVENTOUT on PA13 pin
using EVENTOUT_PA13 = AnyAltOut<Port::PA, 13, AfEVENTOUT_PA13>;
/// A default configuration to map EVENTOUT on PA14 pin
using EVENTOUT_PA14 = AnyAltOut<Port::PA, 14, AfEVENTOUT_PA14>;
/// A default configuration to map EVENTOUT on PA15 pin
using EVENTOUT_PA15 = AnyAltOut<Port::PA, 15, AfEVENTOUT_PA15>;
/// A default configuration to map EVENTOUT on PB0 pin
using EVENTOUT_PB0 = AnyAltOut<Port::PB, 0, AfEVENTOUT_PB0>;
/// A default configuration to map EVENTOUT on PB1 pin
using EVENTOUT_PB1 = AnyAltOut<Port::PB, 1, AfEVENTOUT_PB1>;
/// A default configuration to map EVENTOUT on PB2 pin
using EVENTOUT_PB2 = AnyAltOut<Port::PB, 2, AfEVENTOUT_PB2>;
/// A default configuration to map EVENTOUT on PB3 pin
using EVENTOUT_PB3 = AnyAltOut<Port::PB, 3, AfEVENTOUT_PB3>;
/// A default configuration to map EVENTOUT on PB4 pin
using EVENTOUT_PB4 = AnyAltOut<Port::PB, 4, AfEVENTOUT_PB4>;
/// A default configuration to map EVENTOUT on PB5 pin
using EVENTOUT_PB5 = AnyAltOut<Port::PB, 5, AfEVENTOUT_PB5>;
/// A default configuration to map EVENTOUT on PB6 pin
using EVENTOUT_PB6 = AnyAltOut<Port::PB, 6, AfEVENTOUT_PB6>;
/// A default configuration to map EVENTOUT on PB7 pin
using EVENTOUT_PB7 = AnyAltOut<Port::PB, 7, AfEVENTOUT_PB7>;
/// A default configuration to map EVENTOUT on PB8 pin
using EVENTOUT_PB8 = AnyAltOut<Port::PB, 8, AfEVENTOUT_PB8>;
/// A default configuration to map EVENTOUT on PB9 pin
using EVENTOUT_PB9 = AnyAltOut<Port::PB, 9, AfEVENTOUT_PB9>;
/// A default configuration to map EVENTOUT on PB10 pin
using EVENTOUT_PB10 = AnyAltOut<Port::PB, 10, AfEVENTOUT_PB10>;
/// A default configuration to map EVENTOUT on PB11 pin
using EVENTOUT_PB11 = AnyAltOut<Port::PB, 11, AfEVENTOUT_PB11>;
/// A default configuration to map EVENTOUT on PB12 pin
using EVENTOUT_PB12 = AnyAltOut<Port::PB, 12, AfEVENTOUT_PB12>;
/// A default configuration to map EVENTOUT on PB13 pin
using EVENTOUT_PB13 = AnyAltOut<Port::PB, 13, AfEVENTOUT_PB13>;
/// A default configuration to map EVENTOUT on PB14 pin
using EVENTOUT_PB14 = AnyAltOut<Port::PB, 14, AfEVENTOUT_PB14>;
/// A default configuration to map EVENTOUT on PB15 pin
using EVENTOUT_PB15 = AnyAltOut<Port::PB, 15, AfEVENTOUT_PB15>;
/// A default configuration to map EVENTOUT on PC0 pin
using EVENTOUT_PC0 = AnyAltOut<Port::PC, 0, AfEVENTOUT_PC0>;
/// A default configuration to map EVENTOUT on PC1 pin
using EVENTOUT_PC1 = AnyAltOut<Port::PC, 1, AfEVENTOUT_PC1>;
/// A default configuration to map EVENTOUT on PC2 pin
using EVENTOUT_PC2 = AnyAltOut<Port::PC, 2, AfEVENTOUT_PC2>;
/// A default configuration to map EVENTOUT on PC3 pin
using EVENTOUT_PC3 = AnyAltOut<Port::PC, 3, AfEVENTOUT_PC3>;
/// A default configuration to map EVENTOUT on PC4 pin
using EVENTOUT_PC4 = AnyAltOut<Port::PC, 4, AfEVENTOUT_PC4>;
/// A default configuration to map EVENTOUT on PC5 pin
using EVENTOUT_PC5 = AnyAltOut<Port::PC, 5, AfEVENTOUT_PC5>;
/// A default configuration to map EVENTOUT on PC6 pin
using EVENTOUT_PC6 = AnyAltOut<Port::PC, 6, AfEVENTOUT_PC6>;
/// A default configuration to map EVENTOUT on PC7 pin
using EVENTOUT_PC7 = AnyAltOut<Port::PC, 7, AfEVENTOUT_PC7>;
/// A default configuration to map EVENTOUT on PC8 pin
using EVENTOUT_PC8 = AnyAltOut<Port::PC, 8, AfEVENTOUT_PC8>;
/// A default configuration to map EVENTOUT on PC9 pin
using EVENTOUT_PC9 = AnyAltOut<Port::PC, 9, AfEVENTOUT_PC9>;
/// A default configuration to map EVENTOUT on PC10 pin
using EVENTOUT_PC10 = AnyAltOut<Port::PC, 10, AfEVENTOUT_PC10>;
/// A default configuration to map EVENTOUT on PC11 pin
using EVENTOUT_PC11 = AnyAltOut<Port::PC, 11, AfEVENTOUT_PC11>;
/// A default configuration to map EVENTOUT on PC12 pin
using EVENTOUT_PC12 = AnyAltOut<Port::PC, 12, AfEVENTOUT_PC12>;
/// A default configuration to map EVENTOUT on PC13 pin
using EVENTOUT_PC13 = AnyAltOut<Port::PC, 13, AfEVENTOUT_PC13>;
/// A default configuration to map EVENTOUT on PC14 pin
using EVENTOUT_PC14 = AnyAltOut<Port::PC, 14, AfEVENTOUT_PC14>;
/// A default configuration to map EVENTOUT on PC15 pin
using EVENTOUT_PC15 = AnyAltOut<Port::PC, 15, AfEVENTOUT_PC15>;
#if defined(GPIOD_BASE)
/// A default configuration to map EVENTOUT on PD0 pin
using EVENTOUT_PD0 = AnyAltOut<Port::PD, 0, AfEVENTOUT_PD0>;
/// A default configuration to map EVENTOUT on PD1 pin
using EVENTOUT_PD1 = AnyAltOut<Port::PD, 1, AfEVENTOUT_PD1>;
/// A default configuration to map EVENTOUT on PD2 pin
using EVENTOUT_PD2 = AnyAltOut<Port::PD, 2, AfEVENTOUT_PD2>;
/// A default configuration to map EVENTOUT on PD3 pin
using EVENTOUT_PD3 = AnyAltOut<Port::PD, 3, AfEVENTOUT_PD3>;
/// A default configuration to map EVENTOUT on PD4 pin
using EVENTOUT_PD4 = AnyAltOut<Port::PD, 4, AfEVENTOUT_PD4>;
/// A default configuration to map EVENTOUT on PD5 pin
using EVENTOUT_PD5 = AnyAltOut<Port::PD, 5, AfEVENTOUT_PD5>;
/// A default configuration to map EVENTOUT on PD6 pin
using EVENTOUT_PD6 = AnyAltOut<Port::PD, 6, AfEVENTOUT_PD6>;
/// A default configuration to map EVENTOUT on PD7 pin
using EVENTOUT_PD7 = AnyAltOut<Port::PD, 7, AfEVENTOUT_PD7>;
/// A default configuration to map EVENTOUT on PD8 pin
using EVENTOUT_PD8 = AnyAltOut<Port::PD, 8, AfEVENTOUT_PD8>;
/// A default configuration to map EVENTOUT on PD9 pin
using EVENTOUT_PD9 = AnyAltOut<Port::PD, 9, AfEVENTOUT_PD9>;
/// A default configuration to map EVENTOUT on PD10 pin
using EVENTOUT_PD10 = AnyAltOut<Port::PD, 10, AfEVENTOUT_PD10>;
/// A default configuration to map EVENTOUT on PD11 pin
using EVENTOUT_PD11 = AnyAltOut<Port::PD, 11, AfEVENTOUT_PD11>;
/// A default configuration to map EVENTOUT on PD12 pin
using EVENTOUT_PD12 = AnyAltOut<Port::PD, 12, AfEVENTOUT_PD12>;
/// A default configuration to map EVENTOUT on PD13 pin
using EVENTOUT_PD13 = AnyAltOut<Port::PD, 13, AfEVENTOUT_PD13>;
/// A default configuration to map EVENTOUT on PD14 pin
using EVENTOUT_PD14 = AnyAltOut<Port::PD, 14, AfEVENTOUT_PD14>;
/// A default configuration to map EVENTOUT on PD15 pin
using EVENTOUT_PD15 = AnyAltOut<Port::PD, 15, AfEVENTOUT_PD15>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map EVENTOUT on PE0 pin
using EVENTOUT_PE0 = AnyAltOut<Port::PE, 0, AfEVENTOUT_PE0>;
/// A default configuration to map EVENTOUT on PE1 pin
using EVENTOUT_PE1 = AnyAltOut<Port::PE, 1, AfEVENTOUT_PE1>;
/// A default configuration to map EVENTOUT on PE2 pin
using EVENTOUT_PE2 = AnyAltOut<Port::PE, 2, AfEVENTOUT_PE2>;
/// A default configuration to map EVENTOUT on PE3 pin
using EVENTOUT_PE3 = AnyAltOut<Port::PE, 3, AfEVENTOUT_PE3>;
/// A default configuration to map EVENTOUT on PE4 pin
using EVENTOUT_PE4 = AnyAltOut<Port::PE, 4, AfEVENTOUT_PE4>;
/// A default configuration to map EVENTOUT on PE5 pin
using EVENTOUT_PE5 = AnyAltOut<Port::PE, 5, AfEVENTOUT_PE5>;
/// A default configuration to map EVENTOUT on PE6 pin
using EVENTOUT_PE6 = AnyAltOut<Port::PE, 6, AfEVENTOUT_PE6>;
/// A default configuration to map EVENTOUT on PE7 pin
using EVENTOUT_PE7 = AnyAltOut<Port::PE, 7, AfEVENTOUT_PE7>;
/// A default configuration to map EVENTOUT on PE8 pin
using EVENTOUT_PE8 = AnyAltOut<Port::PE, 8, AfEVENTOUT_PE8>;
/// A default configuration to map EVENTOUT on PE9 pin
using EVENTOUT_PE9 = AnyAltOut<Port::PE, 9, AfEVENTOUT_PE9>;
/// A default configuration to map EVENTOUT on PE10 pin
using EVENTOUT_PE10 = AnyAltOut<Port::PE, 10, AfEVENTOUT_PE10>;
/// A default configuration to map EVENTOUT on PE11 pin
using EVENTOUT_PE11 = AnyAltOut<Port::PE, 11, AfEVENTOUT_PE11>;
/// A default configuration to map EVENTOUT on PE12 pin
using EVENTOUT_PE12 = AnyAltOut<Port::PE, 12, AfEVENTOUT_PE12>;
/// A default configuration to map EVENTOUT on PE13 pin
using EVENTOUT_PE13 = AnyAltOut<Port::PE, 13, AfEVENTOUT_PE13>;
/// A default configuration to map EVENTOUT on PE14 pin
using EVENTOUT_PE14 = AnyAltOut<Port::PE, 14, AfEVENTOUT_PE14>;
/// A default configuration to map EVENTOUT on PE15 pin
using EVENTOUT_PE15 = AnyAltOut<Port::PE, 15, AfEVENTOUT_PE15>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map EVENTOUT on PF0 pin
using EVENTOUT_PF0 = AnyAltOut<Port::PF, 0, AfEVENTOUT_PF0>;
/// A default configuration to map EVENTOUT on PF1 pin
using EVENTOUT_PF1 = AnyAltOut<Port::PF, 1, AfEVENTOUT_PF1>;
/// A default configuration to map EVENTOUT on PF2 pin
using EVENTOUT_PF2 = AnyAltOut<Port::PF, 2, AfEVENTOUT_PF2>;
/// A default configuration to map EVENTOUT on PF3 pin
using EVENTOUT_PF3 = AnyAltOut<Port::PF, 3, AfEVENTOUT_PF3>;
/// A default configuration to map EVENTOUT on PF4 pin
using EVENTOUT_PF4 = AnyAltOut<Port::PF, 4, AfEVENTOUT_PF4>;
/// A default configuration to map EVENTOUT on PF5 pin
using EVENTOUT_PF5 = AnyAltOut<Port::PF, 5, AfEVENTOUT_PF5>;
/// A default configuration to map EVENTOUT on PF6 pin
using EVENTOUT_PF6 = AnyAltOut<Port::PF, 6, AfEVENTOUT_PF6>;
/// A default configuration to map EVENTOUT on PF7 pin
using EVENTOUT_PF7 = AnyAltOut<Port::PF, 7, AfEVENTOUT_PF7>;
/// A default configuration to map EVENTOUT on PF8 pin
using EVENTOUT_PF8 = AnyAltOut<Port::PF, 8, AfEVENTOUT_PF8>;
/// A default configuration to map EVENTOUT on PF9 pin
using EVENTOUT_PF9 = AnyAltOut<Port::PF, 9, AfEVENTOUT_PF9>;
/// A default configuration to map EVENTOUT on PF10 pin
using EVENTOUT_PF10 = AnyAltOut<Port::PF, 10, AfEVENTOUT_PF10>;
/// A default configuration to map EVENTOUT on PF11 pin
using EVENTOUT_PF11 = AnyAltOut<Port::PF, 11, AfEVENTOUT_PF11>;
/// A default configuration to map EVENTOUT on PF12 pin
using EVENTOUT_PF12 = AnyAltOut<Port::PF, 12, AfEVENTOUT_PF12>;
/// A default configuration to map EVENTOUT on PF13 pin
using EVENTOUT_PF13 = AnyAltOut<Port::PF, 13, AfEVENTOUT_PF13>;
/// A default configuration to map EVENTOUT on PF14 pin
using EVENTOUT_PF14 = AnyAltOut<Port::PF, 14, AfEVENTOUT_PF14>;
/// A default configuration to map EVENTOUT on PF15 pin
using EVENTOUT_PF15 = AnyAltOut<Port::PF, 15, AfEVENTOUT_PF15>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map EVENTOUT on PG0 pin
using EVENTOUT_PG0 = AnyAltOut<Port::PG, 0, AfEVENTOUT_PG0>;
/// A default configuration to map EVENTOUT on PG1 pin
using EVENTOUT_PG1 = AnyAltOut<Port::PG, 1, AfEVENTOUT_PG1>;
/// A default configuration to map EVENTOUT on PG2 pin
using EVENTOUT_PG2 = AnyAltOut<Port::PG, 2, AfEVENTOUT_PG2>;
/// A default configuration to map EVENTOUT on PG3 pin
using EVENTOUT_PG3 = AnyAltOut<Port::PG, 3, AfEVENTOUT_PG3>;
/// A default configuration to map EVENTOUT on PG4 pin
using EVENTOUT_PG4 = AnyAltOut<Port::PG, 4, AfEVENTOUT_PG4>;
/// A default configuration to map EVENTOUT on PG5 pin
using EVENTOUT_PG5 = AnyAltOut<Port::PG, 5, AfEVENTOUT_PG5>;
/// A default configuration to map EVENTOUT on PG6 pin
using EVENTOUT_PG6 = AnyAltOut<Port::PG, 6, AfEVENTOUT_PG6>;
/// A default configuration to map EVENTOUT on PG7 pin
using EVENTOUT_PG7 = AnyAltOut<Port::PG, 7, AfEVENTOUT_PG7>;
/// A default configuration to map EVENTOUT on PG8 pin
using EVENTOUT_PG8 = AnyAltOut<Port::PG, 8, AfEVENTOUT_PG8>;
/// A default configuration to map EVENTOUT on PG9 pin
using EVENTOUT_PG9 = AnyAltOut<Port::PG, 9, AfEVENTOUT_PG9>;
/// A default configuration to map EVENTOUT on PG10 pin
using EVENTOUT_PG10 = AnyAltOut<Port::PG, 10, AfEVENTOUT_PG10>;
#endif	// defined(GPIOG_BASE)


}	// namespace Gpio
}	// namespace Bmt

