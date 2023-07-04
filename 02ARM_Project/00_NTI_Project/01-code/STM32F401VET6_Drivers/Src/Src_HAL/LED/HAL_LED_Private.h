/*
 * HAL_LED_Private.h
 *
 *  Created on: May 19, 2022
 *      Author: Group Three
 */

#ifndef INC_HAL_LED_HAL_LED_PRIVATE_H_
#define INC_HAL_LED_HAL_LED_PRIVATE_H_

typedef struct
{
	U8 LED_PORT			  ;
	U8 LED_PIN			  ;
	U8 LED_PinOutputType  ;
	U8 LED_PinOutputSpeed ;
	U8 LED_PinPullType    ;
	U8 LED_State		  ;
}LED_Stag;

#define LED_ON		HIGH_STATE
#define LED_OFF		LOW_STATE

#define ENABLE_LED		1   //for CFG
#define DISABLE_LED		0	//for CFG

#endif /* INC_HAL_LED_HAL_LED_PRIVATE_H_ */
