/*
 * EXTI_program.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: aaa
 */


#include "../../00-LIB/BIT_MATH.h"
#include "../../00-LIB/STD_TYPES.h"
#include "../../04-MCAL/MEXTI/MEXTI_interface.h"
#include "EXTI_interface.h"





u8 MEXTI_u8Enable (u8 Copy_u8_EXTIIndex , u8 Copy_u8EXTIEdge)
{
	MEXTI EXT;
	u8 Loc_u8ErrorState = EXT.MEXTI_u8Enable(Copy_u8_EXTIIndex,Copy_u8EXTIEdge);
	return Loc_u8ErrorState;
}

u8 MEXTI_u8Disable (u8 Copy_u8_EXTIIndex)
{
	MEXTI EXT;
	u8 Loc_u8ErrorState = EXT.MEXTI_u8Disable(Copy_u8_EXTIIndex);
	return Loc_u8ErrorState;
}

u8 MEXTI_u8SetCallBack (void (*Copy_pf)(void), u8 Copy_u8CallBackIndex)
{
	MEXTI EXT;
	u8 Loc_u8ErrorState = EXT.MEXTI_u8SetCallBack(Copy_pf,Copy_u8CallBackIndex);
	return Loc_u8ErrorState;
}

