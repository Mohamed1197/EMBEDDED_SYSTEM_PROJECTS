#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include "GI_interface.h"

void TOG_LED(void);

int main(void)
{
	DIO_u8Init();
	/* Enable Global Interrupt */
	GI_voidEnable();
	/* Set call Back for EXTI0  */
	EXTI_u8SetCallBack(&TOG_LED,EXTI_u8_INT0);
	/* Enable ECTI0 */
	EXTI_u8Enable(EXTI_u8_INT0,EXTI_u8_FALLING_EDGE);
	while(1);
	return 0;
}


void TOG_LED(void)
{
	static u8 Local_u8Flag =0 ;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		Local_u8Flag =1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		Local_u8Flag =0;
	}

}
