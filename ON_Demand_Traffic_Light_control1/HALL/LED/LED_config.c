/*
 * LED_config.c
 *
 *  Created on: ???/???/????
 *      Author: Ahmed Boshtok
 */
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorStates.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "LED_config.h"
#include "LED_priv.h"


LED_t LED_AstrLEDconfig [LED_NUM]={
		{DIO_u8GROUP_A,DIO_u8PIN0,PULL_UP},
		{DIO_u8GROUP_A,DIO_u8PIN1,PULL_UP},
		{DIO_u8GROUP_A,DIO_u8PIN2,PULL_UP},

		{DIO_u8GROUP_B,DIO_u8PIN0,PULL_UP},
		{DIO_u8GROUP_B,DIO_u8PIN1,PULL_UP},
		{DIO_u8GROUP_B,DIO_u8PIN2,PULL_UP},
};

