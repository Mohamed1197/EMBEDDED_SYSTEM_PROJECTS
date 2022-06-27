/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   20/11/2020        ********************/
/**************** SWC     :    GPIO             ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

void MGPIO_voidSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Mode);

void MGPIO_voidSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value);

u8   MGPIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID );

void MGPIO_voidSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8PinType ,u8 Copy_u8Mode );

void MGPIO_voidSetPortValue(u8 Copy_u8PortID , u8 Copy_u8PinType ,u8 Copy_u8value );

void MGPIO_voidSetPortDirectionRegister(u8 Copy_u8PortID , u8 Copy_u8PinType ,u32 Copy_u32Mode );

void MGPIO_voidSetPortValueRegister(u8 Copy_u8PortID ,u16 Copy_u16value );

#define GPIO_u8_HIGH            1
#define GPIO_u8_LOW             0

#define GPIO_INPUT_ANALOG                  0b0000
#define GPIO_INPUT_FLOATING                0b0100
#define GPIO_INPUT_PULL_UP_DOWN            0b1000

#define GPIO_OUTPUT_10MHZ_PUSH_PULL        0b0001
#define GPIO_OUTPUT_10MHZ_OPEN_DRAIN       0b0101
#define GPIO_OUTPUT_10MHZ_AF_PUSH_PULL     0b1001
#define GPIO_OUTPUT_10MHZ_AF_OPEN_DRAIN    0b1101

#define GPIO_OUTPUT_2MHZ_PUSH_PULL         0b0010
#define GPIO_OUTPUT_2MHZ_OPEN_DRAIN        0b0110
#define GPIO_OUTPUT_2MHZ_AF_PUSH_PULL      0b1010
#define GPIO_OUTPUT_2MHZ_AF_OPEN_DRAIN     0b1110

#define GPIO_OUTPUT_50MHZ_PUSH_PULL        0b0011
#define GPIO_OUTPUT_50MHZ_OPEN_DRAIN       0b0111
#define GPIO_OUTPUT_50MHZ_AF_PUSH_PULL     0b1011
#define GPIO_OUTPUT_50MHZ_AF_OPEN_DRAIN    0b1111


#define GPIO_u8_PORTA               0
#define GPIO_u8_PORTB               1
#define GPIO_u8_PORTC               2

#define GPIO_u8_PIN0             0
#define GPIO_u8_PIN1             1
#define GPIO_u8_PIN2             2
#define GPIO_u8_PIN3             3
#define GPIO_u8_PIN4             4
#define GPIO_u8_PIN5             5
#define GPIO_u8_PIN6             6
#define GPIO_u8_PIN7             7
#define GPIO_u8_PIN8             8
#define GPIO_u8_PIN9             9
#define GPIO_u8_PIN10            10
#define GPIO_u8_PIN11            11
#define GPIO_u8_PIN12            12
#define GPIO_u8_PIN13            13
#define GPIO_u8_PIN14            14
#define GPIO_u8_PIN15            15

#define GPIO_u8_HIGH_PINS            1
#define GPIO_u8_LOW_PINS             0




#endif
