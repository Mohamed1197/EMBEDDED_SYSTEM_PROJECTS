#include<avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>
#define A       0b00000001
#define B       0b00000010
#define C       0b00000100
#define D       0b00001000
#define E       0b00010000
#define F       0b00100000

int main (void)
{
	// Configure PORTB Input
		DDRB = 0x00;
    // Configure PORTD Output
		DDRD = 0xFF;
	// Configure PORTC Output
		DDRC = 0xFF;
    // Activate pull up resistor on PB7 and PB6
	    PORTB = 0b11000000;
		unsigned char SevenSegment[8] = {A,B,C,D,D,E,F,A};



		while(1)
			{
			   // If Switch 2 is Pressed
		       if((PINB & 0b10000000) == 0  )
		        {
			      for(int i = 0 ; i<8 ; i++)
			      {
			    	  if(i<4)
			    	  {
			    	      PORTC = 0x02;
			              PORTD = ~SevenSegment[i] ;
			    	  }
			    	  else
			    	  {
			    		  PORTC = 0x01;
			    		  PORTD = ~SevenSegment[i] ;
			    	  }
			    	  _delay_ms(500);


			      }
		        }
		       // If Switch 1 is Pressed
		        else if((PINB & 0b01000000) == 0)
		        {
		        	for(int i = 7 ; i>=0 ; i--)
		        	      {
		        	    	  if(i>3)
		        		    	  {
		    			    	      PORTC = 0x01;
		        		              PORTD = ~SevenSegment[i] ;
		        		    	  }
		        		    	  else
		        		    	  {
		        		    		  PORTC = 0x02;
		        		    		  PORTD = ~SevenSegment[i] ;
		        		    	  }
		          		    	  _delay_ms(500);


		        			}
		        }
			    // If Switch is not Pressed
		        else if((PINB & 0b10000000) && (PINB & 0b01000000) != 0)
		        {
			      // Turn Off LED
		          PORTC = 0x00;
		         }
			}
}
