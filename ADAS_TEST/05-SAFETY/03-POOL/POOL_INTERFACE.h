/*==============================================================================================*
 * File        : POOL_INTERFACE.h																*
 * Description : This file includes DOUBLE INVERSION Algorithm prototypes and macros			*
 * Author      : Embedded C Team					 											*
 * Date        : 																				*
 * version     : V_1								 											*
 *==============================================================================================*/

#ifndef  POOL_INTERFACE_H
#define  POOL_INTERFACE_H


typedef struct 
{
	u16    Data;
	f64    Inversion;
	
}Data_Pool_t;

/****** global Array data_type it "Data_Pool_t" ,it is have critical variable of system ******/
Data_Pool_t  Array_Pool[3] = {0} ;

/******************  Prototypes POOL  Process  ********************/
u16 POOL_u16DoubleInversionCheck(u16 Copy_u16Value,u8 Copy_u8Address);
void POOL_voidStoreData(u16 Copy_u16Value,u8 Copy_u8Address);
void POOL_voidWriteInPool (u16 Copy_u16AddresPool,u16 Copy_u16Value,f64 Copy_f64Inversion);
u16 POOL_u16ReadFromPool(u16 Copy_u16AddresPool);

#endif
