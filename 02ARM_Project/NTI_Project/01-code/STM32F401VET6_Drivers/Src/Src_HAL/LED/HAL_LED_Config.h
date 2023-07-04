/*
 * HAL_LED_Config.h
 *
 *  Created on: May 19, 2022
 *      Author: Group Three
 */

#ifndef INC_HAL_LED_HAL_LED_CONFIG_H_
#define INC_HAL_LED_HAL_LED_CONFIG_H_


#define LED_0_ENABLE			     ENABLE_LED
#define LED_0_PORT_CFG               PHB1_GPIOD
#define LED_0_PIN_CFG                GPIO_PIN_12
#define LED_0_PinOutputType_CFG      OUTPUT_PUSH_PULL_TYPE
#define LED_0_PinOutputSpeed_CFG     OUTPUT_LOW_SPEED
#define LED_0_PinPullType_CFG        PULL_UP_STATE

#define LED_1_ENABLE			     ENABLE_LED
#define LED_1_PORT_CFG               PHB1_GPIOA
#define LED_1_PIN_CFG                GPIO_PIN_1
#define LED_1_PinOutputType_CFG      OUTPUT_PUSH_PULL_TYPE
#define LED_1_PinOutputSpeed_CFG     OUTPUT_LOW_SPEED
#define LED_1_PinPullType_CFG        PULL_UP_STATE

#define LED_2_ENABLE			     ENABLE_LED
#define LED_2_PORT_CFG               PHB1_GPIOA
#define LED_2_PIN_CFG                GPIO_PIN_2
#define LED_2_PinOutputType_CFG      OUTPUT_PUSH_PULL_TYPE
#define LED_2_PinOutputSpeed_CFG     OUTPUT_LOW_SPEED
#define LED_2_PinPullType_CFG        PULL_UP_STATE

#endif /* INC_HAL_LED_HAL_LED_CONFIG_H_ */
