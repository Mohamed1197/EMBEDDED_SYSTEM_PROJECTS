

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "00-LIB/STD_TYPES.h"
#include "00-LIB/BIT_MATH.h"
#include "03-WRAPPING/WDIO/DIO_interface.h"
#include "03-WRAPPING/WEXTI/EXTI_interface.h"
#include "03-WRAPPING/W8TMR/Timer0_interface.h"

u8 mohamed;

void fun (void);
void fun (void)
{

}


extern "C"
{


}

/* declare TestGroup with name FirstTest */
TEST_GROUP(DIO_Wrapping_GetPinValue)
{
	/* declare a setup method for the test group. Optional. */
    void setup ()
    {
    	/* Set method real_one to stub. Automatically restore in teardown */

    }

    /* declare a teardown method for the test group. Optional */
    void teardown()
    {
    }
}; /* do not forget semicolumn */

/* declare one test within the test group */
TEST(DIO_Wrapping_GetPinValue, TEST_R_001)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8GetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,NULL));
}


TEST(DIO_Wrapping_GetPinValue, TEST_R_002)
{

	/* check two longs are equal */
	 LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8GetPinValue(DIO_u8_PORTA,DIO_u8_PIN0, &mohamed ) );
}

TEST(DIO_Wrapping_GetPinValue, TEST_R_003)
{

	/* check two longs are equal */
	 LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8GetPinValue(-1,0, &mohamed ) );
}

TEST(DIO_Wrapping_GetPinValue, TEST_R_004)
{

	/* check two longs are equal */
	 LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8GetPinValue(-1,-1, &mohamed ) );
}

TEST(DIO_Wrapping_GetPinValue, TEST_R_005)
{

	/* check two longs are equal */
	 LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8GetPinValue(0,-1, &mohamed ) );
}

TEST(DIO_Wrapping_GetPinValue, TEST_R_006)
{

	/* check two longs are equal */
	 LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8GetPinValue(DIO_u8_PORTA,DIO_u8_PIN7, &mohamed ) );
}

TEST(DIO_Wrapping_GetPinValue, TEST_R_007)
{

	/* check two longs are equal */
	 LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8GetPinValue(DIO_u8_PORTA,8, &mohamed ) );
}

TEST(DIO_Wrapping_GetPinValue, TEST_R_008)
{

	/* check two longs are equal */
	 LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8GetPinValue(DIO_u8_PORTD,DIO_u8_PIN0, &mohamed ) );
}

TEST(DIO_Wrapping_GetPinValue, TEST_R_009)
{

	/* check two longs are equal */
	 LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8GetPinValue(4,DIO_u8_PIN0, &mohamed ) );
}

/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
TEST_GROUP(DIO_Wrapping_SetPinDirection )
{
	/* declare a setup method for the test group. Optional. */
    void setup ()
    {
    	/* Set method real_one to stub. Automatically restore in teardown */

    }

    /* declare a teardown method for the test group. Optional */
    void teardown()
    {
    }
}; /* do not forget semicolumn */

/* declare one test within the test group */
TEST(DIO_Wrapping_SetPinDirection, TEST_R_010)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT));
}

TEST(DIO_Wrapping_SetPinDirection, TEST_R_011)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_OUTPUT));
}

TEST(DIO_Wrapping_SetPinDirection, TEST_R_012)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,-1));
}

TEST(DIO_Wrapping_SetPinDirection, TEST_R_013)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPinDirection(DIO_u8_PORTA,DIO_u8_PIN0,2));
}

TEST(DIO_Wrapping_SetPinDirection, TEST_R_014)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPinDirection(DIO_u8_PORTA,-1,DIO_u8_OUTPUT));
}

TEST(DIO_Wrapping_SetPinDirection, TEST_R_015)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPinDirection(DIO_u8_PORTA,8,DIO_u8_OUTPUT));
}

TEST(DIO_Wrapping_SetPinDirection, TEST_R_016)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_OUTPUT));
}

TEST(DIO_Wrapping_SetPinDirection, TEST_R_017)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPinDirection(4,DIO_u8_PIN0,DIO_u8_OUTPUT));
}

TEST(DIO_Wrapping_SetPinDirection, TEST_R_018)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPinDirection(-1,DIO_u8_PIN0,DIO_u8_OUTPUT));
}

/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
TEST_GROUP(DIO_Wrapping_DIO_u8SetPinValue  )
{
	/* declare a setup method for the test group. Optional. */
    void setup ()
    {
    	/* Set method real_one to stub. Automatically restore in teardown */

    }

    /* declare a teardown method for the test group. Optional */
    void teardown()
    {
    }
}; /* do not forget semicolumn */

/* declare one test within the test group */
TEST(DIO_Wrapping_DIO_u8SetPinValue, TEST_R_019)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8SetPinValue (DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH));
}

TEST(DIO_Wrapping_DIO_u8SetPinValue, TEST_R_020)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8SetPinValue (DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW));
}

TEST(DIO_Wrapping_DIO_u8SetPinValue, TEST_R_021)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPinValue (DIO_u8_PORTA,DIO_u8_PIN0,-1));
}

TEST(DIO_Wrapping_DIO_u8SetPinValue, TEST_R_022)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPinValue (DIO_u8_PORTA,DIO_u8_PIN0,2));
}

TEST(DIO_Wrapping_DIO_u8SetPinValue, TEST_R_023)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPinValue (DIO_u8_PORTA,-1,DIO_u8_HIGH));
}

TEST(DIO_Wrapping_DIO_u8SetPinValue, TEST_R_024)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPinValue (DIO_u8_PORTA,8,DIO_u8_HIGH));
}

TEST(DIO_Wrapping_DIO_u8SetPinValue, TEST_R_025)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8SetPinValue (DIO_u8_PORTD,DIO_u8_PIN7,DIO_u8_HIGH));
}

TEST(DIO_Wrapping_DIO_u8SetPinValue, TEST_R_026)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPinValue (4,DIO_u8_PIN0,DIO_u8_HIGH));
}

TEST(DIO_Wrapping_DIO_u8SetPinValue, TEST_R_027)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPinValue (-1,DIO_u8_PIN0,DIO_u8_HIGH));
}

/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
TEST_GROUP(DIO_Wrapping_DIO_u8SetPortDirection  )
{
	/* declare a setup method for the test group. Optional. */
    void setup ()
    {
    	/* Set method real_one to stub. Automatically restore in teardown */

    }

    /* declare a teardown method for the test group. Optional */
    void teardown()
    {
    }
}; /* do not forget semicolumn */

/* declare one test within the test group */
TEST(DIO_Wrapping_DIO_u8SetPortDirection, TEST_R_028)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8SetPortDirection (DIO_u8_PORTA , 255));
}

TEST(DIO_Wrapping_DIO_u8SetPortDirection, TEST_R_029)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8SetPortDirection (DIO_u8_PORTA , 0));
}

TEST(DIO_Wrapping_DIO_u8SetPortDirection, TEST_R_030)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8SetPortDirection (DIO_u8_PORTA , -1));
}

TEST(DIO_Wrapping_DIO_u8SetPortDirection, TEST_R_031)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8SetPortDirection (DIO_u8_PORTA , 2));
}

TEST(DIO_Wrapping_DIO_u8SetPortDirection, TEST_R_032)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MDIO_u8SetPortDirection (DIO_u8_PORTD , DIO_u8_OUTPUT));
}

TEST(DIO_Wrapping_DIO_u8SetPortDirection, TEST_R_033)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPortDirection (-1 , DIO_u8_OUTPUT));
}

TEST(DIO_Wrapping_DIO_u8SetPortDirection, TEST_R_034)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MDIO_u8SetPortDirection (4 , DIO_u8_OUTPUT));
}
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
TEST_GROUP(EXTI_Wrapping_EXTI_u8Enable  )
{
	/* declare a setup method for the test group. Optional. */
    void setup ()
    {
    	/* Set method real_one to stub. Automatically restore in teardown */

    }

    /* declare a teardown method for the test group. Optional */
    void teardown()
    {
    }
}; /* do not forget semicolumn */

/* declare one test within the test group */
TEST(EXTI_Wrapping_EXTI_u8Enable, TEST_R_042)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MEXTI_u8Enable(EXTI0,EXTI_RISING_EDGE));
}

TEST(EXTI_Wrapping_EXTI_u8Enable, TEST_R_043)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MEXTI_u8Enable(EXTI0,EXTI_FALLING_EDGE));
}

TEST(EXTI_Wrapping_EXTI_u8Enable, TEST_R_044)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MEXTI_u8Enable(EXTI0,EXTI_ON_CHANGE));
}

TEST(EXTI_Wrapping_EXTI_u8Enable, TEST_R_045)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MEXTI_u8Enable(EXTI0,EXTI_LOW_LEVEL));
}
TEST(EXTI_Wrapping_EXTI_u8Enable, TEST_R_046)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MEXTI_u8Enable(EXTI0,-1));
}

TEST(EXTI_Wrapping_EXTI_u8Enable, TEST_R_047)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MEXTI_u8Enable(EXTI0,4));
}

TEST(EXTI_Wrapping_EXTI_u8Enable, TEST_R_048)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MEXTI_u8Enable(EXTI2,EXTI_RISING_EDGE));
}

TEST(EXTI_Wrapping_EXTI_u8Enable, TEST_R_049)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MEXTI_u8Enable(-1,EXTI_LOW_LEVEL));
}

TEST(EXTI_Wrapping_EXTI_u8Enable, TEST_R_050)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MEXTI_u8Enable(3,EXTI_LOW_LEVEL));
}

/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
TEST_GROUP(EXTI_Wrapping_EXTI_u8Disable  )
{
	/* declare a setup method for the test group. Optional. */
    void setup ()
    {
    	/* Set method real_one to stub. Automatically restore in teardown */

    }

    /* declare a teardown method for the test group. Optional */
    void teardown()
    {
    }
}; /* do not forget semicolumn */

/* declare one test within the test group */
TEST(EXTI_Wrapping_EXTI_u8Disable, TEST_R_051)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MEXTI_u8Disable(EXTI0));
}

TEST(EXTI_Wrapping_EXTI_u8Disable, TEST_R_052)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MEXTI_u8Disable(EXTI2));
}
TEST(EXTI_Wrapping_EXTI_u8Disable, TEST_R_053)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MEXTI_u8Disable(-1));
}
TEST(EXTI_Wrapping_EXTI_u8Disable, TEST_R_054)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MEXTI_u8Disable(3));
}
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
TEST_GROUP(EXTI_Wrapping_EXTI_u8SetCallBack  )
{
	/* declare a setup method for the test group. Optional. */
    void setup ()
    {
    	/* Set method real_one to stub. Automatically restore in teardown */

    }

    /* declare a teardown method for the test group. Optional */
    void teardown()
    {
    }
}; /* do not forget semicolumn */

/* declare one test within the test group */
TEST(EXTI_Wrapping_EXTI_u8SetCallBack, TEST_R_055)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MEXTI_u8SetCallBack(NULL,EXTI0));
}
TEST(EXTI_Wrapping_EXTI_u8SetCallBack, TEST_R_056)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MEXTI_u8SetCallBack(&fun,EXTI0));
}
TEST(EXTI_Wrapping_EXTI_u8SetCallBack, TEST_R_057)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MEXTI_u8SetCallBack(&fun,EXTI2));
}

TEST(EXTI_Wrapping_EXTI_u8SetCallBack, TEST_R_058)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MEXTI_u8SetCallBack(&fun,-1));
}
TEST(EXTI_Wrapping_EXTI_u8SetCallBack, TEST_R_059)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MEXTI_u8SetCallBack(&fun,3));
}
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
TEST_GROUP(TMR_Wrapping_TMR_u8Timer0OVFSetCallBack  )
{
	/* declare a setup method for the test group. Optional. */
    void setup ()
    {
    	/* Set method real_one to stub. Automatically restore in teardown */

    }

    /* declare a teardown method for the test group. Optional */
    void teardown()
    {
    }
}; /* do not forget semicolumn */

/* declare one test within the test group */
TEST(TMR_Wrapping_TMR_u8Timer0OVFSetCallBack, TEST_R_063)
{
    /* check two longs are equal */
    LONGS_EQUAL( 3 ,MTMR_u8Timer0OVFSetCallBack(NULL));
}

TEST(TMR_Wrapping_TMR_u8Timer0OVFSetCallBack, TEST_R_064)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MTMR_u8Timer0OVFSetCallBack(&fun));
}

/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
TEST_GROUP(TMR_Wrapping_TMR_u8Timer0GeneratePWM )
{
	/* declare a setup method for the test group. Optional. */
    void setup ()
    {
    	/* Set method real_one to stub. Automatically restore in teardown */

    }

    /* declare a teardown method for the test group. Optional */
    void teardown()
    {
    }
}; /* do not forget semicolumn */

/* declare one test within the test group */
TEST(TMR_Wrapping_TMR_u8Timer0GeneratePWM, TEST_R_065)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MTMR_u8Timer0GeneratePWM(0));
}

TEST(TMR_Wrapping_TMR_u8Timer0GeneratePWM, TEST_R_066)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MTMR_u8Timer0GeneratePWM(50));
}
TEST(TMR_Wrapping_TMR_u8Timer0GeneratePWM, TEST_R_067)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MTMR_u8Timer0GeneratePWM(100));
}
TEST(TMR_Wrapping_TMR_u8Timer0GeneratePWM, TEST_R_068)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MTMR_u8Timer0GeneratePWM(-1));
}
TEST(TMR_Wrapping_TMR_u8Timer0GeneratePWM, TEST_R_069)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_NOK ,MTMR_u8Timer0GeneratePWM(101));
}
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
/* --------------------------------------------------------------- */
TEST_GROUP(TMR_Wrapping_TMR_u8Timer0GetCounterValue )
{
	/* declare a setup method for the test group. Optional. */
    void setup ()
    {
    	/* Set method real_one to stub. Automatically restore in teardown */

    }

    /* declare a teardown method for the test group. Optional */
    void teardown()
    {
    }
}; /* do not forget semicolumn */

/* declare one test within the test group */
TEST(TMR_Wrapping_TMR_u8Timer0GetCounterValue, TEST_R_070)
{
    /* check two longs are equal */
    LONGS_EQUAL( 3 ,MTMR_u8Timer0GetCounterValue(NULL));
}
TEST(TMR_Wrapping_TMR_u8Timer0GetCounterValue, TEST_R_071)
{
    /* check two longs are equal */
    LONGS_EQUAL( STD_TYPES_OK ,MTMR_u8Timer0GetCounterValue(&mohamed));
}



/*###############################################################*/
/*###############################################################*/
int main(int ac, char **av)
{
    return CommandLineTestRunner::RunAllTests(ac, av); /* cover alternate method */
}
