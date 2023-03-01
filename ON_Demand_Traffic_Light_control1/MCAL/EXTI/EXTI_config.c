#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorStates.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"


EXTI_t EXTI_AstrEXTIConfig[INT_NUM]=
	{
			{ENABLED, FALLING},	  //int 0
			{DISABLED, DISABLED}, //int 1
			{DISABLED, DISABLED}	  //int 2
	};
