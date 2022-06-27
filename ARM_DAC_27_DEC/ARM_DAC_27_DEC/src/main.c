/*
 * main.c
 *
 *  Created on: Dec 27, 2020
 *      Author: Ahmed Ehab
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_macros.h"

#include "RCC_interface.h"
#include "RCC_macros.h"

#include "SYSTICK_interface.h"

#include "song.h"



void DAC_VidSetAudio(void)
{
	static u16 counter=0;
	MGPIO_VidSetGpioValue(GPIO_U8_A,hussein_raw[counter]);
	counter++;
	if(counter == 38633)
	{
		counter=0;
	}
}

int main (void)
{
	/******RCC INIT********/
	MRCC_VidInit();
	/******ENABLE CLOCK FOR GPIOA*****/
	MRCC_VidEnableClock(RCC_APB2,GPIOA_RCC);
	/********SET DIRCTION FOR GPIOA*****/
	MGPIO_VidSetGpioDirection(GPIO_U8_A,ALL_GPIO_OUTPUT_2MHZ_PP,GPIO_U8_FULLREG);
	/*********SYSTICK INIT********/
	MSysTick_VidInit();
	/*********SYSTICK INTERRUPT PERIODIC************/
	MSysTick_VidSetIntervalPeriodic(125,DAC_VidSetAudio);

	while(1);
	return 0;
}
