/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: RCC			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

enum ClockControl {RCC_AHB1=1 ,RCC_AHB2 , RCC_APB1 , RCC_APB2};

void RCC_voidInitSystemClock();

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

#endif
