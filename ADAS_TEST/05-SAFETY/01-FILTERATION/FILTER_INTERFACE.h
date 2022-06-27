/*==================================================================================*
 * File        : FILTER_INTERFACE.h													*
 * Description : This file includes Filters Algorithm prototypes and macros			*
 * Author      : Embedded C Team					 								*
 * Date        : 																	*
 * version     : V_1								 								*
 *==================================================================================*/

#ifndef _FILTER_INTERFACE_H_
#define _FILTER_INTERFACE_H_


/************ LIB  **********/
#include "../../00-LIB/STD_TYPES.h"

/******************  Prototypes Filters Algorithm  Process  ********************/
u16 Average_Filteration( u16 *P_u16Values , u8 Copy_u8Size );
u16 Majority_Filteration( u16 *P_u16Values , u8 Copy_u8Size );
u16 Consective_Filteration( u16 *P_u16Values , u8 Copy_u8Size );

#endif
