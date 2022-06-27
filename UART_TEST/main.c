#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include<util/delay.h>

#include "DIO_interface.h"
#include "UART_interface.h"

int main(void)
{
	u8 *Local_u8Data;
	u8 Data;

//	u8 arr[8] ;
//
//	arr[0] = 'a'  ; //UART_u8RecieveDataByte();
//	arr[1] = 'b'  ;//UART_u8RecieveDataByte();
//	arr[2] = 'c'  ;//UART_u8RecieveDataByte();
//	arr[3] = 'd'  ; //UART_u8RecieveDataByte();
//	arr[4] = 'e'  ; //UART_u8RecieveDataByte();
//	arr[5] = 'f'  ; //UART_u8RecieveDataByte();
//	arr[6] = 'g'  ; //UART_u8RecieveDataByte();
//	arr[7] = 0x00 ;

	DIO_u8Init();

	UART_voidInit();
//
	//ptr = arr;



	while(1)
	{
//		UART_voidSendDataStringSynch("Local");

//		UART_u8RecieveDataStringSynch(Local_u8Data);
////
//		UART_voidSendDataStringSynch(Local_u8Data);


//		UART_u8RecieveDataStringSynch(&Local_u8Data);
//		UART_voidSendDataStringSynch("Local_u8Data");

//
//		Local_u8Data = UART_u8RecieveDataStringSynch();
//
//
//		UART_voidSendDataStringSynch(Local_u8Data);


//		UART_voidSendDataStringSynch(">>>   Start  <<< ");
//		_delay_ms(1000);
//		UART_voidSendDataStringSynch("  TEST 1  ");
//		_delay_ms(1000);
//		UART_voidSendDataStringSynch("  TEST 2  ");
//		_delay_ms(1000);
//		UART_voidSendDataStringSynch("  TEST 3  ");
//		_delay_ms(1000);
//		UART_voidSendDataStringSynch("  TEST 4 ");
//		_delay_ms(1000);
//		UART_voidSendDataStringSynch(" ---- End ---- ");
//		_delay_ms(1000);
//      	UART_voidSendDataStringSynch(" Start ");
//
//		Local_u8Data = UART_u8RecieveDataByte();
//		UART_voidSendDataByte(Local_u8Data);
//
//		UART_voidSendDataStringSynch(" TEST1 Receive Character ");
//
//		UART_u8RecieveDataStringSynch(&Local_u8Data);
//
//		UART_voidSendDataStringSynch(" TEST2 Receive String ");

	    //UART_voidSendDataStringSynch(Local_u8Data);

		Local_u8Data = UART_u8RecieveDataStringSynch();
		UART_voidSendDataStringSynch(Local_u8Data);
//		if(Local_u8Data == "on ")
//		{
//			//Turn On LED
//			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
//		}
//		else if(Local_u8Data == "off ")
//		{
//			//Turn Off LED
//			DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
//		}

	}
	return 0;
}

