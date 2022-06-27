/*****Name     : Mohamed Ibrahim*/
/*****Date     : 10/11/2020******/
/*****Software : RCC***********/
/*****version  : 1.0**********/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define RCC_CR                *((volatile u32*)0x40021000)
#define RCC_CFGR              *((volatile u32*)0x40021004)
#define RCC_CIR               *((volatile u32*)0x40021008)
#define RCC_APB2RSTR          *((volatile u32*)0x4002100C)
#define RCC_APB1RSTR          *((volatile u32*)0x40021010)
#define RCC_AHBENR            *((volatile u32*)0x40021014)
#define RCC_APB2ENR           *((volatile u32*)0x40021018)
#define RCC_APB1ENR           *((volatile u32*)0x4002100C)
#define RCC_BDCR              *((volatile u32*)0x40021020)
#define RCC_CSR               *((volatile u32*)0x40021024)


/*MACROS FOR CONTROL_CLK_MODE*/
#define HSI_MODE                               0
#define HSE_MODE                               1

/*MACROS FOR PLL_MODE*/
#define PLL_MODE_ENABLE                        2
#define PLL_MODE_DISABLE                       3

/*MACROS FOR HSE_Factor*/
#define HSE_NODIV                              0
#define HSE_DIV2                               1

#endif
