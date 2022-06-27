/*****Name     : Mohamed Ibrahim*/
/*****Date     : 10/11/2020******/
/*****Software : RCC***********/
/*****version  : 1.0**********/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*Macros for BUS*/
#define RCC_AHB      1
#define RCC_APB1     3
#define RCC_APB2     6

void RCC_VoidInit(void);

void RCC_VoidEnableClock(u8 copy_u8BusID , u8 copy_u8PeripheralID);

void RCC_VoidDisableClock(u8 copy_u8BusID , u8 copy_u8PeripheralID);

#endif