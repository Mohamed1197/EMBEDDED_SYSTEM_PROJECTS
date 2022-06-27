/* Lib */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include<util/delay.h>

/* MCAL */
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "GI_interface.h"

/* HAL */
#include "LCD_interface.h"

void App_voidADCNotificationFunction(u16 Copy_u16DigitalValue);

u16 App_u16DigitalValue= 0xffff;

int main(void)
{
	u16 Local_u16AnalogValue,Local_u16TempValue;
	DIO_u8Init();
	GI_voidEnable();
	LCD_voidInit();
	ADC_voidInit();
	while(1)
	{
		/* Read Analog Signal */
		ADC_u8GetDigitalValueAsync(ADC_u8_CHANNEL_0,App_voidADCNotificationFunction);
		if(App_u16DigitalValue != 0xffff)
		{
			Local_u16AnalogValue = (u16)((App_u16DigitalValue * 5000UL) /1024);
			Local_u16TempValue = Local_u16AnalogValue/10 ;
			LCD_u8_GoTo_XY(1,7);
			LCD_voidWriteNumber(Local_u16TempValue);
			_delay_ms(1000);
			App_u16DigitalValue = 0xffff;

		}

	}
	return 0;
}

void App_voidADCNotificationFunction(u16 Copy_u16DigitalValue)
{
	App_u16DigitalValue = Copy_u16DigitalValue ;

	//ADC_u8ReadADCRegister(&App_u16DigitalValue);
}
