/*==================================================================================*
 * File        : FILTER_PROGRAM.c													*
 * Description : This file includes Filters Algorithm  implementations 				*
 * Author      : Embedded C Team					 								*
 * Date        : 																	*
 * version     : V_1								 								*
 *==================================================================================*/

/************ LIB  **********/
#include "../../00-LIB/STD_TYPES.h"

/************ FILTER **********/
#include "FILTER_INTERFACE.h"


u16 Average_Filteration( u16 *P_u16Values , u8 Copy_u8Size )
{
	u16 Local_u16Sum     = 0;
	u32 Local_u32Average = 0;
	u8 Local_u8Counter = 0;

	for( Local_u8Counter = 0 ; Local_u8Counter < Copy_u8Size ; Local_u8Counter++)
	{
		Local_u16Sum += P_u16Values[Local_u8Counter];
	}
	Local_u32Average = (Local_u16Sum / Copy_u8Size) ;
	return Local_u32Average ;
}


u16 Majority_Filteration( u16 *P_u16Values , u8 Copy_u8Size )
{
	u8 Local_u8Counter = 0;
		 // check if A[i] is majority element or not
		    for ( Local_u8Counter = 0; Local_u8Counter <= (Copy_u8Size/2) ; Local_u8Counter++)
		    {
		        u8 Local_u8count = 1;
		        for (u8 Local_u8Iterator = Local_u8Counter + 1; Local_u8Iterator < Copy_u8Size; Local_u8Iterator++)
		        {
		            if (P_u16Values[Local_u8Iterator] == P_u16Values[Local_u8Counter])
		            {
		            	Local_u8count++;
		            }
		        }
		        if (Local_u8count > (Copy_u8Size/2) ) {
		            return P_u16Values[Local_u8Counter];
		        }
		    }
		 return 0;
}


u16 Consective_Filteration( u16 *P_u16Values , u8 Copy_u8Size )
{
	u16 Local_u16Counter = 0 , Local_u16Count = 0 , Local_u16Index ;
	u8 Local_u8Counter = 0;
	for( Local_u8Counter = 0 ; Local_u8Counter < Copy_u8Size ; Local_u8Counter++)
		{
			if(P_u16Values[Local_u8Counter] == P_u16Values[Local_u8Counter+1])
			{
				Local_u16Counter++ ;
				if(Local_u16Count < Local_u16Counter)
				{
					Local_u16Index = P_u16Values[Local_u8Counter] ;
					Local_u16Count = Local_u16Counter ;
				}
			}
			else
			{
				Local_u16Counter = 0 ;
			}
		}
	return Local_u16Index;
}
