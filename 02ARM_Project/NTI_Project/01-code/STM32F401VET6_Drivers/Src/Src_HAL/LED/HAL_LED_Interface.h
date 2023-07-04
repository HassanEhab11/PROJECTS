/*
 * HAL_LED_Interface.h
 *
 *  Created on: May 19, 2022
 *      Author: Group Three
 */

#ifndef INC_HAL_LED_HAL_LED_INTERFACE_H_
#define INC_HAL_LED_HAL_LED_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/
#include "HAL_LED_Private.h"
#include "HAL_LED_Config.h"

/***************_MCAL_INCLUDES_****************************/
#include "..\..\Src_MCAL\RCC\MCAL_RCC_Interface.h"
#include "..\..\Src_MCAL\GPIO\MCAL_GPIO_Interface.h"


#define LED_0_	((U8)0U)
#define LED_1_	((U8)1U)
#define LED_2_	((U8)2U)

/*============================================================================
  ==================_APIs Supported by "HAL_LED DRIVER"_======================
  ============================================================================*/
void HLED_vInitLED(U8 LED_Name);
void HLED_vLEDStateControl(U8 LED_Name, U8 LED_State);
void HLED_vToggelLED(U8 LED_Name);

#endif /* INC_HAL_LED_HAL_LED_INTERFACE_H_ */
