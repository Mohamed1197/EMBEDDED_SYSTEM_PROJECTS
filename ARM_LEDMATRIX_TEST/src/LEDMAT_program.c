#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "STK_interface.h"

#include "LEDMAT_interface.h"
#include "LEDMAT_private.h"
#include "LEDMAT_config.h"

void	HLEDMAT_voidInit(void)
{
	/*	Rows Direction							*/
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_ROW_0 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_ROW_1 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_ROW_2 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_ROW_3 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_ROW_4 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_ROW_5 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_ROW_6 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_ROW_7 , GPIO_OUTPUT_2MHZ_PUSH_PULL);

	MGPIO_voidSetPortDirection(HLEDMAT_u8_ROW_PORT , GPIO_OUTPUT_2MHZ_PUSH_PULL);

	/*	Columns Direction							*/
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_COL_0 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_COL_1 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_COL_2 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_COL_3 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_COL_4 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_COL_5 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_COL_6 , GPIO_OUTPUT_2MHZ_PUSH_PULL);
//	MGPIO_voidSetPinDirection( HLEDMAT_U8_COL_7 , GPIO_OUTPUT_2MHZ_PUSH_PULL);

	MGPIO_voidSetPortDirection(HLEDMAT_u8_COL_PORT , GPIO_OUTPUT_2MHZ_PUSH_PULL);

}
void	HLEDMAT_voidDisplayFrame(u8 * Copy_u8Data)
{

	u8 idx;
	for(idx = 0 ; idx < 8 ; idx++)
	{
		/*	Set Rows								*/
		SetRows(Copy_u8Data[idx]);
		/*	Activate Column 0 						*/
		Activate_Column(idx);
		/*		Delay	2.5msec						*/
		MSTK_voidSetBusyWait(2500);
	}
}

void HLEDMAT_voidDisplayString(u8 ** Copy_u8Data)
{
	u8 index = 0;

	while(Copy_u8Data[index ] != NULL)
	{
	   for(u8 i = 0 ; i <50 ; i ++)
	    {

		  HLEDMAT_voidDisplayFrame(Copy_u8Data[index]);
		}
	   index ++ ;
	}

}

void HLEDMAT_voidDisplayStringShift(u8 * Copy_u8StringShift , u8 Copy_u8Lenght)
{
	u8 Temp[Copy_u8Lenght];
	u8 Counter = 0;
while(Counter < Copy_u8Lenght  )
{
	for(u8 i = 0 ; i < 20 ; i++)
	{
		if(Counter < (Copy_u8Lenght - 6) )
		{
	        HLEDMAT_voidDisplayFrame(Copy_u8StringShift);
		}
	}

	for(u8 i = 0 ; i < Copy_u8Lenght ; i++)
	{
		Temp[i] = Copy_u8StringShift[i];
	}

	Copy_u8StringShift[(Copy_u8Lenght - 1)] = Temp[0];

	for(u8 i = 0 ; i < (Copy_u8Lenght - 1) ; i++)
	{
		Copy_u8StringShift[i] = Temp[i+1];
	}

	Counter++;
}
Delay_ms(1000);


}



void SetRows(u8 Copy_u8byteFrame)
{
//	u8 HLEDMAT_u8Temp = 0;
//	HLEDMAT_u8Temp = GET_BIT(Copy_u8byteFrame , 0 );
//	MGPIO_voidSetPinValue( HLEDMAT_U8_ROW_0 , HLEDMAT_u8Temp);
//
//	HLEDMAT_u8Temp = GET_BIT(Copy_u8byteFrame , 1 );
//	MGPIO_voidSetPinValue( HLEDMAT_U8_ROW_1 , HLEDMAT_u8Temp);
//
//	HLEDMAT_u8Temp = GET_BIT(Copy_u8byteFrame , 2 );
//	MGPIO_voidSetPinValue( HLEDMAT_U8_ROW_2 , HLEDMAT_u8Temp);
//
//	HLEDMAT_u8Temp = GET_BIT(Copy_u8byteFrame , 3 );
//	MGPIO_voidSetPinValue( HLEDMAT_U8_ROW_3 , HLEDMAT_u8Temp);
//
//	HLEDMAT_u8Temp = GET_BIT(Copy_u8byteFrame , 4 );
//	MGPIO_voidSetPinValue( HLEDMAT_U8_ROW_4 , HLEDMAT_u8Temp);
//
//	HLEDMAT_u8Temp = GET_BIT(Copy_u8byteFrame , 5 );
//	MGPIO_voidSetPinValue( HLEDMAT_U8_ROW_5 , HLEDMAT_u8Temp);
//
//	HLEDMAT_u8Temp = GET_BIT(Copy_u8byteFrame , 6 );
//	MGPIO_voidSetPinValue( HLEDMAT_U8_ROW_6 , HLEDMAT_u8Temp);
//
//	HLEDMAT_u8Temp = GET_BIT(Copy_u8byteFrame , 7 );
//	MGPIO_voidSetPinValue( HLEDMAT_U8_ROW_7 , HLEDMAT_u8Temp);
	
	MGPIO_voidSetPortValueRegister(HLEDMAT_u8_ROW_PORT , Copy_u8byteFrame );

}

void Activate_Column(u8 Copy_u8Column)
{
			/*	Columns Disable							*/
//	MGPIO_voidSetPinValue( HLEDMAT_U8_COL_0 , GPIO_u8_HIGH);
//	MGPIO_voidSetPinValue( HLEDMAT_U8_COL_1 , GPIO_u8_HIGH);
//	MGPIO_voidSetPinValue( HLEDMAT_U8_COL_2 , GPIO_u8_HIGH);
//	MGPIO_voidSetPinValue( HLEDMAT_U8_COL_3 , GPIO_u8_HIGH);
//	MGPIO_voidSetPinValue( HLEDMAT_U8_COL_4 , GPIO_u8_HIGH);
//	MGPIO_voidSetPinValue( HLEDMAT_U8_COL_5 , GPIO_u8_HIGH);
//	MGPIO_voidSetPinValue( HLEDMAT_U8_COL_6 , GPIO_u8_HIGH);
//	MGPIO_voidSetPinValue( HLEDMAT_U8_COL_7 , GPIO_u8_HIGH);
	MGPIO_voidSetPortValue( HLEDMAT_u8_COL_PORT , GPIO_u8_HIGH);
	
	switch(Copy_u8Column)
	{
		case 0 : MGPIO_voidSetPinValue( HLEDMAT_U8_COL_0 , GPIO_u8_LOW); break;
		case 1 : MGPIO_voidSetPinValue( HLEDMAT_U8_COL_1 , GPIO_u8_LOW); break;
		case 2 : MGPIO_voidSetPinValue( HLEDMAT_U8_COL_2 , GPIO_u8_LOW); break;
		case 3 : MGPIO_voidSetPinValue( HLEDMAT_U8_COL_3 , GPIO_u8_LOW); break;
		case 4 : MGPIO_voidSetPinValue( HLEDMAT_U8_COL_4 , GPIO_u8_LOW); break;
		case 5 : MGPIO_voidSetPinValue( HLEDMAT_U8_COL_5 , GPIO_u8_LOW); break;
		case 6 : MGPIO_voidSetPinValue( HLEDMAT_U8_COL_6 , GPIO_u8_LOW); break;
		case 7 : MGPIO_voidSetPinValue( HLEDMAT_U8_COL_7 , GPIO_u8_LOW); break;
	}
}
