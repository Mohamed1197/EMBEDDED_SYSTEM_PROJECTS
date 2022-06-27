/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :       27/06/2022         ********************/
/**************** SWC     :      SSEG_TEST           ********************/
/**************** Version :          1.0             ********************/
/************************************************************************/

/*************************************************************************/
/*                        Include LIB Layer                              */
/*************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*#######################################################################*/

/*************************************************************************/
/*                        Include MCAL Layer                             */
/*************************************************************************/
#include "RCC_interface.h"
#include "GPIO_interface.h"
/*#######################################################################*/

/*************************************************************************/
/*                        Include HAL Layer                              */
/*************************************************************************/
#include "SSEG_interface.h"
/*#######################################################################*/

int main(void)
{
	/* Initialize System Clock */
	MRCC_voidInitSysClock();

	/* Enable Port A Clock */
	MRCC_voidEnableClock(RCC_APB2 , RCC_APB2_GPIOAEN);

	/* Configure PORT A  PINS 0 ~ 7 OUTPUT */
	MGPIO_voidSetPortDirection(GPIO_u8_PORTA,GPIO_u8_LOW_PINS,GPIO_OUTPUT_10MHZ_PUSH_PULL);


	while(1)
	{

		for(u8 x=0 ; x<=9 ; x++)
		{
			/* Clearing the Seven Segment Display */
			HSSEG_voidClearSSEG();
			/* Displaying Numbers From 0 to 9 on Seven Seg */
			HSSEG_voidSetSSEG(x);
			/* Making Delay With For LOOP */
			for(u16 i=0 ; i<1000 ; i++)
			{
				for(u16 j=0 ; j<1000 ; j++)
				{
					asm("NOP");
				}
				if(x==5)
				{
					HSSEG_voidDotSSEG();
				}
			}
		}
	}

	return 0;
}
