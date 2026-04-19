#pragma once

namespace Bmt
{
namespace Gpio
{

// SPI1
/// SPI1 alternate configuration 1 using PA4, PA5, PA6 and PA7
using AfSpi1_PA4_5_6_7 = AnyAFR<0x00000000U, ~AFIO_MAPR_SPI1_REMAP_Msk>;/// SPI1 alternate configuration 2 using PA15, PB3, PB4 and PB5
using AfSpi1_PA15_PB3_4_5 = AnyAFR<AFIO_MAPR_SPI1_REMAP, ~AFIO_MAPR_SPI1_REMAP_Msk>;
// I²C1
/// I²C1 alternate configuration 1 using PB6 and PB7
using AfI2C1_PB6_7 = AnyAFR<0x00000000U, ~AFIO_MAPR_I2C1_REMAP_Msk>;/// I²C1 alternate configuration 2 using PB8 and PB9
using AfI2C1_PB8_9 = AnyAFR<AFIO_MAPR_I2C1_REMAP, ~AFIO_MAPR_I2C1_REMAP_Msk>;
// USART1
/// USART1 alternate configuration 1 using PA9 and PA10
using AfUsart1_PA9_10 = AnyAFR<0x00000000U, ~AFIO_MAPR_USART1_REMAP_Msk>;/// USART1 alternate configuration 2 using PB6 and PB7
using AfUsart1_PB6_7 = AnyAFR<AFIO_MAPR_USART1_REMAP, ~AFIO_MAPR_USART1_REMAP_Msk>;
// USART2
/// USART2 alternate configuration 1 using PA0, PA1, PA2, PA3 and PA4
using AfUsart2_PA0_1_2_3_4 = AnyAFR<0x00000000U, ~AFIO_MAPR_USART2_REMAP_Msk>;/// USART2 alternate configuration 2 using PD3, PD4, PD5, PD6 and PD7
using AfUsart2_PD3_4_5_6_7 = AnyAFR<AFIO_MAPR_USART2_REMAP, ~AFIO_MAPR_USART2_REMAP_Msk>;
// USART3
/// USART3 alternate configuration 1 using PB10, PB11, PB12, PB13 and PB14
using AfUsart3_PB10_11_12_13_14 = AnyAFR<AFIO_MAPR_USART3_REMAP_NOREMAP, ~AFIO_MAPR_USART3_REMAP_Msk>;/// USART3 alternate configuration 2 using PC10, PC11, PC12, PC13 and PC14
using AfUsart3_PC10_11_12_PB13_14 = AnyAFR<AFIO_MAPR_USART3_REMAP_PARTIALREMAP, ~AFIO_MAPR_USART3_REMAP_Msk>;/// USART3 alternate configuration 3 using PD8, PD9, PD10, PD11 and PD12
using AfUsart3_PD8_9_10_11_12 = AnyAFR<AFIO_MAPR_USART3_REMAP_FULLREMAP, ~AFIO_MAPR_USART3_REMAP_Msk>;
// TIM1
/// TIM1 alternate configuration 1 using PA12, PA8-11 and PB12-15
using AfTim1_PA12_8_9_10_11_PB12_13_14_15 = AnyAFR<AFIO_MAPR_TIM1_REMAP_NOREMAP, ~AFIO_MAPR_TIM1_REMAP_Msk>;/// TIM1 alternate configuration 2 using PA12, PA8-11, PA6-7 and PB0-1
using AfTim1_PA12_8_9_10_11_6_7_PB0_1 = AnyAFR<AFIO_MAPR_TIM1_REMAP_PARTIALREMAP, ~AFIO_MAPR_TIM1_REMAP_Msk>;/// TIM1 alternate configuration 3 using PE7, PE9, PE11, PE13-15, PE8, PE10 and PE12
using AfTim1_PE7_9_11_13_14_15_8_10_12 = AnyAFR<AFIO_MAPR_TIM1_REMAP_FULLREMAP, ~AFIO_MAPR_TIM1_REMAP_Msk>;
// TIM2
/// TIM2 alternate configuration 1 using PA0-3
using AfTim2_PA0_1_2_3 = AnyAFR<AFIO_MAPR_TIM2_REMAP_NOREMAP, ~AFIO_MAPR_TIM2_REMAP_Msk>;/// TIM2 alternate configuration 2 using PA15, PB3, and PA2-3
using AfTim2_PA15_PB3_PA2_3 = AnyAFR<AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1, ~AFIO_MAPR_TIM2_REMAP_Msk>;/// TIM2 alternate configuration 3 using PA0-1 and PB10-11
using AfTim2_PA0_1_PB10_11 = AnyAFR<AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2, ~AFIO_MAPR_TIM2_REMAP_Msk>;/// TIM2 alternate configuration 4 using PA15, PB3 and PB10-11
using AfTim2_PA15_PB3_10_11 = AnyAFR<AFIO_MAPR_TIM2_REMAP_FULLREMAP, ~AFIO_MAPR_TIM2_REMAP_Msk>;
// TIM3
/// TIM3 alternate configuration 1 using PA6-7 and PB0-1
using AfTim3_PA6_7_PB0_1 = AnyAFR<AFIO_MAPR_TIM3_REMAP_NOREMAP, ~AFIO_MAPR_TIM3_REMAP_Msk>;/// TIM3 alternate configuration 2 using PB4-5 and PB0-1
using AfTim3_PB4_5_0_1 = AnyAFR<AFIO_MAPR_TIM3_REMAP_PARTIALREMAP, ~AFIO_MAPR_TIM3_REMAP_Msk>;/// TIM3 alternate configuration 3 using PC6-9
using AfTim3_PC6_7_8_9 = AnyAFR<AFIO_MAPR_TIM3_REMAP_FULLREMAP, ~AFIO_MAPR_TIM3_REMAP_Msk>;
// TIM4
/// TIM3 alternate configuration 1 using PB6-9
using AfTim4_PB6_7_8_9 = AnyAFR<0x00000000U, ~AFIO_MAPR_TIM4_REMAP_Msk>;/// TIM3 alternate configuration 2 using PD12-15
using AfTim4_PD12_13_14_15 = AnyAFR<AFIO_MAPR_TIM4_REMAP, ~AFIO_MAPR_TIM4_REMAP_Msk>;
// CAN
/// CAN alternate configuration 1 using PA11-12
using AfCan_PA11_12 = AnyAFR<AFIO_MAPR_CAN_REMAP_REMAP1, ~AFIO_MAPR_CAN_REMAP_Msk>;/// CAN alternate configuration 2 using PB8-9
using AfCan_PB8_9 = AnyAFR<AFIO_MAPR_CAN_REMAP_REMAP2, ~AFIO_MAPR_CAN_REMAP_Msk>;/// CAN alternate configuration 3 using PD0-1
using AfCan_PD0_1 = AnyAFR<AFIO_MAPR_CAN_REMAP_REMAP3, ~AFIO_MAPR_CAN_REMAP_Msk>;
// OSC
/// OSC alternate configuration 1 using PD0-1
using Af_PD01_OSC = AnyAFR<0x00000000U, ~AFIO_MAPR_PD01_REMAP_Msk>;/// GPIO configuration for port PD0-1
using Af_PD01_GPIO = AnyAFR<AFIO_MAPR_PD01_REMAP, ~AFIO_MAPR_PD01_REMAP_Msk>;
// JTAG/SWD
/// 5-pin JTAG bus active
using AfJtag5 = AnyAFR<AFIO_MAPR_SWJ_CFG_RESET, ~AFIO_MAPR_SWJ_CFG_Msk>;/// 4-pin JTAG bus active
using AfJtag4 = AnyAFR<AFIO_MAPR_SWJ_CFG_NOJNTRST, ~AFIO_MAPR_SWJ_CFG_Msk>;/// 2-pin JTAG bus active (3-pin with optional SWO)
using AfSwd3 = AnyAFR<AFIO_MAPR_SWJ_CFG_JTAGDISABLE, ~AFIO_MAPR_SWJ_CFG_Msk>;/// No emulation active
using AfSwd2 = AnyAFR<AFIO_MAPR_SWJ_CFG_DISABLE, ~AFIO_MAPR_SWJ_CFG_Msk>;
}	// namespace Gpio
}	// namespace Bmt

