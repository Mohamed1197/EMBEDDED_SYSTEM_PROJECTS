/*
 * DIO_program.c
 *
 *  Created on: Jun 20, 2022
 *      Author: aaa
 */


#include "../../00-LIB/BIT_MATH.h"
#include "../../00-LIB/STD_TYPES.h"
#include "../../04-MCAL/MDIO/MDIO_Interface.h"
#include "DIO_interface.h"

u8 MDIO_u8SetPinDirection (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDirection)
{
	DIO D;
	u8 Local_u8ReturnState = D.MDIO_u8SetPinDirection(Copy_u8PortID,Copy_u8PinID,Copy_u8PinDirection);
	return Local_u8ReturnState;
}

u8 MDIO_u8SetPinValue     (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue)
{
	DIO D;
	u8 Local_u8ReturnState = D.MDIO_u8SetPinValue(Copy_u8PortID,Copy_u8PinID,Copy_u8PinValue);
	return Local_u8ReturnState;

}

u8 MDIO_u8GetPinValue     (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 * Copy_pu8ReturnedPinValue)
{
	DIO D;
	u8 Local_u8ReturnState = D.MDIO_u8GetPinValue(Copy_u8PortID,Copy_u8PinID,Copy_pu8ReturnedPinValue);
	return Local_u8ReturnState;
}

u8 MDIO_u8SetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDirection )
{
	DIO D;
	u8 Local_u8ReturnState = D.MDIO_u8SetPortDirection(Copy_u8PortID,Copy_u8PortDirection);
	return Local_u8ReturnState;
}

u8 MDIO_u8SetPortValue    (u8 Copy_u8PortID, u8 Copy_u8PortValue)
{
	DIO D;
	u8 Local_u8ReturnState = D.MDIO_u8SetPortValue(Copy_u8PortID,Copy_u8PortValue);
	return Local_u8ReturnState;
}

u8 MDIO_u8Set4PinsValue    (u8 Copy_u8PortID, u8 Copy_u8PinStart, u8 Copy_u8PortValue)
{
	DIO D;
	u8 Local_u8ReturnState = D.MDIO_u8Set4PinsValue(Copy_u8PortID,Copy_u8PinStart, Copy_u8PortValue);
	return Local_u8ReturnState;
}

u8 MDIO_u8GetPortValue    (u8 Copy_u8PortID, u8 * Copy_pu8ReturnedPortValue)
{
	DIO D;
	u8 Local_u8ReturnState = D.MDIO_u8GetPortValue(Copy_u8PortID, Copy_pu8ReturnedPortValue);
	return Local_u8ReturnState;
}
