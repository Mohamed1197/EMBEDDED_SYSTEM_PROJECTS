/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    : 23/10/2020          ********************/
/**************** SWC     :     RTOS            ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TMR_interface.h"
#include "GI_interface.h"

#include "RTO_config.h"
#include "RTO_interface.h"
#include "RTO_private.h"

/* Create Array of TCBs */
static TCB RTO_AstrTasks[RTO_u8_MAX_NUMBER_OF_TASKS];

u8     RTO_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay, void(*Copy_pf)(void))
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if( (Copy_pf != NULL) && (Copy_u8Priority < RTO_u8_MAX_NUMBER_OF_TASKS) )
	{
		RTO_AstrTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
		RTO_AstrTasks[Copy_u8Priority].FirstDelay  = Copy_u16FirstDelay;
		RTO_AstrTasks[Copy_u8Priority].pf          = Copy_pf;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}

static void   RTO_voidScheduler(void)
{
	u8 Local_u8Counter;
	for(Local_u8Counter = 0; Local_u8Counter < RTO_u8_MAX_NUMBER_OF_TASKS; Local_u8Counter++)
	{
		if(RTO_AstrTasks[Local_u8Counter].FirstDelay == 0)
		{
			//Call Function
			RTO_AstrTasks[Local_u8Counter].pf();
			/* Update FirstDelay With The Periodicity */
			RTO_AstrTasks[Local_u8Counter].FirstDelay = RTO_AstrTasks[Local_u8Counter].Periodicity - 1;
		}
		else
		{
			RTO_AstrTasks[Local_u8Counter].FirstDelay--;
		}
	}
}
void   RTO_voidInit(void)
{
	/* Enable Global Interrupt */
	GI_voidEnable();

	TMR_voidTimer1SetCompareMatchValueChannelA(1000);

	TMR_u8Timer1CTCSetCallBack(&RTO_voidScheduler);



	/* Start Timer */
	TMR_voidTimer1Init();
}
