/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   11/12/2020        ********************/
/**************** SWC     :     AFIO            ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
#ifndef _AFIO_PRIVATE_H
#define _AFIO_PRIVATE_H

typedef struct
{
	volatile u32 EVCR;
	volatile u32 MAPR;
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;
	volatile u32 MAPR2;
	
}AFIO_Type;

#define AFIO  ((volatile AFIO_Type *)(0x40010000)) 



#endif