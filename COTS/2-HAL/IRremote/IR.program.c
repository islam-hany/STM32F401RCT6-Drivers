/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		SWC: IRremote		****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "STK_interface.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "SYSCFG_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

static volatile u8 StartCounter =0;
static volatile u16 FrameData[40]={0};
static volatile u8 Counter=0;
static volatile u8 Data=0;
static	u8 Flag=0;

static void EXTI_ISR();
static void Timer_ISR();
void	HIR_voidInit(void)
{	
	/*Initiate System Tiemr*/
	MSTK_voidInit();
	
	/*Enable EXTI form NVIC*/
	#if PIN == 0
		MNVIC_voidEnableInterrupt  (LINE0);
	#elif PIN == 1
		MNVIC_voidEnableInterrupt  (LINE1);
	#elif PIN == 2
		MNVIC_voidEnableInterrupt  (LINE2);
	#elif PIN == 3
		MNVIC_voidEnableInterrupt  (LINE3);
	#elif PIN == 4
		MNVIC_voidEnableInterrupt  (LINE4);
	#elif (PIN >=5) && (PIN<=9)
		MNVIC_voidEnableInterrupt  (LINE5_9);
	#elif (PIN >=10) && (PIN<=15)
		MNVIC_voidEnableInterrupt  (LINE10_15);
	#else
		#error("Invalid Pin value in IR config file")
	#endif
	
	/*Initiate GPIO PIN*/
	MGPIO_PinType GPIO_Init = {.MODE = INPUT , .InputPullType=FLOUTING , .OutputSpeed =NONE ,
				.OutputType = NONE};
	MGPIO_VidSetPinDirection(PORT, PIN, &GPIO_Init);
	
	/*Initiate External Interrupt*/
	MEXTI_voidTriggerMode(PIN , FALLING_EDGE);
	MEXTI_voidSetCallBack(PIN , EXTI_ISR);
	#if PORT == IR_PORTA
		MSYSCFG_voidSetEXTIConfiguration(PIN,SYSCFG_PORTA);
	#elif PORT == IR_PORTB
		MSYSCFG_voidSetEXTIConfiguration(PIN,SYSCFG_PORTB);
	#elif PORT == IR_PORTC
		MSYSCFG_voidSetEXTIConfiguration(PIN,SYSCFG_PORTC);
	#endif
}


u8	HIR_u8GetData(void)
{
	/*Enable EXTI*/
	MEXTI_voidEnableEXTI(PIN);
	while (Flag==0);
	Flag=0;
	return Data;
}


static void EXTI_ISR()
{
	if (StartCounter == 0)
	{
		MSTK_voidSetIntervalSingle  (150000, Timer_ISR);
		StartCounter++;
	}
	else
	{
		FrameData[Counter]= (u16)MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle  (150000, Timer_ISR);
		Counter++;
	}
}

static void Timer_ISR()
{
	StartCounter=0;
	Counter=0;
	if (FrameData[0] < 14000  && FrameData[0] > 10000 )
	{
		for (u8 Iterator=0 ; Iterator < 8 ; Iterator++)
		{
			if((FrameData[17+Iterator] >2000) && (FrameData[17+Iterator] <2400))
			{
				SET_BIT(Data,Iterator);
			}
			else
			{
				CLR_BIT(Data,Iterator);
			}
		}
	}
	Flag=1;
}

Remote HIR_u8GetKeyValue()
{
	/*Enable EXTI*/
		MEXTI_voidEnableEXTI(PIN);
		while (Flag==0);
		Flag=0;
		switch (Data)
		{
			case 69:	Data=1; break;
			case 70:	Data=2; break;
			case 71:	Data=3; break;
			case 68:	Data=4; break;
			case 64:	Data=5; break;
			case 67:	Data=6; break;
			case 7:		Data=7; break;
			case 21:	Data=8; break;
			case 9:		Data=9; break;
			case 22:	Data=star; break;
			case 25:	Data=0; break;
			case 13:	Data=hash; break;
			case 24:	Data=Up; break;
			case 82:	Data=Down; break;
			case 90:	Data=Right; break;
			case 8:		Data=Left; break;
			case 28:	Data=ok;  break;
		}
		return Data;
}
