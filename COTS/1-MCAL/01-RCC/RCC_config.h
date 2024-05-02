/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: RCC			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/*
 RCC_HSE_CRYSTAL
 RCC_HSE_RC
 RCC_HSI
 RCC_PLL_HSE
 RCC_PLL_HSI
 */
#define RCC_CLOCK_TYPE	RCC_PLL_HSE


/*AHB_prescaler options:
	AHB_DIVIDE_1
	AHB_DIVIDE_2
	AHB_DIVIDE_4
	AHB_DIVIDE_8
	AHB_DIVIDE_16
	AHB_DIVIDE_64
	AHB_DIVIDE_128
	AHB_DIVIDE_256
	AHB_DIVIDE_512
*/
#define	AHB_PRESCALER	AHB_DIVIDE_2

/* PLLP DIVISION FACTOR options:
	PLLP_DIVISION_FACTOR_2
	PLLP_DIVISION_FACTOR_4
	PLLP_DIVISION_FACTOR_6
	PLLP_DIVISION_FACTOR_8
*/

#define PLLP_DIVISION_FACTOR	PLLP_DIVISION_FACTOR_4



#endif
