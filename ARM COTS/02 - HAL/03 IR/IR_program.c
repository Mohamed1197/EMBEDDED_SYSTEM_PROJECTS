/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   27/12/2020        ********************/
/**************** SWC     :     IR              ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/

/* LIB  */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*  MCAL  */
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "EXTI_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

/* HAL */
#include "IR_interface.h"
#include "IR_private.h"

static volatile u8   u8StartFlag       = 0;
static volatile u32  u32FrameData[33]  = {0};
static volatile u8   u8EdgeCounter     = 0;
 volatile u8   Data            = 0;
void (*Play)(void);


void MIR_voidInit(void (*Pf)(void))
{
	Play = Pf ;
	/* EXTI Initializtion */
	MEXTI_voidSetCallBack(voidGetFrame, EXTI_u8_LINE0);
	MEXTI_voidInit(); /* A0 EXTI0 Enabled / Falling Edge */

	/* Enable EXTI Line 0 */
	MEXTI_voidEnable(EXTI_u8_LINE0);

	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();
	MNVIC_u8EnableInterrupt(NVIC_VEC_T_EXTI0); /* EXTI0 */

	/* SysTick Init */
	MSTK_voidInit(); /* Enable SysTick AHB/8 = 1MHZ */

}


void voidTakeAction(void)
{
	u8 i;
	Data = 0;

	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )
	{
		for (i=0;i<8;i++)
		{
			if (  (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300) )
			{
				SET_BIT(Data,i);
			}
			else if(  (u32FrameData[17+i] >= 1000) && (u32FrameData[17+i] <=1300) )
			{
				CLR_BIT(Data,i);
			}
			else
			{
				/* Invalid Frame */
			}
		}
		Play();
	}
	else
	{
		/* Invalid Frame */
	}
	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}

void voidGetFrame(void)
{
	if (u8StartFlag == 0)
	{
		/* Start Timer */
		MSTK_voidSetIntervalSingle(200000,voidTakeAction);
		u8StartFlag = 1;
	}
	else
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTicks();
		MSTK_voidSetIntervalSingle(200000,voidTakeAction);
		u8EdgeCounter++;
	}
}
