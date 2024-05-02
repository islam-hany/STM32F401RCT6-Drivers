/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: SPI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct
{
	volatile u32 CR1    ;
	volatile u32 CR2    ;
	volatile u32 SR     ;
	volatile u32 DR     ;
	volatile u32 CRCPR  ;
	volatile u32 RXCRCR ;
	volatile u32 TXCRCR ;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR  ; 
	
}SPI_Register;


#define MSPI1   ((SPI_Register*)0x40013000)

#define IDLE_LOW	0
#define IDLE_HIGH	1

#define SEND_LEADING	1
#define SEND_TRALING	0

#define CLOCK_DIVIDED_2		0
#define CLOCK_DIVIDED_4		1
#define CLOCK_DIVIDED_8		2
#define CLOCK_DIVIDED_16	3
#define CLOCK_DIVIDED_32	4
#define CLOCK_DIVIDED_64	5
#define CLOCK_DIVIDED_128	6
#define CLOCK_DIVIDED_256	7

#define MSB_FIRST	0
#define LSB_FIRST	1

#endif