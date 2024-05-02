/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: USART			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/*
	OVERSAMPLING options:
		OVERSAMPLING_16
	    OVERSAMPLING_8	
*/
#define OVERSAMPLING	OVERSAMPLING_16

/*
	WORDLENGTH options:
		WORDLENGTH_8
		WORDLENGTH_9
*/
#define WORDLENGTH	WORDLENGTH_8

/*
	PARITY options:
		NO_PARITY	
		PARITY_EVEN	
		PARITY_ODD	
*/
#define	PARITY	NO_PARITY

/*
	STOP_BITS options:
		STOP_1BIT		
	    STOP_HALFBIT	
	    STOP_2BITS		
	    STOP_1AND_HALFBIT
*/
#define STOP_BITS	STOP_1BIT

#define BAUD_RATE	921600UL


#endif
