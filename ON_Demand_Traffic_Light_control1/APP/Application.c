/*
 * Application.c
 *
 *  Created on: ???/???/????
 *      Author: Ahmed Boshtok
 */

#include "Application.h"



u8 flag_yledCar = 0, flag_RledCar = 0, flag_GledCar = 1;

static void pedstrainMode(void)
{
	/*
	 * Local function (only use in this file)
	 * this function estimate pedestrian wanted to cross road in the time of crossing car
	 * he will press the  button to change traffic light..firing interrupt
	 * this function will pass to ISR
	 */
	if (flag_RledCar == FLAG_HIGH){
		/*check if pedestrian press the button when the red led of car is on
		 *
		 */

		LED_ON(CAR_RLED);
		LED_ON(PEDESTRAIN_GLED);
		TIMER0_enuSetSyncDelay(5000);

		LED_OFF(CAR_RLED);
		LED_OFF(PEDESTRAIN_GLED);
		toggle_YLED();


		LED_ON(PEDESTRAIN_RLED);
		LED_ON(CAR_GLED);
		TIMER0_enuSetSyncDelay(5000);

		LED_OFF(CAR_GLED);
		LED_OFF(PEDESTRAIN_RLED);
		TIMER0_enuSetSyncDelay(5000);
	}
	else if (flag_yledCar== FLAG_HIGH){
		/*check if pedestrian press the button when the yellow led blanking
				 *
				 */
		toggle_YLED();

		LED_OFF(PEDESTRAIN_RLED);
		LED_OFF(CAR_GLED);
		LED_ON(CAR_RLED);
		LED_ON(PEDESTRAIN_GLED);
		TIMER0_enuSetSyncDelay(5000);

		LED_OFF(CAR_RLED);
		LED_OFF(PEDESTRAIN_GLED);//ex
		toggle_YLED();

		LED_ON(CAR_GLED);
		LED_ON(PEDESTRAIN_RLED);
		TIMER0_enuSetSyncDelay(5000);

		LED_OFF(PEDESTRAIN_GLED);
		LED_OFF(CAR_RLED);
		toggle_YLED();


	}
	else if (flag_GledCar== FLAG_HIGH) {
		//check if pedestrian press the button when the green led of car is on

		toggle_YLED();

		LED_OFF(CAR_GLED);
		LED_OFF(PEDESTRAIN_RLED);
		LED_ON(CAR_RLED);
		LED_ON(PEDESTRAIN_GLED);
		TIMER0_enuSetSyncDelay(5000);

		LED_OFF(CAR_RLED);
		LED_OFF(PEDESTRAIN_GLED);
		toggle_YLED();

		LED_ON(CAR_GLED);
		LED_ON(PEDESTRAIN_RLED);
		TIMER0_enuSetSyncDelay(5000);



	}

}


ES_t APP_init(){


	ES_t Local_enuerrorState =ES_NOK;
	u16 Local_u16errorState;
	Local_u16errorState= LED_init();
	Local_u16errorState=(Switch_enuInit()<<2);
	Local_u16errorState=(TIMER0_enuInit()<<2);
	Local_u16errorState=(EXTI_enuInit()<<2);
	SETBIT(GIFR,0);
	Local_u16errorState=(GIE_enuInit()<<2);
	Local_u16errorState =(GIE_enuEnable()<<2);
	if (Local_u16errorState == 0x555){ // check if all function return 01 that is mean its ok.
		Local_enuerrorState = ES_OK;
	}
	return Local_enuerrorState;
}



ES_t APP_Start(){
	ES_t Local_enuerrorState =ES_NOK;
	Local_enuerrorState = EXTI_enuCallBack(&pedstrainMode,0);

		NormalMode();

	return Local_enuerrorState;
}
 void toggle_YLED(){
	 /*
	  * first we rising flag of yellow led to tell system if pedestrian press the button when yellow led blank in the end of
	  * blanking down flag again
	  * this function blank yellow led for 5sec
	  */
	 flag_yledCar = FLAG_HIGH;
	u8 Local_u8Itrator;

	for (Local_u8Itrator=0;Local_u8Itrator<20;Local_u8Itrator++){
		LED_toggel(PEDESTRAIN_YLED);
		LED_toggel(CAR_YLED);
		TIMER0_enuSetSyncDelay(250);
	}
	LED_OFF(PEDESTRAIN_YLED);
	LED_OFF(CAR_YLED);
	flag_yledCar = FLAG_LOW;

}
/**************************************************************************************************************************/
void NormalMode(){
	//this function estimate Normal mode of traffic light if no external interrupt happened
	//first IN normal mode turn on Green led to let car pass,rising Flag of Car Green Led and turn off Red led of pedestrain
	LED_ON(CAR_GLED);
	flag_GledCar = FLAG_HIGH;
	LED_ON(PEDESTRAIN_RLED);
	TIMER0_enuSetSyncDelay(5000); //delay 5 SEC
//then turn off Car an the same time down flag and turn off Pedestrain RLED then blinking both yellow Led of Car and pedestrian for 5SEC
	LED_OFF(CAR_GLED);
	flag_GledCar = FLAG_LOW;
	LED_OFF(PEDESTRAIN_RLED);
	toggle_YLED();
//her we let pedestrian cross road by turn on Green led for him and turn of red led for car and rising red led flag  for 5sec
	//then blink yellow leds for 5 sec
	LED_ON(CAR_RLED);
	flag_RledCar = FLAG_HIGH;
	LED_ON(PEDESTRAIN_GLED);
	TIMER0_enuSetSyncDelay(5000);
	LED_OFF(CAR_RLED);
	flag_RledCar = FLAG_LOW;
	LED_OFF(PEDESTRAIN_GLED);
	toggle_YLED();
}
