/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: EXTI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (* CallBack_Func[7]) (void)= {NULL};

void MEXTI_voidTriggerMode(u8 Copy_u8Line , u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case RISING_EDGE 	:	SET_BIT(EXTI -> RTSR , Copy_u8Line); 	break;
		case FALLING_EDGE	:	SET_BIT(EXTI -> FTSR , Copy_u8Line); 	break;
		case ON_CHANGE 	:	SET_BIT(EXTI -> RTSR , Copy_u8Line); 
							SET_BIT(EXTI -> FTSR , Copy_u8Line); 	break;
		default: break;
	}
	CLR_BIT(EXTI->IMR , Copy_u8Line);
}

void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR , Copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR , Copy_u8Line);
}
void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	CLR_BIT(EXTI -> PR , Copy_u8Line);
	SET_BIT(EXTI -> SWIER , Copy_u8Line);
}

u8	 MEXTI_u8GetPendingFlag(u8 Copy_u8Line)
{
	return GET_BIT(EXTI->PR , Copy_u8Line);
}

void MEXTI_u8ClearPendingFlag(u8 Copy_u8Line)
{
	SET_BIT(EXTI->PR , Copy_u8Line);
}


void MEXTI_voidSetCallBack(u8 Copy_u8Line ,void (*Copy_ptrFunc)(void))
{
	if (Copy_u8Line <= 4)
		CallBack_Func[Copy_u8Line] = Copy_ptrFunc;
	else if (Copy_u8Line > 4 && Copy_u8Line < 10)
		CallBack_Func[5] = Copy_ptrFunc;
	else if (Copy_u8Line >= 10 && Copy_u8Line < 16)
		CallBack_Func[6] = Copy_ptrFunc;

}

void EXTI0_IRQHandler(void)
{
	CallBack_Func[0]();
	MEXTI_u8ClearPendingFlag(0);
}

void EXTI1_IRQHandler(void)
{
	CallBack_Func[1]();
	MEXTI_u8ClearPendingFlag(1);
}

void EXTI2_IRQHandler(void)
{

	CallBack_Func[2]();
	MEXTI_u8ClearPendingFlag(2);
}

void EXTI3_IRQHandler(void)
{

	CallBack_Func[3]();
	MEXTI_u8ClearPendingFlag(3);
}

void EXTI4_IRQHandler(void)
{

	CallBack_Func[4]();
	MEXTI_u8ClearPendingFlag(4);
}

void EXTI9_5_IRQHandler(void)
{

	CallBack_Func[5]();
	for (u8 i=5 ; i<9 ; i++)
		{
			MEXTI_u8ClearPendingFlag(i);
		}
}

void EXTI15_10_IRQHandler(void)
{

	CallBack_Func[6]();
	for (u8 i=10 ; i<16 ; i++)
		{
			MEXTI_u8ClearPendingFlag(i);
		}
}
