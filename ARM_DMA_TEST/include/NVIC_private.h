/**************************************************/
/**************************************************/
#ifndef		NVIC_PRIVATE_H
#define		NVIC_PRIVATE_H

/******      NVIC Registers Definition       ******/
#define			NVIC_BASE_ADD		(0xE000E100)

#define			NVIC_ISER0			*((volatile u32 * )(NVIC_BASE_ADD +0x000))
#define			NVIC_ISER1			*((volatile u32 * )(NVIC_BASE_ADD +0x004))

#define			NVIC_ICER0			*((volatile u32 * )(NVIC_BASE_ADD +0x080))
#define			NVIC_ICER1			*((volatile u32 * )(NVIC_BASE_ADD +0x084))

#define			NVIC_ISPR0			*((volatile u32 * )(NVIC_BASE_ADD +0x100))
#define			NVIC_ISPR1			*((volatile u32 * )(NVIC_BASE_ADD +0x104))

#define			NVIC_ICPR0			*((volatile u32 * )(NVIC_BASE_ADD +0x180))
#define			NVIC_ICPR1			*((volatile u32 * )(NVIC_BASE_ADD +0x184))

#define			NVIC_IABR0			*((volatile u32 * )(NVIC_BASE_ADD +0x200))
#define			NVIC_IABR1			*((volatile u32 * )(NVIC_BASE_ADD +0x204))

#define			NVIC_IPR 			 ((volatile u8  * )(NVIC_BASE_ADD +0x400))


/********    NVIC Number of Group and Sub-group      ********/
#define       GROUP_16_SUB_0    0XFA050300
#define       GROUP_8_SUB_2     0XFA050400
#define       GROUP_4_SUB_4     0XFA050500
#define       GROUP_2_SUB_8     0XFA050600
#define       GROUP_0_SUB_16    0XFA050700

#endif
