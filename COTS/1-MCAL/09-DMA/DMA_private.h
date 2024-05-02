/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: DMA			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct
{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;	
	volatile u32 S0CR  ;
	volatile u32 S0NDTR;
	volatile u32 S0PAR ;
	volatile u32 S0M0AR;
	volatile u32 S0M1AR;
	volatile u32 S0FCR ;

	volatile u32 S1CR  ;
	volatile u32 S1NDTR;
	volatile u32 S1PAR ;
	volatile u32 S1M0AR;
	volatile u32 S1M1AR;
	volatile u32 S1FCR ;

	volatile u32 S2CR  ;
	volatile u32 S2NDTR;
	volatile u32 S2PAR ;
	volatile u32 S2M0AR;
	volatile u32 S2M1AR;
	volatile u32 S2FCR ;

	volatile u32 S3CR  ;
	volatile u32 S3NDTR;
	volatile u32 S3PAR ;
	volatile u32 S3M0AR;
	volatile u32 S3M1AR;
	volatile u32 S3FCR ;

	volatile u32 S4CR  ;
	volatile u32 S4NDTR;
	volatile u32 S4PAR ;
	volatile u32 S4M0AR;
	volatile u32 S4M1AR;
	volatile u32 S4FCR ;

	volatile u32 S5CR  ;
	volatile u32 S5NDTR;
	volatile u32 S5PAR ;
	volatile u32 S5M0AR;
	volatile u32 S5M1AR;
	volatile u32 S5FCR ;

	volatile u32 S6CR  ;
	volatile u32 S6NDTR;
	volatile u32 S6PAR ;
	volatile u32 S6M0AR;
	volatile u32 S6M1AR;
	volatile u32 S6FCR ;

	volatile u32 S7CR  ;
	volatile u32 S7NDTR;
	volatile u32 S7PAR ;
	volatile u32 S7M0AR;
    volatile u32 S7M1AR;
	volatile u32 S7FCR ;
	
}DMA_t;


#define MDMA1	((volatile DMA_t*) 0x40026000)
#define MDMA2	((volatile DMA_t*) 0x40026400)

static void (*CallBackFunc1[8])(void)={NULL};
static void (*CallBackFunc2[8])(void)={NULL};

#define DMA_Free 1
#define DMA_Busy 2
static u8 Flag=DMA_Free;
#endif

