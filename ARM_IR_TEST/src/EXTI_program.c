#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*EXTI_CallBack[16])(void) ={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};


/* Initializing EXTI Pin */
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

/* Selecting Sense Mode on an EXTI Pin */
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
//	SET_BIT(EXTI -> IMR , Copy_u8LineID);
}

/* Enable EXTI on a Line */
void MEXTI_voidEnable(u8 Copy_u8LineID)
{
	SET_BIT(EXTI -> IMR , Copy_u8LineID);
}

/* Disable EXTI on a Line */
void MEXTI_voidDisable(u8 Copy_u8LineID)
{
	CLR_BIT(EXTI -> IMR , Copy_u8LineID);
}

/* Set Sotware Trigger EXTI on a Line */
void MEXTI_voidSetSotwareTrigger(u8 Copy_u8LineID)
{
	SET_BIT(EXTI -> SWIER , Copy_u8LineID);
}

/*  Passing the Application ISR Function to the Call Back Function  */
void MEXTI_voidSetCallBack( void (*pf) (void) , u8 Copy_u8EXTI_ID)
{
	EXTI_CallBack[Copy_u8EXTI_ID] = pf;
}

/* EXTI0 ISR Function */
void EXTI0_IRQHandler(void)
{
	EXTI_CallBack[0]();
	SET_BIT(EXTI -> PR , EXTI_u8_LINE0);
}

/*  EXTI1 ISR Function */
void EXTI1_IRQHandler(void)
{
	EXTI_CallBack[1]();
	SET_BIT(EXTI -> PR , EXTI_u8_LINE1);
}

/*  EXTI2 ISR Function */
void EXTI2_IRQHandler(void)
{
	EXTI_CallBack[2]();
	SET_BIT(EXTI -> PR , EXTI_u8_LINE2);
}

/*  EXTI3 ISR Function */
void EXTI3_IRQHandler(void)
{
	EXTI_CallBack[3]();
	SET_BIT(EXTI -> PR , EXTI_u8_LINE3);
}

/* EXTI4 ISR Function */
void EXTI4_IRQHandler(void)
{
	EXTI_CallBack[4]();
	SET_BIT(EXTI -> PR , EXTI_u8_LINE4);
}

/* EXTI5 to EXTI9 ISR Function */
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_CallBack[5] != NULL)
	{
	EXTI_CallBack[5]();
	SET_BIT(EXTI -> PR , EXTI_u8_LINE5);
	}
	if(EXTI_CallBack[6] != NULL)
	{
	EXTI_CallBack[6]();
	SET_BIT(EXTI -> PR , EXTI_u8_LINE6);
	}
	if(EXTI_CallBack[7] != NULL)
	{
	EXTI_CallBack[7]();
	SET_BIT(EXTI -> PR , EXTI_u8_LINE7);
	}
	if(EXTI_CallBack[8] != NULL)
	{
	EXTI_CallBack[8]();
	SET_BIT(EXTI -> PR , EXTI_u8_LINE8);
	}
	if(EXTI_CallBack[9] != NULL)
	{
	EXTI_CallBack[9]();
	SET_BIT(EXTI -> PR , EXTI_u8_LINE9);
	}
}

/*  EXTI10 to EXTI15 ISR Function */
void EXTI15_10_IRQHandler(void)
{
	if(EXTI_CallBack[10] != NULL)
	{
		EXTI_CallBack[10]();
		SET_BIT(EXTI -> PR , EXTI_u8_LINE10);
	}
	if(EXTI_CallBack[11] != NULL)
	{
		EXTI_CallBack[11]();
		SET_BIT(EXTI -> PR , EXTI_u8_LINE11);
	}
	if(EXTI_CallBack[12] != NULL)
	{
		EXTI_CallBack[12]();
		SET_BIT(EXTI -> PR , EXTI_u8_LINE12);
	}
	if(EXTI_CallBack[13] != NULL)
	{
		EXTI_CallBack[13]();
		SET_BIT(EXTI -> PR , EXTI_u8_LINE13);
	}
	if(EXTI_CallBack[14] != NULL)
	{
		EXTI_CallBack[14]();
		SET_BIT(EXTI -> PR , EXTI_u8_LINE14);
	}

	if(EXTI_CallBack[15] != NULL)
	{
		EXTI_CallBack[15]();
		SET_BIT(EXTI -> PR , EXTI_u8_LINE15);
	}

}


