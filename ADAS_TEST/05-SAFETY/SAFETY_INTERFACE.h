/*==================================================================================*
 * File        : SAFETY_INTERFACE.h													*
 * Description : This file includes Safety Process prototypes and macros			*
 * Author      : Embedded C Team					 								*
 * Date        : 																	*
 * version     : V_1								 								*
 *==================================================================================*/

#ifndef _SAFETY_INTERFACE_H_
#define _SAFETY_INTERFACE_H_

/****** Current Speed of Dc_Motor ******/
extern u16 Globalu16_CurrentSpeed;

/****** RANGE Sensor  macros ******/
enum
{
	 MIN_RANGE= 0,
	 MAX_RANGE= 5
};

/****** Levels Error Range Sensor  macros ******/
enum
{
	TRUE  = 1,
	FALSE = 0
};

/******* Types of Filtration Process  macros ******/
enum
{
	AVERAGE_FILTER      =   31,
	MAJORITY_FILTER     =   227,
	CONSECUTIVE_FILTER  =   252

};

/*******  Levels Limp Home States  macros ******/
enum
{
    LIMP_STATE_1   =    85,
	LIMP_STATE_2    =   90
	//LIMP_STATE_3    =   102
};

/******************  Prototypes Safety Process  ********************/
u16  SAFETY_u16P_Check( u16 *P_u16Values , u8 Copy_u8Size );
u16  SAFETY_u16Select_Filteration(u16 *P_u16Values , u8 Copy_u8Size , u8 Copy_u8FilterType);
void SAFETY_voidSelect_LimpHome(u16 Copy_u16State);

#endif
