/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   10/11/2020        ********************/
/**************** SWC     :     RCC             ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


#define RCC_CR                  *((volatile u32 * )0x40021000)
#define RCC_CFGR                *((volatile u32 * )0x40021004)
#define RCC_CIR                 *((volatile u32 * )0x40021008)
#define RCC_APB2RSTR            *((volatile u32 * )0x4002100C)
#define RCC_APB1RSTR            *((volatile u32 * )0x40021010)
#define RCC_AHBENR              *((volatile u32 * )0x40021014)
#define RCC_APB2ENR             *((volatile u32 * )0x40021018)
#define RCC_APB1ENR             *((volatile u32 * )0x4002101C)
#define RCC_BDCR                *((volatile u32 * )0x40021020)
#define RCC_CSR                 *((volatile u32 * )0x40021024)

#define    HSI             0
#define    HSE             1
#define    PLL             2
#define    CRYSTAL         3
#define    RC              4
#define    CSS_ENABLE      5
#define    CSS_DISABLE     6
#define    HSI_DIV_2       7
#define    HSE_DIV_2       8
#define    PLL_MUL_2       9
#define    PLL_MUL_3       10
#define    PLL_MUL_4       11
#define    PLL_MUL_5       12
#define    PLL_MUL_6       13
#define    PLL_MUL_7       14
#define    PLL_MUL_8       15
#define    PLL_MUL_9       16
#define    PLL_MUL_10      17
#define    PLL_MUL_11      18
#define    PLL_MUL_12      19
#define    PLL_MUL_13      20
#define    PLL_MUL_14      21
#define    PLL_MUL_15      22
#define    PLL_MUL_16      23

#define     SYSCLK              0
#define	    SYSCLK_DIV_2        1
#define		SYSCLK_DIV_4        2
#define     SYSCLK_DIV_8        3
#define     SYSCLK_DIV_16	    4
#define     SYSCLK_DIV_64       5
#define     SYSCLK_DIV_128      6
#define     SYSCLK_DIV_256      7
#define     SYSCLK_DIV_512      8

#define     HCLK                0
#define     HCLK_DIV_2          1
#define     HCLK_DIV_4          2
#define     HCLK_DIV_8          3
#define     HCLK_DIV_16         4


#endif  