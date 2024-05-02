/*
 * DAC.c
 *
/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: HAL			****************/
/*****************		SWC: DAC_Audio		****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

static volatile u32 Counter=0;
static u8* AudioData=NULL;
static u32 AudioLength=0;

static void DAC_voidTimer();
void DAC_voidStartAudio(u32 Copy_u32Size, u8* Copy_u8ptrData)
{
	AudioData= Copy_u8ptrData;
	AudioLength= Copy_u32Size;
	MSTK_voidSetIntervalPeriodic(5000, DAC_voidTimer);
}

static void DAC_voidTimer()
{
	MGPIO_VidSetPORTValue(GPIOA, AudioData[Counter]);
	Counter++;
	if (Counter== AudioLength-1)	Counter=0;
}

void DAC_voidStop()
{
	MSTK_voidStopInterval();
}
