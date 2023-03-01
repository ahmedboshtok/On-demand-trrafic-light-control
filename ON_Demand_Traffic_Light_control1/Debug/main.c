/*
 * main.c
 *
 *  Created on: Oct 4, 2021
 *      Author: abosh
 */
#include "stdTypes.h"
#include "errorState.h"
#include "LED_int.h"


int main(){
	LED_int(DIO_u8GROUP_A,DIO_u8PIN4);
	while (1){
		LED_ON(DIO_u8GROUP_A,DIO_u8PIN4);

	}

	return 0;
}

