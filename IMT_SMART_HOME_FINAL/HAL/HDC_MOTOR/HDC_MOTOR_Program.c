/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                    */
/* Description       : HDC_MOTOR_Program.c --> implementations                                         */
/* Module  Features  :                                                                                 */
/*      01-HDCMOTOR_voidInit                                                                           */
/*      02-HDCMOTOR_voidMotorOn                                                                        */
/*      03-HDCMOTOR_voidMotorOff                                                                       */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "../../LIB/LSTD_TYPES.h"
#include "../../LIB/LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include"../../MCAL/MDIO/MDIO_Interface.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      HAL Module Library                                             */
/*******************************************************************************************************/

#include "HDC_MOTOR_Interface.h"

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01-HDCMOTOR_voidInit                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Initialize Motor pin                                                     */
/* 2- Function Input       -> Address of object from DCMotor_t                                         */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void HDCMOTOR_voidInit(DCMotor_t *Copy_PstructDCMotor)
{
	MDIO_Error_State_SetPinDirection(Copy_PstructDCMotor->Copy_u8_Pin,Copy_PstructDCMotor->Copy_u8Port,PIN_OUTPUT);
}


/*******************************************************************************************************/
/*                                      02-HDCMOTOR_voidMotorOn                                        */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Turn on Motor                                                            */
/* 2- Function Input       -> Address of object from DCMotor_t                                         */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void HDCMOTOR_voidMotorOn(DCMotor_t *Copy_PstructDCMotor)
{
	MDIO_Error_State_SetPinValue(Copy_PstructDCMotor->Copy_u8_Pin,Copy_PstructDCMotor->Copy_u8Port,PIN_HIGH);
}

/*******************************************************************************************************/
/*                                      03-HDCMOTOR_voidMotorOff                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Turn off Motor                                                           */
/* 2- Function Input       -> Address of object from DCMotor_t                                         */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void HDCMOTOR_voidMotorOff(DCMotor_t *Copy_PstructDCMotor)
{
	MDIO_Error_State_SetPinValue(Copy_PstructDCMotor->Copy_u8_Pin,Copy_PstructDCMotor->Copy_u8Port,PIN_LOW);
}
/*#####################################################################################################*/
/*                                  END OF FUNCTIONS IMPLEMENTATIONS                                   */
/*#####################################################################################################*/
