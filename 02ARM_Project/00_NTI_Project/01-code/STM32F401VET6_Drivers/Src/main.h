/*
 * main.h
 *
 *  Created on: May 13, 2022
 *      Author: Group Three
 */

#ifndef MAIN_H_
#define MAIN_H_

/***************_APP_INCLUDES_*****************************/
#include "../Src/Src_APP/Utility\APP_Utility.h"

/***************_Debug_INCLUDES_*****************************/
#include "../Src/Src_APP/Debug\APP_Debug.h"

/***************_MyApp_INCLUDES_***************************/
#include "HAL_TFT_ImagesSheet.h"

/***************_HAL_INCLUDES_*****************************/
#include "../Src/Src_HAL/LED/HAL_LED_Interface.h"
#include "../Src/Src_HAL/Keypad/HAL_Keypad_Interface.h"
#include "../Src/Src_HAL/LCD/HAL_LCD_Interface.h"
#include "../Src/Src_HAL/TFT/HAL_TFT_Interface.h"

/***************_MCAL_INCLUDES_****************************/
#include "../Src/Src_MCAL/RCC/MCAL_RCC_Interface.h"
#include "../Src/Src_MCAL/SYSTIK/MCAL_SYSTIK_Interface.h"
#include "../Src/Src_MCAL/GPIO/MCAL_GPIO_Interface.h"
#include "../Src/Src_MCAL/NVIC/MCAL_NVIC_Interface.h"
#include "../Src/Src_MCAL/EXTIx/MCAL_EXTI_Interface.h"
#include "../Src/Src_MCAL/EXTI_AM/EXTI_interface.h"

//#include "../Src/Src_MCAL/ADC/ADC_INTERFACE.h"

/***************_main.c_FUNCTION_PROTOTYPE_****************/
void GetPasswordFromUser(void);
U8 StringCompare(S8* String1 , S8 * String2);
void BuzzerSound(void);
void DefineUserCommand(void);

#endif /* MAIN_H_ */
