/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: GPIO			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void MGPIO_VidSetPinDirection  ( u8 Copy_u8Port , u8 Copy_u8Pin , const	MGPIO_PinType*  Copy_pvPinType)
{
	switch(Copy_u8Port)
	{
	case GPIOA:

		if(Copy_u8Pin <= 15 && !((Copy_u8Pin == 13) || (Copy_u8Pin == 14)))
		{
			//MODER
			GPIOA_MODER &= ~ ( ( 0b11 )    << ( Copy_u8Pin * 2 ));
			GPIOA_MODER |= ( Copy_pvPinType->MODE ) << ( Copy_u8Pin * 2 );
			
			//GPIO port output type register
			if (Copy_pvPinType->OutputType <= 1 && Copy_pvPinType->OutputType !=NONE)
			{                                 
				CLR_BIT(GPIOA_OTYPER,Copy_u8Pin);
				GPIOA_OTYPER |= (Copy_pvPinType->OutputType)<<Copy_u8Pin;
			}
			
			//GPIO port output speed register
			if ((Copy_pvPinType->OutputSpeed) <= 3 && (Copy_pvPinType->OutputSpeed)!=NONE)
			{
				GPIOA_OSPEEDR &= ~ ( ( 0b11 )    << ( Copy_u8Pin * 2 ));
				GPIOA_OSPEEDR |= (Copy_pvPinType->OutputSpeed)<< ( Copy_u8Pin * 2 );
			}
			
			//GPIO port pull-up/pull-down register
			if(((Copy_pvPinType->InputPullType) <= 3) && (Copy_pvPinType->InputPullType) !=NONE)
			{
				GPIOA_PUPDR &= ~ ( ( 0b11 )    << ( Copy_u8Pin * 2 ));
				GPIOA_PUPDR |= (Copy_pvPinType->InputPullType)<< ( Copy_u8Pin * 2 );
			}
		}
		else
		{
			//do nothing
		}

		break;

	case GPIOB:

		if(Copy_u8Pin <= 15 && !(Copy_u8Pin == 11)  )
		{
			//MODER
			GPIOB_MODER &= ~ ( ( 0b11 )    << ( Copy_u8Pin * 2 ));
			GPIOB_MODER |= ( Copy_pvPinType->MODE ) << ( Copy_u8Pin * 2 );
			
			//GPIO port output type register
			if (Copy_pvPinType->OutputType <= 1 && Copy_pvPinType->OutputType !=NONE)
			{                                 
				CLR_BIT(GPIOB_OTYPER,Copy_u8Pin);
				GPIOB_OTYPER |= (Copy_pvPinType->OutputType)<<Copy_u8Pin;
			}
			
			//GPIO port output speed register
			if ((Copy_pvPinType->OutputSpeed) <= 3 && (Copy_pvPinType->OutputSpeed)!=NONE)
			{
				GPIOB_OSPEEDR &= ~ ( ( 0b11 )    << ( Copy_u8Pin * 2 ));
				GPIOB_OSPEEDR |= (Copy_pvPinType->OutputSpeed)<<( Copy_u8Pin * 2 );
			}
			
			//GPIO port pull-up/pull-down register
			if(((Copy_pvPinType->InputPullType) <= 3) && (Copy_pvPinType->InputPullType) !=NONE)
			{
				GPIOB_PUPDR &= ~ ( ( 0b11 )    << ( Copy_u8Pin * 2 ));
				GPIOB_PUPDR |= (Copy_pvPinType->InputPullType)<<( Copy_u8Pin * 2 );
			}
		}
		else
		{
			//do nothing
		}

		break;
	case GPIOC:
		if(Copy_u8Pin <= 15 && Copy_u8Pin >= 13)
		{
			//MODER
			GPIOC_MODER &= ~ ( ( 0b11 )    << ( Copy_u8Pin * 2 ));
			GPIOC_MODER |= ( Copy_pvPinType->MODE ) << ( Copy_u8Pin * 2 );
			
			//GPIO port output type register
			if (Copy_pvPinType->OutputType <= 1 && Copy_pvPinType->OutputType !=NONE)
			{                                 
				CLR_BIT(GPIOC_OTYPER,Copy_u8Pin);
				GPIOC_OTYPER |= (Copy_pvPinType->OutputType)<<Copy_u8Pin;
			}
			
			//GPIO port output speed register
			if ((Copy_pvPinType->OutputSpeed) <= 3 && (Copy_pvPinType->OutputSpeed)!=NONE)
			{
				GPIOC_OSPEEDR &= ~ ( ( 0b11 )    << ( Copy_u8Pin * 2 ));
				GPIOC_OSPEEDR |= (Copy_pvPinType->OutputSpeed)<<( Copy_u8Pin * 2 );
			}
			
			//GPIO port pull-up/pull-down register
			if(((Copy_pvPinType->InputPullType) <= 3) && (Copy_pvPinType->InputPullType) !=NONE)
			{
				GPIOC_PUPDR &= ~ ( ( 0b11 )    << ( Copy_u8Pin * 2 ));
				GPIOC_PUPDR |= (Copy_pvPinType->InputPullType)<<( Copy_u8Pin * 2 );
			}
		}
		else
		{
			//do nothing
		}

		break;
	default :break;
	}


}

void MGPIO_VidSetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value ){

	switch(Copy_u8Port)
	{
	case GPIOA:
		if( Copy_u8Value == HIGH ){

			GPIOA_BSRR = 1<<Copy_u8Pin;

		}else if( Copy_u8Value == LOW ){
			GPIOA_BSRR = 1<<(Copy_u8Pin + 16);
		}
		break;
		
	case GPIOB:
		if( Copy_u8Value == HIGH ){

			GPIOB_BSRR = 1<<Copy_u8Pin;

		}else if( Copy_u8Value == LOW ){
			GPIOB_BSRR = 1<<(Copy_u8Pin + 16);
		}
		break;
		
	case GPIOC:
		if( Copy_u8Value == HIGH ){

			GPIOC_BSRR = 1<<Copy_u8Pin;

		}else if( Copy_u8Value == LOW ){
			GPIOC_BSRR = 1<<(Copy_u8Pin + 16);
		}
		break;

	}

}

u8   MGPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port)
	{
	case GPIOA:
		LOC_u8Result = GET_BIT( GPIOA_IDR , Copy_u8Pin );

		break;
	case GPIOB:

		LOC_u8Result = GET_BIT( GPIOB_IDR , Copy_u8Pin );

		break;
	case GPIOC:

		LOC_u8Result = GET_BIT( GPIOC_IDR , Copy_u8Pin );

		break;
	}
	return LOC_u8Result;
}


void MGPIO_VidSetPORTValue( u8 Copy_u8Port , u16 Copy_u8Value )
{
	switch(Copy_u8Port)
	{
	case GPIOA:
		GPIOA_ODR &=0xffff0000;
		GPIOA_ODR |=Copy_u8Value;
		break;
	case GPIOB:
		GPIOB_ODR &=0xffff0000;
		GPIOB_ODR |=Copy_u8Value;
		break;
	case GPIOC:
		GPIOC_ODR &=0xffff0000;
		GPIOC_ODR |=Copy_u8Value;
		break;
	default: break;
	}
}


void MGPIO_VidSetPORTDirection  ( u8 Copy_u8Port , const MGPIO_PinType*  Copy_pvPinType )
{
	switch(Copy_u8Port)
		{
		case GPIOA:
				//MODER
				GPIOA_MODER &= 0b1111<<26;
				for(u8 Local_Iterator = 0 ; Local_Iterator<16 ; Local_Iterator++)
				{
					if (Local_Iterator == 13 || Local_Iterator == 14) continue;
					GPIOA_MODER |= ( Copy_pvPinType->MODE ) << ( Local_Iterator * 2 );
				}

				//GPIO port output type register
				if (Copy_pvPinType->OutputType <= 1)
				{
					GPIOA_OTYPER &=0xffff0000 | (0b11<<13);
					for(u8 Local_Iterator = 0 ; Local_Iterator<16 ; Local_Iterator++)
					{
						if (Local_Iterator == 13 || Local_Iterator == 14) continue;
						GPIOA_OTYPER |= (Copy_pvPinType->OutputType)<<Local_Iterator;
					}
				}

				//GPIO port output speed register
				if ((Copy_pvPinType->OutputSpeed) <= 3)
				{
					GPIOA_OSPEEDR &= 0b1111<<26;
					for(u8 Local_Iterator = 0 ; Local_Iterator<16 ; Local_Iterator++)
					{
						if (Local_Iterator == 13 || Local_Iterator == 14) continue;
						GPIOA_OSPEEDR |= (Copy_pvPinType->OutputSpeed)<< ( Local_Iterator * 2 );
					}
				}

				//GPIO port pull-up/pull-down register
				if(((Copy_pvPinType->InputPullType) <= 3))
				{
					GPIOA_PUPDR &= 0b1111<<26;
					for(u8 Local_Iterator = 0 ; Local_Iterator<16 ; Local_Iterator++)
					{
						if (Local_Iterator == 13 || Local_Iterator == 14) continue;
						GPIOA_PUPDR |= (Copy_pvPinType->InputPullType)<< ( Local_Iterator * 2 );
					}
				}
			break;

		case GPIOB:

				//MODER
				GPIOB_MODER &=1<<11;
				for(u8 Local_Iterator = 0 ; Local_Iterator<16 ; Local_Iterator++)
            	{
					if (Local_Iterator == 11) continue;
					GPIOB_MODER |= ( Copy_pvPinType->MODE ) << ( Local_Iterator * 2 );
				}
			
				//GPIO port output type register
				if (Copy_pvPinType->OutputType <= 1)
				{
            		GPIOB_OTYPER &=0xffff0000 | (1<<11);
					for(u8 Local_Iterator = 0 ; Local_Iterator<16 ; Local_Iterator++)
					{
						if (Local_Iterator == 11) continue;
						GPIOB_OTYPER |= (Copy_pvPinType->OutputType)<<Local_Iterator;
					}
				}
			
            	//GPIO port output speed register
				if ((Copy_pvPinType->OutputSpeed) <= 3)
				{
					GPIOB_OSPEEDR &=1<<11;
					for(u8 Local_Iterator = 0 ; Local_Iterator<16 ; Local_Iterator++)
					{
						if (Local_Iterator == 11) continue;
						GPIOB_OSPEEDR |= (Copy_pvPinType->OutputSpeed)<< ( Local_Iterator * 2 );
					}
				}
			
				//GPIO port pull-up/pull-down register
				if(((Copy_pvPinType->InputPullType) <= 3))
            	{
					GPIOB_PUPDR &=1<<11;
					for(u8 Local_Iterator = 0 ; Local_Iterator<16 ; Local_Iterator++)
					{
						if (Local_Iterator == 11) continue;
						GPIOB_PUPDR |= (Copy_pvPinType->InputPullType)<< ( Local_Iterator * 2 );
					}
				}

			break;
			
		case GPIOC:

				//MODER
				GPIOC_MODER &=~(0x3F<<26);
				for(u8 Local_Iterator = 13 ; Local_Iterator<16 ; Local_Iterator++)
            	{
					GPIOC_MODER |= ( Copy_pvPinType->MODE ) << ( Local_Iterator * 2 );
				}
			
				//GPIO port output type register
				if (Copy_pvPinType->OutputType <= 1)
				{
            		GPIOC_OTYPER &=~(0b111<<13);
					for(u8 Local_Iterator = 13 ; Local_Iterator<16 ; Local_Iterator++)
					{
						GPIOC_OTYPER |= (Copy_pvPinType->OutputType)<<Local_Iterator;
					}
				}
			
            	//GPIO port output speed register
				if ((Copy_pvPinType->OutputSpeed) <= 3)
				{
					GPIOC_OSPEEDR &=~(0x3F<<26);
					for(u8 Local_Iterator = 13 ; Local_Iterator<16 ; Local_Iterator++)
					{
						GPIOC_OSPEEDR |= (Copy_pvPinType->OutputSpeed)<< ( Local_Iterator * 2 );
					}
				}
			
				//GPIO port pull-up/pull-down register
				if(((Copy_pvPinType->InputPullType) <= 3))
            	{
					GPIOC_PUPDR &=~(0x3F<<26);
					for(u8 Local_Iterator = 13 ; Local_Iterator<16 ; Local_Iterator++)
					{
						GPIOC_PUPDR |= (Copy_pvPinType->InputPullType)<< ( Local_Iterator * 2 );
					}
				}
			
			break;
		default :break;
		}
}


void MGPIO_voidSetPinAlterntaveFunction(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8AlterntiveFuncNumber)
{
	if (Copy_u8Pin <8)
	{
		switch(Copy_u8Port)
			{
			case GPIOA:
				GPIOA_AFRL |= (Copy_u8AlterntiveFuncNumber<<Copy_u8Pin*4);
				break;
			case GPIOB:
				GPIOB_AFRL |= (Copy_u8AlterntiveFuncNumber<<Copy_u8Pin*4);
				break;
			case GPIOC:
				GPIOB_AFRL |= (Copy_u8AlterntiveFuncNumber<<Copy_u8Pin*4);
				break;
			}
	}
	else
	{
		switch(Copy_u8Port)
			{
			case GPIOA:
				GPIOA_AFRH |= (Copy_u8AlterntiveFuncNumber<<(Copy_u8Pin-8)*4);
				break;
			case GPIOB:
				GPIOB_AFRH |= (Copy_u8AlterntiveFuncNumber<<(Copy_u8Pin-8)*4);
				break;
			case GPIOC:
				GPIOC_AFRH |= (Copy_u8AlterntiveFuncNumber<<(Copy_u8Pin-8)*4);
				break;
			}
	}
}
