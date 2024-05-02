/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: SPI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_voidInit(void); /* Home Work */

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive);

void MSPI1_voidSendReceiveSynchArray(u8 *Copy_u8DataToTransmit, u8 *Copy_ReceivingArray, u32 Copy_u8ArraySize);

void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*Copy_ptrCallBackFunc)(u8));

#endif
