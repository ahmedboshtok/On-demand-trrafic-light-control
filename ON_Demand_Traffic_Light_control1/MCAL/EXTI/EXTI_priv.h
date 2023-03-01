/*
 * EXTI_priv.h
 *
 *  Created on: Oct 16, 2021
 *      Author: Ahmed Boshtok
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_

#define INT_NUM 	3

#define MCUCR      *((volatile u8*)0x55)
#define MCUCSR     *((volatile u8*)0x54)
#define GICR       *((volatile u8*)0x5B)
//#define GIFR       *((volatile u8*)0x5A)



enum
{
	LOW_LEVEL,
	ANY_LOGICAL,
	FALLING,
	RISING,

	DISABLED=0,
	ENABLED,

	INT0=0,
	INT1,
	INT2
};

#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
