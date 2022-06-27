#include<avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>

int main(void)
{
	//set PORTA as Output
	DDRA = 0xFF;
	while(1)
	{
   //Flashing every 500 ms
	for(int i=0 ; i<10 ;i++ )
	{
	PORTA = 0b11111111;
	_delay_ms(500);

	PORTA = 0b00000000;
    _delay_ms(500);
	}
	_delay_ms(1000);

    //Shifting Left every 250 ms

	PORTA = 0b00000001;
	_delay_ms(250);
	for(int i=0 ; i<8 ;i++ )
	{
		PORTA = PORTA << 1 ;
		_delay_ms(250);

	}
	_delay_ms(1000);

    //Shifting Right every 250 ms
	PORTA = 0b10000000;
    _delay_ms(250);
	for(int i=0 ; i<8 ;i++ )
	{
	    PORTA = PORTA >> 1 ;
	    _delay_ms(250);

	}
	_delay_ms(1000);

	//2-LEDs Converging every 300 ms

	PORTA = 0b10000001;
	_delay_ms(300);
	PORTA = 0b01000010;
	_delay_ms(300);
	PORTA = 0b00100100;
	_delay_ms(300);
	PORTA = 0b00011000;
	_delay_ms(300);
    _delay_ms(1000);

	//2-LEDs Diverging every 300 ms
	PORTA = 0b00011000;
	_delay_ms(300);
	PORTA = 0b00100100;
	_delay_ms(300);
	PORTA = 0b01000010;
	_delay_ms(300);
	PORTA = 0b10000001;
	_delay_ms(300);
	PORTA = 0b00000000;
	_delay_ms(1000);

	//Ping Pong effect every 250 ms

	for(int x=0 ; x<20 ; x++)
	{
	PORTA = 0b00000001;
	_delay_ms(31);
	for(int i=0 ; i<8 ;i++ )
	{
		PORTA = PORTA << 1 ;
		_delay_ms(31);

	}
	PORTA = 0b10000000;
	    _delay_ms(31);
     for(int i=0 ; i<8 ;i++ )
	  {
	    PORTA = PORTA >> 1 ;
	    _delay_ms(31);
      }
	}
      _delay_ms(1000);


	 //Incrementing (Snake effect) every 300 ms
     PORTA = 0b00000001;
     	_delay_ms(300);
   	for(int i=0 ; i<8 ;i++ )
     	 {
     		PORTA = (PORTA << 1) +1 ;
     		_delay_ms(300);
         }
    PORTA = 0b00000000;
   	_delay_ms(1000);

   //2-LEDs Converging/Diverging every 300 ms
   //Converging
	PORTA = 0b10000001;
	_delay_ms(300);
	PORTA = 0b01000010;
	_delay_ms(300);
	PORTA = 0b00100100;
	_delay_ms(300);
	PORTA = 0b00011000;
	_delay_ms(300);
   //Diverging
	PORTA = 0b00011000;
	_delay_ms(300);
	PORTA = 0b00100100;
	_delay_ms(300);
	PORTA = 0b01000010;
	_delay_ms(300);
	PORTA = 0b10000001;
	_delay_ms(300);
	PORTA = 0b00000000;
	}

}
