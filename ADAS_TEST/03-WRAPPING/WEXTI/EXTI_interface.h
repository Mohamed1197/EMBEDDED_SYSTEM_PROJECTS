/*
 * EXTI_interface.h
 *
 *  Created on: Jun 20, 2022
 *      Author: aaa
 */

#ifndef WRAPPER_WEXTI_EXTI_INTERFACE_H_
#define WRAPPER_WEXTI_EXTI_INTERFACE_H_


#ifdef __cplusplus
extern "C"
{
#endif



#define EXTI0         0
#define EXTI1         1
#define EXTI2         2
#define EXTI3         3

#define EXTI_LOW_LEVEL     0
#define EXTI_ON_CHANGE     1
#define EXTI_FALLING_EDGE  2
#define EXTI_RISING_EDGE   3

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
//u8 WEXTI_u8SetCallBack (void (*Copy_pf)(void), u8 Copy_u8CallBackIndex);

#ifdef __cplusplus
}
#endif



#endif /* WRAPPER_WEXTI_EXTI_INTERFACE_H_ */
