#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"

int main(void)
{
	s8 i ;
	/* RCC initialization */
	MRCC_voidInit();
	/* GPIOA Enable */
	MRCC_voidEnableClock(RCC_APB2 , RCC_APB2_GPIOAEN);

	/* DS */
	MGPIO_voidSetPinDirection(GPIO_u8_PORTA , GPIO_u8_PIN0 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
	/* SHIFT */
	MGPIO_voidSetPinDirection(GPIO_u8_PORTA , GPIO_u8_PIN1 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
	/* STORAGE */
	MGPIO_voidSetPinDirection(GPIO_u8_PORTA , GPIO_u8_PIN2 , GPIO_OUTPUT_2MHZ_PUSH_PULL);

	MSTK_voidInit();

	while(1)
	{
		for(u8 j = 0 ; j < 4 ; j++ )
		{
		for (i = 0 ; i < 8 ; i++)
		{
			HSTP_voidSendSynch( 1 << i);
			Delay_ms(50);

		}
		}
		for(u8 k = 0 ; k < 4 ; k++ )
		{
		for ( i = 7 ; i >= 0 ; i--)
		{
			HSTP_voidSendSynch( 1 << i);
			Delay_ms(50);

		}
		}

	}
	return 0 ;

}
