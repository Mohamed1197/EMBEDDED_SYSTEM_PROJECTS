/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   10/11/2020        ********************/
/**************** SWC     :     RCC             ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB           1
#define RCC_APB1          3
#define RCC_APB2          6

#define RCC_AHB_DMA1EN        0
#define RCC_AHB_DMA2EN        1
#define RCC_AHB_SRAMEN        2
#define RCC_AHB_FLITFEN       4
#define RCC_AHB_CRCEN         6
#define RCC_AHB_FSMCEN        8
#define RCC_AHB_SDIOEN        10

#define RCC_APB1_TIM2EN          0
#define RCC_APB1_TIM3EN          1
#define RCC_APB1_TIM4EN          2
#define RCC_APB1_TIM5EN          3
#define RCC_APB1_TIM6EN          4
#define RCC_APB1_TIM7EN          5
#define RCC_APB1_TIM12EN         6
#define RCC_APB1_TIM13EN         7
#define RCC_APB1_TIM14EN         8
#define RCC_APB1_WWDGEN          11
#define RCC_APB1_SPI2EN          14
#define RCC_APB1_SPI3EN          15
#define RCC_APB1_USART2EN        17
#define RCC_APB1_USART3EN        18
#define RCC_APB1_USART4EN        19
#define RCC_APB1_USART5EN        20
#define RCC_APB1_I2C1EN          21
#define RCC_APB1_I2C2EN          22
#define RCC_APB1_USBEN           23
#define RCC_APB1_CANEN           25
#define RCC_APB1_BKPEN           27
#define RCC_APB1_PWREN           28
#define RCC_APB1_DACEN           29

#define RCC_APB2_AFIOEN          0
#define RCC_APB2_GPIOAEN         2
#define RCC_APB2_GPIOBEN         3
#define RCC_APB2_GPIOCEN         4
#define RCC_APB2_ADC1EN          9
#define RCC_APB2_ADC2EN          10
#define RCC_APB2_TIM1EN          11
#define RCC_APB2_SPI1EN          12
#define RCC_APB2_TIM8EN          13
#define RCC_APB2_USART1EN        14
#define RCC_APB2_ADC3EN          15
#define RCC_APB2_TIM9EN          19
#define RCC_APB2_TIM10EN         20
#define RCC_APB2_TIM11EN         21





void MRCC_voidInit(void);

void MRCC_voidEnableClock(u8 Copy_u8BusID ,u8 Copy_u8PeriferalID );

void MRCC_voidDisableClock(u8 Copy_u8BusID ,u8 Copy_u8PeriferalID );


#endif