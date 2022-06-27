

#include  "STD_TYPES.h"
#include  "BIT_MATH.h"


#include  "EXTI_interface.h"
#include  "NVIC_INT.h"
#include  "STK_interface.h"
#include  "AFIO_interface.h"
#include  "RCC_interface.h"
#include  "IR_interface.h"

/*    Variables   */
static volatile u8 StartFlag = 0;
volatile 		u8 FrameData = 0;
static volatile u8 Counter = 0;
static volatile u32 ArrayFrame[33]={0};
void (*G_Play)(void);

void TakeAction(void)
{
	if(ArrayFrame[0]<=14000)
	{
	for(u8 i=0;i<8;i++)
	{
			if((ArrayFrame[17+i]>=2000) &&(ArrayFrame[17+i]<=2400))
			{
				SET_BIT(FrameData,i);
			}
	}
	G_Play();
	/*Clear Variables*/
	StartFlag = 0;
	FrameData = 0;
	Counter   = 0;
	ArrayFrame[0]=0;
	}

}

void IR_voidInit(void(*LOC_P)(void))
{
	G_Play=LOC_P;
    /*  EXTI CALL BACK  */
	EXTI0_voidSetCallBack(IR_voidFrame);
	/*     NVIC INIT   */
	MNVIC_VidInit();
	MNVIC_U8InteruptEnable(VT_EXTI0);
	/*     EXTI INIT    */
	MEXTI_voidSetSignalLatch(EXTI_u8_LINE0 , EXTI_FALLING);
	MEXTI_voidEnable(EXTI_u8_LINE0);

	/*     STK INIT   */
	MSTK_voidInit();
}
void IR_voidFrame(void)
{
	if (StartFlag == 0 )
	{
		MSTK_voidSetIntervalSingle2(150000,TakeAction);
		StartFlag  = 1;
	}
	else if (StartFlag == 1)
	{
		ArrayFrame[Counter]= MSTK_u32GetElapsedTicks();
		MSTK_voidSetIntervalSingle2(150000,TakeAction);
		Counter++;
	}
}
