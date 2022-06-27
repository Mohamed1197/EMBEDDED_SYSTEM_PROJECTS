/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   05/01/2021        ********************/
/**************** SWC     :     STP            ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/

/* LIB  */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*  MCAL  */
#include "GPIO_interface.h"
#include "STK_interface.h"

/* HAL */
#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"


void HSTP_voidSendSynch(u8 Copy_u8DataToSend)
{
	s8 LOC_Counter ;
	u8 LOC_u8Bit   ;

	MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , GPIO_u8_LOW); 
	MGPIO_voidSetPinValue(STP_STORAGE_CLOCK , GPIO_u8_LOW); 
	
	for( LOC_Counter = 7 ; LOC_Counter >=0 ; LOC_Counter --)
	{
		/* Get MSB first */
		LOC_u8Bit = GET_BIT( Copy_u8DataToSend , LOC_Counter );
		MGPIO_voidSetPinValue(STP_DATA_SERIAL , LOC_u8Bit); //DS --> DATA SERIAL
		
		/*  Send Rising Edge to Shift Clock */
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , GPIO_u8_HIGH); 
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK , GPIO_u8_LOW); 
		MSTK_voidSetBusyWait(1);
		
	}
	
	    /*  Send Rising Edge to Shift Clock */
		MGPIO_voidSetPinValue(STP_STORAGE_CLOCK , GPIO_u8_HIGH); 
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(STP_STORAGE_CLOCK , GPIO_u8_LOW); 
		MSTK_voidSetBusyWait(1);
	
	
}
