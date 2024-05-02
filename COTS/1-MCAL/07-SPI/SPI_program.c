/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: SPI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void (*CallBack_Func)(u8)=NULL;

void MSPI1_voidInit(void)
{
	MSPI1->CR1 |=(0x03<<8) | (MSPI_CPOL<<1) | (MSPI_CPHA<<0) | (BAUD_RATE<<3) | (FRAME_FORMATE<<7)| (1<<2)| (1<<6);

}

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive)
{

	/* Clear For Slave Select Pin */
	MGPIO_VidSetPinValue(MSPI1_SLAVE_PIN,LOW);

	/* Send Data */
	MSPI1 -> DR = Copy_u8DataToTransmit;
	
	/* Wait RXNE Flag to finish */
	while (!(GET_BIT(MSPI1 -> SR, 0) == 1));
	
	/* Wait Busy Flag to finish */
	while ((GET_BIT(MSPI1 -> SR, 7) == 1));

 	/* Return to the received data */
	*Copy_DataToReceive = MSPI1 -> DR;
	
	/* Set Salve Select Pin */
	MGPIO_VidSetPinValue(MSPI1_SLAVE_PIN,HIGH);
}

void MSPI1_voidSendReceiveSynchArray(u8 *Copy_u8DataToTransmit, u8 *Copy_ReceivingArray, u32 Copy_u8ArraySize)
{
	u8 Local_u8Iterator;
	
	/* Clear For Slave Select Pin */
	MGPIO_VidSetPinValue(MSPI1_SLAVE_PIN,LOW);
	
	/* Send Data */
	MSPI1 -> DR = Copy_u8DataToTransmit[0];
	
	for(Local_u8Iterator = 0; Local_u8Iterator < Copy_u8ArraySize-1;Local_u8Iterator++)
	{
		/* Wait Transmit Flag to finish */
		while (GET_BIT(MSPI1 -> SR, 1) == 0);
		
		MSPI1 -> DR = Copy_u8DataToTransmit[Local_u8Iterator+1];
		
		/* Wait RXNE Flag to finish */
		while (GET_BIT(MSPI1 -> SR, 0) == 0);
		
		Copy_ReceivingArray[Local_u8Iterator] = MSPI1 ->DR;
	}
	
	/* Wait RXNE Flag to finish */
	while (GET_BIT(MSPI1 -> SR, 0) == 0);
	
	Copy_ReceivingArray[Local_u8Iterator] = MSPI1 ->DR;
	
	/* Wait Transmit Flag to finish */
	while (GET_BIT(MSPI1 -> SR, 1) == 0);
	
	/* Wait Busy Flag to finish */
	while (GET_BIT(MSPI1 -> SR, 7) == 1);

	/* Set Salve Select Pin */
	MGPIO_VidSetPinValue(MSPI1_SLAVE_PIN,HIGH);
}


void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*Copy_ptrCallBackFunc)(u8))
{
	/* Send Data */
	MSPI1 -> DR = Copy_u8DataToTransmit;
	
	CallBack_Func=Copy_ptrCallBackFunc;
	
	MSPI1->CR2 |=(1<<6); 
}

void SPI1_IRQHandler()
{
	CallBack_Func(MSPI1-> DR);
}
