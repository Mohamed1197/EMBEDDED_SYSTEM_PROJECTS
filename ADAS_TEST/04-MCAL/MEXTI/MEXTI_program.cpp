/*
 * MEXTI_program.cpp
 *
 *  Created on: Jun 19, 2022
 *      Author: Emad Yousry
 *
 *  @file
 *  @auther
 *  @brief
 *  @detials
 *
 *  @version 1.0
 *  @data Jun 11, 2022
 *  @copyright IMT_SCHOOL 2022
 */

#include "../../00-LIB/BIT_MATH.h"
#include "../../00-LIB/STD_TYPES.h"

#include "../MGIE/MGIE_private.h"
#include "MEXTI_private.h"
#include "MEXTI_interface.h"

#include "../../03-WRAPPING/WDIO/DIO_interface.h"

/*Global Pointer to Function*/
static void (*MEXTI0_CallBack)(void);
static void (*MEXTI1_CallBack)(void);
static void (*MEXTI2_CallBack)(void);



/**
 *  @brief Enable External Interrupt
 *
 *  \b Description : This function takes inputs interrupt index and
 *   interrupt sensing control and return error status.
 *   Sense Control Options
 * 1- LOW_LEVEL
 * 2- ON_CHANGE
 * 3- FALLING_EDGE
 * 4- RISING_EDGE
 *
 *  @param u8 Copy_u8_EXTIIndex
 *  @param u8 Copy_u8EXTIEdge
 *
 *  @return Error Status
 */
u8 MEXTI::MEXTI_u8Enable (u8 Copy_u8_EXTIIndex , u8 Copy_u8EXTIEdge){

	MDIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH);


	u8 loc_u8ErrorState = 0 ;

	/*Configure EXTI0 and EXTI1*/
	if (Copy_u8_EXTIIndex == 0){

		/*Configure the sense control*/
//		MCUCR |= Copy_u8EXTIEdge;

		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);



		/*Enable external interrupt*/
		SET_BIT(GICR, GICR_INT0);



	}else if(Copy_u8_EXTIIndex == 1){

		/*Configure the sense control*/
		MCUCR |= Copy_u8EXTIEdge;
		/*Enable external interrupt*/
		SET_BIT(GICR, GICR_INT1);

	/*Configure EXTI2*/
	}else if(Copy_u8_EXTIIndex == 2){

		/*Configure the sense control*/
		if(Copy_u8EXTIEdge == 3){

			/*Configure interrupt sense control as falling edge*/
			//MCUCSR |= Copy_u8EXTIEdge;
			/*Enable external interrupt*/
			SET_BIT(GICR, GICR_INT2);

		}else if(Copy_u8EXTIEdge == 4){

			/*Configure interrupt sense control as rising edge*/
		//	MCUCSR |= Copy_u8EXTIEdge;
			/*Enable external interrupt*/
			SET_BIT(GICR, GICR_INT2);

		}else{
			/*Raise Error INT Sense Control Not Falling or Rising Edges*/
			loc_u8ErrorState = 1;
			}

	}else{
		/*Raise Error INT Index Not 0,1 or 2*/
		loc_u8ErrorState = 1;
		}

	/*Enable Global Interrupt Only if no Errors Occur*/
	if (loc_u8ErrorState == 0){
		/* Enable INT Global */
		SET_BIT(SREG,SREG_I);

	}else{/*DO NOTHING*/}

	return loc_u8ErrorState;

}
/**
 *  @brief Disable External Interrupt
 *
 *  \b Description : This function takes inputs interrupt index and
 *    return error status.
 *
 *  @param u8 Copy_u8_EXTIIndex
 *
 *  @return Error Status
 */
u8 MEXTI::MEXTI_u8Disable (u8 Copy_u8_EXTIIndex){
	u8 loc_u8ErrorState = 0 ;

	/*Configure EXTI0 and EXTI1*/
	if (Copy_u8_EXTIIndex == 0){

		/*Disable external interrupt*/
		CLR_BIT(GICR, GICR_INT0);

	}else if(Copy_u8_EXTIIndex == 1){

		/*Disable external interrupt*/
		CLR_BIT(GICR, GICR_INT1);

	/*Configure EXTI2*/
	}else if(Copy_u8_EXTIIndex == 2){

		/*Disable external interrupt*/
		CLR_BIT(GICR, GICR_INT2);

	}else{
		/*Raise Error INT Index Not 0,1 or 2*/
		loc_u8ErrorState = 1;
		}

	return loc_u8ErrorState;

}

/**
 *  @brief Set External Interrupt Callback
 *
 *  \b Description : This function takes inputs pointer to function and
 *   interrupt index and return error status.
 *
 *  @param (void (*Copy_pf)(void)
 *  @param u8 Copy_u8CallBackIndex
 *
 *  @return Error Status
 */
u8 MEXTI::MEXTI_u8SetCallBack (void (*Copy_pf)(void), u8 Copy_u8CallBackIndex){

	u8 loc_u8ErrorState = 0 ;

	/*if (GET_BIT(GIFR, GIFR_INTF0) == 1){

		MDIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH);
	}*/
	//

	/*Initialize interrupt callback pointer*/
	switch(Copy_u8CallBackIndex){
		/*EXTI0*/
		case 0:
			MEXTI0_CallBack = Copy_pf;
			//MEXTI0_CallBack();
			//MDIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN7,DIO_u8_HIGH);


		break;
		/*EXTI1*/
		case 1: MEXTI1_CallBack = Copy_pf; break;
		/*EXTI2*/
		case 2: MEXTI2_CallBack = Copy_pf; break;

		default:
			/*Raise Error Pointer not Initialed*/
			loc_u8ErrorState = 1;
			break;
	}



	return loc_u8ErrorState;

}




#ifdef __cplusplus
extern "C"
{
#endif
void __vector_1 (void)        __attribute__((signal));
void __vector_1 (void)
{
	/*EXTI0 Excute the App Function*/
	MEXTI0_CallBack();
}

void __vector_2 (void)        __attribute__((signal));
void __vector_2 (void)
{
	/*EXTI1 Excute the App Function*/
	MEXTI1_CallBack();
}

void __vector_3 (void)        __attribute__((signal));
void __vector_3 (void)
{
	/*EXTI2 Excute the App Function*/
	MEXTI2_CallBack();
}
#ifdef __cplusplus
}
#endif


