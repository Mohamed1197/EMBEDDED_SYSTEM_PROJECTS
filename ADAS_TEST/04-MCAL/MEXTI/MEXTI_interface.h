/*
 * MEXTI_interface.h
 *
 *  Created on: Jun 19, 2022
 *      Author: Emad Yousry
 */

#ifndef LIB_MEXTI_INTERFACE_H_
#define LIB_MEXTI_INTERFACE_H_

#define LOW_LEVEL     0
#define ON_CHANGE     1
#define FALLING_EDGE  2
#define RISING_EDGE   3

#define EXTI0         0
#define EXTI1         1
#define EXTI2         2
#define EXTI3         3

#define GICR_INT0     6
#define GICR_INT1     7
#define GICR_INT2     5

#define GIFR_INTF0     6
#define GIFR_INTF1     7
#define GIFR_INTF2     5


#define MCUCR_ISC11   3
#define MCUCR_ISC10   2
#define MCUCR_ISC01   1
#define MCUCR_ISC00   0

class MEXTI{

private:

public:

	/**
	 *  @brief Enable External Interrupt
	 *
	 *  \b Description : This function takes inputs interrupt index and
	 *   interrupt sensing control and return error status.
	 *   Sense Control Options
	 * 1- LOW_LEVEL
	 * 2- ON_CHANGE
	 * 3- FALLING_EDGE
	 * 4- RISING_EDGE
	 *
	 *  @param u8 Copy_u8_EXTIIndex
	 *  @param u8 Copy_u8EXTIEdge
	 *
	 *  @return Error Status
	 */
	u8 MEXTI_u8Enable (u8 Copy_u8_EXTIIndex , u8 Copy_u8EXTIEdge);

	/**
	 *  @brief Disable External Interrupt
	 *
	 *  \b Description : This function takes inputs interrupt index and
	 *    return error status.
	 *
	 *  @param u8 Copy_u8_EXTIIndex
	 *
	 *  @return Error Status
	 */
	u8 MEXTI_u8Disable (u8 Copy_u8_EXTIIndex);
	/**
	 *  @brief Set External Interrupt Callback
	 *
	 *  \b Description : This function takes inputs pointer to function and
	 *   interrupt index and return error status.
	 *
	 *  @param (void (*Copy_pf)(void)
	 *  @param u8 Copy_u8CallBackIndex
	 *
	 *  @return Error Status
	 */
	u8 MEXTI_u8SetCallBack (void (*Copy_pf)(void), u8 Copy_u8CallBackIndex);

};


#endif /* LIB_MEXTI_INTERFACE_H_ */
