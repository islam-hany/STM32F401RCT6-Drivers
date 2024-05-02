/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: USART			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void MUSART_voidInit(void);

u8 MUSART_voidSingleReceiveSynch(u8* Copy_u8ReceivedData);

void MUSART_voidSendSingleDataSynch(u8 Copy_u8DataToTransmit);

void MUSART_voidSendStringSynch(char *Copy_u8DataToTransmit);

void MUSART_voidSendDMA(char *Copy_u8DataToTransmit , u16 Copy_u16NumberOfData);

void MUSART_voidReceiveDMA(u8 *Copy_u8DataToTransmit , u16 Copy_u16NumberOfData);

void MUSART_voidSendSingleDataASynch(u8 Copy_u8DataToTransmit);

void MUSART_voidSendStringASynch(char *Copy_u8DataToTransmit);

void MUSART_voidSingleReceiveASynch(void (*Copy_ptrCallBackFunc)(u8));

void MUSART_voidMULTIReceiveASynch(void (*Copy_ptrCallBackFunc)(u8));

#endif
