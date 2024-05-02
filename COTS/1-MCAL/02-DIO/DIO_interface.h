/***********************************************************/
/***********************************************************/
/*****************		Author: Islam Hany	****************/
/*****************		Layer: MCAL			****************/
/*****************		SWC: GPIO			****************/
/*****************		Version: 1.00		****************/
/***********************************************************/
/***********************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define HIGH    1
#define LOW     0

#define GPIOA   1
#define GPIOB   2
#define GPIOC   3


/*
	MODE options:
		INPUT
		GENERAL_OUTPUT
		ALTERNATE_FUNCTION
		ANALOG
	
	OutputType options:
		PUSH_PULL
		OPEN_DRAIN
		NONE	(For input type)
		
	OutputSpeed options:	
		LOW_SPEED
		MEDIUM_SPEED
		HIGH_SPEED
		VERY_HIGH_SPEED
		NONE  (For input type)
		
	InputPullType options:
		NO_PULL
		PULL_UP
		PULL_DOWN
		NONE  (For output type)
*/
typedef struct GPIO_PIN
{
	u8 MODE;
	u8 OutputType;
	u8 OutputSpeed;
	u8 InputPullType;
}MGPIO_PinType;

#define	 INPUT					0b00
#define	 GENERAL_OUTPUT         0b01
#define	 ALTERNATE_FUNCTION     0b10
#define	 ANALOG                 0b11

#define	PUSH_PULL		0
#define	OPEN_DRAIN		1

#define	LOW_SPEED			0b00
#define	MEDIUM_SPEED        0b01
#define	HIGH_SPEED          0b10
#define	VERY_HIGH_SPEED     0b11

#define FLOUTING			0b00
#define PULL_UP             0b01
#define PULL_DOWN           0b10

#define NONE	0xF			/*use it if not interested in choosing Except in MODE options*/



void MGPIO_VidSetPinDirection  ( u8 Copy_u8Port , u8 Copy_u8Pin , const	MGPIO_PinType*  Copy_pvPinType);
void MGPIO_VidSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value );
void MGPIO_VidSetPORTValue      ( u8 Copy_u8Port , u16 Copy_u8Value );
void MGPIO_VidSetPORTDirection  ( u8 Copy_u8Port , const MGPIO_PinType*  Copy_pvPinType );
u8   MGPIO_u8GetPinValue       ( u8 Copy_u8Port , u8 Copy_u8Pin);

/*Alterntive function values from 0 to 15*/
void MGPIO_voidSetPinAlterntaveFunction(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8AlterntiveFuncNumber);
#endif
