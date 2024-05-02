/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		SWC: IRremote		****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/

#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

typedef enum Directions {Up=100 , Down , Right , Left , ok,star,hash}	Remote;

void	HIR_voidInit(void);
u8		HIR_u8GetData(void);
Remote 		HIR_u8GetKeyValue(void);

#endif
