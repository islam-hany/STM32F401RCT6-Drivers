/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: SYSCFG			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H


typedef struct{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR[4];
	volatile u32 CMPCR;
	
}SYSCFG_t;


#define SYSCFG ((volatile SYSCFG_t *) 0x40013800 )


#endif
