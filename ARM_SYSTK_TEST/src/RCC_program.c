/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   10/11/2020        ********************/
/**************** SWC     :     RCC             ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInit(void)
{
	/* Selecting System Clock Source */
	
#if(RCC_CLOCK_SOURCE == HSI)
{  
    CLR_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);
	
	/* Turn On HSI */
	SET_BIT(RCC_CR,0);
	
	/* Polling on HSI clock ready flag */
	while(!(GET_BIT(RCC_CR,1)));
}
#elif(RCC_CLOCK_SOURCE == HSE)
{
	SET_BIT(RCC_CFGR,0);
	CLR_BIT(RCC_CFGR,1);
	
	/* External Clock HSE Type */
	#if(HSE_CLOCK_TYPE == CRYSTAL)
	{
		CLR_BIT(RCC_CR,18);
	}
	#elif(HSE_CLOCK_TYPE == RC)
	{
		SET_BIT(RCC_CR,18);
	}
	#endif
	
	/* Clock Security System  */
	#if(CLOCK_SECURITY_SYSTEM == CSS_ENABLE)
	{
		SET_BIT(RCC_CR,19);
	}
	#elif(CLOCK_SECURITY_SYSTEM == CSS_DISABLE)
	{
		CLR_BIT(RCC_CR,19);
	}
	#endif
    
	/* Turn On HSE */
	SET_BIT(RCC_CR,16);
    
	/* Polling on HSE clock ready flag */
	while(!(GET_BIT(RCC_CR,17)));
}
#elif(RCC_CLOCK_SOURCE == PLL)
{
	CLR_BIT(RCC_CFGR,0);
	SET_BIT(RCC_CFGR,1);
	
	/* PLL Input Clock Source Select */
	#if(PLL_INPUT_SOURCE == HSI_DIV_2)
	{
		CLR_BIT(RCC_CFGR,16);
		
		/* Turn On HSI */
		SET_BIT(RCC_CR,0);
	}
	#elif(PLL_INPUT_SOURCE == HSE)
	{
		SET_BIT(RCC_CFGR,16);
		
		/* PLL Input Clock Source HSE Divider */
		#if(PLL_INPUT_HSE_DIVIDER == HSE)
		{
			CLR_BIT(RCC_CFGR,17);
		}
		#elif(PLL_INPUT_HSE_DIVIDER == HSE_DIV_2)
		{
			SET_BIT(RCC_CFGR,17);
		}
		#endif
		
		/* Turn On HSE */
		SET_BIT(RCC_CR,16);
	}
	#endif
	
	/* PLL Ouput Multiplication Factor */
	#if(PLL_OUTPUT_FACTOR == PLL_MUL_2)
	{
		RCC_CFGR |= (0<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_3)
	{
		RCC_CFGR |= (1<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_4)
	{
		RCC_CFGR |= (2<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_5)
	{
		RCC_CFGR |= (3<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_6)
	{
		RCC_CFGR |= (4<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_7)
	{
		RCC_CFGR |= (5<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_8)
	{
		RCC_CFGR |= (6<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_9)
	{
		RCC_CFGR |= (7<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_10)
	{
		RCC_CFGR |= (8<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_11)
	{
		RCC_CFGR |= (9<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_12)
	{
		RCC_CFGR |= (10<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_13)
	{
		RCC_CFGR |= (11<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_14)
	{
		RCC_CFGR |= (12<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_15)
	{
		RCC_CFGR |= (13<<18);
	}
	#elif(PLL_OUTPUT_FACTOR == PLL_MUL_16)
	{
		RCC_CFGR |= (14<<18);
	}
	#endif
	
	/* Turn On PLL */
    SET_BIT(RCC_CR,24);
	
	/* Polling on PLL clock ready flag */	
	while(!(GET_BIT(RCC_CR,25)));
}
#else
    #error("Wrong Clock Source Choice !")	
#endif	

#if(AHB_PRESCALER == SYSCLK)
{
	CLR_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_2)
{
	CLR_BIT(RCC_CFGR,4);
	CLR_BIT(RCC_CFGR,5);
	CLR_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_4)
{
	SET_BIT(RCC_CFGR,4);
	CLR_BIT(RCC_CFGR,5);
	CLR_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_8)
{
	CLR_BIT(RCC_CFGR,4);
	SET_BIT(RCC_CFGR,5);
	CLR_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_16)
{
	SET_BIT(RCC_CFGR,4);
	SET_BIT(RCC_CFGR,5);
	CLR_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_64)
{
	CLR_BIT(RCC_CFGR,4);
	CLR_BIT(RCC_CFGR,5);
	SET_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_128)
{
	SET_BIT(RCC_CFGR,4);
	CLR_BIT(RCC_CFGR,5);
	SET_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_256)
{
	CLR_BIT(RCC_CFGR,4);
	SET_BIT(RCC_CFGR,5);
	SET_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#elif(AHB_PRESCALER == SYSCLK_DIV_512)
{
	SET_BIT(RCC_CFGR,4);
	SET_BIT(RCC_CFGR,5);
	SET_BIT(RCC_CFGR,6);
	SET_BIT(RCC_CFGR,7);
}
#endif

#if(APB1_PRESCALER == HCLK)
{
	CLR_BIT(RCC_CFGR,10);
	
}
#elif(APB1_PRESCALER == HCLK_DIV_2)
{                    
	CLR_BIT(RCC_CFGR,8);
    CLR_BIT(RCC_CFGR,9);
    SET_BIT(RCC_CFGR,10);	
}                    
#elif(APB1_PRESCALER == HCLK_DIV_4)
{                      
	SET_BIT(RCC_CFGR,8);
    CLR_BIT(RCC_CFGR,9);
    SET_BIT(RCC_CFGR,10);					   
}                      
#elif(APB1_PRESCALER == HCLK_DIV_8)
{                      
	CLR_BIT(RCC_CFGR,8);
    SET_BIT(RCC_CFGR,9);
    SET_BIT(RCC_CFGR,10);					   
}                      
#elif(APB1_PRESCALER == HCLK_DIV_16)
{
	SET_BIT(RCC_CFGR,8);
    SET_BIT(RCC_CFGR,9);
    SET_BIT(RCC_CFGR,10);
}
#endif

#if(APB2_PRESCALER == HCLK)
{
	CLR_BIT(RCC_CFGR,13);
}
#elif(APB2_PRESCALER == HCLK_DIV_2)
{                    
	CLR_BIT(RCC_CFGR,11);
    CLR_BIT(RCC_CFGR,12);
    SET_BIT(RCC_CFGR,13);				 
}                    
#elif(APB2_PRESCALER == HCLK_DIV_4)
{                      
	SET_BIT(RCC_CFGR,11);
    CLR_BIT(RCC_CFGR,12);
    SET_BIT(RCC_CFGR,13);				   
}                      
#elif(APB2_PRESCALER == HCLK_DIV_8)
{                      
	CLR_BIT(RCC_CFGR,11);
    SET_BIT(RCC_CFGR,12);
    SET_BIT(RCC_CFGR,13);				   
}                      
#elif(APB2_PRESCALER == HCLK_DIV_16)
{
	SET_BIT(RCC_CFGR,11);
    SET_BIT(RCC_CFGR,12);
    SET_BIT(RCC_CFGR,13);
}
#endif

}

void MRCC_voidEnableClock(u8 Copy_u8BusID ,u8 Copy_u8PeriferalID )
{
	if(Copy_u8PeriferalID < 32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR , Copy_u8PeriferalID);  break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR , Copy_u8PeriferalID); break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR , Copy_u8PeriferalID); break;
		}
	}
}

void MRCC_voidDisableClock(u8 Copy_u8BusID ,u8 Copy_u8PeriferalID )
{
		if(Copy_u8PeriferalID < 32)
	{
		switch(Copy_u8BusID)
		{
			case RCC_AHB  : CLR_BIT(RCC_AHBENR , Copy_u8PeriferalID);  break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR , Copy_u8PeriferalID); break;
			case RCC_APB2 : CLR_BIT(RCC_APB2ENR , Copy_u8PeriferalID); break;
		}
	}
}