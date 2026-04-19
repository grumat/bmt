#pragma once

namespace Bmt
{
namespace Gpio
{


// SYS
using AfMCO_PA8 = AnyAFR<Port::PA, 8, AF::k0>;#if defined(GPIOG_BASE)
using AfMCO_PG10 = AnyAFR<Port::PG, 10, AF::k0>;#endif	// defined(GPIOG_BASE)
using AfJTCK_PA14 = AnyAFR<Port::PA, 14, AF::k0>;using AfJTDI_PA15 = AnyAFR<Port::PA, 15, AF::k0>;using AfJTDO_PB3 = AnyAFR<Port::PB, 3, AF::k0>;using AfJTMS_PA13 = AnyAFR<Port::PA, 13, AF::k0>;using AfJTRST_PB4 = AnyAFR<Port::PB, 4, AF::k0>;using AfTRACESWO_PB3 = AnyAFR<Port::PB, 3, AF::k0>;#if defined(GPIOE_BASE)
using AfTRACECK_PE2 = AnyAFR<Port::PE, 2, AF::k0>;using AfTRACED0_PE3 = AnyAFR<Port::PE, 3, AF::k0>;using AfTRACED1_PE4 = AnyAFR<Port::PE, 4, AF::k0>;using AfTRACED2_PE5 = AnyAFR<Port::PE, 5, AF::k0>;using AfTRACED3_PE6 = AnyAFR<Port::PE, 6, AF::k0>;#endif	// defined(GPIOE_BASE)
using AfSWCLK_PA14 = AnyAFR<Port::PA, 14, AF::k0>;using AfSWDIO_PA13 = AnyAFR<Port::PA, 13, AF::k0>;
// CAN1
#if defined(CAN1_BASE)
using AfCAN1_RX_PA11 = AnyAFR<Port::PA, 11, AF::k9>;using AfCAN1_RX_PB8 = AnyAFR<Port::PB, 8, AF::k9>;using AfCAN1_TX_PA12 = AnyAFR<Port::PA, 12, AF::k9>;using AfCAN1_TX_PB9 = AnyAFR<Port::PB, 9, AF::k9>;#if defined(GPIOD_BASE)
using AfCAN1_RX_PD0 = AnyAFR<Port::PD, 0, AF::k9>;using AfCAN1_TX_PD1 = AnyAFR<Port::PD, 1, AF::k9>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfCAN1_RXFD_PE0 = AnyAFR<Port::PE, 0, AF::k9>;#endif	// defined(GPIOE_BASE)
#endif	// defined(CAN1_BASE)

// CAN2
#if defined(CAN2_BASE)
using AfCAN2_RX_PB5 = AnyAFR<Port::PB, 5, AF::k9>;using AfCAN2_RX_PB12 = AnyAFR<Port::PB, 12, AF::k9>;using AfCAN2_TX_PB6 = AnyAFR<Port::PB, 6, AF::k9>;using AfCAN2_TX_PB13 = AnyAFR<Port::PB, 13, AF::k9>;#endif	// defined(CAN2_BASE)

// CAN3
#if defined(CAN3_BASE)
using AfCAN3_RX_PA8 = AnyAFR<Port::PA, 8, AF::k11>;using AfCAN3_RX_PB3 = AnyAFR<Port::PB, 3, AF::k11>;using AfCAN3_TX_PA15 = AnyAFR<Port::PA, 15, AF::k11>;using AfCAN3_TX_PB4 = AnyAFR<Port::PB, 4, AF::k11>;#endif	// defined(CAN3_BASE)

// COMP1
#if defined(COMP1_BASE)
using AfCOMP1_OUT_PA0 = AnyAFR<Port::PA, 0, AF::k8>;using AfCOMP1_OUT_PA6 = AnyAFR<Port::PA, 6, AF::k8>;using AfCOMP1_OUT_PA11 = AnyAFR<Port::PA, 11, AF::k8>;using AfCOMP1_OUT_PB8 = AnyAFR<Port::PB, 8, AF::k8>;#if defined(GPIOF_BASE)
using AfCOMP1_OUT_PF4 = AnyAFR<Port::PF, 4, AF::k2>;#endif	// defined(GPIOF_BASE)
#endif	// defined(COMP1_BASE)

// COMP2
#if defined(COMP2_BASE)
using AfCOMP2_OUT_PA2 = AnyAFR<Port::PA, 2, AF::k8>;using AfCOMP2_OUT_PA7 = AnyAFR<Port::PA, 7, AF::k8>;using AfCOMP2_OUT_PA12 = AnyAFR<Port::PA, 12, AF::k8>;using AfCOMP2_OUT_PB9 = AnyAFR<Port::PB, 9, AF::k8>;#endif	// defined(COMP2_BASE)

// COMP3
#if defined(COMP3_BASE)
using AfCOMP3_OUT_PB7 = AnyAFR<Port::PB, 7, AF::k8>;using AfCOMP3_OUT_PB15 = AnyAFR<Port::PB, 15, AF::k3>;using AfCOMP3_OUT_PC2 = AnyAFR<Port::PC, 2, AF::k3>;#endif	// defined(COMP3_BASE)

// COMP4
#if defined(COMP4_BASE)
using AfCOMP4_OUT_PB1 = AnyAFR<Port::PB, 1, AF::k8>;using AfCOMP4_OUT_PB6 = AnyAFR<Port::PB, 6, AF::k8>;using AfCOMP4_OUT_PB14 = AnyAFR<Port::PB, 14, AF::k8>;#endif	// defined(COMP4_BASE)

// COMP5
#if defined(COMP5_BASE)
using AfCOMP5_OUT_PA9 = AnyAFR<Port::PA, 9, AF::k8>;using AfCOMP5_OUT_PC7 = AnyAFR<Port::PC, 7, AF::k7>;#endif	// defined(COMP5_BASE)

// COMP6
#if defined(COMP6_BASE)
using AfCOMP6_OUT_PA10 = AnyAFR<Port::PA, 10, AF::k8>;using AfCOMP6_OUT_PC6 = AnyAFR<Port::PC, 6, AF::k7>;#endif	// defined(COMP6_BASE)

// COMP7
#if defined(COMP7_BASE)
using AfCOMP7_OUT_PA8 = AnyAFR<Port::PA, 8, AF::k8>;using AfCOMP7_OUT_PC8 = AnyAFR<Port::PC, 8, AF::k7>;#endif	// defined(COMP7_BASE)

// FMC
#if defined(FMC_BASE)
using AfFMC_NL_PB7 = AnyAFR<Port::PB, 7, AF::k12>;#if defined(GPIOD_BASE)
using AfFMC_A16_PD11 = AnyAFR<Port::PD, 11, AF::k12>;using AfFMC_A17_PD12 = AnyAFR<Port::PD, 12, AF::k12>;using AfFMC_A18_PD13 = AnyAFR<Port::PD, 13, AF::k12>;using AfFMC_CLK_PD3 = AnyAFR<Port::PD, 3, AF::k12>;using AfFMC_D0_PD14 = AnyAFR<Port::PD, 14, AF::k12>;using AfFMC_D1_PD15 = AnyAFR<Port::PD, 15, AF::k12>;using AfFMC_D13_PD8 = AnyAFR<Port::PD, 8, AF::k12>;using AfFMC_D14_PD9 = AnyAFR<Port::PD, 9, AF::k12>;using AfFMC_D15_PD10 = AnyAFR<Port::PD, 10, AF::k12>;using AfFMC_D2_PD0 = AnyAFR<Port::PD, 0, AF::k12>;using AfFMC_D3_PD1 = AnyAFR<Port::PD, 1, AF::k12>;using AfFMC_NCE_PD7 = AnyAFR<Port::PD, 7, AF::k12>;using AfFMC_NE1_PD7 = AnyAFR<Port::PD, 7, AF::k12>;using AfFMC_NOE_PD4 = AnyAFR<Port::PD, 4, AF::k12>;using AfFMC_NWAIT_PD6 = AnyAFR<Port::PD, 6, AF::k12>;using AfFMC_NWE_PD5 = AnyAFR<Port::PD, 5, AF::k12>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfFMC_A19_PE3 = AnyAFR<Port::PE, 3, AF::k12>;using AfFMC_A20_PE4 = AnyAFR<Port::PE, 4, AF::k12>;using AfFMC_A21_PE5 = AnyAFR<Port::PE, 5, AF::k12>;using AfFMC_A22_PE6 = AnyAFR<Port::PE, 6, AF::k12>;using AfFMC_A23_PE2 = AnyAFR<Port::PE, 2, AF::k12>;using AfFMC_D10_PE13 = AnyAFR<Port::PE, 13, AF::k12>;using AfFMC_D11_PE14 = AnyAFR<Port::PE, 14, AF::k12>;using AfFMC_D12_PE15 = AnyAFR<Port::PE, 15, AF::k12>;using AfFMC_D4_PE7 = AnyAFR<Port::PE, 7, AF::k12>;using AfFMC_D5_PE8 = AnyAFR<Port::PE, 8, AF::k12>;using AfFMC_D6_PE9 = AnyAFR<Port::PE, 9, AF::k12>;using AfFMC_D7_PE10 = AnyAFR<Port::PE, 10, AF::k12>;using AfFMC_D8_PE11 = AnyAFR<Port::PE, 11, AF::k12>;using AfFMC_D9_PE12 = AnyAFR<Port::PE, 12, AF::k12>;using AfFMC_NBL0_PE0 = AnyAFR<Port::PE, 0, AF::k12>;using AfFMC_NBL1_PE1 = AnyAFR<Port::PE, 1, AF::k12>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfFMC_A0_PF10 = AnyAFR<Port::PF, 10, AF::k12>;using AfFMC_A1_PF7 = AnyAFR<Port::PF, 7, AF::k12>;using AfFMC_A2_PF2 = AnyAFR<Port::PF, 2, AF::k12>;using AfFMC_A24_PF8 = AnyAFR<Port::PF, 8, AF::k12>;using AfFMC_A25_PF9 = AnyAFR<Port::PF, 9, AF::k12>;using AfFMC_A3_PF3 = AnyAFR<Port::PF, 3, AF::k12>;using AfFMC_A4_PF4 = AnyAFR<Port::PF, 4, AF::k12>;using AfFMC_A5_PF5 = AnyAFR<Port::PF, 5, AF::k12>;using AfFMC_A6_PF12 = AnyAFR<Port::PF, 12, AF::k12>;using AfFMC_A7_PF13 = AnyAFR<Port::PF, 13, AF::k12>;using AfFMC_A8_PF14 = AnyAFR<Port::PF, 14, AF::k12>;using AfFMC_A9_PF15 = AnyAFR<Port::PF, 15, AF::k12>;using AfFMC_NE4_PF11 = AnyAFR<Port::PF, 11, AF::k12>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfFMC_A10_PG0 = AnyAFR<Port::PG, 0, AF::k12>;using AfFMC_A11_PG1 = AnyAFR<Port::PG, 1, AF::k12>;using AfFMC_A12_PG2 = AnyAFR<Port::PG, 2, AF::k12>;using AfFMC_A13_PG3 = AnyAFR<Port::PG, 3, AF::k12>;using AfFMC_A14_PG4 = AnyAFR<Port::PG, 4, AF::k12>;using AfFMC_A15_PG5 = AnyAFR<Port::PG, 5, AF::k12>;using AfFMC_INT_PG6 = AnyAFR<Port::PG, 6, AF::k12>;using AfFMC_INT_PG7 = AnyAFR<Port::PG, 7, AF::k12>;using AfFMC_NCE_PG9 = AnyAFR<Port::PG, 9, AF::k12>;using AfFMC_NE2_PG9 = AnyAFR<Port::PG, 9, AF::k12>;using AfFMC_NE3_PG8 = AnyAFR<Port::PG, 8, AF::k12>;#endif	// defined(GPIOG_BASE)
#endif	// defined(FMC_BASE)

// HRTIM1
#if defined(HRTIM1_BASE)
using AfHRTIM1_CHA1_PA8 = AnyAFR<Port::PA, 8, AF::k13>;using AfHRTIM1_CHA2_PA9 = AnyAFR<Port::PA, 9, AF::k13>;using AfHRTIM1_CHB1_PA10 = AnyAFR<Port::PA, 10, AF::k13>;using AfHRTIM1_CHB2_PA11 = AnyAFR<Port::PA, 11, AF::k13>;using AfHRTIM1_CHC1_PB12 = AnyAFR<Port::PB, 12, AF::k13>;using AfHRTIM1_CHC2_PB13 = AnyAFR<Port::PB, 13, AF::k13>;using AfHRTIM1_CHD1_PB14 = AnyAFR<Port::PB, 14, AF::k13>;using AfHRTIM1_CHD2_PB15 = AnyAFR<Port::PB, 15, AF::k13>;using AfHRTIM1_CHE1_PC8 = AnyAFR<Port::PC, 8, AF::k3>;using AfHRTIM1_CHE2_PC9 = AnyAFR<Port::PC, 9, AF::k3>;using AfHRTIM1_CHF1_PC6 = AnyAFR<Port::PC, 6, AF::k13>;using AfHRTIM1_CHF2_PC7 = AnyAFR<Port::PC, 7, AF::k13>;using AfHRTIM1_EEV1_PC12 = AnyAFR<Port::PC, 12, AF::k3>;using AfHRTIM1_EEV10_PC5 = AnyAFR<Port::PC, 5, AF::k13>;using AfHRTIM1_EEV10_PC6 = AnyAFR<Port::PC, 6, AF::k3>;using AfHRTIM1_EEV2_PC11 = AnyAFR<Port::PC, 11, AF::k3>;using AfHRTIM1_EEV3_PB7 = AnyAFR<Port::PB, 7, AF::k13>;using AfHRTIM1_EEV4_PB6 = AnyAFR<Port::PB, 6, AF::k13>;using AfHRTIM1_EEV5_PB9 = AnyAFR<Port::PB, 9, AF::k13>;using AfHRTIM1_EEV6_PB5 = AnyAFR<Port::PB, 5, AF::k13>;using AfHRTIM1_EEV7_PB4 = AnyAFR<Port::PB, 4, AF::k13>;using AfHRTIM1_EEV8_PB8 = AnyAFR<Port::PB, 8, AF::k13>;using AfHRTIM1_EEV9_PB3 = AnyAFR<Port::PB, 3, AF::k13>;using AfHRTIM1_FLT1_PA12 = AnyAFR<Port::PA, 12, AF::k13>;using AfHRTIM1_FLT2_PA15 = AnyAFR<Port::PA, 15, AF::k13>;using AfHRTIM1_FLT3_PB10 = AnyAFR<Port::PB, 10, AF::k13>;using AfHRTIM1_FLT4_PB11 = AnyAFR<Port::PB, 11, AF::k13>;using AfHRTIM1_FLT5_PB0 = AnyAFR<Port::PB, 0, AF::k13>;using AfHRTIM1_FLT5_PC7 = AnyAFR<Port::PC, 7, AF::k3>;using AfHRTIM1_FLT6_PC10 = AnyAFR<Port::PC, 10, AF::k13>;using AfHRTIM1_SCIN_PB2 = AnyAFR<Port::PB, 2, AF::k13>;using AfHRTIM1_SCIN_PB6 = AnyAFR<Port::PB, 6, AF::k12>;using AfHRTIM1_SCOUT_PB1 = AnyAFR<Port::PB, 1, AF::k13>;using AfHRTIM1_SCOUT_PB3 = AnyAFR<Port::PB, 3, AF::k12>;#endif	// defined(HRTIM1_BASE)

// IR
#if defined(TIM16_BASE)
using AfIR_OUT_PA13 = AnyAFR<Port::PA, 13, AF::k5>;using AfIR_OUT_PB9 = AnyAFR<Port::PB, 9, AF::k6>;#endif	// defined(TIM16_BASE)

// I2C1
#if defined(I2C1_BASE)
using AfI2C1_SCL_PA13 = AnyAFR<Port::PA, 13, AF::k4>;using AfI2C1_SCL_PA15 = AnyAFR<Port::PA, 15, AF::k4>;using AfI2C1_SCL_PB8 = AnyAFR<Port::PB, 8, AF::k4>;using AfI2C1_SDA_PA14 = AnyAFR<Port::PA, 14, AF::k4>;using AfI2C1_SDA_PB7 = AnyAFR<Port::PB, 7, AF::k4>;using AfI2C1_SDA_PB9 = AnyAFR<Port::PB, 9, AF::k4>;using AfI2C1_SMBA_PB5 = AnyAFR<Port::PB, 5, AF::k4>;#endif	// defined(I2C1_BASE)

// I2C2
#if defined(I2C2_BASE)
using AfI2C2_SCL_PA9 = AnyAFR<Port::PA, 9, AF::k4>;using AfI2C2_SCL_PC4 = AnyAFR<Port::PC, 4, AF::k4>;using AfI2C2_SDA_PA8 = AnyAFR<Port::PA, 8, AF::k4>;using AfI2C2_SMBA_PA10 = AnyAFR<Port::PA, 10, AF::k4>;using AfI2C2_SMBA_PB12 = AnyAFR<Port::PB, 12, AF::k4>;#if defined(GPIOF_BASE)
using AfI2C2_SCL_PF6 = AnyAFR<Port::PF, 6, AF::k4>;using AfI2C2_SDA_PF0 = AnyAFR<Port::PF, 0, AF::k4>;using AfI2C2_SMBA_PF2 = AnyAFR<Port::PF, 2, AF::k4>;#endif	// defined(GPIOF_BASE)
#endif	// defined(I2C2_BASE)

// I2C3
#if defined(I2C3_BASE)
using AfI2C3_SCL_PA8 = AnyAFR<Port::PA, 8, AF::k2>;using AfI2C3_SCL_PC8 = AnyAFR<Port::PC, 8, AF::k8>;using AfI2C3_SDA_PB5 = AnyAFR<Port::PB, 5, AF::k8>;using AfI2C3_SDA_PC9 = AnyAFR<Port::PC, 9, AF::k8>;using AfI2C3_SDA_PC11 = AnyAFR<Port::PC, 11, AF::k8>;using AfI2C3_SMBA_PA9 = AnyAFR<Port::PA, 9, AF::k2>;using AfI2C3_SMBA_PB2 = AnyAFR<Port::PB, 2, AF::k4>;#if defined(GPIOF_BASE)
using AfI2C3_SCL_PF3 = AnyAFR<Port::PF, 3, AF::k4>;using AfI2C3_SDA_PF4 = AnyAFR<Port::PF, 4, AF::k4>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfI2C3_SCL_PG7 = AnyAFR<Port::PG, 7, AF::k4>;using AfI2C3_SDA_PG8 = AnyAFR<Port::PG, 8, AF::k4>;using AfI2C3_SMBA_PG6 = AnyAFR<Port::PG, 6, AF::k4>;#endif	// defined(GPIOG_BASE)
#endif	// defined(I2C3_BASE)

// I2C4
#if defined(I2C4_BASE)
using AfI2C4_SCL_PA13 = AnyAFR<Port::PA, 13, AF::k3>;using AfI2C4_SCL_PC6 = AnyAFR<Port::PC, 6, AF::k8>;using AfI2C4_SDA_PB7 = AnyAFR<Port::PB, 7, AF::k3>;using AfI2C4_SDA_PC7 = AnyAFR<Port::PC, 7, AF::k8>;using AfI2C4_SMBA_PA14 = AnyAFR<Port::PA, 14, AF::k3>;#if defined(GPIOD_BASE)
using AfI2C4_SMBA_PD11 = AnyAFR<Port::PD, 11, AF::k4>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOF_BASE)
using AfI2C4_SCL_PF14 = AnyAFR<Port::PF, 14, AF::k4>;using AfI2C4_SDA_PF15 = AnyAFR<Port::PF, 15, AF::k4>;using AfI2C4_SMBA_PF13 = AnyAFR<Port::PF, 13, AF::k4>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfI2C4_SCL_PG3 = AnyAFR<Port::PG, 3, AF::k4>;using AfI2C4_SDA_PG4 = AnyAFR<Port::PG, 4, AF::k4>;#endif	// defined(GPIOG_BASE)
#endif	// defined(I2C4_BASE)

// I2S2
#if defined(I2S2_BASE)
using AfI2S2_CK_PB13 = AnyAFR<Port::PB, 13, AF::k5>;using AfI2S2_MCK_PA8 = AnyAFR<Port::PA, 8, AF::k5>;using AfI2S2_MCK_PC6 = AnyAFR<Port::PC, 6, AF::k6>;using AfI2S2_SD_PA11 = AnyAFR<Port::PA, 11, AF::k5>;using AfI2S2_SD_PB15 = AnyAFR<Port::PB, 15, AF::k5>;using AfI2S2_WS_PB12 = AnyAFR<Port::PB, 12, AF::k5>;#if defined(GPIOF_BASE)
using AfI2S2_CK_PF1 = AnyAFR<Port::PF, 1, AF::k5>;using AfI2S2_WS_PF0 = AnyAFR<Port::PF, 0, AF::k5>;#endif	// defined(GPIOF_BASE)
#endif	// defined(I2S2_BASE)

// I2S3
#if defined(I2S3_BASE)
using AfI2S3_CK_PB3 = AnyAFR<Port::PB, 3, AF::k6>;using AfI2S3_CK_PC10 = AnyAFR<Port::PC, 10, AF::k6>;using AfI2S3_MCK_PA9 = AnyAFR<Port::PA, 9, AF::k5>;using AfI2S3_MCK_PC7 = AnyAFR<Port::PC, 7, AF::k6>;using AfI2S3_SD_PB5 = AnyAFR<Port::PB, 5, AF::k6>;using AfI2S3_SD_PC12 = AnyAFR<Port::PC, 12, AF::k6>;using AfI2S3_WS_PA4 = AnyAFR<Port::PA, 4, AF::k6>;using AfI2S3_WS_PA15 = AnyAFR<Port::PA, 15, AF::k6>;#endif	// defined(I2S3_BASE)

// I2SCKIN
#if defined(SPI_I2S_SUPPORT)
using AfI2SCKIN_PA12 = AnyAFR<Port::PA, 12, AF::k5>;using AfI2SCKIN_PC9 = AnyAFR<Port::PC, 9, AF::k5>;#endif	// defined(SPI_I2S_SUPPORT)

// LPTIM1
#if defined(LPTIM1_BASE)
using AfLPTIM1_ETR_PB6 = AnyAFR<Port::PB, 6, AF::k11>;using AfLPTIM1_ETR_PC3 = AnyAFR<Port::PC, 3, AF::k1>;using AfLPTIM1_IN1_PB5 = AnyAFR<Port::PB, 5, AF::k11>;using AfLPTIM1_IN1_PC0 = AnyAFR<Port::PC, 0, AF::k1>;using AfLPTIM1_IN2_PB7 = AnyAFR<Port::PB, 7, AF::k11>;using AfLPTIM1_IN2_PC2 = AnyAFR<Port::PC, 2, AF::k1>;using AfLPTIM1_OUT_PA14 = AnyAFR<Port::PA, 14, AF::k1>;using AfLPTIM1_OUT_PB2 = AnyAFR<Port::PB, 2, AF::k1>;using AfLPTIM1_OUT_PC1 = AnyAFR<Port::PC, 1, AF::k1>;#endif	// defined(LPTIM1_BASE)

// LPUART1
#if defined(LPUART1_BASE)
using AfLPUART1_CTS_PA6 = AnyAFR<Port::PA, 6, AF::k12>;using AfLPUART1_CTS_PB13 = AnyAFR<Port::PB, 13, AF::k8>;using AfLPUART1_RTS_DE_PB1 = AnyAFR<Port::PB, 1, AF::k12>;using AfLPUART1_RTS_DE_PB12 = AnyAFR<Port::PB, 12, AF::k8>;using AfLPUART1_RX_PA3 = AnyAFR<Port::PA, 3, AF::k12>;using AfLPUART1_RX_PB10 = AnyAFR<Port::PB, 10, AF::k8>;using AfLPUART1_RX_PC0 = AnyAFR<Port::PC, 0, AF::k8>;using AfLPUART1_TX_PA2 = AnyAFR<Port::PA, 2, AF::k12>;using AfLPUART1_TX_PB11 = AnyAFR<Port::PB, 11, AF::k8>;using AfLPUART1_TX_PC1 = AnyAFR<Port::PC, 1, AF::k8>;#if defined(GPIOG_BASE)
using AfLPUART1_CTS_PG5 = AnyAFR<Port::PG, 5, AF::k8>;using AfLPUART1_RTS_DE_PG6 = AnyAFR<Port::PG, 6, AF::k8>;using AfLPUART1_RX_PG8 = AnyAFR<Port::PG, 8, AF::k8>;using AfLPUART1_TX_PG7 = AnyAFR<Port::PG, 7, AF::k8>;#endif	// defined(GPIOG_BASE)
#endif	// defined(LPUART1_BASE)

// QUADSPI1
#if defined(QUADSPI)
using AfQUADSPI1_BK1_IO0_PB1 = AnyAFR<Port::PB, 1, AF::k10>;using AfQUADSPI1_BK1_IO1_PB0 = AnyAFR<Port::PB, 0, AF::k10>;using AfQUADSPI1_BK1_IO2_PA7 = AnyAFR<Port::PA, 7, AF::k10>;using AfQUADSPI1_BK1_IO3_PA6 = AnyAFR<Port::PA, 6, AF::k10>;using AfQUADSPI1_BK1_NCS_PA2 = AnyAFR<Port::PA, 2, AF::k10>;using AfQUADSPI1_BK1_NCS_PB11 = AnyAFR<Port::PB, 11, AF::k10>;using AfQUADSPI1_BK2_IO0_PC1 = AnyAFR<Port::PC, 1, AF::k10>;using AfQUADSPI1_BK2_IO1_PB2 = AnyAFR<Port::PB, 2, AF::k10>;using AfQUADSPI1_BK2_IO1_PC2 = AnyAFR<Port::PC, 2, AF::k10>;using AfQUADSPI1_BK2_IO2_PC3 = AnyAFR<Port::PC, 3, AF::k10>;using AfQUADSPI1_BK2_IO3_PC4 = AnyAFR<Port::PC, 4, AF::k10>;using AfQUADSPI1_CLK_PA3 = AnyAFR<Port::PA, 3, AF::k10>;using AfQUADSPI1_CLK_PB10 = AnyAFR<Port::PB, 10, AF::k10>;#if defined(GPIOD_BASE)
using AfQUADSPI1_BK2_IO0_PD4 = AnyAFR<Port::PD, 4, AF::k10>;using AfQUADSPI1_BK2_IO1_PD5 = AnyAFR<Port::PD, 5, AF::k10>;using AfQUADSPI1_BK2_IO2_PD6 = AnyAFR<Port::PD, 6, AF::k10>;using AfQUADSPI1_BK2_IO3_PD7 = AnyAFR<Port::PD, 7, AF::k10>;using AfQUADSPI1_BK2_NCS_PD3 = AnyAFR<Port::PD, 3, AF::k10>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfQUADSPI1_BK1_IO0_PE12 = AnyAFR<Port::PE, 12, AF::k10>;using AfQUADSPI1_BK1_IO1_PE13 = AnyAFR<Port::PE, 13, AF::k10>;using AfQUADSPI1_BK1_IO2_PE14 = AnyAFR<Port::PE, 14, AF::k10>;using AfQUADSPI1_BK1_IO3_PE15 = AnyAFR<Port::PE, 15, AF::k10>;using AfQUADSPI1_BK1_NCS_PE11 = AnyAFR<Port::PE, 11, AF::k10>;using AfQUADSPI1_CLK_PE10 = AnyAFR<Port::PE, 10, AF::k10>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfQUADSPI1_BK1_IO0_PF8 = AnyAFR<Port::PF, 8, AF::k10>;using AfQUADSPI1_BK1_IO1_PF9 = AnyAFR<Port::PF, 9, AF::k10>;using AfQUADSPI1_BK1_IO2_PF7 = AnyAFR<Port::PF, 7, AF::k10>;using AfQUADSPI1_BK1_IO3_PF6 = AnyAFR<Port::PF, 6, AF::k10>;using AfQUADSPI1_CLK_PF10 = AnyAFR<Port::PF, 10, AF::k10>;#endif	// defined(GPIOF_BASE)
#endif	// defined(QUADSPI)

// RTC
#if defined(RTC_BASE)
using AfRTC_OUT2_PB2 = AnyAFR<Port::PB, 2, AF::k0>;using AfRTC_REFIN_PA1 = AnyAFR<Port::PA, 1, AF::k0>;using AfRTC_REFIN_PB15 = AnyAFR<Port::PB, 15, AF::k0>;#endif	// defined(RTC_BASE)

// SAI1
#if defined(SAI1_BASE)
using AfSAI1_CK1_PA3 = AnyAFR<Port::PA, 3, AF::k3>;using AfSAI1_CK1_PB8 = AnyAFR<Port::PB, 8, AF::k3>;using AfSAI1_CK2_PA8 = AnyAFR<Port::PA, 8, AF::k12>;using AfSAI1_D1_PA10 = AnyAFR<Port::PA, 10, AF::k12>;using AfSAI1_D1_PC3 = AnyAFR<Port::PC, 3, AF::k3>;using AfSAI1_D2_PB9 = AnyAFR<Port::PB, 9, AF::k3>;using AfSAI1_D3_PC5 = AnyAFR<Port::PC, 5, AF::k3>;using AfSAI1_FS_A_PA9 = AnyAFR<Port::PA, 9, AF::k14>;using AfSAI1_FS_A_PB9 = AnyAFR<Port::PB, 9, AF::k14>;using AfSAI1_FS_B_PA4 = AnyAFR<Port::PA, 4, AF::k13>;using AfSAI1_FS_B_PA14 = AnyAFR<Port::PA, 14, AF::k13>;using AfSAI1_FS_B_PB6 = AnyAFR<Port::PB, 6, AF::k14>;using AfSAI1_MCLK_A_PA3 = AnyAFR<Port::PA, 3, AF::k13>;using AfSAI1_MCLK_A_PB8 = AnyAFR<Port::PB, 8, AF::k14>;using AfSAI1_MCLK_B_PB4 = AnyAFR<Port::PB, 4, AF::k14>;using AfSAI1_SCK_A_PA8 = AnyAFR<Port::PA, 8, AF::k14>;using AfSAI1_SCK_A_PB10 = AnyAFR<Port::PB, 10, AF::k14>;using AfSAI1_SCK_B_PB3 = AnyAFR<Port::PB, 3, AF::k14>;using AfSAI1_SD_A_PA10 = AnyAFR<Port::PA, 10, AF::k14>;using AfSAI1_SD_A_PC1 = AnyAFR<Port::PC, 1, AF::k13>;using AfSAI1_SD_A_PC3 = AnyAFR<Port::PC, 3, AF::k13>;using AfSAI1_SD_B_PA13 = AnyAFR<Port::PA, 13, AF::k13>;using AfSAI1_SD_B_PB5 = AnyAFR<Port::PB, 5, AF::k12>;#if defined(GPIOD_BASE)
using AfSAI1_D1_PD6 = AnyAFR<Port::PD, 6, AF::k3>;using AfSAI1_SD_A_PD6 = AnyAFR<Port::PD, 6, AF::k13>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfSAI1_CK1_PE2 = AnyAFR<Port::PE, 2, AF::k3>;using AfSAI1_CK2_PE5 = AnyAFR<Port::PE, 5, AF::k3>;using AfSAI1_D1_PE6 = AnyAFR<Port::PE, 6, AF::k3>;using AfSAI1_D2_PE4 = AnyAFR<Port::PE, 4, AF::k3>;using AfSAI1_FS_A_PE4 = AnyAFR<Port::PE, 4, AF::k13>;using AfSAI1_FS_B_PE9 = AnyAFR<Port::PE, 9, AF::k13>;using AfSAI1_MCLK_A_PE2 = AnyAFR<Port::PE, 2, AF::k13>;using AfSAI1_MCLK_B_PE10 = AnyAFR<Port::PE, 10, AF::k13>;using AfSAI1_SCK_A_PE5 = AnyAFR<Port::PE, 5, AF::k13>;using AfSAI1_SCK_B_PE8 = AnyAFR<Port::PE, 8, AF::k13>;using AfSAI1_SD_A_PE6 = AnyAFR<Port::PE, 6, AF::k13>;using AfSAI1_SD_B_PE3 = AnyAFR<Port::PE, 3, AF::k13>;using AfSAI1_SD_B_PE7 = AnyAFR<Port::PE, 7, AF::k13>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfSAI1_D3_PF10 = AnyAFR<Port::PF, 10, AF::k13>;using AfSAI1_FS_B_PF9 = AnyAFR<Port::PF, 9, AF::k13>;using AfSAI1_MCLK_B_PF7 = AnyAFR<Port::PF, 7, AF::k13>;using AfSAI1_SCK_B_PF8 = AnyAFR<Port::PF, 8, AF::k13>;using AfSAI1_SD_B_PF6 = AnyAFR<Port::PF, 6, AF::k3>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfSAI1_CK1_PG7 = AnyAFR<Port::PG, 7, AF::k3>;using AfSAI1_MCLK_A_PG7 = AnyAFR<Port::PG, 7, AF::k13>;#endif	// defined(GPIOG_BASE)
#endif	// defined(SAI1_BASE)

// SPI1
#if defined(SPI1_BASE)
using AfSPI1_MISO_PA6 = AnyAFR<Port::PA, 6, AF::k5>;using AfSPI1_MISO_PB4 = AnyAFR<Port::PB, 4, AF::k5>;using AfSPI1_MOSI_PA7 = AnyAFR<Port::PA, 7, AF::k5>;using AfSPI1_MOSI_PB5 = AnyAFR<Port::PB, 5, AF::k5>;using AfSPI1_NSS_PA4 = AnyAFR<Port::PA, 4, AF::k5>;using AfSPI1_NSS_PA15 = AnyAFR<Port::PA, 15, AF::k5>;using AfSPI1_SCK_PA5 = AnyAFR<Port::PA, 5, AF::k5>;using AfSPI1_SCK_PB3 = AnyAFR<Port::PB, 3, AF::k5>;#if defined(GPIOG_BASE)
using AfSPI1_MISO_PG3 = AnyAFR<Port::PG, 3, AF::k5>;using AfSPI1_MOSI_PG4 = AnyAFR<Port::PG, 4, AF::k5>;using AfSPI1_NSS_PG5 = AnyAFR<Port::PG, 5, AF::k5>;using AfSPI1_SCK_PG2 = AnyAFR<Port::PG, 2, AF::k5>;#endif	// defined(GPIOG_BASE)
#endif	// defined(SPI1_BASE)

// SPI2
#if defined(SPI2_BASE)
using AfSPI2_MISO_PA10 = AnyAFR<Port::PA, 10, AF::k5>;using AfSPI2_MISO_PB14 = AnyAFR<Port::PB, 14, AF::k5>;using AfSPI2_MOSI_PA11 = AnyAFR<Port::PA, 11, AF::k5>;using AfSPI2_MOSI_PB15 = AnyAFR<Port::PB, 15, AF::k5>;using AfSPI2_NSS_PB12 = AnyAFR<Port::PB, 12, AF::k5>;using AfSPI2_SCK_PB13 = AnyAFR<Port::PB, 13, AF::k5>;#if defined(GPIOD_BASE)
using AfSPI2_NSS_PD15 = AnyAFR<Port::PD, 15, AF::k6>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOF_BASE)
using AfSPI2_NSS_PF0 = AnyAFR<Port::PF, 0, AF::k5>;using AfSPI2_SCK_PF1 = AnyAFR<Port::PF, 1, AF::k5>;using AfSPI2_SCK_PF9 = AnyAFR<Port::PF, 9, AF::k5>;using AfSPI2_SCK_PF10 = AnyAFR<Port::PF, 10, AF::k5>;#endif	// defined(GPIOF_BASE)
#endif	// defined(SPI2_BASE)

// SPI3
#if defined(SPI3_BASE)
using AfSPI3_MISO_PB4 = AnyAFR<Port::PB, 4, AF::k6>;using AfSPI3_MISO_PC11 = AnyAFR<Port::PC, 11, AF::k6>;using AfSPI3_MOSI_PB5 = AnyAFR<Port::PB, 5, AF::k6>;using AfSPI3_MOSI_PC12 = AnyAFR<Port::PC, 12, AF::k6>;using AfSPI3_NSS_PA4 = AnyAFR<Port::PA, 4, AF::k6>;using AfSPI3_NSS_PA15 = AnyAFR<Port::PA, 15, AF::k6>;using AfSPI3_SCK_PB3 = AnyAFR<Port::PB, 3, AF::k6>;using AfSPI3_SCK_PC10 = AnyAFR<Port::PC, 10, AF::k6>;#if defined(GPIOG_BASE)
using AfSPI3_SCK_PG9 = AnyAFR<Port::PG, 9, AF::k6>;#endif	// defined(GPIOG_BASE)
#endif	// defined(SPI3_BASE)

// SPI4
#if defined(SPI4_BASE)
#if defined(GPIOE_BASE)
using AfSPI4_MISO_PE5 = AnyAFR<Port::PE, 5, AF::k5>;using AfSPI4_MISO_PE13 = AnyAFR<Port::PE, 13, AF::k5>;using AfSPI4_MOSI_PE6 = AnyAFR<Port::PE, 6, AF::k5>;using AfSPI4_MOSI_PE14 = AnyAFR<Port::PE, 14, AF::k5>;using AfSPI4_NSS_PE3 = AnyAFR<Port::PE, 3, AF::k5>;using AfSPI4_NSS_PE4 = AnyAFR<Port::PE, 4, AF::k5>;using AfSPI4_NSS_PE11 = AnyAFR<Port::PE, 11, AF::k5>;using AfSPI4_SCK_PE2 = AnyAFR<Port::PE, 2, AF::k5>;using AfSPI4_SCK_PE12 = AnyAFR<Port::PE, 12, AF::k5>;#endif	// defined(GPIOE_BASE)
#endif	// defined(SPI4_BASE)

// TIM1
#if defined(TIM1_BASE)
using AfTIM1_BKIN_PA6 = AnyAFR<Port::PA, 6, AF::k6>;using AfTIM1_BKIN_PA14 = AnyAFR<Port::PA, 14, AF::k6>;using AfTIM1_BKIN_PA15 = AnyAFR<Port::PA, 15, AF::k9>;using AfTIM1_BKIN_PB8 = AnyAFR<Port::PB, 8, AF::k12>;using AfTIM1_BKIN_PB10 = AnyAFR<Port::PB, 10, AF::k12>;using AfTIM1_BKIN_PB12 = AnyAFR<Port::PB, 12, AF::k6>;using AfTIM1_BKIN_PC13 = AnyAFR<Port::PC, 13, AF::k2>;using AfTIM1_BKIN2_PA11 = AnyAFR<Port::PA, 11, AF::k12>;using AfTIM1_BKIN2_PC3 = AnyAFR<Port::PC, 3, AF::k6>;using AfTIM1_CH1_PA8 = AnyAFR<Port::PA, 8, AF::k6>;using AfTIM1_CH1_PC0 = AnyAFR<Port::PC, 0, AF::k2>;using AfTIM1_CH1N_PA7 = AnyAFR<Port::PA, 7, AF::k6>;using AfTIM1_CH1N_PA11 = AnyAFR<Port::PA, 11, AF::k6>;using AfTIM1_CH1N_PB13 = AnyAFR<Port::PB, 13, AF::k6>;using AfTIM1_CH1N_PC13 = AnyAFR<Port::PC, 13, AF::k4>;using AfTIM1_CH2_PA9 = AnyAFR<Port::PA, 9, AF::k6>;using AfTIM1_CH2_PC1 = AnyAFR<Port::PC, 1, AF::k2>;using AfTIM1_CH2N_PA12 = AnyAFR<Port::PA, 12, AF::k6>;using AfTIM1_CH2N_PB0 = AnyAFR<Port::PB, 0, AF::k6>;using AfTIM1_CH2N_PB14 = AnyAFR<Port::PB, 14, AF::k6>;using AfTIM1_CH3_PA10 = AnyAFR<Port::PA, 10, AF::k6>;using AfTIM1_CH3_PC2 = AnyAFR<Port::PC, 2, AF::k2>;using AfTIM1_CH3N_PB1 = AnyAFR<Port::PB, 1, AF::k6>;using AfTIM1_CH3N_PB9 = AnyAFR<Port::PB, 9, AF::k12>;using AfTIM1_CH3N_PB15 = AnyAFR<Port::PB, 15, AF::k4>;using AfTIM1_CH4_PA11 = AnyAFR<Port::PA, 11, AF::k11>;using AfTIM1_CH4_PC3 = AnyAFR<Port::PC, 3, AF::k2>;using AfTIM1_CH4N_PC5 = AnyAFR<Port::PC, 5, AF::k6>;using AfTIM1_ETR_PA12 = AnyAFR<Port::PA, 12, AF::k11>;using AfTIM1_ETR_PC4 = AnyAFR<Port::PC, 4, AF::k2>;#if defined(GPIOE_BASE)
using AfTIM1_BKIN_PE15 = AnyAFR<Port::PE, 15, AF::k2>;using AfTIM1_BKIN2_PE14 = AnyAFR<Port::PE, 14, AF::k6>;using AfTIM1_CH1_PE9 = AnyAFR<Port::PE, 9, AF::k2>;using AfTIM1_CH1N_PE8 = AnyAFR<Port::PE, 8, AF::k2>;using AfTIM1_CH2_PE11 = AnyAFR<Port::PE, 11, AF::k2>;using AfTIM1_CH2N_PE10 = AnyAFR<Port::PE, 10, AF::k2>;using AfTIM1_CH3_PE13 = AnyAFR<Port::PE, 13, AF::k2>;using AfTIM1_CH3N_PE12 = AnyAFR<Port::PE, 12, AF::k2>;using AfTIM1_CH4_PE14 = AnyAFR<Port::PE, 14, AF::k2>;using AfTIM1_CH4N_PE15 = AnyAFR<Port::PE, 15, AF::k6>;using AfTIM1_ETR_PE7 = AnyAFR<Port::PE, 7, AF::k2>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfTIM1_CH3N_PF0 = AnyAFR<Port::PF, 0, AF::k6>;#endif	// defined(GPIOF_BASE)
#endif	// defined(TIM1_BASE)

// TIM2
#if defined(TIM2_BASE)
using AfTIM2_CH1_PA0 = AnyAFR<Port::PA, 0, AF::k1>;using AfTIM2_CH1_PA5 = AnyAFR<Port::PA, 5, AF::k1>;using AfTIM2_CH1_PA15 = AnyAFR<Port::PA, 15, AF::k1>;using AfTIM2_CH2_PA1 = AnyAFR<Port::PA, 1, AF::k1>;using AfTIM2_CH2_PB3 = AnyAFR<Port::PB, 3, AF::k1>;using AfTIM2_CH3_PA2 = AnyAFR<Port::PA, 2, AF::k1>;using AfTIM2_CH3_PA9 = AnyAFR<Port::PA, 9, AF::k10>;using AfTIM2_CH3_PB10 = AnyAFR<Port::PB, 10, AF::k1>;using AfTIM2_CH4_PA3 = AnyAFR<Port::PA, 3, AF::k1>;using AfTIM2_CH4_PA10 = AnyAFR<Port::PA, 10, AF::k10>;using AfTIM2_CH4_PB11 = AnyAFR<Port::PB, 11, AF::k1>;using AfTIM2_ETR_PA0 = AnyAFR<Port::PA, 0, AF::k14>;using AfTIM2_ETR_PA5 = AnyAFR<Port::PA, 5, AF::k2>;using AfTIM2_ETR_PA15 = AnyAFR<Port::PA, 15, AF::k14>;#if defined(GPIOD_BASE)
using AfTIM2_CH1_PD3 = AnyAFR<Port::PD, 3, AF::k2>;using AfTIM2_CH2_PD4 = AnyAFR<Port::PD, 4, AF::k2>;using AfTIM2_CH3_PD7 = AnyAFR<Port::PD, 7, AF::k2>;using AfTIM2_CH4_PD6 = AnyAFR<Port::PD, 6, AF::k2>;using AfTIM2_ETR_PD3 = AnyAFR<Port::PD, 3, AF::k2>;#endif	// defined(GPIOD_BASE)
#endif	// defined(TIM2_BASE)

// TIM3
#if defined(TIM3_BASE)
using AfTIM3_CH1_PA6 = AnyAFR<Port::PA, 6, AF::k2>;using AfTIM3_CH1_PB4 = AnyAFR<Port::PB, 4, AF::k2>;using AfTIM3_CH1_PC6 = AnyAFR<Port::PC, 6, AF::k2>;using AfTIM3_CH2_PA4 = AnyAFR<Port::PA, 4, AF::k2>;using AfTIM3_CH2_PA7 = AnyAFR<Port::PA, 7, AF::k2>;using AfTIM3_CH2_PB5 = AnyAFR<Port::PB, 5, AF::k2>;using AfTIM3_CH2_PC7 = AnyAFR<Port::PC, 7, AF::k2>;using AfTIM3_CH3_PB0 = AnyAFR<Port::PB, 0, AF::k2>;using AfTIM3_CH3_PC8 = AnyAFR<Port::PC, 8, AF::k2>;using AfTIM3_CH4_PB1 = AnyAFR<Port::PB, 1, AF::k2>;using AfTIM3_CH4_PB7 = AnyAFR<Port::PB, 7, AF::k10>;using AfTIM3_CH4_PC9 = AnyAFR<Port::PC, 9, AF::k2>;using AfTIM3_ETR_PB3 = AnyAFR<Port::PB, 3, AF::k10>;#if defined(GPIOD_BASE)
using AfTIM3_ETR_PD2 = AnyAFR<Port::PD, 2, AF::k2>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfTIM3_CH1_PE2 = AnyAFR<Port::PE, 2, AF::k2>;using AfTIM3_CH2_PE3 = AnyAFR<Port::PE, 3, AF::k2>;using AfTIM3_CH3_PE4 = AnyAFR<Port::PE, 4, AF::k2>;using AfTIM3_CH4_PE5 = AnyAFR<Port::PE, 5, AF::k2>;#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM3_BASE)

// TIM4
#if defined(TIM4_BASE)
using AfTIM4_CH1_PA11 = AnyAFR<Port::PA, 11, AF::k10>;using AfTIM4_CH1_PB6 = AnyAFR<Port::PB, 6, AF::k2>;using AfTIM4_CH2_PA12 = AnyAFR<Port::PA, 12, AF::k10>;using AfTIM4_CH2_PB7 = AnyAFR<Port::PB, 7, AF::k2>;using AfTIM4_CH3_PA13 = AnyAFR<Port::PA, 13, AF::k10>;using AfTIM4_CH3_PB8 = AnyAFR<Port::PB, 8, AF::k2>;using AfTIM4_CH4_PB9 = AnyAFR<Port::PB, 9, AF::k2>;using AfTIM4_ETR_PA8 = AnyAFR<Port::PA, 8, AF::k10>;using AfTIM4_ETR_PB3 = AnyAFR<Port::PB, 3, AF::k2>;#if defined(GPIOD_BASE)
using AfTIM4_CH1_PD12 = AnyAFR<Port::PD, 12, AF::k2>;using AfTIM4_CH2_PD13 = AnyAFR<Port::PD, 13, AF::k2>;using AfTIM4_CH3_PD14 = AnyAFR<Port::PD, 14, AF::k2>;using AfTIM4_CH4_PD15 = AnyAFR<Port::PD, 15, AF::k2>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfTIM4_ETR_PE0 = AnyAFR<Port::PE, 0, AF::k2>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfTIM4_CH4_PF6 = AnyAFR<Port::PF, 6, AF::k2>;#endif	// defined(GPIOF_BASE)
#endif	// defined(TIM4_BASE)

// TIM5
#if defined(TIM5_BASE)
using AfTIM5_CH1_PA0 = AnyAFR<Port::PA, 0, AF::k2>;using AfTIM5_CH1_PB2 = AnyAFR<Port::PB, 2, AF::k2>;using AfTIM5_CH2_PA1 = AnyAFR<Port::PA, 1, AF::k2>;using AfTIM5_CH2_PC12 = AnyAFR<Port::PC, 12, AF::k1>;using AfTIM5_CH3_PA2 = AnyAFR<Port::PA, 2, AF::k2>;using AfTIM5_CH4_PA3 = AnyAFR<Port::PA, 3, AF::k2>;using AfTIM5_ETR_PB12 = AnyAFR<Port::PB, 12, AF::k2>;#if defined(GPIOD_BASE)
using AfTIM5_ETR_PD11 = AnyAFR<Port::PD, 11, AF::k1>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfTIM5_CH3_PE8 = AnyAFR<Port::PE, 8, AF::k1>;using AfTIM5_CH4_PE9 = AnyAFR<Port::PE, 9, AF::k1>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfTIM5_CH1_PF6 = AnyAFR<Port::PF, 6, AF::k6>;using AfTIM5_CH2_PF7 = AnyAFR<Port::PF, 7, AF::k6>;using AfTIM5_CH3_PF8 = AnyAFR<Port::PF, 8, AF::k6>;using AfTIM5_CH4_PF9 = AnyAFR<Port::PF, 9, AF::k6>;using AfTIM5_ETR_PF6 = AnyAFR<Port::PF, 6, AF::k1>;#endif	// defined(GPIOF_BASE)
#endif	// defined(TIM5_BASE)

// TIM8
#if defined(TIM8_BASE)
using AfTIM8_BKIN_PA0 = AnyAFR<Port::PA, 0, AF::k9>;using AfTIM8_BKIN_PA6 = AnyAFR<Port::PA, 6, AF::k4>;using AfTIM8_BKIN_PA10 = AnyAFR<Port::PA, 10, AF::k11>;using AfTIM8_BKIN_PB7 = AnyAFR<Port::PB, 7, AF::k5>;using AfTIM8_BKIN2_PB6 = AnyAFR<Port::PB, 6, AF::k10>;using AfTIM8_BKIN2_PC9 = AnyAFR<Port::PC, 9, AF::k6>;using AfTIM8_CH1_PA15 = AnyAFR<Port::PA, 15, AF::k2>;using AfTIM8_CH1_PB6 = AnyAFR<Port::PB, 6, AF::k5>;using AfTIM8_CH1_PC6 = AnyAFR<Port::PC, 6, AF::k4>;using AfTIM8_CH1N_PA7 = AnyAFR<Port::PA, 7, AF::k4>;using AfTIM8_CH1N_PB3 = AnyAFR<Port::PB, 3, AF::k4>;using AfTIM8_CH1N_PC10 = AnyAFR<Port::PC, 10, AF::k4>;using AfTIM8_CH2_PA14 = AnyAFR<Port::PA, 14, AF::k5>;using AfTIM8_CH2_PB8 = AnyAFR<Port::PB, 8, AF::k10>;using AfTIM8_CH2_PC7 = AnyAFR<Port::PC, 7, AF::k4>;using AfTIM8_CH2N_PB0 = AnyAFR<Port::PB, 0, AF::k4>;using AfTIM8_CH2N_PB4 = AnyAFR<Port::PB, 4, AF::k4>;using AfTIM8_CH2N_PC11 = AnyAFR<Port::PC, 11, AF::k4>;using AfTIM8_CH3_PB9 = AnyAFR<Port::PB, 9, AF::k10>;using AfTIM8_CH3_PC8 = AnyAFR<Port::PC, 8, AF::k4>;using AfTIM8_CH3N_PB1 = AnyAFR<Port::PB, 1, AF::k4>;using AfTIM8_CH3N_PB5 = AnyAFR<Port::PB, 5, AF::k3>;using AfTIM8_CH3N_PC12 = AnyAFR<Port::PC, 12, AF::k4>;using AfTIM8_CH4_PC9 = AnyAFR<Port::PC, 9, AF::k4>;using AfTIM8_CH4N_PC13 = AnyAFR<Port::PC, 13, AF::k6>;using AfTIM8_ETR_PA0 = AnyAFR<Port::PA, 0, AF::k10>;using AfTIM8_ETR_PB6 = AnyAFR<Port::PB, 6, AF::k6>;#if defined(GPIOD_BASE)
using AfTIM8_BKIN_PD2 = AnyAFR<Port::PD, 2, AF::k4>;using AfTIM8_BKIN2_PD1 = AnyAFR<Port::PD, 1, AF::k6>;using AfTIM8_CH4_PD1 = AnyAFR<Port::PD, 1, AF::k4>;using AfTIM8_CH4N_PD0 = AnyAFR<Port::PD, 0, AF::k6>;#endif	// defined(GPIOD_BASE)
#endif	// defined(TIM8_BASE)

// TIM15
#if defined(TIM15_BASE)
using AfTIM15_BKIN_PA9 = AnyAFR<Port::PA, 9, AF::k9>;using AfTIM15_BKIN_PC5 = AnyAFR<Port::PC, 5, AF::k2>;using AfTIM15_CH1_PA2 = AnyAFR<Port::PA, 2, AF::k9>;using AfTIM15_CH1_PB14 = AnyAFR<Port::PB, 14, AF::k1>;using AfTIM15_CH1N_PA1 = AnyAFR<Port::PA, 1, AF::k9>;using AfTIM15_CH1N_PB15 = AnyAFR<Port::PB, 15, AF::k2>;using AfTIM15_CH2_PA3 = AnyAFR<Port::PA, 3, AF::k9>;using AfTIM15_CH2_PB15 = AnyAFR<Port::PB, 15, AF::k1>;#if defined(GPIOF_BASE)
using AfTIM15_CH1_PF9 = AnyAFR<Port::PF, 9, AF::k3>;using AfTIM15_CH2_PF10 = AnyAFR<Port::PF, 10, AF::k3>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfTIM15_CH1N_PG9 = AnyAFR<Port::PG, 9, AF::k14>;#endif	// defined(GPIOG_BASE)
#endif	// defined(TIM15_BASE)

// TIM16
#if defined(TIM16_BASE)
using AfTIM16_BKIN_PB5 = AnyAFR<Port::PB, 5, AF::k1>;using AfTIM16_CH1_PA6 = AnyAFR<Port::PA, 6, AF::k1>;using AfTIM16_CH1_PA12 = AnyAFR<Port::PA, 12, AF::k1>;using AfTIM16_CH1_PB4 = AnyAFR<Port::PB, 4, AF::k1>;using AfTIM16_CH1_PB8 = AnyAFR<Port::PB, 8, AF::k1>;using AfTIM16_CH1N_PA13 = AnyAFR<Port::PA, 13, AF::k1>;using AfTIM16_CH1N_PB6 = AnyAFR<Port::PB, 6, AF::k1>;#if defined(GPIOE_BASE)
using AfTIM16_CH1_PE0 = AnyAFR<Port::PE, 0, AF::k4>;#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM16_BASE)

// TIM17
#if defined(TIM17_BASE)
using AfTIM17_BKIN_PA10 = AnyAFR<Port::PA, 10, AF::k1>;using AfTIM17_BKIN_PB4 = AnyAFR<Port::PB, 4, AF::k10>;using AfTIM17_CH1_PA7 = AnyAFR<Port::PA, 7, AF::k1>;using AfTIM17_CH1_PB5 = AnyAFR<Port::PB, 5, AF::k10>;using AfTIM17_CH1_PB9 = AnyAFR<Port::PB, 9, AF::k1>;using AfTIM17_CH1N_PB7 = AnyAFR<Port::PB, 7, AF::k1>;#if defined(GPIOE_BASE)
using AfTIM17_CH1_PE1 = AnyAFR<Port::PE, 1, AF::k4>;#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM17_BASE)

// TIM20
#if defined(TIM20_BASE)
using AfTIM20_CH1_PB2 = AnyAFR<Port::PB, 2, AF::k3>;using AfTIM20_CH2_PC2 = AnyAFR<Port::PC, 2, AF::k6>;using AfTIM20_CH3_PC8 = AnyAFR<Port::PC, 8, AF::k6>;#if defined(GPIOE_BASE)
using AfTIM20_CH1_PE2 = AnyAFR<Port::PE, 2, AF::k6>;using AfTIM20_CH1N_PE4 = AnyAFR<Port::PE, 4, AF::k6>;using AfTIM20_CH2_PE3 = AnyAFR<Port::PE, 3, AF::k6>;using AfTIM20_CH2N_PE5 = AnyAFR<Port::PE, 5, AF::k6>;using AfTIM20_CH3N_PE6 = AnyAFR<Port::PE, 6, AF::k6>;using AfTIM20_CH4_PE1 = AnyAFR<Port::PE, 1, AF::k6>;using AfTIM20_CH4N_PE0 = AnyAFR<Port::PE, 0, AF::k3>;using AfTIM20_ETR_PE0 = AnyAFR<Port::PE, 0, AF::k6>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfTIM20_BKIN_PF7 = AnyAFR<Port::PF, 7, AF::k2>;using AfTIM20_BKIN_PF9 = AnyAFR<Port::PF, 9, AF::k2>;using AfTIM20_BKIN2_PF8 = AnyAFR<Port::PF, 8, AF::k2>;using AfTIM20_BKIN2_PF10 = AnyAFR<Port::PF, 10, AF::k2>;using AfTIM20_CH1_PF12 = AnyAFR<Port::PF, 12, AF::k2>;using AfTIM20_CH1N_PF4 = AnyAFR<Port::PF, 4, AF::k3>;using AfTIM20_CH2_PF13 = AnyAFR<Port::PF, 13, AF::k2>;using AfTIM20_CH2N_PF5 = AnyAFR<Port::PF, 5, AF::k2>;using AfTIM20_CH3_PF2 = AnyAFR<Port::PF, 2, AF::k2>;using AfTIM20_CH3_PF14 = AnyAFR<Port::PF, 14, AF::k2>;using AfTIM20_CH4_PF3 = AnyAFR<Port::PF, 3, AF::k2>;using AfTIM20_CH4_PF15 = AnyAFR<Port::PF, 15, AF::k2>;using AfTIM20_ETR_PF11 = AnyAFR<Port::PF, 11, AF::k2>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfTIM20_BKIN_PG3 = AnyAFR<Port::PG, 3, AF::k2>;using AfTIM20_BKIN_PG6 = AnyAFR<Port::PG, 6, AF::k2>;using AfTIM20_BKIN2_PG4 = AnyAFR<Port::PG, 4, AF::k2>;using AfTIM20_CH1N_PG0 = AnyAFR<Port::PG, 0, AF::k2>;using AfTIM20_CH2N_PG1 = AnyAFR<Port::PG, 1, AF::k2>;using AfTIM20_CH3N_PG2 = AnyAFR<Port::PG, 2, AF::k2>;using AfTIM20_CH4N_PG3 = AnyAFR<Port::PG, 3, AF::k6>;using AfTIM20_ETR_PG5 = AnyAFR<Port::PG, 5, AF::k2>;#endif	// defined(GPIOG_BASE)
#endif	// defined(TIM20_BASE)

// USART1
#if defined(USART1_BASE)
using AfUSART1_CK_PA8 = AnyAFR<Port::PA, 8, AF::k7>;using AfUSART1_CTS_PA11 = AnyAFR<Port::PA, 11, AF::k7>;using AfUSART1_RTS_DE_PA12 = AnyAFR<Port::PA, 12, AF::k7>;using AfUSART1_RX_PA10 = AnyAFR<Port::PA, 10, AF::k7>;using AfUSART1_RX_PB7 = AnyAFR<Port::PB, 7, AF::k7>;using AfUSART1_RX_PC5 = AnyAFR<Port::PC, 5, AF::k7>;using AfUSART1_TX_PA9 = AnyAFR<Port::PA, 9, AF::k7>;using AfUSART1_TX_PB6 = AnyAFR<Port::PB, 6, AF::k7>;using AfUSART1_TX_PC4 = AnyAFR<Port::PC, 4, AF::k7>;#if defined(GPIOE_BASE)
using AfUSART1_RX_PE1 = AnyAFR<Port::PE, 1, AF::k7>;using AfUSART1_TX_PE0 = AnyAFR<Port::PE, 0, AF::k7>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOG_BASE)
using AfUSART1_TX_PG9 = AnyAFR<Port::PG, 9, AF::k7>;#endif	// defined(GPIOG_BASE)
#endif	// defined(USART1_BASE)

// USART2
#if defined(USART2_BASE)
using AfUSART2_CK_PA4 = AnyAFR<Port::PA, 4, AF::k7>;using AfUSART2_CK_PB5 = AnyAFR<Port::PB, 5, AF::k7>;using AfUSART2_CTS_PA0 = AnyAFR<Port::PA, 0, AF::k7>;using AfUSART2_RTS_DE_PA1 = AnyAFR<Port::PA, 1, AF::k7>;using AfUSART2_RX_PA3 = AnyAFR<Port::PA, 3, AF::k7>;using AfUSART2_RX_PA15 = AnyAFR<Port::PA, 15, AF::k7>;using AfUSART2_RX_PB4 = AnyAFR<Port::PB, 4, AF::k7>;using AfUSART2_TX_PA2 = AnyAFR<Port::PA, 2, AF::k7>;using AfUSART2_TX_PA14 = AnyAFR<Port::PA, 14, AF::k7>;using AfUSART2_TX_PB3 = AnyAFR<Port::PB, 3, AF::k7>;#if defined(GPIOD_BASE)
using AfUSART2_CK_PD7 = AnyAFR<Port::PD, 7, AF::k7>;using AfUSART2_CTS_PD3 = AnyAFR<Port::PD, 3, AF::k7>;using AfUSART2_RTS_DE_PD4 = AnyAFR<Port::PD, 4, AF::k7>;using AfUSART2_RX_PD6 = AnyAFR<Port::PD, 6, AF::k7>;using AfUSART2_TX_PD5 = AnyAFR<Port::PD, 5, AF::k7>;#endif	// defined(GPIOD_BASE)
#endif	// defined(USART2_BASE)

// USART3
#if defined(USART3_BASE)
using AfUSART3_CK_PB12 = AnyAFR<Port::PB, 12, AF::k7>;using AfUSART3_CK_PC12 = AnyAFR<Port::PC, 12, AF::k7>;using AfUSART3_CTS_PA13 = AnyAFR<Port::PA, 13, AF::k7>;using AfUSART3_CTS_PB13 = AnyAFR<Port::PB, 13, AF::k7>;using AfUSART3_RTS_DE_PB14 = AnyAFR<Port::PB, 14, AF::k7>;using AfUSART3_RX_PB8 = AnyAFR<Port::PB, 8, AF::k7>;using AfUSART3_RX_PB11 = AnyAFR<Port::PB, 11, AF::k7>;using AfUSART3_RX_PC11 = AnyAFR<Port::PC, 11, AF::k7>;using AfUSART3_TX_PB9 = AnyAFR<Port::PB, 9, AF::k7>;using AfUSART3_TX_PB10 = AnyAFR<Port::PB, 10, AF::k7>;using AfUSART3_TX_PC10 = AnyAFR<Port::PC, 10, AF::k7>;#if defined(GPIOD_BASE)
using AfUSART3_CK_PD10 = AnyAFR<Port::PD, 10, AF::k7>;using AfUSART3_CTS_PD11 = AnyAFR<Port::PD, 11, AF::k7>;using AfUSART3_RTS_DE_PD12 = AnyAFR<Port::PD, 12, AF::k7>;using AfUSART3_RX_PD9 = AnyAFR<Port::PD, 9, AF::k7>;using AfUSART3_TX_PD8 = AnyAFR<Port::PD, 8, AF::k7>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfUSART3_RX_PE15 = AnyAFR<Port::PE, 15, AF::k7>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfUSART3_RTS_PF6 = AnyAFR<Port::PF, 6, AF::k7>;#endif	// defined(GPIOF_BASE)
#endif	// defined(USART3_BASE)

// UART4
#if defined(UART4_BASE)
using AfUART4_CTS_PB7 = AnyAFR<Port::PB, 7, AF::k14>;using AfUART4_RTS_DE_PA15 = AnyAFR<Port::PA, 15, AF::k8>;using AfUART4_RX_PC11 = AnyAFR<Port::PC, 11, AF::k5>;using AfUART4_TX_PC10 = AnyAFR<Port::PC, 10, AF::k5>;#endif	// defined(UART4_BASE)

// UART5
#if defined(UART5_BASE)
using AfUART5_CTS_PB5 = AnyAFR<Port::PB, 5, AF::k14>;using AfUART5_RTS_DE_PB4 = AnyAFR<Port::PB, 4, AF::k8>;using AfUART5_TX_PC12 = AnyAFR<Port::PC, 12, AF::k5>;#if defined(GPIOD_BASE)
using AfUART5_RX_PD2 = AnyAFR<Port::PD, 2, AF::k5>;#endif	// defined(GPIOD_BASE)
#endif	// defined(UART5_BASE)

// USB
#if defined(USB_BASE)
using AfUSB_CRS_SYNC_PA10 = AnyAFR<Port::PA, 10, AF::k3>;using AfUSB_CRS_SYNC_PB3 = AnyAFR<Port::PB, 3, AF::k3>;#endif	// defined(USB_BASE)

// UCPD1
#if defined(UCPD1_BASE)
using AfUCPD1_FRSTX_PA2 = AnyAFR<Port::PA, 2, AF::k14>;using AfUCPD1_FRSTX_PA5 = AnyAFR<Port::PA, 5, AF::k14>;using AfUCPD1_FRSTX_PA7 = AnyAFR<Port::PA, 7, AF::k14>;using AfUCPD1_FRSTX_PB0 = AnyAFR<Port::PB, 0, AF::k14>;using AfUCPD1_FRSTX_PC12 = AnyAFR<Port::PC, 12, AF::k14>;#endif	// defined(UCPD1_BASE)

// EVENTOUT
using AfEVENTOUT_PA0 = AnyAFR<Port::PA, 0, AF::k15>;using AfEVENTOUT_PA1 = AnyAFR<Port::PA, 1, AF::k15>;using AfEVENTOUT_PA2 = AnyAFR<Port::PA, 2, AF::k15>;using AfEVENTOUT_PA3 = AnyAFR<Port::PA, 3, AF::k15>;using AfEVENTOUT_PA4 = AnyAFR<Port::PA, 4, AF::k15>;using AfEVENTOUT_PA5 = AnyAFR<Port::PA, 5, AF::k15>;using AfEVENTOUT_PA6 = AnyAFR<Port::PA, 6, AF::k15>;using AfEVENTOUT_PA7 = AnyAFR<Port::PA, 7, AF::k15>;using AfEVENTOUT_PA8 = AnyAFR<Port::PA, 8, AF::k15>;using AfEVENTOUT_PA9 = AnyAFR<Port::PA, 9, AF::k15>;using AfEVENTOUT_PA10 = AnyAFR<Port::PA, 10, AF::k15>;using AfEVENTOUT_PA11 = AnyAFR<Port::PA, 11, AF::k15>;using AfEVENTOUT_PA12 = AnyAFR<Port::PA, 12, AF::k15>;using AfEVENTOUT_PA13 = AnyAFR<Port::PA, 13, AF::k15>;using AfEVENTOUT_PA14 = AnyAFR<Port::PA, 14, AF::k15>;using AfEVENTOUT_PA15 = AnyAFR<Port::PA, 15, AF::k15>;using AfEVENTOUT_PB0 = AnyAFR<Port::PB, 0, AF::k15>;using AfEVENTOUT_PB1 = AnyAFR<Port::PB, 1, AF::k15>;using AfEVENTOUT_PB2 = AnyAFR<Port::PB, 2, AF::k15>;using AfEVENTOUT_PB3 = AnyAFR<Port::PB, 3, AF::k15>;using AfEVENTOUT_PB4 = AnyAFR<Port::PB, 4, AF::k15>;using AfEVENTOUT_PB5 = AnyAFR<Port::PB, 5, AF::k15>;using AfEVENTOUT_PB6 = AnyAFR<Port::PB, 6, AF::k15>;using AfEVENTOUT_PB7 = AnyAFR<Port::PB, 7, AF::k15>;using AfEVENTOUT_PB8 = AnyAFR<Port::PB, 8, AF::k15>;using AfEVENTOUT_PB9 = AnyAFR<Port::PB, 9, AF::k15>;using AfEVENTOUT_PB10 = AnyAFR<Port::PB, 10, AF::k15>;using AfEVENTOUT_PB11 = AnyAFR<Port::PB, 11, AF::k15>;using AfEVENTOUT_PB12 = AnyAFR<Port::PB, 12, AF::k15>;using AfEVENTOUT_PB13 = AnyAFR<Port::PB, 13, AF::k15>;using AfEVENTOUT_PB14 = AnyAFR<Port::PB, 14, AF::k15>;using AfEVENTOUT_PB15 = AnyAFR<Port::PB, 15, AF::k15>;using AfEVENTOUT_PC0 = AnyAFR<Port::PC, 0, AF::k15>;using AfEVENTOUT_PC1 = AnyAFR<Port::PC, 1, AF::k15>;using AfEVENTOUT_PC2 = AnyAFR<Port::PC, 2, AF::k15>;using AfEVENTOUT_PC3 = AnyAFR<Port::PC, 3, AF::k15>;using AfEVENTOUT_PC4 = AnyAFR<Port::PC, 4, AF::k15>;using AfEVENTOUT_PC5 = AnyAFR<Port::PC, 5, AF::k15>;using AfEVENTOUT_PC6 = AnyAFR<Port::PC, 6, AF::k15>;using AfEVENTOUT_PC7 = AnyAFR<Port::PC, 7, AF::k15>;using AfEVENTOUT_PC8 = AnyAFR<Port::PC, 8, AF::k15>;using AfEVENTOUT_PC9 = AnyAFR<Port::PC, 9, AF::k15>;using AfEVENTOUT_PC10 = AnyAFR<Port::PC, 10, AF::k15>;using AfEVENTOUT_PC11 = AnyAFR<Port::PC, 11, AF::k15>;using AfEVENTOUT_PC12 = AnyAFR<Port::PC, 12, AF::k15>;using AfEVENTOUT_PC13 = AnyAFR<Port::PC, 13, AF::k15>;using AfEVENTOUT_PC14 = AnyAFR<Port::PC, 14, AF::k15>;using AfEVENTOUT_PC15 = AnyAFR<Port::PC, 15, AF::k15>;#if defined(GPIOD_BASE)
using AfEVENTOUT_PD0 = AnyAFR<Port::PD, 0, AF::k15>;using AfEVENTOUT_PD1 = AnyAFR<Port::PD, 1, AF::k15>;using AfEVENTOUT_PD2 = AnyAFR<Port::PD, 2, AF::k15>;using AfEVENTOUT_PD3 = AnyAFR<Port::PD, 3, AF::k15>;using AfEVENTOUT_PD4 = AnyAFR<Port::PD, 4, AF::k15>;using AfEVENTOUT_PD5 = AnyAFR<Port::PD, 5, AF::k15>;using AfEVENTOUT_PD6 = AnyAFR<Port::PD, 6, AF::k15>;using AfEVENTOUT_PD7 = AnyAFR<Port::PD, 7, AF::k15>;using AfEVENTOUT_PD8 = AnyAFR<Port::PD, 8, AF::k15>;using AfEVENTOUT_PD9 = AnyAFR<Port::PD, 9, AF::k15>;using AfEVENTOUT_PD10 = AnyAFR<Port::PD, 10, AF::k15>;using AfEVENTOUT_PD11 = AnyAFR<Port::PD, 11, AF::k15>;using AfEVENTOUT_PD12 = AnyAFR<Port::PD, 12, AF::k15>;using AfEVENTOUT_PD13 = AnyAFR<Port::PD, 13, AF::k15>;using AfEVENTOUT_PD14 = AnyAFR<Port::PD, 14, AF::k15>;using AfEVENTOUT_PD15 = AnyAFR<Port::PD, 15, AF::k15>;#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfEVENTOUT_PE0 = AnyAFR<Port::PE, 0, AF::k15>;using AfEVENTOUT_PE1 = AnyAFR<Port::PE, 1, AF::k15>;using AfEVENTOUT_PE2 = AnyAFR<Port::PE, 2, AF::k15>;using AfEVENTOUT_PE3 = AnyAFR<Port::PE, 3, AF::k15>;using AfEVENTOUT_PE4 = AnyAFR<Port::PE, 4, AF::k15>;using AfEVENTOUT_PE5 = AnyAFR<Port::PE, 5, AF::k15>;using AfEVENTOUT_PE6 = AnyAFR<Port::PE, 6, AF::k15>;using AfEVENTOUT_PE7 = AnyAFR<Port::PE, 7, AF::k15>;using AfEVENTOUT_PE8 = AnyAFR<Port::PE, 8, AF::k15>;using AfEVENTOUT_PE9 = AnyAFR<Port::PE, 9, AF::k15>;using AfEVENTOUT_PE10 = AnyAFR<Port::PE, 10, AF::k15>;using AfEVENTOUT_PE11 = AnyAFR<Port::PE, 11, AF::k15>;using AfEVENTOUT_PE12 = AnyAFR<Port::PE, 12, AF::k15>;using AfEVENTOUT_PE13 = AnyAFR<Port::PE, 13, AF::k15>;using AfEVENTOUT_PE14 = AnyAFR<Port::PE, 14, AF::k15>;using AfEVENTOUT_PE15 = AnyAFR<Port::PE, 15, AF::k15>;#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfEVENTOUT_PF0 = AnyAFR<Port::PF, 0, AF::k15>;using AfEVENTOUT_PF1 = AnyAFR<Port::PF, 1, AF::k15>;using AfEVENTOUT_PF2 = AnyAFR<Port::PF, 2, AF::k15>;using AfEVENTOUT_PF3 = AnyAFR<Port::PF, 3, AF::k15>;using AfEVENTOUT_PF4 = AnyAFR<Port::PF, 4, AF::k15>;using AfEVENTOUT_PF5 = AnyAFR<Port::PF, 5, AF::k15>;using AfEVENTOUT_PF6 = AnyAFR<Port::PF, 6, AF::k15>;using AfEVENTOUT_PF7 = AnyAFR<Port::PF, 7, AF::k15>;using AfEVENTOUT_PF8 = AnyAFR<Port::PF, 8, AF::k15>;using AfEVENTOUT_PF9 = AnyAFR<Port::PF, 9, AF::k15>;using AfEVENTOUT_PF10 = AnyAFR<Port::PF, 10, AF::k15>;using AfEVENTOUT_PF11 = AnyAFR<Port::PF, 11, AF::k15>;using AfEVENTOUT_PF12 = AnyAFR<Port::PF, 12, AF::k15>;using AfEVENTOUT_PF13 = AnyAFR<Port::PF, 13, AF::k15>;using AfEVENTOUT_PF14 = AnyAFR<Port::PF, 14, AF::k15>;using AfEVENTOUT_PF15 = AnyAFR<Port::PF, 15, AF::k15>;#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfEVENTOUT_PG0 = AnyAFR<Port::PG, 0, AF::k15>;using AfEVENTOUT_PG1 = AnyAFR<Port::PG, 1, AF::k15>;using AfEVENTOUT_PG2 = AnyAFR<Port::PG, 2, AF::k15>;using AfEVENTOUT_PG3 = AnyAFR<Port::PG, 3, AF::k15>;using AfEVENTOUT_PG4 = AnyAFR<Port::PG, 4, AF::k15>;using AfEVENTOUT_PG5 = AnyAFR<Port::PG, 5, AF::k15>;using AfEVENTOUT_PG6 = AnyAFR<Port::PG, 6, AF::k15>;using AfEVENTOUT_PG7 = AnyAFR<Port::PG, 7, AF::k15>;using AfEVENTOUT_PG8 = AnyAFR<Port::PG, 8, AF::k15>;using AfEVENTOUT_PG9 = AnyAFR<Port::PG, 9, AF::k15>;using AfEVENTOUT_PG10 = AnyAFR<Port::PG, 10, AF::k15>;#endif	// defined(GPIOG_BASE)


}	// namespace Gpio
}	// namespace Bmt

