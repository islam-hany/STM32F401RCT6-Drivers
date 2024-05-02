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

#include "STK_interface.h"
#include "DIO_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "HLEDMAT_config.h"

static void HLEDMAT_voidInitialValues();
static void HLEDMAT_voidSetRowsValue(u8 Copy_u8Value);
static void ActivateColumn(u8 Copy_u8Col);
static void DisplayNextColumn(void);

u8* HLEDMAT_u8Frame=NULL;
u8 HLEDMAT_u8CurrentIdx=0;

void HLEDMAT_voidInit()
{
	/*SET pins direction*/
	MGPIO_PinType GPIO_Init	= {.MODE = GENERAL_OUTPUT , .InputPullType=NONE , .OutputSpeed =LOW_SPEED ,
								.OutputType = PUSH_PULL};
	MGPIO_VidSetPinDirection  ( LEDMAT_ROW0 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_ROW1 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_ROW2 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_ROW3 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_ROW4 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_ROW5 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_ROW6 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_ROW7 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_COL0 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_COL1 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_COL2 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_COL3 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_COL4 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_COL5 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_COL6 , &GPIO_Init);
	MGPIO_VidSetPinDirection  ( LEDMAT_COL7 , &GPIO_Init);
	HLEDMAT_voidInitialValues();
	
	/*initalize System Timer*/
	MSTK_voidInit();
}

void HLEDMAT_voidDisplayFrame(u8 *Copy_u8Frame)
{
	HLEDMAT_voidInitialValues();
	
	/* Save the desired Frame */
	HLEDMAT_u8Frame = Copy_u8Frame;
	
	/* Reset the frame Start */
	HLEDMAT_u8CurrentIdx = 0;
	
	/* Dislay The first Column */
	ActivateColumn(HLEDMAT_u8CurrentIdx);
	HLEDMAT_voidSetRowsValue  (HLEDMAT_u8Frame[HLEDMAT_u8CurrentIdx]);
	
	/* Start timer */
	MSTK_voidSetIntervalPeriodic(80000,DisplayNextColumn);
}


static void DisplayNextColumn(void)
{
	HLEDMAT_u8CurrentIdx++;
	if (HLEDMAT_u8CurrentIdx == 8)
	{
		HLEDMAT_u8CurrentIdx = 0;
	}
	
	/* Dislay The first Column */
	ActivateColumn(HLEDMAT_u8CurrentIdx);
	HLEDMAT_voidSetRowsValue  (HLEDMAT_u8Frame[HLEDMAT_u8CurrentIdx]);
}



static void ActivateColumn(u8 Copy_u8Col)
{
	/* Disable All */
	MGPIO_VidSetPinValue(LEDMAT_COL0,HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL1,HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL2,HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL3,HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL4,HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL5,HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL6,HIGH);
	MGPIO_VidSetPinValue(LEDMAT_COL7,HIGH);
	
	/* Enable the desired pin only */
	switch (Copy_u8Col)
	{
		case 0: MGPIO_VidSetPinValue(LEDMAT_COL0,LOW); break;
		case 1: MGPIO_VidSetPinValue(LEDMAT_COL1,LOW); break;
		case 2: MGPIO_VidSetPinValue(LEDMAT_COL2,LOW); break;
		case 3: MGPIO_VidSetPinValue(LEDMAT_COL3,LOW); break;
		case 4: MGPIO_VidSetPinValue(LEDMAT_COL4,LOW); break;
		case 5: MGPIO_VidSetPinValue(LEDMAT_COL5,LOW); break;
		case 6: MGPIO_VidSetPinValue(LEDMAT_COL6,LOW); break;
		case 7: MGPIO_VidSetPinValue(LEDMAT_COL7,LOW); break;
	}
}
static void HLEDMAT_voidInitialValues()
{
	MGPIO_VidSetPinValue  ( LEDMAT_COL0 , HIGH);
	MGPIO_VidSetPinValue  ( LEDMAT_COL1 , HIGH);
	MGPIO_VidSetPinValue  ( LEDMAT_COL2 , HIGH);
	MGPIO_VidSetPinValue  ( LEDMAT_COL3 , HIGH);
	MGPIO_VidSetPinValue  ( LEDMAT_COL4 , HIGH);
	MGPIO_VidSetPinValue  ( LEDMAT_COL5 , HIGH);
	MGPIO_VidSetPinValue  ( LEDMAT_COL6 , HIGH);
	MGPIO_VidSetPinValue  ( LEDMAT_COL7 , HIGH);
	
	MGPIO_VidSetPinValue  ( LEDMAT_ROW0 , LOW);
	MGPIO_VidSetPinValue  ( LEDMAT_ROW1 , LOW);
	MGPIO_VidSetPinValue  ( LEDMAT_ROW2 , LOW);
	MGPIO_VidSetPinValue  ( LEDMAT_ROW3 , LOW);
	MGPIO_VidSetPinValue  ( LEDMAT_ROW4 , LOW);
	MGPIO_VidSetPinValue  ( LEDMAT_ROW5 , LOW);
	MGPIO_VidSetPinValue  ( LEDMAT_ROW6 , LOW);
	MGPIO_VidSetPinValue  ( LEDMAT_ROW7 , LOW);
}




static void HLEDMAT_voidSetRowsValue(u8 Copy_u8Value)
{
	MGPIO_VidSetPinValue  ( LEDMAT_ROW0 , GET_BIT(Copy_u8Value,0));
	MGPIO_VidSetPinValue  ( LEDMAT_ROW1 , GET_BIT(Copy_u8Value,1));
	MGPIO_VidSetPinValue  ( LEDMAT_ROW2 , GET_BIT(Copy_u8Value,2));
	MGPIO_VidSetPinValue  ( LEDMAT_ROW3 , GET_BIT(Copy_u8Value,3));
	MGPIO_VidSetPinValue  ( LEDMAT_ROW4 , GET_BIT(Copy_u8Value,4));
	MGPIO_VidSetPinValue  ( LEDMAT_ROW5 , GET_BIT(Copy_u8Value,5));
	MGPIO_VidSetPinValue  ( LEDMAT_ROW6 , GET_BIT(Copy_u8Value,6));
	MGPIO_VidSetPinValue  ( LEDMAT_ROW7 , GET_BIT(Copy_u8Value,7));
}

void HLEDMAT_voidStopLEDMatrix()
{
	MSTK_voidStopInterval();
}
