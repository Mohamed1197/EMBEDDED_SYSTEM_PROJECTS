#include<avr/io.h>

int main(void)
{
	// Configure PA0 Output
	// Configure PB7 Input
	DDRA = 0x01;
	DDRB = 0x00;
	// Activate pull up resistor on PB7
	PORTB =0b10000000;
	while(1)
	{
	   // If Switchg is Pressed
       if((PINB & 0b10000000) == 0)
        {
	      // Turn On LED
	      PORTA =0x01;
        }
	    // If Switchg is not Pressed
        else if((PINB & 0b10000000) != 0)
        {
	      // Turn Off LED
          PORTA = 0x00;
         }
	}

	return 0;
}
