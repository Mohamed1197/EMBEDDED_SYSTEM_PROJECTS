#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"

#include "GPIO_interface.h"

#include "STK_interface.h"

#include "LEDMAT_interface.h"

/* Letters */
u8 Letter_A[] = {0, 248, 36, 34, 36, 248, 0, 0};
u8 Letter_B[] = {0, 254, 146, 146, 108, 0, 0, 0};
u8 Letter_C[] = {0, 56, 68, 130, 130, 130, 0, 0};
u8 Letter_D[] = {0, 254, 130, 68, 56, 0, 0, 0};
u8 Letter_E[] = {0, 254, 146, 146, 146, 0, 0, 0};
u8 Letter_F[] = {0, 254, 18, 18, 18, 0, 0, 0};
u8 Letter_G[] = {0, 56, 68, 130, 146, 146, 112, 0};
u8 Letter_H[] = {0, 254, 16, 16, 16, 254, 0, 0};
u8 Letter_I[] = {0, 0, 130, 254, 130, 0, 0, 0};
u8 Letter_J[] = {0, 96, 130, 130, 126, 2, 0, 0};
u8 Letter_K[] = {0, 254, 16, 40, 68, 130, 0, 0};
u8 Letter_L[] = {0, 254, 128, 128, 128, 128, 0, 0};
u8 Letter_M[] = {0, 254, 4, 8, 8, 4, 254, 0};
u8 Letter_N[] = {0, 254, 4, 24, 48, 64, 254, 0};
u8 Letter_O[] = {0, 124, 130, 130, 130, 124, 0, 0};
u8 Letter_P[] = {0, 254, 18, 18, 12, 0, 0, 0};
u8 Letter_Q[] = {0, 124, 130, 130, 162, 194, 252, 0};
u8 Letter_R[] = {0, 254, 18, 18, 236, 0, 0, 0};
u8 Letter_S[] = {0, 76, 146, 146, 146, 100, 0, 0};
u8 Letter_T[] = {0, 2, 2, 254, 2, 2, 0, 0};
u8 Letter_U[] = {0, 126, 128, 128, 128, 126, 0, 0};
u8 Letter_V[] = {0, 62, 64, 128, 64, 62, 0, 0};
u8 Letter_W[] = {0, 254, 64, 32, 32, 64, 254, 0};
u8 Letter_X[] = {0, 198, 40, 16, 40, 198, 0, 0};
u8 Letter_Y[] = {0, 14, 16, 224, 16, 14, 0, 0};
u8 Letter_Z[] = {0, 194, 162, 146, 138, 134, 0, 0};

/* Numbers */
u8 Number_0[] = {0, 0, 126, 129, 129, 126, 0, 0};
u8 Number_1[] = {0, 0, 130, 255, 255, 128, 0, 0};
u8 Number_2[] = {0, 194, 161, 145, 137, 134, 0, 0};
u8 Number_3[] = {0, 66, 137, 137, 118, 0, 0, 0};
u8 Number_4[] = {0, 24, 20, 18, 255, 16, 0, 0};
u8 Number_5[] = {0, 0, 71, 137, 137, 137, 113, 0};
u8 Number_6[] = {0, 0, 124, 146, 146, 100, 0, 0};
u8 Number_7[] = {0, 2, 194, 34, 18, 14, 0, 0};
u8 Number_8[] = {0, 118, 137, 137, 118, 0, 0, 0};
u8 Number_9[] = {0, 70, 137, 137, 137, 126, 0, 0};

/* Mohamed Shifting  */
u8 Mohamed_shift[] = {0, 254, 4, 8, 8, 4, 254, 0, 0, 0, 124, 130, 130, 130, 124, 0, 0, 0, 254, 16, 16, 254, 0, 0, 0, 248, 36, 34, 36, 248, 0, 0, 0, 254, 4, 8, 8, 4, 254, 0, 0, 0, 254, 146, 146, 146, 0, 0, 0, 254, 130, 68, 56 , 0, 0, 0};


u8 * Mohamed[] =  {Letter_M , Letter_O , Letter_H , Letter_A , Letter_M , Letter_E , Letter_D , NULL };
u8 * Hafiz[]   =  {Letter_H , Letter_A , Letter_F , Letter_I , Letter_Z , NULL };
u8 * Alpha[]   =  {Letter_A , Letter_B , Letter_C , Letter_D , Letter_E , Letter_F , Letter_G , Letter_H , Letter_I , Letter_J , Letter_K , Letter_L , Letter_M , Letter_N , Letter_O , Letter_P , Letter_Q ,Letter_R , Letter_S , Letter_T , Letter_U , Letter_V , Letter_W , Letter_X , Letter_Y , Letter_Z , NULL };
u8 * Nums[]   =   {Number_0 , Number_1 , Number_2 , Number_3 , Number_4 , Number_5 , Number_6 , Number_7 , Number_8 , Number_9 , NULL };



int main(void)
{
	/*	8MHz 							*/
	MRCC_voidInit();
	/*	Enable GPIOA , GPIOB Bus		*/
	MRCC_voidEnableClock(RCC_APB2 , RCC_APB2_GPIOAEN);
	MRCC_voidEnableClock(RCC_APB2 , RCC_APB2_GPIOBEN);
	
	/*	GPIO Init						*/
	HLEDMAT_voidInit();
	
	/*	Systick Init					*/
	MSTK_voidInit();
	MGPIO_voidSetPortDirection(GPIO_u8_PORTA,GPIO_u8_LOW_PINS,GPIO_OUTPUT_2MHZ_PUSH_PULL);
	MGPIO_voidSetPortDirection(GPIO_u8_PORTA,GPIO_u8_HIGH_PINS,GPIO_OUTPUT_2MHZ_PUSH_PULL);
	
	while(1)
	{
	/*	Display Char					*/
//		for(u8 i = 0 ; i<50 ; i++)
//		{
//			HLEDMAT_voidDisplayFrame(Letter_M);
//		}
//		for(u8 i = 0 ; i<50 ; i++)
//		{
//			HLEDMAT_voidDisplayFrame(Letter_O);
//		}
//		for(u8 i = 0 ; i<50 ; i++)
//		{
//			HLEDMAT_voidDisplayFrame(Letter_H);
//		}
//		for(u8 i = 0 ; i<50 ; i++)
//		{
//			HLEDMAT_voidDisplayFrame(Letter_A);
//		}
//		for(u8 i = 0 ; i<50 ; i++)
//		{
//			HLEDMAT_voidDisplayFrame(Letter_M);
//		}
//		for(u8 i = 0 ; i<50 ; i++)
//		{
//			HLEDMAT_voidDisplayFrame(Letter_E);
//		}
//		for(u8 i = 0 ; i<50 ; i++)
//		{
//			HLEDMAT_voidDisplayFrame(Letter_D);
//		}

//		HLEDMAT_voidDisplayString(Mohamed);
//		Delay_s(1);
//		HLEDMAT_voidDisplayString(Hafiz);
//		Delay_ms(1000);
//		HLEDMAT_voidDisplayString(Alpha);
//		Delay_ms(1000);
//		HLEDMAT_voidDisplayString(Nums);
//		Delay_ms(1000);


		HLEDMAT_voidDisplayStringShift(Mohamed_shift , 56);

		HLEDMAT_voidDisplayString(Nums);




	}
}














