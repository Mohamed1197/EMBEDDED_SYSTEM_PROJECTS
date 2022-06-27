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
int main(void)
{
	unsigned char SevenSegment1[2]={ZERO,ONE};
	unsigned char SevenSegment2[10]={ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,ZERO};
	//configure PORTD output
	DDRD = 0xFF;
	//configure PORTC output
	DDRC = 0xFF;
	//configure PORTA output
	DDRA = 0xFF;
	while(1)
	{
		 //Turn on Green LED
		PORTA=0b00000100;
		// seven segment 10 seconds countdown
	   PORTD = ~SevenSegment1[1];
	   for(int j=9; j>=0; j--)
			  {
			     // 7 segment is common anode
				 PORTC = ~SevenSegment2[j];
				 _delay_ms(1000);
				 PORTD = ~SevenSegment1[0];
			  }

	   //Turn on Yellow LED
		PORTA=0b00000010;
	   // seven segment 3 seconds countdown
		PORTD = ~SevenSegment1[0];
		for(int j=2; j>=0; j--)
		  {
	     	// 7 segment is common anode
			PORTC = ~SevenSegment2[j];
			_delay_ms(1000);
		   }

		 //Turn on Red LED
		PORTA=0b00000001;
		// seven segment 10 seconds countdown
		PORTD = ~SevenSegment1[1];
	    for(int j=9; j>=0; j--)
		  	{
		      // 7 segment is common anode
	        	PORTC = ~SevenSegment2[j];
			   _delay_ms(1000);
		        PORTD = ~SevenSegment1[0];
	        }


	}
}
