#define F_CPU 8000000UL
#include<util/delay.h>
/* Lib */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"
/* HAL */
#include "LCD_interface.h"

int main(void)
{
	/* Dio Init */
	DIO_u8Init();
	/* LCD init */
	LCD_voidInit();
	LCD_voidCursorBlinkerOff();
	/* Write My Name */

  u8 HamokshaRuning[8]={0b00001110,
		                0b00001110,
					    0b00000100,
					    0b00011111,
					    0b00000100,
					    0b00000100,
					    0b00001010,
					    0b00001001};

  u8 Hamokshastanding[8]={0b00001110,
                          0b00001110,
		                  0b00000100,
		                  0b00011111,
		                  0b00000100,
		                  0b00000100,
		                  0b00001010,
		                  0b00001010};

  u8 BallDown[8]={0b00000000,
		          0b00000000,
		          0b00000000,
		          0b00000000,
		          0b00000000,
		          0b00011000,
		          0b00011000,
		          0b00000000};

  u8 BallUp[8]={0b00000000,
                0b00000000,
                0b00000000,
                0b00000000,
                0b00000110,
                0b00000110,
                0b00000000,
                0b00000000};

  u8 Goal[8]={0b00011000,
		      0b00011100,
		      0b00010110,
		      0b00010011,
		      0b00010001,
		      0b00001101,
		      0b00001101,
		      0b00000001};

  u8 HamokshaHandsUp[8]={0b00001110,
		                 0b00001110,
					     0b00010101,
					     0b00001110,
					     0b00000100,
					     0b00000100,
			             0b00001010,
				         0b00010001};

  u8 HamokshaHandsDown[8]={0b00001110,
		                   0b00001110,
					       0b00000100,
					       0b00001110,
					       0b00010101,
					       0b00000100,
					       0b00001010,
					       0b00010001};

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

while(1)
	{
	DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
	LCD_voidClear();

 // FRAME 1
  LCD_u8_GoTo_XY(0,2);
  LCD_voidWriteString("I'm Hamoksha");
  LCD_voidSendSpecialChar(0,1,8,Hamokshastanding);
  _delay_ms(2000);
  LCD_voidClear();

  //FRAME 2
  LCD_u8_GoTo_XY(0,0);
  LCD_voidWriteString("I Play FootBall");
  LCD_voidSendSpecialChar(0,1,8,Hamokshastanding);
  _delay_ms(2000);
  for(u8 i =0 ; i<7 ;i++)
  {
  LCD_voidClear();
  LCD_voidSendSpecialChar(1,1,4+i,HamokshaRuning);
  LCD_voidSendSpecialChar(2,1,5+i,BallDown);
  _delay_ms(200);
  LCD_voidClear();
  LCD_voidSendSpecialChar(0,1,5+i,Hamokshastanding);
  LCD_voidSendSpecialChar(3,1,6+i,BallUp);
  _delay_ms(200);
  }
  LCD_voidClear();
  LCD_u8_GoTo_XY(0,4);
  LCD_voidWriteString("Goaaaaaal!");
  LCD_voidSendSpecialChar(0,1,13,Hamokshastanding);
  LCD_voidSendSpecialChar(4,1,15,Goal);
  _delay_ms(2000);
  LCD_voidClear();
  DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);




  //FRAME 3
  LCD_u8_GoTo_XY(0,4);
  LCD_voidWriteString("I Can Dance");
  LCD_voidSendSpecialChar(0,1,8,Hamokshastanding);
  _delay_ms(2000);
  for(u8 i =0 ; i<10 ;i++)
  {
	  LCD_voidClear();
	  LCD_voidSendSpecialChar(1,1,8,HamokshaHandsUp);
	  _delay_ms(400);
	  LCD_voidClear();
	  LCD_voidSendSpecialChar(0,1,8,Hamokshastanding);
	  _delay_ms(400);
	  LCD_voidClear();
	  LCD_voidSendSpecialChar(2,1,8,HamokshaGoingRight);
	  _delay_ms(400);
	  LCD_voidClear();
	  LCD_voidSendSpecialChar(0,1,9,Hamokshastanding);
	  _delay_ms(400);
	  LCD_voidClear();
	  LCD_voidSendSpecialChar(3,1,9,HamokshaHandsDown);
	  _delay_ms(400);
	  LCD_voidClear();
	  LCD_voidSendSpecialChar(4,1,9,HamokshaGoingLeft);
	  _delay_ms(400);
	  LCD_voidClear();
	  LCD_voidSendSpecialChar(4,1,8,HamokshaGoingLeft);
	  _delay_ms(400);
	  LCD_voidClear();
	  LCD_voidSendSpecialChar(2,1,7,HamokshaGoingRight);
	  _delay_ms(400);
  }

	}


}
