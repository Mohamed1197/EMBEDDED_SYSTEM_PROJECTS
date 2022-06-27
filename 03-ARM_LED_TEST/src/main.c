/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :       27/06/2022         ********************/
/**************** SWC     :       LED_TEST           ********************/
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
#include "LED_interface.h"
/*#######################################################################*/


int main (void)
{
	/* Initialize System Clock */
	MRCC_voidInitSysClock();
	/* Enable GPIOA */
	MRCC_voidEnableClock(RCC_APB2 , RCC_APB2_GPIOAEN);
	/* Set PortA  Pins 0 ~ 7  OUTPUT */
	MGPIO_voidSetPortDirection(GPIO_u8_PORTA , GPIO_u8_LOW_PINS ,GPIO_OUTPUT_10MHZ_PUSH_PULL);
	MGPIO_voidSetPortDirection(GPIO_u8_PORTA , GPIO_u8_HIGH_PINS ,GPIO_OUTPUT_10MHZ_PUSH_PULL);

	while(1)
	{
		for(u16 x=0 ; x<=10 ; x++ )
		{
			HLED_voidToggleLED(GPIO_u8_PORTA,x);
			for(u16 i=0 ; i<100 ; i++)
			{
				for(u16 j=0 ; j<1000 ; j++)
				{
					asm("NOP");
				}
			}
			HLED_voidToggleLED(GPIO_u8_PORTA,x);
		}
	}

	return 0;
}
