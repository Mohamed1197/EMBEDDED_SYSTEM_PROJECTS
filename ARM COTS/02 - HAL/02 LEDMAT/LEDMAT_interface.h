/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   13/12/2020        ********************/
/**************** SWC     :     LEDMAT          ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/

#ifndef		_LEDMAT_INTERFACE_H
#define		_LEDMAT_INTERFACE_H

void	HLEDMAT_voidInit(void);

void	HLEDMAT_voidDisplayFrame(u8 * Copy_u8Data);

void    HLEDMAT_voidDisplayString(u8 ** Copy_u8Data);

void    HLEDMAT_voidDisplayStringShift(u8 * Copy_u8StringShift , u8 Copy_u8Lenght);

#endif

