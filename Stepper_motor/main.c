#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/delay.h>
#define F_CPU 8000000

#include "DIO_interface.h"
#include "STP_interface.h"



int main (void)
{
	DIO_u8Init();

	Stepper_u8Rotation(300,Clockwise);



	return 0;
}

