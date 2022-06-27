/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    : 25/9/2020           ********************/
/**************** SWC     :     TMR             ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TMR_interface.h"
#include "TMR_private.h"
#include "TMR_config.h"




static void (*TMR_pfTimer0OVF)(void) = NULL;
static void (*TMR_pfTimer0CTC)(void) = NULL;

void TMR_voidTimer0Init(void)
{

 /* Timer Mode IF Selection */
#if (TIMER_MODE == NORMAL_MODE)
	{
      CLR_BIT(TMR_u8_TCCR0_REG,6);
      CLR_BIT(TMR_u8_TCCR0_REG,3);
      TMR_u8_TCNT0_REG = PRELOAD_VALUE ;
      #if (TIMER_PIE == ENABLE_TIMER0_PIE)
	    {
		  SET_BIT(TMR_u8_TIMSK_REG,0);
	    }
      #endif
	}
#elif (TIMER_MODE == CTC_MODE)
	{
	  CLR_BIT(TMR_u8_TCCR0_REG,6);
	  SET_BIT(TMR_u8_TCCR0_REG,3);
	  TMR_u8_OCR0_REG = COMPARE_MATCH_VALUE;
      #if (TIMER_PIE == ENABLE_TIMER0_PIE)
	   {
		  SET_BIT(TMR_u8_TIMSK_REG,1);
	   }
      #endif
	}
#elif (TIMER_MODE == FAST_PWM)
	{
		SET_BIT(TMR_u8_TCCR0_REG,6);
		SET_BIT(TMR_u8_TCCR0_REG,3);
	}
#elif (TIMER_MODE == PHASE_CORRECT_PWM)
	{
	   SET_BIT(TMR_u8_TCCR0_REG,6);
	   CLR_BIT(TMR_u8_TCCR0_REG,3);
	}

#endif

	 /* Compare Output Mode IF Selection */
#if (COMPARE_OUTPUT_MODE == OC0_DISCONNECTED)
{
	CLR_BIT(TMR_u8_TCCR0_REG,5);
 	CLR_BIT(TMR_u8_TCCR0_REG,4);
}
#elif (COMPARE_OUTPUT_MODE == TOGGLE_OC0_ON_COMPARE)
{
	CLR_BIT(TMR_u8_TCCR0_REG,5);
	SET_BIT(TMR_u8_TCCR0_REG,4);
}
#elif ((COMPARE_OUTPUT_MODE == CLEAR_OC0_ON_COMPARE) || (COMPARE_OUTPUT_MODE == NON_INVERTING_PWM))
{
	SET_BIT(TMR_u8_TCCR0_REG,5);
	CLR_BIT(TMR_u8_TCCR0_REG,4);
}
#elif ((COMPARE_OUTPUT_MODE == SET_OC0_ON_COMPARE) || (COMPARE_OUTPUT_MODE == INVERTING_PWM))
{
	SET_BIT(TMR_u8_TCCR0_REG,5);
	SET_BIT(TMR_u8_TCCR0_REG,4);
}
#endif

/* Prescaler Value IF Selection */
#if (PRESCALER_VALUE == TIMER_OFF)
	{
		 CLR_BIT(TMR_u8_TCCR0_REG,2);
		 CLR_BIT(TMR_u8_TCCR0_REG,1);
		 CLR_BIT(TMR_u8_TCCR0_REG,0);
	}
#elif (PRESCALER_VALUE == NO_PRESCALING)
	{
		 CLR_BIT(TMR_u8_TCCR0_REG,2);
		 CLR_BIT(TMR_u8_TCCR0_REG,1);
		 SET_BIT(TMR_u8_TCCR0_REG,0);
	}
#elif (PRESCALER_VALUE == CLOCK_8)
	{
		 CLR_BIT(TMR_u8_TCCR0_REG,2);
		 SET_BIT(TMR_u8_TCCR0_REG,1);
		 CLR_BIT(TMR_u8_TCCR0_REG,0);
	}
#elif (PRESCALER_VALUE == CLOCK_64)
	{
		 CLR_BIT(TMR_u8_TCCR0_REG,2);
		 SET_BIT(TMR_u8_TCCR0_REG,1);
		 SET_BIT(TMR_u8_TCCR0_REG,0);
	}
#elif (PRESCALER_VALUE == CLOCK_256)
	{
		 SET_BIT(TMR_u8_TCCR0_REG,2);
		 CLR_BIT(TMR_u8_TCCR0_REG,1);
		 CLR_BIT(TMR_u8_TCCR0_REG,0);
	}
#elif (PRESCALER_VALUE == CLOCK_1024)
	{
		 SET_BIT(TMR_u8_TCCR0_REG,2);
		 CLR_BIT(TMR_u8_TCCR0_REG,1);
		 SET_BIT(TMR_u8_TCCR0_REG,0);
	}
#elif (PRESCALER_VALUE == CLOCK_FALLING_EDGE)
	{
		 SET_BIT(TMR_u8_TCCR0_REG,2);
		 SET_BIT(TMR_u8_TCCR0_REG,1);
		 CLR_BIT(TMR_u8_TCCR0_REG,0);
	}
#elif (PRESCALER_VALUE == CLOCK_RISING_EDGE)
	{
		 SET_BIT(TMR_u8_TCCR0_REG,2);
		 SET_BIT(TMR_u8_TCCR0_REG,1);
		 SET_BIT(TMR_u8_TCCR0_REG,0);
	}
#endif

 // /* Set Preload Value */
 // TMR_u8_TCNT0_REG = 192;
 //
 // /* Enable PIE of OVF */
 // SET_BIT(TMR_u8_TIMSK_REG,0);
 //
 // /* Prescaler => 8 */
 // CLR_BIT(TMR_u8_TCCR0_REG,2);
 // SET_BIT(TMR_u8_TCCR0_REG,1);
 // CLR_BIT(TMR_u8_TCCR0_REG,0);

	
	
//	/* Select Moe Of Timer => CTC Mode */
//	CLR_BIT(TMR_u8_TCCR0_REG,6);
//	SET_BIT(TMR_u8_TCCR0_REG,3);
//
//	/* Set Compare Match Register */
//	 TMR_u8_OCR0_REG = COMPARE_MATCH_VALUE;
//
//	  /* Enable PIE of CTC */
//	  SET_BIT(TMR_u8_TIMSK_REG,1);
//
//	  /* Prescaler => 8 */
//	  CLR_BIT(TMR_u8_TCCR0_REG,2);
//	  SET_BIT(TMR_u8_TCCR0_REG,1);
//	  CLR_BIT(TMR_u8_TCCR0_REG,0);


	
//		/* Select Mode Of Timer => Fast PWM */
//		SET_BIT(TMR_u8_TCCR0_REG,6);
//		SET_BIT(TMR_u8_TCCR0_REG,3);
//	   /* Select Action on OC0 Pin => Non Inverting */
//   	SET_BIT(TMR_u8_TCCR0_REG,5);
//	    CLR_BIT(TMR_u8_TCCR0_REG,4);
//
//	    /* Prescaler => 8 */
//	    CLR_BIT(TMR_u8_TCCR0_REG,2);
//      SET_BIT(TMR_u8_TCCR0_REG,1);
//      CLR_BIT(TMR_u8_TCCR0_REG,0);

//
//		/* Select Mode Of Timer => Phase Correct PWM */
//		SET_BIT(TMR_u8_TCCR0_REG,6);
//		CLR_BIT(TMR_u8_TCCR0_REG,3);
//
//		/* Select Action on OC0 Pin => Non Inverting */
//		SET_BIT(TMR_u8_TCCR0_REG,5);
//		CLR_BIT(TMR_u8_TCCR0_REG,4);
//
//		/* Prescaler => 8 */
//   	    CLR_BIT(TMR_u8_TCCR0_REG,2);
//	    SET_BIT(TMR_u8_TCCR0_REG,1);
//	    CLR_BIT(TMR_u8_TCCR0_REG,0);

}

void TMR_voidTimer1Init(void)
{
	/* Timer1 Select Mode 14 => ICR1 top Value */
	SET_BIT(TMR_u8_TCCR1A_REG,1);
	CLR_BIT(TMR_u8_TCCR1A_REG,0);
	SET_BIT(TMR_u8_TCCR1B_REG,4);
	SET_BIT(TMR_u8_TCCR1B_REG,3);

	/* Channel A => NON Inverting */
	SET_BIT(TMR_u8_TCCR1A_REG,7);
	CLR_BIT(TMR_u8_TCCR1A_REG,6);

	/* Set Max Value */
	TMR_u16_ICR1_REG = 19999;

	/* Set Prescaler => 8 */
	CLR_BIT(TMR_u8_TCCR1B_REG,2);
	SET_BIT(TMR_u8_TCCR1B_REG,1);
	CLR_BIT(TMR_u8_TCCR1B_REG,0);

}

void TMR_voidTimer1SetCompareMatchValueChannelA(u16 Copy_u16CompareMatchValue)
{
	TMR_u16_OCR1A_REG = Copy_u16CompareMatchValue;
}

void TMR_voidTimer0SetCompareMatchValue(u8 Copy_u8OCRValue)
{
	TMR_u8_OCR0_REG = Copy_u8OCRValue;
}

u8  TMR_u8Timer0OVFSetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8_ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TMR_pfTimer0OVF = Copy_pf;
	}
	else
	{
		Local_u8_ErrorState =STD_TYPES_NOK;
	}
	return Local_u8_ErrorState;
}

u8  TMR_u8Timer0CTCSetCallBack(void(*Copy_pf)(void))
{
	u8 Local_u8_ErrorState = STD_TYPES_OK;
	if(Copy_pf != NULL)
	{
		TMR_pfTimer0CTC = Copy_pf;
	}
	else
	{
		Local_u8_ErrorState =STD_TYPES_NOK;
	}
	return Local_u8_ErrorState;
}

/* Prototype of ISR Timer0 OVF */
void __vector_11(void)     __attribute__((signal));
void __vector_11(void)
{
	static u16 Local_u16Counter = 0 ;
	Local_u16Counter++;
	if(Local_u16Counter == 3907)
	{
		/* Set Preload Value */
		TMR_u8_TCNT0_REG = 192;
		/* Reset Counter */
		Local_u16Counter = 0;
		/* Call CallBack Function */
		if(TMR_pfTimer0OVF != NULL)
		{
			TMR_pfTimer0OVF();
		}
	}
}
/* Prototype of ISR Timer0 Compare Match */
void __vector_10(void)     __attribute__((signal));
void __vector_10(void)
{
	static u16 Local_u16Counter = 0 ;
	Local_u16Counter++;
	if(Local_u16Counter == 10000)
	{
		/* Reset Counter */
		Local_u16Counter = 0;
		/* Call CallBack Function */
		if(TMR_pfTimer0CTC != NULL)
		{
			TMR_pfTimer0CTC();
		}
	}
}
