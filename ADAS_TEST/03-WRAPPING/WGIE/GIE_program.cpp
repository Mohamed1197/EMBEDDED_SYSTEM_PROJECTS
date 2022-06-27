/*
 * GIE_program.cpp
 *
 *  Created on: Jun 20, 2022
 *      Author: aaa
 */


#include "../../00-LIB/BIT_MATH.h"
#include "../../00-LIB/STD_TYPES.h"
#include "../../04-MCAL/MGIE/MGIE_interface.h"
#include "GIE_interface.h"

#include "../WDIO/DIO_interface.h"


void MGIE_voidEnable(void)
{
	MGIE GIE;
	GIE.MGIE_voidEnable();
}

void MGIE_voidDisable(void)
{
	MGIE GIE;
	GIE.MGIE_voidDisable();
}
