/*
 * LED_program.c
 *
 *  Created on: ???/???/????
 *      Author: Ahmed Boshtok
 */

#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorStates.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/Timer0/TIMER0_int.h"


#include "../../MCAL/GIE/GIE_int.h"
#include "../../MCAL/interrupt.h"

#include "LED_config.h"
#include "LED_priv.h"

extern LED_t LED_AstrLEDconfig [LED_NUM];

ES_t LED_init(){
	ES_t Local_enuErrorStates = ES_NOK;

	u8 Local_u8Iterator;
	for (Local_u8Iterator = 0; Local_u8Iterator<= LED_NUM; Local_u8Iterator++){

		Local_enuErrorStates= DIO_enuSetPinDirection(LED_AstrLEDconfig[Local_u8Iterator].LED_port,LED_AstrLEDconfig[Local_u8Iterator].LED_pin,DIO_u8OUTPUT);

		}
	return Local_enuErrorStates;
}
ES_t LED_ON(u8 CopypAstrLEDinfo){

	ES_t Local_enuErrorStates = ES_NOK;
		if(CopypAstrLEDinfo < LED_NUM){
			if(LED_AstrLEDconfig[CopypAstrLEDinfo].LED_connection == PULL_DOWN){
				Local_enuErrorStates = DIO_enuSetPinValue(LED_AstrLEDconfig[CopypAstrLEDinfo].LED_port, LED_AstrLEDconfig[CopypAstrLEDinfo].LED_pin, DIO_u8LOW);
			}
			else if(LED_AstrLEDconfig[CopypAstrLEDinfo].LED_connection == PULL_UP){
				Local_enuErrorStates = DIO_enuSetPinValue(LED_AstrLEDconfig[CopypAstrLEDinfo].LED_port, LED_AstrLEDconfig[CopypAstrLEDinfo].LED_pin, DIO_u8HIGH);
			}
			else{
				Local_enuErrorStates = ES_OUT_OF_RANGE;
			}
		}
		else{
			Local_enuErrorStates = ES_OUT_OF_RANGE;
		}

		return Local_enuErrorStates;

}
ES_t LED_OFF(u8 CopypAstrLEDinfo){

	ES_t Local_enuErrorStates = ES_NOK;
		if(CopypAstrLEDinfo < LED_NUM){
			if(LED_AstrLEDconfig[CopypAstrLEDinfo].LED_connection == PULL_DOWN){
				Local_enuErrorStates = DIO_enuSetPinValue(LED_AstrLEDconfig[CopypAstrLEDinfo].LED_port, LED_AstrLEDconfig[CopypAstrLEDinfo].LED_pin, DIO_u8HIGH);
			}
			else if(LED_AstrLEDconfig[CopypAstrLEDinfo].LED_connection == PULL_UP){
				Local_enuErrorStates = DIO_enuSetPinValue(LED_AstrLEDconfig[CopypAstrLEDinfo].LED_port, LED_AstrLEDconfig[CopypAstrLEDinfo].LED_pin, DIO_u8LOW);
			}
			else{
				Local_enuErrorStates = ES_OUT_OF_RANGE;
			}
		}
		else{
			Local_enuErrorStates = ES_OUT_OF_RANGE;
		}

		return Local_enuErrorStates;
}
ES_t LED_toggel(u8 CopypAstrLEDinfo){
	ES_t Local_enuErrorStates = ES_NOK;

		if(CopypAstrLEDinfo < LED_NUM){
			DIO_enuTogPinValue(LED_AstrLEDconfig[CopypAstrLEDinfo].LED_port, LED_AstrLEDconfig[CopypAstrLEDinfo].LED_pin);
		}
		else{
			Local_enuErrorStates = ES_OUT_OF_RANGE;
		}

		return Local_enuErrorStates;


}
