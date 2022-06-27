/*==================================================================================*
 * File        : POOL__PROGRAM.c													*
 * Description : This file includes DOUBLE INVERSION Algorithm implementations 		*
 * Author      : Embedded C Team					 								*
 * Date        : 																	*
 * version     : V_1								 								*
 *==================================================================================*/

/************ LIB  **********/
#include <math.h>
#include "../../00-LIB/STD_TYPES.h"

/************ POOL **********/
#include "POOL_INTERFACE.h"

u16 POOL_u16DoubleInversionCheck(u16 Copy_u16Value,u8 Copy_u8Address)
{
	u16 Local_u16ReadValue ;
	POOL_voidStoreData(Copy_u16Value , Copy_u8Address);
	Local_u16ReadValue = POOL_u16ReadFromPool(Copy_u8Address);
	return Local_u16ReadValue;
}


void POOL_voidStoreData(u16 Copy_u16Value,u8 Copy_u8Address)
{
	f64 Local_f64Inversion  =  pow(Copy_u16Value,-1) ;
	POOL_voidWriteInPool(Copy_u8Address,Copy_u16Value,Local_f64Inversion);
}


void POOL_voidWriteInPool (u16 Copy_u16AddresPool,u16 Copy_u16Value,f64 Copy_f64Inversion)
{
	f64 Local_f64Inversion  =  pow(Copy_u16Value,-1) ;
	if(Local_f64Inversion == Copy_f64Inversion)
	{
		Array_Pool[Copy_u16AddresPool].Data 	    = Copy_u16Value ;
		Array_Pool[Copy_u16AddresPool].Inversion  = Copy_f64Inversion ;
	}
	else
	{
		printf("Error Inversion\n");
	}
}

u16 POOL_u16ReadFromPool(u16 Copy_u16AddresPool)
{
	u16 Local_u16Value , Local_u16INDEX ;
	f64 Local_f64Inversion ;
    Local_u16Value = Array_Pool[Copy_u16AddresPool].Data 	;
	Local_f64Inversion = pow(Local_u16Value,-1) ; 
	
	if(Local_f64Inversion == Array_Pool[Copy_u16AddresPool].Inversion)
	{
		 Local_u16INDEX = Local_u16Value ;
	}
	else
	{
		printf("Error Inversion\n");
	}
	
	return Local_u16INDEX ;
}
