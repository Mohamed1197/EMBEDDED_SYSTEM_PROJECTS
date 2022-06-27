#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"


#include "RTO_interface.h"

void App_voidTask1(void);
void App_voidTask2(void);
void App_voidTask3(void);

int main(void)
{
	DIO_u8Init();
	/* Create Tasks */
	RTO_u8CreateTask(0,1000,0,&App_voidTask1);
	RTO_u8CreateTask(1,2000,0,&App_voidTask2);
	RTO_u8CreateTask(2,5000,0,&App_voidTask3);


	RTO_voidInit();

	while(1);

	return 0;

}

void App_voidTask1(void)
{
	static u8 flag = 0;
	if(flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
		flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
		flag = 0;
	}
}

void App_voidTask2(void)
{
	static u8 flag = 0;
	if(flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
		flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_LOW);
		flag = 0;
	}
}

void App_voidTask3(void)
{
	static u8 flag = 0;
	if(flag == 0)
	{
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
		flag = 1;
	}
	else
	{
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_LOW);
		flag = 0;
	}
}
