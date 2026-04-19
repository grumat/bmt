#pragma once

namespace Bmt
{
namespace Gpio
{


// SYS
using AfMCO_PA8 = AnyAFR<Port::PA, 8, AF::k0>;
using AfJTCK_PA14 = AnyAFR<Port::PA, 14, AF::k0>;
using AfJTDI_PA15 = AnyAFR<Port::PA, 15, AF::k0>;
using AfJTDO_PB3 = AnyAFR<Port::PB, 3, AF::k0>;
using AfJTMS_PA13 = AnyAFR<Port::PA, 13, AF::k0>;
using AfNJTRST_PB4 = AnyAFR<Port::PB, 4, AF::k0>;
using AfTRACED0_PC1 = AnyAFR<Port::PC, 1, AF::k0>;
using AfTRACED1_PC10 = AnyAFR<Port::PC, 10, AF::k0>;
using AfTRACED3_PC12 = AnyAFR<Port::PC, 12, AF::k0>;
using AfTRACESWO_PB3 = AnyAFR<Port::PB, 3, AF::k0>;
#if defined(GPIOD_BASE)
using AfTRACED2_PD2 = AnyAFR<Port::PD, 2, AF::k0>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfTRACECLK_PE2 = AnyAFR<Port::PE, 2, AF::k0>;
using AfTRACED0_PE3 = AnyAFR<Port::PE, 3, AF::k0>;
using AfTRACED1_PE4 = AnyAFR<Port::PE, 4, AF::k0>;
using AfTRACED2_PE5 = AnyAFR<Port::PE, 5, AF::k0>;
using AfTRACED3_PE6 = AnyAFR<Port::PE, 6, AF::k0>;
#endif	// defined(GPIOE_BASE)
using AfSWCLK_PA14 = AnyAFR<Port::PA, 14, AF::k0>;
using AfSWDIO_PA13 = AnyAFR<Port::PA, 13, AF::k0>;
// CAN1
#if defined(CAN1_BASE)
using AfCAN1_RX_PA11 = AnyAFR<Port::PA, 11, AF::k9>;
using AfCAN1_RX_PB8 = AnyAFR<Port::PB, 8, AF::k9>;
using AfCAN1_TX_PA12 = AnyAFR<Port::PA, 12, AF::k9>;
using AfCAN1_TX_PB9 = AnyAFR<Port::PB, 9, AF::k9>;
#if defined(GPIOD_BASE)
using AfCAN1_RX_PD0 = AnyAFR<Port::PD, 0, AF::k9>;
using AfCAN1_TX_PD1 = AnyAFR<Port::PD, 1, AF::k9>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOH_BASE)
using AfCAN1_TX_PH13 = AnyAFR<Port::PH, 13, AF::k9>;
#endif	// defined(GPIOH_BASE)
#if defined(GPIOI_BASE)
using AfCAN1_RX_PI9 = AnyAFR<Port::PI, 9, AF::k9>;
#endif	// defined(GPIOI_BASE)
#endif	// defined(CAN1_BASE)

// CAN2
#if defined(CAN2_BASE)
using AfCAN2_RX_PB5 = AnyAFR<Port::PB, 5, AF::k3>;
using AfCAN2_RX_PB12 = AnyAFR<Port::PB, 12, AF::k10>;
using AfCAN2_TX_PB6 = AnyAFR<Port::PB, 6, AF::k8>;
using AfCAN2_TX_PB13 = AnyAFR<Port::PB, 13, AF::k10>;
#endif	// defined(CAN2_BASE)

// COMP1
#if defined(COMP1_BASE)
using AfCOMP1_OUT_PB0 = AnyAFR<Port::PB, 0, AF::k12>;
using AfCOMP1_OUT_PB10 = AnyAFR<Port::PB, 10, AF::k12>;
#endif	// defined(COMP1_BASE)

// COMP2
#if defined(COMP2_BASE)
using AfCOMP2_OUT_PB5 = AnyAFR<Port::PB, 5, AF::k12>;
using AfCOMP2_OUT_PB11 = AnyAFR<Port::PB, 11, AF::k12>;
#endif	// defined(COMP2_BASE)

// DFSDM1
#if defined(DFSDM1_BASE)
using AfDFSDM1_CKIN0_PB2 = AnyAFR<Port::PB, 2, AF::k6>;
using AfDFSDM1_CKIN1_PB13 = AnyAFR<Port::PB, 13, AF::k6>;
using AfDFSDM1_CKIN2_PB15 = AnyAFR<Port::PB, 15, AF::k6>;
using AfDFSDM1_CKIN3_PC6 = AnyAFR<Port::PC, 6, AF::k6>;
using AfDFSDM1_CKIN4_PC1 = AnyAFR<Port::PC, 1, AF::k6>;
using AfDFSDM1_CKIN5_PB7 = AnyAFR<Port::PB, 7, AF::k6>;
using AfDFSDM1_CKIN6_PB9 = AnyAFR<Port::PB, 9, AF::k6>;
using AfDFSDM1_CKIN7_PB11 = AnyAFR<Port::PB, 11, AF::k6>;
using AfDFSDM1_CKOUT_PC2 = AnyAFR<Port::PC, 2, AF::k6>;
using AfDFSDM1_DATIN0_PB1 = AnyAFR<Port::PB, 1, AF::k6>;
using AfDFSDM1_DATIN1_PB12 = AnyAFR<Port::PB, 12, AF::k6>;
using AfDFSDM1_DATIN2_PB14 = AnyAFR<Port::PB, 14, AF::k6>;
using AfDFSDM1_DATIN3_PC7 = AnyAFR<Port::PC, 7, AF::k6>;
using AfDFSDM1_DATIN4_PC0 = AnyAFR<Port::PC, 0, AF::k6>;
using AfDFSDM1_DATIN5_PB6 = AnyAFR<Port::PB, 6, AF::k6>;
using AfDFSDM1_DATIN6_PB8 = AnyAFR<Port::PB, 8, AF::k6>;
using AfDFSDM1_DATIN7_PB10 = AnyAFR<Port::PB, 10, AF::k6>;
#if defined(GPIOD_BASE)
using AfDFSDM1_CKIN0_PD4 = AnyAFR<Port::PD, 4, AF::k6>;
using AfDFSDM1_CKIN1_PD7 = AnyAFR<Port::PD, 7, AF::k6>;
using AfDFSDM1_CKIN7_PD1 = AnyAFR<Port::PD, 1, AF::k6>;
using AfDFSDM1_DATIN0_PD3 = AnyAFR<Port::PD, 3, AF::k6>;
using AfDFSDM1_DATIN1_PD6 = AnyAFR<Port::PD, 6, AF::k6>;
using AfDFSDM1_DATIN7_PD0 = AnyAFR<Port::PD, 0, AF::k6>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfDFSDM1_CKIN2_PE8 = AnyAFR<Port::PE, 8, AF::k6>;
using AfDFSDM1_CKIN3_PE5 = AnyAFR<Port::PE, 5, AF::k6>;
using AfDFSDM1_CKIN4_PE11 = AnyAFR<Port::PE, 11, AF::k6>;
using AfDFSDM1_CKIN5_PE13 = AnyAFR<Port::PE, 13, AF::k6>;
using AfDFSDM1_CKOUT_PE9 = AnyAFR<Port::PE, 9, AF::k6>;
using AfDFSDM1_DATIN2_PE7 = AnyAFR<Port::PE, 7, AF::k6>;
using AfDFSDM1_DATIN3_PE4 = AnyAFR<Port::PE, 4, AF::k6>;
using AfDFSDM1_DATIN4_PE10 = AnyAFR<Port::PE, 10, AF::k6>;
using AfDFSDM1_DATIN5_PE12 = AnyAFR<Port::PE, 12, AF::k6>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfDFSDM1_CKIN6_PF14 = AnyAFR<Port::PF, 14, AF::k6>;
using AfDFSDM1_DATIN6_PF13 = AnyAFR<Port::PF, 13, AF::k6>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(DFSDM1_BASE)

// DCMI
#if defined(DCMI_BASE)
using AfDCMI_D0_PA9 = AnyAFR<Port::PA, 9, AF::k5>;
using AfDCMI_D0_PC6 = AnyAFR<Port::PC, 6, AF::k10>;
using AfDCMI_D1_PA10 = AnyAFR<Port::PA, 10, AF::k5>;
using AfDCMI_D1_PC7 = AnyAFR<Port::PC, 7, AF::k10>;
using AfDCMI_D10_PB5 = AnyAFR<Port::PB, 5, AF::k10>;
using AfDCMI_D12_PB4 = AnyAFR<Port::PB, 4, AF::k10>;
using AfDCMI_D2_PC8 = AnyAFR<Port::PC, 8, AF::k10>;
using AfDCMI_D3_PC9 = AnyAFR<Port::PC, 9, AF::k4>;
using AfDCMI_D4_PC11 = AnyAFR<Port::PC, 11, AF::k10>;
using AfDCMI_D5_PB6 = AnyAFR<Port::PB, 6, AF::k10>;
using AfDCMI_D6_PB8 = AnyAFR<Port::PB, 8, AF::k10>;
using AfDCMI_D7_PB9 = AnyAFR<Port::PB, 9, AF::k10>;
using AfDCMI_D8_PC10 = AnyAFR<Port::PC, 10, AF::k10>;
using AfDCMI_D9_PC12 = AnyAFR<Port::PC, 12, AF::k10>;
using AfDCMI_HSYNC_PA4 = AnyAFR<Port::PA, 4, AF::k10>;
using AfDCMI_PIXCLK_PA6 = AnyAFR<Port::PA, 6, AF::k4>;
using AfDCMI_VSYNC_PB7 = AnyAFR<Port::PB, 7, AF::k10>;
#if defined(GPIOD_BASE)
using AfDCMI_D10_PD6 = AnyAFR<Port::PD, 6, AF::k4>;
using AfDCMI_D11_PD2 = AnyAFR<Port::PD, 2, AF::k10>;
using AfDCMI_D5_PD3 = AnyAFR<Port::PD, 3, AF::k4>;
using AfDCMI_HSYNC_PD8 = AnyAFR<Port::PD, 8, AF::k10>;
using AfDCMI_PIXCLK_PD9 = AnyAFR<Port::PD, 9, AF::k10>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfDCMI_D2_PE0 = AnyAFR<Port::PE, 0, AF::k10>;
using AfDCMI_D3_PE1 = AnyAFR<Port::PE, 1, AF::k10>;
using AfDCMI_D4_PE4 = AnyAFR<Port::PE, 4, AF::k10>;
using AfDCMI_D6_PE5 = AnyAFR<Port::PE, 5, AF::k10>;
using AfDCMI_D7_PE6 = AnyAFR<Port::PE, 6, AF::k10>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfDCMI_D11_PF10 = AnyAFR<Port::PF, 10, AF::k10>;
using AfDCMI_D12_PF11 = AnyAFR<Port::PF, 11, AF::k10>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfDCMI_D13_PG15 = AnyAFR<Port::PG, 15, AF::k10>;
#endif	// defined(GPIOG_BASE)
#if defined(GPIOH_BASE)
using AfDCMI_D0_PH9 = AnyAFR<Port::PH, 9, AF::k10>;
using AfDCMI_D1_PH10 = AnyAFR<Port::PH, 10, AF::k10>;
using AfDCMI_D11_PH15 = AnyAFR<Port::PH, 15, AF::k10>;
using AfDCMI_D2_PH11 = AnyAFR<Port::PH, 11, AF::k10>;
using AfDCMI_D3_PH12 = AnyAFR<Port::PH, 12, AF::k10>;
using AfDCMI_D4_PH14 = AnyAFR<Port::PH, 14, AF::k10>;
using AfDCMI_D8_PH6 = AnyAFR<Port::PH, 6, AF::k10>;
using AfDCMI_D9_PH7 = AnyAFR<Port::PH, 7, AF::k10>;
using AfDCMI_HSYNC_PH8 = AnyAFR<Port::PH, 8, AF::k10>;
using AfDCMI_PIXCLK_PH5 = AnyAFR<Port::PH, 5, AF::k10>;
#endif	// defined(GPIOH_BASE)
#if defined(GPIOI_BASE)
using AfDCMI_D10_PI3 = AnyAFR<Port::PI, 3, AF::k10>;
using AfDCMI_D12_PI8 = AnyAFR<Port::PI, 8, AF::k10>;
using AfDCMI_D13_PI0 = AnyAFR<Port::PI, 0, AF::k10>;
using AfDCMI_D5_PI4 = AnyAFR<Port::PI, 4, AF::k10>;
using AfDCMI_D6_PI6 = AnyAFR<Port::PI, 6, AF::k10>;
using AfDCMI_D7_PI7 = AnyAFR<Port::PI, 7, AF::k10>;
using AfDCMI_D8_PI1 = AnyAFR<Port::PI, 1, AF::k10>;
using AfDCMI_D9_PI2 = AnyAFR<Port::PI, 2, AF::k10>;
using AfDCMI_VSYNC_PI5 = AnyAFR<Port::PI, 5, AF::k10>;
#endif	// defined(GPIOI_BASE)
#endif	// defined(DCMI_BASE)

// FMC
#if defined(FMC_BASE)
using AfFMC_NL_PB7 = AnyAFR<Port::PB, 7, AF::k12>;
#if defined(GPIOD_BASE)
using AfFMC_A16_PD11 = AnyAFR<Port::PD, 11, AF::k12>;
using AfFMC_A17_PD12 = AnyAFR<Port::PD, 12, AF::k12>;
using AfFMC_A18_PD13 = AnyAFR<Port::PD, 13, AF::k12>;
using AfFMC_CLK_PD3 = AnyAFR<Port::PD, 3, AF::k12>;
using AfFMC_D0_PD14 = AnyAFR<Port::PD, 14, AF::k12>;
using AfFMC_D1_PD15 = AnyAFR<Port::PD, 15, AF::k12>;
using AfFMC_D13_PD8 = AnyAFR<Port::PD, 8, AF::k12>;
using AfFMC_D14_PD9 = AnyAFR<Port::PD, 9, AF::k12>;
using AfFMC_D15_PD10 = AnyAFR<Port::PD, 10, AF::k12>;
using AfFMC_D2_PD0 = AnyAFR<Port::PD, 0, AF::k12>;
using AfFMC_D3_PD1 = AnyAFR<Port::PD, 1, AF::k12>;
using AfFMC_NE1_PD7 = AnyAFR<Port::PD, 7, AF::k12>;
using AfFMC_NOE_PD4 = AnyAFR<Port::PD, 4, AF::k12>;
using AfFMC_NWAIT_PD6 = AnyAFR<Port::PD, 6, AF::k12>;
using AfFMC_NWE_PD5 = AnyAFR<Port::PD, 5, AF::k12>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfFMC_A19_PE3 = AnyAFR<Port::PE, 3, AF::k12>;
using AfFMC_A20_PE4 = AnyAFR<Port::PE, 4, AF::k12>;
using AfFMC_A21_PE5 = AnyAFR<Port::PE, 5, AF::k12>;
using AfFMC_A22_PE6 = AnyAFR<Port::PE, 6, AF::k12>;
using AfFMC_A23_PE2 = AnyAFR<Port::PE, 2, AF::k12>;
using AfFMC_D10_PE13 = AnyAFR<Port::PE, 13, AF::k12>;
using AfFMC_D11_PE14 = AnyAFR<Port::PE, 14, AF::k12>;
using AfFMC_D12_PE15 = AnyAFR<Port::PE, 15, AF::k12>;
using AfFMC_D4_PE7 = AnyAFR<Port::PE, 7, AF::k12>;
using AfFMC_D5_PE8 = AnyAFR<Port::PE, 8, AF::k12>;
using AfFMC_D6_PE9 = AnyAFR<Port::PE, 9, AF::k12>;
using AfFMC_D7_PE10 = AnyAFR<Port::PE, 10, AF::k12>;
using AfFMC_D8_PE11 = AnyAFR<Port::PE, 11, AF::k12>;
using AfFMC_D9_PE12 = AnyAFR<Port::PE, 12, AF::k12>;
using AfFMC_NBL0_PE0 = AnyAFR<Port::PE, 0, AF::k12>;
using AfFMC_NBL1_PE1 = AnyAFR<Port::PE, 1, AF::k12>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfFMC_A0_PF0 = AnyAFR<Port::PF, 0, AF::k12>;
using AfFMC_A1_PF1 = AnyAFR<Port::PF, 1, AF::k12>;
using AfFMC_A2_PF2 = AnyAFR<Port::PF, 2, AF::k12>;
using AfFMC_A3_PF3 = AnyAFR<Port::PF, 3, AF::k12>;
using AfFMC_A4_PF4 = AnyAFR<Port::PF, 4, AF::k12>;
using AfFMC_A5_PF5 = AnyAFR<Port::PF, 5, AF::k12>;
using AfFMC_A6_PF12 = AnyAFR<Port::PF, 12, AF::k12>;
using AfFMC_A7_PF13 = AnyAFR<Port::PF, 13, AF::k12>;
using AfFMC_A8_PF14 = AnyAFR<Port::PF, 14, AF::k12>;
using AfFMC_A9_PF15 = AnyAFR<Port::PF, 15, AF::k12>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfFMC_A10_PG0 = AnyAFR<Port::PG, 0, AF::k12>;
using AfFMC_A11_PG1 = AnyAFR<Port::PG, 1, AF::k12>;
using AfFMC_A12_PG2 = AnyAFR<Port::PG, 2, AF::k12>;
using AfFMC_A13_PG3 = AnyAFR<Port::PG, 3, AF::k12>;
using AfFMC_A14_PG4 = AnyAFR<Port::PG, 4, AF::k12>;
using AfFMC_A15_PG5 = AnyAFR<Port::PG, 5, AF::k12>;
using AfFMC_A24_PG13 = AnyAFR<Port::PG, 13, AF::k12>;
using AfFMC_A25_PG14 = AnyAFR<Port::PG, 14, AF::k12>;
using AfFMC_INT_PG7 = AnyAFR<Port::PG, 7, AF::k12>;
using AfFMC_NCE_PG9 = AnyAFR<Port::PG, 9, AF::k12>;
using AfFMC_NE2_PG9 = AnyAFR<Port::PG, 9, AF::k12>;
using AfFMC_NE3_PG10 = AnyAFR<Port::PG, 10, AF::k12>;
using AfFMC_NE4_PG12 = AnyAFR<Port::PG, 12, AF::k12>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(FMC_BASE)

// IR
#if defined(TIM16_BASE)
using AfIR_OUT_PA13 = AnyAFR<Port::PA, 13, AF::k1>;
using AfIR_OUT_PB9 = AnyAFR<Port::PB, 9, AF::k1>;
#endif	// defined(TIM16_BASE)

// I2C1
#if defined(I2C1_BASE)
using AfI2C1_SCL_PA9 = AnyAFR<Port::PA, 9, AF::k4>;
using AfI2C1_SCL_PB6 = AnyAFR<Port::PB, 6, AF::k4>;
using AfI2C1_SCL_PB8 = AnyAFR<Port::PB, 8, AF::k4>;
using AfI2C1_SDA_PA10 = AnyAFR<Port::PA, 10, AF::k4>;
using AfI2C1_SDA_PB7 = AnyAFR<Port::PB, 7, AF::k4>;
using AfI2C1_SDA_PB9 = AnyAFR<Port::PB, 9, AF::k4>;
using AfI2C1_SMBA_PA1 = AnyAFR<Port::PA, 1, AF::k4>;
using AfI2C1_SMBA_PA14 = AnyAFR<Port::PA, 14, AF::k4>;
using AfI2C1_SMBA_PB5 = AnyAFR<Port::PB, 5, AF::k4>;
#if defined(GPIOG_BASE)
using AfI2C1_SCL_PG14 = AnyAFR<Port::PG, 14, AF::k4>;
using AfI2C1_SDA_PG13 = AnyAFR<Port::PG, 13, AF::k4>;
using AfI2C1_SMBA_PG15 = AnyAFR<Port::PG, 15, AF::k4>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(I2C1_BASE)

// I2C2
#if defined(I2C2_BASE)
using AfI2C2_SCL_PB10 = AnyAFR<Port::PB, 10, AF::k4>;
using AfI2C2_SCL_PB13 = AnyAFR<Port::PB, 13, AF::k4>;
using AfI2C2_SDA_PB11 = AnyAFR<Port::PB, 11, AF::k4>;
using AfI2C2_SDA_PB14 = AnyAFR<Port::PB, 14, AF::k4>;
using AfI2C2_SMBA_PB12 = AnyAFR<Port::PB, 12, AF::k4>;
#if defined(GPIOF_BASE)
using AfI2C2_SCL_PF1 = AnyAFR<Port::PF, 1, AF::k4>;
using AfI2C2_SDA_PF0 = AnyAFR<Port::PF, 0, AF::k4>;
using AfI2C2_SMBA_PF2 = AnyAFR<Port::PF, 2, AF::k4>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOH_BASE)
using AfI2C2_SCL_PH4 = AnyAFR<Port::PH, 4, AF::k4>;
using AfI2C2_SDA_PH5 = AnyAFR<Port::PH, 5, AF::k4>;
using AfI2C2_SMBA_PH6 = AnyAFR<Port::PH, 6, AF::k4>;
#endif	// defined(GPIOH_BASE)
#endif	// defined(I2C2_BASE)

// I2C3
#if defined(I2C3_BASE)
using AfI2C3_SCL_PA7 = AnyAFR<Port::PA, 7, AF::k4>;
using AfI2C3_SCL_PC0 = AnyAFR<Port::PC, 0, AF::k4>;
using AfI2C3_SDA_PB4 = AnyAFR<Port::PB, 4, AF::k4>;
using AfI2C3_SDA_PC1 = AnyAFR<Port::PC, 1, AF::k4>;
using AfI2C3_SDA_PC9 = AnyAFR<Port::PC, 9, AF::k6>;
using AfI2C3_SMBA_PB2 = AnyAFR<Port::PB, 2, AF::k4>;
#if defined(GPIOG_BASE)
using AfI2C3_SCL_PG7 = AnyAFR<Port::PG, 7, AF::k4>;
using AfI2C3_SDA_PG8 = AnyAFR<Port::PG, 8, AF::k4>;
using AfI2C3_SMBA_PG6 = AnyAFR<Port::PG, 6, AF::k4>;
#endif	// defined(GPIOG_BASE)
#if defined(GPIOH_BASE)
using AfI2C3_SCL_PH7 = AnyAFR<Port::PH, 7, AF::k4>;
using AfI2C3_SDA_PH8 = AnyAFR<Port::PH, 8, AF::k4>;
using AfI2C3_SMBA_PH9 = AnyAFR<Port::PH, 9, AF::k4>;
#endif	// defined(GPIOH_BASE)
#endif	// defined(I2C3_BASE)

// I2C4
#if defined(I2C4_BASE)
using AfI2C4_SCL_PB6 = AnyAFR<Port::PB, 6, AF::k5>;
using AfI2C4_SCL_PB10 = AnyAFR<Port::PB, 10, AF::k3>;
using AfI2C4_SCL_PC0 = AnyAFR<Port::PC, 0, AF::k2>;
using AfI2C4_SDA_PB7 = AnyAFR<Port::PB, 7, AF::k5>;
using AfI2C4_SDA_PB11 = AnyAFR<Port::PB, 11, AF::k3>;
using AfI2C4_SDA_PC1 = AnyAFR<Port::PC, 1, AF::k2>;
using AfI2C4_SMBA_PA14 = AnyAFR<Port::PA, 14, AF::k5>;
#if defined(GPIOD_BASE)
using AfI2C4_SCL_PD12 = AnyAFR<Port::PD, 12, AF::k4>;
using AfI2C4_SDA_PD13 = AnyAFR<Port::PD, 13, AF::k4>;
using AfI2C4_SMBA_PD11 = AnyAFR<Port::PD, 11, AF::k4>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOF_BASE)
using AfI2C4_SCL_PF14 = AnyAFR<Port::PF, 14, AF::k4>;
using AfI2C4_SDA_PF15 = AnyAFR<Port::PF, 15, AF::k4>;
using AfI2C4_SMBA_PF13 = AnyAFR<Port::PF, 13, AF::k4>;
#endif	// defined(GPIOF_BASE)
#endif	// defined(I2C4_BASE)

// LCD
#if defined(LCD_BASE)
using AfLCD_COM0_PA8 = AnyAFR<Port::PA, 8, AF::k11>;
using AfLCD_COM1_PA9 = AnyAFR<Port::PA, 9, AF::k11>;
using AfLCD_COM2_PA10 = AnyAFR<Port::PA, 10, AF::k11>;
using AfLCD_COM3_PB9 = AnyAFR<Port::PB, 9, AF::k11>;
using AfLCD_COM4_PC10 = AnyAFR<Port::PC, 10, AF::k11>;
using AfLCD_COM5_PC11 = AnyAFR<Port::PC, 11, AF::k11>;
using AfLCD_COM6_PC12 = AnyAFR<Port::PC, 12, AF::k11>;
using AfLCD_SEG0_PA1 = AnyAFR<Port::PA, 1, AF::k11>;
using AfLCD_SEG1_PA2 = AnyAFR<Port::PA, 2, AF::k11>;
using AfLCD_SEG10_PB10 = AnyAFR<Port::PB, 10, AF::k11>;
using AfLCD_SEG11_PB11 = AnyAFR<Port::PB, 11, AF::k11>;
using AfLCD_SEG12_PB12 = AnyAFR<Port::PB, 12, AF::k11>;
using AfLCD_SEG13_PB13 = AnyAFR<Port::PB, 13, AF::k11>;
using AfLCD_SEG14_PB14 = AnyAFR<Port::PB, 14, AF::k11>;
using AfLCD_SEG15_PB15 = AnyAFR<Port::PB, 15, AF::k11>;
using AfLCD_SEG16_PB8 = AnyAFR<Port::PB, 8, AF::k11>;
using AfLCD_SEG17_PA15 = AnyAFR<Port::PA, 15, AF::k11>;
using AfLCD_SEG18_PC0 = AnyAFR<Port::PC, 0, AF::k11>;
using AfLCD_SEG19_PC1 = AnyAFR<Port::PC, 1, AF::k11>;
using AfLCD_SEG2_PA3 = AnyAFR<Port::PA, 3, AF::k11>;
using AfLCD_SEG20_PC2 = AnyAFR<Port::PC, 2, AF::k11>;
using AfLCD_SEG21_PB7 = AnyAFR<Port::PB, 7, AF::k11>;
using AfLCD_SEG22_PC4 = AnyAFR<Port::PC, 4, AF::k11>;
using AfLCD_SEG23_PC5 = AnyAFR<Port::PC, 5, AF::k11>;
using AfLCD_SEG24_PC6 = AnyAFR<Port::PC, 6, AF::k11>;
using AfLCD_SEG25_PC7 = AnyAFR<Port::PC, 7, AF::k11>;
using AfLCD_SEG26_PC8 = AnyAFR<Port::PC, 8, AF::k11>;
using AfLCD_SEG27_PC9 = AnyAFR<Port::PC, 9, AF::k11>;
using AfLCD_SEG28_PC10 = AnyAFR<Port::PC, 10, AF::k11>;
using AfLCD_SEG29_PC11 = AnyAFR<Port::PC, 11, AF::k11>;
using AfLCD_SEG3_PA6 = AnyAFR<Port::PA, 6, AF::k11>;
using AfLCD_SEG30_PC12 = AnyAFR<Port::PC, 12, AF::k11>;
using AfLCD_SEG4_PA7 = AnyAFR<Port::PA, 7, AF::k11>;
using AfLCD_SEG40_PC10 = AnyAFR<Port::PC, 10, AF::k11>;
using AfLCD_SEG41_PC11 = AnyAFR<Port::PC, 11, AF::k11>;
using AfLCD_SEG42_PC12 = AnyAFR<Port::PC, 12, AF::k11>;
using AfLCD_SEG5_PB0 = AnyAFR<Port::PB, 0, AF::k11>;
using AfLCD_SEG6_PB1 = AnyAFR<Port::PB, 1, AF::k11>;
using AfLCD_SEG7_PB3 = AnyAFR<Port::PB, 3, AF::k11>;
using AfLCD_SEG8_PB4 = AnyAFR<Port::PB, 4, AF::k11>;
using AfLCD_SEG9_PB5 = AnyAFR<Port::PB, 5, AF::k11>;
using AfLCD_VLCD_PB2 = AnyAFR<Port::PB, 2, AF::k11>;
using AfLCD_VLCD_PC3 = AnyAFR<Port::PC, 3, AF::k11>;
#if defined(GPIOD_BASE)
using AfLCD_COM7_PD2 = AnyAFR<Port::PD, 2, AF::k11>;
using AfLCD_SEG28_PD8 = AnyAFR<Port::PD, 8, AF::k11>;
using AfLCD_SEG29_PD9 = AnyAFR<Port::PD, 9, AF::k11>;
using AfLCD_SEG30_PD10 = AnyAFR<Port::PD, 10, AF::k11>;
using AfLCD_SEG31_PD2 = AnyAFR<Port::PD, 2, AF::k11>;
using AfLCD_SEG31_PD11 = AnyAFR<Port::PD, 11, AF::k11>;
using AfLCD_SEG32_PD12 = AnyAFR<Port::PD, 12, AF::k11>;
using AfLCD_SEG33_PD13 = AnyAFR<Port::PD, 13, AF::k11>;
using AfLCD_SEG34_PD14 = AnyAFR<Port::PD, 14, AF::k11>;
using AfLCD_SEG35_PD15 = AnyAFR<Port::PD, 15, AF::k11>;
using AfLCD_SEG43_PD2 = AnyAFR<Port::PD, 2, AF::k11>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfLCD_SEG36_PE0 = AnyAFR<Port::PE, 0, AF::k11>;
using AfLCD_SEG37_PE1 = AnyAFR<Port::PE, 1, AF::k11>;
using AfLCD_SEG38_PE2 = AnyAFR<Port::PE, 2, AF::k11>;
using AfLCD_SEG39_PE3 = AnyAFR<Port::PE, 3, AF::k11>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(LCD_BASE)

// LPTIM1
#if defined(LPTIM1_BASE)
using AfLPTIM1_ETR_PB6 = AnyAFR<Port::PB, 6, AF::k1>;
using AfLPTIM1_ETR_PC3 = AnyAFR<Port::PC, 3, AF::k1>;
using AfLPTIM1_IN1_PB5 = AnyAFR<Port::PB, 5, AF::k1>;
using AfLPTIM1_IN1_PC0 = AnyAFR<Port::PC, 0, AF::k1>;
using AfLPTIM1_IN2_PB7 = AnyAFR<Port::PB, 7, AF::k1>;
using AfLPTIM1_IN2_PC2 = AnyAFR<Port::PC, 2, AF::k1>;
using AfLPTIM1_OUT_PA14 = AnyAFR<Port::PA, 14, AF::k1>;
using AfLPTIM1_OUT_PB2 = AnyAFR<Port::PB, 2, AF::k1>;
using AfLPTIM1_OUT_PC1 = AnyAFR<Port::PC, 1, AF::k1>;
#if defined(GPIOG_BASE)
using AfLPTIM1_ETR_PG12 = AnyAFR<Port::PG, 12, AF::k1>;
using AfLPTIM1_IN1_PG10 = AnyAFR<Port::PG, 10, AF::k1>;
using AfLPTIM1_IN2_PG11 = AnyAFR<Port::PG, 11, AF::k1>;
using AfLPTIM1_OUT_PG15 = AnyAFR<Port::PG, 15, AF::k1>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(LPTIM1_BASE)

// LPTIM2
#if defined(LPTIM2_BASE)
using AfLPTIM2_ETR_PA5 = AnyAFR<Port::PA, 5, AF::k14>;
using AfLPTIM2_ETR_PC3 = AnyAFR<Port::PC, 3, AF::k14>;
using AfLPTIM2_IN1_PB1 = AnyAFR<Port::PB, 1, AF::k14>;
using AfLPTIM2_IN1_PC0 = AnyAFR<Port::PC, 0, AF::k14>;
using AfLPTIM2_OUT_PA4 = AnyAFR<Port::PA, 4, AF::k14>;
using AfLPTIM2_OUT_PA8 = AnyAFR<Port::PA, 8, AF::k14>;
#if defined(GPIOD_BASE)
using AfLPTIM2_ETR_PD11 = AnyAFR<Port::PD, 11, AF::k14>;
using AfLPTIM2_IN1_PD12 = AnyAFR<Port::PD, 12, AF::k14>;
using AfLPTIM2_OUT_PD13 = AnyAFR<Port::PD, 13, AF::k14>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(LPTIM2_BASE)

// LPUART1
#if defined(LPUART1_BASE)
using AfLPUART1_CTS_PA6 = AnyAFR<Port::PA, 6, AF::k8>;
using AfLPUART1_CTS_PB13 = AnyAFR<Port::PB, 13, AF::k8>;
using AfLPUART1_DE_PB1 = AnyAFR<Port::PB, 1, AF::k8>;
using AfLPUART1_DE_PB12 = AnyAFR<Port::PB, 12, AF::k8>;
using AfLPUART1_RTS_PB1 = AnyAFR<Port::PB, 1, AF::k8>;
using AfLPUART1_RTS_PB12 = AnyAFR<Port::PB, 12, AF::k8>;
using AfLPUART1_RX_PA3 = AnyAFR<Port::PA, 3, AF::k8>;
using AfLPUART1_RX_PB10 = AnyAFR<Port::PB, 10, AF::k8>;
using AfLPUART1_RX_PC0 = AnyAFR<Port::PC, 0, AF::k8>;
using AfLPUART1_TX_PA2 = AnyAFR<Port::PA, 2, AF::k8>;
using AfLPUART1_TX_PB11 = AnyAFR<Port::PB, 11, AF::k8>;
using AfLPUART1_TX_PC1 = AnyAFR<Port::PC, 1, AF::k8>;
#if defined(GPIOG_BASE)
using AfLPUART1_CTS_PG5 = AnyAFR<Port::PG, 5, AF::k8>;
using AfLPUART1_DE_PG6 = AnyAFR<Port::PG, 6, AF::k8>;
using AfLPUART1_RTS_PG6 = AnyAFR<Port::PG, 6, AF::k8>;
using AfLPUART1_RX_PG8 = AnyAFR<Port::PG, 8, AF::k8>;
using AfLPUART1_TX_PG7 = AnyAFR<Port::PG, 7, AF::k8>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(LPUART1_BASE)

// OTG
#if defined(OTG_BASE)
using AfOTG_FS_CRS_SYNC_PB3 = AnyAFR<Port::PB, 3, AF::k10>;
using AfOTG_FS_DM_PA11 = AnyAFR<Port::PA, 11, AF::k10>;
using AfOTG_FS_DP_PA12 = AnyAFR<Port::PA, 12, AF::k10>;
using AfOTG_FS_ID_PA10 = AnyAFR<Port::PA, 10, AF::k10>;
using AfOTG_FS_NOE_PA13 = AnyAFR<Port::PA, 13, AF::k10>;
using AfOTG_FS_NOE_PC9 = AnyAFR<Port::PC, 9, AF::k10>;
using AfOTG_FS_SOF_PA8 = AnyAFR<Port::PA, 8, AF::k10>;
using AfOTG_FS_SOF_PA14 = AnyAFR<Port::PA, 14, AF::k10>;
#endif	// defined(OTG_BASE)

// QUADSPI
#if defined(QUADSPI)
using AfQUADSPI_BK1_IO0_PB1 = AnyAFR<Port::PB, 1, AF::k10>;
using AfQUADSPI_BK1_IO1_PB0 = AnyAFR<Port::PB, 0, AF::k10>;
using AfQUADSPI_BK1_IO2_PA7 = AnyAFR<Port::PA, 7, AF::k10>;
using AfQUADSPI_BK1_IO3_PA6 = AnyAFR<Port::PA, 6, AF::k10>;
using AfQUADSPI_BK1_NCS_PA2 = AnyAFR<Port::PA, 2, AF::k10>;
using AfQUADSPI_BK1_NCS_PB11 = AnyAFR<Port::PB, 11, AF::k10>;
using AfQUADSPI_BK2_IO0_PC1 = AnyAFR<Port::PC, 1, AF::k10>;
using AfQUADSPI_BK2_IO1_PC2 = AnyAFR<Port::PC, 2, AF::k10>;
using AfQUADSPI_BK2_IO2_PC3 = AnyAFR<Port::PC, 3, AF::k10>;
using AfQUADSPI_BK2_IO3_PC4 = AnyAFR<Port::PC, 4, AF::k10>;
using AfQUADSPI_BK2_NCS_PC11 = AnyAFR<Port::PC, 11, AF::k5>;
using AfQUADSPI_CLK_PA3 = AnyAFR<Port::PA, 3, AF::k10>;
using AfQUADSPI_CLK_PB10 = AnyAFR<Port::PB, 10, AF::k10>;
#if defined(GPIOD_BASE)
using AfQUADSPI_BK2_IO0_PD4 = AnyAFR<Port::PD, 4, AF::k10>;
using AfQUADSPI_BK2_IO1_PD5 = AnyAFR<Port::PD, 5, AF::k10>;
using AfQUADSPI_BK2_IO1_PD6 = AnyAFR<Port::PD, 6, AF::k5>;
using AfQUADSPI_BK2_IO2_PD6 = AnyAFR<Port::PD, 6, AF::k10>;
using AfQUADSPI_BK2_IO3_PD7 = AnyAFR<Port::PD, 7, AF::k10>;
using AfQUADSPI_BK2_NCS_PD3 = AnyAFR<Port::PD, 3, AF::k10>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfQUADSPI_BK1_IO0_PE12 = AnyAFR<Port::PE, 12, AF::k10>;
using AfQUADSPI_BK1_IO1_PE13 = AnyAFR<Port::PE, 13, AF::k10>;
using AfQUADSPI_BK1_IO2_PE14 = AnyAFR<Port::PE, 14, AF::k10>;
using AfQUADSPI_BK1_IO3_PE15 = AnyAFR<Port::PE, 15, AF::k10>;
using AfQUADSPI_BK1_NCS_PE11 = AnyAFR<Port::PE, 11, AF::k10>;
using AfQUADSPI_CLK_PE10 = AnyAFR<Port::PE, 10, AF::k10>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfQUADSPI_BK1_IO0_PF8 = AnyAFR<Port::PF, 8, AF::k10>;
using AfQUADSPI_BK1_IO1_PF9 = AnyAFR<Port::PF, 9, AF::k10>;
using AfQUADSPI_BK1_IO2_PF7 = AnyAFR<Port::PF, 7, AF::k10>;
using AfQUADSPI_BK1_IO3_PF6 = AnyAFR<Port::PF, 6, AF::k10>;
using AfQUADSPI_CLK_PF10 = AnyAFR<Port::PF, 10, AF::k3>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOH_BASE)
using AfQUADSPI_BK2_IO0_PH2 = AnyAFR<Port::PH, 2, AF::k3>;
#endif	// defined(GPIOH_BASE)
#endif	// defined(QUADSPI)

// RTC
#if defined(RTC_BASE)
using AfRTC_OUT_PB2 = AnyAFR<Port::PB, 2, AF::k0>;
using AfRTC_REFIN_PB15 = AnyAFR<Port::PB, 15, AF::k0>;
#endif	// defined(RTC_BASE)

// SAI1
#if defined(SAI1_BASE)
using AfSAI1_EXTCLK_PA0 = AnyAFR<Port::PA, 0, AF::k13>;
using AfSAI1_EXTCLK_PB0 = AnyAFR<Port::PB, 0, AF::k13>;
using AfSAI1_FS_A_PA9 = AnyAFR<Port::PA, 9, AF::k13>;
using AfSAI1_FS_A_PB9 = AnyAFR<Port::PB, 9, AF::k13>;
using AfSAI1_FS_B_PA4 = AnyAFR<Port::PA, 4, AF::k13>;
using AfSAI1_FS_B_PA14 = AnyAFR<Port::PA, 14, AF::k13>;
using AfSAI1_FS_B_PB6 = AnyAFR<Port::PB, 6, AF::k13>;
using AfSAI1_MCLK_A_PA3 = AnyAFR<Port::PA, 3, AF::k13>;
using AfSAI1_MCLK_A_PB8 = AnyAFR<Port::PB, 8, AF::k13>;
using AfSAI1_MCLK_B_PB4 = AnyAFR<Port::PB, 4, AF::k13>;
using AfSAI1_SCK_A_PA8 = AnyAFR<Port::PA, 8, AF::k13>;
using AfSAI1_SCK_A_PB10 = AnyAFR<Port::PB, 10, AF::k13>;
using AfSAI1_SCK_B_PB3 = AnyAFR<Port::PB, 3, AF::k13>;
using AfSAI1_SD_A_PA10 = AnyAFR<Port::PA, 10, AF::k13>;
using AfSAI1_SD_A_PC1 = AnyAFR<Port::PC, 1, AF::k13>;
using AfSAI1_SD_A_PC3 = AnyAFR<Port::PC, 3, AF::k13>;
using AfSAI1_SD_B_PA13 = AnyAFR<Port::PA, 13, AF::k13>;
using AfSAI1_SD_B_PB5 = AnyAFR<Port::PB, 5, AF::k13>;
#if defined(GPIOD_BASE)
using AfSAI1_SD_A_PD6 = AnyAFR<Port::PD, 6, AF::k13>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfSAI1_FS_A_PE4 = AnyAFR<Port::PE, 4, AF::k13>;
using AfSAI1_FS_B_PE9 = AnyAFR<Port::PE, 9, AF::k13>;
using AfSAI1_MCLK_A_PE2 = AnyAFR<Port::PE, 2, AF::k13>;
using AfSAI1_MCLK_B_PE10 = AnyAFR<Port::PE, 10, AF::k13>;
using AfSAI1_SCK_A_PE5 = AnyAFR<Port::PE, 5, AF::k13>;
using AfSAI1_SCK_B_PE8 = AnyAFR<Port::PE, 8, AF::k13>;
using AfSAI1_SD_A_PE6 = AnyAFR<Port::PE, 6, AF::k13>;
using AfSAI1_SD_B_PE3 = AnyAFR<Port::PE, 3, AF::k13>;
using AfSAI1_SD_B_PE7 = AnyAFR<Port::PE, 7, AF::k13>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfSAI1_FS_B_PF9 = AnyAFR<Port::PF, 9, AF::k13>;
using AfSAI1_MCLK_B_PF7 = AnyAFR<Port::PF, 7, AF::k13>;
using AfSAI1_SCK_B_PF8 = AnyAFR<Port::PF, 8, AF::k13>;
using AfSAI1_SD_B_PF6 = AnyAFR<Port::PF, 6, AF::k13>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfSAI1_MCLK_A_PG7 = AnyAFR<Port::PG, 7, AF::k13>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(SAI1_BASE)

// SAI2
#if defined(SAI2_BASE)
using AfSAI2_EXTCLK_PA2 = AnyAFR<Port::PA, 2, AF::k13>;
using AfSAI2_EXTCLK_PC9 = AnyAFR<Port::PC, 9, AF::k13>;
using AfSAI2_FS_A_PB12 = AnyAFR<Port::PB, 12, AF::k13>;
using AfSAI2_FS_B_PA15 = AnyAFR<Port::PA, 15, AF::k13>;
using AfSAI2_MCLK_A_PB14 = AnyAFR<Port::PB, 14, AF::k13>;
using AfSAI2_MCLK_A_PC6 = AnyAFR<Port::PC, 6, AF::k13>;
using AfSAI2_MCLK_B_PC7 = AnyAFR<Port::PC, 7, AF::k13>;
using AfSAI2_MCLK_B_PC11 = AnyAFR<Port::PC, 11, AF::k13>;
using AfSAI2_SCK_A_PB13 = AnyAFR<Port::PB, 13, AF::k13>;
using AfSAI2_SCK_B_PC10 = AnyAFR<Port::PC, 10, AF::k13>;
using AfSAI2_SD_A_PB15 = AnyAFR<Port::PB, 15, AF::k13>;
using AfSAI2_SD_B_PC12 = AnyAFR<Port::PC, 12, AF::k13>;
#if defined(GPIOD_BASE)
using AfSAI2_FS_A_PD12 = AnyAFR<Port::PD, 12, AF::k13>;
using AfSAI2_MCLK_A_PD9 = AnyAFR<Port::PD, 9, AF::k13>;
using AfSAI2_SCK_A_PD10 = AnyAFR<Port::PD, 10, AF::k13>;
using AfSAI2_SD_A_PD11 = AnyAFR<Port::PD, 11, AF::k13>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOG_BASE)
using AfSAI2_FS_A_PG10 = AnyAFR<Port::PG, 10, AF::k13>;
using AfSAI2_FS_B_PG3 = AnyAFR<Port::PG, 3, AF::k13>;
using AfSAI2_MCLK_A_PG11 = AnyAFR<Port::PG, 11, AF::k13>;
using AfSAI2_MCLK_B_PG4 = AnyAFR<Port::PG, 4, AF::k13>;
using AfSAI2_SCK_A_PG9 = AnyAFR<Port::PG, 9, AF::k13>;
using AfSAI2_SCK_B_PG2 = AnyAFR<Port::PG, 2, AF::k13>;
using AfSAI2_SD_A_PG12 = AnyAFR<Port::PG, 12, AF::k13>;
using AfSAI2_SD_B_PG5 = AnyAFR<Port::PG, 5, AF::k13>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(SAI2_BASE)

// SDMMC1
#if defined(SDMMC1_BASE)
using AfSDMMC1_CK_PC12 = AnyAFR<Port::PC, 12, AF::k12>;
using AfSDMMC1_D0_PC8 = AnyAFR<Port::PC, 8, AF::k12>;
using AfSDMMC1_D1_PC9 = AnyAFR<Port::PC, 9, AF::k12>;
using AfSDMMC1_D2_PC10 = AnyAFR<Port::PC, 10, AF::k12>;
using AfSDMMC1_D3_PC11 = AnyAFR<Port::PC, 11, AF::k12>;
using AfSDMMC1_D4_PB8 = AnyAFR<Port::PB, 8, AF::k12>;
using AfSDMMC1_D5_PB9 = AnyAFR<Port::PB, 9, AF::k12>;
using AfSDMMC1_D6_PC6 = AnyAFR<Port::PC, 6, AF::k12>;
using AfSDMMC1_D7_PC7 = AnyAFR<Port::PC, 7, AF::k12>;
#if defined(GPIOD_BASE)
using AfSDMMC1_CMD_PD2 = AnyAFR<Port::PD, 2, AF::k12>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(SDMMC1_BASE)

// SPI1
#if defined(SPI1_BASE)
using AfSPI1_MISO_PA6 = AnyAFR<Port::PA, 6, AF::k5>;
using AfSPI1_MISO_PA11 = AnyAFR<Port::PA, 11, AF::k5>;
using AfSPI1_MISO_PB4 = AnyAFR<Port::PB, 4, AF::k5>;
using AfSPI1_MOSI_PA7 = AnyAFR<Port::PA, 7, AF::k5>;
using AfSPI1_MOSI_PA12 = AnyAFR<Port::PA, 12, AF::k5>;
using AfSPI1_MOSI_PB5 = AnyAFR<Port::PB, 5, AF::k5>;
using AfSPI1_NSS_PA4 = AnyAFR<Port::PA, 4, AF::k5>;
using AfSPI1_NSS_PA15 = AnyAFR<Port::PA, 15, AF::k5>;
using AfSPI1_NSS_PB0 = AnyAFR<Port::PB, 0, AF::k5>;
using AfSPI1_SCK_PA1 = AnyAFR<Port::PA, 1, AF::k5>;
using AfSPI1_SCK_PA5 = AnyAFR<Port::PA, 5, AF::k5>;
using AfSPI1_SCK_PB3 = AnyAFR<Port::PB, 3, AF::k5>;
#if defined(GPIOE_BASE)
using AfSPI1_MISO_PE14 = AnyAFR<Port::PE, 14, AF::k5>;
using AfSPI1_MOSI_PE15 = AnyAFR<Port::PE, 15, AF::k5>;
using AfSPI1_NSS_PE12 = AnyAFR<Port::PE, 12, AF::k5>;
using AfSPI1_SCK_PE13 = AnyAFR<Port::PE, 13, AF::k5>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOG_BASE)
using AfSPI1_MISO_PG3 = AnyAFR<Port::PG, 3, AF::k5>;
using AfSPI1_MOSI_PG4 = AnyAFR<Port::PG, 4, AF::k5>;
using AfSPI1_NSS_PG5 = AnyAFR<Port::PG, 5, AF::k5>;
using AfSPI1_SCK_PG2 = AnyAFR<Port::PG, 2, AF::k5>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(SPI1_BASE)

// SPI2
#if defined(SPI2_BASE)
using AfSPI2_MISO_PB14 = AnyAFR<Port::PB, 14, AF::k5>;
using AfSPI2_MISO_PC2 = AnyAFR<Port::PC, 2, AF::k5>;
using AfSPI2_MOSI_PB15 = AnyAFR<Port::PB, 15, AF::k5>;
using AfSPI2_MOSI_PC1 = AnyAFR<Port::PC, 1, AF::k3>;
using AfSPI2_MOSI_PC3 = AnyAFR<Port::PC, 3, AF::k5>;
using AfSPI2_NSS_PB9 = AnyAFR<Port::PB, 9, AF::k5>;
using AfSPI2_NSS_PB12 = AnyAFR<Port::PB, 12, AF::k5>;
using AfSPI2_SCK_PA9 = AnyAFR<Port::PA, 9, AF::k3>;
using AfSPI2_SCK_PB10 = AnyAFR<Port::PB, 10, AF::k5>;
using AfSPI2_SCK_PB13 = AnyAFR<Port::PB, 13, AF::k5>;
#if defined(GPIOD_BASE)
using AfSPI2_MISO_PD3 = AnyAFR<Port::PD, 3, AF::k5>;
using AfSPI2_MOSI_PD4 = AnyAFR<Port::PD, 4, AF::k5>;
using AfSPI2_NSS_PD0 = AnyAFR<Port::PD, 0, AF::k5>;
using AfSPI2_SCK_PD1 = AnyAFR<Port::PD, 1, AF::k5>;
using AfSPI2_SCK_PD3 = AnyAFR<Port::PD, 3, AF::k3>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOI_BASE)
using AfSPI2_MISO_PI2 = AnyAFR<Port::PI, 2, AF::k5>;
using AfSPI2_MOSI_PI3 = AnyAFR<Port::PI, 3, AF::k5>;
using AfSPI2_NSS_PI0 = AnyAFR<Port::PI, 0, AF::k5>;
using AfSPI2_SCK_PI1 = AnyAFR<Port::PI, 1, AF::k5>;
#endif	// defined(GPIOI_BASE)
#endif	// defined(SPI2_BASE)

// SPI3
#if defined(SPI3_BASE)
using AfSPI3_MISO_PB4 = AnyAFR<Port::PB, 4, AF::k6>;
using AfSPI3_MISO_PC11 = AnyAFR<Port::PC, 11, AF::k6>;
using AfSPI3_MOSI_PB5 = AnyAFR<Port::PB, 5, AF::k6>;
using AfSPI3_MOSI_PC12 = AnyAFR<Port::PC, 12, AF::k6>;
using AfSPI3_NSS_PA4 = AnyAFR<Port::PA, 4, AF::k6>;
using AfSPI3_NSS_PA15 = AnyAFR<Port::PA, 15, AF::k6>;
using AfSPI3_SCK_PB3 = AnyAFR<Port::PB, 3, AF::k6>;
using AfSPI3_SCK_PC10 = AnyAFR<Port::PC, 10, AF::k6>;
#if defined(GPIOG_BASE)
using AfSPI3_MISO_PG10 = AnyAFR<Port::PG, 10, AF::k6>;
using AfSPI3_MOSI_PG11 = AnyAFR<Port::PG, 11, AF::k6>;
using AfSPI3_NSS_PG12 = AnyAFR<Port::PG, 12, AF::k6>;
using AfSPI3_SCK_PG9 = AnyAFR<Port::PG, 9, AF::k6>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(SPI3_BASE)

// SWPMI1
#if defined(SWPMI1_BASE)
using AfSWPMI1_IO_PA8 = AnyAFR<Port::PA, 8, AF::k12>;
using AfSWPMI1_IO_PB12 = AnyAFR<Port::PB, 12, AF::k12>;
using AfSWPMI1_RX_PA14 = AnyAFR<Port::PA, 14, AF::k12>;
using AfSWPMI1_RX_PB14 = AnyAFR<Port::PB, 14, AF::k12>;
using AfSWPMI1_SUSPEND_PA15 = AnyAFR<Port::PA, 15, AF::k12>;
using AfSWPMI1_SUSPEND_PB15 = AnyAFR<Port::PB, 15, AF::k12>;
using AfSWPMI1_TX_PA13 = AnyAFR<Port::PA, 13, AF::k12>;
using AfSWPMI1_TX_PB13 = AnyAFR<Port::PB, 13, AF::k12>;
#endif	// defined(SWPMI1_BASE)

// TIM1
#if defined(TIM1_BASE)
using AfTIM1_BKIN_PA6 = AnyAFR<Port::PA, 6, AF::k1>;
using AfTIM1_BKIN_PB12 = AnyAFR<Port::PB, 12, AF::k1>;
using AfTIM1_BKIN2_PA11 = AnyAFR<Port::PA, 11, AF::k2>;
using AfTIM1_BKIN2_COMP1_PA11 = AnyAFR<Port::PA, 11, AF::k12>;
using AfTIM1_BKIN_COMP2_PA6 = AnyAFR<Port::PA, 6, AF::k12>;
using AfTIM1_BKIN_COMP2_PB12 = AnyAFR<Port::PB, 12, AF::k3>;
using AfTIM1_CH1_PA8 = AnyAFR<Port::PA, 8, AF::k1>;
using AfTIM1_CH1N_PA7 = AnyAFR<Port::PA, 7, AF::k1>;
using AfTIM1_CH1N_PB13 = AnyAFR<Port::PB, 13, AF::k1>;
using AfTIM1_CH2_PA9 = AnyAFR<Port::PA, 9, AF::k1>;
using AfTIM1_CH2N_PB0 = AnyAFR<Port::PB, 0, AF::k1>;
using AfTIM1_CH2N_PB14 = AnyAFR<Port::PB, 14, AF::k1>;
using AfTIM1_CH3_PA10 = AnyAFR<Port::PA, 10, AF::k1>;
using AfTIM1_CH3N_PB1 = AnyAFR<Port::PB, 1, AF::k1>;
using AfTIM1_CH3N_PB15 = AnyAFR<Port::PB, 15, AF::k1>;
using AfTIM1_CH4_PA11 = AnyAFR<Port::PA, 11, AF::k1>;
using AfTIM1_ETR_PA12 = AnyAFR<Port::PA, 12, AF::k1>;
#if defined(GPIOE_BASE)
using AfTIM1_BKIN_PE15 = AnyAFR<Port::PE, 15, AF::k1>;
using AfTIM1_BKIN2_PE14 = AnyAFR<Port::PE, 14, AF::k2>;
using AfTIM1_BKIN2_COMP2_PE14 = AnyAFR<Port::PE, 14, AF::k3>;
using AfTIM1_BKIN_COMP1_PE15 = AnyAFR<Port::PE, 15, AF::k3>;
using AfTIM1_CH1_PE9 = AnyAFR<Port::PE, 9, AF::k1>;
using AfTIM1_CH1N_PE8 = AnyAFR<Port::PE, 8, AF::k1>;
using AfTIM1_CH2_PE11 = AnyAFR<Port::PE, 11, AF::k1>;
using AfTIM1_CH2N_PE10 = AnyAFR<Port::PE, 10, AF::k1>;
using AfTIM1_CH3_PE13 = AnyAFR<Port::PE, 13, AF::k1>;
using AfTIM1_CH3N_PE12 = AnyAFR<Port::PE, 12, AF::k1>;
using AfTIM1_CH4_PE14 = AnyAFR<Port::PE, 14, AF::k1>;
using AfTIM1_ETR_PE7 = AnyAFR<Port::PE, 7, AF::k1>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM1_BASE)

// TIM2
#if defined(TIM2_BASE)
using AfTIM2_CH1_PA0 = AnyAFR<Port::PA, 0, AF::k1>;
using AfTIM2_CH1_PA5 = AnyAFR<Port::PA, 5, AF::k1>;
using AfTIM2_CH1_PA15 = AnyAFR<Port::PA, 15, AF::k1>;
using AfTIM2_CH2_PA1 = AnyAFR<Port::PA, 1, AF::k1>;
using AfTIM2_CH2_PB3 = AnyAFR<Port::PB, 3, AF::k1>;
using AfTIM2_CH3_PA2 = AnyAFR<Port::PA, 2, AF::k1>;
using AfTIM2_CH3_PB10 = AnyAFR<Port::PB, 10, AF::k1>;
using AfTIM2_CH4_PA3 = AnyAFR<Port::PA, 3, AF::k1>;
using AfTIM2_CH4_PB11 = AnyAFR<Port::PB, 11, AF::k1>;
using AfTIM2_ETR_PA0 = AnyAFR<Port::PA, 0, AF::k14>;
using AfTIM2_ETR_PA5 = AnyAFR<Port::PA, 5, AF::k2>;
using AfTIM2_ETR_PA15 = AnyAFR<Port::PA, 15, AF::k2>;
#endif	// defined(TIM2_BASE)

// TIM3
#if defined(TIM3_BASE)
using AfTIM3_CH1_PA6 = AnyAFR<Port::PA, 6, AF::k2>;
using AfTIM3_CH1_PB4 = AnyAFR<Port::PB, 4, AF::k2>;
using AfTIM3_CH1_PC6 = AnyAFR<Port::PC, 6, AF::k2>;
using AfTIM3_CH2_PA7 = AnyAFR<Port::PA, 7, AF::k2>;
using AfTIM3_CH2_PB5 = AnyAFR<Port::PB, 5, AF::k2>;
using AfTIM3_CH2_PC7 = AnyAFR<Port::PC, 7, AF::k2>;
using AfTIM3_CH3_PB0 = AnyAFR<Port::PB, 0, AF::k2>;
using AfTIM3_CH3_PC8 = AnyAFR<Port::PC, 8, AF::k2>;
using AfTIM3_CH4_PB1 = AnyAFR<Port::PB, 1, AF::k2>;
using AfTIM3_CH4_PC9 = AnyAFR<Port::PC, 9, AF::k2>;
#if defined(GPIOD_BASE)
using AfTIM3_ETR_PD2 = AnyAFR<Port::PD, 2, AF::k2>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfTIM3_CH1_PE3 = AnyAFR<Port::PE, 3, AF::k2>;
using AfTIM3_CH2_PE4 = AnyAFR<Port::PE, 4, AF::k2>;
using AfTIM3_CH3_PE5 = AnyAFR<Port::PE, 5, AF::k2>;
using AfTIM3_CH4_PE6 = AnyAFR<Port::PE, 6, AF::k2>;
using AfTIM3_ETR_PE2 = AnyAFR<Port::PE, 2, AF::k2>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM3_BASE)

// TIM4
#if defined(TIM4_BASE)
using AfTIM4_CH1_PB6 = AnyAFR<Port::PB, 6, AF::k2>;
using AfTIM4_CH2_PB7 = AnyAFR<Port::PB, 7, AF::k2>;
using AfTIM4_CH3_PB8 = AnyAFR<Port::PB, 8, AF::k2>;
using AfTIM4_CH4_PB9 = AnyAFR<Port::PB, 9, AF::k2>;
#if defined(GPIOD_BASE)
using AfTIM4_CH1_PD12 = AnyAFR<Port::PD, 12, AF::k2>;
using AfTIM4_CH2_PD13 = AnyAFR<Port::PD, 13, AF::k2>;
using AfTIM4_CH3_PD14 = AnyAFR<Port::PD, 14, AF::k2>;
using AfTIM4_CH4_PD15 = AnyAFR<Port::PD, 15, AF::k2>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfTIM4_ETR_PE0 = AnyAFR<Port::PE, 0, AF::k2>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM4_BASE)

// TIM5
#if defined(TIM5_BASE)
using AfTIM5_CH1_PA0 = AnyAFR<Port::PA, 0, AF::k2>;
using AfTIM5_CH2_PA1 = AnyAFR<Port::PA, 1, AF::k2>;
using AfTIM5_CH3_PA2 = AnyAFR<Port::PA, 2, AF::k2>;
using AfTIM5_CH4_PA3 = AnyAFR<Port::PA, 3, AF::k2>;
#if defined(GPIOF_BASE)
using AfTIM5_CH1_PF6 = AnyAFR<Port::PF, 6, AF::k2>;
using AfTIM5_CH2_PF7 = AnyAFR<Port::PF, 7, AF::k2>;
using AfTIM5_CH3_PF8 = AnyAFR<Port::PF, 8, AF::k2>;
using AfTIM5_CH4_PF9 = AnyAFR<Port::PF, 9, AF::k2>;
using AfTIM5_ETR_PF6 = AnyAFR<Port::PF, 6, AF::k1>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOH_BASE)
using AfTIM5_CH1_PH10 = AnyAFR<Port::PH, 10, AF::k2>;
using AfTIM5_CH2_PH11 = AnyAFR<Port::PH, 11, AF::k2>;
using AfTIM5_CH3_PH12 = AnyAFR<Port::PH, 12, AF::k2>;
#endif	// defined(GPIOH_BASE)
#if defined(GPIOI_BASE)
using AfTIM5_CH4_PI0 = AnyAFR<Port::PI, 0, AF::k2>;
#endif	// defined(GPIOI_BASE)
#endif	// defined(TIM5_BASE)

// TIM8
#if defined(TIM8_BASE)
using AfTIM8_BKIN_PA6 = AnyAFR<Port::PA, 6, AF::k3>;
using AfTIM8_BKIN_PB7 = AnyAFR<Port::PB, 7, AF::k3>;
using AfTIM8_BKIN2_PB6 = AnyAFR<Port::PB, 6, AF::k3>;
using AfTIM8_BKIN2_PC9 = AnyAFR<Port::PC, 9, AF::k1>;
using AfTIM8_BKIN2_COMP1_PC9 = AnyAFR<Port::PC, 9, AF::k14>;
using AfTIM8_BKIN2_COMP2_PB6 = AnyAFR<Port::PB, 6, AF::k12>;
using AfTIM8_BKIN_COMP1_PB7 = AnyAFR<Port::PB, 7, AF::k13>;
using AfTIM8_BKIN_COMP2_PA6 = AnyAFR<Port::PA, 6, AF::k13>;
using AfTIM8_CH1_PC6 = AnyAFR<Port::PC, 6, AF::k3>;
using AfTIM8_CH1N_PA5 = AnyAFR<Port::PA, 5, AF::k3>;
using AfTIM8_CH1N_PA7 = AnyAFR<Port::PA, 7, AF::k3>;
using AfTIM8_CH2_PC7 = AnyAFR<Port::PC, 7, AF::k3>;
using AfTIM8_CH2N_PB0 = AnyAFR<Port::PB, 0, AF::k3>;
using AfTIM8_CH2N_PB14 = AnyAFR<Port::PB, 14, AF::k3>;
using AfTIM8_CH3_PC8 = AnyAFR<Port::PC, 8, AF::k3>;
using AfTIM8_CH3N_PB1 = AnyAFR<Port::PB, 1, AF::k3>;
using AfTIM8_CH3N_PB15 = AnyAFR<Port::PB, 15, AF::k3>;
using AfTIM8_CH4_PC9 = AnyAFR<Port::PC, 9, AF::k3>;
using AfTIM8_ETR_PA0 = AnyAFR<Port::PA, 0, AF::k3>;
#if defined(GPIOH_BASE)
using AfTIM8_CH1N_PH13 = AnyAFR<Port::PH, 13, AF::k3>;
using AfTIM8_CH2N_PH14 = AnyAFR<Port::PH, 14, AF::k3>;
using AfTIM8_CH3N_PH15 = AnyAFR<Port::PH, 15, AF::k3>;
#endif	// defined(GPIOH_BASE)
#if defined(GPIOI_BASE)
using AfTIM8_BKIN_PI4 = AnyAFR<Port::PI, 4, AF::k3>;
using AfTIM8_CH1_PI5 = AnyAFR<Port::PI, 5, AF::k3>;
using AfTIM8_CH2_PI6 = AnyAFR<Port::PI, 6, AF::k3>;
using AfTIM8_CH3_PI7 = AnyAFR<Port::PI, 7, AF::k3>;
using AfTIM8_CH4_PI2 = AnyAFR<Port::PI, 2, AF::k3>;
using AfTIM8_ETR_PI3 = AnyAFR<Port::PI, 3, AF::k3>;
#endif	// defined(GPIOI_BASE)
#endif	// defined(TIM8_BASE)

// TIM15
#if defined(TIM15_BASE)
using AfTIM15_BKIN_PA9 = AnyAFR<Port::PA, 9, AF::k14>;
using AfTIM15_BKIN_PB12 = AnyAFR<Port::PB, 12, AF::k14>;
using AfTIM15_CH1_PA2 = AnyAFR<Port::PA, 2, AF::k14>;
using AfTIM15_CH1_PB14 = AnyAFR<Port::PB, 14, AF::k14>;
using AfTIM15_CH1N_PA1 = AnyAFR<Port::PA, 1, AF::k14>;
using AfTIM15_CH1N_PB13 = AnyAFR<Port::PB, 13, AF::k14>;
using AfTIM15_CH2_PA3 = AnyAFR<Port::PA, 3, AF::k14>;
using AfTIM15_CH2_PB15 = AnyAFR<Port::PB, 15, AF::k14>;
#if defined(GPIOF_BASE)
using AfTIM15_CH1_PF9 = AnyAFR<Port::PF, 9, AF::k14>;
using AfTIM15_CH2_PF10 = AnyAFR<Port::PF, 10, AF::k14>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfTIM15_CH1_PG10 = AnyAFR<Port::PG, 10, AF::k14>;
using AfTIM15_CH1N_PG9 = AnyAFR<Port::PG, 9, AF::k14>;
using AfTIM15_CH2_PG11 = AnyAFR<Port::PG, 11, AF::k14>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(TIM15_BASE)

// TIM16
#if defined(TIM16_BASE)
using AfTIM16_BKIN_PB5 = AnyAFR<Port::PB, 5, AF::k14>;
using AfTIM16_CH1_PA6 = AnyAFR<Port::PA, 6, AF::k14>;
using AfTIM16_CH1_PB8 = AnyAFR<Port::PB, 8, AF::k14>;
using AfTIM16_CH1N_PB6 = AnyAFR<Port::PB, 6, AF::k14>;
#if defined(GPIOE_BASE)
using AfTIM16_CH1_PE0 = AnyAFR<Port::PE, 0, AF::k14>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM16_BASE)

// TIM17
#if defined(TIM17_BASE)
using AfTIM17_BKIN_PA10 = AnyAFR<Port::PA, 10, AF::k14>;
using AfTIM17_BKIN_PB4 = AnyAFR<Port::PB, 4, AF::k14>;
using AfTIM17_CH1_PA7 = AnyAFR<Port::PA, 7, AF::k14>;
using AfTIM17_CH1_PB9 = AnyAFR<Port::PB, 9, AF::k14>;
using AfTIM17_CH1N_PB7 = AnyAFR<Port::PB, 7, AF::k14>;
#if defined(GPIOE_BASE)
using AfTIM17_CH1_PE1 = AnyAFR<Port::PE, 1, AF::k14>;
#endif	// defined(GPIOE_BASE)
#endif	// defined(TIM17_BASE)

// TSC
#if defined(TSC_BASE)
using AfTSC_G1_IO1_PB12 = AnyAFR<Port::PB, 12, AF::k9>;
using AfTSC_G1_IO2_PB13 = AnyAFR<Port::PB, 13, AF::k9>;
using AfTSC_G1_IO3_PB14 = AnyAFR<Port::PB, 14, AF::k9>;
using AfTSC_G1_IO4_PB15 = AnyAFR<Port::PB, 15, AF::k9>;
using AfTSC_G2_IO1_PB4 = AnyAFR<Port::PB, 4, AF::k9>;
using AfTSC_G2_IO2_PB5 = AnyAFR<Port::PB, 5, AF::k9>;
using AfTSC_G2_IO3_PB6 = AnyAFR<Port::PB, 6, AF::k9>;
using AfTSC_G2_IO4_PB7 = AnyAFR<Port::PB, 7, AF::k9>;
using AfTSC_G3_IO1_PA15 = AnyAFR<Port::PA, 15, AF::k9>;
using AfTSC_G3_IO2_PC10 = AnyAFR<Port::PC, 10, AF::k9>;
using AfTSC_G3_IO3_PC11 = AnyAFR<Port::PC, 11, AF::k9>;
using AfTSC_G3_IO4_PC12 = AnyAFR<Port::PC, 12, AF::k9>;
using AfTSC_G4_IO1_PC6 = AnyAFR<Port::PC, 6, AF::k9>;
using AfTSC_G4_IO2_PC7 = AnyAFR<Port::PC, 7, AF::k9>;
using AfTSC_G4_IO3_PC8 = AnyAFR<Port::PC, 8, AF::k9>;
using AfTSC_G4_IO4_PC9 = AnyAFR<Port::PC, 9, AF::k9>;
using AfTSC_SYNC_PB10 = AnyAFR<Port::PB, 10, AF::k9>;
#if defined(GPIOD_BASE)
using AfTSC_G6_IO1_PD10 = AnyAFR<Port::PD, 10, AF::k9>;
using AfTSC_G6_IO2_PD11 = AnyAFR<Port::PD, 11, AF::k9>;
using AfTSC_G6_IO3_PD12 = AnyAFR<Port::PD, 12, AF::k9>;
using AfTSC_G6_IO4_PD13 = AnyAFR<Port::PD, 13, AF::k9>;
using AfTSC_SYNC_PD2 = AnyAFR<Port::PD, 2, AF::k9>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfTSC_G5_IO1_PE10 = AnyAFR<Port::PE, 10, AF::k9>;
using AfTSC_G5_IO2_PE11 = AnyAFR<Port::PE, 11, AF::k9>;
using AfTSC_G5_IO3_PE12 = AnyAFR<Port::PE, 12, AF::k9>;
using AfTSC_G5_IO4_PE13 = AnyAFR<Port::PE, 13, AF::k9>;
using AfTSC_G7_IO1_PE2 = AnyAFR<Port::PE, 2, AF::k9>;
using AfTSC_G7_IO2_PE3 = AnyAFR<Port::PE, 3, AF::k9>;
using AfTSC_G7_IO3_PE4 = AnyAFR<Port::PE, 4, AF::k9>;
using AfTSC_G7_IO4_PE5 = AnyAFR<Port::PE, 5, AF::k9>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfTSC_G8_IO1_PF14 = AnyAFR<Port::PF, 14, AF::k9>;
using AfTSC_G8_IO2_PF15 = AnyAFR<Port::PF, 15, AF::k9>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfTSC_G8_IO3_PG0 = AnyAFR<Port::PG, 0, AF::k9>;
using AfTSC_G8_IO4_PG1 = AnyAFR<Port::PG, 1, AF::k9>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(TSC_BASE)

// USART1
#if defined(USART1_BASE)
using AfUSART1_CK_PA8 = AnyAFR<Port::PA, 8, AF::k7>;
using AfUSART1_CK_PB5 = AnyAFR<Port::PB, 5, AF::k7>;
using AfUSART1_CTS_PA11 = AnyAFR<Port::PA, 11, AF::k7>;
using AfUSART1_CTS_PB4 = AnyAFR<Port::PB, 4, AF::k7>;
using AfUSART1_DE_PA12 = AnyAFR<Port::PA, 12, AF::k7>;
using AfUSART1_DE_PB3 = AnyAFR<Port::PB, 3, AF::k7>;
using AfUSART1_RTS_PA12 = AnyAFR<Port::PA, 12, AF::k7>;
using AfUSART1_RTS_PB3 = AnyAFR<Port::PB, 3, AF::k7>;
using AfUSART1_RX_PA10 = AnyAFR<Port::PA, 10, AF::k7>;
using AfUSART1_RX_PB7 = AnyAFR<Port::PB, 7, AF::k7>;
using AfUSART1_TX_PA9 = AnyAFR<Port::PA, 9, AF::k7>;
using AfUSART1_TX_PB6 = AnyAFR<Port::PB, 6, AF::k7>;
#if defined(GPIOG_BASE)
using AfUSART1_CK_PG13 = AnyAFR<Port::PG, 13, AF::k7>;
using AfUSART1_CTS_PG11 = AnyAFR<Port::PG, 11, AF::k7>;
using AfUSART1_DE_PG12 = AnyAFR<Port::PG, 12, AF::k7>;
using AfUSART1_RTS_PG12 = AnyAFR<Port::PG, 12, AF::k7>;
using AfUSART1_RX_PG10 = AnyAFR<Port::PG, 10, AF::k7>;
using AfUSART1_TX_PG9 = AnyAFR<Port::PG, 9, AF::k7>;
#endif	// defined(GPIOG_BASE)
#endif	// defined(USART1_BASE)

// USART2
#if defined(USART2_BASE)
using AfUSART2_CK_PA4 = AnyAFR<Port::PA, 4, AF::k7>;
using AfUSART2_CTS_PA0 = AnyAFR<Port::PA, 0, AF::k7>;
using AfUSART2_DE_PA1 = AnyAFR<Port::PA, 1, AF::k7>;
using AfUSART2_RTS_PA1 = AnyAFR<Port::PA, 1, AF::k7>;
using AfUSART2_RX_PA3 = AnyAFR<Port::PA, 3, AF::k7>;
using AfUSART2_RX_PA15 = AnyAFR<Port::PA, 15, AF::k3>;
using AfUSART2_TX_PA2 = AnyAFR<Port::PA, 2, AF::k7>;
#if defined(GPIOD_BASE)
using AfUSART2_CK_PD7 = AnyAFR<Port::PD, 7, AF::k7>;
using AfUSART2_CTS_PD3 = AnyAFR<Port::PD, 3, AF::k7>;
using AfUSART2_DE_PD4 = AnyAFR<Port::PD, 4, AF::k7>;
using AfUSART2_RTS_PD4 = AnyAFR<Port::PD, 4, AF::k7>;
using AfUSART2_RX_PD6 = AnyAFR<Port::PD, 6, AF::k7>;
using AfUSART2_TX_PD5 = AnyAFR<Port::PD, 5, AF::k7>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(USART2_BASE)

// USART3
#if defined(USART3_BASE)
using AfUSART3_CK_PB0 = AnyAFR<Port::PB, 0, AF::k7>;
using AfUSART3_CK_PB12 = AnyAFR<Port::PB, 12, AF::k7>;
using AfUSART3_CK_PC12 = AnyAFR<Port::PC, 12, AF::k7>;
using AfUSART3_CTS_PA6 = AnyAFR<Port::PA, 6, AF::k7>;
using AfUSART3_CTS_PB13 = AnyAFR<Port::PB, 13, AF::k7>;
using AfUSART3_DE_PA15 = AnyAFR<Port::PA, 15, AF::k7>;
using AfUSART3_DE_PB1 = AnyAFR<Port::PB, 1, AF::k7>;
using AfUSART3_DE_PB14 = AnyAFR<Port::PB, 14, AF::k7>;
using AfUSART3_RTS_PA15 = AnyAFR<Port::PA, 15, AF::k7>;
using AfUSART3_RTS_PB1 = AnyAFR<Port::PB, 1, AF::k7>;
using AfUSART3_RTS_PB14 = AnyAFR<Port::PB, 14, AF::k7>;
using AfUSART3_RX_PB11 = AnyAFR<Port::PB, 11, AF::k7>;
using AfUSART3_RX_PC5 = AnyAFR<Port::PC, 5, AF::k7>;
using AfUSART3_RX_PC11 = AnyAFR<Port::PC, 11, AF::k7>;
using AfUSART3_TX_PB10 = AnyAFR<Port::PB, 10, AF::k7>;
using AfUSART3_TX_PC4 = AnyAFR<Port::PC, 4, AF::k7>;
using AfUSART3_TX_PC10 = AnyAFR<Port::PC, 10, AF::k7>;
#if defined(GPIOD_BASE)
using AfUSART3_CK_PD10 = AnyAFR<Port::PD, 10, AF::k7>;
using AfUSART3_CTS_PD11 = AnyAFR<Port::PD, 11, AF::k7>;
using AfUSART3_DE_PD2 = AnyAFR<Port::PD, 2, AF::k7>;
using AfUSART3_DE_PD12 = AnyAFR<Port::PD, 12, AF::k7>;
using AfUSART3_RTS_PD2 = AnyAFR<Port::PD, 2, AF::k7>;
using AfUSART3_RTS_PD12 = AnyAFR<Port::PD, 12, AF::k7>;
using AfUSART3_RX_PD9 = AnyAFR<Port::PD, 9, AF::k7>;
using AfUSART3_TX_PD8 = AnyAFR<Port::PD, 8, AF::k7>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(USART3_BASE)

// UART4
#if defined(UART4_BASE)
using AfUART4_CTS_PB7 = AnyAFR<Port::PB, 7, AF::k8>;
using AfUART4_DE_PA15 = AnyAFR<Port::PA, 15, AF::k8>;
using AfUART4_RTS_PA15 = AnyAFR<Port::PA, 15, AF::k8>;
using AfUART4_RX_PA1 = AnyAFR<Port::PA, 1, AF::k8>;
using AfUART4_RX_PC11 = AnyAFR<Port::PC, 11, AF::k8>;
using AfUART4_TX_PA0 = AnyAFR<Port::PA, 0, AF::k8>;
using AfUART4_TX_PC10 = AnyAFR<Port::PC, 10, AF::k8>;
#endif	// defined(UART4_BASE)

// UART5
#if defined(UART5_BASE)
using AfUART5_CTS_PB5 = AnyAFR<Port::PB, 5, AF::k8>;
using AfUART5_DE_PB4 = AnyAFR<Port::PB, 4, AF::k8>;
using AfUART5_RTS_PB4 = AnyAFR<Port::PB, 4, AF::k8>;
using AfUART5_TX_PC12 = AnyAFR<Port::PC, 12, AF::k8>;
#if defined(GPIOD_BASE)
using AfUART5_RX_PD2 = AnyAFR<Port::PD, 2, AF::k8>;
#endif	// defined(GPIOD_BASE)
#endif	// defined(UART5_BASE)

// EVENTOUT
using AfEVENTOUT_PA0 = AnyAFR<Port::PA, 0, AF::k15>;
using AfEVENTOUT_PA1 = AnyAFR<Port::PA, 1, AF::k15>;
using AfEVENTOUT_PA2 = AnyAFR<Port::PA, 2, AF::k15>;
using AfEVENTOUT_PA3 = AnyAFR<Port::PA, 3, AF::k15>;
using AfEVENTOUT_PA4 = AnyAFR<Port::PA, 4, AF::k15>;
using AfEVENTOUT_PA5 = AnyAFR<Port::PA, 5, AF::k15>;
using AfEVENTOUT_PA6 = AnyAFR<Port::PA, 6, AF::k15>;
using AfEVENTOUT_PA7 = AnyAFR<Port::PA, 7, AF::k15>;
using AfEVENTOUT_PA8 = AnyAFR<Port::PA, 8, AF::k15>;
using AfEVENTOUT_PA9 = AnyAFR<Port::PA, 9, AF::k15>;
using AfEVENTOUT_PA10 = AnyAFR<Port::PA, 10, AF::k15>;
using AfEVENTOUT_PA11 = AnyAFR<Port::PA, 11, AF::k15>;
using AfEVENTOUT_PA12 = AnyAFR<Port::PA, 12, AF::k15>;
using AfEVENTOUT_PA13 = AnyAFR<Port::PA, 13, AF::k15>;
using AfEVENTOUT_PA14 = AnyAFR<Port::PA, 14, AF::k15>;
using AfEVENTOUT_PA15 = AnyAFR<Port::PA, 15, AF::k15>;
using AfEVENTOUT_PB0 = AnyAFR<Port::PB, 0, AF::k15>;
using AfEVENTOUT_PB1 = AnyAFR<Port::PB, 1, AF::k15>;
using AfEVENTOUT_PB2 = AnyAFR<Port::PB, 2, AF::k15>;
using AfEVENTOUT_PB3 = AnyAFR<Port::PB, 3, AF::k15>;
using AfEVENTOUT_PB4 = AnyAFR<Port::PB, 4, AF::k15>;
using AfEVENTOUT_PB5 = AnyAFR<Port::PB, 5, AF::k15>;
using AfEVENTOUT_PB6 = AnyAFR<Port::PB, 6, AF::k15>;
using AfEVENTOUT_PB7 = AnyAFR<Port::PB, 7, AF::k15>;
using AfEVENTOUT_PB8 = AnyAFR<Port::PB, 8, AF::k15>;
using AfEVENTOUT_PB9 = AnyAFR<Port::PB, 9, AF::k15>;
using AfEVENTOUT_PB10 = AnyAFR<Port::PB, 10, AF::k15>;
using AfEVENTOUT_PB11 = AnyAFR<Port::PB, 11, AF::k15>;
using AfEVENTOUT_PB12 = AnyAFR<Port::PB, 12, AF::k15>;
using AfEVENTOUT_PB13 = AnyAFR<Port::PB, 13, AF::k15>;
using AfEVENTOUT_PB14 = AnyAFR<Port::PB, 14, AF::k15>;
using AfEVENTOUT_PB15 = AnyAFR<Port::PB, 15, AF::k15>;
using AfEVENTOUT_PC0 = AnyAFR<Port::PC, 0, AF::k15>;
using AfEVENTOUT_PC1 = AnyAFR<Port::PC, 1, AF::k15>;
using AfEVENTOUT_PC2 = AnyAFR<Port::PC, 2, AF::k15>;
using AfEVENTOUT_PC3 = AnyAFR<Port::PC, 3, AF::k15>;
using AfEVENTOUT_PC4 = AnyAFR<Port::PC, 4, AF::k15>;
using AfEVENTOUT_PC5 = AnyAFR<Port::PC, 5, AF::k15>;
using AfEVENTOUT_PC6 = AnyAFR<Port::PC, 6, AF::k15>;
using AfEVENTOUT_PC7 = AnyAFR<Port::PC, 7, AF::k15>;
using AfEVENTOUT_PC8 = AnyAFR<Port::PC, 8, AF::k15>;
using AfEVENTOUT_PC9 = AnyAFR<Port::PC, 9, AF::k15>;
using AfEVENTOUT_PC10 = AnyAFR<Port::PC, 10, AF::k15>;
using AfEVENTOUT_PC11 = AnyAFR<Port::PC, 11, AF::k15>;
using AfEVENTOUT_PC12 = AnyAFR<Port::PC, 12, AF::k15>;
using AfEVENTOUT_PC13 = AnyAFR<Port::PC, 13, AF::k15>;
using AfEVENTOUT_PC14 = AnyAFR<Port::PC, 14, AF::k15>;
using AfEVENTOUT_PC15 = AnyAFR<Port::PC, 15, AF::k15>;
#if defined(GPIOD_BASE)
using AfEVENTOUT_PD0 = AnyAFR<Port::PD, 0, AF::k15>;
using AfEVENTOUT_PD1 = AnyAFR<Port::PD, 1, AF::k15>;
using AfEVENTOUT_PD2 = AnyAFR<Port::PD, 2, AF::k15>;
using AfEVENTOUT_PD3 = AnyAFR<Port::PD, 3, AF::k15>;
using AfEVENTOUT_PD4 = AnyAFR<Port::PD, 4, AF::k15>;
using AfEVENTOUT_PD5 = AnyAFR<Port::PD, 5, AF::k15>;
using AfEVENTOUT_PD6 = AnyAFR<Port::PD, 6, AF::k15>;
using AfEVENTOUT_PD7 = AnyAFR<Port::PD, 7, AF::k15>;
using AfEVENTOUT_PD8 = AnyAFR<Port::PD, 8, AF::k15>;
using AfEVENTOUT_PD9 = AnyAFR<Port::PD, 9, AF::k15>;
using AfEVENTOUT_PD10 = AnyAFR<Port::PD, 10, AF::k15>;
using AfEVENTOUT_PD11 = AnyAFR<Port::PD, 11, AF::k15>;
using AfEVENTOUT_PD12 = AnyAFR<Port::PD, 12, AF::k15>;
using AfEVENTOUT_PD13 = AnyAFR<Port::PD, 13, AF::k15>;
using AfEVENTOUT_PD14 = AnyAFR<Port::PD, 14, AF::k15>;
using AfEVENTOUT_PD15 = AnyAFR<Port::PD, 15, AF::k15>;
#endif	// defined(GPIOD_BASE)
#if defined(GPIOE_BASE)
using AfEVENTOUT_PE0 = AnyAFR<Port::PE, 0, AF::k15>;
using AfEVENTOUT_PE1 = AnyAFR<Port::PE, 1, AF::k15>;
using AfEVENTOUT_PE2 = AnyAFR<Port::PE, 2, AF::k15>;
using AfEVENTOUT_PE3 = AnyAFR<Port::PE, 3, AF::k15>;
using AfEVENTOUT_PE4 = AnyAFR<Port::PE, 4, AF::k15>;
using AfEVENTOUT_PE5 = AnyAFR<Port::PE, 5, AF::k15>;
using AfEVENTOUT_PE6 = AnyAFR<Port::PE, 6, AF::k15>;
using AfEVENTOUT_PE7 = AnyAFR<Port::PE, 7, AF::k15>;
using AfEVENTOUT_PE8 = AnyAFR<Port::PE, 8, AF::k15>;
using AfEVENTOUT_PE9 = AnyAFR<Port::PE, 9, AF::k15>;
using AfEVENTOUT_PE10 = AnyAFR<Port::PE, 10, AF::k15>;
using AfEVENTOUT_PE11 = AnyAFR<Port::PE, 11, AF::k15>;
using AfEVENTOUT_PE12 = AnyAFR<Port::PE, 12, AF::k15>;
using AfEVENTOUT_PE13 = AnyAFR<Port::PE, 13, AF::k15>;
using AfEVENTOUT_PE14 = AnyAFR<Port::PE, 14, AF::k15>;
using AfEVENTOUT_PE15 = AnyAFR<Port::PE, 15, AF::k15>;
#endif	// defined(GPIOE_BASE)
#if defined(GPIOF_BASE)
using AfEVENTOUT_PF0 = AnyAFR<Port::PF, 0, AF::k15>;
using AfEVENTOUT_PF1 = AnyAFR<Port::PF, 1, AF::k15>;
using AfEVENTOUT_PF2 = AnyAFR<Port::PF, 2, AF::k15>;
using AfEVENTOUT_PF3 = AnyAFR<Port::PF, 3, AF::k15>;
using AfEVENTOUT_PF4 = AnyAFR<Port::PF, 4, AF::k15>;
using AfEVENTOUT_PF5 = AnyAFR<Port::PF, 5, AF::k15>;
using AfEVENTOUT_PF6 = AnyAFR<Port::PF, 6, AF::k15>;
using AfEVENTOUT_PF7 = AnyAFR<Port::PF, 7, AF::k15>;
using AfEVENTOUT_PF8 = AnyAFR<Port::PF, 8, AF::k15>;
using AfEVENTOUT_PF9 = AnyAFR<Port::PF, 9, AF::k15>;
using AfEVENTOUT_PF10 = AnyAFR<Port::PF, 10, AF::k15>;
using AfEVENTOUT_PF11 = AnyAFR<Port::PF, 11, AF::k15>;
using AfEVENTOUT_PF12 = AnyAFR<Port::PF, 12, AF::k15>;
using AfEVENTOUT_PF13 = AnyAFR<Port::PF, 13, AF::k15>;
using AfEVENTOUT_PF14 = AnyAFR<Port::PF, 14, AF::k15>;
using AfEVENTOUT_PF15 = AnyAFR<Port::PF, 15, AF::k15>;
#endif	// defined(GPIOF_BASE)
#if defined(GPIOG_BASE)
using AfEVENTOUT_PG0 = AnyAFR<Port::PG, 0, AF::k15>;
using AfEVENTOUT_PG1 = AnyAFR<Port::PG, 1, AF::k15>;
using AfEVENTOUT_PG2 = AnyAFR<Port::PG, 2, AF::k15>;
using AfEVENTOUT_PG3 = AnyAFR<Port::PG, 3, AF::k15>;
using AfEVENTOUT_PG4 = AnyAFR<Port::PG, 4, AF::k15>;
using AfEVENTOUT_PG5 = AnyAFR<Port::PG, 5, AF::k15>;
using AfEVENTOUT_PG6 = AnyAFR<Port::PG, 6, AF::k15>;
using AfEVENTOUT_PG7 = AnyAFR<Port::PG, 7, AF::k15>;
using AfEVENTOUT_PG8 = AnyAFR<Port::PG, 8, AF::k15>;
using AfEVENTOUT_PG9 = AnyAFR<Port::PG, 9, AF::k15>;
using AfEVENTOUT_PG10 = AnyAFR<Port::PG, 10, AF::k15>;
using AfEVENTOUT_PG11 = AnyAFR<Port::PG, 11, AF::k15>;
using AfEVENTOUT_PG12 = AnyAFR<Port::PG, 12, AF::k15>;
using AfEVENTOUT_PG13 = AnyAFR<Port::PG, 13, AF::k15>;
using AfEVENTOUT_PG14 = AnyAFR<Port::PG, 14, AF::k15>;
using AfEVENTOUT_PG15 = AnyAFR<Port::PG, 15, AF::k15>;
#endif	// defined(GPIOG_BASE)
#if defined(GPIOH_BASE)
using AfEVENTOUT_PH0 = AnyAFR<Port::PH, 0, AF::k15>;
using AfEVENTOUT_PH1 = AnyAFR<Port::PH, 1, AF::k15>;
using AfEVENTOUT_PH2 = AnyAFR<Port::PH, 2, AF::k15>;
using AfEVENTOUT_PH3 = AnyAFR<Port::PH, 3, AF::k15>;
using AfEVENTOUT_PH4 = AnyAFR<Port::PH, 4, AF::k15>;
using AfEVENTOUT_PH5 = AnyAFR<Port::PH, 5, AF::k15>;
using AfEVENTOUT_PH6 = AnyAFR<Port::PH, 6, AF::k15>;
using AfEVENTOUT_PH7 = AnyAFR<Port::PH, 7, AF::k15>;
using AfEVENTOUT_PH8 = AnyAFR<Port::PH, 8, AF::k15>;
using AfEVENTOUT_PH9 = AnyAFR<Port::PH, 9, AF::k15>;
using AfEVENTOUT_PH10 = AnyAFR<Port::PH, 10, AF::k15>;
using AfEVENTOUT_PH11 = AnyAFR<Port::PH, 11, AF::k15>;
using AfEVENTOUT_PH12 = AnyAFR<Port::PH, 12, AF::k15>;
using AfEVENTOUT_PH13 = AnyAFR<Port::PH, 13, AF::k15>;
using AfEVENTOUT_PH14 = AnyAFR<Port::PH, 14, AF::k15>;
using AfEVENTOUT_PH15 = AnyAFR<Port::PH, 15, AF::k15>;
#endif	// defined(GPIOH_BASE)
#if defined(GPIOI_BASE)
using AfEVENTOUT_PI0 = AnyAFR<Port::PI, 0, AF::k15>;
using AfEVENTOUT_PI1 = AnyAFR<Port::PI, 1, AF::k15>;
using AfEVENTOUT_PI2 = AnyAFR<Port::PI, 2, AF::k15>;
using AfEVENTOUT_PI3 = AnyAFR<Port::PI, 3, AF::k15>;
using AfEVENTOUT_PI4 = AnyAFR<Port::PI, 4, AF::k15>;
using AfEVENTOUT_PI5 = AnyAFR<Port::PI, 5, AF::k15>;
using AfEVENTOUT_PI6 = AnyAFR<Port::PI, 6, AF::k15>;
using AfEVENTOUT_PI7 = AnyAFR<Port::PI, 7, AF::k15>;
using AfEVENTOUT_PI8 = AnyAFR<Port::PI, 8, AF::k15>;
using AfEVENTOUT_PI9 = AnyAFR<Port::PI, 9, AF::k15>;
using AfEVENTOUT_PI10 = AnyAFR<Port::PI, 10, AF::k15>;
using AfEVENTOUT_PI11 = AnyAFR<Port::PI, 11, AF::k15>;
#endif	// defined(GPIOI_BASE)


}	// namespace Gpio
}	// namespace Bmt

