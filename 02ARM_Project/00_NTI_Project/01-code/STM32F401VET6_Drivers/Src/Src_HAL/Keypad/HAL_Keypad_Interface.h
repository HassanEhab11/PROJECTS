/*
 * HAL_Keypad_Interface.h
 *
 *  Created on: May 30, 2022
 *      Author: Group Three
 */

#ifndef SRC_HAL_KEYPAD_HAL_KEYPAD_INTERFACE_H_
#define SRC_HAL_KEYPAD_HAL_KEYPAD_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/
#include "HAL_Keypad_Private.h"
#include "HAL_Keypad_Config.h"

/***************_MCAL_INCLUDES_****************************/
#include "..\..\Src_MCAL\RCC\MCAL_RCC_Interface.h"
#include "..\..\Src_MCAL\GPIO\MCAL_GPIO_Interface.h"

/*============================================================================
  ==================_APIs Supported by "HAL_Keypad DRIVER"_===================
  ============================================================================*/
void HKEYPAD_vInitiate(void);
U8 HKEYPAD_U8READ(void);

#endif /* SRC_HAL_KEYPAD_HAL_KEYPAD_INTERFACE_H_ */
