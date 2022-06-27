#include<avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>
#define ZERO  0b00111111
#define ONE   0b00000110
#define TWO   0b01011011
#define THREE 0b01001111
#define FOUR  0b01100110
#define FIVE  0b01101101
#define SIX   0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE  0b01101111
#define SW1   PINB & 0b01000000
#define SW2   PINB & 0b10000000

int main(void)
{

	   //configure PORTD output
	    DDRD = 0xFF;
		//configure PORTC output
		DDRC = 0xFF;
		//configure PORTB intput
		DDRB = 0x00;
		// Activate pull up resistor on PB7 & PB6
	    PORTB =0b11000000;
		unsigned char SevenSegment[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
		PORTC = 0xFF;
		int j =0;
		int i =0;
		while(1)
			{
			// If the 2 Switches are not Pressed
	         if((SW1) && (SW2) != 0)
	       		        {
	       		    	   while((SW1 && SW2 ) != 0)
	       		    	   {
	       		    	   PORTC = 0x02;
	       		    	   PORTD = ~SevenSegment[j];
	       		    	   _delay_ms(10);
	       		    	   PORTC = 0x01;
	       		    	   PORTD = ~SevenSegment[i];
	       		    	   _delay_ms(10);
	       		    	   }
	       		        }

		   // If Switch 1 is Pressed and Switch 2 is not pressed
	         else if (((SW1) == 0 ) && ((SW2) != 0 ))
		        {    i=0;
		        	 for(  ; i < 10 ; i++)
		        	 {
		        		 for(int k=0 ; k<20 ; k++)
		        		 {
		        				     PORTC = 0x02;
		        					 PORTD = ~SevenSegment[j];
		        					 _delay_ms(10);
		        					 PORTC = 0x01;
		        					 PORTD = ~SevenSegment[i];
		        					 _delay_ms(10);

		        		 }
		        		          if(((SW1) != 0) || ((SW2) == 0 ))
		        					 {
		        						 break;
		        					 }

		        		 }

		        }
			// If Switch 2 is Pressed and Switch 1 is not pressed
	         else if (((SW1) != 0 ) && ((SW2) == 0 ))
		        {
	        	 j=0;
		        	 for(  ; j < 10 ; j++)
		        	 {
		        		 for(int k=0 ; k<20 ; k++)
		        		 {
		        				     PORTC = 0x02;
		        					 PORTD = ~SevenSegment[j];
		        					 _delay_ms(10);
		        					 PORTC = 0x01;
		        					 PORTD = ~SevenSegment[i];
		        					 _delay_ms(10);

		        		 }
		        		 if(((SW2) != 0) || ((SW1) == 0 ))
		        		   {
		        			  break;
		        		   }

		        	 }

		        }
	         // If Switch 1 and Switch 2 are both pressed
	         else if(((SW1) && (SW2)) == 0)
	         {
	        	 for(  ;  ; i-- , j--)
	        	 {
	        		 if(i<0)
	        		 {
	        			 i=0;
	        		 }
	        		 if(j<0)
	        		 {
	        			 j=0;
	        		 }
	        		 for(int k=0 ; k<20 ; k++)
	        		 {
	        				     PORTC = 0x02;
	        					 PORTD = ~SevenSegment[j];
	        					 _delay_ms(10);
	        					 PORTC = 0x01;
	        					 PORTD = ~SevenSegment[i];
	        					 _delay_ms(10);

	        		 }
	        		 if((SW1 || SW2) != 0)
	        		   {
	        			  break;
	        		   }


	        	 }


	         }


			}
}

