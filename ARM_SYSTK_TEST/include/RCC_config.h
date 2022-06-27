/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   10/11/2020        ********************/
/**************** SWC     :     RCC             ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*  Clock Source :     1- HSI
                       2- HSE
                       3- PLL   */
#define RCC_CLOCK_SOURCE      PLL

/*  External clock Source HSE Type   1- CRYSTAL
                                     2- RC      */
#define HSE_CLOCK_TYPE                  CRYSTAL									 


/*  Clock Security System :     1- CSS_ENABLE
                                2- CSS_DISABLE    */
#define CLOCK_SECURITY_SYSTEM      CSS_DISABLE


/*  Note : PPL Mode Only !  */
/*  PLL Input Clock Source :  1- HSI_DIV_2
                              2- HSE       */						
#if(RCC_CLOCK_SOURCE   ==    PLL)
#define PLL_INPUT_SOURCE         HSE
#endif


/*  Note : PPL Mode Only !  */
/*  PLL Input Clock HSE divider :  1- HSE
                                   2- HSE_DIV_2       */						
#if(RCC_CLOCK_SOURCE   ==    PLL)
#define PLL_INPUT_HSE_DIVIDER         HSE
#endif



/*  Note : PPL Mode Only !  */
/*  PLL Output Factor :      1-  PLL_MUL_2
                             2-  PLL_MUL_3
					         3-  PLL_MUL_4
					         4-  PLL_MUL_5
					         5-  PLL_MUL_6
					         6-  PLL_MUL_7
					         7-  PLL_MUL_8
					         8-  PLL_MUL_9
					         9-  PLL_MUL_10
					         10- PLL_MUL_11
					         11- PLL_MUL_12
					         12- PLL_MUL_13
					         13- PLL_MUL_14
					         14- PLL_MUL_15
					         15- PLL_MUL_16      */					   
#if(RCC_CLOCK_SOURCE   ==    PLL)
#define PLL_OUTPUT_FACTOR        PLL_MUL_2   
#endif


/* ABH prescaler Select :     1- SYSCLK 
                              2- SYSCLK_DIV_2
                              3- SYSCLK_DIV_4
                              4- SYSCLK_DIV_8
                              5- SYSCLK_DIV_16	
                              6- SYSCLK_DIV_64
                              7- SYSCLK_DIV_128
                              8- SYSCLK_DIV_256
                              9- SYSCLK_DIV_512 
                    							  */
#define AHB_PRESCALER		     SYSCLK


/* NOTE : APB1 Should not Exceed 36 Mhz  */
/* APB1 prescaler Select :    1- HCLK 
                              2- HCLK_DIV_2
                              3- HCLK_DIV_4
                              4- HCLK_DIV_8
                              5- HCLK_DIV_16	
                                              */
#define APB1_PRESCALER		     HCLK



/* APB2 prescaler Select :    1- HCLK 
                              2- HCLK_DIV_2
                              3- HCLK_DIV_4
                              4- HCLK_DIV_8
                              5- HCLK_DIV_16	
                                              */
#define APB2_PRESCALER		     HCLK					  


#endif