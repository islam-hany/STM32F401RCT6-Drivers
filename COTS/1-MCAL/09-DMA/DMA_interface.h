/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: DMA			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

typedef enum {DMA_LOW=0 , DMA_MEDIUM , DMA_HIGH , DMA_VERY_HIGH} Priority;

/*CircularMode options*/
#define CIRCULAR_ON		1
#define CIRCULAR_OFF	0


/*TransmitionSize options*/
#define WORD		2
#define HALF_WORD	1
#define BYTE		0


/*MemoryInc options*/
#define MemoryInc_ON		1
#define MemoryInc_OFF	0

/*PeripheralInc options*/
#define PeripheralInc_ON		1
#define PeripheralInc_OFF	0
typedef struct
{
	u8 StreamNumber;
	Priority SelectChannel;
	u8 SetPriority;  /*options: DMA_LOW , DMA_MEDIUM , DMA_HIGH , DMA_VERY_HIGH */
	u8 CircularMode;
	u8 TransmitionSize; /*options: WORD , HALFWORD , BYTE*/
	u8 MemoryInc;
	u8 PeripheralInc;
}MDMA_Config_t;

void MDMA2_voidStreamConfig(MDMA_Config_t * Copy_ptrConfig);


/*Same options as above but memory to memory is invalid*/
void MDMA1_voidStreamConfig(MDMA_Config_t * Copy_ptrConfig);


/*Direction options*/
#define MEM_TO_PER	1
#define PER_TO_MEM	0
#define MEM_TO_MEM	2

void MDMA1_voidStartDMAStreamAsync(u8 Copy_u8StreamNumber , u32 Copy_u32PeripheralAddress,
								u32 Copy_u32MemoryAddress , u16 Copy_u16NumberOfData,
								u8 Direction,void (*Copy_CallBackFunc)(void));

void MDMA2_voidStartDMAStreamAsync(u8 Copy_u8StreamNumber , u32 Copy_u32PeripheralAddress,
								u32 Copy_u32MemoryAddress , u16 Copy_u16NumberOfData,
								u8 Direction, void (*Copy_CallBackFunc)(void));

void MDMA1_voidStartDMAStreamSync(u8 Copy_u8StreamNumber , u32 Copy_u32PeripheralAddress,
								u32 Copy_u32MemoryAddress , u16 Copy_u16NumberOfData,
								u8 Direction );

void MDMA2_voidStartDMAStreamSync(u8 Copy_u8StreamNumber , u32 Copy_u32PeripheralAddress,
								u32 Copy_u32MemoryAddress , u16 Copy_u16NumberOfData,
								u8 Direction );

#endif
