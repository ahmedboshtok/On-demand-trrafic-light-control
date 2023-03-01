/*
 * main.c
 *
 *  Created on: Feb 23, 2022
 *      Author: Ahmed Boshtok
 */



#include "Application.h"

int main(){
	APP_init();


	while (1){

		APP_Start();
	}

	return 0;
}

/*
void delay(void){
	for (int i=0;i<=220;i++){
		for (int j=0;j<=200;j++){
			__asm("NOP");
		}
	}
}
int main(){
	DIO_enuInit();
	while (1){
		DIO_enuSetPinValue(DIO_u8GROUP_A,DIO_u8PIN0,DIO_u8HIGH );
		delay();
		DIO_enuSetPinValue(DIO_u8GROUP_A,DIO_u8PIN0,DIO_u8LOW );
		delay();

	}

	return 0;
}*/

