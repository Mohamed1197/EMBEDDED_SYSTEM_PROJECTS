/*
 * main.c
 *
 *  Created on: 19 Jun 2022
 *      Author: mhafi
 */

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* Mcal Layer */

#include "RCC_interface.h"

#define PORTA_CRL   *((u32*)0x40010800)
#define PORTA_ODR   *((u32*)0x4001080C)

int main()
{
	/* Initialize clock system */
	RCC_voidInitSysClock();

	/* Enable peripheral 2 on APB2 Bus (GPIOA)  */
	RCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOAEN);

	/* Configure A0 as o/p push pull */
	PORTA_CRL = 0x00000002;

	/* Set A0 as o/p HIGH */
	PORTA_ODR = 0x00000001;


	while(1)
	{

	}

}
