#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LCD_interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

void App_voidTask1(void * Copy_pv);
void App_voidTask2(void * Copy_pv);
void App_voidTask3(void * Copy_pv);

void App_voidLCD1(void * Copy_pv);
void App_voidLCD2(void * Copy_pv);


#define TASK1_u8_PRIORITY         1
#define TASK2_u8_PRIORITY         2
#define TASK3_u8_PRIORITY         3

/* Create Global Varible of Semaphore Type */
xSemaphoreHandle App_LCDSemph;

int main(void)
{
	DIO_u8Init();

	LCD_voidInit();
/* Create Tasks */
//	xTaskCreate(&App_voidTask1,NULL,200,NULL,TASK1_u8_PRIORITY,NULL);
//	xTaskCreate(&App_voidTask2,NULL,200,NULL,TASK2_u8_PRIORITY,NULL);
//	xTaskCreate(&App_voidTask3,NULL,200,NULL,TASK3_u8_PRIORITY,NULL);
	xTaskCreate(&App_voidLCD1,NULL,200,NULL,2,NULL);
	xTaskCreate(&App_voidLCD2,NULL,200,NULL,2,NULL);


	/* Create Semaphore */
	vSemaphoreCreateBinary(App_LCDSemph);

	/* Start Scheduler */
	vTaskStartScheduler();
	return 0;
}

void App_voidTask1(void * Copy_pv)
{
	static u8 flag = 0;
	while(1)
	{

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
		vTaskDelay(1000);
	}
}

void App_voidTask2(void * Copy_pv)
{
	static u8 flag = 0;
	while(1)
	{

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
		vTaskDelay(2000);
	}
}

void App_voidTask3(void * Copy_pv)
{
	static u8 flag = 0;
	while(1)
	{

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
		vTaskDelay(5000);
	}
}

void App_voidLCD1(void * Copy_pv)
{
	while(1)
	{
		if(xSemaphoreTake(App_LCDSemph,portMAX_DELAY) == pdTRUE)
		{
		LCD_u8_GoTo_XY(0,0);
		LCD_voidWriteString("Iam TASK 1");
		xSemaphoreGive(App_LCDSemph);
		vTaskDelay(1000);
		}
	}
}

void App_voidLCD2(void * Copy_pv)
{
	while(1)
	{
		if(xSemaphoreTake(App_LCDSemph,portMAX_DELAY) == pdTRUE)
		{
		LCD_u8_GoTo_XY(1,0);
		LCD_voidWriteString("Iam TASK 2");
		xSemaphoreGive(App_LCDSemph);
		vTaskDelay(1000);
		}

	}
}
