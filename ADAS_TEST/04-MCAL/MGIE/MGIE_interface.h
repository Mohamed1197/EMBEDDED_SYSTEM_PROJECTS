/*
 * GIE_interface.h
 *
 *  Created on: Jun 19, 2022
 *      Author: Emad Yousry
 */

#ifndef LIB_MGIE_INTERFACE_H_
#define LIB_MGIE_INTERFACE_H_



class MGIE {

private:

public:

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

};




#endif /* LIB_MGIE_INTERFACE_H_ */
