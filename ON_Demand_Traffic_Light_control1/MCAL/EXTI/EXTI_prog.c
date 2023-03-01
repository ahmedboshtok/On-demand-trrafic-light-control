/*
 * EXTI_prog.c
 *
 *  Created on: Oct 16, 2021
 *      Author: Ahmed Boshtok
 */
#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorStates.h"
#include "../../LIBRARIES/BIT_MASK.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"

#include "../interrupt.h"

static volatile void (* EXTI_pfunISRFun[3]) (void) = {NULL,NULL,NULL};
extern EXTI_t EXTI_AstrEXTIConfig[INT_NUM];



ES_t EXTI_enuInit()
{
	ES_t Local_enuErrorState = ES_NOK;

	/*u8 arr[]={6,7,5} ,arr2[] = {0,2,6}, Local_u8Iter=0;
	for (; Local_u8Iter<3; Local_u8Iter++)
	{
		if (Copy_pAstrEXTIConfig[Local_u8Iter].Int_State == ENABLED)
		{
			GICR |= (1<<arr[Local_u8Iter]);
			switch(Copy_pAstrEXTIConfig[Local_u8Iter])
			{
			case LOW_LEVEL:
				MCUCR &= ~(3<<arr2[Local_u8Iter]);
				break;
			case ANY_LOGICAL:
				MCUCR |=  (1<< arr2 [Local_u8Iter]);
				MCUCR &= ~(1<< (arr2[Local_u8Iter] + 1));
				break;
			case FALLING:
				MCUCR &= ~(1<<arr2 [Local_u8Iter]);
				MCUCR |=  (1<<(arr2[Local_u8Iter] + 1));
				break;
			case RISING:
				MCUCR |=  (3<<arr2 [Local_u8Iter]);
				break;
			default:
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
		else if (Copy_pAstrEXTIConfig[INT0].Int_State == DISABLED)
		{
			GICR &=~(1<<6);
		}
	}*/

	if (EXTI_AstrEXTIConfig[INT0].Int_State == ENABLED)
	{

		GICR |= (1<<6);
		switch(EXTI_AstrEXTIConfig[INT0].Sence_level)
		{
		case LOW_LEVEL:
			MCUCR &= ~(3<<0);
			break;
		case ANY_LOGICAL:
			MCUCR |=  (1<<0);
			MCUCR &= ~(1<<1);
			break;
		case FALLING:
			MCUCR &= ~(1<<0);
			MCUCR |=  (1<<1);
			break;
		case RISING:
			MCUCR |=  (3<<0);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else if (EXTI_AstrEXTIConfig[INT0].Int_State == DISABLED)
	{
		GICR &=~(1<<6);
	}

	if (EXTI_AstrEXTIConfig[INT1].Int_State == ENABLED)
	{
		GICR |= (1<<7);
		switch(EXTI_AstrEXTIConfig[INT1].Sence_level)
		{
		case LOW_LEVEL:
			MCUCR &= ~(3<<2);
			break;
		case ANY_LOGICAL:
			MCUCR |=  (1<<2);
			MCUCR &= ~(1<<3);
			break;
		case FALLING:
			MCUCR &= ~(1<<2);
			MCUCR |=  (1<<3);
			break;
		case RISING:
			MCUCR |=  (3<<2);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else if (EXTI_AstrEXTIConfig[INT1].Int_State == DISABLED)
	{
		GICR &=~(1<<7);
	}

	if (EXTI_AstrEXTIConfig[INT2].Int_State == ENABLED)
	{
		GICR |= (1<<5);
		switch(EXTI_AstrEXTIConfig[INT2].Sence_level)
		{
		case FALLING:
			MCUCSR &= ~(1<<6);
			break;
		case RISING:
			MCUCSR |=  (1<<6);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else if (EXTI_AstrEXTIConfig[INT2].Int_State == DISABLED)
	{
		GICR &=~(1<<5);
	}
	return Local_enuErrorState;
}

ES_t EXTI_enuSetSenseLevel(u8 Copy_u8IntNum, u8 Copy_u8SenceLevel)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8IntNum == INT0)
	{
		switch(Copy_u8SenceLevel)
		{
		case LOW_LEVEL:
			MCUCR &= ~(3<<0);
			break;
		case ANY_LOGICAL:
			MCUCR |=  (1<<0);
			MCUCR &= ~(1<<1);
			break;
		case FALLING:
			MCUCR &= ~(1<<0);
			MCUCR |=  (1<<1);
			break;
		case RISING:
			MCUCR |=  (3<<0);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else if (Copy_u8IntNum == INT1)
	{
		switch(Copy_u8SenceLevel)
		{
		case LOW_LEVEL:
			MCUCR &= ~(3<<2);
			break;
		case ANY_LOGICAL:
			MCUCR |=  (1<<2);
			MCUCR &= ~(1<<3);
			break;
		case FALLING:
			MCUCR &= ~(1<<2);
			MCUCR |=  (1<<3);
			break;
		case RISING:
			MCUCR |=  (3<<2);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else if (Copy_u8IntNum == INT2)
	{
		switch(Copy_u8SenceLevel)
		{
		case FALLING:
			MCUCSR &= ~(1<<6);
			break;
		case RISING:
			MCUCSR |=  (1<<6);
			break;
		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}


	return Local_enuErrorState;
}

ES_t EXTI_enuEnableInterrupt(u8 Copy_u8IntNum)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8IntNum == INT0)
	{
		GICR |= (1<<6);
	}
	else if (Copy_u8IntNum == INT1)
	{
		GICR |= (1<<7);
	}
	else if (Copy_u8IntNum == INT2)
	{
		GICR |= (1<<5);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t EXTI_enuDisableInterrupt(u8 Copy_u8IntNum)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_u8IntNum == INT0)
	{
		GICR &=~(1<<6);
	}
	else if (Copy_u8IntNum == INT1)
	{
		GICR &=~(1<<7);
	}
	else if (Copy_u8IntNum == INT2)
	{
		GICR &=~(1<<5);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t EXTI_enuCallBack(volatile void (* Copy_pfunAppFun)(void), u8 Copy_u8IntNum)
{
	ES_t Local_enuErrorState = ES_NOK;

	if (Copy_pfunAppFun != NULL)
	{
		if (Copy_u8IntNum <=2 )
		{
				EXTI_pfunISRFun[Copy_u8IntNum] = Copy_pfunAppFun;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ISR(VECT_INT0){
	if(EXTI_pfunISRFun != NULL){
		EXTI_pfunISRFun[0]();
	}

}



ISR(VECT_INT1){
	if(EXTI_pfunISRFun != NULL){
			EXTI_pfunISRFun[1]();
	}

}


ISR(VECT_INT2){
	if(EXTI_pfunISRFun != NULL){
			EXTI_pfunISRFun[2]();
}

}



