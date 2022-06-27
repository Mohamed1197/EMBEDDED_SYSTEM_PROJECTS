
/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#define  F_CPU 8000000UL

/* MCAL  */
#include "DIO_interface.h"
#include "GI_interface.h"
#include "EXTI_interface.h"
#include "TMR_interface.h"
#include "ADC_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "KPD_interface.h"

/* Functions Prototype  */
void Ask_For_Login(void);
void Display_Temperature_LCD(void);



int main(void)
{


	/* Peripherals Initialization */
	DIO_u8Init();
	ADC_voidInit();
    LCD_voidInit();


	/* Calls a Functions that asks the user to enter Password */
	Ask_For_Login();

    while(1)
    {

    	/* Calls a Functions that Displays The Current Temperature  */
    	Display_Temperature_LCD();





    }

	return 0;
}


/* Functions Implementation  */
void Display_Temperature_LCD(void)
{
	u16 Digital_Value, Analog_value;
	u8 Temerature , Temerature_dec;

	ADC_u8GetDigitalValueSunchNonBlocking(ADC_u8_CHANNEL_0,&Digital_Value);
	Analog_value = (u16)((Digital_Value*5000UL)/1024);
	Temerature_dec = (Analog_value % 10);
	Temerature = (Analog_value/10);


	LCD_voidClear();
	LCD_u8_GoTo_XY(0,1);
	LCD_voidWriteString("Temperature");
	LCD_u8_GoTo_XY(1,1);
	LCD_voidWriteNumber(Temerature);
	LCD_voidWriteString(".");
	LCD_voidWriteNumber(Temerature_dec);
	LCD_u8_GoTo_XY(1,6);
	LCD_voidWriteString("C");
	_delay_ms(1000);
}



void Ask_For_Login(void)
{
    u8 Local_u8Key;
    static u16 password = 2580 ,value , Num1=0;
    static u8 Operator = 0,counter=0 , counter2=0;

    LCD_voidWriteString("Enter Passcode :");
    LCD_u8_GoTo_XY(1,4);
	while(1)
	{
		KPD_u8GetKey(&Local_u8Key);
	       if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
	       {
	    	   if(counter<4)
	    	   {
	    		   counter++;

	    	   switch(Local_u8Key)
	    	   {
	    	   case '0':
	    		   value =0;
	    		   Num1 = (Num1*10) +value ;
	    		   LCD_voidSendChar('0');
	    		   break;
	    	   case '1':
	    		   value =1;
	    		   Num1 = (Num1*10) +value ;
	    		   LCD_voidSendChar('1');
	    		   break;
	    	   case '2':
	    	       value =2;
	    	       Num1 = (Num1*10) +value ;
	    		   LCD_voidSendChar('2');
	    	       break;
	    	   case '3':
	    	       value =3;
	    	       Num1 = (Num1*10) +value ;
	    		   LCD_voidSendChar('3');
	    	       break;
	    	   case '4':
	    	       value =4;
	    	       Num1 = (Num1*10) +value ;
	    		   LCD_voidSendChar('4');
	    	       break;
	    	   case '5':
	    	       value =5;
	    	       Num1 = (Num1*10) +value ;
	    		   LCD_voidSendChar('5');
	    	       break;
	    	   case '6':
	    	       value =6;
	    	       Num1 = (Num1*10) +value ;
	    		   LCD_voidSendChar('6');
	    	       break;
	    	   case '7':
	    	       value =7;
	    	       Num1 = (Num1*10) +value ;
	    		   LCD_voidSendChar('7');
	    	        break;
	       	   case '8':
	        	   value =8;
	        	   Num1 = (Num1*10) +value ;
	    		   LCD_voidSendChar('8');
	        	    break;
	           case '9':
	        	   value =9;
	        	   Num1 = (Num1*10) +value ;
	    		   LCD_voidSendChar('9');
	        	    break;
	           default:
	        	   LCD_voidClear();

	        	   LCD_u8_GoTo_XY(0,1);
	        	   LCD_voidWriteString("Please Enter");

	        	   LCD_u8_GoTo_XY(1,1);
	        	   LCD_voidWriteString("Numbers Only");
	        	   _delay_ms(1500);

	        	   LCD_voidClear();
	        	   LCD_voidWriteString("Try Again ");
	        	   LCD_u8_GoTo_XY(1,4);
	        	   _delay_ms(500);
	        	   counter =0 ;

	    	   }

	    	   }
	    	   if(counter>3)
	    	   {
	    		   if(Num1 == password)
	    		   {
	    		   _delay_ms(1000);

	    		   LCD_voidClear();
	    		   LCD_voidCursorBlinkerOff();
	    		   LCD_voidWriteString(" Welcome Mohamed");
	    		   _delay_ms(1000);
	    		   break;
	    		   }
	    		   else
	    		   {

	    			   if(counter2 < 2)
	    			   {
	    	    		 _delay_ms(1000);
	    	    		 LCD_voidInit();
	    			     LCD_voidWriteString("  Try Again ");
	    			     counter = 0 ;
	    			     Num1=0;
	    			     counter2++;
	    			     LCD_u8_GoTo_XY(1,4);


	    			   }
	    			   else
	    			   {
	    				   _delay_ms(1000);
	    				   LCD_voidClear();
	    				   LCD_voidCursorBlinkerOff();
	    				   LCD_voidWriteString(" Out of tries !");

	    				   break;
	    			   }

	    		   }
	    	   }


	       }
	}

}

