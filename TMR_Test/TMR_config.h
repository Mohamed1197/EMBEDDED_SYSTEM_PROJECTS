/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    : 25/9/2020           ********************/
/**************** SWC     :     TMR             ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
#ifndef TMR_CONFIG_H
#define TMR_CONFIG_H

/* Select Mode of Timer */
#define NORMAL_MODE              0
#define CTC_MODE                 1
#define FAST_PWM                 2
#define PHASE_CORRECT_PWM        3
#define TIMER_MODE            CTC_MODE


/* Enable Timer OVF or CTC PIE  */
#define ENABLE_TIMER0_PIE             0
#define DISABLE_TIMER0_PIE            1
#define TIMER_PIE             ENABLE_TIMER0_PIE


/* Set Preload Value */
#define PRELOAD_VALUE                192


/* Set Compare Match Register */
#define COMPARE_MATCH_VALUE          99


/* Select Action on OC0 Pin */
#define OC0_DISCONNECTED                         0
#define TOGGLE_OC0_ON_COMPARE                    1
#define CLEAR_OC0_ON_COMPARE                     2
#define NON_INVERTING_PWM                        2
#define SET_OC0_ON_COMPARE                       3
#define INVERTING_PWM                            3
#define COMPARE_OUTPUT_MODE                  NON_INVERTING_PWM


/* Set Prescaler Value */
#define TIMER_OFF                     0
#define NO_PRESCALING                 1
#define CLOCK_8                       2
#define CLOCK_64                      3
#define CLOCK_256                     4
#define CLOCK_1024                    5
#define CLOCK_FALLING_EDGE            6
#define CLOCK_RISING_EDGE             7
#define PRESCALER_VALUE             CLOCK_8


#endif
