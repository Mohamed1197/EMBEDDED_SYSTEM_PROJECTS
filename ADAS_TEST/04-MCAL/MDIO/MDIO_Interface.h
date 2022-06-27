 /**
 * @file         MDIO_interface.h 
 *
 * /b Description : 
 * This file includes DIO abstract class 	  
 *
 * @author      Embedded Cpp TEAM					 								*
 * @date        20/6/2022 																	*
 * @version     V_1	
 * @copyright   IMT_SCHOOL 2022
 */

#ifndef MDIO_INTERFACE_H
#define MDIO_INTERFACE_H

/* Macros for PORTS ID */
#define DIO_u8_PORTA           0
#define DIO_u8_PORTB           1
#define DIO_u8_PORTC           2
#define DIO_u8_PORTD           3

/* Macros for PINS ID */
#define DIO_u8_PIN0            0
#define DIO_u8_PIN1            1
#define DIO_u8_PIN2            2
#define DIO_u8_PIN3            3
#define DIO_u8_PIN4            4
#define DIO_u8_PIN5            5
#define DIO_u8_PIN6            6
#define DIO_u8_PIN7            7

/* Macros for PIN Direction */
#define DIO_u8_INPUT           0
#define DIO_u8_OUTPUT          1

/*Macros for PIN Value*/
#define DIO_u8_HIGH            1
#define DIO_u8_LOW             0


/* Prototypes of the DIO driver */
class DIO
{
private:
	//private variable data;
public:
	/**
	 * Prototype   : MDIO_u8SetPinDirection (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDirection);
	 *
	 * \b Description : 
	 * Set pin direction as input or output
	 * 													
	 * @param   Copy_u8PortID  port name 
	 * 							Options:
	 * 								- DIO_u8_PORTA
	 * 								- DIO_u8_PORTB
	 * 								- DIO_u8_PORTC
	 * 							    - DIO_u8_PORTD
	 * 
	 * @param	Copy_u8PinID	pin number, Options
	 * 								- DIO_u8_PIN0
	 * 								- DIO_u8_PIN1
	 * 								- DIO_u8_PIN2
	 * 								- DIO_u8_PIN3
	 * 								- DIO_u8_PIN4
	 * 								- DIO_u8_PIN5
	 * 								- DIO_u8_PIN6
	 * 								- DIO_u8_PIN7
	 * 
	 * @param	Copy_u8PinDirection  pin direction, Options:
	 * 								- DIO_u8_INPUT
	 * 								- DIO_u8_OUTPUT
	 * 
	 * @return  u8 indication error 
	 * 					- STD_TYPES_NOK
	 * 					- STD_TYPES_OK	
	 */ 
	u8 MDIO_u8SetPinDirection (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinDirection);

	/**
	 * Prototype   : MDIO_u8SetPinValue     (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue);
	 *
	 * \b Description : 
	 * Set pin value as input or output
	 * 													
	 * @param   Copy_u8PortID  port name, Options:
	 * 								- DIO_u8_PORTA
	 * 								- DIO_u8_PORTB
	 * 								- DIO_u8_PORTC
	 * 							    - DIO_u8_PORTD
	 * 
	 * @param	Copy_u8PinID	pin number, Options
	 * 								- DIO_u8_PIN0
	 * 								- DIO_u8_PIN1
	 * 								- DIO_u8_PIN2
	 * 								- DIO_u8_PIN3
	 * 								- DIO_u8_PIN4
	 * 								- DIO_u8_PIN5
	 * 								- DIO_u8_PIN6
	 * 								- DIO_u8_PIN7
	 * 
	 * @param	Copy_u8PinValue  pin value, Options:
	 * 								- DIO_u8_HIGH
	 * 								- DIO_u8_LOW
	 * 
	 * @return  u8 indication error 
	 * 					- STD_TYPES_NOK
	 * 					- STD_TYPES_OK	
	 */ 
	u8 MDIO_u8SetPinValue     (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8PinValue);


	/**
	 * Prototype   : MDIO_u8GetPinValue     (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 * Copy_pu8ReturnedPinValue);
	 * 
	 * \b Description : 
	 * return pin value as high or low
	 * 													
	 * @param   Copy_u8PortID  port name, Options:
	 * 								- DIO_u8_PORTA
	 * 								- DIO_u8_PORTB
	 * 								- DIO_u8_PORTC
	 * 							    - DIO_u8_PORTD
	 * 
	 * @param	Copy_u8PinID	pin number, Options
	 * 								- DIO_u8_PIN0
	 * 								- DIO_u8_PIN1
	 * 								- DIO_u8_PIN2
	 * 								- DIO_u8_PIN3
	 * 								- DIO_u8_PIN4
	 * 								- DIO_u8_PIN5
	 * 								- DIO_u8_PIN6
	 * 								- DIO_u8_PIN7
	 * 
	 * @param	Copy_pu8ReturnedPinValue  pointer to get pin value
	 * 
	 * @return  u8 indication error 
	 * 					- STD_TYPES_NOK
	 * 					- STD_TYPES_OK	
	 */ 
	u8 MDIO_u8GetPinValue     (u8 Copy_u8PortID, u8 Copy_u8PinID, u8 * Copy_pu8ReturnedPinValue);

	/**
	 * Prototype   : MDIO_u8SetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDirection );
	 * 
	 * \b Description : 
	 * set port direction input or output or mixed.
	 * 													
	 * @param   Copy_u8PortID  port name, Options:
	 * 								- DIO_u8_PORTA
	 * 								- DIO_u8_PORTB
	 * 								- DIO_u8_PORTC
	 * 							    - DIO_u8_PORTD
	 * 
	 * @param	Copy_u8PortDirection  port direction, AS (0xF1)
	 * 
	 * @return  u8 indication error 
	 * 					- STD_TYPES_NOK
	 * 					- STD_TYPES_OK	
	 */ 
	u8 MDIO_u8SetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDirection );

	/**
	 * Prototype   : MDIO_u8SetPortValue    (u8 Copy_u8PortID, u8 Copy_u8PortValue);
	 * 
	 * \b Description : 
	 * set port value.
	 * 													
	 * @param   Copy_u8PortID  port name, Options:
	 * 								- DIO_u8_PORTA
	 * 								- DIO_u8_PORTB
	 * 								- DIO_u8_PORTC
	 * 							    - DIO_u8_PORTD
	 * 
	 * @param	Copy_u8PortValue  port value, AS (0xF1)
	 * 
	 * @return  u8 indication error 
	 * 					- STD_TYPES_NOK
	 * 					- STD_TYPES_OK	
	 */ 
	u8 MDIO_u8SetPortValue    (u8 Copy_8uPortID, u8 Copy_u8PortValue);

	/**
	 * Prototype   : MDIO_u8Set4PinsValue    (u8 Copy_u8PortID, u8 Copy_u8PinStart, u8 Copy_u8PortValue);
	 * 
	 * \b Description : 
	 * set specific Continuous 4 bits value, sta.
	 * 													
	 * @param   Copy_u8PortID  port name, Options:
	 * 								- DIO_u8_PORTA
	 * 								- DIO_u8_PORTB
	 * 								- DIO_u8_PORTC
	 * 							    - DIO_u8_PORTD
	 * 
	 * @param	Copy_u8PinID	pin number, Options
	 * 								- DIO_u8_PIN0
	 * 								- DIO_u8_PIN1
	 * 								- DIO_u8_PIN2
	 * 								- DIO_u8_PIN3
	 * 								- DIO_u8_PIN4
	 * 								- DIO_u8_PIN5
	 * 								- DIO_u8_PIN6
	 * 								- DIO_u8_PIN7
	 * 
	 * @param	Copy_u8PortValue  set 4 pins value.
	 * 
	 * @return  u8 indication error 
	 * 					- STD_TYPES_NOK
	 * 					- STD_TYPES_OK	
	 */ 
	u8 MDIO_u8Set4PinsValue    (u8 Copy_u8PortID, u8 Copy_u8PinStart, u8 Copy_u8PortValue);

	/**
	 * Prototype   : MDIO_u8GetPortValue    (u8 Copy_u8PortID, u8 * Copy_pu8ReturnedPortValue);
	 * 
	 * \b Description : 
	 * return port values.
	 * 													
	 * @param   Copy_u8PortID  port name, Options:
	 * 								- DIO_u8_PORTA
	 * 								- DIO_u8_PORTB
	 * 								- DIO_u8_PORTC
	 * 							    - DIO_u8_PORTD
	 * 
	 * @param	Copy_pu8ReturnedPortValue  pointer to get port VALUE.
	 * 
	 * @return  u8 indication error 
	 * 					- STD_TYPES_NOK
	 * 					- STD_TYPES_OK	
	 */ 
	u8 MDIO_u8GetPortValue    (u8 Copy_u8PortID, u8 * Copy_pu8ReturnedPortValue);

};

#endif
