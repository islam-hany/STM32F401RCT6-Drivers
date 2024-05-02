/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: SPI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/*
	IDLE_LOW
	IDLE_HIGH
*/
#define MSPI_CPOL	IDLE_HIGH

/*
	Master Clock Phase:
		SEND_LEADING
		SEND_TRALING
*/
#define MSPI_CPHA	SEND_LEADING

/*
	BAUD_RATE options:
	CLOCK_DIVIDED_2		
	CLOCK_DIVIDED_4
	CLOCK_DIVIDED_8
	CLOCK_DIVIDED_16
	CLOCK_DIVIDED_32
	CLOCK_DIVIDED_64
	CLOCK_DIVIDED_128
	CLOCK_DIVIDED_256
	
*/
#define BAUD_RATE	CLOCK_DIVIDED_4

/*
	FRAME_FORMATE options:
		MSB_FIRST
		LSB_FIRST
*/
#define FRAME_FORMATE	MSB_FIRST
/* Write it in a pair port,pin */
#define MSPI1_SLAVE_PIN   GPIOA,0

#endif
