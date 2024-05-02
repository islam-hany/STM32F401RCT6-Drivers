/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: DMA			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


void MDMA2_voidStreamConfig(MDMA_Config_t * Copy_ptrConfig)
{
	switch (Copy_ptrConfig ->StreamNumber)
	{
		case 0:
			/*Disable Stream before config*/
			CLR_BIT(MDMA2->S0CR , 0);
			while(GET_BIT(MDMA2->S0CR , 0));

			MDMA2->LIFCR |=0x3f;

			MDMA2->S0CR =0;
			MDMA2->S0CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
							  | Copy_ptrConfig->CircularMode<<8
							| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
							| Copy_ptrConfig->MemoryInc<<10;

			break;
		case 1:
			/*Disable Stream before config*/
			CLR_BIT(MDMA2->S1CR , 0);
			while(GET_BIT(MDMA2->S1CR , 0));

			MDMA2->LIFCR |=0x3f<<6;

			MDMA2->S1CR = 0;
			MDMA2->S1CR |=Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
					  | Copy_ptrConfig->CircularMode<<8
					| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
					| Copy_ptrConfig->MemoryInc<<10;

			break;
		case 2:
			/*Disable Stream before config*/
			CLR_BIT(MDMA2->S2CR , 0);
			while(GET_BIT(MDMA2->S2CR , 0));

			MDMA2->LIFCR |=0x3f<<16;

			MDMA2->S2CR = 0;
			MDMA2->S2CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
					  | Copy_ptrConfig->CircularMode<<8
					| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
					| Copy_ptrConfig->MemoryInc<<10;

			break;
		case 3:
			/*Disable Stream before config*/
			CLR_BIT(MDMA2->S3CR , 0);
			while(GET_BIT(MDMA2->S3CR , 0));

			MDMA2->LIFCR |=0x3f<<22;

			MDMA2->S3CR = 0;
			MDMA2->S3CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
					  | Copy_ptrConfig->CircularMode<<8
					| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
					| Copy_ptrConfig->MemoryInc<<10;

			break;
		case 4:
			/*Disable Stream before config*/
			CLR_BIT(MDMA2->S4CR , 0);
			while(GET_BIT(MDMA2->S4CR , 0));

			MDMA2->HIFCR |=0x3f;

			MDMA2->S4CR = 0;
			MDMA2->S4CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
					  | Copy_ptrConfig->CircularMode<<8
					| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
					| Copy_ptrConfig->MemoryInc<<10;

			break;
		case 5:
			/*Disable Stream before config*/
			CLR_BIT(MDMA2->S5CR , 0);
			while(GET_BIT(MDMA2->S5CR , 0));

			MDMA2->HIFCR |=0x3f<<6;

			MDMA2->S5CR =0;
			MDMA2->S5CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
					  | Copy_ptrConfig->CircularMode<<8
					| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
					| Copy_ptrConfig->MemoryInc<<10;

			break;
		case 6:
			/*Disable Stream before config*/
			CLR_BIT(MDMA2->S6CR , 0);
			while(GET_BIT(MDMA2->S6CR , 0));

			MDMA2->HIFCR |=0x3f<<16;

			MDMA2->S6CR = 0;
			MDMA2->S6CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
					  | Copy_ptrConfig->CircularMode<<8
					| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
					| Copy_ptrConfig->MemoryInc<<10;

			break;
		case 7:
			/*Disable Stream before config*/
			CLR_BIT(MDMA2->S7CR , 0);
			while(GET_BIT(MDMA2->S7CR , 0));

			MDMA2->HIFCR |=0x3f<<22;

			MDMA2->S7CR = 0;
			MDMA2->S7CR |=Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
					  | Copy_ptrConfig->CircularMode<<8
					| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
					| Copy_ptrConfig->MemoryInc<<10;

			break;
	}

}



void MDMA1_voidStreamConfig(MDMA_Config_t * Copy_ptrConfig)
{
		switch (Copy_ptrConfig ->StreamNumber)
			{
				case 0:
					/*Disable Stream before config*/
					CLR_BIT(MDMA1->S0CR , 0);
					while(GET_BIT(MDMA1->S0CR , 0));

					MDMA1->LIFCR |=0x3f;

					MDMA1->S0CR =0;
					MDMA1->S0CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
							  | Copy_ptrConfig->CircularMode<<8
							| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
							| Copy_ptrConfig->MemoryInc<<10;

					break;
				case 1:
					/*Disable Stream before config*/
					CLR_BIT(MDMA1->S1CR , 0);
					while(GET_BIT(MDMA1->S1CR , 0));

					MDMA1->LIFCR |=0x3f<<6;

					MDMA1->S1CR =0;
					MDMA1->S1CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
							  | Copy_ptrConfig->CircularMode<<8
							| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
							| Copy_ptrConfig->MemoryInc<<10;

					break;
				case 2:
					/*Disable Stream before config*/
					CLR_BIT(MDMA1->S2CR , 0);
					while(GET_BIT(MDMA1->S2CR , 0));

					MDMA1->LIFCR |=0x3f<<16;

					MDMA1->S2CR =0;
					MDMA1->S2CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
							  | Copy_ptrConfig->CircularMode<<8
							| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
							| Copy_ptrConfig->MemoryInc<<10;

					break;
				case 3:
					/*Disable Stream before config*/
					CLR_BIT(MDMA1->S3CR , 0);
					while(GET_BIT(MDMA1->S3CR , 0));

					MDMA1->LIFCR |=0x3f<<22;

					MDMA1->S3CR =0;
					MDMA1->S3CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
							  | Copy_ptrConfig->CircularMode<<8
							| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
							| Copy_ptrConfig->MemoryInc<<10;

					break;
				case 4:
					/*Disable Stream before config*/
					CLR_BIT(MDMA1->S4CR , 0);
					while(GET_BIT(MDMA1->S4CR , 0));

					MDMA1->HIFCR |=0x3f;

					MDMA1->S4CR =0;
					MDMA1->S4CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
							  | Copy_ptrConfig->CircularMode<<8
							| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
							| Copy_ptrConfig->MemoryInc<<10;

					break;
				case 5:
					/*Disable Stream before config*/
					CLR_BIT(MDMA1->S5CR , 0);
					while(GET_BIT(MDMA1->S5CR , 0));

					MDMA2->HIFCR |=0x3f<<6;

					MDMA1->S5CR =0;
					MDMA1->S5CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
							  | Copy_ptrConfig->CircularMode<<8
							| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
							| Copy_ptrConfig->MemoryInc<<10;

					break;
				case 6:
					/*Disable Stream before config*/
					CLR_BIT(MDMA1->S6CR , 0);
					while(GET_BIT(MDMA1->S6CR , 0));

					MDMA2->HIFCR |=0x3f<<16;

					MDMA1->S6CR =0;
					MDMA1->S6CR |= Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
							  | Copy_ptrConfig->CircularMode<<8
							| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
							| Copy_ptrConfig->MemoryInc<<10;

					break;
				case 7:
					/*Disable Stream before config*/
					CLR_BIT(MDMA1->S7CR , 0);
					while(GET_BIT(MDMA1->S7CR , 0));

					MDMA2->HIFCR |=0x3f<<22;

					MDMA1->S7CR =0;
					MDMA1->S7CR |=Copy_ptrConfig->SelectChannel << 25  | (u8)Copy_ptrConfig -> SetPriority<<16
							  | Copy_ptrConfig->CircularMode<<8
							| Copy_ptrConfig->TransmitionSize << 11 | Copy_ptrConfig->PeripheralInc <<9
							| Copy_ptrConfig->MemoryInc<<10;

					break;
			}

}

void MDMA1_voidStartDMAStreamSync(u8 Copy_u8StreamNumber , u32 Copy_u32PeripheralAddress,
								u32 Copy_u32MemoryAddress , u16 Copy_u16NumberOfData,
								u8 Direction)
{
	if(Flag == DMA_Free)
	{
		Flag=DMA_Busy;
		switch (Copy_u8StreamNumber)
		{
			case 0:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S0CR , 0);
				while(GET_BIT(MDMA1->S0CR , 0));

				MDMA2->S0CR &= ~(0b11) <<6;
				MDMA2->S0CR |= Direction<<6;

				MDMA1->S0NDTR = Copy_u16NumberOfData;
				MDMA1->S0PAR =Copy_u32PeripheralAddress;
				MDMA1->S0M0AR = Copy_u32MemoryAddress;

				MDMA1->LIFCR |=0x3f;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S0CR, 0);
				break;
			case 1:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S1CR , 0);
				while(GET_BIT(MDMA1->S1CR , 0));

				MDMA2->S1CR &= ~(0b11) <<6;
				MDMA2->S1CR |= Direction<<6;

				MDMA1->S1NDTR = Copy_u16NumberOfData;
				MDMA1->S1PAR =Copy_u32PeripheralAddress;
				MDMA1->S1M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA1-> S1CR, 4);

				MDMA1->LIFCR |=0x3f<<6;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S1CR, 0);
				break;
			case 2:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S2CR , 0);
				while(GET_BIT(MDMA1->S2CR , 0));

				MDMA2->S2CR &= ~(0b11) <<6;
				MDMA2->S2CR |= Direction<<6;

				MDMA1->S2NDTR = Copy_u16NumberOfData;
				MDMA1->S2PAR =Copy_u32PeripheralAddress;
				MDMA1->S2M0AR = Copy_u32MemoryAddress;


				MDMA1->LIFCR |=0x3f<<16;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S2CR, 0);
				break;
			case 3:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S3CR , 0);
				while(GET_BIT(MDMA1->S3CR , 0));

				MDMA2->S3CR &= ~(0b11) <<6;
				MDMA2->S3CR |= Direction<<6;

				MDMA1->S3NDTR = Copy_u16NumberOfData;
				MDMA1->S3PAR =Copy_u32PeripheralAddress;
				MDMA1->S3M0AR = Copy_u32MemoryAddress;


				MDMA1->LIFCR |=0x3f<<22;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S3CR, 0);
				break;
			case 4:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S4CR , 0);
				while(GET_BIT(MDMA1->S4CR , 0));

				MDMA2->S4CR &= ~(0b11) <<6;
				MDMA2->S4CR |= Direction<<6;

				MDMA1->S4NDTR = Copy_u16NumberOfData;
				MDMA1->S4PAR =Copy_u32PeripheralAddress;
				MDMA1->S4M0AR = Copy_u32MemoryAddress;



				MDMA1->HIFCR |=0x3f;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S4CR, 0);
				break;
			case 5:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S5CR , 0);
				while(GET_BIT(MDMA1->S5CR , 0));

				MDMA2->S5CR &= ~(0b11) <<6;
				MDMA2->S5CR |= Direction<<6;

				MDMA1->S5NDTR = Copy_u16NumberOfData;
				MDMA1->S5PAR =Copy_u32PeripheralAddress;
				MDMA1->S5M0AR = Copy_u32MemoryAddress;


				MDMA2->HIFCR |=0x3f<<6;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S5CR, 0);
				break;
			case 6:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S6CR , 0);
				while(GET_BIT(MDMA1->S6CR , 0));

				MDMA2->S6CR &= ~(0b11) <<6;
				MDMA2->S6CR |= Direction<<6;

				MDMA1->S6NDTR = Copy_u16NumberOfData;
				MDMA1->S6PAR =Copy_u32PeripheralAddress;
				MDMA1->S6M0AR = Copy_u32MemoryAddress;



				MDMA2->HIFCR |=0x3f<<16;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S6CR, 0);
				break;
			case 7:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S7CR , 0);
				while(GET_BIT(MDMA1->S7CR , 0));

				MDMA2->S7CR &= ~(0b11) <<6;
				MDMA2->S7CR |= Direction<<6;

				MDMA1->S7NDTR = Copy_u16NumberOfData;
				MDMA1->S7PAR =Copy_u32PeripheralAddress;
				MDMA1->S7M0AR = Copy_u32MemoryAddress;


				MDMA2->HIFCR |=0x3f<<22;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S7CR, 0);
				break;
		}
	}
}

void MDMA1_voidStartDMAStreamAsync(u8 Copy_u8StreamNumber , u32 Copy_u32PeripheralAddress,
								u32 Copy_u32MemoryAddress , u16 Copy_u16NumberOfData,
								u8 Direction ,void (*Copy_CallBackFunc)(void))
{
	if(Flag == DMA_Free)
	{
		Flag=DMA_Busy;
		CallBackFunc1[Copy_u8StreamNumber] = Copy_CallBackFunc;
		switch (Copy_u8StreamNumber)
		{
			case 0:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S0CR , 0);
				while(GET_BIT(MDMA1->S0CR , 0));

				MDMA2->S0CR &= ~(0b11) <<6;
				MDMA2->S0CR |= Direction<<6;

				MDMA1->S0NDTR = Copy_u16NumberOfData;
				MDMA1->S0PAR =Copy_u32PeripheralAddress;
				MDMA1->S0M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA1-> S0CR, 4);

				MDMA1->LIFCR |=0x3f;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S0CR, 0);
				break;
			case 1:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S1CR , 0);
				while(GET_BIT(MDMA1->S1CR , 0));

				MDMA2->S1CR &= ~(0b11) <<6;
				MDMA2->S1CR |= Direction<<6;

				MDMA1->S1NDTR = Copy_u16NumberOfData;
				MDMA1->S1PAR =Copy_u32PeripheralAddress;
				MDMA1->S1M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA1-> S1CR, 4);

				MDMA1->LIFCR |=0x3f<<6;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S1CR, 0);
				break;
			case 2:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S2CR , 0);
				while(GET_BIT(MDMA1->S2CR , 0));

				MDMA2->S2CR &= ~(0b11) <<6;
				MDMA2->S2CR |= Direction<<6;

				MDMA1->S2NDTR = Copy_u16NumberOfData;
				MDMA1->S2PAR =Copy_u32PeripheralAddress;
				MDMA1->S2M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA1-> S2CR, 4);

				MDMA1->LIFCR |=0x3f<<16;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S2CR, 0);
				break;
			case 3:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S3CR , 0);
				while(GET_BIT(MDMA1->S3CR , 0));

				MDMA2->S3CR &= ~(0b11) <<6;
				MDMA2->S3CR |= Direction<<6;

				MDMA1->S3NDTR = Copy_u16NumberOfData;
				MDMA1->S3PAR =Copy_u32PeripheralAddress;
				MDMA1->S3M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA1-> S3CR, 4);

				MDMA1->LIFCR |=0x3f<<22;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S3CR, 0);
				break;
			case 4:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S4CR , 0);
				while(GET_BIT(MDMA1->S4CR , 0));

				MDMA2->S4CR &= ~(0b11) <<6;
				MDMA2->S4CR |= Direction<<6;

				MDMA1->S4NDTR = Copy_u16NumberOfData;
				MDMA1->S4PAR =Copy_u32PeripheralAddress;
				MDMA1->S4M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA1-> S4CR, 4);

				MDMA1->HIFCR |=0x3f;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S4CR, 0);
				break;
			case 5:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S5CR , 0);
				while(GET_BIT(MDMA1->S5CR , 0));

				MDMA2->S5CR &= ~(0b11) <<6;
				MDMA2->S5CR |= Direction<<6;

				MDMA1->S5NDTR = Copy_u16NumberOfData;
				MDMA1->S5PAR =Copy_u32PeripheralAddress;
				MDMA1->S5M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA1-> S5CR, 4);

				MDMA2->HIFCR |=0x3f<<6;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S5CR, 0);
				break;
			case 6:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S6CR , 0);
				while(GET_BIT(MDMA1->S6CR , 0));

				MDMA2->S6CR &= ~(0b11) <<6;
				MDMA2->S6CR |= Direction<<6;

				MDMA1->S6NDTR = Copy_u16NumberOfData;
				MDMA1->S6PAR =Copy_u32PeripheralAddress;
				MDMA1->S6M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA1-> S6CR, 4);

				MDMA2->HIFCR |=0x3f<<16;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S6CR, 0);
				break;
			case 7:
				/*Disable Stream before config*/
				CLR_BIT(MDMA1->S7CR , 0);
				while(GET_BIT(MDMA1->S7CR , 0));

				MDMA2->S7CR &= ~(0b11) <<6;
				MDMA2->S7CR |= Direction<<6;

				MDMA1->S7NDTR = Copy_u16NumberOfData;
				MDMA1->S7PAR =Copy_u32PeripheralAddress;
				MDMA1->S7M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA1-> S7CR, 4);

				MDMA2->HIFCR |=0x3f<<22;

				/*Enable Stream*/
				SET_BIT(MDMA1-> S7CR, 0);
				break;
		}

	}
}

void MDMA2_voidStartDMAStreamSync(u8 Copy_u8StreamNumber , u32 Copy_u32PeripheralAddress,
								u32 Copy_u32MemoryAddress , u16 Copy_u16NumberOfData,
								u8 Direction )
{
	if(Flag == DMA_Free)
	{
		Flag=DMA_Busy;
		switch (Copy_u8StreamNumber)
		{
			case 0:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S0CR , 0);
				while(GET_BIT(MDMA2->S0CR , 0));

				MDMA2->S0CR &= ~(0b11) <<6;
				MDMA2->S0CR |= Direction<<6;

				MDMA2->S0NDTR = Copy_u16NumberOfData;
				MDMA2->S0PAR =Copy_u32PeripheralAddress;
				MDMA2->S0M0AR = Copy_u32MemoryAddress;
				MDMA2->LIFCR |=0x3f;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S0CR, 0);
				while(!GET_BIT(MDMA2->LISR,5));
				break;
			case 1:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S1CR , 0);
				while(GET_BIT(MDMA2->S1CR , 0));

				MDMA2->S1CR &= ~(0b11) <<6;
				MDMA2->S1CR |= Direction<<6;

				MDMA2->S1NDTR = Copy_u16NumberOfData;
				MDMA2->S1PAR =Copy_u32PeripheralAddress;
				MDMA2->S1M0AR = Copy_u32MemoryAddress;


				MDMA2->LIFCR |=0x3f<<6;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S1CR, 0);
				while(!GET_BIT(MDMA2->LISR,11));
				break;
			case 2:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S2CR , 0);
				while(GET_BIT(MDMA2->S2CR , 0));

				MDMA2->S2CR &= ~(0b11) <<6;
			    MDMA2->S2CR |= Direction<<6;

				MDMA2->S2NDTR = Copy_u16NumberOfData;
				MDMA2->S2PAR =Copy_u32PeripheralAddress;
				MDMA2->S2M0AR = Copy_u32MemoryAddress;

				MDMA2->LIFCR |=0x3f<<16;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S2CR, 0);
				while(!GET_BIT(MDMA2->LISR,21));
				break;
			case 3:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S3CR , 0);
				while(GET_BIT(MDMA2->S3CR , 0));

				MDMA2->S3CR &= ~(0b11) <<6;
				MDMA2->S3CR |= Direction<<6;

				MDMA2->S3NDTR = Copy_u16NumberOfData;
				MDMA2->S3PAR =Copy_u32PeripheralAddress;
				MDMA2->S3M0AR = Copy_u32MemoryAddress;


				MDMA2->LIFCR |=0x3f<<22;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S3CR, 0);
				while(!GET_BIT(MDMA2->LISR,27));
				break;
			case 4:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S4CR , 0);
				while(GET_BIT(MDMA2->S4CR , 0));

				MDMA2->S4CR &= ~(0b11) <<6;
				MDMA2->S4CR |= Direction<<6;

				MDMA2->S4NDTR = Copy_u16NumberOfData;
				MDMA2->S4PAR =Copy_u32PeripheralAddress;
				MDMA2->S4M0AR = Copy_u32MemoryAddress;


				MDMA2->HIFCR |=0x3f;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S4CR, 0);
				while(!GET_BIT(MDMA2->HISR,5));
				break;
			case 5:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S5CR , 0);
				while(GET_BIT(MDMA2->S5CR , 0));

				MDMA2->S5CR &= ~(0b11) <<6;
				MDMA2->S5CR |= Direction<<6;

				MDMA2->S5NDTR = Copy_u16NumberOfData;
				MDMA2->S5PAR =Copy_u32PeripheralAddress;
				MDMA2->S5M0AR = Copy_u32MemoryAddress;



				MDMA2->HIFCR |=0x3f<<6;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S5CR, 0);
				while(!GET_BIT(MDMA2->HISR,11));
				break;
			case 6:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S6CR , 0);
				while(GET_BIT(MDMA2->S6CR , 0));

				MDMA2->S6CR &= ~(0b11) <<6;
				MDMA2->S6CR |= Direction<<6;

				MDMA2->S6NDTR = Copy_u16NumberOfData;
				MDMA2->S6PAR =Copy_u32PeripheralAddress;
				MDMA2->S6M0AR = Copy_u32MemoryAddress;



				MDMA2->HIFCR |=0x3f<<16;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S6CR, 0);
				while(!GET_BIT(MDMA2->HISR,21));
				break;
			case 7:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S7CR , 0);
				while(GET_BIT(MDMA2->S7CR , 0));

				MDMA2->S7CR &= ~(0b11) <<6;
				MDMA2->S7CR |= Direction<<6;

				MDMA2->S7NDTR = Copy_u16NumberOfData;
				MDMA2->S7PAR =Copy_u32PeripheralAddress;
				MDMA2->S7M0AR = Copy_u32MemoryAddress;



				MDMA2->HIFCR |=0x3f<<22;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S7CR, 0);
				while(!GET_BIT(MDMA2->HISR,27));
				break;
		}
	}
}
void MDMA2_voidStartDMAStreamAsync(u8 Copy_u8StreamNumber , u32 Copy_u32PeripheralAddress,
								u32 Copy_u32MemoryAddress , u16 Copy_u16NumberOfData,
								u8 Direction , void (*Copy_CallBackFunc)(void))
{
	if(Flag == DMA_Free)
	{
		Flag=DMA_Busy;
		CallBackFunc2[Copy_u8StreamNumber] = Copy_CallBackFunc;
		switch (Copy_u8StreamNumber)
		{
			case 0:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S0CR , 0);
				while(GET_BIT(MDMA2->S0CR , 0));

				MDMA2->S0CR &= ~(0b11) <<6;
				MDMA2->S0CR |= Direction<<6;

				MDMA2->S0NDTR = Copy_u16NumberOfData;
				MDMA2->S0PAR =Copy_u32PeripheralAddress;
				MDMA2->S0M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA2-> S0CR, 4);

				MDMA2->LIFCR |=0x3f;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S0CR, 0);
				break;
			case 1:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S1CR , 0);
				while(GET_BIT(MDMA2->S1CR , 0));

				MDMA2->S1CR &= ~(0b11) <<6;
				MDMA2->S1CR |= Direction<<6;

				MDMA2->S1NDTR = Copy_u16NumberOfData;
				MDMA2->S1PAR =Copy_u32PeripheralAddress;
				MDMA2->S1M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA2-> S1CR, 4);

				MDMA2->LIFCR |=0x3f<<6;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S1CR, 0);
				break;
			case 2:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S2CR , 0);
				while(GET_BIT(MDMA2->S2CR , 0));

				MDMA2->S2CR &= ~(0b11) <<6;
				MDMA2->S2CR |= Direction<<6;

				MDMA2->S2NDTR = Copy_u16NumberOfData;
				MDMA2->S2PAR =Copy_u32PeripheralAddress;
				MDMA2->S2M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA2-> S2CR, 4);

				MDMA2->LIFCR |=0x3f<<16;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S2CR, 0);
				break;
			case 3:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S3CR , 0);
				while(GET_BIT(MDMA2->S3CR , 0));

				MDMA2->S3CR &= ~(0b11) <<6;
				MDMA2->S3CR |= Direction<<6;

				MDMA2->S3NDTR = Copy_u16NumberOfData;
				MDMA2->S3PAR =Copy_u32PeripheralAddress;
				MDMA2->S3M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA2-> S3CR, 4);

				MDMA2->LIFCR |=0x3f<<22;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S3CR, 0);
				break;
			case 4:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S4CR , 0);
				while(GET_BIT(MDMA2->S4CR , 0));

				MDMA2->S4CR &= ~(0b11) <<6;
				MDMA2->S4CR |= Direction<<6;

				MDMA2->S4NDTR = Copy_u16NumberOfData;
				MDMA2->S4PAR =Copy_u32PeripheralAddress;
				MDMA2->S4M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA2-> S4CR, 4);

				MDMA2->HIFCR |=0x3f;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S4CR, 0);
				break;
			case 5:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S5CR , 0);
				while(GET_BIT(MDMA2->S5CR , 0));

				MDMA2->S5CR &= ~(0b11) <<6;
				MDMA2->S5CR |= Direction<<6;

				MDMA2->S5NDTR = Copy_u16NumberOfData;
				MDMA2->S5PAR =Copy_u32PeripheralAddress;
				MDMA2->S5M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA2-> S5CR, 4);

				MDMA2->HIFCR |=0x3f<<6;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S5CR, 0);
				break;
			case 6:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S6CR , 0);
				while(GET_BIT(MDMA2->S6CR , 0));

				MDMA2->S6CR &= ~(0b11) <<6;
				MDMA2->S6CR |= Direction<<6;

				MDMA2->S6NDTR = Copy_u16NumberOfData;
				MDMA2->S6PAR =Copy_u32PeripheralAddress;
				MDMA2->S6M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA2-> S6CR, 4);

				MDMA2->HIFCR |=0x3f<<16;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S6CR, 0);
				break;
			case 7:
				/*Disable Stream before config*/
				CLR_BIT(MDMA2->S7CR , 0);
				while(GET_BIT(MDMA2->S7CR , 0));

				MDMA2->S7CR &= ~(0b11) <<6;
				MDMA2->S7CR |= Direction<<6;

				MDMA2->S7NDTR = Copy_u16NumberOfData;
				MDMA2->S7PAR =Copy_u32PeripheralAddress;
				MDMA2->S7M0AR = Copy_u32MemoryAddress;

				/*Enable TCI interrupt*/
				SET_BIT(MDMA2-> S7CR, 4);

				MDMA2->HIFCR |=0x3f<<22;

				/*Enable Stream*/
				SET_BIT(MDMA2-> S7CR, 0);


				break;
		}
	}

}

void DMA1_Stream0_IRQHandler()
{

	/*Clear TCI flag*/
	SET_BIT(MDMA1->LIFCR , 5);
	CallBackFunc1[0]();
	Flag=DMA_Free;

}
void DMA1_Stream1_IRQHandler()
{

	/*Clear TCI flag*/
	SET_BIT(MDMA1->LIFCR , 11);
	CallBackFunc1[1]();
	Flag=DMA_Free;
}
void DMA1_Stream2_IRQHandler()
{

	/*Clear TCI flag*/
	SET_BIT(MDMA1->LIFCR , 21);
	CallBackFunc1[2]();
	Flag=DMA_Free;

}
void DMA1_Stream3_IRQHandler()
{
	/*Clear TCI flag*/
	SET_BIT(MDMA1->LIFCR , 27);
	CallBackFunc1[3]();
	Flag=DMA_Free;

}
void DMA1_Stream4_IRQHandler()
{

	/*Clear TCI flag*/
	SET_BIT(MDMA1->HIFCR , 5);
	CallBackFunc1[4]();
	Flag=DMA_Free;

}
void DMA1_Stream5_IRQHandler()
{
	/*Clear TCI flag*/
	SET_BIT(MDMA1->HIFCR , 11);
	CallBackFunc1[5]();
	Flag=DMA_Free;

}
void DMA1_Stream6_IRQHandler()
{
	/*Clear TCI flag*/
	SET_BIT(MDMA1->HIFCR , 21);
	CallBackFunc1[6]();
	Flag=DMA_Free;

}
void DMA1_Stream7_IRQHandler()
{

	/*Clear TCI flag*/
	SET_BIT(MDMA1->HIFCR , 27);
	CallBackFunc1[7]();

	Flag=DMA_Free;
}

void DMA2_Stream0_IRQHandler()
{

	/*Clear TCI flag*/
	SET_BIT(MDMA2->LIFCR , 5);
	CallBackFunc2[0]();

	Flag=DMA_Free;
}
void DMA2_Stream1_IRQHandler()
{

	/*Clear TCI flag*/
	SET_BIT(MDMA2->LIFCR , 11);
	CallBackFunc2[1]();
	Flag=DMA_Free;

}
void DMA2_Stream2_IRQHandler()
{

	/*Clear TCI flag*/
	SET_BIT(MDMA2->LIFCR , 21);
	CallBackFunc2[2]();
	Flag=DMA_Free;

}
void DMA2_Stream3_IRQHandler()
{
	/*Clear TCI flag*/
	SET_BIT(MDMA2->LIFCR , 27);
	CallBackFunc2[3]();
	Flag=DMA_Free;
}
void DMA2_Stream4_IRQHandler()
{
	/*Clear TCI flag*/
	SET_BIT(MDMA2->HIFCR , 5);
	CallBackFunc2[4]();
	Flag=DMA_Free;
}
void DMA2_Stream5_IRQHandler()
{
	/*Clear TCI flag*/
	SET_BIT(MDMA2->HIFCR , 11);
	CallBackFunc2[5]();
	Flag=DMA_Free;
}
void DMA2_Stream6_IRQHandler()
{
	/*Clear TCI flag*/
	SET_BIT(MDMA2->HIFCR , 21);
	CallBackFunc2[6]();
	Flag=DMA_Free;

}
void DMA2_Stream7_IRQHandler()
{
	/*Clear TCI flag*/
	SET_BIT(MDMA2->HIFCR , 27);

	CallBackFunc2[7]();
	Flag=DMA_Free;

}
