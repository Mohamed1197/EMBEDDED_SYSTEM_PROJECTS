
/* Lib */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include<util/delay.h>
/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "KPD_interface.h"

int main(void)
{
    u8 Local_u8Key,Operator = 0,counter=0 , counter2=0;
    u16 password = 2580 ,value , Num1=0;
	DIO_u8Init();
    LCD_voidInit();
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
    		   LCD_voidSendChar('*');
    		   break;
    	   case '1':
    		   value =1;
    		   Num1 = (Num1*10) +value ;
    		   LCD_voidSendChar('*');
    		   break;
    	   case '2':
    	       value =2;
    	       Num1 = (Num1*10) +value ;
    		   LCD_voidSendChar('*');
    	       break;
    	   case '3':
    	       value =3;
    	       Num1 = (Num1*10) +value ;
    		   LCD_voidSendChar('*');
    	       break;
    	   case '4':
    	       value =4;
    	       Num1 = (Num1*10) +value ;
    		   LCD_voidSendChar('*');
    	       break;
    	   case '5':
    	       value =5;
    	       Num1 = (Num1*10) +value ;
    		   LCD_voidSendChar('*');
    	       break;
    	   case '6':
    	       value =6;
    	       Num1 = (Num1*10) +value ;
    		   LCD_voidSendChar('*');
    	       break;
    	   case '7':
    	       value =7;
    	       Num1 = (Num1*10) +value ;
    		   LCD_voidSendChar('*');
    	        break;
       	   case '8':
        	   value =8;
        	   Num1 = (Num1*10) +value ;
    		   LCD_voidSendChar('*');
        	    break;
           case '9':
        	   value =9;
        	   Num1 = (Num1*10) +value ;
    		   LCD_voidSendChar('*');
        	    break;
    	   }

    	   }
    	   if(counter>3)
    	   {
    		   if(Num1 == password)
    		   {
    		   _delay_ms(1000);
			   DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_LOW);
			   DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH);
    		   LCD_voidClear();
    		   LCD_voidCursorBlinkerOff();
    		   LCD_voidWriteString(" Welcome Mohamed");
    		   break;
    		   }
    		   else
    		   {
    			   DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_LOW);
    			   DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_HIGH);
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
    				   for(u8 x =0; ; x++)
    				   {
        			   DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_LOW);
        			   _delay_ms(500);
        			   DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN6,DIO_u8_HIGH);
        			   _delay_ms(500);
    				   }
    				   break;
    			   }

    		   }
    	   }


       }



    }

	return 0;
}

