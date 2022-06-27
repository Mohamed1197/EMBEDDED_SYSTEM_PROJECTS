/*
 * GIE_interface.h
 *
 *  Created on: Jun 20, 2022
 *      Author: aaa
 */

#ifndef WRAPPER_WGIE_GIE_INTERFACE_H_
#define WRAPPER_WGIE_GIE_INTERFACE_H_


#ifdef __cplusplus
extern "C"
{
#endif

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
	void MGIE_voidEnable(void);

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
	void MGIE_voidDisable(void);

#ifdef __cplusplus
}
#endif


#endif /* WRAPPER_WGIE_GIE_INTERFACE_H_ */
