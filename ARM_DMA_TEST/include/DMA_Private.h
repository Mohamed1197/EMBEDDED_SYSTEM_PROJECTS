/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   31/12/2020        ********************/
/**************** SWC     :     DMA              ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
/*Preprocessor File Guard*/
#ifndef DMA_REG_H_
#define DMA_REG_H_

typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 Reserved;
}DMA_Channel;

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA_Channel Channel[7];
}DMA_t;

#define DMA	((volatile DMA_t*)0x40020000)

/* DMA Config Macros  */
#define MEMORY_TO_MEMORY_ENABLED                 0
#define MEMORY_TO_MEMORY_DISABLED                1
#define CHANNEL_PRIORITY_LOW                     2
#define CHANNEL_PRIORITY_MEDIUM                  3
#define CHANNEL_PRIORITY_HIGH                    4
#define CHANNEL_PRIORITY_VERY_HIGH               5
#define MEMORY_SIZE_8_BITS                       6
#define MEMORY_SIZE_16_BITS                      7
#define MEMORY_SIZE_32_BITS                      8
#define PERIPHERAL_SIZE_8_BITS                   9
#define PERIPHERAL_SIZE_16_BITS                  10
#define PERIPHERAL_SIZE_32_BITS                  11
#define MEMORY_INCREMENT_ENABLED                 12
#define MEMORY_INCREMENT_DISABLED                13
#define PERIPHERAL_INCREMENT_ENABLED             14
#define PERIPHERAL_INCREMENT_DISABLED            15
#define CIRCULAR_MODE_ENABLED                    16
#define CIRCULAR_MODE_DISABLED                   17
#define READ_FROM_PERIPHERAL                     18
#define READ_FROM_MEMORY                         19
#define TRANSFER_ERROR_INTERRUPT_ENABLED         20
#define TRANSFER_ERROR_INTERRUPT_DISABLED        21
#define HALF_TRANSFER_INTERRUPT_ENABLED          22
#define HALF_TRANSFER_INTERRUPT_DISABLED         23
#define TRANSFER_COMPLETE_INTERRUPT_ENABLED      24
#define TRANSFER_COMPLETE_INTERRUPT_DISABLED     25
#define CHANNEL_ENABLED                          26
#define CHANNEL_DISABLED                         27
#define CHANNEL_1                                28
#define CHANNEL_2                                29
#define CHANNEL_3                                30
#define CHANNEL_4                                31
#define CHANNEL_5                                32
#define CHANNEL_6                                33
#define CHANNEL_7                                34




#endif
