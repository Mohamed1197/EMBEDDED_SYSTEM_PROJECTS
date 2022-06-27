#include<avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>
int main(void)
{
	//configure PIN0 in PORTA -> output
	DDRA =0b00000001;
	while(1)
	{
	//Turn on LED by writing one to PORTA register
	PORTA=0x01;
	_delay_ms(200);
	//Turn off LED by writing zero to PORTA register
	PORTA=0x00;
	_delay_ms(200);
	}
	return 0;
}
