/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    :   10/11/2020        ********************/
/**************** SWC     :    BIT Math         ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BITNO)  (REG|=(1<<BITNO))
#define CLR_BIT(REG,BITNO)  (REG&=~(1<<BITNO))
#define TOG_BIT(REG,BITNO)  (REG^=(1<<BITNO))
#define GET_BIT(REG,BITNO)  ((REG>>BITNO)&1)

#endif