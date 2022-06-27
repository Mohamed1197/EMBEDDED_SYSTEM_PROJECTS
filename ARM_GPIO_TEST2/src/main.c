/*
 * main.c
 *
 *  Created on: Nov 20, 2020
 *      Author: elsay
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"RCC_Priv.h"
#include"RCC_INT.h"

#define   GPIOA_CRL      *((volatile u32*)0x40010800)
#define   GPIOA_ODR      *((volatile u32*)0x4001080C)


int main(void)
{
	/*RCC INITIAIZATION*/
	RCC_voidInit();
	/*Enable PERIPHERAL*/
	RCC_voidEnableClock(RCC_APB2, APB2_GPIOA);
	/*SET DIRECTION FOR GPIO A*/
	GPIOA_CRL=0X00000002;

	/*SET PIN VALUE*/
	GPIOA_ODR=0X00000008;



	while(1)
	{

	}


	return 0;
}
