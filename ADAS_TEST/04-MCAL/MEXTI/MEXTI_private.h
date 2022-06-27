/*
 * MEXTI_private.h
 *
 *  Created on: Jun 19, 2022
 *      Author: Emad Yousry
 */

#ifndef LIB_MEXTI_PRIVATE_H_
#define LIB_MEXTI_PRIVATE_H_

#define MCUCR    *((volatile u8*)0x55)
#define MCUCSR   *((volatile u8*)0x54)
#define GICR     *((volatile u8*)0x5B)
#define GIFR     *((volatile u8*)0x5A)


#endif /* LIB_MEXTI_PRIVATE_H_ */
