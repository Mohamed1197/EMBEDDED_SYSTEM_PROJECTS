/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   31/12/2020        ********************/
/**************** SWC     :     DMA              ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/

#ifndef DMA_CONFIG_H_
#define DMA_CONFIG_H_

/*************      Memory to Memory Mode      *************/
/*                               1 - MEMORY_TO_MEMORY_ENABLED
                                 2 - MEMORY_TO_MEMORY_DISABLED   */
#define MEMORY_TO_MEMORY_MODE        MEMORY_TO_MEMORY_ENABLED


/*************      Channel priority level      *************/
/*                               1 - CHANNEL_PRIORITY_LOW
                                 2 - CHANNEL_PRIORITY_MEDIUM
                                 3 - CHANNEL_PRIORITY_HIGH
                                 4 - CHANNEL_PRIORITY_VERY_HIGH   */
#define CHANNEL_PRIORITY_LEVEL       CHANNEL_PRIORITY_VERY_HIGH


/*************         Memory size Bits         *************/
/*                               1 - MEMORY_SIZE_8_BITS
                                 2 - MEMORY_SIZE_16_BITS
                                 3 - MEMORY_SIZE_32_BITS   */
#define MEMORY_SIZE                  MEMORY_SIZE_32_BITS


/*************      Peripheral size Bits        *************/
/*                               1 - PERIPHERAL_SIZE_8_BITS
                                 2 - PERIPHERAL_SIZE_16_BITS
                                 3 - PERIPHERAL_SIZE_32_BITS  */
#define PERIPHERAL_SIZE              PERIPHERAL_SIZE_32_BITS


/*************      Memory increment mode      *************/
/*                               1 - MEMORY_INCREMENT_ENABLED
                                 2 - MEMORY_INCREMENT_DISABLED  */
#define MEMORY_INCREMENT_MODE        MEMORY_INCREMENT_ENABLED


/*************     Peripheral increment mode     *************/
/*                                   1 - PERIPHERAL_INCREMENT_ENABLED
                                     2 - PERIPHERAL_INCREMENT_DISABLED  */
#define PERIPHERAL_INCREMENT_MODE        PERIPHERAL_INCREMENT_ENABLED


/*************     Circular mode     *************/
/*                               1 - CIRCULAR_MODE_ENABLED
                                 2 - CIRCULAR_MODE_DISABLED  */
#define CIRCULAR_MODE                CIRCULAR_MODE_DISABLED



/*************     Data transfer direction     *************/
/*                                  1 - READ_FROM_PERIPHERAL
                                    2 - READ_FROM_MEMORY  */
#define DATA_TRANSFER_DIRECTION         READ_FROM_PERIPHERAL



/*************     Transfer error interrupt enable     *************/
/*                                 1 - TRANSFER_ERROR_INTERRUPT_ENABLED
                                   2 - TRANSFER_ERROR_INTERRUPT_DISABLED  */
#define TRANSFER_ERROR_INTERRUPT       TRANSFER_ERROR_INTERRUPT_DISABLED



/*************     Half transfer interrupt enable     *************/
/*                                  1 - HALF_TRANSFER_INTERRUPT_ENABLED
                                    2 - HALF_TRANSFER_INTERRUPT_DISABLED  */
#define HALF_TRANSFER_INTERRUPT         HALF_TRANSFER_INTERRUPT_DISABLED



/*************     Transfer complete interrupt enable     *************/
/*                                     1 - TRANSFER_COMPLETE_INTERRUPT_ENABLED
                                       2 - TRANSFER_COMPLETE_INTERRUPT_DISABLED  */
#define TRANSFER_COMPLETE_INTERRUPT        TRANSFER_COMPLETE_INTERRUPT_ENABLED



/*************      Channel enable     *************/
/*                               1 - CHANNEL_ENABLED
                                 2 - CHANNEL_DISABLED   */
#define CHANNEL_ENABLE               CHANNEL_DISABLED

/*************      DMA Channel Number     *************/
/*                               1 - CHANNEL_1
                                 2 - CHANNEL_2
                                 3 - CHANNEL_3
                                 4 - CHANNEL_4
                                 5 - CHANNEL_5
                                 6 - CHANNEL_6
                                 7 - CHANNEL_7   */
#define CHANNEL_NUMBER               CHANNEL_1







#endif
