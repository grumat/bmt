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
using MCO_PA8 = AnyAltOut<Port::PA, 8, AfMCO_PA8>;/// A default configuration to map JTCK on PA14 pin
using JTCK_PA14 = AnyAltOut<Port::PA, 14, AfJTCK_PA14, Speed::kFast, Level::kLow, PuPd::kPullDown>;/// A default configuration to map JTDI on PA15 pin
using JTDI_PA15 = AnyAltOut<Port::PA, 15, AfJTDI_PA15, Speed::kFast, Level::kLow, PuPd::kPullUp>;/// A default configuration to map JTDO on PB3 pin
using JTDO_PB3 = AnyAltOut<Port::PB, 3, AfJTDO_PB3, Speed::kFast>;/// A default configuration to map JTMS on PA13 pin
using JTMS_PA13 = AnyAltOut<Port::PA, 13, AfJTMS_PA13, Speed::kFastest, Level::kLow, PuPd::kPullUp>;/// A default configuration to map NJTRST on PB4 pin
using NJTRST_PB4 = AnyAltOut<Port::PB, 4, AfNJTRST_PB4, Speed::kSlow, Level::kLow, PuPd::kPullUp>;/// A default configuration to map TRACED0 on PC1 pin
using TRACED0_PC1 = AnyAltOut<Port::PC, 1, AfTRACED0_PC1, Speed::kFast>;/// A default configuration to map TRACED1 on PC10 pin
using TRACED1_PC10 = AnyAltOut<Port::PC, 10, AfTRACED1_PC10, Speed::kFast>;/// A default configuration to map TRACED3 on PC12 pin
using TRACED3_PC12 = AnyAltOut<Port::PC, 12, AfTRACED3_PC12, Speed::kFast>;/// A default configuration to map TRACESWO on PB3 pin
using TRACESWO_PB3 = AnyAltOut<Port::PB, 3, AfTRACESWO_PB3, Speed::kFast>;#if defined(GPIOD_BASE)
/// A default configuration to map TRACED2 on PD2 pin
using TRACED2_PD2 = AnyAltOut<Port::PD, 2, AfTRACED2_PD2, Speed::kFast>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map TRACECLK on PE2 pin
using TRACECLK_PE2 = AnyAltOut<Port::PE, 2, AfTRACECLK_PE2, Speed::kFast>;/// A default configuration to map TRACED0 on PE3 pin
using TRACED0_PE3 = AnyAltOut<Port::PE, 3, AfTRACED0_PE3, Speed::kFast>;/// A default configuration to map TRACED1 on PE4 pin
using TRACED1_PE4 = AnyAltOut<Port::PE, 4, AfTRACED1_PE4, Speed::kFast>;/// A default configuration to map TRACED2 on PE5 pin
using TRACED2_PE5 = AnyAltOut<Port::PE, 5, AfTRACED2_PE5, Speed::kFast>;/// A default configuration to map TRACED3 on PE6 pin
using TRACED3_PE6 = AnyAltOut<Port::PE, 6, AfTRACED3_PE6, Speed::kFast>;#endif	// defined(GPIOE_BASE)
/// A default configuration to map SWCLK on PA14 pin
using SWCLK_PA14 = AnyAltOut<Port::PA, 14, AfSWCLK_PA14, Speed::kFast, Level::kLow, PuPd::kPullDown>;/// A default configuration to map SWDIO on PA13 pin
using SWDIO_PA13 = AnyAltOut<Port::PA, 13, AfSWDIO_PA13, Speed::kFastest, Level::kLow, PuPd::kPullUp>;
//////////////////////////////////////////////////////////////////////
// ADC1
//////////////////////////////////////////////////////////////////////
#if defined(ADC1_BASE)
/// A default configuration to map ADC1 IN1 on PC0 pin
using ADC1_IN1_PC0 = AnyAnalog<Port::PC, 0>;/// A default configuration to map ADC1 IN10 on PA5 pin
using ADC1_IN10_PA5 = AnyAnalog<Port::PA, 5>;/// A default configuration to map ADC1 IN11 on PA6 pin
using ADC1_IN11_PA6 = AnyAnalog<Port::PA, 6>;/// A default configuration to map ADC1 IN12 on PA7 pin
using ADC1_IN12_PA7 = AnyAnalog<Port::PA, 7>;/// A default configuration to map ADC1 IN13 on PC4 pin
using ADC1_IN13_PC4 = AnyAnalog<Port::PC, 4>;/// A default configuration to map ADC1 IN14 on PC5 pin
using ADC1_IN14_PC5 = AnyAnalog<Port::PC, 5>;/// A default configuration to map ADC1 IN15 on PB0 pin
using ADC1_IN15_PB0 = AnyAnalog<Port::PB, 0>;/// A default configuration to map ADC1 IN16 on PB1 pin
using ADC1_IN16_PB1 = AnyAnalog<Port::PB, 1>;/// A default configuration to map ADC1 IN2 on PC1 pin
using ADC1_IN2_PC1 = AnyAnalog<Port::PC, 1>;/// A default configuration to map ADC1 IN3 on PC2 pin
using ADC1_IN3_PC2 = AnyAnalog<Port::PC, 2>;/// A default configuration to map ADC1 IN4 on PC3 pin
using ADC1_IN4_PC3 = AnyAnalog<Port::PC, 3>;/// A default configuration to map ADC1 IN5 on PA0 pin
using ADC1_IN5_PA0 = AnyAnalog<Port::PA, 0>;/// A default configuration to map ADC1 IN6 on PA1 pin
using ADC1_IN6_PA1 = AnyAnalog<Port::PA, 1>;/// A default configuration to map ADC1 IN7 on PA2 pin
using ADC1_IN7_PA2 = AnyAnalog<Port::PA, 2>;/// A default configuration to map ADC1 IN8 on PA3 pin
using ADC1_IN8_PA3 = AnyAnalog<Port::PA, 3>;/// A default configuration to map ADC1 IN9 on PA4 pin
using ADC1_IN9_PA4 = AnyAnalog<Port::PA, 4>;#endif	// defined(ADC1_BASE)

//////////////////////////////////////////////////////////////////////
// ADC2
//////////////////////////////////////////////////////////////////////
#if defined(ADC2_BASE)
/// A default configuration to map ADC2 IN1 on PC0 pin
using ADC2_IN1_PC0 = AnyAnalog<Port::PC, 0>;/// A default configuration to map ADC2 IN10 on PA5 pin
using ADC2_IN10_PA5 = AnyAnalog<Port::PA, 5>;/// A default configuration to map ADC2 IN11 on PA6 pin
using ADC2_IN11_PA6 = AnyAnalog<Port::PA, 6>;/// A default configuration to map ADC2 IN12 on PA7 pin
using ADC2_IN12_PA7 = AnyAnalog<Port::PA, 7>;/// A default configuration to map ADC2 IN13 on PC4 pin
using ADC2_IN13_PC4 = AnyAnalog<Port::PC, 4>;/// A default configuration to map ADC2 IN14 on PC5 pin
using ADC2_IN14_PC5 = AnyAnalog<Port::PC, 5>;/// A default configuration to map ADC2 IN15 on PB0 pin
using ADC2_IN15_PB0 = AnyAnalog<Port::PB, 0>;/// A default configuration to map ADC2 IN16 on PB1 pin
using ADC2_IN16_PB1 = AnyAnalog<Port::PB, 1>;/// A default configuration to map ADC2 IN2 on PC1 pin
using ADC2_IN2_PC1 = AnyAnalog<Port::PC, 1>;/// A default configuration to map ADC2 IN3 on PC2 pin
using ADC2_IN3_PC2 = AnyAnalog<Port::PC, 2>;/// A default configuration to map ADC2 IN4 on PC3 pin
using ADC2_IN4_PC3 = AnyAnalog<Port::PC, 3>;/// A default configuration to map ADC2 IN5 on PA0 pin
using ADC2_IN5_PA0 = AnyAnalog<Port::PA, 0>;/// A default configuration to map ADC2 IN6 on PA1 pin
using ADC2_IN6_PA1 = AnyAnalog<Port::PA, 1>;/// A default configuration to map ADC2 IN7 on PA2 pin
using ADC2_IN7_PA2 = AnyAnalog<Port::PA, 2>;/// A default configuration to map ADC2 IN8 on PA3 pin
using ADC2_IN8_PA3 = AnyAnalog<Port::PA, 3>;/// A default configuration to map ADC2 IN9 on PA4 pin
using ADC2_IN9_PA4 = AnyAnalog<Port::PA, 4>;#endif	// defined(ADC2_BASE)

//////////////////////////////////////////////////////////////////////
// ADC3
//////////////////////////////////////////////////////////////////////
#if defined(ADC3_BASE)
/// A default configuration to map ADC3 IN1 on PC0 pin
using ADC3_IN1_PC0 = AnyAnalog<Port::PC, 0>;/// A default configuration to map ADC3 IN2 on PC1 pin
using ADC3_IN2_PC1 = AnyAnalog<Port::PC, 1>;/// A default configuration to map ADC3 IN3 on PC2 pin
using ADC3_IN3_PC2 = AnyAnalog<Port::PC, 2>;/// A default configuration to map ADC3 IN4 on PC3 pin
using ADC3_IN4_PC3 = AnyAnalog<Port::PC, 3>;#if defined(GPIOF_BASE)
/// A default configuration to map ADC3 IN10 on PF7 pin
using ADC3_IN10_PF7 = AnyAnalog<Port::PF, 7>;/// A default configuration to map ADC3 IN11 on PF8 pin
using ADC3_IN11_PF8 = AnyAnalog<Port::PF, 8>;/// A default configuration to map ADC3 IN12 on PF9 pin
using ADC3_IN12_PF9 = AnyAnalog<Port::PF, 9>;/// A default configuration to map ADC3 IN13 on PF10 pin
using ADC3_IN13_PF10 = AnyAnalog<Port::PF, 10>;/// A default configuration to map ADC3 IN6 on PF3 pin
using ADC3_IN6_PF3 = AnyAnalog<Port::PF, 3>;/// A default configuration to map ADC3 IN7 on PF4 pin
using ADC3_IN7_PF4 = AnyAnalog<Port::PF, 4>;/// A default configuration to map ADC3 IN8 on PF5 pin
using ADC3_IN8_PF5 = AnyAnalog<Port::PF, 5>;/// A default configuration to map ADC3 IN9 on PF6 pin
using ADC3_IN9_PF6 = AnyAnalog<Port::PF, 6>;#endif	// defined(GPIOF_BASE)
#endif	// defined(ADC3_BASE)

//////////////////////////////////////////////////////////////////////
// CAN1
//////////////////////////////////////////////////////////////////////
#if defined(CAN1_BASE)
/// A default configuration to map CAN1 RX on PA11 pin
using CAN1_RX_PA11 = AnyAltOut<Port::PA, 11, AfCAN1_RX_PA11>;/// A default configuration to map CAN1 RX on PB8 pin
using CAN1_RX_PB8 = AnyAltOut<Port::PB, 8, AfCAN1_RX_PB8>;/// A default configuration to map CAN1 TX on PA12 pin
using CAN1_TX_PA12 = AnyAltOut<Port::PA, 12, AfCAN1_TX_PA12>;/// A default configuration to map CAN1 TX on PB9 pin
using CAN1_TX_PB9 = AnyAltOut<Port::PB, 9, AfCAN1_TX_PB9>;#if defined(GPIOD_BASE)
/// A default configuration to map CAN1 RX on PD0 pin
using CAN1_RX_PD0 = AnyAltOut<Port::PD, 0, AfCAN1_RX_PD0>;/// A default configuration to map CAN1 TX on PD1 pin
using CAN1_TX_PD1 = AnyAltOut<Port::PD, 1, AfCAN1_TX_PD1>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOH_BASE)
/// A default configuration to map CAN1 TX on PH13 pin
using CAN1_TX_PH13 = AnyAltOut<Port::PH, 13, AfCAN1_TX_PH13>;#endif	// defined(GPIOH_BASE)
#if defined(GPIOI_BASE)
/// A default configuration to map CAN1 RX on PI9 pin
using CAN1_RX_PI9 = AnyAltOut<Port::PI, 9, AfCAN1_RX_PI9>;#endif	// defined(GPIOI_BASE)
#endif	// defined(CAN1_BASE)

//////////////////////////////////////////////////////////////////////
// CAN2
//////////////////////////////////////////////////////////////////////
#if defined(CAN2_BASE)
/// A default configuration to map CAN2 RX on PB5 pin
using CAN2_RX_PB5 = AnyAltOut<Port::PB, 5, AfCAN2_RX_PB5>;/// A default configuration to map CAN2 RX on PB12 pin
using CAN2_RX_PB12 = AnyAltOut<Port::PB, 12, AfCAN2_RX_PB12>;/// A default configuration to map CAN2 TX on PB6 pin
using CAN2_TX_PB6 = AnyAltOut<Port::PB, 6, AfCAN2_TX_PB6>;/// A default configuration to map CAN2 TX on PB13 pin
using CAN2_TX_PB13 = AnyAltOut<Port::PB, 13, AfCAN2_TX_PB13>;#endif	// defined(CAN2_BASE)

//////////////////////////////////////////////////////////////////////
// COMP1
//////////////////////////////////////////////////////////////////////
#if defined(COMP1_BASE)
/// A default configuration to map COMP1 INM on PB1 pin
using COMP1_INM_PB1 = AnyAnalog<Port::PB, 1>;/// A default configuration to map COMP1 INM on PC4 pin
using COMP1_INM_PC4 = AnyAnalog<Port::PC, 4>;/// A default configuration to map COMP1 INP on PB2 pin
using COMP1_INP_PB2 = AnyAnalog<Port::PB, 2>;/// A default configuration to map COMP1 INP on PC5 pin
using COMP1_INP_PC5 = AnyAnalog<Port::PC, 5>;/// A default configuration to map COMP1 OUT on PB0 pin
using COMP1_OUT_PB0 = AnyAltOut<Port::PB, 0, AfCOMP1_OUT_PB0>;/// A default configuration to map COMP1 OUT on PB10 pin
using COMP1_OUT_PB10 = AnyAltOut<Port::PB, 10, AfCOMP1_OUT_PB10>;#endif	// defined(COMP1_BASE)

//////////////////////////////////////////////////////////////////////
// COMP2
//////////////////////////////////////////////////////////////////////
#if defined(COMP2_BASE)
/// A default configuration to map COMP2 INM on PB3 pin
using COMP2_INM_PB3 = AnyAnalog<Port::PB, 3>;/// A default configuration to map COMP2 INM on PB7 pin
using COMP2_INM_PB7 = AnyAnalog<Port::PB, 7>;/// A default configuration to map COMP2 INP on PB4 pin
using COMP2_INP_PB4 = AnyAnalog<Port::PB, 4>;/// A default configuration to map COMP2 INP on PB6 pin
using COMP2_INP_PB6 = AnyAnalog<Port::PB, 6>;/// A default configuration to map COMP2 OUT on PB5 pin
using COMP2_OUT_PB5 = AnyAltOut<Port::PB, 5, AfCOMP2_OUT_PB5>;/// A default configuration to map COMP2 OUT on PB11 pin
using COMP2_OUT_PB11 = AnyAltOut<Port::PB, 11, AfCOMP2_OUT_PB11>;#endif	// defined(COMP2_BASE)

//////////////////////////////////////////////////////////////////////
// DAC1
//////////////////////////////////////////////////////////////////////
#if defined(DAC1_BASE)
/// A default configuration to map DAC1 OUT1 on PA4 pin
using DAC1_OUT1_PA4 = AnyAnalog<Port::PA, 4>;/// A default configuration to map DAC1 OUT2 on PA5 pin
using DAC1_OUT2_PA5 = AnyAnalog<Port::PA, 5>;#endif	// defined(DAC1_BASE)

//////////////////////////////////////////////////////////////////////
// DFSDM1
//////////////////////////////////////////////////////////////////////
#if defined(DFSDM1_BASE)
/// A default configuration to map DFSDM1 CKIN0 on PB2 pin
using DFSDM1_CKIN0_PB2 = AnyAltOut<Port::PB, 2, AfDFSDM1_CKIN0_PB2>;/// A default configuration to map DFSDM1 CKIN1 on PB13 pin
using DFSDM1_CKIN1_PB13 = AnyAltOut<Port::PB, 13, AfDFSDM1_CKIN1_PB13>;/// A default configuration to map DFSDM1 CKIN2 on PB15 pin
using DFSDM1_CKIN2_PB15 = AnyAltOut<Port::PB, 15, AfDFSDM1_CKIN2_PB15>;/// A default configuration to map DFSDM1 CKIN3 on PC6 pin
using DFSDM1_CKIN3_PC6 = AnyAltOut<Port::PC, 6, AfDFSDM1_CKIN3_PC6>;/// A default configuration to map DFSDM1 CKIN4 on PC1 pin
using DFSDM1_CKIN4_PC1 = AnyAltOut<Port::PC, 1, AfDFSDM1_CKIN4_PC1>;/// A default configuration to map DFSDM1 CKIN5 on PB7 pin
using DFSDM1_CKIN5_PB7 = AnyAltOut<Port::PB, 7, AfDFSDM1_CKIN5_PB7>;/// A default configuration to map DFSDM1 CKIN6 on PB9 pin
using DFSDM1_CKIN6_PB9 = AnyAltOut<Port::PB, 9, AfDFSDM1_CKIN6_PB9>;/// A default configuration to map DFSDM1 CKIN7 on PB11 pin
using DFSDM1_CKIN7_PB11 = AnyAltOut<Port::PB, 11, AfDFSDM1_CKIN7_PB11>;/// A default configuration to map DFSDM1 CKOUT on PC2 pin
using DFSDM1_CKOUT_PC2 = AnyAltOut<Port::PC, 2, AfDFSDM1_CKOUT_PC2>;/// A default configuration to map DFSDM1 DATIN0 on PB1 pin
using DFSDM1_DATIN0_PB1 = AnyAltOut<Port::PB, 1, AfDFSDM1_DATIN0_PB1>;/// A default configuration to map DFSDM1 DATIN1 on PB12 pin
using DFSDM1_DATIN1_PB12 = AnyAltOut<Port::PB, 12, AfDFSDM1_DATIN1_PB12>;/// A default configuration to map DFSDM1 DATIN2 on PB14 pin
using DFSDM1_DATIN2_PB14 = AnyAltOut<Port::PB, 14, AfDFSDM1_DATIN2_PB14>;/// A default configuration to map DFSDM1 DATIN3 on PC7 pin
using DFSDM1_DATIN3_PC7 = AnyAltOut<Port::PC, 7, AfDFSDM1_DATIN3_PC7>;/// A default configuration to map DFSDM1 DATIN4 on PC0 pin
using DFSDM1_DATIN4_PC0 = AnyAltOut<Port::PC, 0, AfDFSDM1_DATIN4_PC0>;/// A default configuration to map DFSDM1 DATIN5 on PB6 pin
using DFSDM1_DATIN5_PB6 = AnyAltOut<Port::PB, 6, AfDFSDM1_DATIN5_PB6>;/// A default configuration to map DFSDM1 DATIN6 on PB8 pin
using DFSDM1_DATIN6_PB8 = AnyAltOut<Port::PB, 8, AfDFSDM1_DATIN6_PB8>;/// A default configuration to map DFSDM1 DATIN7 on PB10 pin
using DFSDM1_DATIN7_PB10 = AnyAltOut<Port::PB, 10, AfDFSDM1_DATIN7_PB10>;#if defined(GPIOD_BASE)
/// A default configuration to map DFSDM1 CKIN0 on PD4 pin
using DFSDM1_CKIN0_PD4 = AnyAltOut<Port::PD, 4, AfDFSDM1_CKIN0_PD4>;/// A default configuration to map DFSDM1 CKIN1 on PD7 pin
using DFSDM1_CKIN1_PD7 = AnyAltOut<Port::PD, 7, AfDFSDM1_CKIN1_PD7>;/// A default configuration to map DFSDM1 CKIN7 on PD1 pin
using DFSDM1_CKIN7_PD1 = AnyAltOut<Port::PD, 1, AfDFSDM1_CKIN7_PD1>;/// A default configuration to map DFSDM1 DATIN0 on PD3 pin
using DFSDM1_DATIN0_PD3 = AnyAltOut<Port::PD, 3, AfDFSDM1_DATIN0_PD3>;/// A default configuration to map DFSDM1 DATIN1 on PD6 pin
using DFSDM1_DATIN1_PD6 = AnyAltOut<Port::PD, 6, AfDFSDM1_DATIN1_PD6>;/// A default configuration to map DFSDM1 DATIN7 on PD0 pin
using DFSDM1_DATIN7_PD0 = AnyAltOut<Port::PD, 0, AfDFSDM1_DATIN7_PD0>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map DFSDM1 CKIN2 on PE8 pin
using DFSDM1_CKIN2_PE8 = AnyAltOut<Port::PE, 8, AfDFSDM1_CKIN2_PE8>;/// A default configuration to map DFSDM1 CKIN3 on PE5 pin
using DFSDM1_CKIN3_PE5 = AnyAltOut<Port::PE, 5, AfDFSDM1_CKIN3_PE5>;/// A default configuration to map DFSDM1 CKIN4 on PE11 pin
using DFSDM1_CKIN4_PE11 = AnyAltOut<Port::PE, 11, AfDFSDM1_CKIN4_PE11>;/// A default configuration to map DFSDM1 CKIN5 on PE13 pin
using DFSDM1_CKIN5_PE13 = AnyAltOut<Port::PE, 13, AfDFSDM1_CKIN5_PE13>;/// A default configuration to map DFSDM1 CKOUT on PE9 pin
using DFSDM1_CKOUT_PE9 = AnyAltOut<Port::PE, 9, AfDFSDM1_CKOUT_PE9>;/// A default configuration to map DFSDM1 DATIN2 on PE7 pin
using DFSDM1_DATIN2_PE7 = AnyAltOut<Port::PE, 7, AfDFSDM1_DATIN2_PE7>;/// A default configuration to map DFSDM1 DATIN3 on PE4 pin
using DFSDM1_DATIN3_PE4 = AnyAltOut<Port::PE, 4, AfDFSDM1_DATIN3_PE4>;/// A default configuration to map DFSDM1 DATIN4 on PE10 pin
using DFSDM1_DATIN4_PE10 = AnyAltOut<Port::PE, 10, AfDFSDM1_DATIN4_PE10>;/// A default configuration to map DFSDM1 DATIN5 on PE12 pin
using DFSDM1_DATIN5_PE12 = AnyAltOut<Port::PE, 12, AfDFSDM1_DATIN5_PE12>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map DFSDM1 CKIN6 on PF14 pin
using DFSDM1_CKIN6_PF14 = AnyAltOut<Port::PF, 14, AfDFSDM1_CKIN6_PF14>;/// A default configuration to map DFSDM1 DATIN6 on PF13 pin
using DFSDM1_DATIN6_PF13 = AnyAltOut<Port::PF, 13, AfDFSDM1_DATIN6_PF13>;#endif	// defined(GPIOF_BASE)
#endif	// defined(DFSDM1_BASE)

//////////////////////////////////////////////////////////////////////
// DCMI
//////////////////////////////////////////////////////////////////////
#if defined(DCMI_BASE)
/// A default configuration to map DCMI D0 on PA9 pin
using DCMI_D0_PA9 = AnyAltOut<Port::PA, 9, AfDCMI_D0_PA9>;/// A default configuration to map DCMI D0 on PC6 pin
using DCMI_D0_PC6 = AnyAltOut<Port::PC, 6, AfDCMI_D0_PC6>;/// A default configuration to map DCMI D1 on PA10 pin
using DCMI_D1_PA10 = AnyAltOut<Port::PA, 10, AfDCMI_D1_PA10>;/// A default configuration to map DCMI D1 on PC7 pin
using DCMI_D1_PC7 = AnyAltOut<Port::PC, 7, AfDCMI_D1_PC7>;/// A default configuration to map DCMI D10 on PB5 pin
using DCMI_D10_PB5 = AnyAltOut<Port::PB, 5, AfDCMI_D10_PB5>;/// A default configuration to map DCMI D12 on PB4 pin
using DCMI_D12_PB4 = AnyAltOut<Port::PB, 4, AfDCMI_D12_PB4>;/// A default configuration to map DCMI D2 on PC8 pin
using DCMI_D2_PC8 = AnyAltOut<Port::PC, 8, AfDCMI_D2_PC8>;/// A default configuration to map DCMI D3 on PC9 pin
using DCMI_D3_PC9 = AnyAltOut<Port::PC, 9, AfDCMI_D3_PC9>;/// A default configuration to map DCMI D4 on PC11 pin
using DCMI_D4_PC11 = AnyAltOut<Port::PC, 11, AfDCMI_D4_PC11>;/// A default configuration to map DCMI D5 on PB6 pin
using DCMI_D5_PB6 = AnyAltOut<Port::PB, 6, AfDCMI_D5_PB6>;/// A default configuration to map DCMI D6 on PB8 pin
using DCMI_D6_PB8 = AnyAltOut<Port::PB, 8, AfDCMI_D6_PB8>;/// A default configuration to map DCMI D7 on PB9 pin
using DCMI_D7_PB9 = AnyAltOut<Port::PB, 9, AfDCMI_D7_PB9>;/// A default configuration to map DCMI D8 on PC10 pin
using DCMI_D8_PC10 = AnyAltOut<Port::PC, 10, AfDCMI_D8_PC10>;/// A default configuration to map DCMI D9 on PC12 pin
using DCMI_D9_PC12 = AnyAltOut<Port::PC, 12, AfDCMI_D9_PC12>;/// A default configuration to map DCMI HSYNC on PA4 pin
using DCMI_HSYNC_PA4 = AnyAltOut<Port::PA, 4, AfDCMI_HSYNC_PA4>;/// A default configuration to map DCMI PIXCLK on PA6 pin
using DCMI_PIXCLK_PA6 = AnyAltOut<Port::PA, 6, AfDCMI_PIXCLK_PA6>;/// A default configuration to map DCMI VSYNC on PB7 pin
using DCMI_VSYNC_PB7 = AnyAltOut<Port::PB, 7, AfDCMI_VSYNC_PB7>;#if defined(GPIOD_BASE)
/// A default configuration to map DCMI D10 on PD6 pin
using DCMI_D10_PD6 = AnyAltOut<Port::PD, 6, AfDCMI_D10_PD6>;/// A default configuration to map DCMI D11 on PD2 pin
using DCMI_D11_PD2 = AnyAltOut<Port::PD, 2, AfDCMI_D11_PD2>;/// A default configuration to map DCMI D5 on PD3 pin
using DCMI_D5_PD3 = AnyAltOut<Port::PD, 3, AfDCMI_D5_PD3>;/// A default configuration to map DCMI HSYNC on PD8 pin
using DCMI_HSYNC_PD8 = AnyAltOut<Port::PD, 8, AfDCMI_HSYNC_PD8>;/// A default configuration to map DCMI PIXCLK on PD9 pin
using DCMI_PIXCLK_PD9 = AnyAltOut<Port::PD, 9, AfDCMI_PIXCLK_PD9>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map DCMI D2 on PE0 pin
using DCMI_D2_PE0 = AnyAltOut<Port::PE, 0, AfDCMI_D2_PE0>;/// A default configuration to map DCMI D3 on PE1 pin
using DCMI_D3_PE1 = AnyAltOut<Port::PE, 1, AfDCMI_D3_PE1>;/// A default configuration to map DCMI D4 on PE4 pin
using DCMI_D4_PE4 = AnyAltOut<Port::PE, 4, AfDCMI_D4_PE4>;/// A default configuration to map DCMI D6 on PE5 pin
using DCMI_D6_PE5 = AnyAltOut<Port::PE, 5, AfDCMI_D6_PE5>;/// A default configuration to map DCMI D7 on PE6 pin
using DCMI_D7_PE6 = AnyAltOut<Port::PE, 6, AfDCMI_D7_PE6>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map DCMI D11 on PF10 pin
using DCMI_D11_PF10 = AnyAltOut<Port::PF, 10, AfDCMI_D11_PF10>;/// A default configuration to map DCMI D12 on PF11 pin
using DCMI_D12_PF11 = AnyAltOut<Port::PF, 11, AfDCMI_D12_PF11>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map DCMI D13 on PG15 pin
using DCMI_D13_PG15 = AnyAltOut<Port::PG, 15, AfDCMI_D13_PG15>;#endif	// defined(GPIOG_BASE)
#if defined(GPIOH_BASE)
/// A default configuration to map DCMI D0 on PH9 pin
using DCMI_D0_PH9 = AnyAltOut<Port::PH, 9, AfDCMI_D0_PH9>;/// A default configuration to map DCMI D1 on PH10 pin
using DCMI_D1_PH10 = AnyAltOut<Port::PH, 10, AfDCMI_D1_PH10>;/// A default configuration to map DCMI D11 on PH15 pin
using DCMI_D11_PH15 = AnyAltOut<Port::PH, 15, AfDCMI_D11_PH15>;/// A default configuration to map DCMI D2 on PH11 pin
using DCMI_D2_PH11 = AnyAltOut<Port::PH, 11, AfDCMI_D2_PH11>;/// A default configuration to map DCMI D3 on PH12 pin
using DCMI_D3_PH12 = AnyAltOut<Port::PH, 12, AfDCMI_D3_PH12>;/// A default configuration to map DCMI D4 on PH14 pin
using DCMI_D4_PH14 = AnyAltOut<Port::PH, 14, AfDCMI_D4_PH14>;/// A default configuration to map DCMI D8 on PH6 pin
using DCMI_D8_PH6 = AnyAltOut<Port::PH, 6, AfDCMI_D8_PH6>;/// A default configuration to map DCMI D9 on PH7 pin
using DCMI_D9_PH7 = AnyAltOut<Port::PH, 7, AfDCMI_D9_PH7>;/// A default configuration to map DCMI HSYNC on PH8 pin
using DCMI_HSYNC_PH8 = AnyAltOut<Port::PH, 8, AfDCMI_HSYNC_PH8>;/// A default configuration to map DCMI PIXCLK on PH5 pin
using DCMI_PIXCLK_PH5 = AnyAltOut<Port::PH, 5, AfDCMI_PIXCLK_PH5>;#endif	// defined(GPIOH_BASE)
#if defined(GPIOI_BASE)
/// A default configuration to map DCMI D10 on PI3 pin
using DCMI_D10_PI3 = AnyAltOut<Port::PI, 3, AfDCMI_D10_PI3>;/// A default configuration to map DCMI D12 on PI8 pin
using DCMI_D12_PI8 = AnyAltOut<Port::PI, 8, AfDCMI_D12_PI8>;/// A default configuration to map DCMI D13 on PI0 pin
using DCMI_D13_PI0 = AnyAltOut<Port::PI, 0, AfDCMI_D13_PI0>;/// A default configuration to map DCMI D5 on PI4 pin
using DCMI_D5_PI4 = AnyAltOut<Port::PI, 4, AfDCMI_D5_PI4>;/// A default configuration to map DCMI D6 on PI6 pin
using DCMI_D6_PI6 = AnyAltOut<Port::PI, 6, AfDCMI_D6_PI6>;/// A default configuration to map DCMI D7 on PI7 pin
using DCMI_D7_PI7 = AnyAltOut<Port::PI, 7, AfDCMI_D7_PI7>;/// A default configuration to map DCMI D8 on PI1 pin
using DCMI_D8_PI1 = AnyAltOut<Port::PI, 1, AfDCMI_D8_PI1>;/// A default configuration to map DCMI D9 on PI2 pin
using DCMI_D9_PI2 = AnyAltOut<Port::PI, 2, AfDCMI_D9_PI2>;/// A default configuration to map DCMI VSYNC on PI5 pin
using DCMI_VSYNC_PI5 = AnyAltOut<Port::PI, 5, AfDCMI_VSYNC_PI5>;#endif	// defined(GPIOI_BASE)
#endif	// defined(DCMI_BASE)

//////////////////////////////////////////////////////////////////////
// FMC
//////////////////////////////////////////////////////////////////////
#if defined(FMC_BASE)
/// A default configuration to map FMC NL on PB7 pin
using FMC_NL_PB7 = AnyAltOut<Port::PB, 7, AfFMC_NL_PB7>;#if defined(GPIOD_BASE)
/// A default configuration to map FMC A16 on PD11 pin
using FMC_A16_PD11 = AnyAltOut<Port::PD, 11, AfFMC_A16_PD11>;/// A default configuration to map FMC A17 on PD12 pin
using FMC_A17_PD12 = AnyAltOut<Port::PD, 12, AfFMC_A17_PD12>;/// A default configuration to map FMC A18 on PD13 pin
using FMC_A18_PD13 = AnyAltOut<Port::PD, 13, AfFMC_A18_PD13>;/// A default configuration to map FMC CLK on PD3 pin
using FMC_CLK_PD3 = AnyAltOut<Port::PD, 3, AfFMC_CLK_PD3>;/// A default configuration to map FMC D0 on PD14 pin
using FMC_D0_PD14 = AnyAltOut<Port::PD, 14, AfFMC_D0_PD14>;/// A default configuration to map FMC D1 on PD15 pin
using FMC_D1_PD15 = AnyAltOut<Port::PD, 15, AfFMC_D1_PD15>;/// A default configuration to map FMC D13 on PD8 pin
using FMC_D13_PD8 = AnyAltOut<Port::PD, 8, AfFMC_D13_PD8>;/// A default configuration to map FMC D14 on PD9 pin
using FMC_D14_PD9 = AnyAltOut<Port::PD, 9, AfFMC_D14_PD9>;/// A default configuration to map FMC D15 on PD10 pin
using FMC_D15_PD10 = AnyAltOut<Port::PD, 10, AfFMC_D15_PD10>;/// A default configuration to map FMC D2 on PD0 pin
using FMC_D2_PD0 = AnyAltOut<Port::PD, 0, AfFMC_D2_PD0>;/// A default configuration to map FMC D3 on PD1 pin
using FMC_D3_PD1 = AnyAltOut<Port::PD, 1, AfFMC_D3_PD1>;/// A default configuration to map FMC NE1 on PD7 pin
using FMC_NE1_PD7 = AnyAltOut<Port::PD, 7, AfFMC_NE1_PD7>;/// A default configuration to map FMC NOE on PD4 pin
using FMC_NOE_PD4 = AnyAltOut<Port::PD, 4, AfFMC_NOE_PD4>;/// A default configuration to map FMC NWAIT on PD6 pin
using FMC_NWAIT_PD6 = AnyAltOut<Port::PD, 6, AfFMC_NWAIT_PD6>;/// A default configuration to map FMC NWE on PD5 pin
using FMC_NWE_PD5 = AnyAltOut<Port::PD, 5, AfFMC_NWE_PD5>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map FMC A19 on PE3 pin
using FMC_A19_PE3 = AnyAltOut<Port::PE, 3, AfFMC_A19_PE3>;/// A default configuration to map FMC A20 on PE4 pin
using FMC_A20_PE4 = AnyAltOut<Port::PE, 4, AfFMC_A20_PE4>;/// A default configuration to map FMC A21 on PE5 pin
using FMC_A21_PE5 = AnyAltOut<Port::PE, 5, AfFMC_A21_PE5>;/// A default configuration to map FMC A22 on PE6 pin
using FMC_A22_PE6 = AnyAltOut<Port::PE, 6, AfFMC_A22_PE6>;/// A default configuration to map FMC A23 on PE2 pin
using FMC_A23_PE2 = AnyAltOut<Port::PE, 2, AfFMC_A23_PE2>;/// A default configuration to map FMC D10 on PE13 pin
using FMC_D10_PE13 = AnyAltOut<Port::PE, 13, AfFMC_D10_PE13>;/// A default configuration to map FMC D11 on PE14 pin
using FMC_D11_PE14 = AnyAltOut<Port::PE, 14, AfFMC_D11_PE14>;/// A default configuration to map FMC D12 on PE15 pin
using FMC_D12_PE15 = AnyAltOut<Port::PE, 15, AfFMC_D12_PE15>;/// A default configuration to map FMC D4 on PE7 pin
using FMC_D4_PE7 = AnyAltOut<Port::PE, 7, AfFMC_D4_PE7>;/// A default configuration to map FMC D5 on PE8 pin
using FMC_D5_PE8 = AnyAltOut<Port::PE, 8, AfFMC_D5_PE8>;/// A default configuration to map FMC D6 on PE9 pin
using FMC_D6_PE9 = AnyAltOut<Port::PE, 9, AfFMC_D6_PE9>;/// A default configuration to map FMC D7 on PE10 pin
using FMC_D7_PE10 = AnyAltOut<Port::PE, 10, AfFMC_D7_PE10>;/// A default configuration to map FMC D8 on PE11 pin
using FMC_D8_PE11 = AnyAltOut<Port::PE, 11, AfFMC_D8_PE11>;/// A default configuration to map FMC D9 on PE12 pin
using FMC_D9_PE12 = AnyAltOut<Port::PE, 12, AfFMC_D9_PE12>;/// A default configuration to map FMC NBL0 on PE0 pin
using FMC_NBL0_PE0 = AnyAltOut<Port::PE, 0, AfFMC_NBL0_PE0>;/// A default configuration to map FMC NBL1 on PE1 pin
using FMC_NBL1_PE1 = AnyAltOut<Port::PE, 1, AfFMC_NBL1_PE1>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map FMC A0 on PF0 pin
using FMC_A0_PF0 = AnyAltOut<Port::PF, 0, AfFMC_A0_PF0>;/// A default configuration to map FMC A1 on PF1 pin
using FMC_A1_PF1 = AnyAltOut<Port::PF, 1, AfFMC_A1_PF1>;/// A default configuration to map FMC A2 on PF2 pin
using FMC_A2_PF2 = AnyAltOut<Port::PF, 2, AfFMC_A2_PF2>;/// A default configuration to map FMC A3 on PF3 pin
using FMC_A3_PF3 = AnyAltOut<Port::PF, 3, AfFMC_A3_PF3>;/// A default configuration to map FMC A4 on PF4 pin
using FMC_A4_PF4 = AnyAltOut<Port::PF, 4, AfFMC_A4_PF4>;/// A default configuration to map FMC A5 on PF5 pin
using FMC_A5_PF5 = AnyAltOut<Port::PF, 5, AfFMC_A5_PF5>;/// A default configuration to map FMC A6 on PF12 pin
using FMC_A6_PF12 = AnyAltOut<Port::PF, 12, AfFMC_A6_PF12>;/// A default configuration to map FMC A7 on PF13 pin
using FMC_A7_PF13 = AnyAltOut<Port::PF, 13, AfFMC_A7_PF13>;/// A default configuration to map FMC A8 on PF14 pin
using FMC_A8_PF14 = AnyAltOut<Port::PF, 14, AfFMC_A8_PF14>;/// A default configuration to map FMC A9 on PF15 pin
using FMC_A9_PF15 = AnyAltOut<Port::PF, 15, AfFMC_A9_PF15>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map FMC A10 on PG0 pin
using FMC_A10_PG0 = AnyAltOut<Port::PG, 0, AfFMC_A10_PG0>;/// A default configuration to map FMC A11 on PG1 pin
using FMC_A11_PG1 = AnyAltOut<Port::PG, 1, AfFMC_A11_PG1>;/// A default configuration to map FMC A12 on PG2 pin
using FMC_A12_PG2 = AnyAltOut<Port::PG, 2, AfFMC_A12_PG2>;/// A default configuration to map FMC A13 on PG3 pin
using FMC_A13_PG3 = AnyAltOut<Port::PG, 3, AfFMC_A13_PG3>;/// A default configuration to map FMC A14 on PG4 pin
using FMC_A14_PG4 = AnyAltOut<Port::PG, 4, AfFMC_A14_PG4>;/// A default configuration to map FMC A15 on PG5 pin
using FMC_A15_PG5 = AnyAltOut<Port::PG, 5, AfFMC_A15_PG5>;/// A default configuration to map FMC A24 on PG13 pin
using FMC_A24_PG13 = AnyAltOut<Port::PG, 13, AfFMC_A24_PG13>;/// A default configuration to map FMC A25 on PG14 pin
using FMC_A25_PG14 = AnyAltOut<Port::PG, 14, AfFMC_A25_PG14>;/// A default configuration to map FMC INT on PG7 pin
using FMC_INT_PG7 = AnyAltOut<Port::PG, 7, AfFMC_INT_PG7>;/// A default configuration to map FMC NCE on PG9 pin
using FMC_NCE_PG9 = AnyAltOut<Port::PG, 9, AfFMC_NCE_PG9>;/// A default configuration to map FMC NE2 on PG9 pin
using FMC_NE2_PG9 = AnyAltOut<Port::PG, 9, AfFMC_NE2_PG9>;/// A default configuration to map FMC NE3 on PG10 pin
using FMC_NE3_PG10 = AnyAltOut<Port::PG, 10, AfFMC_NE3_PG10>;/// A default configuration to map FMC NE4 on PG12 pin
using FMC_NE4_PG12 = AnyAltOut<Port::PG, 12, AfFMC_NE4_PG12>;#endif	// defined(GPIOG_BASE)
#endif	// defined(FMC_BASE)

//////////////////////////////////////////////////////////////////////
// IR
//////////////////////////////////////////////////////////////////////
#if defined(TIM16_BASE)
/// A default configuration to map IR OUT on PA13 pin
using IR_OUT_PA13 = AnyAltOut<Port::PA, 13, AfIR_OUT_PA13>;/// A default configuration to map IR OUT on PB9 pin
using IR_OUT_PB9 = AnyAltOut<Port::PB, 9, AfIR_OUT_PB9>;#endif	// defined(TIM16_BASE)

//////////////////////////////////////////////////////////////////////
// I2C1
//////////////////////////////////////////////////////////////////////
#if defined(I2C1_BASE)
/// A default configuration to map I2C1 SCL on PA9 pin
using I2C1_SCL_PA9 = AnyAltOutOD<Port::PA, 9, AfI2C1_SCL_PA9>;/// A default configuration to map I2C1 SCL on PB6 pin
using I2C1_SCL_PB6 = AnyAltOutOD<Port::PB, 6, AfI2C1_SCL_PB6>;/// A default configuration to map I2C1 SCL on PB8 pin
using I2C1_SCL_PB8 = AnyAltOutOD<Port::PB, 8, AfI2C1_SCL_PB8>;/// A default configuration to map I2C1 SDA on PA10 pin
using I2C1_SDA_PA10 = AnyAltOutOD<Port::PA, 10, AfI2C1_SDA_PA10>;/// A default configuration to map I2C1 SDA on PB7 pin
using I2C1_SDA_PB7 = AnyAltOutOD<Port::PB, 7, AfI2C1_SDA_PB7>;/// A default configuration to map I2C1 SDA on PB9 pin
using I2C1_SDA_PB9 = AnyAltOutOD<Port::PB, 9, AfI2C1_SDA_PB9>;/// A default configuration to map I2C1 SMBA on PA1 pin
using I2C1_SMBA_PA1 = AnyAltOutOD<Port::PA, 1, AfI2C1_SMBA_PA1>;/// A default configuration to map I2C1 SMBA on PA14 pin
using I2C1_SMBA_PA14 = AnyAltOutOD<Port::PA, 14, AfI2C1_SMBA_PA14>;/// A default configuration to map I2C1 SMBA on PB5 pin
using I2C1_SMBA_PB5 = AnyAltOutOD<Port::PB, 5, AfI2C1_SMBA_PB5>;#if defined(GPIOG_BASE)
/// A default configuration to map I2C1 SCL on PG14 pin
using I2C1_SCL_PG14 = AnyAltOutOD<Port::PG, 14, AfI2C1_SCL_PG14>;/// A default configuration to map I2C1 SDA on PG13 pin
using I2C1_SDA_PG13 = AnyAltOutOD<Port::PG, 13, AfI2C1_SDA_PG13>;/// A default configuration to map I2C1 SMBA on PG15 pin
using I2C1_SMBA_PG15 = AnyAltOutOD<Port::PG, 15, AfI2C1_SMBA_PG15>;#endif	// defined(GPIOG_BASE)
#endif	// defined(I2C1_BASE)

//////////////////////////////////////////////////////////////////////
// I2C2
//////////////////////////////////////////////////////////////////////
#if defined(I2C2_BASE)
/// A default configuration to map I2C2 SCL on PB10 pin
using I2C2_SCL_PB10 = AnyAltOutOD<Port::PB, 10, AfI2C2_SCL_PB10>;/// A default configuration to map I2C2 SCL on PB13 pin
using I2C2_SCL_PB13 = AnyAltOutOD<Port::PB, 13, AfI2C2_SCL_PB13>;/// A default configuration to map I2C2 SDA on PB11 pin
using I2C2_SDA_PB11 = AnyAltOutOD<Port::PB, 11, AfI2C2_SDA_PB11>;/// A default configuration to map I2C2 SDA on PB14 pin
using I2C2_SDA_PB14 = AnyAltOutOD<Port::PB, 14, AfI2C2_SDA_PB14>;/// A default configuration to map I2C2 SMBA on PB12 pin
using I2C2_SMBA_PB12 = AnyAltOutOD<Port::PB, 12, AfI2C2_SMBA_PB12>;#if defined(GPIOF_BASE)
/// A default configuration to map I2C2 SCL on PF1 pin
using I2C2_SCL_PF1 = AnyAltOutOD<Port::PF, 1, AfI2C2_SCL_PF1>;/// A default configuration to map I2C2 SDA on PF0 pin
using I2C2_SDA_PF0 = AnyAltOutOD<Port::PF, 0, AfI2C2_SDA_PF0>;/// A default configuration to map I2C2 SMBA on PF2 pin
using I2C2_SMBA_PF2 = AnyAltOutOD<Port::PF, 2, AfI2C2_SMBA_PF2>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOH_BASE)
/// A default configuration to map I2C2 SCL on PH4 pin
using I2C2_SCL_PH4 = AnyAltOutOD<Port::PH, 4, AfI2C2_SCL_PH4>;/// A default configuration to map I2C2 SDA on PH5 pin
using I2C2_SDA_PH5 = AnyAltOutOD<Port::PH, 5, AfI2C2_SDA_PH5>;/// A default configuration to map I2C2 SMBA on PH6 pin
using I2C2_SMBA_PH6 = AnyAltOutOD<Port::PH, 6, AfI2C2_SMBA_PH6>;#endif	// defined(GPIOH_BASE)
#endif	// defined(I2C2_BASE)

//////////////////////////////////////////////////////////////////////
// I2C3
//////////////////////////////////////////////////////////////////////
#if defined(I2C3_BASE)
/// A default configuration to map I2C3 SCL on PA7 pin
using I2C3_SCL_PA7 = AnyAltOutOD<Port::PA, 7, AfI2C3_SCL_PA7>;/// A default configuration to map I2C3 SCL on PC0 pin
using I2C3_SCL_PC0 = AnyAltOutOD<Port::PC, 0, AfI2C3_SCL_PC0>;/// A default configuration to map I2C3 SDA on PB4 pin
using I2C3_SDA_PB4 = AnyAltOutOD<Port::PB, 4, AfI2C3_SDA_PB4>;/// A default configuration to map I2C3 SDA on PC1 pin
using I2C3_SDA_PC1 = AnyAltOutOD<Port::PC, 1, AfI2C3_SDA_PC1>;/// A default configuration to map I2C3 SDA on PC9 pin
using I2C3_SDA_PC9 = AnyAltOutOD<Port::PC, 9, AfI2C3_SDA_PC9>;/// A default configuration to map I2C3 SMBA on PB2 pin
using I2C3_SMBA_PB2 = AnyAltOutOD<Port::PB, 2, AfI2C3_SMBA_PB2>;#if defined(GPIOG_BASE)
/// A default configuration to map I2C3 SCL on PG7 pin
using I2C3_SCL_PG7 = AnyAltOutOD<Port::PG, 7, AfI2C3_SCL_PG7>;/// A default configuration to map I2C3 SDA on PG8 pin
using I2C3_SDA_PG8 = AnyAltOutOD<Port::PG, 8, AfI2C3_SDA_PG8>;/// A default configuration to map I2C3 SMBA on PG6 pin
using I2C3_SMBA_PG6 = AnyAltOutOD<Port::PG, 6, AfI2C3_SMBA_PG6>;#endif	// defined(GPIOG_BASE)
#if defined(GPIOH_BASE)
/// A default configuration to map I2C3 SCL on PH7 pin
using I2C3_SCL_PH7 = AnyAltOutOD<Port::PH, 7, AfI2C3_SCL_PH7>;/// A default configuration to map I2C3 SDA on PH8 pin
using I2C3_SDA_PH8 = AnyAltOutOD<Port::PH, 8, AfI2C3_SDA_PH8>;/// A default configuration to map I2C3 SMBA on PH9 pin
using I2C3_SMBA_PH9 = AnyAltOutOD<Port::PH, 9, AfI2C3_SMBA_PH9>;#endif	// defined(GPIOH_BASE)
#endif	// defined(I2C3_BASE)

//////////////////////////////////////////////////////////////////////
// I2C4
//////////////////////////////////////////////////////////////////////
#if defined(I2C4_BASE)
/// A default configuration to map I2C4 SCL on PB6 pin
using I2C4_SCL_PB6 = AnyAltOutOD<Port::PB, 6, AfI2C4_SCL_PB6>;/// A default configuration to map I2C4 SCL on PB10 pin
using I2C4_SCL_PB10 = AnyAltOutOD<Port::PB, 10, AfI2C4_SCL_PB10>;/// A default configuration to map I2C4 SCL on PC0 pin
using I2C4_SCL_PC0 = AnyAltOutOD<Port::PC, 0, AfI2C4_SCL_PC0>;/// A default configuration to map I2C4 SDA on PB7 pin
using I2C4_SDA_PB7 = AnyAltOutOD<Port::PB, 7, AfI2C4_SDA_PB7>;/// A default configuration to map I2C4 SDA on PB11 pin
using I2C4_SDA_PB11 = AnyAltOutOD<Port::PB, 11, AfI2C4_SDA_PB11>;/// A default configuration to map I2C4 SDA on PC1 pin
using I2C4_SDA_PC1 = AnyAltOutOD<Port::PC, 1, AfI2C4_SDA_PC1>;/// A default configuration to map I2C4 SMBA on PA14 pin
using I2C4_SMBA_PA14 = AnyAltOutOD<Port::PA, 14, AfI2C4_SMBA_PA14>;#if defined(GPIOD_BASE)
/// A default configuration to map I2C4 SCL on PD12 pin
using I2C4_SCL_PD12 = AnyAltOutOD<Port::PD, 12, AfI2C4_SCL_PD12>;/// A default configuration to map I2C4 SDA on PD13 pin
using I2C4_SDA_PD13 = AnyAltOutOD<Port::PD, 13, AfI2C4_SDA_PD13>;/// A default configuration to map I2C4 SMBA on PD11 pin
using I2C4_SMBA_PD11 = AnyAltOutOD<Port::PD, 11, AfI2C4_SMBA_PD11>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map I2C4 SCL on PF14 pin
using I2C4_SCL_PF14 = AnyAltOutOD<Port::PF, 14, AfI2C4_SCL_PF14>;/// A default configuration to map I2C4 SDA on PF15 pin
using I2C4_SDA_PF15 = AnyAltOutOD<Port::PF, 15, AfI2C4_SDA_PF15>;/// A default configuration to map I2C4 SMBA on PF13 pin
using I2C4_SMBA_PF13 = AnyAltOutOD<Port::PF, 13, AfI2C4_SMBA_PF13>;#endif	// defined(GPIOF_BASE)
#endif	// defined(I2C4_BASE)

//////////////////////////////////////////////////////////////////////
// LCD
//////////////////////////////////////////////////////////////////////
#if defined(LCD_BASE)
/// A default configuration to map LCD COM0 on PA8 pin
using LCD_COM0_PA8 = AnyAltOut<Port::PA, 8, AfLCD_COM0_PA8>;/// A default configuration to map LCD COM1 on PA9 pin
using LCD_COM1_PA9 = AnyAltOut<Port::PA, 9, AfLCD_COM1_PA9>;/// A default configuration to map LCD COM2 on PA10 pin
using LCD_COM2_PA10 = AnyAltOut<Port::PA, 10, AfLCD_COM2_PA10>;/// A default configuration to map LCD COM3 on PB9 pin
using LCD_COM3_PB9 = AnyAltOut<Port::PB, 9, AfLCD_COM3_PB9>;/// A default configuration to map LCD COM4 on PC10 pin
using LCD_COM4_PC10 = AnyAltOut<Port::PC, 10, AfLCD_COM4_PC10>;/// A default configuration to map LCD COM5 on PC11 pin
using LCD_COM5_PC11 = AnyAltOut<Port::PC, 11, AfLCD_COM5_PC11>;/// A default configuration to map LCD COM6 on PC12 pin
using LCD_COM6_PC12 = AnyAltOut<Port::PC, 12, AfLCD_COM6_PC12>;/// A default configuration to map LCD SEG0 on PA1 pin
using LCD_SEG0_PA1 = AnyAltOut<Port::PA, 1, AfLCD_SEG0_PA1>;/// A default configuration to map LCD SEG1 on PA2 pin
using LCD_SEG1_PA2 = AnyAltOut<Port::PA, 2, AfLCD_SEG1_PA2>;/// A default configuration to map LCD SEG10 on PB10 pin
using LCD_SEG10_PB10 = AnyAltOut<Port::PB, 10, AfLCD_SEG10_PB10>;/// A default configuration to map LCD SEG11 on PB11 pin
using LCD_SEG11_PB11 = AnyAltOut<Port::PB, 11, AfLCD_SEG11_PB11>;/// A default configuration to map LCD SEG12 on PB12 pin
using LCD_SEG12_PB12 = AnyAltOut<Port::PB, 12, AfLCD_SEG12_PB12>;/// A default configuration to map LCD SEG13 on PB13 pin
using LCD_SEG13_PB13 = AnyAltOut<Port::PB, 13, AfLCD_SEG13_PB13>;/// A default configuration to map LCD SEG14 on PB14 pin
using LCD_SEG14_PB14 = AnyAltOut<Port::PB, 14, AfLCD_SEG14_PB14>;/// A default configuration to map LCD SEG15 on PB15 pin
using LCD_SEG15_PB15 = AnyAltOut<Port::PB, 15, AfLCD_SEG15_PB15>;/// A default configuration to map LCD SEG16 on PB8 pin
using LCD_SEG16_PB8 = AnyAltOut<Port::PB, 8, AfLCD_SEG16_PB8>;/// A default configuration to map LCD SEG17 on PA15 pin
using LCD_SEG17_PA15 = AnyAltOut<Port::PA, 15, AfLCD_SEG17_PA15>;/// A default configuration to map LCD SEG18 on PC0 pin
using LCD_SEG18_PC0 = AnyAltOut<Port::PC, 0, AfLCD_SEG18_PC0>;/// A default configuration to map LCD SEG19 on PC1 pin
using LCD_SEG19_PC1 = AnyAltOut<Port::PC, 1, AfLCD_SEG19_PC1>;/// A default configuration to map LCD SEG2 on PA3 pin
using LCD_SEG2_PA3 = AnyAltOut<Port::PA, 3, AfLCD_SEG2_PA3>;/// A default configuration to map LCD SEG20 on PC2 pin
using LCD_SEG20_PC2 = AnyAltOut<Port::PC, 2, AfLCD_SEG20_PC2>;/// A default configuration to map LCD SEG21 on PB7 pin
using LCD_SEG21_PB7 = AnyAltOut<Port::PB, 7, AfLCD_SEG21_PB7>;/// A default configuration to map LCD SEG22 on PC4 pin
using LCD_SEG22_PC4 = AnyAltOut<Port::PC, 4, AfLCD_SEG22_PC4>;/// A default configuration to map LCD SEG23 on PC5 pin
using LCD_SEG23_PC5 = AnyAltOut<Port::PC, 5, AfLCD_SEG23_PC5>;/// A default configuration to map LCD SEG24 on PC6 pin
using LCD_SEG24_PC6 = AnyAltOut<Port::PC, 6, AfLCD_SEG24_PC6>;/// A default configuration to map LCD SEG25 on PC7 pin
using LCD_SEG25_PC7 = AnyAltOut<Port::PC, 7, AfLCD_SEG25_PC7>;/// A default configuration to map LCD SEG26 on PC8 pin
using LCD_SEG26_PC8 = AnyAltOut<Port::PC, 8, AfLCD_SEG26_PC8>;/// A default configuration to map LCD SEG27 on PC9 pin
using LCD_SEG27_PC9 = AnyAltOut<Port::PC, 9, AfLCD_SEG27_PC9>;/// A default configuration to map LCD SEG28 on PC10 pin
using LCD_SEG28_PC10 = AnyAltOut<Port::PC, 10, AfLCD_SEG28_PC10>;/// A default configuration to map LCD SEG29 on PC11 pin
using LCD_SEG29_PC11 = AnyAltOut<Port::PC, 11, AfLCD_SEG29_PC11>;/// A default configuration to map LCD SEG3 on PA6 pin
using LCD_SEG3_PA6 = AnyAltOut<Port::PA, 6, AfLCD_SEG3_PA6>;/// A default configuration to map LCD SEG30 on PC12 pin
using LCD_SEG30_PC12 = AnyAltOut<Port::PC, 12, AfLCD_SEG30_PC12>;/// A default configuration to map LCD SEG4 on PA7 pin
using LCD_SEG4_PA7 = AnyAltOut<Port::PA, 7, AfLCD_SEG4_PA7>;/// A default configuration to map LCD SEG40 on PC10 pin
using LCD_SEG40_PC10 = AnyAltOut<Port::PC, 10, AfLCD_SEG40_PC10>;/// A default configuration to map LCD SEG41 on PC11 pin
using LCD_SEG41_PC11 = AnyAltOut<Port::PC, 11, AfLCD_SEG41_PC11>;/// A default configuration to map LCD SEG42 on PC12 pin
using LCD_SEG42_PC12 = AnyAltOut<Port::PC, 12, AfLCD_SEG42_PC12>;/// A default configuration to map LCD SEG5 on PB0 pin
using LCD_SEG5_PB0 = AnyAltOut<Port::PB, 0, AfLCD_SEG5_PB0>;/// A default configuration to map LCD SEG6 on PB1 pin
using LCD_SEG6_PB1 = AnyAltOut<Port::PB, 1, AfLCD_SEG6_PB1>;/// A default configuration to map LCD SEG7 on PB3 pin
using LCD_SEG7_PB3 = AnyAltOut<Port::PB, 3, AfLCD_SEG7_PB3>;/// A default configuration to map LCD SEG8 on PB4 pin
using LCD_SEG8_PB4 = AnyAltOut<Port::PB, 4, AfLCD_SEG8_PB4>;/// A default configuration to map LCD SEG9 on PB5 pin
using LCD_SEG9_PB5 = AnyAltOut<Port::PB, 5, AfLCD_SEG9_PB5>;/// A default configuration to map LCD VLCD on PB2 pin
using LCD_VLCD_PB2 = AnyAltOut<Port::PB, 2, AfLCD_VLCD_PB2>;/// A default configuration to map LCD VLCD on PC3 pin
using LCD_VLCD_PC3 = AnyAltOut<Port::PC, 3, AfLCD_VLCD_PC3>;#if defined(GPIOD_BASE)
/// A default configuration to map LCD COM7 on PD2 pin
using LCD_COM7_PD2 = AnyAltOut<Port::PD, 2, AfLCD_COM7_PD2>;/// A default configuration to map LCD SEG28 on PD8 pin
using LCD_SEG28_PD8 = AnyAltOut<Port::PD, 8, AfLCD_SEG28_PD8>;/// A default configuration to map LCD SEG29 on PD9 pin
using LCD_SEG29_PD9 = AnyAltOut<Port::PD, 9, AfLCD_SEG29_PD9>;/// A default configuration to map LCD SEG30 on PD10 pin
using LCD_SEG30_PD10 = AnyAltOut<Port::PD, 10, AfLCD_SEG30_PD10>;/// A default configuration to map LCD SEG31 on PD2 pin
using LCD_SEG31_PD2 = AnyAltOut<Port::PD, 2, AfLCD_SEG31_PD2>;/// A default configuration to map LCD SEG31 on PD11 pin
using LCD_SEG31_PD11 = AnyAltOut<Port::PD, 11, AfLCD_SEG31_PD11>;/// A default configuration to map LCD SEG32 on PD12 pin
using LCD_SEG32_PD12 = AnyAltOut<Port::PD, 12, AfLCD_SEG32_PD12>;/// A default configuration to map LCD SEG33 on PD13 pin
using LCD_SEG33_PD13 = AnyAltOut<Port::PD, 13, AfLCD_SEG33_PD13>;/// A default configuration to map LCD SEG34 on PD14 pin
using LCD_SEG34_PD14 = AnyAltOut<Port::PD, 14, AfLCD_SEG34_PD14>;/// A default configuration to map LCD SEG35 on PD15 pin
using LCD_SEG35_PD15 = AnyAltOut<Port::PD, 15, AfLCD_SEG35_PD15>;/// A default configuration to map LCD SEG43 on PD2 pin
using LCD_SEG43_PD2 = AnyAltOut<Port::PD, 2, AfLCD_SEG43_PD2>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map LCD SEG36 on PE0 pin
using LCD_SEG36_PE0 = AnyAltOut<Port::PE, 0, AfLCD_SEG36_PE0>;/// A default configuration to map LCD SEG37 on PE1 pin
using LCD_SEG37_PE1 = AnyAltOut<Port::PE, 1, AfLCD_SEG37_PE1>;/// A default configuration to map LCD SEG38 on PE2 pin
using LCD_SEG38_PE2 = AnyAltOut<Port::PE, 2, AfLCD_SEG38_PE2>;/// A default configuration to map LCD SEG39 on PE3 pin
using LCD_SEG39_PE3 = AnyAltOut<Port::PE, 3, AfLCD_SEG39_PE3>;#endif	// defined(GPIOE_BASE)
#endif	// defined(LCD_BASE)

//////////////////////////////////////////////////////////////////////
// LPTIM1
//////////////////////////////////////////////////////////////////////
#if defined(LPTIM1_BASE)
/// A default configuration to map LPTIM1 ETR on PB6 pin
using LPTIM1_ETR_PB6 = AnyAltOut<Port::PB, 6, AfLPTIM1_ETR_PB6>;/// A default configuration to map LPTIM1 ETR on PC3 pin
using LPTIM1_ETR_PC3 = AnyAltOut<Port::PC, 3, AfLPTIM1_ETR_PC3>;/// A default configuration to map LPTIM1 IN1 on PB5 pin
using LPTIM1_IN1_PB5 = AnyAltOut<Port::PB, 5, AfLPTIM1_IN1_PB5>;/// A default configuration to map LPTIM1 IN1 on PC0 pin
using LPTIM1_IN1_PC0 = AnyAltOut<Port::PC, 0, AfLPTIM1_IN1_PC0>;/// A default configuration to map LPTIM1 IN2 on PB7 pin
using LPTIM1_IN2_PB7 = AnyAltOut<Port::PB, 7, AfLPTIM1_IN2_PB7>;/// A default configuration to map LPTIM1 IN2 on PC2 pin
using LPTIM1_IN2_PC2 = AnyAltOut<Port::PC, 2, AfLPTIM1_IN2_PC2>;/// A default configuration to map LPTIM1 OUT on PA14 pin
using LPTIM1_OUT_PA14 = AnyAltOut<Port::PA, 14, AfLPTIM1_OUT_PA14>;/// A default configuration to map LPTIM1 OUT on PB2 pin
using LPTIM1_OUT_PB2 = AnyAltOut<Port::PB, 2, AfLPTIM1_OUT_PB2>;/// A default configuration to map LPTIM1 OUT on PC1 pin
using LPTIM1_OUT_PC1 = AnyAltOut<Port::PC, 1, AfLPTIM1_OUT_PC1>;#if defined(GPIOG_BASE)
/// A default configuration to map LPTIM1 ETR on PG12 pin
using LPTIM1_ETR_PG12 = AnyAltOut<Port::PG, 12, AfLPTIM1_ETR_PG12>;/// A default configuration to map LPTIM1 IN1 on PG10 pin
using LPTIM1_IN1_PG10 = AnyAltOut<Port::PG, 10, AfLPTIM1_IN1_PG10>;/// A default configuration to map LPTIM1 IN2 on PG11 pin
using LPTIM1_IN2_PG11 = AnyAltOut<Port::PG, 11, AfLPTIM1_IN2_PG11>;/// A default configuration to map LPTIM1 OUT on PG15 pin
using LPTIM1_OUT_PG15 = AnyAltOut<Port::PG, 15, AfLPTIM1_OUT_PG15>;#endif	// defined(GPIOG_BASE)
#endif	// defined(LPTIM1_BASE)

//////////////////////////////////////////////////////////////////////
// LPTIM2
//////////////////////////////////////////////////////////////////////
#if defined(LPTIM2_BASE)
/// A default configuration to map LPTIM2 ETR on PA5 pin
using LPTIM2_ETR_PA5 = AnyAltOut<Port::PA, 5, AfLPTIM2_ETR_PA5>;/// A default configuration to map LPTIM2 ETR on PC3 pin
using LPTIM2_ETR_PC3 = AnyAltOut<Port::PC, 3, AfLPTIM2_ETR_PC3>;/// A default configuration to map LPTIM2 IN1 on PB1 pin
using LPTIM2_IN1_PB1 = AnyAltOut<Port::PB, 1, AfLPTIM2_IN1_PB1>;/// A default configuration to map LPTIM2 IN1 on PC0 pin
using LPTIM2_IN1_PC0 = AnyAltOut<Port::PC, 0, AfLPTIM2_IN1_PC0>;/// A default configuration to map LPTIM2 OUT on PA4 pin
using LPTIM2_OUT_PA4 = AnyAltOut<Port::PA, 4, AfLPTIM2_OUT_PA4>;/// A default configuration to map LPTIM2 OUT on PA8 pin
using LPTIM2_OUT_PA8 = AnyAltOut<Port::PA, 8, AfLPTIM2_OUT_PA8>;#if defined(GPIOD_BASE)
/// A default configuration to map LPTIM2 ETR on PD11 pin
using LPTIM2_ETR_PD11 = AnyAltOut<Port::PD, 11, AfLPTIM2_ETR_PD11>;/// A default configuration to map LPTIM2 IN1 on PD12 pin
using LPTIM2_IN1_PD12 = AnyAltOut<Port::PD, 12, AfLPTIM2_IN1_PD12>;/// A default configuration to map LPTIM2 OUT on PD13 pin
using LPTIM2_OUT_PD13 = AnyAltOut<Port::PD, 13, AfLPTIM2_OUT_PD13>;#endif	// defined(GPIOD_BASE)
#endif	// defined(LPTIM2_BASE)

//////////////////////////////////////////////////////////////////////
// LPUART1
//////////////////////////////////////////////////////////////////////
#if defined(LPUART1_BASE)
/// A default configuration to map LPUART1 CTS on PA6 pin
using LPUART1_CTS_PA6 = AnyAltOutOD<Port::PA, 6, AfLPUART1_CTS_PA6>;/// A default configuration to map LPUART1 CTS on PB13 pin
using LPUART1_CTS_PB13 = AnyAltOutOD<Port::PB, 13, AfLPUART1_CTS_PB13>;/// A default configuration to map LPUART1 DE on PB1 pin
using LPUART1_DE_PB1 = AnyAltOut<Port::PB, 1, AfLPUART1_DE_PB1>;/// A default configuration to map LPUART1 DE on PB12 pin
using LPUART1_DE_PB12 = AnyAltOut<Port::PB, 12, AfLPUART1_DE_PB12>;/// A default configuration to map LPUART1 RTS on PB1 pin
using LPUART1_RTS_PB1 = AnyAltOut<Port::PB, 1, AfLPUART1_RTS_PB1>;/// A default configuration to map LPUART1 RTS on PB12 pin
using LPUART1_RTS_PB12 = AnyAltOut<Port::PB, 12, AfLPUART1_RTS_PB12>;/// A default configuration to map LPUART1 RX on PA3 pin
using LPUART1_RX_PA3 = AnyAltOutOD<Port::PA, 3, AfLPUART1_RX_PA3>;/// A default configuration to map LPUART1 RX on PB10 pin
using LPUART1_RX_PB10 = AnyAltOutOD<Port::PB, 10, AfLPUART1_RX_PB10>;/// A default configuration to map LPUART1 RX on PC0 pin
using LPUART1_RX_PC0 = AnyAltOutOD<Port::PC, 0, AfLPUART1_RX_PC0>;/// A default configuration to map LPUART1 TX on PA2 pin
using LPUART1_TX_PA2 = AnyAltOut<Port::PA, 2, AfLPUART1_TX_PA2>;/// A default configuration to map LPUART1 TX on PB11 pin
using LPUART1_TX_PB11 = AnyAltOut<Port::PB, 11, AfLPUART1_TX_PB11>;/// A default configuration to map LPUART1 TX on PC1 pin
using LPUART1_TX_PC1 = AnyAltOut<Port::PC, 1, AfLPUART1_TX_PC1>;#if defined(GPIOG_BASE)
/// A default configuration to map LPUART1 CTS on PG5 pin
using LPUART1_CTS_PG5 = AnyAltOutOD<Port::PG, 5, AfLPUART1_CTS_PG5>;/// A default configuration to map LPUART1 DE on PG6 pin
using LPUART1_DE_PG6 = AnyAltOut<Port::PG, 6, AfLPUART1_DE_PG6>;/// A default configuration to map LPUART1 RTS on PG6 pin
using LPUART1_RTS_PG6 = AnyAltOut<Port::PG, 6, AfLPUART1_RTS_PG6>;/// A default configuration to map LPUART1 RX on PG8 pin
using LPUART1_RX_PG8 = AnyAltOutOD<Port::PG, 8, AfLPUART1_RX_PG8>;/// A default configuration to map LPUART1 TX on PG7 pin
using LPUART1_TX_PG7 = AnyAltOut<Port::PG, 7, AfLPUART1_TX_PG7>;#endif	// defined(GPIOG_BASE)
#endif	// defined(LPUART1_BASE)

//////////////////////////////////////////////////////////////////////
// OTG
//////////////////////////////////////////////////////////////////////
#if defined(OTG_BASE)
/// A default configuration to map OTG FS_CRS_SYNC on PB3 pin
using OTG_FS_CRS_SYNC_PB3 = AnyAltOut<Port::PB, 3, AfOTG_FS_CRS_SYNC_PB3>;/// A default configuration to map OTG FS_DM on PA11 pin
using OTG_FS_DM_PA11 = AnyAltOut<Port::PA, 11, AfOTG_FS_DM_PA11>;/// A default configuration to map OTG FS_DP on PA12 pin
using OTG_FS_DP_PA12 = AnyAltOut<Port::PA, 12, AfOTG_FS_DP_PA12>;/// A default configuration to map OTG FS_ID on PA10 pin
using OTG_FS_ID_PA10 = AnyAltOut<Port::PA, 10, AfOTG_FS_ID_PA10>;/// A default configuration to map OTG FS_NOE on PA13 pin
using OTG_FS_NOE_PA13 = AnyAltOut<Port::PA, 13, AfOTG_FS_NOE_PA13>;/// A default configuration to map OTG FS_NOE on PC9 pin
using OTG_FS_NOE_PC9 = AnyAltOut<Port::PC, 9, AfOTG_FS_NOE_PC9>;/// A default configuration to map OTG FS_SOF on PA8 pin
using OTG_FS_SOF_PA8 = AnyAltOut<Port::PA, 8, AfOTG_FS_SOF_PA8>;/// A default configuration to map OTG FS_SOF on PA14 pin
using OTG_FS_SOF_PA14 = AnyAltOut<Port::PA, 14, AfOTG_FS_SOF_PA14>;#endif	// defined(OTG_BASE)

//////////////////////////////////////////////////////////////////////
// QUADSPI
//////////////////////////////////////////////////////////////////////
#if defined(QUADSPI)
/// A default configuration to map QUADSPI BK1_IO0 on PB1 pin
using QUADSPI_BK1_IO0_PB1 = AnyAltOut<Port::PB, 1, AfQUADSPI_BK1_IO0_PB1>;/// A default configuration to map QUADSPI BK1_IO1 on PB0 pin
using QUADSPI_BK1_IO1_PB0 = AnyAltOut<Port::PB, 0, AfQUADSPI_BK1_IO1_PB0>;/// A default configuration to map QUADSPI BK1_IO2 on PA7 pin
using QUADSPI_BK1_IO2_PA7 = AnyAltOut<Port::PA, 7, AfQUADSPI_BK1_IO2_PA7>;/// A default configuration to map QUADSPI BK1_IO3 on PA6 pin
using QUADSPI_BK1_IO3_PA6 = AnyAltOut<Port::PA, 6, AfQUADSPI_BK1_IO3_PA6>;/// A default configuration to map QUADSPI BK1_NCS on PA2 pin
using QUADSPI_BK1_NCS_PA2 = AnyAltOut<Port::PA, 2, AfQUADSPI_BK1_NCS_PA2>;/// A default configuration to map QUADSPI BK1_NCS on PB11 pin
using QUADSPI_BK1_NCS_PB11 = AnyAltOut<Port::PB, 11, AfQUADSPI_BK1_NCS_PB11>;/// A default configuration to map QUADSPI BK2_IO0 on PC1 pin
using QUADSPI_BK2_IO0_PC1 = AnyAltOut<Port::PC, 1, AfQUADSPI_BK2_IO0_PC1>;/// A default configuration to map QUADSPI BK2_IO1 on PC2 pin
using QUADSPI_BK2_IO1_PC2 = AnyAltOut<Port::PC, 2, AfQUADSPI_BK2_IO1_PC2>;/// A default configuration to map QUADSPI BK2_IO2 on PC3 pin
using QUADSPI_BK2_IO2_PC3 = AnyAltOut<Port::PC, 3, AfQUADSPI_BK2_IO2_PC3>;/// A default configuration to map QUADSPI BK2_IO3 on PC4 pin
using QUADSPI_BK2_IO3_PC4 = AnyAltOut<Port::PC, 4, AfQUADSPI_BK2_IO3_PC4>;/// A default configuration to map QUADSPI BK2_NCS on PC11 pin
using QUADSPI_BK2_NCS_PC11 = AnyAltOut<Port::PC, 11, AfQUADSPI_BK2_NCS_PC11>;/// A default configuration to map QUADSPI CLK on PA3 pin
using QUADSPI_CLK_PA3 = AnyAltOut<Port::PA, 3, AfQUADSPI_CLK_PA3>;/// A default configuration to map QUADSPI CLK on PB10 pin
using QUADSPI_CLK_PB10 = AnyAltOut<Port::PB, 10, AfQUADSPI_CLK_PB10>;#if defined(GPIOD_BASE)
/// A default configuration to map QUADSPI BK2_IO0 on PD4 pin
using QUADSPI_BK2_IO0_PD4 = AnyAltOut<Port::PD, 4, AfQUADSPI_BK2_IO0_PD4>;/// A default configuration to map QUADSPI BK2_IO1 on PD5 pin
using QUADSPI_BK2_IO1_PD5 = AnyAltOut<Port::PD, 5, AfQUADSPI_BK2_IO1_PD5>;/// A default configuration to map QUADSPI BK2_IO1 on PD6 pin
using QUADSPI_BK2_IO1_PD6 = AnyAltOut<Port::PD, 6, AfQUADSPI_BK2_IO1_PD6>;/// A default configuration to map QUADSPI BK2_IO2 on PD6 pin
using QUADSPI_BK2_IO2_PD6 = AnyAltOut<Port::PD, 6, AfQUADSPI_BK2_IO2_PD6>;/// A default configuration to map QUADSPI BK2_IO3 on PD7 pin
using QUADSPI_BK2_IO3_PD7 = AnyAltOut<Port::PD, 7, AfQUADSPI_BK2_IO3_PD7>;/// A default configuration to map QUADSPI BK2_NCS on PD3 pin
using QUADSPI_BK2_NCS_PD3 = AnyAltOut<Port::PD, 3, AfQUADSPI_BK2_NCS_PD3>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map QUADSPI BK1_IO0 on PE12 pin
using QUADSPI_BK1_IO0_PE12 = AnyAltOut<Port::PE, 12, AfQUADSPI_BK1_IO0_PE12>;/// A default configuration to map QUADSPI BK1_IO1 on PE13 pin
using QUADSPI_BK1_IO1_PE13 = AnyAltOut<Port::PE, 13, AfQUADSPI_BK1_IO1_PE13>;/// A default configuration to map QUADSPI BK1_IO2 on PE14 pin
using QUADSPI_BK1_IO2_PE14 = AnyAltOut<Port::PE, 14, AfQUADSPI_BK1_IO2_PE14>;/// A default configuration to map QUADSPI BK1_IO3 on PE15 pin
using QUADSPI_BK1_IO3_PE15 = AnyAltOut<Port::PE, 15, AfQUADSPI_BK1_IO3_PE15>;/// A default configuration to map QUADSPI BK1_NCS on PE11 pin
using QUADSPI_BK1_NCS_PE11 = AnyAltOut<Port::PE, 11, AfQUADSPI_BK1_NCS_PE11>;/// A default configuration to map QUADSPI CLK on PE10 pin
using QUADSPI_CLK_PE10 = AnyAltOut<Port::PE, 10, AfQUADSPI_CLK_PE10>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map QUADSPI BK1_IO0 on PF8 pin
using QUADSPI_BK1_IO0_PF8 = AnyAltOut<Port::PF, 8, AfQUADSPI_BK1_IO0_PF8>;/// A default configuration to map QUADSPI BK1_IO1 on PF9 pin
using QUADSPI_BK1_IO1_PF9 = AnyAltOut<Port::PF, 9, AfQUADSPI_BK1_IO1_PF9>;/// A default configuration to map QUADSPI BK1_IO2 on PF7 pin
using QUADSPI_BK1_IO2_PF7 = AnyAltOut<Port::PF, 7, AfQUADSPI_BK1_IO2_PF7>;/// A default configuration to map QUADSPI BK1_IO3 on PF6 pin
using QUADSPI_BK1_IO3_PF6 = AnyAltOut<Port::PF, 6, AfQUADSPI_BK1_IO3_PF6>;/// A default configuration to map QUADSPI CLK on PF10 pin
using QUADSPI_CLK_PF10 = AnyAltOut<Port::PF, 10, AfQUADSPI_CLK_PF10>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOH_BASE)
/// A default configuration to map QUADSPI BK2_IO0 on PH2 pin
using QUADSPI_BK2_IO0_PH2 = AnyAltOut<Port::PH, 2, AfQUADSPI_BK2_IO0_PH2>;#endif	// defined(GPIOH_BASE)
#endif	// defined(QUADSPI)

//////////////////////////////////////////////////////////////////////
// RTC
//////////////////////////////////////////////////////////////////////
#if defined(RTC_BASE)
/// A default configuration to map RTC OUT on PB2 pin
using RTC_OUT_PB2 = AnyAltOut<Port::PB, 2, AfRTC_OUT_PB2>;/// A default configuration to map RTC REFIN on PB15 pin
using RTC_REFIN_PB15 = AnyAltOut<Port::PB, 15, AfRTC_REFIN_PB15>;#endif	// defined(RTC_BASE)

//////////////////////////////////////////////////////////////////////
// SAI1
//////////////////////////////////////////////////////////////////////
#if defined(SAI1_BASE)
/// A default configuration to map SAI1 EXTCLK on PA0 pin
using SAI1_EXTCLK_PA0 = AnyAltOut<Port::PA, 0, AfSAI1_EXTCLK_PA0>;/// A default configuration to map SAI1 EXTCLK on PB0 pin
using SAI1_EXTCLK_PB0 = AnyAltOut<Port::PB, 0, AfSAI1_EXTCLK_PB0>;/// A default configuration to map SAI1 FS_A on PA9 pin
using SAI1_FS_A_PA9 = AnyAltOut<Port::PA, 9, AfSAI1_FS_A_PA9>;/// A default configuration to map SAI1 FS_A on PB9 pin
using SAI1_FS_A_PB9 = AnyAltOut<Port::PB, 9, AfSAI1_FS_A_PB9>;/// A default configuration to map SAI1 FS_B on PA4 pin
using SAI1_FS_B_PA4 = AnyAltOut<Port::PA, 4, AfSAI1_FS_B_PA4>;/// A default configuration to map SAI1 FS_B on PA14 pin
using SAI1_FS_B_PA14 = AnyAltOut<Port::PA, 14, AfSAI1_FS_B_PA14>;/// A default configuration to map SAI1 FS_B on PB6 pin
using SAI1_FS_B_PB6 = AnyAltOut<Port::PB, 6, AfSAI1_FS_B_PB6>;/// A default configuration to map SAI1 MCLK_A on PA3 pin
using SAI1_MCLK_A_PA3 = AnyAltOut<Port::PA, 3, AfSAI1_MCLK_A_PA3>;/// A default configuration to map SAI1 MCLK_A on PB8 pin
using SAI1_MCLK_A_PB8 = AnyAltOut<Port::PB, 8, AfSAI1_MCLK_A_PB8>;/// A default configuration to map SAI1 MCLK_B on PB4 pin
using SAI1_MCLK_B_PB4 = AnyAltOut<Port::PB, 4, AfSAI1_MCLK_B_PB4>;/// A default configuration to map SAI1 SCK_A on PA8 pin
using SAI1_SCK_A_PA8 = AnyAltOut<Port::PA, 8, AfSAI1_SCK_A_PA8>;/// A default configuration to map SAI1 SCK_A on PB10 pin
using SAI1_SCK_A_PB10 = AnyAltOut<Port::PB, 10, AfSAI1_SCK_A_PB10>;/// A default configuration to map SAI1 SCK_B on PB3 pin
using SAI1_SCK_B_PB3 = AnyAltOut<Port::PB, 3, AfSAI1_SCK_B_PB3>;/// A default configuration to map SAI1 SD_A on PA10 pin
using SAI1_SD_A_PA10 = AnyAltOut<Port::PA, 10, AfSAI1_SD_A_PA10>;/// A default configuration to map SAI1 SD_A on PC1 pin
using SAI1_SD_A_PC1 = AnyAltOut<Port::PC, 1, AfSAI1_SD_A_PC1>;/// A default configuration to map SAI1 SD_A on PC3 pin
using SAI1_SD_A_PC3 = AnyAltOut<Port::PC, 3, AfSAI1_SD_A_PC3>;/// A default configuration to map SAI1 SD_B on PA13 pin
using SAI1_SD_B_PA13 = AnyAltOut<Port::PA, 13, AfSAI1_SD_B_PA13>;/// A default configuration to map SAI1 SD_B on PB5 pin
using SAI1_SD_B_PB5 = AnyAltOut<Port::PB, 5, AfSAI1_SD_B_PB5>;#if defined(GPIOD_BASE)
/// A default configuration to map SAI1 SD_A on PD6 pin
using SAI1_SD_A_PD6 = AnyAltOut<Port::PD, 6, AfSAI1_SD_A_PD6>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map SAI1 FS_A on PE4 pin
using SAI1_FS_A_PE4 = AnyAltOut<Port::PE, 4, AfSAI1_FS_A_PE4>;/// A default configuration to map SAI1 FS_B on PE9 pin
using SAI1_FS_B_PE9 = AnyAltOut<Port::PE, 9, AfSAI1_FS_B_PE9>;/// A default configuration to map SAI1 MCLK_A on PE2 pin
using SAI1_MCLK_A_PE2 = AnyAltOut<Port::PE, 2, AfSAI1_MCLK_A_PE2>;/// A default configuration to map SAI1 MCLK_B on PE10 pin
using SAI1_MCLK_B_PE10 = AnyAltOut<Port::PE, 10, AfSAI1_MCLK_B_PE10>;/// A default configuration to map SAI1 SCK_A on PE5 pin
using SAI1_SCK_A_PE5 = AnyAltOut<Port::PE, 5, AfSAI1_SCK_A_PE5>;/// A default configuration to map SAI1 SCK_B on PE8 pin
using SAI1_SCK_B_PE8 = AnyAltOut<Port::PE, 8, AfSAI1_SCK_B_PE8>;/// A default configuration to map SAI1 SD_A on PE6 pin
using SAI1_SD_A_PE6 = AnyAltOut<Port::PE, 6, AfSAI1_SD_A_PE6>;/// A default configuration to map SAI1 SD_B on PE3 pin
using SAI1_SD_B_PE3 = AnyAltOut<Port::PE, 3, AfSAI1_SD_B_PE3>;/// A default configuration to map SAI1 SD_B on PE7 pin
using SAI1_SD_B_PE7 = AnyAltOut<Port::PE, 7, AfSAI1_SD_B_PE7>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map SAI1 FS_B on PF9 pin
using SAI1_FS_B_PF9 = AnyAltOut<Port::PF, 9, AfSAI1_FS_B_PF9>;/// A default configuration to map SAI1 MCLK_B on PF7 pin
using SAI1_MCLK_B_PF7 = AnyAltOut<Port::PF, 7, AfSAI1_MCLK_B_PF7>;/// A default configuration to map SAI1 SCK_B on PF8 pin
using SAI1_SCK_B_PF8 = AnyAltOut<Port::PF, 8, AfSAI1_SCK_B_PF8>;/// A default configuration to map SAI1 SD_B on PF6 pin
using SAI1_SD_B_PF6 = AnyAltOut<Port::PF, 6, AfSAI1_SD_B_PF6>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map SAI1 MCLK_A on PG7 pin
using SAI1_MCLK_A_PG7 = AnyAltOut<Port::PG, 7, AfSAI1_MCLK_A_PG7>;#endif	// defined(GPIOG_BASE)
#endif	// defined(SAI1_BASE)

//////////////////////////////////////////////////////////////////////
// SAI2
//////////////////////////////////////////////////////////////////////
#if defined(SAI2_BASE)
/// A default configuration to map SAI2 EXTCLK on PA2 pin
using SAI2_EXTCLK_PA2 = AnyAltOut<Port::PA, 2, AfSAI2_EXTCLK_PA2>;/// A default configuration to map SAI2 EXTCLK on PC9 pin
using SAI2_EXTCLK_PC9 = AnyAltOut<Port::PC, 9, AfSAI2_EXTCLK_PC9>;/// A default configuration to map SAI2 FS_A on PB12 pin
using SAI2_FS_A_PB12 = AnyAltOut<Port::PB, 12, AfSAI2_FS_A_PB12>;/// A default configuration to map SAI2 FS_B on PA15 pin
using SAI2_FS_B_PA15 = AnyAltOut<Port::PA, 15, AfSAI2_FS_B_PA15>;/// A default configuration to map SAI2 MCLK_A on PB14 pin
using SAI2_MCLK_A_PB14 = AnyAltOut<Port::PB, 14, AfSAI2_MCLK_A_PB14>;/// A default configuration to map SAI2 MCLK_A on PC6 pin
using SAI2_MCLK_A_PC6 = AnyAltOut<Port::PC, 6, AfSAI2_MCLK_A_PC6>;/// A default configuration to map SAI2 MCLK_B on PC7 pin
using SAI2_MCLK_B_PC7 = AnyAltOut<Port::PC, 7, AfSAI2_MCLK_B_PC7>;/// A default configuration to map SAI2 MCLK_B on PC11 pin
using SAI2_MCLK_B_PC11 = AnyAltOut<Port::PC, 11, AfSAI2_MCLK_B_PC11>;/// A default configuration to map SAI2 SCK_A on PB13 pin
using SAI2_SCK_A_PB13 = AnyAltOut<Port::PB, 13, AfSAI2_SCK_A_PB13>;/// A default configuration to map SAI2 SCK_B on PC10 pin
using SAI2_SCK_B_PC10 = AnyAltOut<Port::PC, 10, AfSAI2_SCK_B_PC10>;/// A default configuration to map SAI2 SD_A on PB15 pin
using SAI2_SD_A_PB15 = AnyAltOut<Port::PB, 15, AfSAI2_SD_A_PB15>;/// A default configuration to map SAI2 SD_B on PC12 pin
using SAI2_SD_B_PC12 = AnyAltOut<Port::PC, 12, AfSAI2_SD_B_PC12>;#if defined(GPIOD_BASE)
/// A default configuration to map SAI2 FS_A on PD12 pin
using SAI2_FS_A_PD12 = AnyAltOut<Port::PD, 12, AfSAI2_FS_A_PD12>;/// A default configuration to map SAI2 MCLK_A on PD9 pin
using SAI2_MCLK_A_PD9 = AnyAltOut<Port::PD, 9, AfSAI2_MCLK_A_PD9>;/// A default configuration to map SAI2 SCK_A on PD10 pin
using SAI2_SCK_A_PD10 = AnyAltOut<Port::PD, 10, AfSAI2_SCK_A_PD10>;/// A default configuration to map SAI2 SD_A on PD11 pin
using SAI2_SD_A_PD11 = AnyAltOut<Port::PD, 11, AfSAI2_SD_A_PD11>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map SAI2 FS_A on PG10 pin
using SAI2_FS_A_PG10 = AnyAltOut<Port::PG, 10, AfSAI2_FS_A_PG10>;/// A default configuration to map SAI2 FS_B on PG3 pin
using SAI2_FS_B_PG3 = AnyAltOut<Port::PG, 3, AfSAI2_FS_B_PG3>;/// A default configuration to map SAI2 MCLK_A on PG11 pin
using SAI2_MCLK_A_PG11 = AnyAltOut<Port::PG, 11, AfSAI2_MCLK_A_PG11>;/// A default configuration to map SAI2 MCLK_B on PG4 pin
using SAI2_MCLK_B_PG4 = AnyAltOut<Port::PG, 4, AfSAI2_MCLK_B_PG4>;/// A default configuration to map SAI2 SCK_A on PG9 pin
using SAI2_SCK_A_PG9 = AnyAltOut<Port::PG, 9, AfSAI2_SCK_A_PG9>;/// A default configuration to map SAI2 SCK_B on PG2 pin
using SAI2_SCK_B_PG2 = AnyAltOut<Port::PG, 2, AfSAI2_SCK_B_PG2>;/// A default configuration to map SAI2 SD_A on PG12 pin
using SAI2_SD_A_PG12 = AnyAltOut<Port::PG, 12, AfSAI2_SD_A_PG12>;/// A default configuration to map SAI2 SD_B on PG5 pin
using SAI2_SD_B_PG5 = AnyAltOut<Port::PG, 5, AfSAI2_SD_B_PG5>;#endif	// defined(GPIOG_BASE)
#endif	// defined(SAI2_BASE)

//////////////////////////////////////////////////////////////////////
// SDMMC1
//////////////////////////////////////////////////////////////////////
#if defined(SDMMC1_BASE)
/// A default configuration to map SDMMC1 CK on PC12 pin
using SDMMC1_CK_PC12 = AnyAltOut<Port::PC, 12, AfSDMMC1_CK_PC12>;/// A default configuration to map SDMMC1 D0 on PC8 pin
using SDMMC1_D0_PC8 = AnyAltOut<Port::PC, 8, AfSDMMC1_D0_PC8>;/// A default configuration to map SDMMC1 D1 on PC9 pin
using SDMMC1_D1_PC9 = AnyAltOut<Port::PC, 9, AfSDMMC1_D1_PC9>;/// A default configuration to map SDMMC1 D2 on PC10 pin
using SDMMC1_D2_PC10 = AnyAltOut<Port::PC, 10, AfSDMMC1_D2_PC10>;/// A default configuration to map SDMMC1 D3 on PC11 pin
using SDMMC1_D3_PC11 = AnyAltOut<Port::PC, 11, AfSDMMC1_D3_PC11>;/// A default configuration to map SDMMC1 D4 on PB8 pin
using SDMMC1_D4_PB8 = AnyAltOut<Port::PB, 8, AfSDMMC1_D4_PB8>;/// A default configuration to map SDMMC1 D5 on PB9 pin
using SDMMC1_D5_PB9 = AnyAltOut<Port::PB, 9, AfSDMMC1_D5_PB9>;/// A default configuration to map SDMMC1 D6 on PC6 pin
using SDMMC1_D6_PC6 = AnyAltOut<Port::PC, 6, AfSDMMC1_D6_PC6>;/// A default configuration to map SDMMC1 D7 on PC7 pin
using SDMMC1_D7_PC7 = AnyAltOut<Port::PC, 7, AfSDMMC1_D7_PC7>;#if defined(GPIOD_BASE)
/// A default configuration to map SDMMC1 CMD on PD2 pin
using SDMMC1_CMD_PD2 = AnyAltOut<Port::PD, 2, AfSDMMC1_CMD_PD2>;#endif	// defined(GPIOD_BASE)
#endif	// defined(SDMMC1_BASE)

//////////////////////////////////////////////////////////////////////
// SPI1
//////////////////////////////////////////////////////////////////////
#if defined(SPI1_BASE)
/// A default configuration to map SPI1 MISO on PA6 pin
using SPI1_MISO_PA6 = AnyAltOut<Port::PA, 6, AfSPI1_MISO_PA6>;/// A default configuration to map SPI1 MISO on PA11 pin
using SPI1_MISO_PA11 = AnyAltOut<Port::PA, 11, AfSPI1_MISO_PA11>;/// A default configuration to map SPI1 MISO on PB4 pin
using SPI1_MISO_PB4 = AnyAltOut<Port::PB, 4, AfSPI1_MISO_PB4>;/// A default configuration to map SPI1 MOSI on PA7 pin
using SPI1_MOSI_PA7 = AnyAltOut<Port::PA, 7, AfSPI1_MOSI_PA7>;/// A default configuration to map SPI1 MOSI on PA12 pin
using SPI1_MOSI_PA12 = AnyAltOut<Port::PA, 12, AfSPI1_MOSI_PA12>;/// A default configuration to map SPI1 MOSI on PB5 pin
using SPI1_MOSI_PB5 = AnyAltOut<Port::PB, 5, AfSPI1_MOSI_PB5>;/// A default configuration to map SPI1 NSS on PA4 pin
using SPI1_NSS_PA4 = AnyAltOut<Port::PA, 4, AfSPI1_NSS_PA4>;/// A default configuration to map SPI1 NSS on PA15 pin
using SPI1_NSS_PA15 = AnyAltOut<Port::PA, 15, AfSPI1_NSS_PA15>;/// A default configuration to map SPI1 NSS on PB0 pin
using SPI1_NSS_PB0 = AnyAltOut<Port::PB, 0, AfSPI1_NSS_PB0>;/// A default configuration to map SPI1 SCK on PA1 pin
using SPI1_SCK_PA1 = AnyAltOut<Port::PA, 1, AfSPI1_SCK_PA1>;/// A default configuration to map SPI1 SCK on PA5 pin
using SPI1_SCK_PA5 = AnyAltOut<Port::PA, 5, AfSPI1_SCK_PA5>;/// A default configuration to map SPI1 SCK on PB3 pin
using SPI1_SCK_PB3 = AnyAltOut<Port::PB, 3, AfSPI1_SCK_PB3>;#if defined(GPIOE_BASE)
/// A default configuration to map SPI1 MISO on PE14 pin
using SPI1_MISO_PE14 = AnyAltOut<Port::PE, 14, AfSPI1_MISO_PE14>;/// A default configuration to map SPI1 MOSI on PE15 pin
using SPI1_MOSI_PE15 = AnyAltOut<Port::PE, 15, AfSPI1_MOSI_PE15>;/// A default configuration to map SPI1 NSS on PE12 pin
using SPI1_NSS_PE12 = AnyAltOut<Port::PE, 12, AfSPI1_NSS_PE12>;/// A default configuration to map SPI1 SCK on PE13 pin
using SPI1_SCK_PE13 = AnyAltOut<Port::PE, 13, AfSPI1_SCK_PE13>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map SPI1 MISO on PG3 pin
using SPI1_MISO_PG3 = AnyAltOut<Port::PG, 3, AfSPI1_MISO_PG3>;/// A default configuration to map SPI1 MOSI on PG4 pin
using SPI1_MOSI_PG4 = AnyAltOut<Port::PG, 4, AfSPI1_MOSI_PG4>;/// A default configuration to map SPI1 NSS on PG5 pin
using SPI1_NSS_PG5 = AnyAltOut<Port::PG, 5, AfSPI1_NSS_PG5>;/// A default configuration to map SPI1 SCK on PG2 pin
using SPI1_SCK_PG2 = AnyAltOut<Port::PG, 2, AfSPI1_SCK_PG2>;#endif	// defined(GPIOG_BASE)
#endif	// defined(SPI1_BASE)

//////////////////////////////////////////////////////////////////////
// SPI2
//////////////////////////////////////////////////////////////////////
#if defined(SPI2_BASE)
/// A default configuration to map SPI2 MISO on PB14 pin
using SPI2_MISO_PB14 = AnyAltOut<Port::PB, 14, AfSPI2_MISO_PB14>;/// A default configuration to map SPI2 MISO on PC2 pin
using SPI2_MISO_PC2 = AnyAltOut<Port::PC, 2, AfSPI2_MISO_PC2>;/// A default configuration to map SPI2 MOSI on PB15 pin
using SPI2_MOSI_PB15 = AnyAltOut<Port::PB, 15, AfSPI2_MOSI_PB15>;/// A default configuration to map SPI2 MOSI on PC1 pin
using SPI2_MOSI_PC1 = AnyAltOut<Port::PC, 1, AfSPI2_MOSI_PC1>;/// A default configuration to map SPI2 MOSI on PC3 pin
using SPI2_MOSI_PC3 = AnyAltOut<Port::PC, 3, AfSPI2_MOSI_PC3>;/// A default configuration to map SPI2 NSS on PB9 pin
using SPI2_NSS_PB9 = AnyAltOut<Port::PB, 9, AfSPI2_NSS_PB9>;/// A default configuration to map SPI2 NSS on PB12 pin
using SPI2_NSS_PB12 = AnyAltOut<Port::PB, 12, AfSPI2_NSS_PB12>;/// A default configuration to map SPI2 SCK on PA9 pin
using SPI2_SCK_PA9 = AnyAltOut<Port::PA, 9, AfSPI2_SCK_PA9>;/// A default configuration to map SPI2 SCK on PB10 pin
using SPI2_SCK_PB10 = AnyAltOut<Port::PB, 10, AfSPI2_SCK_PB10>;/// A default configuration to map SPI2 SCK on PB13 pin
using SPI2_SCK_PB13 = AnyAltOut<Port::PB, 13, AfSPI2_SCK_PB13>;#if defined(GPIOD_BASE)
/// A default configuration to map SPI2 MISO on PD3 pin
using SPI2_MISO_PD3 = AnyAltOut<Port::PD, 3, AfSPI2_MISO_PD3>;/// A default configuration to map SPI2 MOSI on PD4 pin
using SPI2_MOSI_PD4 = AnyAltOut<Port::PD, 4, AfSPI2_MOSI_PD4>;/// A default configuration to map SPI2 NSS on PD0 pin
using SPI2_NSS_PD0 = AnyAltOut<Port::PD, 0, AfSPI2_NSS_PD0>;/// A default configuration to map SPI2 SCK on PD1 pin
using SPI2_SCK_PD1 = AnyAltOut<Port::PD, 1, AfSPI2_SCK_PD1>;/// A default configuration to map SPI2 SCK on PD3 pin
using SPI2_SCK_PD3 = AnyAltOut<Port::PD, 3, AfSPI2_SCK_PD3>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOI_BASE)
/// A default configuration to map SPI2 MISO on PI2 pin
using SPI2_MISO_PI2 = AnyAltOut<Port::PI, 2, AfSPI2_MISO_PI2>;/// A default configuration to map SPI2 MOSI on PI3 pin
using SPI2_MOSI_PI3 = AnyAltOut<Port::PI, 3, AfSPI2_MOSI_PI3>;/// A default configuration to map SPI2 NSS on PI0 pin
using SPI2_NSS_PI0 = AnyAltOut<Port::PI, 0, AfSPI2_NSS_PI0>;/// A default configuration to map SPI2 SCK on PI1 pin
using SPI2_SCK_PI1 = AnyAltOut<Port::PI, 1, AfSPI2_SCK_PI1>;#endif	// defined(GPIOI_BASE)
#endif	// defined(SPI2_BASE)

//////////////////////////////////////////////////////////////////////
// SPI3
//////////////////////////////////////////////////////////////////////
#if defined(SPI3_BASE)
/// A default configuration to map SPI3 MISO on PB4 pin
using SPI3_MISO_PB4 = AnyAltOut<Port::PB, 4, AfSPI3_MISO_PB4>;/// A default configuration to map SPI3 MISO on PC11 pin
using SPI3_MISO_PC11 = AnyAltOut<Port::PC, 11, AfSPI3_MISO_PC11>;/// A default configuration to map SPI3 MOSI on PB5 pin
using SPI3_MOSI_PB5 = AnyAltOut<Port::PB, 5, AfSPI3_MOSI_PB5>;/// A default configuration to map SPI3 MOSI on PC12 pin
using SPI3_MOSI_PC12 = AnyAltOut<Port::PC, 12, AfSPI3_MOSI_PC12>;/// A default configuration to map SPI3 NSS on PA4 pin
using SPI3_NSS_PA4 = AnyAltOut<Port::PA, 4, AfSPI3_NSS_PA4>;/// A default configuration to map SPI3 NSS on PA15 pin
using SPI3_NSS_PA15 = AnyAltOut<Port::PA, 15, AfSPI3_NSS_PA15>;/// A default configuration to map SPI3 SCK on PB3 pin
using SPI3_SCK_PB3 = AnyAltOut<Port::PB, 3, AfSPI3_SCK_PB3>;/// A default configuration to map SPI3 SCK on PC10 pin
using SPI3_SCK_PC10 = AnyAltOut<Port::PC, 10, AfSPI3_SCK_PC10>;#if defined(GPIOG_BASE)
/// A default configuration to map SPI3 MISO on PG10 pin
using SPI3_MISO_PG10 = AnyAltOut<Port::PG, 10, AfSPI3_MISO_PG10>;/// A default configuration to map SPI3 MOSI on PG11 pin
using SPI3_MOSI_PG11 = AnyAltOut<Port::PG, 11, AfSPI3_MOSI_PG11>;/// A default configuration to map SPI3 NSS on PG12 pin
using SPI3_NSS_PG12 = AnyAltOut<Port::PG, 12, AfSPI3_NSS_PG12>;/// A default configuration to map SPI3 SCK on PG9 pin
using SPI3_SCK_PG9 = AnyAltOut<Port::PG, 9, AfSPI3_SCK_PG9>;#endif	// defined(GPIOG_BASE)
#endif	// defined(SPI3_BASE)

//////////////////////////////////////////////////////////////////////
// SWPMI1
//////////////////////////////////////////////////////////////////////
#if defined(SWPMI1_BASE)
/// A default configuration to map SWPMI1 IO on PA8 pin
using SWPMI1_IO_PA8 = AnyAltOut<Port::PA, 8, AfSWPMI1_IO_PA8>;/// A default configuration to map SWPMI1 IO on PB12 pin
using SWPMI1_IO_PB12 = AnyAltOut<Port::PB, 12, AfSWPMI1_IO_PB12>;/// A default configuration to map SWPMI1 RX on PA14 pin
using SWPMI1_RX_PA14 = AnyAltOut<Port::PA, 14, AfSWPMI1_RX_PA14>;/// A default configuration to map SWPMI1 RX on PB14 pin
using SWPMI1_RX_PB14 = AnyAltOut<Port::PB, 14, AfSWPMI1_RX_PB14>;/// A default configuration to map SWPMI1 SUSPEND on PA15 pin
using SWPMI1_SUSPEND_PA15 = AnyAltOut<Port::PA, 15, AfSWPMI1_SUSPEND_PA15>;/// A default configuration to map SWPMI1 SUSPEND on PB15 pin
using SWPMI1_SUSPEND_PB15 = AnyAltOut<Port::PB, 15, AfSWPMI1_SUSPEND_PB15>;/// A default configuration to map SWPMI1 TX on PA13 pin
using SWPMI1_TX_PA13 = AnyAltOut<Port::PA, 13, AfSWPMI1_TX_PA13>;/// A default configuration to map SWPMI1 TX on PB13 pin
using SWPMI1_TX_PB13 = AnyAltOut<Port::PB, 13, AfSWPMI1_TX_PB13>;#endif	// defined(SWPMI1_BASE)

//////////////////////////////////////////////////////////////////////
// TIM1
//////////////////////////////////////////////////////////////////////
#if defined(TIM1_BASE)
/// A default configuration to map TIM1 BKIN on PA6 pin
using TIM1_BKIN_PA6 = AnyAltOut<Port::PA, 6, AfTIM1_BKIN_PA6>;/// A default configuration to map TIM1 BKIN on PB12 pin
using TIM1_BKIN_PB12 = AnyAltOut<Port::PB, 12, AfTIM1_BKIN_PB12>;/// A default configuration to map TIM1 BKIN2 on PA11 pin
using TIM1_BKIN2_PA11 = AnyAltOut<Port::PA, 11, AfTIM1_BKIN2_PA11>;/// A default configuration to map TIM1 BKIN2_COMP1 on PA11 pin
using TIM1_BKIN2_COMP1_PA11 = AnyAltOut<Port::PA, 11, AfTIM1_BKIN2_COMP1_PA11>;/// A default configuration to map TIM1 BKIN_COMP2 on PA6 pin
using TIM1_BKIN_COMP2_PA6 = AnyAltOut<Port::PA, 6, AfTIM1_BKIN_COMP2_PA6>;/// A default configuration to map TIM1 BKIN_COMP2 on PB12 pin
using TIM1_BKIN_COMP2_PB12 = AnyAltOut<Port::PB, 12, AfTIM1_BKIN_COMP2_PB12>;/// A default configuration to map TIM1 CH1 on PA8 pin
using TIM1_CH1_PA8 = AnyAltOut<Port::PA, 8, AfTIM1_CH1_PA8>;/// A default configuration to map TIM1 CH1N on PA7 pin
using TIM1_CH1N_PA7 = AnyAltOut<Port::PA, 7, AfTIM1_CH1N_PA7>;/// A default configuration to map TIM1 CH1N on PB13 pin
using TIM1_CH1N_PB13 = AnyAltOut<Port::PB, 13, AfTIM1_CH1N_PB13>;/// A default configuration to map TIM1 CH2 on PA9 pin
using TIM1_CH2_PA9 = AnyAltOut<Port::PA, 9, AfTIM1_CH2_PA9>;/// A default configuration to map TIM1 CH2N on PB0 pin
using TIM1_CH2N_PB0 = AnyAltOut<Port::PB, 0, AfTIM1_CH2N_PB0>;/// A default configuration to map TIM1 CH2N on PB14 pin
using TIM1_CH2N_PB14 = AnyAltOut<Port::PB, 14, AfTIM1_CH2N_PB14>;/// A default configuration to map TIM1 CH3 on PA10 pin
using TIM1_CH3_PA10 = AnyAltOut<Port::PA, 10, AfTIM1_CH3_PA10>;/// A default configuration to map TIM1 CH3N on PB1 pin
using TIM1_CH3N_PB1 = AnyAltOut<Port::PB, 1, AfTIM1_CH3N_PB1>;/// A default configuration to map TIM1 CH3N on PB15 pin
using TIM1_CH3N_PB15 = AnyAltOut<Port::PB, 15, AfTIM1_CH3N_PB15>;/// A default configuration to map TIM1 CH4 on PA11 pin
using TIM1_CH4_PA11 = AnyAltOut<Port::PA, 11, AfTIM1_CH4_PA11>;/// A default configuration to map TIM1 ETR on PA12 pin
using TIM1_ETR_PA12 = AnyAltOut<Port::PA, 12, AfTIM1_ETR_PA12>;#if defined(GPIOE_BASE)
/// A default configuration to map TIM1 BKIN on PE15 pin
using TIM1_BKIN_PE15 = AnyAltOut<Port::PE, 15, AfTIM1_BKIN_PE15>;/// A default configuration to map TIM1 BKIN2 on PE14 pin
using TIM1_BKIN2_PE14 = AnyAltOut<Port::PE, 14, AfTIM1_BKIN2_PE14>;/// A default configuration to map TIM1 BKIN2_COMP2 on PE14 pin
using TIM1_BKIN2_COMP2_PE14 = AnyAltOut<Port::PE, 14, AfTIM1_BKIN2_COMP2_PE14>;/// A default configuration to map TIM1 BKIN_COMP1 on PE15 pin
using TIM1_BKIN_COMP1_PE15 = AnyAltOut<Port::PE, 15, AfTIM1_BKIN_COMP1_PE15>;/// A default configuration to map TIM1 CH1 on PE9 pin
using TIM1_CH1_PE9 = AnyAltOut<Port::PE, 9, AfTIM1_CH1_PE9>;/// A default configuration to map TIM1 CH1N on PE8 pin
using TIM1_CH1N_PE8 = AnyAltOut<Port::PE, 8, AfTIM1_CH1N_PE8>;/// A default configuration to map TIM1 CH2 on PE11 pin
using TIM1_CH2_PE11 = AnyAltOut<Port::PE, 11, AfTIM1_CH2_PE11>;/// A default configuration to map TIM1 CH2N on PE10 pin
using TIM1_CH2N_PE10 = AnyAltOut<Port::PE, 10, AfTIM1_CH2N_PE10>;/// A default configuration to map TIM1 CH3 on PE13 pin
using TIM1_CH3_PE13 = AnyAltOut<Port::PE, 13, AfTIM1_CH3_PE13>;/// A default configuration to map TIM1 CH3N on PE12 pin
using TIM1_CH3N_PE12 = AnyAltOut<Port::PE, 12, AfTIM1_CH3N_PE12>;/// A default configuration to map TIM1 CH4 on PE14 pin
using TIM1_CH4_PE14 = AnyAltOut<Port::PE, 14, AfTIM1_CH4_PE14>;/// A default configuration to map TIM1 ETR on PE7 pin
using TIM1_ETR_PE7 = AnyAltOut<Port::PE, 7, AfTIM1_ETR_PE7>;#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM1_BASE)

//////////////////////////////////////////////////////////////////////
// TIM2
//////////////////////////////////////////////////////////////////////
#if defined(TIM2_BASE)
/// A default configuration to map TIM2 CH1 on PA0 pin
using TIM2_CH1_PA0 = AnyAltOut<Port::PA, 0, AfTIM2_CH1_PA0>;/// A default configuration to map TIM2 CH1 on PA5 pin
using TIM2_CH1_PA5 = AnyAltOut<Port::PA, 5, AfTIM2_CH1_PA5>;/// A default configuration to map TIM2 CH1 on PA15 pin
using TIM2_CH1_PA15 = AnyAltOut<Port::PA, 15, AfTIM2_CH1_PA15>;/// A default configuration to map TIM2 CH2 on PA1 pin
using TIM2_CH2_PA1 = AnyAltOut<Port::PA, 1, AfTIM2_CH2_PA1>;/// A default configuration to map TIM2 CH2 on PB3 pin
using TIM2_CH2_PB3 = AnyAltOut<Port::PB, 3, AfTIM2_CH2_PB3>;/// A default configuration to map TIM2 CH3 on PA2 pin
using TIM2_CH3_PA2 = AnyAltOut<Port::PA, 2, AfTIM2_CH3_PA2>;/// A default configuration to map TIM2 CH3 on PB10 pin
using TIM2_CH3_PB10 = AnyAltOut<Port::PB, 10, AfTIM2_CH3_PB10>;/// A default configuration to map TIM2 CH4 on PA3 pin
using TIM2_CH4_PA3 = AnyAltOut<Port::PA, 3, AfTIM2_CH4_PA3>;/// A default configuration to map TIM2 CH4 on PB11 pin
using TIM2_CH4_PB11 = AnyAltOut<Port::PB, 11, AfTIM2_CH4_PB11>;/// A default configuration to map TIM2 ETR on PA0 pin
using TIM2_ETR_PA0 = AnyAltOut<Port::PA, 0, AfTIM2_ETR_PA0>;/// A default configuration to map TIM2 ETR on PA5 pin
using TIM2_ETR_PA5 = AnyAltOut<Port::PA, 5, AfTIM2_ETR_PA5>;/// A default configuration to map TIM2 ETR on PA15 pin
using TIM2_ETR_PA15 = AnyAltOut<Port::PA, 15, AfTIM2_ETR_PA15>;#endif	// defined(TIM2_BASE)

//////////////////////////////////////////////////////////////////////
// TIM3
//////////////////////////////////////////////////////////////////////
#if defined(TIM3_BASE)
/// A default configuration to map TIM3 CH1 on PA6 pin
using TIM3_CH1_PA6 = AnyAltOut<Port::PA, 6, AfTIM3_CH1_PA6>;/// A default configuration to map TIM3 CH1 on PB4 pin
using TIM3_CH1_PB4 = AnyAltOut<Port::PB, 4, AfTIM3_CH1_PB4>;/// A default configuration to map TIM3 CH1 on PC6 pin
using TIM3_CH1_PC6 = AnyAltOut<Port::PC, 6, AfTIM3_CH1_PC6>;/// A default configuration to map TIM3 CH2 on PA7 pin
using TIM3_CH2_PA7 = AnyAltOut<Port::PA, 7, AfTIM3_CH2_PA7>;/// A default configuration to map TIM3 CH2 on PB5 pin
using TIM3_CH2_PB5 = AnyAltOut<Port::PB, 5, AfTIM3_CH2_PB5>;/// A default configuration to map TIM3 CH2 on PC7 pin
using TIM3_CH2_PC7 = AnyAltOut<Port::PC, 7, AfTIM3_CH2_PC7>;/// A default configuration to map TIM3 CH3 on PB0 pin
using TIM3_CH3_PB0 = AnyAltOut<Port::PB, 0, AfTIM3_CH3_PB0>;/// A default configuration to map TIM3 CH3 on PC8 pin
using TIM3_CH3_PC8 = AnyAltOut<Port::PC, 8, AfTIM3_CH3_PC8>;/// A default configuration to map TIM3 CH4 on PB1 pin
using TIM3_CH4_PB1 = AnyAltOut<Port::PB, 1, AfTIM3_CH4_PB1>;/// A default configuration to map TIM3 CH4 on PC9 pin
using TIM3_CH4_PC9 = AnyAltOut<Port::PC, 9, AfTIM3_CH4_PC9>;#if defined(GPIOD_BASE)
/// A default configuration to map TIM3 ETR on PD2 pin
using TIM3_ETR_PD2 = AnyAltOut<Port::PD, 2, AfTIM3_ETR_PD2>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map TIM3 CH1 on PE3 pin
using TIM3_CH1_PE3 = AnyAltOut<Port::PE, 3, AfTIM3_CH1_PE3>;/// A default configuration to map TIM3 CH2 on PE4 pin
using TIM3_CH2_PE4 = AnyAltOut<Port::PE, 4, AfTIM3_CH2_PE4>;/// A default configuration to map TIM3 CH3 on PE5 pin
using TIM3_CH3_PE5 = AnyAltOut<Port::PE, 5, AfTIM3_CH3_PE5>;/// A default configuration to map TIM3 CH4 on PE6 pin
using TIM3_CH4_PE6 = AnyAltOut<Port::PE, 6, AfTIM3_CH4_PE6>;/// A default configuration to map TIM3 ETR on PE2 pin
using TIM3_ETR_PE2 = AnyAltOut<Port::PE, 2, AfTIM3_ETR_PE2>;#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM3_BASE)

//////////////////////////////////////////////////////////////////////
// TIM4
//////////////////////////////////////////////////////////////////////
#if defined(TIM4_BASE)
/// A default configuration to map TIM4 CH1 on PB6 pin
using TIM4_CH1_PB6 = AnyAltOut<Port::PB, 6, AfTIM4_CH1_PB6>;/// A default configuration to map TIM4 CH2 on PB7 pin
using TIM4_CH2_PB7 = AnyAltOut<Port::PB, 7, AfTIM4_CH2_PB7>;/// A default configuration to map TIM4 CH3 on PB8 pin
using TIM4_CH3_PB8 = AnyAltOut<Port::PB, 8, AfTIM4_CH3_PB8>;/// A default configuration to map TIM4 CH4 on PB9 pin
using TIM4_CH4_PB9 = AnyAltOut<Port::PB, 9, AfTIM4_CH4_PB9>;#if defined(GPIOD_BASE)
/// A default configuration to map TIM4 CH1 on PD12 pin
using TIM4_CH1_PD12 = AnyAltOut<Port::PD, 12, AfTIM4_CH1_PD12>;/// A default configuration to map TIM4 CH2 on PD13 pin
using TIM4_CH2_PD13 = AnyAltOut<Port::PD, 13, AfTIM4_CH2_PD13>;/// A default configuration to map TIM4 CH3 on PD14 pin
using TIM4_CH3_PD14 = AnyAltOut<Port::PD, 14, AfTIM4_CH3_PD14>;/// A default configuration to map TIM4 CH4 on PD15 pin
using TIM4_CH4_PD15 = AnyAltOut<Port::PD, 15, AfTIM4_CH4_PD15>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map TIM4 ETR on PE0 pin
using TIM4_ETR_PE0 = AnyAltOut<Port::PE, 0, AfTIM4_ETR_PE0>;#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM4_BASE)

//////////////////////////////////////////////////////////////////////
// TIM5
//////////////////////////////////////////////////////////////////////
#if defined(TIM5_BASE)
/// A default configuration to map TIM5 CH1 on PA0 pin
using TIM5_CH1_PA0 = AnyAltOut<Port::PA, 0, AfTIM5_CH1_PA0>;/// A default configuration to map TIM5 CH2 on PA1 pin
using TIM5_CH2_PA1 = AnyAltOut<Port::PA, 1, AfTIM5_CH2_PA1>;/// A default configuration to map TIM5 CH3 on PA2 pin
using TIM5_CH3_PA2 = AnyAltOut<Port::PA, 2, AfTIM5_CH3_PA2>;/// A default configuration to map TIM5 CH4 on PA3 pin
using TIM5_CH4_PA3 = AnyAltOut<Port::PA, 3, AfTIM5_CH4_PA3>;#if defined(GPIOF_BASE)
/// A default configuration to map TIM5 CH1 on PF6 pin
using TIM5_CH1_PF6 = AnyAltOut<Port::PF, 6, AfTIM5_CH1_PF6>;/// A default configuration to map TIM5 CH2 on PF7 pin
using TIM5_CH2_PF7 = AnyAltOut<Port::PF, 7, AfTIM5_CH2_PF7>;/// A default configuration to map TIM5 CH3 on PF8 pin
using TIM5_CH3_PF8 = AnyAltOut<Port::PF, 8, AfTIM5_CH3_PF8>;/// A default configuration to map TIM5 CH4 on PF9 pin
using TIM5_CH4_PF9 = AnyAltOut<Port::PF, 9, AfTIM5_CH4_PF9>;/// A default configuration to map TIM5 ETR on PF6 pin
using TIM5_ETR_PF6 = AnyAltOut<Port::PF, 6, AfTIM5_ETR_PF6>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOH_BASE)
/// A default configuration to map TIM5 CH1 on PH10 pin
using TIM5_CH1_PH10 = AnyAltOut<Port::PH, 10, AfTIM5_CH1_PH10>;/// A default configuration to map TIM5 CH2 on PH11 pin
using TIM5_CH2_PH11 = AnyAltOut<Port::PH, 11, AfTIM5_CH2_PH11>;/// A default configuration to map TIM5 CH3 on PH12 pin
using TIM5_CH3_PH12 = AnyAltOut<Port::PH, 12, AfTIM5_CH3_PH12>;#endif	// defined(GPIOH_BASE)
#if defined(GPIOI_BASE)
/// A default configuration to map TIM5 CH4 on PI0 pin
using TIM5_CH4_PI0 = AnyAltOut<Port::PI, 0, AfTIM5_CH4_PI0>;#endif	// defined(GPIOI_BASE)
#endif	// defined(TIM5_BASE)

//////////////////////////////////////////////////////////////////////
// TIM8
//////////////////////////////////////////////////////////////////////
#if defined(TIM8_BASE)
/// A default configuration to map TIM8 BKIN on PA6 pin
using TIM8_BKIN_PA6 = AnyAltOut<Port::PA, 6, AfTIM8_BKIN_PA6>;/// A default configuration to map TIM8 BKIN on PB7 pin
using TIM8_BKIN_PB7 = AnyAltOut<Port::PB, 7, AfTIM8_BKIN_PB7>;/// A default configuration to map TIM8 BKIN2 on PB6 pin
using TIM8_BKIN2_PB6 = AnyAltOut<Port::PB, 6, AfTIM8_BKIN2_PB6>;/// A default configuration to map TIM8 BKIN2 on PC9 pin
using TIM8_BKIN2_PC9 = AnyAltOut<Port::PC, 9, AfTIM8_BKIN2_PC9>;/// A default configuration to map TIM8 BKIN2_COMP1 on PC9 pin
using TIM8_BKIN2_COMP1_PC9 = AnyAltOut<Port::PC, 9, AfTIM8_BKIN2_COMP1_PC9>;/// A default configuration to map TIM8 BKIN2_COMP2 on PB6 pin
using TIM8_BKIN2_COMP2_PB6 = AnyAltOut<Port::PB, 6, AfTIM8_BKIN2_COMP2_PB6>;/// A default configuration to map TIM8 BKIN_COMP1 on PB7 pin
using TIM8_BKIN_COMP1_PB7 = AnyAltOut<Port::PB, 7, AfTIM8_BKIN_COMP1_PB7>;/// A default configuration to map TIM8 BKIN_COMP2 on PA6 pin
using TIM8_BKIN_COMP2_PA6 = AnyAltOut<Port::PA, 6, AfTIM8_BKIN_COMP2_PA6>;/// A default configuration to map TIM8 CH1 on PC6 pin
using TIM8_CH1_PC6 = AnyAltOut<Port::PC, 6, AfTIM8_CH1_PC6>;/// A default configuration to map TIM8 CH1N on PA5 pin
using TIM8_CH1N_PA5 = AnyAltOut<Port::PA, 5, AfTIM8_CH1N_PA5>;/// A default configuration to map TIM8 CH1N on PA7 pin
using TIM8_CH1N_PA7 = AnyAltOut<Port::PA, 7, AfTIM8_CH1N_PA7>;/// A default configuration to map TIM8 CH2 on PC7 pin
using TIM8_CH2_PC7 = AnyAltOut<Port::PC, 7, AfTIM8_CH2_PC7>;/// A default configuration to map TIM8 CH2N on PB0 pin
using TIM8_CH2N_PB0 = AnyAltOut<Port::PB, 0, AfTIM8_CH2N_PB0>;/// A default configuration to map TIM8 CH2N on PB14 pin
using TIM8_CH2N_PB14 = AnyAltOut<Port::PB, 14, AfTIM8_CH2N_PB14>;/// A default configuration to map TIM8 CH3 on PC8 pin
using TIM8_CH3_PC8 = AnyAltOut<Port::PC, 8, AfTIM8_CH3_PC8>;/// A default configuration to map TIM8 CH3N on PB1 pin
using TIM8_CH3N_PB1 = AnyAltOut<Port::PB, 1, AfTIM8_CH3N_PB1>;/// A default configuration to map TIM8 CH3N on PB15 pin
using TIM8_CH3N_PB15 = AnyAltOut<Port::PB, 15, AfTIM8_CH3N_PB15>;/// A default configuration to map TIM8 CH4 on PC9 pin
using TIM8_CH4_PC9 = AnyAltOut<Port::PC, 9, AfTIM8_CH4_PC9>;/// A default configuration to map TIM8 ETR on PA0 pin
using TIM8_ETR_PA0 = AnyAltOut<Port::PA, 0, AfTIM8_ETR_PA0>;#if defined(GPIOH_BASE)
/// A default configuration to map TIM8 CH1N on PH13 pin
using TIM8_CH1N_PH13 = AnyAltOut<Port::PH, 13, AfTIM8_CH1N_PH13>;/// A default configuration to map TIM8 CH2N on PH14 pin
using TIM8_CH2N_PH14 = AnyAltOut<Port::PH, 14, AfTIM8_CH2N_PH14>;/// A default configuration to map TIM8 CH3N on PH15 pin
using TIM8_CH3N_PH15 = AnyAltOut<Port::PH, 15, AfTIM8_CH3N_PH15>;#endif	// defined(GPIOH_BASE)
#if defined(GPIOI_BASE)
/// A default configuration to map TIM8 BKIN on PI4 pin
using TIM8_BKIN_PI4 = AnyAltOut<Port::PI, 4, AfTIM8_BKIN_PI4>;/// A default configuration to map TIM8 CH1 on PI5 pin
using TIM8_CH1_PI5 = AnyAltOut<Port::PI, 5, AfTIM8_CH1_PI5>;/// A default configuration to map TIM8 CH2 on PI6 pin
using TIM8_CH2_PI6 = AnyAltOut<Port::PI, 6, AfTIM8_CH2_PI6>;/// A default configuration to map TIM8 CH3 on PI7 pin
using TIM8_CH3_PI7 = AnyAltOut<Port::PI, 7, AfTIM8_CH3_PI7>;/// A default configuration to map TIM8 CH4 on PI2 pin
using TIM8_CH4_PI2 = AnyAltOut<Port::PI, 2, AfTIM8_CH4_PI2>;/// A default configuration to map TIM8 ETR on PI3 pin
using TIM8_ETR_PI3 = AnyAltOut<Port::PI, 3, AfTIM8_ETR_PI3>;#endif	// defined(GPIOI_BASE)
#endif	// defined(TIM8_BASE)

//////////////////////////////////////////////////////////////////////
// TIM15
//////////////////////////////////////////////////////////////////////
#if defined(TIM15_BASE)
/// A default configuration to map TIM15 BKIN on PA9 pin
using TIM15_BKIN_PA9 = AnyAltOut<Port::PA, 9, AfTIM15_BKIN_PA9>;/// A default configuration to map TIM15 BKIN on PB12 pin
using TIM15_BKIN_PB12 = AnyAltOut<Port::PB, 12, AfTIM15_BKIN_PB12>;/// A default configuration to map TIM15 CH1 on PA2 pin
using TIM15_CH1_PA2 = AnyAltOut<Port::PA, 2, AfTIM15_CH1_PA2>;/// A default configuration to map TIM15 CH1 on PB14 pin
using TIM15_CH1_PB14 = AnyAltOut<Port::PB, 14, AfTIM15_CH1_PB14>;/// A default configuration to map TIM15 CH1N on PA1 pin
using TIM15_CH1N_PA1 = AnyAltOut<Port::PA, 1, AfTIM15_CH1N_PA1>;/// A default configuration to map TIM15 CH1N on PB13 pin
using TIM15_CH1N_PB13 = AnyAltOut<Port::PB, 13, AfTIM15_CH1N_PB13>;/// A default configuration to map TIM15 CH2 on PA3 pin
using TIM15_CH2_PA3 = AnyAltOut<Port::PA, 3, AfTIM15_CH2_PA3>;/// A default configuration to map TIM15 CH2 on PB15 pin
using TIM15_CH2_PB15 = AnyAltOut<Port::PB, 15, AfTIM15_CH2_PB15>;#if defined(GPIOF_BASE)
/// A default configuration to map TIM15 CH1 on PF9 pin
using TIM15_CH1_PF9 = AnyAltOut<Port::PF, 9, AfTIM15_CH1_PF9>;/// A default configuration to map TIM15 CH2 on PF10 pin
using TIM15_CH2_PF10 = AnyAltOut<Port::PF, 10, AfTIM15_CH2_PF10>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map TIM15 CH1 on PG10 pin
using TIM15_CH1_PG10 = AnyAltOut<Port::PG, 10, AfTIM15_CH1_PG10>;/// A default configuration to map TIM15 CH1N on PG9 pin
using TIM15_CH1N_PG9 = AnyAltOut<Port::PG, 9, AfTIM15_CH1N_PG9>;/// A default configuration to map TIM15 CH2 on PG11 pin
using TIM15_CH2_PG11 = AnyAltOut<Port::PG, 11, AfTIM15_CH2_PG11>;#endif	// defined(GPIOG_BASE)
#endif	// defined(TIM15_BASE)

//////////////////////////////////////////////////////////////////////
// TIM16
//////////////////////////////////////////////////////////////////////
#if defined(TIM16_BASE)
/// A default configuration to map TIM16 BKIN on PB5 pin
using TIM16_BKIN_PB5 = AnyAltOut<Port::PB, 5, AfTIM16_BKIN_PB5>;/// A default configuration to map TIM16 CH1 on PA6 pin
using TIM16_CH1_PA6 = AnyAltOut<Port::PA, 6, AfTIM16_CH1_PA6>;/// A default configuration to map TIM16 CH1 on PB8 pin
using TIM16_CH1_PB8 = AnyAltOut<Port::PB, 8, AfTIM16_CH1_PB8>;/// A default configuration to map TIM16 CH1N on PB6 pin
using TIM16_CH1N_PB6 = AnyAltOut<Port::PB, 6, AfTIM16_CH1N_PB6>;#if defined(GPIOE_BASE)
/// A default configuration to map TIM16 CH1 on PE0 pin
using TIM16_CH1_PE0 = AnyAltOut<Port::PE, 0, AfTIM16_CH1_PE0>;#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM16_BASE)

//////////////////////////////////////////////////////////////////////
// TIM17
//////////////////////////////////////////////////////////////////////
#if defined(TIM17_BASE)
/// A default configuration to map TIM17 BKIN on PA10 pin
using TIM17_BKIN_PA10 = AnyAltOut<Port::PA, 10, AfTIM17_BKIN_PA10>;/// A default configuration to map TIM17 BKIN on PB4 pin
using TIM17_BKIN_PB4 = AnyAltOut<Port::PB, 4, AfTIM17_BKIN_PB4>;/// A default configuration to map TIM17 CH1 on PA7 pin
using TIM17_CH1_PA7 = AnyAltOut<Port::PA, 7, AfTIM17_CH1_PA7>;/// A default configuration to map TIM17 CH1 on PB9 pin
using TIM17_CH1_PB9 = AnyAltOut<Port::PB, 9, AfTIM17_CH1_PB9>;/// A default configuration to map TIM17 CH1N on PB7 pin
using TIM17_CH1N_PB7 = AnyAltOut<Port::PB, 7, AfTIM17_CH1N_PB7>;#if defined(GPIOE_BASE)
/// A default configuration to map TIM17 CH1 on PE1 pin
using TIM17_CH1_PE1 = AnyAltOut<Port::PE, 1, AfTIM17_CH1_PE1>;#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM17_BASE)

//////////////////////////////////////////////////////////////////////
// TSC
//////////////////////////////////////////////////////////////////////
#if defined(TSC_BASE)
/// A default configuration to map TSC G1_IO1 on PB12 pin
using TSC_G1_IO1_PB12 = AnyAltOut<Port::PB, 12, AfTSC_G1_IO1_PB12>;/// A default configuration to map TSC G1_IO2 on PB13 pin
using TSC_G1_IO2_PB13 = AnyAltOut<Port::PB, 13, AfTSC_G1_IO2_PB13>;/// A default configuration to map TSC G1_IO3 on PB14 pin
using TSC_G1_IO3_PB14 = AnyAltOut<Port::PB, 14, AfTSC_G1_IO3_PB14>;/// A default configuration to map TSC G1_IO4 on PB15 pin
using TSC_G1_IO4_PB15 = AnyAltOut<Port::PB, 15, AfTSC_G1_IO4_PB15>;/// A default configuration to map TSC G2_IO1 on PB4 pin
using TSC_G2_IO1_PB4 = AnyAltOut<Port::PB, 4, AfTSC_G2_IO1_PB4>;/// A default configuration to map TSC G2_IO2 on PB5 pin
using TSC_G2_IO2_PB5 = AnyAltOut<Port::PB, 5, AfTSC_G2_IO2_PB5>;/// A default configuration to map TSC G2_IO3 on PB6 pin
using TSC_G2_IO3_PB6 = AnyAltOut<Port::PB, 6, AfTSC_G2_IO3_PB6>;/// A default configuration to map TSC G2_IO4 on PB7 pin
using TSC_G2_IO4_PB7 = AnyAltOut<Port::PB, 7, AfTSC_G2_IO4_PB7>;/// A default configuration to map TSC G3_IO1 on PA15 pin
using TSC_G3_IO1_PA15 = AnyAltOut<Port::PA, 15, AfTSC_G3_IO1_PA15>;/// A default configuration to map TSC G3_IO2 on PC10 pin
using TSC_G3_IO2_PC10 = AnyAltOut<Port::PC, 10, AfTSC_G3_IO2_PC10>;/// A default configuration to map TSC G3_IO3 on PC11 pin
using TSC_G3_IO3_PC11 = AnyAltOut<Port::PC, 11, AfTSC_G3_IO3_PC11>;/// A default configuration to map TSC G3_IO4 on PC12 pin
using TSC_G3_IO4_PC12 = AnyAltOut<Port::PC, 12, AfTSC_G3_IO4_PC12>;/// A default configuration to map TSC G4_IO1 on PC6 pin
using TSC_G4_IO1_PC6 = AnyAltOut<Port::PC, 6, AfTSC_G4_IO1_PC6>;/// A default configuration to map TSC G4_IO2 on PC7 pin
using TSC_G4_IO2_PC7 = AnyAltOut<Port::PC, 7, AfTSC_G4_IO2_PC7>;/// A default configuration to map TSC G4_IO3 on PC8 pin
using TSC_G4_IO3_PC8 = AnyAltOut<Port::PC, 8, AfTSC_G4_IO3_PC8>;/// A default configuration to map TSC G4_IO4 on PC9 pin
using TSC_G4_IO4_PC9 = AnyAltOut<Port::PC, 9, AfTSC_G4_IO4_PC9>;/// A default configuration to map TSC SYNC on PB10 pin
using TSC_SYNC_PB10 = AnyAltOut<Port::PB, 10, AfTSC_SYNC_PB10>;#if defined(GPIOD_BASE)
/// A default configuration to map TSC G6_IO1 on PD10 pin
using TSC_G6_IO1_PD10 = AnyAltOut<Port::PD, 10, AfTSC_G6_IO1_PD10>;/// A default configuration to map TSC G6_IO2 on PD11 pin
using TSC_G6_IO2_PD11 = AnyAltOut<Port::PD, 11, AfTSC_G6_IO2_PD11>;/// A default configuration to map TSC G6_IO3 on PD12 pin
using TSC_G6_IO3_PD12 = AnyAltOut<Port::PD, 12, AfTSC_G6_IO3_PD12>;/// A default configuration to map TSC G6_IO4 on PD13 pin
using TSC_G6_IO4_PD13 = AnyAltOut<Port::PD, 13, AfTSC_G6_IO4_PD13>;/// A default configuration to map TSC SYNC on PD2 pin
using TSC_SYNC_PD2 = AnyAltOut<Port::PD, 2, AfTSC_SYNC_PD2>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map TSC G5_IO1 on PE10 pin
using TSC_G5_IO1_PE10 = AnyAltOut<Port::PE, 10, AfTSC_G5_IO1_PE10>;/// A default configuration to map TSC G5_IO2 on PE11 pin
using TSC_G5_IO2_PE11 = AnyAltOut<Port::PE, 11, AfTSC_G5_IO2_PE11>;/// A default configuration to map TSC G5_IO3 on PE12 pin
using TSC_G5_IO3_PE12 = AnyAltOut<Port::PE, 12, AfTSC_G5_IO3_PE12>;/// A default configuration to map TSC G5_IO4 on PE13 pin
using TSC_G5_IO4_PE13 = AnyAltOut<Port::PE, 13, AfTSC_G5_IO4_PE13>;/// A default configuration to map TSC G7_IO1 on PE2 pin
using TSC_G7_IO1_PE2 = AnyAltOut<Port::PE, 2, AfTSC_G7_IO1_PE2>;/// A default configuration to map TSC G7_IO2 on PE3 pin
using TSC_G7_IO2_PE3 = AnyAltOut<Port::PE, 3, AfTSC_G7_IO2_PE3>;/// A default configuration to map TSC G7_IO3 on PE4 pin
using TSC_G7_IO3_PE4 = AnyAltOut<Port::PE, 4, AfTSC_G7_IO3_PE4>;/// A default configuration to map TSC G7_IO4 on PE5 pin
using TSC_G7_IO4_PE5 = AnyAltOut<Port::PE, 5, AfTSC_G7_IO4_PE5>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map TSC G8_IO1 on PF14 pin
using TSC_G8_IO1_PF14 = AnyAltOut<Port::PF, 14, AfTSC_G8_IO1_PF14>;/// A default configuration to map TSC G8_IO2 on PF15 pin
using TSC_G8_IO2_PF15 = AnyAltOut<Port::PF, 15, AfTSC_G8_IO2_PF15>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map TSC G8_IO3 on PG0 pin
using TSC_G8_IO3_PG0 = AnyAltOut<Port::PG, 0, AfTSC_G8_IO3_PG0>;/// A default configuration to map TSC G8_IO4 on PG1 pin
using TSC_G8_IO4_PG1 = AnyAltOut<Port::PG, 1, AfTSC_G8_IO4_PG1>;#endif	// defined(GPIOG_BASE)
#endif	// defined(TSC_BASE)

//////////////////////////////////////////////////////////////////////
// USART1
//////////////////////////////////////////////////////////////////////
#if defined(USART1_BASE)
/// A default configuration to map USART1 CK on PA8 pin
using USART1_CK_PA8 = AnyAltOut<Port::PA, 8, AfUSART1_CK_PA8>;/// A default configuration to map USART1 CK on PB5 pin
using USART1_CK_PB5 = AnyAltOut<Port::PB, 5, AfUSART1_CK_PB5>;/// A default configuration to map USART1 CTS on PA11 pin
using USART1_CTS_PA11 = AnyAltOutOD<Port::PA, 11, AfUSART1_CTS_PA11>;/// A default configuration to map USART1 CTS on PB4 pin
using USART1_CTS_PB4 = AnyAltOutOD<Port::PB, 4, AfUSART1_CTS_PB4>;/// A default configuration to map USART1 DE on PA12 pin
using USART1_DE_PA12 = AnyAltOut<Port::PA, 12, AfUSART1_DE_PA12>;/// A default configuration to map USART1 DE on PB3 pin
using USART1_DE_PB3 = AnyAltOut<Port::PB, 3, AfUSART1_DE_PB3>;/// A default configuration to map USART1 RTS on PA12 pin
using USART1_RTS_PA12 = AnyAltOut<Port::PA, 12, AfUSART1_RTS_PA12>;/// A default configuration to map USART1 RTS on PB3 pin
using USART1_RTS_PB3 = AnyAltOut<Port::PB, 3, AfUSART1_RTS_PB3>;/// A default configuration to map USART1 RX on PA10 pin
using USART1_RX_PA10 = AnyAltOutOD<Port::PA, 10, AfUSART1_RX_PA10>;/// A default configuration to map USART1 RX on PB7 pin
using USART1_RX_PB7 = AnyAltOutOD<Port::PB, 7, AfUSART1_RX_PB7>;/// A default configuration to map USART1 TX on PA9 pin
using USART1_TX_PA9 = AnyAltOut<Port::PA, 9, AfUSART1_TX_PA9>;/// A default configuration to map USART1 TX on PB6 pin
using USART1_TX_PB6 = AnyAltOut<Port::PB, 6, AfUSART1_TX_PB6>;#if defined(GPIOG_BASE)
/// A default configuration to map USART1 CK on PG13 pin
using USART1_CK_PG13 = AnyAltOut<Port::PG, 13, AfUSART1_CK_PG13>;/// A default configuration to map USART1 CTS on PG11 pin
using USART1_CTS_PG11 = AnyAltOutOD<Port::PG, 11, AfUSART1_CTS_PG11>;/// A default configuration to map USART1 DE on PG12 pin
using USART1_DE_PG12 = AnyAltOut<Port::PG, 12, AfUSART1_DE_PG12>;/// A default configuration to map USART1 RTS on PG12 pin
using USART1_RTS_PG12 = AnyAltOut<Port::PG, 12, AfUSART1_RTS_PG12>;/// A default configuration to map USART1 RX on PG10 pin
using USART1_RX_PG10 = AnyAltOutOD<Port::PG, 10, AfUSART1_RX_PG10>;/// A default configuration to map USART1 TX on PG9 pin
using USART1_TX_PG9 = AnyAltOut<Port::PG, 9, AfUSART1_TX_PG9>;#endif	// defined(GPIOG_BASE)
#endif	// defined(USART1_BASE)

//////////////////////////////////////////////////////////////////////
// USART2
//////////////////////////////////////////////////////////////////////
#if defined(USART2_BASE)
/// A default configuration to map USART2 CK on PA4 pin
using USART2_CK_PA4 = AnyAltOut<Port::PA, 4, AfUSART2_CK_PA4>;/// A default configuration to map USART2 CTS on PA0 pin
using USART2_CTS_PA0 = AnyAltOutOD<Port::PA, 0, AfUSART2_CTS_PA0>;/// A default configuration to map USART2 DE on PA1 pin
using USART2_DE_PA1 = AnyAltOut<Port::PA, 1, AfUSART2_DE_PA1>;/// A default configuration to map USART2 RTS on PA1 pin
using USART2_RTS_PA1 = AnyAltOut<Port::PA, 1, AfUSART2_RTS_PA1>;/// A default configuration to map USART2 RX on PA3 pin
using USART2_RX_PA3 = AnyAltOutOD<Port::PA, 3, AfUSART2_RX_PA3>;/// A default configuration to map USART2 RX on PA15 pin
using USART2_RX_PA15 = AnyAltOutOD<Port::PA, 15, AfUSART2_RX_PA15>;/// A default configuration to map USART2 TX on PA2 pin
using USART2_TX_PA2 = AnyAltOut<Port::PA, 2, AfUSART2_TX_PA2>;#if defined(GPIOD_BASE)
/// A default configuration to map USART2 CK on PD7 pin
using USART2_CK_PD7 = AnyAltOut<Port::PD, 7, AfUSART2_CK_PD7>;/// A default configuration to map USART2 CTS on PD3 pin
using USART2_CTS_PD3 = AnyAltOutOD<Port::PD, 3, AfUSART2_CTS_PD3>;/// A default configuration to map USART2 DE on PD4 pin
using USART2_DE_PD4 = AnyAltOut<Port::PD, 4, AfUSART2_DE_PD4>;/// A default configuration to map USART2 RTS on PD4 pin
using USART2_RTS_PD4 = AnyAltOut<Port::PD, 4, AfUSART2_RTS_PD4>;/// A default configuration to map USART2 RX on PD6 pin
using USART2_RX_PD6 = AnyAltOutOD<Port::PD, 6, AfUSART2_RX_PD6>;/// A default configuration to map USART2 TX on PD5 pin
using USART2_TX_PD5 = AnyAltOut<Port::PD, 5, AfUSART2_TX_PD5>;#endif	// defined(GPIOD_BASE)
#endif	// defined(USART2_BASE)

//////////////////////////////////////////////////////////////////////
// USART3
//////////////////////////////////////////////////////////////////////
#if defined(USART3_BASE)
/// A default configuration to map USART3 CK on PB0 pin
using USART3_CK_PB0 = AnyAltOut<Port::PB, 0, AfUSART3_CK_PB0>;/// A default configuration to map USART3 CK on PB12 pin
using USART3_CK_PB12 = AnyAltOut<Port::PB, 12, AfUSART3_CK_PB12>;/// A default configuration to map USART3 CK on PC12 pin
using USART3_CK_PC12 = AnyAltOut<Port::PC, 12, AfUSART3_CK_PC12>;/// A default configuration to map USART3 CTS on PA6 pin
using USART3_CTS_PA6 = AnyAltOutOD<Port::PA, 6, AfUSART3_CTS_PA6>;/// A default configuration to map USART3 CTS on PB13 pin
using USART3_CTS_PB13 = AnyAltOutOD<Port::PB, 13, AfUSART3_CTS_PB13>;/// A default configuration to map USART3 DE on PA15 pin
using USART3_DE_PA15 = AnyAltOut<Port::PA, 15, AfUSART3_DE_PA15>;/// A default configuration to map USART3 DE on PB1 pin
using USART3_DE_PB1 = AnyAltOut<Port::PB, 1, AfUSART3_DE_PB1>;/// A default configuration to map USART3 DE on PB14 pin
using USART3_DE_PB14 = AnyAltOut<Port::PB, 14, AfUSART3_DE_PB14>;/// A default configuration to map USART3 RTS on PA15 pin
using USART3_RTS_PA15 = AnyAltOut<Port::PA, 15, AfUSART3_RTS_PA15>;/// A default configuration to map USART3 RTS on PB1 pin
using USART3_RTS_PB1 = AnyAltOut<Port::PB, 1, AfUSART3_RTS_PB1>;/// A default configuration to map USART3 RTS on PB14 pin
using USART3_RTS_PB14 = AnyAltOut<Port::PB, 14, AfUSART3_RTS_PB14>;/// A default configuration to map USART3 RX on PB11 pin
using USART3_RX_PB11 = AnyAltOutOD<Port::PB, 11, AfUSART3_RX_PB11>;/// A default configuration to map USART3 RX on PC5 pin
using USART3_RX_PC5 = AnyAltOutOD<Port::PC, 5, AfUSART3_RX_PC5>;/// A default configuration to map USART3 RX on PC11 pin
using USART3_RX_PC11 = AnyAltOutOD<Port::PC, 11, AfUSART3_RX_PC11>;/// A default configuration to map USART3 TX on PB10 pin
using USART3_TX_PB10 = AnyAltOut<Port::PB, 10, AfUSART3_TX_PB10>;/// A default configuration to map USART3 TX on PC4 pin
using USART3_TX_PC4 = AnyAltOut<Port::PC, 4, AfUSART3_TX_PC4>;/// A default configuration to map USART3 TX on PC10 pin
using USART3_TX_PC10 = AnyAltOut<Port::PC, 10, AfUSART3_TX_PC10>;#if defined(GPIOD_BASE)
/// A default configuration to map USART3 CK on PD10 pin
using USART3_CK_PD10 = AnyAltOut<Port::PD, 10, AfUSART3_CK_PD10>;/// A default configuration to map USART3 CTS on PD11 pin
using USART3_CTS_PD11 = AnyAltOutOD<Port::PD, 11, AfUSART3_CTS_PD11>;/// A default configuration to map USART3 DE on PD2 pin
using USART3_DE_PD2 = AnyAltOut<Port::PD, 2, AfUSART3_DE_PD2>;/// A default configuration to map USART3 DE on PD12 pin
using USART3_DE_PD12 = AnyAltOut<Port::PD, 12, AfUSART3_DE_PD12>;/// A default configuration to map USART3 RTS on PD2 pin
using USART3_RTS_PD2 = AnyAltOut<Port::PD, 2, AfUSART3_RTS_PD2>;/// A default configuration to map USART3 RTS on PD12 pin
using USART3_RTS_PD12 = AnyAltOut<Port::PD, 12, AfUSART3_RTS_PD12>;/// A default configuration to map USART3 RX on PD9 pin
using USART3_RX_PD9 = AnyAltOutOD<Port::PD, 9, AfUSART3_RX_PD9>;/// A default configuration to map USART3 TX on PD8 pin
using USART3_TX_PD8 = AnyAltOut<Port::PD, 8, AfUSART3_TX_PD8>;#endif	// defined(GPIOD_BASE)
#endif	// defined(USART3_BASE)

//////////////////////////////////////////////////////////////////////
// UART4
//////////////////////////////////////////////////////////////////////
#if defined(UART4_BASE)
/// A default configuration to map UART4 CTS on PB7 pin
using UART4_CTS_PB7 = AnyAltOutOD<Port::PB, 7, AfUART4_CTS_PB7>;/// A default configuration to map UART4 DE on PA15 pin
using UART4_DE_PA15 = AnyAltOut<Port::PA, 15, AfUART4_DE_PA15>;/// A default configuration to map UART4 RTS on PA15 pin
using UART4_RTS_PA15 = AnyAltOut<Port::PA, 15, AfUART4_RTS_PA15>;/// A default configuration to map UART4 RX on PA1 pin
using UART4_RX_PA1 = AnyAltOutOD<Port::PA, 1, AfUART4_RX_PA1>;/// A default configuration to map UART4 RX on PC11 pin
using UART4_RX_PC11 = AnyAltOutOD<Port::PC, 11, AfUART4_RX_PC11>;/// A default configuration to map UART4 TX on PA0 pin
using UART4_TX_PA0 = AnyAltOut<Port::PA, 0, AfUART4_TX_PA0>;/// A default configuration to map UART4 TX on PC10 pin
using UART4_TX_PC10 = AnyAltOut<Port::PC, 10, AfUART4_TX_PC10>;#endif	// defined(UART4_BASE)

//////////////////////////////////////////////////////////////////////
// UART5
//////////////////////////////////////////////////////////////////////
#if defined(UART5_BASE)
/// A default configuration to map UART5 CTS on PB5 pin
using UART5_CTS_PB5 = AnyAltOutOD<Port::PB, 5, AfUART5_CTS_PB5>;/// A default configuration to map UART5 DE on PB4 pin
using UART5_DE_PB4 = AnyAltOut<Port::PB, 4, AfUART5_DE_PB4>;/// A default configuration to map UART5 RTS on PB4 pin
using UART5_RTS_PB4 = AnyAltOut<Port::PB, 4, AfUART5_RTS_PB4>;/// A default configuration to map UART5 TX on PC12 pin
using UART5_TX_PC12 = AnyAltOut<Port::PC, 12, AfUART5_TX_PC12>;#if defined(GPIOD_BASE)
/// A default configuration to map UART5 RX on PD2 pin
using UART5_RX_PD2 = AnyAltOutOD<Port::PD, 2, AfUART5_RX_PD2>;#endif	// defined(GPIOD_BASE)
#endif	// defined(UART5_BASE)

//////////////////////////////////////////////////////////////////////
// EVENTOUT
//////////////////////////////////////////////////////////////////////
/// A default configuration to map EVENTOUT on PA0 pin
using EVENTOUT_PA0 = AnyAltOut<Port::PA, 0, AfEVENTOUT_PA0>;/// A default configuration to map EVENTOUT on PA1 pin
using EVENTOUT_PA1 = AnyAltOut<Port::PA, 1, AfEVENTOUT_PA1>;/// A default configuration to map EVENTOUT on PA2 pin
using EVENTOUT_PA2 = AnyAltOut<Port::PA, 2, AfEVENTOUT_PA2>;/// A default configuration to map EVENTOUT on PA3 pin
using EVENTOUT_PA3 = AnyAltOut<Port::PA, 3, AfEVENTOUT_PA3>;/// A default configuration to map EVENTOUT on PA4 pin
using EVENTOUT_PA4 = AnyAltOut<Port::PA, 4, AfEVENTOUT_PA4>;/// A default configuration to map EVENTOUT on PA5 pin
using EVENTOUT_PA5 = AnyAltOut<Port::PA, 5, AfEVENTOUT_PA5>;/// A default configuration to map EVENTOUT on PA6 pin
using EVENTOUT_PA6 = AnyAltOut<Port::PA, 6, AfEVENTOUT_PA6>;/// A default configuration to map EVENTOUT on PA7 pin
using EVENTOUT_PA7 = AnyAltOut<Port::PA, 7, AfEVENTOUT_PA7>;/// A default configuration to map EVENTOUT on PA8 pin
using EVENTOUT_PA8 = AnyAltOut<Port::PA, 8, AfEVENTOUT_PA8>;/// A default configuration to map EVENTOUT on PA9 pin
using EVENTOUT_PA9 = AnyAltOut<Port::PA, 9, AfEVENTOUT_PA9>;/// A default configuration to map EVENTOUT on PA10 pin
using EVENTOUT_PA10 = AnyAltOut<Port::PA, 10, AfEVENTOUT_PA10>;/// A default configuration to map EVENTOUT on PA11 pin
using EVENTOUT_PA11 = AnyAltOut<Port::PA, 11, AfEVENTOUT_PA11>;/// A default configuration to map EVENTOUT on PA12 pin
using EVENTOUT_PA12 = AnyAltOut<Port::PA, 12, AfEVENTOUT_PA12>;/// A default configuration to map EVENTOUT on PA13 pin
using EVENTOUT_PA13 = AnyAltOut<Port::PA, 13, AfEVENTOUT_PA13>;/// A default configuration to map EVENTOUT on PA14 pin
using EVENTOUT_PA14 = AnyAltOut<Port::PA, 14, AfEVENTOUT_PA14>;/// A default configuration to map EVENTOUT on PA15 pin
using EVENTOUT_PA15 = AnyAltOut<Port::PA, 15, AfEVENTOUT_PA15>;/// A default configuration to map EVENTOUT on PB0 pin
using EVENTOUT_PB0 = AnyAltOut<Port::PB, 0, AfEVENTOUT_PB0>;/// A default configuration to map EVENTOUT on PB1 pin
using EVENTOUT_PB1 = AnyAltOut<Port::PB, 1, AfEVENTOUT_PB1>;/// A default configuration to map EVENTOUT on PB2 pin
using EVENTOUT_PB2 = AnyAltOut<Port::PB, 2, AfEVENTOUT_PB2>;/// A default configuration to map EVENTOUT on PB3 pin
using EVENTOUT_PB3 = AnyAltOut<Port::PB, 3, AfEVENTOUT_PB3>;/// A default configuration to map EVENTOUT on PB4 pin
using EVENTOUT_PB4 = AnyAltOut<Port::PB, 4, AfEVENTOUT_PB4>;/// A default configuration to map EVENTOUT on PB5 pin
using EVENTOUT_PB5 = AnyAltOut<Port::PB, 5, AfEVENTOUT_PB5>;/// A default configuration to map EVENTOUT on PB6 pin
using EVENTOUT_PB6 = AnyAltOut<Port::PB, 6, AfEVENTOUT_PB6>;/// A default configuration to map EVENTOUT on PB7 pin
using EVENTOUT_PB7 = AnyAltOut<Port::PB, 7, AfEVENTOUT_PB7>;/// A default configuration to map EVENTOUT on PB8 pin
using EVENTOUT_PB8 = AnyAltOut<Port::PB, 8, AfEVENTOUT_PB8>;/// A default configuration to map EVENTOUT on PB9 pin
using EVENTOUT_PB9 = AnyAltOut<Port::PB, 9, AfEVENTOUT_PB9>;/// A default configuration to map EVENTOUT on PB10 pin
using EVENTOUT_PB10 = AnyAltOut<Port::PB, 10, AfEVENTOUT_PB10>;/// A default configuration to map EVENTOUT on PB11 pin
using EVENTOUT_PB11 = AnyAltOut<Port::PB, 11, AfEVENTOUT_PB11>;/// A default configuration to map EVENTOUT on PB12 pin
using EVENTOUT_PB12 = AnyAltOut<Port::PB, 12, AfEVENTOUT_PB12>;/// A default configuration to map EVENTOUT on PB13 pin
using EVENTOUT_PB13 = AnyAltOut<Port::PB, 13, AfEVENTOUT_PB13>;/// A default configuration to map EVENTOUT on PB14 pin
using EVENTOUT_PB14 = AnyAltOut<Port::PB, 14, AfEVENTOUT_PB14>;/// A default configuration to map EVENTOUT on PB15 pin
using EVENTOUT_PB15 = AnyAltOut<Port::PB, 15, AfEVENTOUT_PB15>;/// A default configuration to map EVENTOUT on PC0 pin
using EVENTOUT_PC0 = AnyAltOut<Port::PC, 0, AfEVENTOUT_PC0>;/// A default configuration to map EVENTOUT on PC1 pin
using EVENTOUT_PC1 = AnyAltOut<Port::PC, 1, AfEVENTOUT_PC1>;/// A default configuration to map EVENTOUT on PC2 pin
using EVENTOUT_PC2 = AnyAltOut<Port::PC, 2, AfEVENTOUT_PC2>;/// A default configuration to map EVENTOUT on PC3 pin
using EVENTOUT_PC3 = AnyAltOut<Port::PC, 3, AfEVENTOUT_PC3>;/// A default configuration to map EVENTOUT on PC4 pin
using EVENTOUT_PC4 = AnyAltOut<Port::PC, 4, AfEVENTOUT_PC4>;/// A default configuration to map EVENTOUT on PC5 pin
using EVENTOUT_PC5 = AnyAltOut<Port::PC, 5, AfEVENTOUT_PC5>;/// A default configuration to map EVENTOUT on PC6 pin
using EVENTOUT_PC6 = AnyAltOut<Port::PC, 6, AfEVENTOUT_PC6>;/// A default configuration to map EVENTOUT on PC7 pin
using EVENTOUT_PC7 = AnyAltOut<Port::PC, 7, AfEVENTOUT_PC7>;/// A default configuration to map EVENTOUT on PC8 pin
using EVENTOUT_PC8 = AnyAltOut<Port::PC, 8, AfEVENTOUT_PC8>;/// A default configuration to map EVENTOUT on PC9 pin
using EVENTOUT_PC9 = AnyAltOut<Port::PC, 9, AfEVENTOUT_PC9>;/// A default configuration to map EVENTOUT on PC10 pin
using EVENTOUT_PC10 = AnyAltOut<Port::PC, 10, AfEVENTOUT_PC10>;/// A default configuration to map EVENTOUT on PC11 pin
using EVENTOUT_PC11 = AnyAltOut<Port::PC, 11, AfEVENTOUT_PC11>;/// A default configuration to map EVENTOUT on PC12 pin
using EVENTOUT_PC12 = AnyAltOut<Port::PC, 12, AfEVENTOUT_PC12>;/// A default configuration to map EVENTOUT on PC13 pin
using EVENTOUT_PC13 = AnyAltOut<Port::PC, 13, AfEVENTOUT_PC13>;/// A default configuration to map EVENTOUT on PC14 pin
using EVENTOUT_PC14 = AnyAltOut<Port::PC, 14, AfEVENTOUT_PC14>;/// A default configuration to map EVENTOUT on PC15 pin
using EVENTOUT_PC15 = AnyAltOut<Port::PC, 15, AfEVENTOUT_PC15>;#if defined(GPIOD_BASE)
/// A default configuration to map EVENTOUT on PD0 pin
using EVENTOUT_PD0 = AnyAltOut<Port::PD, 0, AfEVENTOUT_PD0>;/// A default configuration to map EVENTOUT on PD1 pin
using EVENTOUT_PD1 = AnyAltOut<Port::PD, 1, AfEVENTOUT_PD1>;/// A default configuration to map EVENTOUT on PD2 pin
using EVENTOUT_PD2 = AnyAltOut<Port::PD, 2, AfEVENTOUT_PD2>;/// A default configuration to map EVENTOUT on PD3 pin
using EVENTOUT_PD3 = AnyAltOut<Port::PD, 3, AfEVENTOUT_PD3>;/// A default configuration to map EVENTOUT on PD4 pin
using EVENTOUT_PD4 = AnyAltOut<Port::PD, 4, AfEVENTOUT_PD4>;/// A default configuration to map EVENTOUT on PD5 pin
using EVENTOUT_PD5 = AnyAltOut<Port::PD, 5, AfEVENTOUT_PD5>;/// A default configuration to map EVENTOUT on PD6 pin
using EVENTOUT_PD6 = AnyAltOut<Port::PD, 6, AfEVENTOUT_PD6>;/// A default configuration to map EVENTOUT on PD7 pin
using EVENTOUT_PD7 = AnyAltOut<Port::PD, 7, AfEVENTOUT_PD7>;/// A default configuration to map EVENTOUT on PD8 pin
using EVENTOUT_PD8 = AnyAltOut<Port::PD, 8, AfEVENTOUT_PD8>;/// A default configuration to map EVENTOUT on PD9 pin
using EVENTOUT_PD9 = AnyAltOut<Port::PD, 9, AfEVENTOUT_PD9>;/// A default configuration to map EVENTOUT on PD10 pin
using EVENTOUT_PD10 = AnyAltOut<Port::PD, 10, AfEVENTOUT_PD10>;/// A default configuration to map EVENTOUT on PD11 pin
using EVENTOUT_PD11 = AnyAltOut<Port::PD, 11, AfEVENTOUT_PD11>;/// A default configuration to map EVENTOUT on PD12 pin
using EVENTOUT_PD12 = AnyAltOut<Port::PD, 12, AfEVENTOUT_PD12>;/// A default configuration to map EVENTOUT on PD13 pin
using EVENTOUT_PD13 = AnyAltOut<Port::PD, 13, AfEVENTOUT_PD13>;/// A default configuration to map EVENTOUT on PD14 pin
using EVENTOUT_PD14 = AnyAltOut<Port::PD, 14, AfEVENTOUT_PD14>;/// A default configuration to map EVENTOUT on PD15 pin
using EVENTOUT_PD15 = AnyAltOut<Port::PD, 15, AfEVENTOUT_PD15>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
/// A default configuration to map EVENTOUT on PE0 pin
using EVENTOUT_PE0 = AnyAltOut<Port::PE, 0, AfEVENTOUT_PE0>;/// A default configuration to map EVENTOUT on PE1 pin
using EVENTOUT_PE1 = AnyAltOut<Port::PE, 1, AfEVENTOUT_PE1>;/// A default configuration to map EVENTOUT on PE2 pin
using EVENTOUT_PE2 = AnyAltOut<Port::PE, 2, AfEVENTOUT_PE2>;/// A default configuration to map EVENTOUT on PE3 pin
using EVENTOUT_PE3 = AnyAltOut<Port::PE, 3, AfEVENTOUT_PE3>;/// A default configuration to map EVENTOUT on PE4 pin
using EVENTOUT_PE4 = AnyAltOut<Port::PE, 4, AfEVENTOUT_PE4>;/// A default configuration to map EVENTOUT on PE5 pin
using EVENTOUT_PE5 = AnyAltOut<Port::PE, 5, AfEVENTOUT_PE5>;/// A default configuration to map EVENTOUT on PE6 pin
using EVENTOUT_PE6 = AnyAltOut<Port::PE, 6, AfEVENTOUT_PE6>;/// A default configuration to map EVENTOUT on PE7 pin
using EVENTOUT_PE7 = AnyAltOut<Port::PE, 7, AfEVENTOUT_PE7>;/// A default configuration to map EVENTOUT on PE8 pin
using EVENTOUT_PE8 = AnyAltOut<Port::PE, 8, AfEVENTOUT_PE8>;/// A default configuration to map EVENTOUT on PE9 pin
using EVENTOUT_PE9 = AnyAltOut<Port::PE, 9, AfEVENTOUT_PE9>;/// A default configuration to map EVENTOUT on PE10 pin
using EVENTOUT_PE10 = AnyAltOut<Port::PE, 10, AfEVENTOUT_PE10>;/// A default configuration to map EVENTOUT on PE11 pin
using EVENTOUT_PE11 = AnyAltOut<Port::PE, 11, AfEVENTOUT_PE11>;/// A default configuration to map EVENTOUT on PE12 pin
using EVENTOUT_PE12 = AnyAltOut<Port::PE, 12, AfEVENTOUT_PE12>;/// A default configuration to map EVENTOUT on PE13 pin
using EVENTOUT_PE13 = AnyAltOut<Port::PE, 13, AfEVENTOUT_PE13>;/// A default configuration to map EVENTOUT on PE14 pin
using EVENTOUT_PE14 = AnyAltOut<Port::PE, 14, AfEVENTOUT_PE14>;/// A default configuration to map EVENTOUT on PE15 pin
using EVENTOUT_PE15 = AnyAltOut<Port::PE, 15, AfEVENTOUT_PE15>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
/// A default configuration to map EVENTOUT on PF0 pin
using EVENTOUT_PF0 = AnyAltOut<Port::PF, 0, AfEVENTOUT_PF0>;/// A default configuration to map EVENTOUT on PF1 pin
using EVENTOUT_PF1 = AnyAltOut<Port::PF, 1, AfEVENTOUT_PF1>;/// A default configuration to map EVENTOUT on PF2 pin
using EVENTOUT_PF2 = AnyAltOut<Port::PF, 2, AfEVENTOUT_PF2>;/// A default configuration to map EVENTOUT on PF3 pin
using EVENTOUT_PF3 = AnyAltOut<Port::PF, 3, AfEVENTOUT_PF3>;/// A default configuration to map EVENTOUT on PF4 pin
using EVENTOUT_PF4 = AnyAltOut<Port::PF, 4, AfEVENTOUT_PF4>;/// A default configuration to map EVENTOUT on PF5 pin
using EVENTOUT_PF5 = AnyAltOut<Port::PF, 5, AfEVENTOUT_PF5>;/// A default configuration to map EVENTOUT on PF6 pin
using EVENTOUT_PF6 = AnyAltOut<Port::PF, 6, AfEVENTOUT_PF6>;/// A default configuration to map EVENTOUT on PF7 pin
using EVENTOUT_PF7 = AnyAltOut<Port::PF, 7, AfEVENTOUT_PF7>;/// A default configuration to map EVENTOUT on PF8 pin
using EVENTOUT_PF8 = AnyAltOut<Port::PF, 8, AfEVENTOUT_PF8>;/// A default configuration to map EVENTOUT on PF9 pin
using EVENTOUT_PF9 = AnyAltOut<Port::PF, 9, AfEVENTOUT_PF9>;/// A default configuration to map EVENTOUT on PF10 pin
using EVENTOUT_PF10 = AnyAltOut<Port::PF, 10, AfEVENTOUT_PF10>;/// A default configuration to map EVENTOUT on PF11 pin
using EVENTOUT_PF11 = AnyAltOut<Port::PF, 11, AfEVENTOUT_PF11>;/// A default configuration to map EVENTOUT on PF12 pin
using EVENTOUT_PF12 = AnyAltOut<Port::PF, 12, AfEVENTOUT_PF12>;/// A default configuration to map EVENTOUT on PF13 pin
using EVENTOUT_PF13 = AnyAltOut<Port::PF, 13, AfEVENTOUT_PF13>;/// A default configuration to map EVENTOUT on PF14 pin
using EVENTOUT_PF14 = AnyAltOut<Port::PF, 14, AfEVENTOUT_PF14>;/// A default configuration to map EVENTOUT on PF15 pin
using EVENTOUT_PF15 = AnyAltOut<Port::PF, 15, AfEVENTOUT_PF15>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
/// A default configuration to map EVENTOUT on PG0 pin
using EVENTOUT_PG0 = AnyAltOut<Port::PG, 0, AfEVENTOUT_PG0>;/// A default configuration to map EVENTOUT on PG1 pin
using EVENTOUT_PG1 = AnyAltOut<Port::PG, 1, AfEVENTOUT_PG1>;/// A default configuration to map EVENTOUT on PG2 pin
using EVENTOUT_PG2 = AnyAltOut<Port::PG, 2, AfEVENTOUT_PG2>;/// A default configuration to map EVENTOUT on PG3 pin
using EVENTOUT_PG3 = AnyAltOut<Port::PG, 3, AfEVENTOUT_PG3>;/// A default configuration to map EVENTOUT on PG4 pin
using EVENTOUT_PG4 = AnyAltOut<Port::PG, 4, AfEVENTOUT_PG4>;/// A default configuration to map EVENTOUT on PG5 pin
using EVENTOUT_PG5 = AnyAltOut<Port::PG, 5, AfEVENTOUT_PG5>;/// A default configuration to map EVENTOUT on PG6 pin
using EVENTOUT_PG6 = AnyAltOut<Port::PG, 6, AfEVENTOUT_PG6>;/// A default configuration to map EVENTOUT on PG7 pin
using EVENTOUT_PG7 = AnyAltOut<Port::PG, 7, AfEVENTOUT_PG7>;/// A default configuration to map EVENTOUT on PG8 pin
using EVENTOUT_PG8 = AnyAltOut<Port::PG, 8, AfEVENTOUT_PG8>;/// A default configuration to map EVENTOUT on PG9 pin
using EVENTOUT_PG9 = AnyAltOut<Port::PG, 9, AfEVENTOUT_PG9>;/// A default configuration to map EVENTOUT on PG10 pin
using EVENTOUT_PG10 = AnyAltOut<Port::PG, 10, AfEVENTOUT_PG10>;/// A default configuration to map EVENTOUT on PG11 pin
using EVENTOUT_PG11 = AnyAltOut<Port::PG, 11, AfEVENTOUT_PG11>;/// A default configuration to map EVENTOUT on PG12 pin
using EVENTOUT_PG12 = AnyAltOut<Port::PG, 12, AfEVENTOUT_PG12>;/// A default configuration to map EVENTOUT on PG13 pin
using EVENTOUT_PG13 = AnyAltOut<Port::PG, 13, AfEVENTOUT_PG13>;/// A default configuration to map EVENTOUT on PG14 pin
using EVENTOUT_PG14 = AnyAltOut<Port::PG, 14, AfEVENTOUT_PG14>;/// A default configuration to map EVENTOUT on PG15 pin
using EVENTOUT_PG15 = AnyAltOut<Port::PG, 15, AfEVENTOUT_PG15>;#endif	// defined(GPIOG_BASE)
#if defined(GPIOH_BASE)
/// A default configuration to map EVENTOUT on PH0 pin
using EVENTOUT_PH0 = AnyAltOut<Port::PH, 0, AfEVENTOUT_PH0>;/// A default configuration to map EVENTOUT on PH1 pin
using EVENTOUT_PH1 = AnyAltOut<Port::PH, 1, AfEVENTOUT_PH1>;/// A default configuration to map EVENTOUT on PH2 pin
using EVENTOUT_PH2 = AnyAltOut<Port::PH, 2, AfEVENTOUT_PH2>;/// A default configuration to map EVENTOUT on PH3 pin
using EVENTOUT_PH3 = AnyAltOut<Port::PH, 3, AfEVENTOUT_PH3>;/// A default configuration to map EVENTOUT on PH4 pin
using EVENTOUT_PH4 = AnyAltOut<Port::PH, 4, AfEVENTOUT_PH4>;/// A default configuration to map EVENTOUT on PH5 pin
using EVENTOUT_PH5 = AnyAltOut<Port::PH, 5, AfEVENTOUT_PH5>;/// A default configuration to map EVENTOUT on PH6 pin
using EVENTOUT_PH6 = AnyAltOut<Port::PH, 6, AfEVENTOUT_PH6>;/// A default configuration to map EVENTOUT on PH7 pin
using EVENTOUT_PH7 = AnyAltOut<Port::PH, 7, AfEVENTOUT_PH7>;/// A default configuration to map EVENTOUT on PH8 pin
using EVENTOUT_PH8 = AnyAltOut<Port::PH, 8, AfEVENTOUT_PH8>;/// A default configuration to map EVENTOUT on PH9 pin
using EVENTOUT_PH9 = AnyAltOut<Port::PH, 9, AfEVENTOUT_PH9>;/// A default configuration to map EVENTOUT on PH10 pin
using EVENTOUT_PH10 = AnyAltOut<Port::PH, 10, AfEVENTOUT_PH10>;/// A default configuration to map EVENTOUT on PH11 pin
using EVENTOUT_PH11 = AnyAltOut<Port::PH, 11, AfEVENTOUT_PH11>;/// A default configuration to map EVENTOUT on PH12 pin
using EVENTOUT_PH12 = AnyAltOut<Port::PH, 12, AfEVENTOUT_PH12>;/// A default configuration to map EVENTOUT on PH13 pin
using EVENTOUT_PH13 = AnyAltOut<Port::PH, 13, AfEVENTOUT_PH13>;/// A default configuration to map EVENTOUT on PH14 pin
using EVENTOUT_PH14 = AnyAltOut<Port::PH, 14, AfEVENTOUT_PH14>;/// A default configuration to map EVENTOUT on PH15 pin
using EVENTOUT_PH15 = AnyAltOut<Port::PH, 15, AfEVENTOUT_PH15>;#endif	// defined(GPIOH_BASE)
#if defined(GPIOI_BASE)
/// A default configuration to map EVENTOUT on PI0 pin
using EVENTOUT_PI0 = AnyAltOut<Port::PI, 0, AfEVENTOUT_PI0>;/// A default configuration to map EVENTOUT on PI1 pin
using EVENTOUT_PI1 = AnyAltOut<Port::PI, 1, AfEVENTOUT_PI1>;/// A default configuration to map EVENTOUT on PI2 pin
using EVENTOUT_PI2 = AnyAltOut<Port::PI, 2, AfEVENTOUT_PI2>;/// A default configuration to map EVENTOUT on PI3 pin
using EVENTOUT_PI3 = AnyAltOut<Port::PI, 3, AfEVENTOUT_PI3>;/// A default configuration to map EVENTOUT on PI4 pin
using EVENTOUT_PI4 = AnyAltOut<Port::PI, 4, AfEVENTOUT_PI4>;/// A default configuration to map EVENTOUT on PI5 pin
using EVENTOUT_PI5 = AnyAltOut<Port::PI, 5, AfEVENTOUT_PI5>;/// A default configuration to map EVENTOUT on PI6 pin
using EVENTOUT_PI6 = AnyAltOut<Port::PI, 6, AfEVENTOUT_PI6>;/// A default configuration to map EVENTOUT on PI7 pin
using EVENTOUT_PI7 = AnyAltOut<Port::PI, 7, AfEVENTOUT_PI7>;/// A default configuration to map EVENTOUT on PI8 pin
using EVENTOUT_PI8 = AnyAltOut<Port::PI, 8, AfEVENTOUT_PI8>;/// A default configuration to map EVENTOUT on PI9 pin
using EVENTOUT_PI9 = AnyAltOut<Port::PI, 9, AfEVENTOUT_PI9>;/// A default configuration to map EVENTOUT on PI10 pin
using EVENTOUT_PI10 = AnyAltOut<Port::PI, 10, AfEVENTOUT_PI10>;/// A default configuration to map EVENTOUT on PI11 pin
using EVENTOUT_PI11 = AnyAltOut<Port::PI, 11, AfEVENTOUT_PI11>;#endif	// defined(GPIOI_BASE)


}	// namespace Gpio
}	// namespace Bmt

