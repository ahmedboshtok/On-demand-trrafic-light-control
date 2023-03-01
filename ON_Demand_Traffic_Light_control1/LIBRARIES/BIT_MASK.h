/*
 * BIT_MASK.h
 *
 *  Created on: Nov 7, 2021
 *      Author: abosh
 */

#ifndef BIT_MASK_H_
#define BIT_MASK_H_

#define SETBIT(PORT_ID,PIN_ID)			(PORT_ID |=(1<<PIN_ID))
#define CLEARBIT(PORT_ID,PIN_ID)		(PORT_ID &=~(1<<PIN_ID))
#define TOGGLEBIT(PORT_ID,PIN_ID)		(PORT_ID ^=(1<<PIN_ID))
#define GETBIT(PORT_ID,PIN_ID)			((PORT_ID)>>(PIN_IN)) & 0x01)
#endif /* BIT_MASK_H_ */
