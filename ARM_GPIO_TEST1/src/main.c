#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Delay.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"



int main(void)
{
	/*RCC INITIAIZATION*/
	RCC_voidInit();

	/*Enable Clock for GPIOA */
	RCC_voidEnableClock(RCC_APB2, 2);
	RCC_voidEnableClock(RCC_APB2, 3);
	RCC_voidEnableClock(RCC_APB2, 4);

	/* Set Port Direction */
	MGPIO_voidSetPortDirection(GPIO_u8_PORTA,GPIO_u8_HIGH_PINS,GPIO_OUTPUT_10MHZ_PUSH_PULL);
	MGPIO_voidSetPortDirection(GPIO_u8_PORTA,GPIO_u8_LOW_PINS,GPIO_OUTPUT_10MHZ_PUSH_PULL);
	MGPIO_voidSetPortDirection(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,GPIO_OUTPUT_10MHZ_PUSH_PULL);
	MGPIO_voidSetPortDirectionRegister(GPIO_u8_PORTA , GPIO_u8_LOW_PINS , 0x22222222 );


	/*SET PIN VALUE*/



	while(1)
	{

		//MGPIO_voidSetPortValue(GPIO_u8_PORTA,GPIO_u8_HIGH_PINS,GPIO_u8_HIGH);
		MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN8,GPIO_u8_HIGH);
		MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN9,GPIO_u8_LOW);

		MGPIO_voidSetPortValueRegister(GPIO_u8_PORTA,0x0118);

		MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,0b1011011000000000);

//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN9,GPIO_u8_HIGH);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN10,GPIO_u8_HIGH);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN11,GPIO_u8_LOW);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN12,GPIO_u8_HIGH);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN13,GPIO_u8_HIGH);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN14,GPIO_u8_LOW);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN15,GPIO_u8_HIGH);

		Delay(1000);
		MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN9,GPIO_u8_HIGH);
		MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN8,GPIO_u8_LOW);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN2,GPIO_u8_HIGH);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN5,GPIO_u8_HIGH);

		MGPIO_voidSetPortValueRegister(GPIO_u8_PORTA,0x0282);

		MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,0b0000111000000000);

//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN9,GPIO_u8_HIGH);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN10,GPIO_u8_HIGH);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN11,GPIO_u8_HIGH);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN12,GPIO_u8_LOW);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN13,GPIO_u8_LOW);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN14,GPIO_u8_LOW);
//		MGPIO_voidSetPinValue(GPIO_u8_PORTB,GPIO_u8_PIN15,GPIO_u8_LOW);
		Delay(1000);


	}


	return 0;
}
