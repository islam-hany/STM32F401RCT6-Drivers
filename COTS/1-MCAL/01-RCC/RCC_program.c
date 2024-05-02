/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: RCC			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSystemClock()
{

	#if (RCC_HSE_CRYSTAL == RCC_CLOCK_TYPE)
		RCC->RCC_CR &= ~((1<<0) | (1<<24) | (1<<26) | (1<<18));
		RCC->RCC_CR |= (1<<16) | (1<<19);
		while (!GET_BIT(RCC->RCC_CR ,17));
		RCC->RCC_CFGR &=0xfffffff0;
		RCC->RCC_CFGR |=0b01;

	#elif (RCC_HSE_RC == RCC_CLOCK_TYPE)
		RCC->RCC_CR &= ~((1<<0) | (1<<24) | (1<<26) | (1<<16));
		RCC->RCC_CR |= (1<<16) | (1<<19) | (1<<18);
		while (!GET_BIT(RCC->RCC_CR ,17));
		RCC->RCC_CFGR &=0xfffffff0;
		RCC->RCC_CFGR |=0b01;
		
	#elif (RCC_HSI == RCC_CLOCK_TYPE)
		RCC->RCC_CR &= ~((1<<16) | (1<<24) | (1<<26));
		RCC->RCC_CR |= (1<<0);
		while (!GET_BIT(RCC->RCC_CR ,1));
		for(u8 i=0 ; i<2 ; i++);
		RCC->RCC_CFGR |=(0b00) | (1<<12) | (AHB_PRESCALER<<4);
		
	#elif (RCC_PLL_HSE == RCC_CLOCK_TYPE)
//		RCC -> RCC_CFGR &=~(0b111<<24 | 0b11<<21);
//		RCC -> RCC_CFGR |= ((0b110<<24) | (0b11<<21));

		RCC->RCC_CR &= ~((1<<26) | (1<<18));
		RCC->RCC_CR |= (1<<16) | (1<<19);
		while (!GET_BIT(RCC->RCC_CR ,17));
		
		SET_BIT(RCC->RCC_PLLCFGR,22);
		
		RCC->RCC_PLLCFGR &=~(0b111111);
		RCC->RCC_PLLCFGR |=15;
		
		RCC->RCC_PLLCFGR &=~(0x3FE0);
		RCC->RCC_PLLCFGR |=192<<6;
		

		RCC->RCC_PLLCFGR &= ~(0b11<<16);
		RCC->RCC_PLLCFGR |=PLLP_DIVISION_FACTOR<<16;

		SET_BIT(RCC->RCC_CR ,24);
		while (!GET_BIT(RCC->RCC_CR ,25));
		for(u8 i=0 ; i<2 ; i++);
		RCC->RCC_CFGR |=(0b10) | (1<<12) | (AHB_PRESCALER<<4);
		CLR_BIT(RCC->RCC_CR,0);

	#elif (RCC_CLOCK_TYPE == RCC_PLL_HSI)
		//		RCC -> RCC_CFGR &=~(0b111<<24 | 0b11<<21);
		//		RCC -> RCC_CFGR |= ((0b110<<24) | (0b11<<21));
				RCC->RCC_CR &= ~((1<<16) | (1<<24) | (1<<26));
				RCC->RCC_CR |= (1<<0);
				while (!GET_BIT(RCC->RCC_CR ,1));

				CLR_BIT(RCC->RCC_PLLCFGR,22);

				RCC->RCC_PLLCFGR &=~(0b111111);
				RCC->RCC_PLLCFGR |=25;

				RCC->RCC_PLLCFGR &=~(0x3FE0);
				RCC->RCC_PLLCFGR |=192<<6;


				RCC->RCC_PLLCFGR &= ~(0b11<<16);
				RCC->RCC_PLLCFGR |=PLLP_DIVISION_FACTOR<<16;

				SET_BIT(RCC->RCC_CR ,24);
				while (!GET_BIT(RCC->RCC_CR ,25));
				for(u8 i=0 ; i<2 ; i++);
				RCC->RCC_CFGR |=(0b10) | (1<<12) | (AHB_PRESCALER<<4);
	#else
		#error ("The clock type is not valid")
	#endif
}


void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{

	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB1 : SET_BIT(RCC->RCC_AHB1ENR ,Copy_u8PerId);   break;
			case RCC_AHB2 : SET_BIT(RCC->RCC_AHB2ENR ,Copy_u8PerId);   break;
			case RCC_APB1 : SET_BIT(RCC->RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : SET_BIT(RCC->RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	
	else
	{
		/* Return Error */
	}

}


void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{

	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB1 : CLR_BIT(RCC->RCC_AHB1ENR  ,Copy_u8PerId);   break;
			case RCC_AHB2 : CLR_BIT(RCC->RCC_AHB2ENR   ,Copy_u8PerId);   break;
			case RCC_APB1 : CLR_BIT(RCC->RCC_APB1ENR ,Copy_u8PerId);   break;
			case RCC_APB2 : CLR_BIT(RCC->RCC_APB2ENR ,Copy_u8PerId);   break;
		}
	}
	else
	{
		/* Return Error */
	}

}
