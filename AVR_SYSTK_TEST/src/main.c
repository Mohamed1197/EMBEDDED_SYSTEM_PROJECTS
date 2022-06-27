/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL  */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"



int main(void)
{
	/* Enable RCC For GPIO A */
	MRCC_voidEnableClock(RCC_APB2 , RCC_APB2_GPIOAEN);

	MGPIO_voidSetPortDirection(GPIO_u8_PORTA,GPIO_u8_LOW_PINS,GPIO_OUTPUT_2MHZ_PUSH_PULL);

	/* Inistialize SYSTK */
	MSTK_voidInit();




	while(1)
	{
		/* Flashing every 500 ms */
		for(u8 i =0 ; i<3 ; i++)
		{
		MGPIO_voidSetPortValue(GPIO_u8_PORTA,GPIO_u8_LOW_PINS,GPIO_u8_HIGH);
		MSTK_voidSetBusyWait(5000000);
		MGPIO_voidSetPortValue(GPIO_u8_PORTA,GPIO_u8_LOW_PINS,GPIO_u8_LOW);
		MSTK_voidSetBusyWait(5000000);
		}
		/* Shifting Left every 250 ms */
		for(u8 i =0 ; i<3 ; i++)
		{
		     for(u8 j = GPIO_u8_PIN0 ; j < GPIO_u8_PIN8 ; j++)
		     {
		     MGPIO_voidSetPinValue(GPIO_u8_PORTA,j,GPIO_u8_HIGH);
		     MSTK_voidSetBusyWait(2500000);
		     MGPIO_voidSetPinValue(GPIO_u8_PORTA,j,GPIO_u8_LOW);
		     }
		}
		/* Shifting Right every 250 ms */
		for(u8 i =0 ; i<3 ; i++)
		{
		     for(s8 j = GPIO_u8_PIN7 ; j >= GPIO_u8_PIN0 ; j--)
		     {
		     MGPIO_voidSetPinValue(GPIO_u8_PORTA,j,GPIO_u8_HIGH);
		     MSTK_voidSetBusyWait(2500000);
		     MGPIO_voidSetPinValue(GPIO_u8_PORTA,j,GPIO_u8_LOW);
		     }
		}
		/* 2-LEDs Converging every 300 ms */
		for(u8 i =0 ; i<3 ; i++)
		{
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN4,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN3,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN7,GPIO_u8_HIGH);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN0,GPIO_u8_HIGH);
			MSTK_voidSetBusyWait(3000000);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN7,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN0,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN6,GPIO_u8_HIGH);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN1,GPIO_u8_HIGH);
			MSTK_voidSetBusyWait(3000000);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN6,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN1,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN5,GPIO_u8_HIGH);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN2,GPIO_u8_HIGH);
			MSTK_voidSetBusyWait(3000000);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN5,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN2,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN4,GPIO_u8_HIGH);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN3,GPIO_u8_HIGH);
			MSTK_voidSetBusyWait(3000000);
		}
		/* 2-LEDs Diverging every 300 ms */
		for(u8 i =0 ; i<3 ; i++)
		{
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN4,GPIO_u8_HIGH);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN3,GPIO_u8_HIGH);
			MSTK_voidSetBusyWait(3000000);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN4,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN3,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN5,GPIO_u8_HIGH);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN2,GPIO_u8_HIGH);
			MSTK_voidSetBusyWait(3000000);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN5,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN2,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN6,GPIO_u8_HIGH);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN1,GPIO_u8_HIGH);
			MSTK_voidSetBusyWait(3000000);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN6,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN1,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN7,GPIO_u8_HIGH);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN0,GPIO_u8_HIGH);
			MSTK_voidSetBusyWait(3000000);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN7,GPIO_u8_LOW);
			MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN0,GPIO_u8_LOW);
		}
		/* Ping Pong effect every 250 ms */
		for(u8 i =0 ; i<10 ; i++)
		{
		     for(u8 j = GPIO_u8_PIN0 ; j < GPIO_u8_PIN8 ; j++)
		     {
		     MGPIO_voidSetPinValue(GPIO_u8_PORTA,j,GPIO_u8_HIGH);
		     MSTK_voidSetBusyWait(310000);
		     MGPIO_voidSetPinValue(GPIO_u8_PORTA,j,GPIO_u8_LOW);
		     }
		     for(s8 j = GPIO_u8_PIN7 ; j >= GPIO_u8_PIN0 ; j--)
		     {
		     MGPIO_voidSetPinValue(GPIO_u8_PORTA,j,GPIO_u8_HIGH);
		     MSTK_voidSetBusyWait(310000);
		     MGPIO_voidSetPinValue(GPIO_u8_PORTA,j,GPIO_u8_LOW);
		     }
		}
		/* Incrementing (Snake effect) every 300 ms */
		for(u8 i = 0 ; i < 3 ; i++)
		{
			for(u8 j = GPIO_u8_PIN0 ; j < GPIO_u8_PIN8 ; j++)
			{
			  MGPIO_voidSetPinValue(GPIO_u8_PORTA,j,GPIO_u8_HIGH);
			  if(j > GPIO_u8_PIN2)
			  {
					for(u8 k = j-3 ; k < j-2 ; k++)
					{
					  MGPIO_voidSetPinValue(GPIO_u8_PORTA,k,GPIO_u8_LOW);
			        }
			  }
			  if(j == GPIO_u8_PIN7 )
			  {
					for(u8 k = j-3 ; k <= j ; k++)
					{
					  MGPIO_voidSetPinValue(GPIO_u8_PORTA,k,GPIO_u8_LOW);
					  MSTK_voidSetBusyWait(3000000);
			        }
			  }
			  MSTK_voidSetBusyWait(3000000);
			}
		}
		    /* 2-LEDs Converging/Diverging every 300 ms */
		for(u8 i = 0 ; i < 3 ; i++)
		{
	     	/* 2-LEDs Diverging every 300 ms */
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN4,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN3,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN7,GPIO_u8_HIGH);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN0,GPIO_u8_HIGH);
					MSTK_voidSetBusyWait(3000000);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN7,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN0,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN6,GPIO_u8_HIGH);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN1,GPIO_u8_HIGH);
					MSTK_voidSetBusyWait(3000000);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN6,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN1,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN5,GPIO_u8_HIGH);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN2,GPIO_u8_HIGH);
					MSTK_voidSetBusyWait(3000000);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN5,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN2,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN4,GPIO_u8_HIGH);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN3,GPIO_u8_HIGH);
					MSTK_voidSetBusyWait(3000000);

			/* 2-LEDs Diverging every 300 ms */
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN4,GPIO_u8_HIGH);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN3,GPIO_u8_HIGH);
					MSTK_voidSetBusyWait(3000000);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN4,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN3,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN5,GPIO_u8_HIGH);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN2,GPIO_u8_HIGH);
					MSTK_voidSetBusyWait(3000000);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN5,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN2,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN6,GPIO_u8_HIGH);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN1,GPIO_u8_HIGH);
					MSTK_voidSetBusyWait(3000000);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN6,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN1,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN7,GPIO_u8_HIGH);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN0,GPIO_u8_HIGH);
					MSTK_voidSetBusyWait(3000000);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN7,GPIO_u8_LOW);
					MGPIO_voidSetPinValue(GPIO_u8_PORTA,GPIO_u8_PIN0,GPIO_u8_LOW);
		}

	}
	return 0;
}
