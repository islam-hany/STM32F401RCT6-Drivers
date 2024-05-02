/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: STK			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


static void (* CallBack_Func) (void) = NULL;
static u8 ISR_State=NOT_ACTIVE;

void MSTK_voidInit(void)
{
	STK->LOAD = 0;
	STK->VAL = 0;
	#if (AHB == MSTK_CLOCK_FREQUENCY)
	SET_BIT(STK->CTRL , 2);
	#elif (AHB_divided_8 == MSTK_CLOCKFREQUENCY)
	CLR_BIT(STK->CTRL , 2);
	#else
		#error ("Enter valid systic clock frequency")
	#endif
	CLR_BIT(STK->CTRL , 1);
	CLR_BIT(STK->CTRL , 0);

}

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	/* Disable STK timer */
	CLR_BIT(STK->CTRL , 0);

	STK->LOAD = Copy_u32Ticks;

	STK->VAL = 0;

	

	/* Enable STK timer */ 
	SET_BIT(STK->CTRL , 0);
	
	/* Busy waiting until underflow flag raised */ 
	while (!GET_BIT(STK->CTRL ,16));

	/* Disable STK timer */
	CLR_BIT(STK->CTRL , 0);


}

void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	if (Copy_ptr != NULL)
	{
		ISR_State = SINGLE;

		/* Disable STK timer */
		CLR_BIT(STK->CTRL , 0);

		STK->LOAD = Copy_u32Ticks;

		STK->VAL = 0;

		CallBack_Func = Copy_ptr;
		/* Enable interrupt of STK timer and enabling the peripheral*/ 
		SET_BIT(STK->CTRL , 1);
		SET_BIT(STK->CTRL , 0);
	}
	else
	{
		/*   DO nothing    */
	}
	
}

void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	if (Copy_ptr != NULL)
	{
		ISR_State = PERIODIC;

		/* Disable STK timer */
		CLR_BIT(STK->CTRL , 0);
		STK->LOAD = Copy_u32Ticks-1;
		STK->VAL = 0;

		CallBack_Func = Copy_ptr;
		/* Enable interrupt of STK timer and enabling the peripheral*/ 
		SET_BIT(STK->CTRL , 1);
		SET_BIT(STK->CTRL , 0);
	}
	else
	{
		/*   DO nothing    */
	}
}
void MSTK_voidStopInterval(void)
{
	ISR_State = NOT_ACTIVE;
	STK->LOAD = 0;
	STK->VAL = 0;
	/* Disable STK timer */ 
	CLR_BIT(STK->CTRL , 1);
	CLR_BIT(STK->CTRL , 0);
}
u32  MSTK_u32GetElapsedTime(void)
{
	return ((STK->LOAD) -  (STK->VAL));
}
u32  MSTK_u32GetRemainingTime(void)
{
	return STK->VAL ; 
}


void SysTick_Handler(void)
{
	u8 Local_u8ClearFlage=0;
	switch(ISR_State)
	{
		case SINGLE:
			ISR_State= NOT_ACTIVE;
			STK->LOAD = 0;
			STK->VAL = 0;
			CLR_BIT(STK->CTRL , 0);
			CallBack_Func(); 
			break;
		case PERIODIC:
			CallBack_Func();
			break;
	}
	Local_u8ClearFlage += GET_BIT(STK -> CTRL , 16);
}
