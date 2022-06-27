/*==================================================================================*
 * File        : LIMP_HOME_PROGRAM.c												*
 * Description : This file includes LIMP_HOME STATES implementations 				*
 * Author      : Embedded C Team					 								*
 * Date        : 																	*
 * version     : V_1								 								*
 *==================================================================================*/

/************ LIB  **********/
#include "../../00-LIB/STD_TYPES.h"

/************ LIMP_HOME  **********/
#include "LIMP_HOME_INTERFACE.h"

/*=================================================================================================*
 * Prototype   : void  LIMPHOME_voidLimp_home_S1(void);											   *
 * Description : This case will be entered when Ultrasonic sensor gives wrong values and the car   *
 * 				 is moving on speed more than 50												   *
 * 				 Action: Force the motor to down its speed to min. speed						   *
 * Arguments   : void																			   *
 * return      : void																			   *
 *=================================================================================================*/
void  LIMPHOME_voidLimp_home_S1(void)
{

}

/*=================================================================================================*
 * Prototype   : void  LIMPHOME_voidLimp_home_S1(void);											   *
 * Description : This case will be entered when Ultrasonic sensor gives wrong values and the car   *
 * 				 is moving on speed less than 50 and more than 30  								   *
 * 				 Action: Force the motor to down its speed to min. speed						   *
 * Arguments   : void																			   *
 * return      : void																			   *
 *=================================================================================================*/
void  LIMPHOME_voidLimp_home_S2(void)
{

}
