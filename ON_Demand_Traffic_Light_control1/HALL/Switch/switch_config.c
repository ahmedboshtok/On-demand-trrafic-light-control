#include "../../LIBRARIES/stdTypes.h"
#include "../../LIBRARIES/errorStates.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "switch_config.h"
#include "switch_priv.h"

SW_t Switch_AstrSwitchconfig [SW_NUM]={

		{DIO_u8GROUP_D,DIO_u8PIN2,DIO_u8FLOAT}

};
