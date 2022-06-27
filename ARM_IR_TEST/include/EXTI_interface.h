#ifndef		_EXTI_INTERFACE_H
#define		_EXTI_INTERFACE_H

/*******   EXTI Edge Detect Selection    *******/
#define		EXTI_FALLING		1
#define		EXTI_RISING			3
#define		EXTI_IOC			5

/*******   EXTI Input Line Selection     *******/
#define		EXTI_u8_LINE0			0
#define		EXTI_u8_LINE1			1
#define		EXTI_u8_LINE2			2
#define		EXTI_u8_LINE3			3
#define		EXTI_u8_LINE4			4
#define		EXTI_u8_LINE5			5
#define		EXTI_u8_LINE6			6
#define		EXTI_u8_LINE7			7
#define		EXTI_u8_LINE8			8
#define		EXTI_u8_LINE9			9
#define		EXTI_u8_LINE10			10
#define		EXTI_u8_LINE11			11
#define		EXTI_u8_LINE12			12
#define		EXTI_u8_LINE13			13
#define		EXTI_u8_LINE14			14
#define		EXTI_u8_LINE15			15

	
void MEXTI_voidInit(void);

void MEXTI_voidSetSignalLatch(u8 Copy_u8LineID , u8 Copy_u8SenseMode);

void MEXTI_voidEnable(u8 Copy_u8LineID);

void MEXTI_voidDisable(u8 Copy_u8LineID);

void MEXTI_voidSetSotwareTrigger(u8 Copy_u8LineID);

void MEXTI_voidSetCallBack( void (*pf) (void) , u8 Copy_u8EXTI_ID);


#endif
