/*************************************************/
/**               AUTHOR : AHMED EHAB           **/                        
/**               VERSION : V0.1                **/
/*************************************************/

#ifndef   _SYSTICK_CONFIG_H_
#define   _SYSTICK_CONFIG_H_


                /**--------------------------**/
                /**|*OPTIONS OF CLOCK SOURCE*|**/
                /**|-------------------------|**/ 		
                /**| MSYSTICK_SOURCE_AHB_8   |**/ 
                /**|-------------------------|**/ 
                /**| MSYSTICK_SOURCE_AHB     |**/ 
                /**|-------------------------|**/

/**************************************************************************/
#define      MSYSTICK_CLOCK_SOURCE                    MSYSTICK_SOURCE_AHB_8                 
/**************************************************************************/

/**************************************************************************/
#define         CPU                        8000000                 
/**************************************************************************/
/**************************************************************************/
#if   MSYSTICK_CLOCK_SOURCE==MSYSTICK_SOURCE_AHB_8
#define   Sys_PRESCALER          8
#elif MSYSTICK_CLOCK_SOURCE==MSYSTICK_SOURCE_AHB
#define   Sys_PRESCALER          1
#endif
/***************************************************************************/

#endif