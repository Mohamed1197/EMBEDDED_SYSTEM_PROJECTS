#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include "DIO_interface.h"
#include "TMR_interface.h"
#include "GI_interface.h"
#include "ADC_interface.h"




void App_voidTogLed(void);

int main(void)
{
	u8 Local_u8OCRValue =0;
	u16 Local_u16DigitalValue , Local_u16OCRValue;
	DIO_u8Init();
//	ADC_voidInit();
//	/* Enable GI */
//	GI_voidEnable();
//	/* Set Call back of Timer */
//	TMR_u8Timer0CTCSetCallBack(&App_voidTogLed);
	/* Start Timer */


	TMR_voidTimer1Init();

	//TMR_voidTimer1SetCompareMatchValueChannelA(580);
//	_delay_ms(1000);
	//TMR_voidTimer1SetCompareMatchValueChannelA(2580);
//	_delay_ms(1000);

	while(1)
	{
		/* Get Digital Value ADC0 */
//		ADC_u8GetDigitalValueSunchNonBlocking(ADC_u8_CHANNEL_0,&Local_u16DigitalValue);
//		Local_u16OCRValue =((2000UL* Local_u16DigitalValue)/1023)+580;
		TMR_voidTimer1SetCompareMatchValueChannelA(2500);
		_delay_ms(1000);
		TMR_voidTimer1SetCompareMatchValueChannelA(500);
		_delay_ms(1000);

	}
	return 0 ;

	}
void App_voidTogLed(void)
{
	static u8 Local_u8Flag = 0;
	if(Local_u8Flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		Local_u8Flag =1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		Local_u8Flag =0;
	}
}
