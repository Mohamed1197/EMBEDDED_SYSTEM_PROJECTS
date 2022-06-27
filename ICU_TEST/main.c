
/* Lib Layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL Layer */
#include "DIO_interface.h"
#include "TMR_interface.h"
#include "GI_interface.h"

/* HAL Layer */
#include "LCD_interface.h"
#include "SWICU_interface.h"


int main(void)
{
	u32 Local_u32TotalPeriod;
	u8 Local_u8DutyCycle;

	/* DIO Init */
	DIO_u8Init();

	/* Global Interrupt Enable */
	GI_voidEnable();

	/* Turn on Timer1 */
	TMR_voidTimer1Init();

//	/* SWICU Enable */
//	SWICU_voidEnable();

	/* HW ICU Enable */
	TMR_voidHWICUEnable();

	/* Set Duty Cycle Of The PWM */
	TMR_voidTimer0SetCompareMatchValue(127);
	/* Enable Timer0 To Generate PWM */
	TMR_voidTimer0Init();

	/* Enable LCD */
	LCD_voidInit();

	while(1)
	{
//		SWICU_u8GetTotalPeriod(&Local_u32TotalPeriod);
//		SWICU_u8GetDutyCycle(&Local_u8DutyCycle);
		TMR_u8GetPWMTotalPeriod(&Local_u32TotalPeriod);
		TMR_u8GetPWMDutyCycle(&Local_u8DutyCycle);
		LCD_u8_GoTo_XY(0,0);
		LCD_voidWriteString("Duty = ");
		LCD_voidWriteNumber(Local_u8DutyCycle);
		LCD_voidWriteString(" %");
		LCD_u8_GoTo_XY(1,0);
		LCD_voidWriteString("T.Prd = ");
		LCD_voidWriteNumber(Local_u32TotalPeriod);
		LCD_voidWriteString(" usec");
	}

	return 0;
}

