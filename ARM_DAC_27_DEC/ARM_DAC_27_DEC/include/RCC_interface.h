/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _RCC_INTERFACE_H_
#define   _RCC_INTERFACE_H_



void MRCC_VidInit(void);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MRCC_VidInit.								            **/
/**	Return Type		: void					   		   		                **/
/**	Arguments		: void                                                  **/
/**	Functionality	: Choosing the clock source of the system	            **/
/*****************************************************************************/
/*****************************************************************************/
void MRCC_VidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PeripheralId);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MRCC_VidEnableClock.								    **/
/**	Return Type		: void					   		   		                **/
/**	Arguments		: Bus , Peripheral number                               **/
/**	Functionality	: Enabling the clock for specific peripheral	        **/
/*****************************************************************************/
/*****************************************************************************/
void MRCC_VidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PeripheralId);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MRCC_VidEnableClock.								    **/
/**	Return Type		: void					   		   		                **/
/**	Arguments		: Bus , Peripheral number                               **/
/**	Functionality	: Disabling the clock for specific peripheral	        **/
/*****************************************************************************/
/*****************************************************************************/
void MRCC_VidCalibrationHSI(void);
/*****************************************************************************/
/*****************************************************************************/
/**	Function Name	: MRCC_VidCalibrationHSI.								**/
/**	Return Type		: void				   		   		                    **/
/**	Arguments		: void                                                  **/
/**	Functionality	: Calibrating HSI clock	to be 8MHZ at end               **/
/*****************************************************************************/
/*****************************************************************************/




#endif