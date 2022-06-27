#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include "DIO_interface.h"
#include "WDT_interface.h"

int main(void)
{
	DIO_u8Init();

	while(1)
	{
		WDT_voidEnable();
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
		_delay_ms(1000);
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
		while(1);
		WDT_voidDisable();
	}
	return 0;
}
