/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: SYSCFG			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSCFG_interface.h"
#include "SYSCFG_config.h"
#include "SYSCFG_private.h"



void	MSYSCFG_voidSetEXTIConfiguration(u8 Copy_u8Line ,u8 Copy_u8PortMap)
{
	u8 Local_u8RegIndex = Copy_u8Line/4;		
	/* Assign to EXTICRX register */
	
	
	SYSCFG->EXTICR[Local_u8RegIndex] &= ~((0b1111) << ((Copy_u8Line%4) * 4));
	SYSCFG->EXTICR[Local_u8RegIndex]  |= ((Copy_u8PortMap) << ((Copy_u8Line%4) * 4));	
}
