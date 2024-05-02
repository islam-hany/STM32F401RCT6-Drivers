/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		SWC: TFT			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_voidTFTInit(void)
{
	/*Reset Pulse*/
	MGPIO_VidSetPinValue(HTFT_RST_PIN, HIGH);
	MSTK_voidSetBusyWait(4000);
	MGPIO_VidSetPinValue(HTFT_RST_PIN, LOW);
	MSTK_voidSetBusyWait(40);
	MGPIO_VidSetPinValue(HTFT_RST_PIN, HIGH);
	MSTK_voidSetBusyWait(4000);
	MGPIO_VidSetPinValue(HTFT_RST_PIN, LOW);
	MSTK_voidSetBusyWait(4000);
	MGPIO_VidSetPinValue(HTFT_RST_PIN, HIGH);
	MSTK_voidSetBusyWait(4800000);

	/*Sleep Out Command*/
	HTFT_voidSendCommand(0x11);

	/*Wait 150ms*/
	MSTK_voidSetBusyWait(6000000);

	/*Choose Color Mode RGB565*/
	HTFT_voidSendCommand(0x3A);
	HTFT_voidSendData(0x05);

	/*Inversion ON*/
	HTFT_voidSendCommand(0x21);

	/*Display On*/
	HTFT_voidSendCommand(0x29);
}

void HTFT_voidBackgroundColour(u16 Copy_u16Colour)
{
	u16 Local_u16Counter;
	HTFT_voidSendCommand(0x2A);
	HTFT_voidSendData(0);
	HTFT_voidSendData(0);
	HTFT_voidSendData(0);
	HTFT_voidSendData(127);
	/*Set Y Address*/
	HTFT_voidSendCommand(0x2B);
	HTFT_voidSendData(0);
	HTFT_voidSendData(0);
	HTFT_voidSendData(0);
	HTFT_voidSendData(159);
	/*RAM write*/
	HTFT_voidSendCommand(0x2C);

	for (Local_u16Counter=0 ; Local_u16Counter < 20480 ; Local_u16Counter++)
	{
		HTFT_voidSendData(Copy_u16Colour>>8);
		HTFT_voidSendData(Copy_u16Colour & 0xff);
	}

}
void HTFT_voidDisplay(const u16* Copy_u16PicArray)
{
	u16 Local_u16Counter;
	/*Set X Address*/
	HTFT_voidSendCommand(0x2A);
	HTFT_voidSendData(0);
	HTFT_voidSendData(0);
	HTFT_voidSendData(0);
	HTFT_voidSendData(127);
	/*Set Y Address*/
	HTFT_voidSendCommand(0x2B);
	HTFT_voidSendData(0);
	HTFT_voidSendData(0);
	HTFT_voidSendData(0);
	HTFT_voidSendData(159);

	/*RAM write*/
	HTFT_voidSendCommand(0x2C);
	
	for(Local_u16Counter =0 ; Local_u16Counter<20480 ; Local_u16Counter++)
	{
		HTFT_voidSendData(Copy_u16PicArray[Local_u16Counter]>>8);
		HTFT_voidSendData(Copy_u16PicArray[Local_u16Counter] & 0xff);
	}
}


void HTFT_voidDisplayRectangle(u16 Copy_u16Colour , u8 x1 ,u8 x2 , u8 y1 , u8 y2)
{
	u16 Local_u16Counter;

	u16 Local_u16NumberPixels=0;
	/*Set X Address*/
	HTFT_voidSendCommand(0x2A);
	HTFT_voidSendData(0);
	HTFT_voidSendData(x1);
	HTFT_voidSendData(0);
	HTFT_voidSendData(x2);
	/*Set Y Address*/
	HTFT_voidSendCommand(0x2B);
	HTFT_voidSendData(0);
	HTFT_voidSendData(y1);
	HTFT_voidSendData(0);
	HTFT_voidSendData(y2);

	/*RAM write*/
	HTFT_voidSendCommand(0x2C);

	Local_u16NumberPixels=(x2 - x1+1)*(y2 - y1+1);

	for(Local_u16Counter =0 ; Local_u16Counter<Local_u16NumberPixels ; Local_u16Counter++)
	{
		HTFT_voidSendData(Copy_u16Colour>>8);
		HTFT_voidSendData(Copy_u16Colour& 0xff);
	}
}



static void HTFT_voidSendCommand(u8 Copy_u8Command)
{
	u8 Local_u8Received;
	MGPIO_VidSetPinValue(HTFT_A0_PIN, LOW);
	MSPI1_voidSendReceiveSynch(Copy_u8Command, &Local_u8Received);
}

static void HTFT_voidSendData(u8 Copy_u8Data)
{
	u8 Local_u8Received;
	MGPIO_VidSetPinValue(HTFT_A0_PIN, HIGH);
	MSPI1_voidSendReceiveSynch(Copy_u8Data, &Local_u8Received);
}
