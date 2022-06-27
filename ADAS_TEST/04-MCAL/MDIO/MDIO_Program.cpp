 /**
 * @file         MDIO_program.cpp 
 *
 * /b Description : 
 * This file includes DIO class implementation  	  
 *
 * @author      Embedded Cpp TEAM					 								*
 * @date        20/6/2022 																	*
 * @version     V_1	
 * @copyright   IMT_SCHOOL 2022
 */

#include "../../00-LIB/BIT_MATH.h"
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/ERROR_STATE.h"
#include "MDIO_Interface.h"
#include "MDIO_Config.h"
#include "MDIO_Private.h"

u8 DIO :: MDIO_u8SetPinDirection (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDirection)
{
	u8 Local_u8ReturnState = OK;
	/* Check 1- Valid Port  ID
	         2- Valid Pin ID
			 3- Valid Pin Direction */
    if((Copy_u8PortID <= DIO_u8_PORTD) && (Copy_u8PinID <= DIO_u8_PIN7) && ((Copy_u8PinDirection == DIO_u8_INPUT) || (Copy_u8PinDirection == DIO_u8_OUTPUT)))
	{
		switch(Copy_u8PortID)
		{
			case DIO_u8_PORTA:
			{
				switch(Copy_u8PinDirection)
				{
					case DIO_u8_OUTPUT:
					{
						SET_BIT(DDRA_u8_REG,Copy_u8PinID);
						break;
					}
					case DIO_u8_INPUT:
					{
						CLR_BIT(DDRA_u8_REG,Copy_u8PinID);
						break;
					}
				}
				break;
			}
			case DIO_u8_PORTB:
			{
				switch(Copy_u8PinDirection)
				{
					case DIO_u8_OUTPUT:
					{
						SET_BIT(DDRB_u8_REG,Copy_u8PinID);
						break;
					}
					case DIO_u8_INPUT:
					{
						CLR_BIT(DDRB_u8_REG,Copy_u8PinID);
						break;
					}
				}
				break;
			}
			case DIO_u8_PORTC:
			{
				switch(Copy_u8PinDirection)
				{
					case DIO_u8_OUTPUT:
					{
						SET_BIT(DDRC_u8_REG,Copy_u8PinID);
						break;
					}
					case DIO_u8_INPUT:
					{
						CLR_BIT(DDRC_u8_REG,Copy_u8PinID);
						break;
					}
				}
				break;
			}
			case DIO_u8_PORTD:
			{
				switch(Copy_u8PinDirection)
				{
					case DIO_u8_OUTPUT:
					{
						SET_BIT(DDRD_u8_REG,Copy_u8PinID);
						break;
					}
					case DIO_u8_INPUT:
					{
						CLR_BIT(DDRD_u8_REG,Copy_u8PinID);
						break;
					}
				}
				break;
			}
			
		}
	}
	else
	{
		Local_u8ReturnState = NOK;
	}
	return Local_u8ReturnState;
}


u8 DIO :: MDIO_u8SetPinValue     (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue)
{
	/* error state */
	u8 Local_u8ReturnState = OK;

	/* check if port or pin is out of scope or vale*/
	  if((Copy_u8PortID <= DIO_u8_PORTD)  && (Copy_u8PinID <= DIO_u8_PIN7) && ((Copy_u8PinValue == DIO_u8_HIGH) || (Copy_u8PinValue == DIO_u8_LOW)))
	  {
		  switch (Copy_u8PortID)
		  {
			  case DIO_u8_PORTA:
			  {
					switch(Copy_u8PinValue)
					{
						case DIO_u8_HIGH:
						{
							SET_BIT(PORTA_u8_REG,Copy_u8PinID);
							break;
						}
						case DIO_u8_LOW:
						{
							CLR_BIT(PORTA_u8_REG,Copy_u8PinID);
							break;
						}
					}
				break;
			  }
			  case DIO_u8_PORTB:
			  {
					switch(Copy_u8PinValue)
					{
						case DIO_u8_HIGH:
						{
							SET_BIT(PORTB_u8_REG,Copy_u8PinID);
							break;
						}
						case DIO_u8_LOW:
						{
							CLR_BIT(PORTB_u8_REG,Copy_u8PinID);
							break;
						}
					}
				break;
			  }
			  case DIO_u8_PORTC:
			  {
					switch(Copy_u8PinValue)
					{
						case DIO_u8_HIGH:
						{
							SET_BIT(PORTC_u8_REG,Copy_u8PinID);
							break;
						}
						case DIO_u8_LOW:
						{
							CLR_BIT(PORTC_u8_REG,Copy_u8PinID);
							break;
						}
					}
				break;
			  }
			  case DIO_u8_PORTD:
			  {
					switch(Copy_u8PinValue)
					{
						case DIO_u8_HIGH:
						{
							SET_BIT(PORTD_u8_REG,Copy_u8PinID);
							break;
						}
						case DIO_u8_LOW:
						{
							CLR_BIT(PORTD_u8_REG,Copy_u8PinID);
							break;
						}
					}
				break;
			  }
		   }
	  }
	  else
	  {
			/* error */
	      Local_u8ReturnState = NOK;
	  }
	  
	  /* return error state */
	return Local_u8ReturnState;
}


u8 DIO::MDIO_u8GetPinValue(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 * Copy_pu8ReturnedPinValue)
{
	/* error state */
	u8 Local_u8ReturnState = OK;

	if((Copy_u8PortID <= DIO_u8_PORTD)  && (Copy_u8PinID <= DIO_u8_PIN7) && (Copy_pu8ReturnedPinValue != NULL))
	{
		switch (Copy_u8PortID)
		{
			case DIO_u8_PORTA:	*Copy_pu8ReturnedPinValue = GET_BIT(PINA_u8_REG,Copy_u8PinID); break;
			case DIO_u8_PORTB:	*Copy_pu8ReturnedPinValue = GET_BIT(PINB_u8_REG,Copy_u8PinID); break;
			case DIO_u8_PORTC:	*Copy_pu8ReturnedPinValue = GET_BIT(PINC_u8_REG,Copy_u8PinID); break;
			case DIO_u8_PORTD:	*Copy_pu8ReturnedPinValue = GET_BIT(PIND_u8_REG,Copy_u8PinID); break;
		}
	}
	else
	{
		/*return error */ 
		Local_u8ReturnState = NOK;
	}

	/* return error state */
	return Local_u8ReturnState;
}


u8 DIO :: MDIO_u8SetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDirection )
{
	u8 Local_u8ReturnState = OK;
	/* check for error */
//	if(Copy_u8PortID > PORTD_u8_REG)
//	{
//		/* error */
//		Local_u8ReturnState = NOK;
//	}
//	else
	{
		switch(Copy_u8PortID)
		{
			case DIO_u8_PORTA: /* DDRA_u8_REG = Copy_u8PortDirection; */ break;
			case DIO_u8_PORTB: /* DDRB_u8_REG = Copy_u8PortDirection; */break;
			case DIO_u8_PORTC: /* DDRC_u8_REG = Copy_u8PortDirection; */break;
			case DIO_u8_PORTD: /* DDRD_u8_REG = Copy_u8PortDirection; */break;
			default 		 : Local_u8ReturnState = NOK;
		}
	}	
	return Local_u8ReturnState;
}


u8 DIO :: MDIO_u8SetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortValue)
{
	u8 Local_u8ReturnState = OK;
	/* check for error */
//	if(Copy_u8PortID > PORTD_u8_REG)
//	{
//		/* error */
//		Local_u8ReturnState = NOK;
//	}
//	else
	{
		switch(Copy_u8PortID)
		{
			case DIO_u8_PORTA:PORTA_u8_REG = Copy_u8PortValue; break;
			case DIO_u8_PORTB:PORTB_u8_REG = Copy_u8PortValue; break;
			case DIO_u8_PORTC:PORTC_u8_REG = Copy_u8PortValue; break;
			case DIO_u8_PORTD:PORTD_u8_REG = Copy_u8PortValue; break;
			default : Local_u8ReturnState = NOK;
		}
	}
	
	return Local_u8ReturnState;
}


u8 DIO :: MDIO_u8Set4PinsValue    (u8 Copy_u8PortID, u8 Copy_u8PinStart, u8 Copy_u8PortValue)
{
	u8 Local_u8ReturnState = OK;
	if(Copy_u8PinStart<=4)
	{
		switch(Copy_u8PortValue)
		{
			case DIO_u8_PORTA:
			{
				PORTA_u8_REG&=(~(0b00001111<<Copy_u8PinStart));
				PORTA_u8_REG|=(Copy_u8PortValue<<Copy_u8PinStart);
				break;
			}
			case DIO_u8_PORTB:
			{
				PORTB_u8_REG&=(~(0b00001111<<Copy_u8PinStart));
				PORTB_u8_REG|=(Copy_u8PortValue<<Copy_u8PinStart);
				break;
			}
			case DIO_u8_PORTC:
			{
				PORTC_u8_REG&=(~(0b00001111<<Copy_u8PinStart));
				PORTC_u8_REG|=(Copy_u8PortValue<<Copy_u8PinStart);
				break;
			}
			case DIO_u8_PORTD:
			{
				PORTD_u8_REG&=(~(0b00001111<<Copy_u8PinStart));
				PORTD_u8_REG|=(Copy_u8PortValue<<Copy_u8PinStart);
				break;
			}

		}
	}
	else
	{
		/* return error */ 
		Local_u8ReturnState = NOK;
	}

	return Local_u8ReturnState;
}


u8 DIO :: MDIO_u8GetPortValue    (u8 Copy_u8PortID, u8 * Copy_pu8ReturnedPortValue)
{
	u8 Local_u8ReturnState = OK;
	if(Copy_pu8ReturnedPortValue != NULL)
	{
		switch(Copy_u8PortID)
		{
		   case DIO_u8_PORTA: *Copy_pu8ReturnedPortValue = PINA_u8_REG; break;
		   case DIO_u8_PORTB: *Copy_pu8ReturnedPortValue = PINB_u8_REG; break;
		   case DIO_u8_PORTC: *Copy_pu8ReturnedPortValue = PINC_u8_REG; break;
		   case DIO_u8_PORTD: *Copy_pu8ReturnedPortValue = PIND_u8_REG; break;
		   default : Local_u8ReturnState = NOK;
		}
	}
	else
	{
		Local_u8ReturnState = NOK;
	}
	return Local_u8ReturnState;
}

