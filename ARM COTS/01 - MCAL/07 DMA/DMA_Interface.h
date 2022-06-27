/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   31/12/2020        ********************/
/**************** SWC     :     DMA              ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
/*Preprocessor File Guard*/
#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#define DMA_CHANNEL_1       1
#define DMA_CHANNEL_2       2
#define DMA_CHANNEL_3       3
#define DMA_CHANNEL_4       4
#define DMA_CHANNEL_5       5
#define DMA_CHANNEL_6       6
#define DMA_CHANNEL_7       7



void MDMA_voidChannelInit(void);


void MDMA_voidChannelStart(u8 Copy_u8ChannelNumber , u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);


#endif
