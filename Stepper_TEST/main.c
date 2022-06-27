
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
#include "STP_interface.h"

int main(void)
{

	u8 Local_u8Key,Operator = 0,counter=0 , counter2=0,flag =0,flag2=0,flag3=0 ,Dir=0;
    u16 password = 2580 ,value , Num1=0,Num2=0;
	DIO_u8Init();
	 Start:
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
	    		    LCD_voidClear();
	    		    LCD_voidCursorBlinkerOff();
	    		    LCD_voidWriteString("Welcome to Motor");
	    		    LCD_u8_GoTo_XY(1,3);
	    		    LCD_voidWriteString("Dash Board");
	    		   _delay_ms(2000);
	    		   repeat:
	    		   LCD_voidClear();
	    		   LCD_voidWriteString("1-DCMotor 3-Exit");
	    		   LCD_u8_GoTo_XY(1,0);
	    		   LCD_voidWriteString("2-StepperMotor");


		    	       while(1)
		    		   {
		    	    	KPD_u8GetKey(&Local_u8Key);
	    	          if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
  	    	           {
	    	        	  LCD_voidClear();
	    		    	   switch(Local_u8Key)
	    		    	   {

                           case '1':
                           	   value =1;
                               LCD_voidWriteString("Direction: ");
                               LCD_u8_GoTo_XY(1,0);
                               LCD_voidWriteString("1-CW    2-CCW");
                               while(1)
                               {
                               KPD_u8GetKey(&Local_u8Key);
                        	   if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
                        	       {

                 	    	   switch(Local_u8Key)
                 	    	   {

                 	    	   case '1':
                 	    		   Dir =Clockwise;
                 	    		   flag3 =1;
                 	    		   break;
                 	    	   case '2':
                 	    		   Dir =AntiClockwise;
                 	    		   flag3 =1;
                 	    		   break;
                 	    	   }

                    	       }
                	    	   if (flag3 ==1 )
                	    	   {
                	               flag3 = 0;
                	    		   DC_voidRotation(Dir);
                  	               LCD_voidClear();
                      	    	   LCD_voidWriteString("   Press any");
                                   LCD_u8_GoTo_XY(1,0);
                                   LCD_voidWriteString("  Key to Stop");

                                   while(1)
                                   {
                                   KPD_u8GetKey(&Local_u8Key);
                            	   if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
                            	       {
                                       DC_voidStop();
                            		   break;
                            	       }
                                   }
                	    		   goto repeat;
                                   break;

                    	       }

            	    	   }
                           	   break;
                           case '2':
                        	  reenter:
                              value =2;
                              Num2=0;
                              LCD_voidClear();
                              LCD_voidWriteString("Angle : ");
                              while(1)
                               {
                          	   KPD_u8GetKey(&Local_u8Key);
         	    	          if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
           	    	           {
                	    	   switch(Local_u8Key)
                	    	   {
                	    	   case '0':
                	    		   value =0;
                	    		   Num2 = (Num2*10) +value ;
                	    		   LCD_voidSendChar('0');
                	    		   break;
                	    	   case '1':
                	    		   value =1;
                	    		   Num2 = (Num2*10) +value ;
                	    		   LCD_voidSendChar('1');
                	    		   break;
                	    	   case '2':
                	    	       value =2;
                	    	       Num2 = (Num2*10) +value ;
                	    		   LCD_voidSendChar('2');
                	    	       break;
                	    	   case '3':
                	    	       value =3;
                	    	       Num2 = (Num2*10) +value ;
                	    		   LCD_voidSendChar('3');
                	    	       break;
                	    	   case '4':
                	    	       value =4;
                	    	       Num2 = (Num2*10) +value ;
                	    		   LCD_voidSendChar('4');
                	    	       break;
                	    	   case '5':
                	    	       value =5;
                	    	       Num2 = (Num2*10) +value ;
                	    		   LCD_voidSendChar('5');
                	    	       break;
                	    	   case '6':
                	    	       value =6;
                	    	       Num2 = (Num2*10) +value ;
                	    		   LCD_voidSendChar('6');
                	    	       break;
                	    	   case '7':
                	    	       value =7;
                	    	       Num2 = (Num2*10) +value ;
                	    		   LCD_voidSendChar('7');
                	    	        break;
                	       	   case '8':
                	        	   value =8;
                	        	   Num2 = (Num2*10) +value ;
                	    		   LCD_voidSendChar('8');
                	        	    break;
                	           case '9':
                	        	   value =9;
                	        	   Num2 = (Num2*10) +value ;
                	    		   LCD_voidSendChar('9');
                	        	    break;
                	           case '=':
                	               flag = 1;
                	        	   LCD_voidSendChar(223);
                	        	   _delay_ms(1000);
              	              	   LCD_voidClear();
              	              	   if(Num2 > 360)
              	              	   {
              	              		   LCD_voidWriteString("Re-enter a");
              	              		   LCD_u8_GoTo_XY(1,0);
              	              		   LCD_voidWriteString("Correct Angle");
              	              		  _delay_ms(1500);
              	              		  flag =0 ;
              	              		  goto reenter;
              	              	   }
                                   LCD_voidWriteString("Direction: ");
                                   LCD_u8_GoTo_XY(1,0);
                                   LCD_voidWriteString("1-CW    2-CCW");

                                   while(1)
                                   {
                                   KPD_u8GetKey(&Local_u8Key);
                            	   if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
                            	       {
                     	    	   switch(Local_u8Key)
                     	    	   {
                     	    	   case '1':
                     	    		   Dir =Clockwise;
                     	    		   flag2 =1;
                     	    		   break;
                     	    	   case '2':
                     	    		   Dir =AntiClockwise;
                     	    		   flag2 =1;
                     	    		   break;
                     	    	   }

                        	       }
                    	    	   if (flag2 ==1 )
                    	    	   {
                                       break;

                        	       }

                	    	   }

                	    	   }
           	    	           }

                	    	   if (flag ==1 )
                	    	   {
                                   break;
         		    		   }
                               }

                               break;
                           case '3':
                               counter =0;
                               Num1=0;
                               goto Start;
                               break;
  	    	                  }
	    		    	   }


	       	    	     if (flag ==1 )
	       	    	       {
	       	    	    	 Stepper_u8Rotation(Num2,Dir);
	       	    	    	 flag =0;
	       	    	    	 flag2 =0;
	                         goto repeat;

			    		   }
	    		    }


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
