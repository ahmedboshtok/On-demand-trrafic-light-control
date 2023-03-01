/*
  * switch_config.h
 *
 *  Created on: Oct 7, 2021
 *      Author: Ahmed Boshtok
 */

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

#define SW_NUM		1
typedef struct {
	u8 sw_port;
	u8 sw_pin;
	u8 sw_state;

}SW_t;
#endif /* SWITCH_CONFIG_H_ */
