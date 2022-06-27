/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   31/12/2020        ********************/
/**************** SWC     :     DMA              ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DMA_Interface.h"
#include "DMA_Private.h"
#include "DMA_Config.h"

void MDMA_voidChannelInit(void)
{
	u8 ChanelNum ;
/********	  Channel Number  ********/
        #if(CHANNEL_NUMBER == CHANNEL_1)
	    {
		   ChanelNum = 0;
     	}
       #elif(CHANNEL_NUMBER == CHANNEL_2)
        {
           ChanelNum = 1;
	    }
       #elif(CHANNEL_NUMBER == CHANNEL_3)
        {
           ChanelNum = 2;
	    }
       #elif(CHANNEL_NUMBER == CHANNEL_4)
        {
           ChanelNum = 3;
	    }
       #elif(CHANNEL_NUMBER == CHANNEL_5)
        {
           ChanelNum = 4;
	    }
       #elif(CHANNEL_NUMBER == CHANNEL_6)
        {
           ChanelNum = 5;
	    }
       #elif(CHANNEL_NUMBER == CHANNEL_7)
        {
           ChanelNum = 6;
	    }
   #endif
        DMA->Channel[ChanelNum].CCR = 0x00000000;



/********  Memory to memory  ********/
#if(MEMORY_TO_MEMORY_MODE == MEMORY_TO_MEMORY_ENABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00004000);
	DMA->Channel[ChanelNum].CCR |=   (0x00004000);
}
#elif(MEMORY_TO_MEMORY_MODE == MEMORY_TO_MEMORY_DISABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000000);
	DMA->Channel[ChanelNum].CCR |=   (0x00000000);
}

#endif



/********	 Channel priority level   ********/
#if(CHANNEL_PRIORITY_LEVEL == CHANNEL_PRIORITY_LOW)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000000);
	DMA->Channel[ChanelNum].CCR |=   (0x00000000);
}
#elif(CHANNEL_PRIORITY_LEVEL == CHANNEL_PRIORITY_MEDIUM)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00001000);
	DMA->Channel[ChanelNum].CCR |=   (0x00001000);
}
#elif(CHANNEL_PRIORITY_LEVEL == CHANNEL_PRIORITY_HIGH)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00002000);
	DMA->Channel[ChanelNum].CCR |=   (0x00002000);
}
#elif(CHANNEL_PRIORITY_LEVEL == CHANNEL_PRIORITY_VERY_HIGH)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00003000);
	DMA->Channel[ChanelNum].CCR |=   (0x00003000);
}

#endif



/********		Source size = 32bit    ********/
#if(MEMORY_SIZE == MEMORY_SIZE_8_BITS)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000000);
	DMA->Channel[ChanelNum].CCR |=   (0x00000000);
}
#elif(MEMORY_SIZE == MEMORY_SIZE_16_BITS)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000400);
	DMA->Channel[ChanelNum].CCR |=   (0x00000400);
}
#elif(MEMORY_SIZE == MEMORY_SIZE_32_BITS)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000800);
	DMA->Channel[ChanelNum].CCR |=   (0x00000800);
}
#endif

/********		Destination size = 32bit    ********/
#if(PERIPHERAL_SIZE == PERIPHERAL_SIZE_8_BITS)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000000);
	DMA->Channel[ChanelNum].CCR |=   (0x00000000);
}
#elif(PERIPHERAL_SIZE == PERIPHERAL_SIZE_16_BITS)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000100);
	DMA->Channel[ChanelNum].CCR |=   (0x00000100);
}
#elif(PERIPHERAL_SIZE == PERIPHERAL_SIZE_32_BITS)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000200);
	DMA->Channel[ChanelNum].CCR |=   (0x00000200);
}
#endif



/********     Memory increment mode     ********/
#if(MEMORY_INCREMENT_MODE == MEMORY_INCREMENT_ENABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000080);
	DMA->Channel[ChanelNum].CCR |=   (0x00000080);
}
#elif(MEMORY_INCREMENT_MODE == MEMORY_INCREMENT_DISABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000000);
	DMA->Channel[ChanelNum].CCR |=   (0x00000000);
}

#endif

/********     Peripheral increment mode     ********/
#if(PERIPHERAL_INCREMENT_MODE == PERIPHERAL_INCREMENT_ENABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000040);
	DMA->Channel[ChanelNum].CCR |=   (0x00000040);
}
#elif(PERIPHERAL_INCREMENT_MODE == PERIPHERAL_INCREMENT_DISABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000000);
	DMA->Channel[ChanelNum].CCR |=   (0x00000000);
}

#endif



	/********	Circular mode *********/
#if(CIRCULAR_MODE == CIRCULAR_MODE_ENABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000020);
	DMA->Channel[ChanelNum].CCR |=   (0x00000020);
}
#elif(CIRCULAR_MODE == CIRCULAR_MODE_DISABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000000);
	DMA->Channel[ChanelNum].CCR |=   (0x00000000);
}

#endif



/******		Data transfer direction : peripheral to memory   ******/
#if(DATA_TRANSFER_DIRECTION == READ_FROM_PERIPHERAL)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000000);
	DMA->Channel[ChanelNum].CCR |=   (0x00000000);
}
#elif(DATA_TRANSFER_DIRECTION == READ_FROM_MEMORY)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000010);
	DMA->Channel[ChanelNum].CCR |=   (0x00000010);
}

#endif



/********	Transfer error interrupt enable  ********/
#if(TRANSFER_ERROR_INTERRUPT == TRANSFER_ERROR_INTERRUPT_ENABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000008);
	DMA->Channel[ChanelNum].CCR |=   (0x00000008);
}
#elif(TRANSFER_ERROR_INTERRUPT == TRANSFER_ERROR_INTERRUPT_DISABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000000);
	DMA->Channel[ChanelNum].CCR |=   (0x00000000);
}

#endif

/********	Half transfer interrupt enable  ********/
#if(HALF_TRANSFER_INTERRUPT == HALF_TRANSFER_INTERRUPT_ENABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000004);
	DMA->Channel[ChanelNum].CCR |=   (0x00000004);
}
#elif(HALF_TRANSFER_INTERRUPT == HALF_TRANSFER_INTERRUPT_DISABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000000);
	DMA->Channel[ChanelNum].CCR |=   (0x00000000);
}

#endif

/********	Transfer complete interrupt enable  ********/
#if(TRANSFER_COMPLETE_INTERRUPT == TRANSFER_COMPLETE_INTERRUPT_ENABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000002);
	DMA->Channel[ChanelNum].CCR |=   (0x00000002);
}
#elif(TRANSFER_COMPLETE_INTERRUPT == TRANSFER_COMPLETE_INTERRUPT_DISABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000000);
	DMA->Channel[ChanelNum].CCR |=   (0x00000000);
}

#endif




/********		Channel Enable ==> Channel Disabled        ********/
#if(CHANNEL_ENABLE == CHANNEL_ENABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000001);
	DMA->Channel[ChanelNum].CCR |=   (0x00000001);
}
#elif(CHANNEL_ENABLE == CHANNEL_DISABLED)
{
	DMA->Channel[ChanelNum].CCR &= ~ (0x00000000);
	DMA->Channel[ChanelNum].CCR |=   (0x00000000);
}

#endif


	// DMA->Channel[0].CCR=0x00007AC2;
}


void MDMA_voidChannelStart(u8 Copy_u8ChannelNumber , u32* Copy_pu32SourceAddress, u32* Copy_pu32DestinationAddress, u16 Copy_u16BlockLength)
{
	Copy_u8ChannelNumber = Copy_u8ChannelNumber - 1 ;
	/*Make sure channel is disabled*/
	CLR_BIT(DMA->Channel[Copy_u8ChannelNumber].CCR,0);
	/*Load the addresses*/
	DMA->Channel[Copy_u8ChannelNumber].CPAR = Copy_pu32SourceAddress;
	DMA->Channel[Copy_u8ChannelNumber].CMAR = Copy_pu32DestinationAddress;
	
	/*Load the block length*/
	DMA->Channel[Copy_u8ChannelNumber].CNDTR = Copy_u16BlockLength;
	
	SET_BIT(DMA->Channel[Copy_u8ChannelNumber].CCR,0);
}
