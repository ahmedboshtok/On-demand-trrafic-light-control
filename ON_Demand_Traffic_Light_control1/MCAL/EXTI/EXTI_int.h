/*
 * EXTI_int.h
 *
 *  Created on: Oct 16, 2021
 *      Author: Ahmed Boshtok
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

ES_t EXTI_enuInit();

ES_t EXTI_enuSetSenseLevel(u8 Copy_u8IntNum, u8 Copy_u8SenceLevel);

ES_t EXTI_enuEnableInterrupt(u8 Copy_u8IntNum);

ES_t EXTI_enuDisableInterrupt(u8 Copy_u8IntNum);

ES_t EXTI_enuCallBack(volatile void (* Copy_pfunAppFun)(void), u8 Copy_u8IntNum);
#endif /* MCAL_EXTI_EXTI_INT_H_ */
