/* Lib Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"
#define STEPPER_MOTOR               DIO_u8_PORTC
#define STEPPER_MOTOR_BLUE_COIL     DIO_u8_PIN0
#define STEPPER_MOTOR_PINK_COIL     DIO_u8_PIN1
#define STEPPER_MOTOR_YELLOW_COIL   DIO_u8_PIN2
#define STEPPER_MOTOR_ORANGE_COIL   DIO_u8_PIN3


int main(void)
{
	/* Connect PC3 to a led */
	/* Configure PC3 output */
	DIO_u8Init();
	u8 direction =0;

//	if(direction == 0)
//	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		_delay_ms(5000);
/*	}
	else if(direction == 1)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
	}
*/

while(1);



	return 0 ;
}
