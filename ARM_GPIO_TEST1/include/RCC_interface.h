/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   10/11/2020        ********************/
/**************** SWC     :     RCC             ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB           1
#define RCC_APB1          3
#define RCC_APB2          6

void RCC_voidInit(void);

void RCC_voidEnableClock(u8 Copy_u8BusID ,u8 Copy_u8PeriferalID );

void RCC_voidDisableClock(u8 Copy_u8BusID ,u8 Copy_u8PeriferalID );


#endif