/*==================================================================================*
 * File        : SAFETY_PROGRAM.c													*
 * Description : This file includes Safety Process implementations 					*
 * Author      : Embedded C Team					 								*
 * Date        : 																	*
 * version     : V_1								 								*
 *==================================================================================*/

/************ LIB  **********/
#include "../00-LIB/STD_TYPES.h"

/************ SAFETY  **********/
#include "02-LIMP_HOME/LIMP_HOME_INTERFACE.h"
#include "01-FILTERATION/FILTER_INTERFACE.h"
#include "SAFETY_INTERFACE.h"

/*=================================================================================================*
 * Prototype   : u16 SAFETY_u16P_Check( u16 *P_u16Values , u8 Copy_u8Size );					   *
 * Description : Check if Values Of Sensor In Range Or Not										   *
 * 			 	               1)  In Range      ->  go_to_filteration then Return Best Value	   *
 * 							   2)  Out Of Range  ->  go_To_LimpHome	then Return Best Value		   *
 * Arguments   : 2 	Arguments :																	   *
 * 			 	               1)  Array -> Values Of Sensor 									   *
 * 							   2)  size of Array  												   *
 * return      : return Best Value of Sensor													   *
 *=================================================================================================*/
u16 SAFETY_u16P_Check( u16 *P_u16Values , u8 Copy_u8Size )
{
	u8 Local_u8Counter = 0;                // iterator for loop of values of of Sensor
	u8 InRange_Flag = FALSE;               // flag for ==>> for Check values of of Sensor in Range ,initial Value FALSE
	u8 Local_u8Errors_Counter = 0;         // counter ==>> for check values of of Sensor Out Of Range ,initial Value Zero
	u8 Local_u8ErrorIndex;				   // Local_u8ErrorIndex store index of Value that is Out of Range
	u16 Local_u16Value;                    //

	/*===================================================================================*
	 *  For Loop : Looping in values of Sensor											 *
	 *  				Check :															 *
	 *  							1)if Values  Out Of Range 							 *
	 *  							2)if Values In Range 								 *
	 *===================================================================================*/
	for( Local_u8Counter = 0 ; Local_u8Counter < Copy_u8Size ; Local_u8Counter++)
	{
		if(P_u16Values[Local_u8Counter] > MAX_RANGE || P_u16Values[Local_u8Counter] < MIN_RANGE)   		 // Check Out Of Range
		{
			Local_u8Errors_Counter = Local_u8Errors_Counter + 1;         // Increment Local_u8Errors_Counter by one
			Local_u8ErrorIndex = Local_u8Counter;                        // assign Number of index to Local_u8ErrorIndex

		}
		else if(P_u16Values[Local_u8Counter] <= MAX_RANGE || P_u16Values[Local_u8Counter] >= MIN_RANGE)   // Check In Range
		{
			InRange_Flag = TRUE;                          // assign TRUE value to InRange_Flag
		}
	}

	if( (InRange_Flag == TRUE) && (Local_u8Errors_Counter == 0) )       // Check if All values in Range
	{
		//go_to_filteration
		Local_u16Value = SAFETY_u16Select_Filteration(P_u16Values,Copy_u8Size,AVERAGE_FILTER);
		//return Value
		return Local_u16Value;
	}
	else if( (InRange_Flag == TRUE) && (Local_u8Errors_Counter > 0) )   // Check if any value out Of Range
	{
		// go_To_LimpHome
		if( (P_u16Values[Local_u8ErrorIndex] < 0 ) && (Local_u8Errors_Counter > 5) ) // Local_Counter_2 = Number of wrong values
		{
			SAFETY_voidSelect_LimpHome(LIMP_STATE_2);
		}
		else if( (P_u16Values[Local_u8ErrorIndex] > 5)  && (Local_u8Errors_Counter > 5))
		{

		}
		//return Value
	}
}

/*==============================================================================================================*
 * Prototype   : u16 SAFETY_u16Select_Filteration(u16 *P_u16Values , u8 Copy_u8Size , u8 Copy_u8FilterType);    *
 * Description :  Values of Sensor 									                               				*
 * 			 	               In Range  ->  go_to_filteration then Return Best Value	  		  			    *
 * Arguments   : 3 	Arguments :																	  			    *
 * 			 	               1)  Array -> Values Of Sensor 									   				*
 * 							   2)  size of Array  															    *
 * 							   3)  Types of Filtration											  			    *
 * return      : return Best Value of Sensor													 			    *
 *==============================================================================================================*/
u16 SAFETY_u16Select_Filteration(u16 *P_u16Values , u8 Copy_u8Size , u8 Copy_u8FilterType )
{
	u16 Local_u16Value = 0;
	switch( Copy_u8FilterType )      				  // Selection Type of Filter
	{
	case AVERAGE_FILTER   :
		Local_u16Value = Average_Filteration(P_u16Values,Copy_u8Size);		// call Average_Filteration and assign return to Local_u16Value
		break;

	case MAJORITY_FILTER    :
		Local_u16Value = Majority_Filteration(P_u16Values,Copy_u8Size);     // call Majority_Filteration and assign return to Local_u16Value
		break;

	case CONSECUTIVE_FILTER :
		Local_u16Value = Consective_Filteration(P_u16Values,Copy_u8Size);   // call Consective_Filteration and assign return to Local_u16Value
		break;

	default:
		/************  Do_Nothing ***********/
		break;
	}
	return Local_u16Value;                            // return  Local_u16Value
}

/*=================================================================================================*
 * Prototype   : void SAFETY_voidSelect_LimpHome(u16 Copy_u16State);							   *
 * Description : This function decides the action to keep the driver safe, after detecting an error*
 * 				 in any module. 										  						   *
 * 							     Out Of Range  ->  go_To_LimpHome	then Return Best Value		   *
 * Arguments   : 1 	Arguments :																	   *
 * 			 	                Limp Home State 			 									   *
 * return      : void																			   *
 *=================================================================================================*/
void SAFETY_voidSelect_LimpHome(u16 Copy_u16State)
{
	switch( Copy_u16State )                  		 // Selection Levels of Limp Home States
	{

	case LIMP_STATE_1	:
		/*===================================================================================*
		 *  This case will be entered when Ultrasonic sensor gives wrong values and the car   *
		 *  is moving on speed more than 50													 *
		 *  Action: Force the motor to down its speed to min. speed							 *
		 *====================================================================================*/
		LIMPHOME_voidLimp_home_S1();												// call limp_home state 1
		break;

	case LIMP_STATE_2	:
		/*===================================================================================*
		 *  This case will be entered when Ultrasonic sensor gives wrong values and the car   *
		 *  is moving on speed less than 50 and more than 30  								 *
		 *  Action: Force the motor to down its speed to min. speed  						 *
		 *====================================================================================*/
		LIMPHOME_voidLimp_home_S2();										    	// call limp_home state 2
		break;

	default:
		/************  Do_Nothing ***********/
		break;
	}
}
