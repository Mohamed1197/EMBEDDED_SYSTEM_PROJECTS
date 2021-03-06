/* Author            : Ahmed khaled Hammad & Mohamed Ahmed Abdelhamid                                  */
/* Version           : V0.0.0                                                                          */
/* Data              : 24 May 2022                                                                     */
/* Description       : MADC Driver                                                                     */

#ifndef MCAL_MADC_MADC_CONFIG_H_
#define MCAL_MADC_MADC_CONFIG_H_

/*MADC REFERENCE VOLATGE Options:
 *1- MADC_AVCC_REFERENCEVOLATGE
 *2- MADC_2.56V_REFERENCEVOLATGE
 */

#define MADC_SET_REFERENCEVOLATGE  MADC_AVCC_REFERENCEVOLATGE

/*MADC Prescaler options:
 * 1- MADC_2_PRESCALER
 * 2- MADC_4_PRESCALER
 * 3- MADC_8_PRESCALER
 * 4- MADC_16_PRESCALER
 * 5- MADC_32_PRESCALER
 * 6- MADC_64_PRESCALER
 * 7- MADC_128_PRESCALER
 */
#define MADC_SET_PRESCALER   MADC_64_PRESCALER

/*MADC Adjust Options:
 *1- MADC_LEFT_ADJUST
 *2- MADC_RIGHT_ADJUST
 */

#define MADC_SET_ADJUST      MADC_RIGHT_ADJUST


#endif /* MCAL_MADC_MADC_CONFIG_H_ */
