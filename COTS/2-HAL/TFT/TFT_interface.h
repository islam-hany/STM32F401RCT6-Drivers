/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		SWC: TFT			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void HTFT_voidTFTInit(void);

void HTFT_voidDisplay(const u16* Copy_u16PicArray);

void HTFT_voidBackgroundColour(u16 Copy_u16Colour);

void HTFT_voidDisplayRectangle(u16 Copy_u16Colour , u8 x1 ,u8 x2 , u8 y1 , u8 y2);




#endif
