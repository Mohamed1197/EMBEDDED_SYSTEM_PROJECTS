#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "EERPROM_interface.h"

int main(void)
{
	u8 Local_u8Data;

	DIO_u8Init();

	EEPROM_voidInit();

	LCD_voidInit();

	EEPROM_u8WriteDataByte(5,20);

	EEPROM_u8ReadDataByte(&Local_u8Data,20);

	LCD_voidWriteNumber(Local_u8Data);

	while(1);
	return 0;
}
