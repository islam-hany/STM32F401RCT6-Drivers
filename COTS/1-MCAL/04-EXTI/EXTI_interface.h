/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: EXTI			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


void MEXTI_voidTriggerMode(u8 Copy_u8Line , u8 Copy_u8Mode);
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
u8	 MEXTI_u8GetPendingFlag(u8 Copy_u8Line);
void MEXTI_u8ClearPendingFlag(u8 Copy_u8Line);
void MEXTI_voidSetCallBack(u8 Copy_u8Line ,void (*Copy_ptrFunc)(void));


enum EXTI_LineNumber {Line0=1,Line1,Line2,Line3,Line4,Line5,Line6,Line7,
					Line8,Line9,Line10,Line11,Line12,Line13,Line14,Line15};


#define	RISING_EDGE			1
#define	FALLING_EDGE		2
#define	ON_CHANGE			3



#endif
