/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 18 May 2022                                                                     */
/* Description       : main.c --> IMT_Osliscope                                                        */
/* Project Features  :                                                                                 */
/*      1- Display Digital Signal On LCD                                                               */
/*		2- Calculate Digital Signal Frequency ,Duty Cycle                                              */
/*      3- Generate PWM with different Duty cycle controlled by potentiometer                          */
/*      4- Display Calculated  Signal Frequency ,Duty Cycle on LCD                                     */
/* Future Updates:                                                                                     */
/*      1- Generate and  Read Analog Signal like sine wave                                             */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "../LIB/LSTD_TYPES.h"
#include "../LIB/LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include"../MCAL/MDIO/MDIO_Interface.h"         //for DIO
#include"../MCAL/MGIE/MGIE_Interface.h"         //for Global Interrupt
#include"../MCAL/MTIMER/MTIMER_Interface.h"     //for timer
#include"../MCAL/MADC/MADC_Interface.h"         //for ADC

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      HAL Components                                                 */
/*******************************************************************************************************/

#include"../HAL/HCLCD/HCLCD_Interface.h"         //for LCD
#include"../HAL/HLED/HLED_Interface.h"           //for LED

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                   Service Layer  Components                                         */
/*******************************************************************************************************/

#define F_CPU  8000000UL
#include<util\delay.h>

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Global Variables(Flag)                                         */
/*******************************************************************************************************/

LED_t Y_LED4 = {HLED_PORTB,PIN3};     //Hardware Interface--> OC0

static u8 Flag=0;
static u8 Count=0;
static u32 T1=0;
static u32 T2=0;
static u32 T3=0;

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                     Application Function Prototype                                  */
/*******************************************************************************************************/

void App_TIMER1_OVF_ISR(void);
void App_TIMER1_ICF_ISR(void);

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                    Beginning of the System                                          */
/*******************************************************************************************************/

int main(void)
{
	/*#####################################################################################################*/
	/*#####################################################################################################*/

	/*******************************************************************************************************/
	/*                                          System variables                                           */
	/*******************************************************************************************************/

	u16 LOC_u16DigitalValue     = 0;
	u16 LOC_u16AnalogValue      = 0;
	u16 LOC_u16Analog_OldValue  = 0;
	u16 LOC_u16OCR_Value        = 0;
	u32 LOC_u32Freq             = 0;
	u16 LOC_u16DutyCycle        = 0;
	u8 pattern_low[8]           ={0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x00};
	u8 pattern_high[8]          ={0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	u8 pattern_rising[8]        ={0x1F,0x10,0x10,0x10,0x10,0x10,0x10,0x00};
	u8 pattern_falling[8]       ={0x1F,0x01,0x01,0x01,0x01,0x01,0x01,0x00};
	u8 pattern_full[8]          ={0x1F,0x11,0x11,0x11,0x11,0x11,0x11,0x00};


	/*#####################################################################################################*/
	/*#####################################################################################################*/

	/*******************************************************************************************************/
	/*                                      System Initialization                                          */
	/*******************************************************************************************************/

	HLED_VidInit(&Y_LED4);                                             /*Generate PWM on this OC0-->Pin PB3*/

	HCLCD_Vid4Bits_Init();                                             /*        LCD Initialization        */

	/*Initialize patterns*/
	HCLCD_Vid4Bits_CustomAlphChar(0, pattern_low);
	HCLCD_Vid4Bits_CustomAlphChar(1, pattern_high);
	HCLCD_Vid4Bits_CustomAlphChar(2, pattern_rising);
	HCLCD_Vid4Bits_CustomAlphChar(3, pattern_falling);
	HCLCD_Vid4Bits_CustomAlphChar(4, pattern_full);

	HCLCD_Vid4Bits_SetPosition(1,0);

	HCLCD_Vid4Bits_DisplayString((u8*)"Welcome....");                  /*       Send Welcome message       */
	_delay_ms(1000);
	HCLCD_Vid4Bits_ClearScreen();
	_delay_ms(1000);

	MADC_VidInit();                                                  /*         Initialize ADC           */

	/*******************************************************************************************************/
	/*                    F_cpu = 8MHz, prescaler = 64 -->F_timer = 125000HZ ,                             */
	/*                    T_tick = 8 micro second ,One_OVF = 256*8 = 2048  micro second ,                  */
	/*	                  F_out = Fcpu/N*510                                                               */
	/*******************************************************************************************************/

	MTIMER0_VidInit();                                              /*Timer0 Initialization in Phase Correct PWM */

	/*******************************************************************************************************/
	/*                              Set CTC Value 255 -->DutyCycle=100%                                    */
	/*                              Set CTC Value 191 -->DutyCycle=75%                                     */
	/*	                            Set CTC Value 127 -->DutyCycle=50%                                     */
	/*                              Set CTC Value 63-->DutyCycle  =25%                                     */
	/*                              Set CTC Value 0 -->DutyCycle  =0%                                      */
	/*******************************************************************************************************/


	MTIMER0_VidSetCTCValue(191);                                       /*Set CTC Value 191 -->DutyCycle=75%*/

	/*******************************************************************************************************/
	/*                    Timer1 Initialization-->-->Set timer1 in Input Capture Mode                      */
	/*                    F_cpu = 8MHz, NO_Prescaler --> F_timer = 8MHz -->T_tick = 0.125 micro second     */
	/*	                 one_OFV = 0.125 *65536 = 8192 micro second = 8.192 ms                             */
	/*                   TIMER1 Sense Control----> Rising Edge                                             */
	/*******************************************************************************************************/

	MTIMER1_VidInit();                                                 /*    TIMER1 initialized in ICU     */

	MTIMER1_VidICF_SetCallBack(&App_TIMER1_ICF_ISR);                   /* Set Input Capture Call Back func */
	MTIMER1_VidOVF_SetCallBack(&App_TIMER1_OVF_ISR);                   /*   Set overflow Call Back func    */


	MGIE_VidEnable();                                                  /*          Enable To GIE           */
	/*#####################################################################################################*/
	/*#####################################################################################################*/

	/*******************************************************************************************************/
	/*                                          Debugging Section                                          */
	/*******************************************************************************************************/

	/*#####################################################################################################*/
	/*#####################################################################################################*/


	while(1)
	{
		/*******************************************************************************************************/
		/*                                         Calculate signal Features                                   */
		/*******************************************************************************************************/
		if(Flag==3){
			LOC_u32Freq =(1000000/((T3-T1)*0.125));                         /*           Frequency in HZ           */
			LOC_u16DutyCycle=((f32)(T2-T1)/(T3-T1)*100);                    /*         calculate Duty Cycle        */
			Flag = 0 ;
		}

		/*******************************************************************************************************/
		/*                                         Update PWM signal                                           */
		/*******************************************************************************************************/
		LOC_u16DigitalValue=MADC_u16ADC_StartConversion(CHANNEL_0);
		LOC_u16AnalogValue=(LOC_u16DigitalValue*5000UL)/1023;            /*        Read Analog Voltage         */
		LOC_u16OCR_Value = LOC_u16DigitalValue/4 ;                       /*           update PWM               */
		HCLCD_Vid4Bits_SetPosition(1,0);                             /*  Position of Duty on LCD first row */
		HCLCD_Vid4Bits_DisplayString((u8*) "D =");
		HCLCD_Vid4Bits_DisplayNumber(LOC_u16DutyCycle);
		HCLCD_Vid4Bits_DisplayString((u8*)"%");
		HCLCD_Vid4Bits_SetPosition(1,8);
		HCLCD_Vid4Bits_DisplayString((u8*)"F =");
		HCLCD_Vid4Bits_DisplayNumber(LOC_u32Freq);
		HCLCD_Vid4Bits_DisplayString((u8*)"Hz");
		if(LOC_u16AnalogValue!=LOC_u16Analog_OldValue)                   /*       Check if signal change       */
		{
			LOC_u16Analog_OldValue=LOC_u16AnalogValue;
			MTIMER0_VidSetCTCValue(LOC_u16OCR_Value);

			/*******************************************************************************************************/
			/*                                         Display Signal Calculations                                  */
			/*******************************************************************************************************/

			HCLCD_Vid4Bits_SetPosition(1,0);                             /*  Position of Duty on LCD first row */
			HCLCD_Vid4Bits_DisplayString((u8*) "D =");
			HCLCD_Vid4Bits_DisplayNumber(LOC_u16DutyCycle);
			HCLCD_Vid4Bits_DisplayString((u8*)"%");
			HCLCD_Vid4Bits_SetPosition(1,9);
			HCLCD_Vid4Bits_DisplayString((u8*)"F =");
			HCLCD_Vid4Bits_DisplayNumber(LOC_u32Freq);
			HCLCD_Vid4Bits_DisplayString((u8*)"Hz");
			/*******************************************************************************************************/
			/*                                         Display Signal shape                                        */
			/*******************************************************************************************************/
			HCLCD_Vid4Bits_SetPosition(2,0);                             /*  Position of Signal Shape          */
			HCLCD_Vid4Bits_DisplayString((u8*)"                  ");     /*          Clear Line Two            */
			HCLCD_Vid4Bits_SetPosition(2,0);
			if(LOC_u16DutyCycle==0 && (LOC_u16DutyCycle <=10) )
			{
				//0%
				for(int i = 0 ; i<= 16;i++)
				{
					HCLCD_Vid4Bits_DisplayCharacter(0);
					HCLCD_Vid4Bits_DisplayCharacter(0);
					HCLCD_Vid4Bits_DisplayCharacter(0);
					HCLCD_Vid4Bits_DisplayCharacter(0);
				}

			}
			else if((LOC_u16DutyCycle>=20) && (LOC_u16DutyCycle<=30 ))
			{
				//25%
				for(int i = 0 ; i<= 16;i++)
				{
					HCLCD_Vid4Bits_DisplayCharacter(4);
					HCLCD_Vid4Bits_DisplayCharacter(0);
					HCLCD_Vid4Bits_DisplayCharacter(0);
					HCLCD_Vid4Bits_DisplayCharacter(0);
				}

			}
			else if((LOC_u16DutyCycle>=45) && (LOC_u16DutyCycle<=55 ))
			{
				//50%
				for(int i = 0 ; i<= 16;i++)
				{
					HCLCD_Vid4Bits_DisplayCharacter(2);
					HCLCD_Vid4Bits_DisplayCharacter(3);
					HCLCD_Vid4Bits_DisplayCharacter(0);
					HCLCD_Vid4Bits_DisplayCharacter(0);
				}

			}
			else if((LOC_u16DutyCycle>=65) && (LOC_u16DutyCycle<=85 ))
			{
				//75%
				for(int i = 0 ; i<= 16;i++)
				{
					HCLCD_Vid4Bits_DisplayCharacter(2);
					HCLCD_Vid4Bits_DisplayCharacter(1);
					HCLCD_Vid4Bits_DisplayCharacter(3);
					HCLCD_Vid4Bits_DisplayCharacter(0);
				}

			}
			else if((LOC_u16DutyCycle>=90) && (LOC_u16DutyCycle=100 ))
			{
				//100%
				for(int i = 0 ; i<= 16;i++)
				{
					HCLCD_Vid4Bits_DisplayCharacter(1);
					HCLCD_Vid4Bits_DisplayCharacter(1);
					HCLCD_Vid4Bits_DisplayCharacter(1);
					HCLCD_Vid4Bits_DisplayCharacter(1);

				}

			}
		}
		else
		{
			/*Do Nothing*/
		}
	}
	return 0 ;

}


void App_TIMER1_ICF_ISR(void)
{
	if(Flag==0)
	{
		T1= MTIMER1_u16GetICR1Value()+Count*65536;
		MTIMER1_VidSenseControl(MTIMER1_ICU_FALLING_EDGE);
		Flag=1;
	}
	else if(Flag==1)
	{
		T2=	 MTIMER1_u16GetICR1Value()+Count*65536;
		MTIMER1_VidSenseControl(MTIMER1_ICU_RISING_EDGE);
		Flag=2;
	}
	else if(Flag==2)
	{
		T3= MTIMER1_u16GetICR1Value()+Count*65536;
		Flag=3;
	}
}

void App_TIMER1_OVF_ISR(void)
{
	Count++ ;
}



