#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void (*EXTI0_CallBack)(void);

void (*EXTI1_CallBack)(void);


void MEXTI_voidInit(void)
{
	#if		EXTI_SENSE_MODE == EXTI_FALLING
			SET_BIT(EXTI->	FTSR,EXTI_LINE);
	#elif	EXTI_SENSE_MODE == EXTI_RISING
			SET_BIT(EXTI->	RTSR,EXTI_LINE);
	#elif	EXTI_SENSE_MODE == EXTI_IOC
			SET_BIT(EXTI->	RTSR,EXTI_LINE);
			SET_BIT(EXTI->	FTSR,EXTI_LINE);
	#else
			#error "Wrong choice of External Interrupt Sense Mode"
	#endif
	/*	In initialization fun we disable Interrupts	*/
	CLR_BIT(EXTI -> IMR , EXTI_LINE);
}


void MEXTI_voidSetSignalLatch(u8 Copy_u8LineID , u8 Copy_u8SenseMode)
{
	switch(Copy_u8SenseMode)
	{
		case EXTI_FALLING	:	SET_BIT(EXTI->	FTSR,Copy_u8LineID);
								CLR_BIT(EXTI->	RTSR,Copy_u8LineID);		break;
		
		case EXTI_RISING	:	SET_BIT(EXTI->	RTSR,Copy_u8LineID);
								CLR_BIT(EXTI->	FTSR,Copy_u8LineID);		break;
								
		case EXTI_IOC	   :	SET_BIT(EXTI->	RTSR,Copy_u8LineID);
								SET_BIT(EXTI->	FTSR,Copy_u8LineID);		break;
	}
//		/* 		Enable Interrupt	Line									*/
	CLR_BIT(EXTI -> IMR , Copy_u8LineID);
}
void MEXTI_voidEnable(u8 Copy_u8LineID)
{
	SET_BIT(EXTI -> IMR , Copy_u8LineID);
}
void MEXTI_voidDisable(u8 Copy_u8LineID)
{
	CLR_BIT(EXTI -> IMR , Copy_u8LineID);
}
void MEXTI_voidSetSotwareTrigger(u8 Copy_u8LineID)
{
	SET_BIT(EXTI -> SWIER , Copy_u8LineID);
}

void EXTI0_voidSetCallBack(void (*pf) (void))
{
	EXTI0_CallBack = pf;
}

void EXTI1_voidSetCallBack(void (*pf) (void))
{
	EXTI1_CallBack = pf;
}

void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
	SET_BIT(EXTI -> PR , EXTI_u8_LINE0);
}

void EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();
	SET_BIT(EXTI -> PR , EXTI_u8_LINE1);
}
