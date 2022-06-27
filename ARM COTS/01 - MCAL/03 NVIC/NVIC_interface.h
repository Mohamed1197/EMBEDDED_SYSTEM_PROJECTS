



void MNVIC_voidInit(void);
u8 MNVIC_u8SetInterrruptPriority(/*Arguments*/ u8 Copy_u8PrephiralID , u8 Copy_u8Grouppriority , u8 Copy_u8Subpriority);

u8	MNVIC_u8EnableInterrupt	(u8 Copy_u8IntNumber);
u8	MNVIC_u8DisableInterrupt(u8 Copy_u8IntNumber);

u8	MNVIC_u8SetPendingFlag	(u8 Copy_u8IntNumber);
u8	MNVIC_u8ClearPendingFlag(u8 Copy_u8IntNumber);

u8	MNVIC_u8GetActiveFlag	(u8 Copy_u8IntNumber);



/******   Vector Table ISR Interrupt ID  *****/
#define NVIC_VEC_T_WWDG                  0
#define NVIC_VEC_T_PVD                   1
#define NVIC_VEC_T_TAMPER                2
#define NVIC_VEC_T_RTC                   3
#define NVIC_VEC_T_FLASH                 4
#define NVIC_VEC_T_RCC                   5
#define NVIC_VEC_T_EXTI0                 6
#define NVIC_VEC_T_EXTI1                 7
#define NVIC_VEC_T_EXTI2                 8
#define NVIC_VEC_T_EXTI3                 9
#define NVIC_VEC_T_EXTI4                 10
#define NVIC_VEC_T_DMA1_Channel1         11
#define NVIC_VEC_T_DMA1_Channel2         12
#define NVIC_VEC_T_DMA1_Channel3         13
#define NVIC_VEC_T_DMA1_Channel4         14
#define NVIC_VEC_T_DMA1_Channel5         15
#define NVIC_VEC_T_DMA1_Channel6         16
#define NVIC_VEC_T_DMA1_Channel7         17
#define NVIC_VEC_T_ADC1_2                18
#define NVIC_VEC_T_USB_HP_CAN_TX         19
#define NVIC_VEC_T_USB_LP_CAN_RX0        20
#define NVIC_VEC_T_CAN_RX1               21
#define NVIC_VEC_T_CAN_SCE               22
#define NVIC_VEC_T_EXTI9_5               23
#define NVIC_VEC_T_TIM1_BRK              24
#define NVIC_VEC_T_TIM1_UP               25
#define NVIC_VEC_T_TIM1_TRG_COM          26
#define NVIC_VEC_T_TIM1_CC               27
#define NVIC_VEC_T_TIM2                  28
#define NVIC_VEC_T_TIM3                  29
#define NVIC_VEC_T_TIM4                  30
#define NVIC_VEC_T_I2C1_EV               31
#define NVIC_VEC_T_I2C1_ER               32
#define NVIC_VEC_T_I2C2_EV               33
#define NVIC_VEC_T_I2C2_ER               34
#define NVIC_VEC_T_SPI1                  35
#define NVIC_VEC_T_SPI2                  36
#define NVIC_VEC_T_USART1                37
#define NVIC_VEC_T_USART2                38
#define NVIC_VEC_T_USART3                39
#define NVIC_VEC_T_EXTI15_10             40
#define NVIC_VEC_T_RTCAlarm              41
#define NVIC_VEC_T_USBWakeup             42
#define NVIC_VEC_T_TIM8_BRK              43
#define NVIC_VEC_T_TIM8_UP               44
#define NVIC_VEC_T_TIM8_TRG_COM          45
#define NVIC_VEC_T_TIM8_CC               46
#define NVIC_VEC_T_ADC3                  47
#define NVIC_VEC_T_FSMC                  48
#define NVIC_VEC_T_SDIO                  49
#define NVIC_VEC_T_TIM5                  50
#define NVIC_VEC_T_SPI3                  51
#define NVIC_VEC_T_UART4                 52
#define NVIC_VEC_T_UART5                 53
#define NVIC_VEC_T_TIM6                  54
#define NVIC_VEC_T_TIM7                  55
#define NVIC_VEC_T_DMA2_Channel1         56
#define NVIC_VEC_T_DMA2_Channel2         57
#define NVIC_VEC_T_DMA2_Channel3         58
#define NVIC_VEC_T_DMA2_Channel4_5       59


