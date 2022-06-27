/******************************************************************/
/*             >>DATE:11/11/2020                                  */
/*             >>AUTHOR:ELSAYED MANSOUR SHALABY                   */
/*             >>VERSION:0.1                                      */
/******************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_INT.h"
#include"RCC_Priv.h"
#include"RCC_Config.h"

void RCC_voidInit(void)
{
	#if	Clock_Source==HSI
		/*ENABLE HSI*/
		CLR_BIT(RCC_CFGR,0);
		CLR_BIT(RCC_CFGR,1);
		
		/*HSION*/
		SET_BIT(RCC_CR,0);
		/*wait for HSI to be ready*/
		while(GET_BIT(RCC_CR,1)==0);
		RCC_voidCalibrationOfClock();
	#elif	Clock_Source==HSE 
		/*ENABLE HSE*/
		SET_BIT(RCC_CFGR,0);
		CLR_BIT(RCC_CFGR,1);
		/*HSE TYPES*/
		#if		  HSE_TYPES==HSE_RC

		SET_BIT(RCC_CR,18);
		#elif     HSE_TYPES==HSE_CRYSTAL
		CLR_BIT(RCC_CR,18);
		#endif

		/*HSEON*/
		SET_BIT(RCC_CR,16);
		/*wait for HSE to be ready*/
		while(GET_BIT(RCC_CR,17)==0);
		SET_BIT(RCC_CR,19);//CSSON
	#elif	Clock_Source==PLL
		/*ENABLE PLL*/
		CLR_BIT(RCC_CFGR,0);
		SET_BIT(RCC_CFGR,1);
		/*PLL MODES*/
			#if	PLL_MODES==PLL_HSE
		{
			SET_BIT(RCC_CFGR,16);
			#if HSE_MODE==HSE_TOTAL
			CLR_BIT(RCC_CFGR,17);
			#elif HSE_MODE==HSE_2
			SET_BIT(RCC_CFGR,17);
			#endif
		}
				/*HSEON*/
			SET_BIT(RCC_CR,16);
		#elif	PLL_MODES==PLL_HSI_2
			CLR_BIT(RCC_CFGR,16);
				/*HSION*/
			SET_BIT(RCC_CR,0);
		#endif
		/*PLL multiplication factor*/
		#if 	  PLL_multiplication_factor==PLL_input_clock_2
			RCC_CFGR|=(0<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_3 
			RCC_CFGR|=(1<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_4 
			RCC_CFGR|=(2<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_5 
			RCC_CFGR|=(3<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_6 
			RCC_CFGR|=(4<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_7 
			RCC_CFGR|=(5<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_8 
			RCC_CFGR|=(6<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_9 
			RCC_CFGR|=(7<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_10
			RCC_CFGR|=(8<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_11
			RCC_CFGR|=(9<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_12
			RCC_CFGR|=(10<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_13
			RCC_CFGR|=(11<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_14
			RCC_CFGR|=(12<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_15
			RCC_CFGR|=(13<<18);
		#elif     PLL_multiplication_factor==PLL_input_clock_16
			RCC_CFGR|=(14<<18);
		#endif
		/*PLLON*/
		SET_BIT(RCC_CR,24);
		/*wait for PLL to be ready*/
		while(GET_BIT(RCC_CR,25)==0);
	#endif
		/*	AHB*/
		RCC_CFGR|=(0<<4);
		/*	APB2*/
		RCC_CFGR|=(0<<11);
		/*	APB1*/
		RCC_CFGR|=(0<<8);
	}

void RCC_voidEnableClock(u8 Copy_u8BusID ,u8 Copy_u8PeripheralID )
{
	if(Copy_u8PeripheralID<32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR,Copy_u8PeripheralID); break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PeripheralID); break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PeripheralID); break;
		}
	}
}
void RCC_voidDisableClock(u8 Copy_u8BusID ,u8 Copy_u8PeripheralID )
{
		if(Copy_u8PeripheralID<32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR,Copy_u8PeripheralID); break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralID); break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralID); break;
		}
	}
}
void RCC_voidCalibrationOfClock(void)
{
	u8 Value=0;
	u8 Sum_HSICAL=0;
	u8 Sum_HSITRIM=16;
	u32 Sum=0;
	u8 step=0;
	Sum_HSICAL=RCC_CR>>8;
	Sum=( (Sum_HSICAL+Sum_HSITRIM) * 40000 );
	if(Sum>MAX_Number)
	{
	Sum=Sum-MAX_Number;
	step=Sum/40000;
	Sum_HSITRIM=Sum_HSITRIM-step;
	RCC_CR|=(Sum_HSITRIM<<3);	
	}
	else if(Sum<MAX_Number)
	{
	Sum=MAX_Number-Sum;
	step=Sum/40000;
	Sum_HSITRIM=Sum_HSITRIM+step;
	RCC_CR|=(Sum_HSITRIM<<3);	
	}
}
