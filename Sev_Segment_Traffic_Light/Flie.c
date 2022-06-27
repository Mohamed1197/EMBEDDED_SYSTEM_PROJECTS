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
	unsigned char SevenSegment[10]={ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,ZERO};
	//configure PORTD output
	DDRD = 0xFF;
	//configure PORTC output
	DDRC = 0xFF;
	//configure PORTA output
	DDRA = 0xFF;
	while(1)
	{
	 int j =0;
     //Turn on Green LED
     PORTA = 0b00000100;
	 for(int i = 9, j = 0; i >= 0 ; i--, j = 9 )
	    {

		    for(int k =49 ; k >= 0 ; k--)
		    {
		       PORTC = 0x01;
		       PORTD = ~SevenSegment[j];
		       _delay_ms(10);
    	       PORTC = 0x02;
	           PORTD = ~SevenSegment[i];
		       _delay_ms(10);
		     }
		 }
     //Turn on Yellow LED
     PORTA = 0b00000010;
	 for(int i = 2; i >= 0 ; i-- )
	    {

		    for(int k =49 ; k >= 0 ; k--)
		    {
		       j = 9;
		       PORTC = 0x01;
		       PORTD = ~SevenSegment[j];
		       _delay_ms(10);
    	       PORTC = 0x02;
	           PORTD = ~SevenSegment[i];
		       _delay_ms(10);
		     }
		 }
	 //Turn on Red LED
	      PORTA = 0b00000001;
	 	 for(int i = 9, j = 0; i >= 0 ; i--, j = 9 )
	 	    {

	 		    for(int k =49 ; k >= 0 ; k--)
	 		    {
	 		       PORTC = 0x01;
	 		       PORTD = ~SevenSegment[j];
	 		       _delay_ms(10);
	     	       PORTC = 0x02;
	 	           PORTD = ~SevenSegment[i];
	 		       _delay_ms(10);
	 		     }
	 		 }


	}


 }
