/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: USART			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct 
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}MUSART_t;

#define USART1	((volatile MUSART_t*) 0x40011000)

#define OVERSAMPLING_16	0
#define OVERSAMPLING_8	1

#define WORDLENGTH_8	0
#define WORDLENGTH_9	1

#define NO_PARITY		0b00	
#define PARITY_EVEN		0b10
#define PARITY_ODD		0b11

#define STOP_1BIT			0
#define STOP_HALFBIT		1
#define STOP_2BITS			2
#define STOP_1AND_HALFBIT	3



static void (*CallBackFunc)(u8)=NULL;

#define USART_FREE	1
#define USART_BUSY	2
static u8 Flage = USART_FREE;

#define USART_NONE		0
#define USART_SINGLE	1
#define USART_STRING	2
static u8 State = USART_NONE;

static char* USART_Array=NULL;
static u32 Counter=0;

#define USART_RXSingle	1
#define USART_RXMULTI		2
static u8 Rx_State=USART_NONE;
#endif
