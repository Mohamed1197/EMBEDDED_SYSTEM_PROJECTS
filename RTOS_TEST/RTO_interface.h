/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    : 23/10/2020          ********************/
/**************** SWC     :     RTOS            ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
#ifndef RTO_INTERFACE_H
#define RTO_INTERFACE_H

u8     RTO_u8CreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity, u16 Copy_u16FirstDelay, void(*Copy_pf)(void));


void   RTO_voidInit(void);

#endif
