
/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

/* HAL */
#include "IR_interface.h"


#define  ZER0_SG       0b00111111
#define  ONE_SG        0b00000110
#define  TWO_SG        0b01011011
#define  THREE_SG      0b01001111
#define  FOUR_SG       0b01100110
#define  FIVE_SG       0b01101101
#define  SIX_SG        0b01111101
#define  SEVEN_SG      0b00000111
#define  EIGHT_SG      0b01111111
#define  NINE_SG       0b01101111


extern  volatile u8 Data;

void voidPlay(void)
{
	switch (Data)
	{
		case POWER_BUTTON: MGPIO_voidSetPinValue(GPIO_u8_PORTA,8,GPIO_u8_HIGH);                         break;
		case MODE_BUTTON: MGPIO_voidSetPinValue(GPIO_u8_PORTA,8,GPIO_u8_LOW);                           break;
		case MUTE_BUTTON: MGPIO_voidSetPinValue(GPIO_u8_PORTA,9,GPIO_u8_HIGH);                          break;
		case PLAY_BUTTON: MGPIO_voidSetPinValue(GPIO_u8_PORTA,9,GPIO_u8_LOW);                           break;
		case LEFT_BUTTON: MGPIO_voidSetPinValue(GPIO_u8_PORTA,10,GPIO_u8_HIGH);                         break;
		case RIGHT_BUTTON: MGPIO_voidSetPinValue(GPIO_u8_PORTA,10,GPIO_u8_LOW);                         break;
		case RPT_BUTTON: MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,0x00);          break;
		case ZER0_BUTTON: MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,ZER0_SG);      break;
		case ONE_BUTTON: MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,ONE_SG);        break;
		case TWO_BUTTON: MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,TWO_SG);        break;
		case THREE_BUTTON: MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,THREE_SG);    break;
		case FOUR_BUTTON:  MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,FOUR_SG);     break;
		case FIVE_BUTTON: MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,FIVE_SG);      break;
		case SIX_BUTTON: MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,SIX_SG);        break;
		case SEVEN_BUTTON: MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,SEVEN_SG);    break;
		case EIGHT_BUTTON: MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,EIGHT_SG);    break;
		case NINE_BUTTON: MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,NINE_SG);      break;
	}
}


void main(void)
{
	/* RCC Initialize */
	MRCC_voidInit();
	MRCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOAEN); /* GPIOA Enable Clock */
	MRCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOBEN); /* GPIOB Enable Clock */
	MRCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOCEN); /* GPIOC Enable Clock */
	
	/* IO Pins Initialization */
	MGPIO_voidSetPinDirection(GPIO_u8_PORTA,0,GPIO_INPUT_FLOATING); /* A0 Input Floating        */
	MGPIO_voidSetPinDirection(GPIO_u8_PORTA,8,GPIO_OUTPUT_2MHZ_PUSH_PULL); /* A1 Output PP "RED"       */
	MGPIO_voidSetPinDirection(GPIO_u8_PORTA,9,GPIO_OUTPUT_2MHZ_PUSH_PULL); /* A1 Output PP "GREEN"     */
	MGPIO_voidSetPinDirection(GPIO_u8_PORTA,10,GPIO_OUTPUT_2MHZ_PUSH_PULL); /* A1 Output PP "BLUE"      */
	MGPIO_voidSetPortDirection(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,GPIO_OUTPUT_2MHZ_PUSH_PULL);


	MIR_voidInit(voidPlay);


	while(1)
	{

	}

}
