/*****Name     : Mohamed Ibrahim*/
/*****Date     : 10/11/2020******/
/*****Software : RCC***********/
/*****version  : 1.0**********/

/*LIB Layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*MCAL*/
#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Config.h"

void RCC_VoidInit(void)
{
	/*Clear all the reserved bits for RCC_CR*/
	
	RCC_CR = 0X00000080;
	
	/*Clear all the reserved bits for RCC_CFGR*/
	
	RCC_CFGR = 0X00000000;

	#if (CONTROL_CLK_MODE == HSI_MODE)
		
		/*enable HSI and disable HSE*/
		SET(RCC_CR,0);
		RESET(RCC_CR,16);
		while( (GET(RCC_CR,1)) == 0 );
		
		/*Choose to disable or enable PLL*/
		#if (PLL_MODE == PLL_MODE_DISABLE)
			
			/*code for disbale pll*/
			RESET(RCC_CR,24);
			
			/*select the System clock switch*/
			RESET(RCC_CFGR,1);
			RESET(RCC_CFGR,0);
			
		#elif (PLL_MODE == PLL_MODE_ENABLE)
			
			RESET(RCC_CFGR,16); //choose HSI/2
			
			/*PLL multiplication factor*/
			u32 u32MultiFactor = (PLL_FACTOR-2);
			RCC_CFGR = (RCC_CFGR | (u32MultiFactor<<18));
			
			/*enable PLL*/
			SET(RCC_CR,24);
			while( (GET(RCC_CR,25)) == 0 );
			
			/*select the System clock switch*/
			SET(RCC_CFGR,1);
			RESET(RCC_CFGR,0);
			
		#endif
		
	#elif (CONTROL_CLK_MODE == HSE_MODE)
		
		/*code for HSE*/
		CLR_BIT(RCC_CR,18);//Bypass which what i don't understand
		SET_BIT(RCC_CR,16);
		CLR_BIT(RCC_CR,0);
		while( (GET_BIT(RCC_CR,17)) == 0 );
		
		/*Choose to disable or enable PLL*/
		#if (PLL_MODE == PLL_MODE_DISABLE)
			
			/*code for disbale pll*/
			RESET(RCC_CR,24);
			
			/*select the System clock switch*/
			RESET(RCC_CFGR,1);
			SET(RCC_CFGR,0);
			
		#elif (PLL_MODE == PLL_MODE_ENABLE)
			
			/*Choose HSE_DIV_Factor*/
			#if   (HSE_FACTOR == HSE_NODIV)
				CLR_BIT(RCC_CFGR,17);
			#elif (HSE_FACTOR == HSE_DIV2)
				SET(RCC_CFGR,17);
			#endif
			
			SET_BIT(RCC_CFGR,16); //Choose HSE
			
			/*PLL multiplication factor*/
			u32 u32MultiFactor = (PLL_FACTOR-2);
			RCC_CFGR = (RCC_CFGR | (u32MultiFactor<<18));
			
			/*enable PLL*/
			SET_BIT(RCC_CR,24);
			while( (GET_BIT(RCC_CR,25)) == 0 );
			
			/*select the System clock switch*/
			SET_BIT(RCC_CFGR,1);
			CLR_BIT(RCC_CFGR,0);
			
		#endif
		
	#endif
}

void RCC_VoidEnableClock(u8 copy_u8BusID , u8 copy_u8PeripheralID)
{
	if(copy_u8PeripheralID < 32)
	{
		switch(copy_u8BusID)
		{
			case RCC_AHB : SET_BIT(RCC_AHBENR,copy_u8PeripheralID);  break;
			case RCC_APB1: SET_BIT(RCC_APB1ENR,copy_u8PeripheralID); break;
			case RCC_APB2: SET_BIT(RCC_APB2ENR,copy_u8PeripheralID); break;
		}
	}
}

void RCC_VoidDisableClock(u8 copy_u8BusID , u8 copy_u8PeripheralID)
{
	if(copy_u8PeripheralID < 32)
	{
		switch(copy_u8BusID)
		{
			case RCC_AHB : CLR_BIT(RCC_AHBENR,copy_u8PeripheralID);  break;
			case RCC_APB1: CLR_BIT(RCC_APB1ENR,copy_u8PeripheralID); break;
			case RCC_APB2: CLR_BIT(RCC_APB2ENR,copy_u8PeripheralID); break;
		}
	}
}
