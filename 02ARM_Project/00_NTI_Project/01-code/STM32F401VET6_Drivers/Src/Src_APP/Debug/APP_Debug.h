/*
 * APP_Debug.h
 *
 *  Created on: May 19, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef SRC_APP_DEBUG_APP_DEBUG_H_
#define SRC_APP_DEBUG_APP_DEBUG_H_

/***************_APP_INCLUDES_*****************************/
#include "..\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/
#include "..\..\Src_HAL\LED\HAL_LED_Interface.h"

/***************_MCAL_INCLUDES_****************************/
#include "..\..\Src_MCAL\RCC\MCAL_RCC_Interface.h"
#include "..\..\Src_MCAL\GPIO\MCAL_GPIO_Interface.h"
#include "../Src/Src_MCAL/NVIC/MCAL_NVIC_Interface.h"
#include "../Src/Src_MCAL/EXTIx/MCAL_EXTI_Interface.h"

/***************_APP_Debug.c_FUNCTION_PROTOTYPE_****************/
void ADebug_vAll_GPIO_Ports (void);
void ADebug_vFlashingPins (void);
void ADebug_vLED_Driver (void);

#endif /* SRC_APP_DEBUG_APP_DEBUG_H_ */
