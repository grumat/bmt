#pragma once

class System
{
public:
	/*
	This should be added to the SystemInit() C function.
	(a STM32 firmware startup requirement)
	*/
	static void Init()
	{
		/*
		Turns all clocks off and switch to HSI
		*/
		// Set HSION bit
		RCC->CR |= RCC_CR_HSION;

		// Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits
		RCC->CFGR &=
			~(
				RCC_CFGR_SW_Msk
				| RCC_CFGR_HPRE_Msk
				| RCC_CFGR_PPRE1_Msk
				| RCC_CFGR_PPRE2_Msk
				| RCC_CFGR_ADCPRE_Msk
				| RCC_CFGR_MCO_Msk
			);
		// Reset HSEON, CSSON and PLLON bits
		RCC->CR &= 
			~(
				RCC_CR_HSEON_Msk
				| RCC_CR_CSSON_Msk
				| RCC_CR_PLLON_Msk
#ifdef RCC_CR_PLL2ON_Msk
				| RCC_CR_PLL2ON_Msk
				| RCC_CR_PLL3ON_Msk
#endif
			);
		// Reset HSEBYP bit (The HSEBYP bit can be written only if the HSE oscillator is disabled)
		RCC->CR &= ~RCC_CR_HSEBYP_Msk;
		// Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits (these can be modified only with PLL disabled)
		RCC->CFGR &= 
			~(
				RCC_CFGR_PLLSRC_Msk
				| RCC_CFGR_PLLXTPRE_Msk
				| RCC_CFGR_PLLMULL_Msk
				| RCC_CFGR_USBPRE_Msk
#ifdef RCC_CFGR_OTGFSPRE_Msk
				| RCC_CFGR_OTGFSPRE_Msk
#endif
			);
#ifdef RCC_CFGR2_PREDIV1_Pos
		RCC->CFGR2 = 0;
#endif
		RCC->CIR &=
			~(
				RCC_CIR_LSIRDYF_Msk
				| RCC_CIR_LSERDYF_Msk
				| RCC_CIR_HSIRDYF_Msk
				| RCC_CIR_HSERDYF_Msk
				| RCC_CIR_PLLRDYF_Msk
				| RCC_CIR_CSSF_Msk
				| RCC_CIR_LSIRDYIE_Msk
				| RCC_CIR_LSERDYIE_Msk
				| RCC_CIR_HSIRDYIE_Msk
				| RCC_CIR_HSERDYIE_Msk
				| RCC_CIR_PLLRDYIE_Msk
				| RCC_CIR_LSIRDYC_Msk
				| RCC_CIR_LSERDYC_Msk
				| RCC_CIR_HSIRDYC_Msk
				| RCC_CIR_HSERDYC_Msk
				| RCC_CIR_PLLRDYC_Msk
				| RCC_CIR_CSSC_Msk
#ifdef RCC_CIR_PLL2RDYF_Msk
				| RCC_CIR_PLL2RDYF_Msk
				| RCC_CIR_PLL3RDYF_Msk
				| RCC_CIR_PLL2RDYIE_Msk
				| RCC_CIR_PLL3RDYIE_Msk
				| RCC_CIR_PLL2RDYC_Msk
				| RCC_CIR_PLL3RDYC_Msk
#endif
			);
		// Now proceed to custom clock setup...
	}
};

