/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   08/12/2020        ********************/
/**************** SWC     :     STK             ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/

#ifndef _STK_INTERFACE_H
#define _STK_INTERFACE_H

void MSTK_voidInit(void);

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_pf)(void));

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_pf)(void));

void MSTK_voidStopInterval(void);

u32 MSTK_u32GetElapsedTicks(void);

u32 MSTK_u32GetRemainingTicks(void);

void SysTick_Handler(void);

void Delay_us(u32 Copy_u32Ticks);

void Delay_ms(u32 Copy_u32Ticks);

void Delay_s(u32 Copy_u32Ticks);


#endif
