/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    : 23/10/2020          ********************/
/**************** SWC     :     RTOS            ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
#ifndef RTO_PRIVATE_H
#define RTO_PRIVATE_H


typedef struct
{
	u16 Periodicity;

	u16 FirstDelay;

	void(*pf)(void);
}TCB;

static void   RTO_voidScheduler(void);

#endif
