/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   11/12/2020        ********************/
/**************** SWC     :     AFIO            ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
#ifndef _AFIO_INTERFACE_H
#define _AFIO_INTERFACE_H

void MAFIO_voidSelectInterruptSource(u8 Copy_u8PortID , u8 Copy_u8INTLine);

/**** Select Interrupt PORT  ****/
#define AFIO_PORTA      0b0000
#define AFIO_PORTB      0b0001
#define AFIO_PORTC      0b0010


#endif
