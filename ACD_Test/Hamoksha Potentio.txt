
/* Lib */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include<util/delay.h>
/* MCAL */
#include "DIO_interface.h"
#include "ADC_interface.h"

/* HAL */
#include "LCD_interface.h"



int main(void)
{
	u16 Local_u16DigitalValue,Local_u16AnalogValue,Local_u16LastAnalogValue,Local_u16Last2AnalogValue;


	  u8 HamokshaGoingRight[8]={0b00001110,
			                    0b00001110,
						        0b00000100,
						        0b00000111,
						        0b00001100,
						        0b00010100,
						        0b00001010,
						        0b00001010};

	  u8 HamokshaGoingLeft[8]={0b00001110,
			                   0b00001110,
						       0b00000100,
						       0b00011100,
						       0b00000110,
						       0b00000101,
						       0b00001010,
						       0b00001010};

	  u8 Hamokshastanding[8]={0b00001110,
	                          0b00001110,
			                  0b00000100,
			                  0b00011111,
			                  0b00000100,
			                  0b00000100,
			                  0b00001010,
			                  0b00001010};

	  u8 HamokshaRuning[8]={0b00001110,
			                0b00001110,
						    0b00000100,
						    0b00011111,
						    0b00000100,
						    0b00000100,
						    0b00001010,
						    0b00010001};

		DIO_u8Init();
		LCD_voidInit();
		ADC_voidInit();
		LCD_voidCursorBlinkerOff();
		LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(0,1,7,Hamokshastanding);


//1425mv light

//4980mv Dark
		while(1)
		{
			/* Read Analog Signal */
	  ADC_u8GetDigitalValueSunchNonBlocking(ADC_u8_CHANNEL_1,&Local_u16DigitalValue);
	  Local_u16AnalogValue = (u16)((Local_u16DigitalValue * 5000UL) /1024);

	  if((Local_u16AnalogValue > Local_u16LastAnalogValue) || (Local_u16AnalogValue < Local_u16Last2AnalogValue))
	  {
			LCD_voidClear();

	  if(Local_u16AnalogValue <= 312)
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,0,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,0,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue =0;



	  }
	  else if((Local_u16AnalogValue > 312) && (Local_u16AnalogValue <= 624))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,1,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,1,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;
	  }
	  else if((Local_u16AnalogValue > 624) && (Local_u16AnalogValue <= 936))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,2,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,2,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 936) && (Local_u16AnalogValue <= 1248))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,3,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,3,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 1248) && (Local_u16AnalogValue <= 1560 ))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,4,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,4,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 1560) && (Local_u16AnalogValue <= 1872 ))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,5,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,5,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 1872) && (Local_u16AnalogValue <= 2184))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,6,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,6,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 2184) && (Local_u16AnalogValue <= 2500))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,7,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,7,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 2500) && (Local_u16AnalogValue <= 2812))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,8,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,8,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 2812) && (Local_u16AnalogValue <= 3124))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,9,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,9,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 3124) && (Local_u16AnalogValue <= 3436))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,10,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,10,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 3436) && (Local_u16AnalogValue <= 3748))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,11,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,11,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 3748) && (Local_u16AnalogValue <= 4060))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,12,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,12,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 4060) && (Local_u16AnalogValue <= 4372))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,13,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,13,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 4372) && (Local_u16AnalogValue <= 4684))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,14,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,14,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }
	  else if((Local_u16AnalogValue > 4684))
	  {
		  LCD_u8_GoTo_XY(0,0);
		  LCD_voidWriteString("Adjust Potentio");
		  LCD_voidSendSpecialChar(1,1,15,HamokshaRuning);
		  _delay_ms(200);
		  LCD_voidSendSpecialChar(0,1,15,Hamokshastanding);
		  _delay_ms(200);
		  Local_u16LastAnalogValue = Local_u16AnalogValue + 150;
		  Local_u16Last2AnalogValue = Local_u16AnalogValue - 150;

	  }



	  }
		}





return 0;
}
