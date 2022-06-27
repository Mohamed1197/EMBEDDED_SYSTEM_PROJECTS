/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "TMR_interface.h"
#include "GI_interface.h"

void App_voidTogLed(void);

int main(void)
{
	DIO_u8Init();
	GI_voidEnable();
	TMR_voidTimer1SetCompareMatchValueChannelA(10000);
	TMR_voidTimer1CTCCounter(100);
	TMR_u8Timer1CTCSetCallBack(&App_voidTogLed);
	TMR_voidTimer1Init();




    while(1);


	return 0;
}

void App_voidTogLed(void)
{
	static u8 Local_u8Flag = 0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
		Local_u8Flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
		Local_u8Flag = 0;
	}
}



