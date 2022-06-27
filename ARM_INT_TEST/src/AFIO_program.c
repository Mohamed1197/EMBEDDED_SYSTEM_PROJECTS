/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   11/12/2020        ********************/
/**************** SWC     :     AFIO            ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidSelectInterruptSource(u8 Copy_u8PortID , u8 Copy_u8INTLine)
{
	if(Copy_u8INTLine < 4)
	{
		AFIO -> EXTICR1 &= ~      (0b1111 << (Copy_u8INTLine * 4));
		AFIO -> EXTICR1 |= (Copy_u8PortID << (Copy_u8INTLine * 4));
	}
	else if((Copy_u8INTLine >= 4) && (Copy_u8INTLine < 8))
    {
		Copy_u8INTLine -=4;
		AFIO -> EXTICR2 &= ~      (0b1111 << (Copy_u8INTLine * 4));
		AFIO -> EXTICR2 |= (Copy_u8PortID << (Copy_u8INTLine * 4));
    }
    else if((Copy_u8INTLine >= 8) && (Copy_u8INTLine < 12))
    {
    	Copy_u8INTLine -=8;
		AFIO -> EXTICR3 &= ~      (0b1111 << (Copy_u8INTLine * 4));
		AFIO -> EXTICR3 |= (Copy_u8PortID << (Copy_u8INTLine * 4));
    }
	else if((Copy_u8INTLine >= 12) && (Copy_u8INTLine < 16))
    {
		Copy_u8INTLine -=12;
		AFIO -> EXTICR4 &= ~      (0b1111 << (Copy_u8INTLine * 4));
		AFIO -> EXTICR4 |= (Copy_u8PortID << (Copy_u8INTLine * 4));
    }
}
