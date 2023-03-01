/*
 * switch_prog.c
 *
 *  Created on: Oct 7, 2021
 *      Author: Ahmed Boshtok
 */
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorStates.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Switch_config.h"
#include "Switch_priv.h"

extern SW_t Switch_AstrSwitchconfig [SW_NUM];
ES_t Switch_enuInit()
{
	ES_t Local_enuErrorState = ES_NOK;
	u16 Local_u16ErrorState=0;
	u8 Local_u8Iterator=0;
	for (Local_u8Iterator = 0; Local_u8Iterator< SW_NUM; Local_u8Iterator++){
		Local_u16ErrorState = ( DIO_enuSetPinDirection(Switch_AstrSwitchconfig[Local_u8Iterator].sw_port, Switch_AstrSwitchconfig[Local_u8Iterator].sw_pin, DIO_u8INPUT));
		Local_u16ErrorState |= (DIO_enuSetPinValue((Switch_AstrSwitchconfig+Local_u8Iterator)->sw_port, (Switch_AstrSwitchconfig+Local_u8Iterator)->sw_pin,(Switch_AstrSwitchconfig+Local_u8Iterator)->sw_state) )<<2;
	}
	if (Local_u16ErrorState== 5){
		Local_enuErrorState =ES_OK;
	}


	return Local_enuErrorState;
}
ES_t Switch_enuGetstate( u8 * Copy_pu8value ){
	ES_t Local_enuErrorState = ES_NOK;
	DIO_enuGetPinValue(Switch_AstrSwitchconfig->sw_port , Switch_AstrSwitchconfig->sw_pin,Copy_pu8value);


	return Local_enuErrorState ;
}

