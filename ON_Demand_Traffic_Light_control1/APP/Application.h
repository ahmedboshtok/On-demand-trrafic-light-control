/*
 * Application.h
 *
 *  Created on: ???/???/????
 *      Author: Ahmed Boshtok
 */

#ifndef APP_APPLICATION_H_
#define APP_APPLICATION_H_

#include "../LIBRARIES/errorStates.h"
#include"../LIBRARIES/stdTypes.h"
#include "../LIBRARIES/BIT_MASK.h"

#include  "../HALL/LED/LED_int.h"
#include"../HALL/Switch/switch_int.h"






ES_t APP_init();
ES_t APP_Start();
void NormalMode();

void toggle_YLED();





#define PEDESTRAIN_RLED      3
#define PEDESTRAIN_YLED  	 4
#define PEDESTRAIN_GLED    	 5

#define CAR_RLED             0
#define CAR_YLED          	 1
#define CAR_GLED           	 2

#define FLAG_HIGH			1
#define FLAG_LOW			0


#endif /* APP_APPLICATION_H_ */
