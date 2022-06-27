#include  "STD_TYPES.h"
#include  "BIT_MATH.h"

#include  "GPIO_interface.h"
#include  "EXTI_interface.h"
#include  "NVIC_INT.h"

#include  "STK_interface.h"
#include  "RCC_interface.h"
#include  "IR_interface.h"

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


extern  volatile u8 FrameData;

u8 SG_DIS[10] ={ZER0_SG,ONE_SG,TWO_SG,THREE_SG,FOUR_SG,FIVE_SG,SIX_SG,SEVEN_SG,EIGHT_SG,NINE_SG};

void play(void)
{

	switch(FrameData)
	{
	case ZER0_BUTTON : MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,ZER0_SG);break;
	case ONE_BUTTON  : MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,ONE_SG);break;
	case TWO_BUTTON  : MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,TWO_SG);break;
	case THREE_BUTTON : MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,THREE_SG);break;
	case FOUR_BUTTON  : MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,FOUR_SG);break;
	case FIVE_BUTTON  : MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,FIVE_SG);break;
	case SIX_BUTTON : MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,SIX_SG);break;
	case SEVEN_BUTTON  : MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,SEVEN_SG);break;
	case EIGHT_BUTTON  : MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,EIGHT_SG);break;
	case NINE_BUTTON : MGPIO_voidSetPortValueRegister(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,NINE_SG);break;
	case POWER_BUTTON : MGPIO_voidSetPinValue(GPIO_u8_PORTA, GPIO_u8_PIN8 , GPIO_u8_HIGH);break;
	case MODE_BUTTON : MGPIO_voidSetPinValue(GPIO_u8_PORTA, GPIO_u8_PIN8 , GPIO_u8_LOW);break;
	}

}


int main(void)
{

	MRCC_voidInit();
	MRCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOAEN);
	MRCC_voidEnableClock(RCC_APB2,RCC_APB2_GPIOBEN);

    MGPIO_voidSetPinDirection(GPIO_u8_PORTA,GPIO_u8_PIN0,GPIO_INPUT_FLOATING);
    MGPIO_voidSetPortDirection(GPIO_u8_PORTB,GPIO_u8_HIGH_PINS,GPIO_OUTPUT_2MHZ_PUSH_PULL);


    IR_voidInit(&play);


    while(1)
    { }

	return 0;
}
