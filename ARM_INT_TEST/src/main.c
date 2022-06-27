/* LIB */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* MCAL */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "Delay.h"

void TOG_LED(void)
{
	/*         LED ON                 */
	MGPIO_voidSetPinValue(GPIO_u8_PORTA, GPIO_u8_PIN8, GPIO_u8_HIGH);
	/* 1 sec delay */
	Delay(4000);
	/*         LED OFF                 */
	MGPIO_voidSetPinValue(GPIO_u8_PORTA, GPIO_u8_PIN8, GPIO_u8_LOW);
	/* 1 sec delay */
	Delay(4000);
}

int main(void)
{
	/*  RCC Initialization  */
	MRCC_voidInit();

	/* RCC GPIOA Enable  */
	MRCC_voidEnableClock(RCC_APB2 , RCC_APB2_GPIOAEN);
	MRCC_voidEnableClock(RCC_APB2 , RCC_APB2_GPIOBEN);
//	/* RCC AFIO Enable  */
//	MRCC_voidEnableClock(RCC_APB2 , RCC_APB2_AFIOEN);

//	/* AFIO External Interrupt Select */
//	MAFIO_voidSelectInterruptSource(AFIO_PORTB,EXTI_u8_LINE8);

	/* GPIO Mode      A0 = input pull-up    */
	MGPIO_voidSetPinDirection(GPIO_u8_PORTA, GPIO_u8_PIN0, GPIO_INPUT_PULL_UP_DOWN);
//	MGPIO_voidSetPinValue(GPIO_u8_PORTA, GPIO_u8_PIN0, GPIO_u8_HIGH);
	/* GPIO Mode      A2 = output Push-Pull 2MHz    */
	MGPIO_voidSetPinDirection(GPIO_u8_PORTA, GPIO_u8_PIN8, GPIO_OUTPUT_2MHZ_PUSH_PULL);

	MEXTI_voidSetSignalLatch(EXTI_u8_LINE0 , EXTI_RISING);

	/* EXTI Call Back function */
	MEXTI_voidSetCallBack(TOG_LED , EXTI_u8_LINE0 );

	/*  NVIC Initialization  */
	MNVIC_voidInit();
	/*  EXTI Initialization  */
	MEXTI_voidInit();

//	/* Set Priority   Group  0 and Sub 3 */
//	MNVIC_u8SetInterrruptPriority(NVIC_VEC_T_EXTI0 ,0,3);
	/* Enable EXTI Line 0 */
	MEXTI_voidEnable(EXTI_u8_LINE0);
	/* NVIC Enable */
	MNVIC_u8EnableInterrupt(NVIC_VEC_T_EXTI0);


	while(1);
	return 0;
}



