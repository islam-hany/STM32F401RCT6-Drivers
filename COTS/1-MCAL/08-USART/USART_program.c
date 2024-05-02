/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: USART			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "DMA_interface.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

static void USART_SendDMA();
static void USART_ReceiveDMA();
void MUSART_voidInit(void)
{
	/*Enable USART*/
	SET_BIT(USART1 ->CR1 ,13);

	/*Set USART Configurations*/
	USART1 ->CR1 |= (PARITY<<9) | (WORDLENGTH<<12) | (OVERSAMPLING <<15);

	/*Configuring the number of stop bits*/
	USART1 -> CR2 |= (STOP_BITS <<12);

	/*Configuring the baud rate*/
#if OVERSAMPLING_16 == OVERSAMPLING
	f32	USARTDIV = (40000000UL)/ (16.0 * BAUD_RATE);
	f32 Fraction =USARTDIV- (u16)USARTDIV;

	f32 intermediate =Fraction *16;
	Fraction =intermediate- (u8)intermediate;
	if (Fraction>=0.5)
		intermediate++;
	if ((u8)intermediate == 16)
		{
			intermediate=0;
			USARTDIV++;
		}
	USART1->BRR |= ((u16)USARTDIV << 4) | ((u8)intermediate);

#elif OVERSAMPLING_8 == OVERSAMPLING
	f32	USARTDIV = (40000000UL)/ (8.0 * BAUD_RATE);
		f32 Fraction =USARTDIV- (u16)USARTDIV;

		f32 intermediate =Fraction *16;
		Fraction =intermediate- (u8)intermediate;
		if (Fraction>=0.5)
			intermediate++;
		if ((u8)intermediate == 16)
			{
				intermediate=0;
				USARTDIV++;
			}
		USART1->BRR |= ((u16)USARTDIV << 4) | ((u8)intermediate);
#else
	#error ("Wrong OVERSAMLING choice")
#endif

		/* Enable Transmission*/
		SET_BIT(USART1->CR1 , 3);
		/* Enable Reception*/
		SET_BIT(USART1->CR1 , 2);
}

u8 MUSART_voidSingleReceiveSynch(u8* Copy_u8ReceivedData)
{
	u8 Local_u8Result = 1;

		if ( (GET_BIT((USART1 -> SR), 5)) == 1 )
		{
			*Copy_u8ReceivedData = USART1 -> DR;
		}
		else
		{
			Local_u8Result = 0;
		}

		return (Local_u8Result);
}

void MUSART_voidSendSingleDataSynch(u8 Copy_u8DataToTransmit)
{
	/*Write the data to be transmitted*/
	USART1->DR = Copy_u8DataToTransmit;
	
	while(!GET_BIT(USART1 -> SR , 6));
	CLR_BIT(USART1 -> SR , 6);
}

void MUSART_voidSendSingleDataASynch(u8 Copy_u8DataToTransmit)
{
	if (Flage ==USART_FREE)
		{
			Flage=USART_BUSY;
			State=USART_SINGLE;
			/*Write the data to be transmitted*/
			USART1->DR = Copy_u8DataToTransmit;

			/*Enable TCIE interrupt*/
			SET_BIT(USART1->CR1 , 6);
		}
}

void MUSART_voidSendStringSynch(char *Copy_u8DataToTransmit)
{
	u32 Local_u32Iterator=0;
	while(Copy_u8DataToTransmit[Local_u32Iterator] != '\0')
	{
		/*Write the data to be transmitted*/

		USART1->DR = Copy_u8DataToTransmit[Local_u32Iterator];
		while(!GET_BIT(USART1 -> SR , 6));
		Local_u32Iterator++;
	}
	CLR_BIT(USART1->SR , 6);
}

void MUSART_voidSendStringASynch(char *Copy_u8DataToTransmit)
{
	if (Flage ==USART_FREE)
	{
		Flage=USART_BUSY;
		State=USART_STRING;
		Counter=0;

		USART_Array=Copy_u8DataToTransmit;

		/*Write the data to be transmitted*/
		USART1->DR = Copy_u8DataToTransmit[0];

		/*Enable TCIE interrupt*/
		SET_BIT(USART1->CR1 , 6);
	}

}


void MUSART_voidSingleReceiveASynch(void (*Copy_ptrCallBackFunc)(u8))
{
	Rx_State=USART_RXSingle;
	CallBackFunc=Copy_ptrCallBackFunc;
	/*Enable RXNE interrupt*/
	SET_BIT(USART1->CR1 , 5);
}

void MUSART_voidMULTIReceiveASynch(void (*Copy_ptrCallBackFunc)(u8))
{
	Rx_State=USART_RXMULTI;
	CallBackFunc=Copy_ptrCallBackFunc;
	/*Enable RXNE interrupt*/
	SET_BIT(USART1->CR1 , 5);
}


void MUSART_voidSendDMA(char *Copy_u8DataToTransmit , u16 Copy_u16NumberOfData)
{
	/*Enable DMAT*/
	SET_BIT(USART1->CR3 ,7 );

	MDMA2_voidStartDMAStreamAsync(7,(u32)&(USART1->DR), (u32)Copy_u8DataToTransmit,
							Copy_u16NumberOfData, MEM_TO_PER,USART_SendDMA);
}

void MUSART_voidReceiveDMA(u8 *Copy_u8DataToTransmit , u16 Copy_u16NumberOfData)
{
	/*Enable DMAR*/
	SET_BIT(USART1->CR3 ,6 );

	MDMA2_voidStartDMAStreamAsync(5,(u32)&(USART1->DR), (u32)Copy_u8DataToTransmit,
							Copy_u16NumberOfData, PER_TO_MEM , USART_ReceiveDMA);
}

void USART1_IRQHandler()
{
	if (GET_BIT(USART1 -> SR , 7) == 1)
	{
		switch(State)
		{
			case USART_SINGLE:
				Flage=USART_FREE;
				State=USART_NONE;
				CLR_BIT(USART1->SR , 6);
				/*Disable TCIE interrupt*/
				CLR_BIT(USART1->CR1 , 6);
				break;
			case USART_STRING:
				Counter++;
				if (USART_Array[Counter] != '\0')
				{
					/*Write the data to be transmitted*/
					USART1->DR = USART_Array[Counter];
					CLR_BIT(USART1->SR , 6);
				}
				else
				{
					Flage=USART_FREE;
					State=USART_NONE;
					CLR_BIT(USART1->SR , 6);
					/*Disable TCIE interrupt*/
					CLR_BIT(USART1->CR1 , 6);
				}

				break;
			case USART_NONE:
				if(USART_RXSingle==Rx_State)
				{
					CallBackFunc(USART1->DR);
					Rx_State=USART_NONE;
					/*Disable RXNE interrupt*/
					CLR_BIT(USART1->CR1 , 5);
				}
				else if (USART_RXMULTI==Rx_State)
				{
					CallBackFunc(USART1->DR);
				}
				break;
		}
	}

}

static void USART_ReceiveDMA()
{
	/*Disable DMAR*/
	CLR_BIT(USART1->CR3 ,6 );
}

static void USART_SendDMA()
{
	/*Disable DMAT*/
	CLR_BIT(USART1->CR3 ,7 );
}
