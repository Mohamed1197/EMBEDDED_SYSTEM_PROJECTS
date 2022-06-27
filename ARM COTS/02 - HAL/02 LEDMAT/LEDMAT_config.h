/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   13/12/2020        ********************/
/**************** SWC     :     LEDMAT          ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/

#ifndef		_LEDMAT_CONFIG_H
#define		_LEDMAT_CONFIG_H

/*******  Configure LED Matrix ROW PORT   *********/
#define     HLEDMAT_u8_ROW_PORT     GPIO_u8_PORTA , GPIO_u8_LOW_PINS

#define		HLEDMAT_U8_ROW_0		GPIO_u8_PORTA , GPIO_u8_PIN0
#define		HLEDMAT_U8_ROW_1		GPIO_u8_PORTA , GPIO_u8_PIN1
#define		HLEDMAT_U8_ROW_2		GPIO_u8_PORTA , GPIO_u8_PIN2
#define		HLEDMAT_U8_ROW_3		GPIO_u8_PORTA , GPIO_u8_PIN3
#define		HLEDMAT_U8_ROW_4		GPIO_u8_PORTA , GPIO_u8_PIN4
#define		HLEDMAT_U8_ROW_5		GPIO_u8_PORTA , GPIO_u8_PIN5
#define		HLEDMAT_U8_ROW_6		GPIO_u8_PORTA , GPIO_u8_PIN6
#define		HLEDMAT_U8_ROW_7		GPIO_u8_PORTA , GPIO_u8_PIN7

/*******  Configure LED Matrix COLUMN PORT   *********/
#define     HLEDMAT_u8_COL_PORT     GPIO_u8_PORTB , GPIO_u8_HIGH_PINS

#define		HLEDMAT_U8_COL_0		GPIO_u8_PORTB , GPIO_u8_PIN8
#define		HLEDMAT_U8_COL_1		GPIO_u8_PORTB , GPIO_u8_PIN9
#define		HLEDMAT_U8_COL_2		GPIO_u8_PORTB , GPIO_u8_PIN10
#define		HLEDMAT_U8_COL_3		GPIO_u8_PORTB , GPIO_u8_PIN11
#define		HLEDMAT_U8_COL_4		GPIO_u8_PORTB , GPIO_u8_PIN12
#define		HLEDMAT_U8_COL_5		GPIO_u8_PORTB , GPIO_u8_PIN13
#define		HLEDMAT_U8_COL_6		GPIO_u8_PORTB , GPIO_u8_PIN14
#define		HLEDMAT_U8_COL_7		GPIO_u8_PORTB , GPIO_u8_PIN15


#endif
