/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _RCC_MACROS_H_
#define   _RCC_MACROS_H_


#define     HSE_FLAG_NOT_READY      ( (GET_BIT(RCC->CR,17)) != 1 )
#define     HSI_FLAG_NOT_READY      ( (GET_BIT(RCC->CR,1))  != 1 )
#define     PLL_FLAG_NOT_READY      ( (GET_BIT(RCC->CR,25)) != 1 )
#define     MAX_HSI                     8000000
#define     STEP_SIZE                   40000

/*****************************AMBA BUSES************************/
#define     RCC_AHB                     0
#define     RCC_APB1                    1
#define     RCC_APB2                    2
/****************************************************************/

/***************************Peripheral Clock Enable For APB1 Bus********************/
                           #define    TIM2_RCC         0
                           #define    TIM3_RCC         1
                           #define    TIM4_RCC         2
                           #define    TIM5_RCC         3
                           #define    TIM6_RCC         4
                           #define    TIM7_RCC         5
                           #define    TIM12_RCC        6
                           #define    TIM13_RCC        7
                           #define    TIM14_RCC        8
                           #define    WWDG_RCC         11
                           #define    SPI2_RCC         14
                           #define    SPI3_RCC         15
                           #define    USART2_RCC       17
                           #define    USART3_RCC       18
                           #define    UART4_RCC        19
                           #define    UART5_RCC        20
                           #define    I2C1_RCC         21
                           #define    I2C2_RCC         22
                           #define    USB_RCC          23
                           #define    CAN_RCC          25
                           #define    BKP_RCC          27
                           #define    PWR_RCC          28
                           #define    DAC_RCC          29
/***********************************************************************************/

/***************************Peripheral Clock Enable For APB2 Bus********************/
                            #define    AFIO_RCC         0
                            #define    GPIOA_RCC        2
                            #define    GPIOB_RCC        3
                            #define    GPIOC_RCC        4
                            #define    GPIOD_RCC        5
                            #define    GPIOE_RCC        6
                            #define    GPIOF_RCC        7
                            #define    GPIOG_RCC        8
                            #define    ADC1_RCC         9
                            #define    ADC2_RCC         10
                            #define    TIM1_RCC         11
                            #define    SPI1_RCC         12
                            #define    TIM8_RCC         13
                            #define    USART1_RCC       14
                            #define    ADC3_RCC         15
                            #define    TIM9_RCC         19
                            #define    TIM10_RCC        20
                            #define    TIM11_RCC        21
/************************************************************************************/
/***************************Peripheral Clock Enable For AHB Bus*********************/
                            #define    DMA1_RCC         0
                            #define    DMA2_RCC         1
                            #define    SRAM_RCC         2
                            #define    FLITF_RCC        4
                            #define    CRC_RCC          6
                            #define    FSMC_RCC         8
                            #define    SDIO_RCC         10             
/************************************************************************************/



















#endif
