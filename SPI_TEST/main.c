/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* MCAL */
#include "DIO_interface.h"
#include "SPI_interface.h"

int main(void)
{
	u8 Local_u8Data;
	DIO_u8Init();

	SPI_voidInit();

	while(1)
	{
		SPI_u8TransRecive('a',&Local_u8Data);
		if(Local_u8Data == 10)
		{
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		}
		_delay_ms(200);
	}

	return 0;
}
