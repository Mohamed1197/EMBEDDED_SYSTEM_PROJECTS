/*
 * MGIE_program.cpp
 *
 *  Created on: Jun 19, 2022
 *      Author: Emad Yousry
 */
#include "../../00-LIB/BIT_MATH.h"
#include "../../00-LIB/STD_TYPES.h"
#include "MGIE_private.h"
#include "MGIE_interface.h"




	/**
	 *  @brief Enable Global Interrupt
	 *
	 *  \b Description : This function Enables the global interrupt
	 *    and takes no inputs arguments return void.
	 *
	 *  @param void
	 *
	 *  @return void
	 */
void MGIE::MGIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);

//	MDIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH);
}

	/**
	 *  @brief Disable Global Interrupt
	 *
	 *  \b Description : This function Disables the global interrupt
	 *    and takes no inputs arguments return void.
	 *
	 *  @param void
	 *
	 *  @return void
	 */
void MGIE::MGIE_voidDisable(void)
	{
		CLR_BIT(SREG,SREG_I);
	}

