/**
 * @file         WTMR_PROGRAM.cpp
 *
 * \b Description :
 * This file includes Timer Driver implementation
 *
 * @author      Mohamed Osama
 * @date        20/6/2022
 * @version     V1.0
 * @copyright   IMT_SCHOOL 2022
 */

#include "../../00-LIB/BIT_MATH.h"
#include "../../00-LIB/STD_TYPES.h"
#include "../../04-MCAL/MTMR/MTMR_interface.h"
#include "Timer0_interface.h"


void MTMR_voidTimer0Init(void)
{
	Timer0 TIM0;
	TIM0.MTMR_voidTimer0Init();
}

u8 MTMR_u8Timer0GetCounterValue(u8* Copy_pu16CounterValue)
{
	Timer0 TIM0;
	u8 Local_u8ErrorState = TIM0.MTMR_u8Timer0GetCounterValue(Copy_pu16CounterValue);
	return Local_u8ErrorState;
}

u8 MTMR_u8Timer0GeneratePWM(u8 Copy_u8DutyCycle)
{
	Timer0 TIM0;
	u8 Local_u8ErrorState = TIM0.MTMR_u8Timer0GeneratePWM(Copy_u8DutyCycle);
	return Local_u8ErrorState;
}

u8 MTMR_u8Timer0OVFSetCallBack(void (*Copy_pf)(void))
{
	Timer0 TIM0;
	u8 Local_u8ErrorState = TIM0.MTMR_u8Timer0OVFSetCallBack(Copy_pf);
	return Local_u8ErrorState;
}

void MTMR_voidTimer2Init(void)
{
	Timer2 TIM2;
	TIM2.MTMR_voidTimer2Init();
}

u8 MTMR_u8Timer2GetCounterValue(u8* Copy_pu16CounterValue)
{
	Timer2 TIM2;
	u8 Local_u8ErrorState = TIM2.MTMR_u8Timer2GetCounterValue(Copy_pu16CounterValue);
	return Local_u8ErrorState;
}

u8 MTMR_u8Timer2GeneratePWM(u8 Copy_u8DutyCycle)
{
	Timer2 TIM2;
	u8 Local_u8ErrorState = TIM2.MTMR_u8Timer2GeneratePWM(Copy_u8DutyCycle);
	return Local_u8ErrorState;
}

u8 MTMR_u8Timer2OVFSetCallBack(void (*Copy_pf)(void))
{
	Timer2 TIM2;
	u8 Local_u8ErrorState = TIM2.MTMR_u8Timer2OVFSetCallBack(Copy_pf);
	return Local_u8ErrorState;
}

u8 MTMR_u8Timer0Disable(void)
{
	Timer0 TMR;
	u8 Local_u8ErrorState = TMR.MTMR_u8Timer0Disable();
	return Local_u8ErrorState ;
}

u8 MTMR_u8Timer0SetPreloadValue(u8 Copy_u8PreloadValue)
{
	Timer0 TMR;
	u8 Local_u8ErrorState = TMR.MTMR_u8Timer0SetPreloadValue(Copy_u8PreloadValue);
	return Local_u8ErrorState ;

}

u8 MTMR_u8Timer0SetCompareMatchValue(u8 Copy_u8CTCValue)
{
	Timer0 TMR;
	u8 Local_u8ErrorState = TMR.MTMR_u8Timer0SetCompareMatchValue(Copy_u8CTCValue);
	return Local_u8ErrorState ;
}

u8 MTMR_u8Timer0CTCSetCallBack(void (*Copy_pf)(void))
{
	Timer0 TMR;
	u8 Local_u8ErrorState = TMR.MTMR_u8Timer0CTCSetCallBack(Copy_pf);
	return Local_u8ErrorState;
}
