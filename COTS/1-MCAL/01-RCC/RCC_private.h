/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: RCC			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/* Register Definition */


typedef struct RCC
{
	volatile u32  RCC_CR;
	volatile u32  RCC_PLLCFGR;
	volatile u32  RCC_CFGR;
	volatile u32  RCC_CIR;
	volatile u32  RCC_AHB1RSTR;
	volatile u32  RCC_AHB2RSTR;
	volatile u32	 Reserved1;
	volatile u32	 Reserved2;
	volatile u32  RCC_APB1RSTR;
	volatile u32  RCC_APB2RSTR;
	volatile u32	 Reserved3;
	volatile u32	 Reserved4;
	volatile u32  RCC_AHB1ENR;
	volatile u32  RCC_AHB2ENR;
	volatile u32	 Reserved5;
	volatile u32	 Reserved6;
	volatile u32  RCC_APB1ENR;
	volatile u32  RCC_APB2ENR;
	volatile u32	 Reserved7;
	volatile u32	 Reserved8;
	volatile u32  RCC_AHB1LPENR;
	volatile u32  RCC_AHB2LPENR;
	volatile u32	 Reserved9;
	volatile u32	 Reserved10;
	volatile u32  RCC_APB1LPENR;
	volatile u32  RCC_APB2LPENR;
	volatile u32	 Reserved11;
	volatile u32	 Reserved12;
	volatile u32  RCC_BDCR;
	volatile u32  RCC_CSR;
	volatile u32	 Reserved13;
	volatile u32	 Reserved14;
	volatile u32  RCC_SSCGR;
	volatile u32  RCC_PLLI2SCFGR;
	volatile u32	 Reserved15;
	volatile u32  RCC_DCKCFGR;
}RCC_Registers_t;


#define RCC		((volatile RCC_Registers_t*)0x40023800)


#define RCC_HSE	1
#define	RCC_HSI	2
#define RCC_PLL_HSE	3
#define RCC_PLL_HSI	4


#define AHB_DIVIDE_1      0b0111
#define AHB_DIVIDE_2      0b1000
#define AHB_DIVIDE_4      0b1001
#define AHB_DIVIDE_8      0b1010
#define AHB_DIVIDE_16     0b1011
#define AHB_DIVIDE_64     0b1100
#define AHB_DIVIDE_128    0b1101
#define AHB_DIVIDE_256    0b1110
#define AHB_DIVIDE_512    0b1111


#define PLLP_DIVISION_FACTOR_2       0b00
#define PLLP_DIVISION_FACTOR_4       0b01
#define PLLP_DIVISION_FACTOR_6       0b10
#define PLLP_DIVISION_FACTOR_8       0b11

#endif
