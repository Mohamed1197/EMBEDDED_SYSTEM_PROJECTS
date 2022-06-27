#ifndef		_EXTI_PRIVATE_H
#define		_EXTI_PRIVATE_H

typedef struct
{
	volatile u32 IMR ;
	volatile u32 EMR ;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR ;
}EXTI_type;

#define		EXTI		((volatile EXTI_type *)0x40010400)


#endif
