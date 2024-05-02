/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: STK			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef	MSTK_PRIVATE_H_
#define	MSTK_PRIVATE_H_

#define AHB				1
#define AHB_divided_8	0


typedef	struct 
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}MSTK_t;

#define STK		((volatile MSTK_t*) 0xE000E010)

#define SINGLE		1
#define PERIODIC	2
#define NOT_ACTIVE	3

#endif