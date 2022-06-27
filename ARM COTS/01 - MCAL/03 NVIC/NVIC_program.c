#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/*	How many Groups and Sub Groups 	*/
void MNVIC_voidInit(void)
{
	#define  SCB_AIRCR     *((volatile u32 *)(0xE000ED00 + 0x0C))
	/* 4 bits for Groups(Max Groups 16) and 0 bits for Sub-Group Priority(Max Sub 0) */
    #if (NUM_GROUPS_AND_SUB == GROUP_16_SUB_0)
	{
		SCB_AIRCR = GROUP_16_SUB_0 ;
	}
	/* 3 bits for Groups(Max Groups 8) and 1 bits for Sub-Group Priority(Max Sub 2) */
	#elif   (NUM_GROUPS_AND_SUB == GROUP_8_SUB_2)
	{
	SCB_AIRCR = GROUP_8_SUB_2 ;
	}
	/* 2 bits for Groups(Max Groups 4) and 2 bits for Sub-Group Priority(Max Sub 4) */
	#elif   (NUM_GROUPS_AND_SUB == GROUP_4_SUB_4)
	{
	SCB_AIRCR = GROUP_4_SUB_4 ;
	}
	/* 1 bits for Groups(Max Groups 2) and 3 bits for Sub-Group Priority(Max Sub 8) */
	#elif   (NUM_GROUPS_AND_SUB == GROUP_2_SUB_8)
	{
	SCB_AIRCR = GROUP_2_SUB_8 ;
	}
	/* 0 bits for Groups(Max Groups 0) and 4 bits for Sub-Group Priority(Max Sub 16) */
	#elif   (NUM_GROUPS_AND_SUB == GROUP_0_SUB_16)
	{
	SCB_AIRCR = GROUP_0_SUB_16 ;
	}
    #else
		#error "Wrong choice of NVIC GROUP and SUB selection"
	#endif
}

/*	Set interrupt priority	*/
u8 MNVIC_u8SetInterrruptPriority(/*Arguments*/ u8 Copy_u8PrephiralID , u8 Copy_u8Grouppriority , u8 Copy_u8Subpriority)
{
	u8 Local_u8ErrorStats = STD_TYPES_OK;
	if(Copy_u8PrephiralID < 60)
	{
		/* 4 bits for Groups(Max Groups 16) and 0 bits for Sub-Group Priority(Max Sub 0) */
	    #if (NUM_GROUPS_AND_SUB == GROUP_16_SUB_0)
		{
			if((Copy_u8Grouppriority < 16) && (Copy_u8Subpriority == 0 ))
			{
			NVIC_IPR[Copy_u8PrephiralID] = (Copy_u8Grouppriority << 4);
			}
			else
			{
				Local_u8ErrorStats = STD_TYPES_NOK;
			}
		}
		/* 3 bits for Groups(Max Groups 8) and 1 bits for Sub-Group Priority(Max Sub 2) */
		#elif   (NUM_GROUPS_AND_SUB == GROUP_8_SUB_2)
		{
			if((Copy_u8Grouppriority < 8) && (Copy_u8Subpriority < 2 ))
			{
				NVIC_IPR[Copy_u8PrephiralID] = ((Copy_u8Grouppriority << 5) | (Copy_u8Subpriority << 4));
			}
			else
			{
				Local_u8ErrorStats = STD_TYPES_NOK;
			}
		}
		/* 2 bits for Groups(Max Groups 4) and 2 bits for Sub-Group Priority(Max Sub 4) */
		#elif   (NUM_GROUPS_AND_SUB == GROUP_4_SUB_4)
		{
			if((Copy_u8Grouppriority < 4) && (Copy_u8Subpriority < 4 ))
			{
				NVIC_IPR[Copy_u8PrephiralID] = ((Copy_u8Grouppriority << 6) | (Copy_u8Subpriority << 4));
			}
			else
			{
				Local_u8ErrorStats = STD_TYPES_NOK;
			}

		}
		/* 1 bits for Groups(Max Groups 2) and 3 bits for Sub-Group Priority(Max Sub 8) */
		#elif   (NUM_GROUPS_AND_SUB == GROUP_2_SUB_8)
		{
			if((Copy_u8Grouppriority < 2) && (Copy_u8Subpriority < 8 ))
			{
				NVIC_IPR[Copy_u8PrephiralID] = ((Copy_u8Grouppriority << 7) | (Copy_u8Subpriority << 4));
			}
			else
			{
				Local_u8ErrorStats = STD_TYPES_NOK;
			}
		}
		/* 0 bits for Groups(Max Groups 0) and 4 bits for Sub-Group Priority(Max Sub 16) */
		#elif   (NUM_GROUPS_AND_SUB == GROUP_0_SUB_16)
		{
			if((Copy_u8Grouppriority == 0) && (Copy_u8Subpriority < 16 ))
			{
				NVIC_IPR[Copy_u8PrephiralID] =  (Copy_u8Subpriority << 4);
			}
			else
			{
				Local_u8ErrorStats = STD_TYPES_NOK;
			}
		}
        #else
              	#error "Wrong choice of NVIC GROUP and SUB selection"
		#endif

	}
	else
	{
		Local_u8ErrorStats = STD_TYPES_NOK;
	}
	return Local_u8ErrorStats;
	
}

u8	MNVIC_u8EnableInterrupt(u8 Copy_u8IntNumber)
{
	u8 ErrorStatus ;
	/*		Range Check			*/
	if(Copy_u8IntNumber < 32)
	{
		NVIC_ISER0 = (1<<Copy_u8IntNumber);
		ErrorStatus = 0;
	}
	else if(Copy_u8IntNumber < 60)
	{
		Copy_u8IntNumber -=32;
		NVIC_ISER1 = (1<<Copy_u8IntNumber);
		ErrorStatus = 0;
	}
	else 
	{
		/*	return Error	 */
		ErrorStatus = 1;
	}
	return ErrorStatus ;
}




u8	MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber)
{
	u8 ErrorStatus ;
	/*		Range Check			*/
	if(Copy_u8IntNumber < 32)
	{
		NVIC_ICER0 = (1<<Copy_u8IntNumber);
		ErrorStatus = 0;
	}
	else if(Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ICER1 = (1<<Copy_u8IntNumber);
		ErrorStatus = 0;
	}
	else 
	{
		/*	return Error	 */
		ErrorStatus = 1;
	}
	return ErrorStatus ;
}



u8	MNVIC_u8SetPendingFlag(u8 Copy_u8IntNumber)
{
	u8 ErrorStatus ;
	/*		Range Check			*/
	if(Copy_u8IntNumber < 32)
	{
		NVIC_ISPR0 = (1<<Copy_u8IntNumber);
		ErrorStatus = 0;
	}
	else if(Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ISPR1 = (1<<Copy_u8IntNumber);
		ErrorStatus = 0;
	}
	else 
	{
		/*	return Error	 */
		ErrorStatus = 1;
	}
	return ErrorStatus ;
}




u8	MNVIC_u8ClearPendingFlag(u8 Copy_u8IntNumber)
{
	u8 ErrorStatus ;
	/*		Range Check			*/
	if(Copy_u8IntNumber < 32)
	{
		NVIC_ICPR0 = (1<<Copy_u8IntNumber);
		ErrorStatus = 0;
	}
	else if(Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ICPR1 = (1<<Copy_u8IntNumber);
		ErrorStatus = 0;
	}
	else 
	{
		/*	return Error	 */
		ErrorStatus = 1;
	}
	return ErrorStatus ;
}


u8	MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8ActiveValue = 0xFF ;
	/*		Range Check			*/
	if(Copy_u8IntNumber < 32)
	{
		Local_u8ActiveValue = GET_BIT(NVIC_IABR0 , Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -=32;
		Local_u8ActiveValue = GET_BIT(NVIC_IABR1 , Copy_u8IntNumber);
	}
	else 
	{
		/*	return Error	 */
	}
	return Local_u8ActiveValue;
}
