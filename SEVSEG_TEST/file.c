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
	unsigned char SevenSegment[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
	//configure PORTD output
	DDRD = 0xFF;
	while(1)
	{
		for(int i=0; i<10; i++)
			{
			 // 7 segment is common anode
				PORTD = ~SevenSegment[i];
				_delay_ms(1000);
			}
	}
}

