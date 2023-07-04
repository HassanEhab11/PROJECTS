/*
 * HAL_LED.c
 *
 *  Created on: May 19, 2022
 *      Author: Group Three
 */

#include "HAL_LED_Interface.h"

/**********_Hardware_LED_x_CFG_***********/
LED_Stag LEDs_0_CFG;
LED_Stag LEDs_1_CFG;
LED_Stag LEDs_2_CFG;
/************************************/

static LED_Stag* HLED_Sptr_LEDSelect(U8 LED_Name)
{
	LED_Stag *LED_ptr = NULL;
	switch(LED_Name)
	{
	#if LED_0_ENABLE		== 	ENABLE_LED
		case LED_0_ : LED_ptr = &LEDs_0_CFG;      break ;
	#else
	#endif
	#if LED_1_ENABLE		== 	ENABLE_LED
		case LED_1_ : LED_ptr = &LEDs_1_CFG;      break ;
	#else
	#endif
	#if LED_2_ENABLE		==  ENABLE_LED
		case LED_2_ : LED_ptr = &LEDs_2_CFG;      break ;
	#else
	#endif
		default :		break ;
	}
	return LED_ptr ;
}

void HLED_vInitLED(U8 LED_Name)
{
	LED_Stag *LED_ptr = NULL;
	LED_ptr = HLED_Sptr_LEDSelect(LED_Name);
	switch(LED_Name)
	{
	#if LED_0_ENABLE		== 	ENABLE_LED
		case LED_0_:
			LED_ptr->LED_PORT           = LED_0_PORT_CFG          ;
			LED_ptr->LED_PIN            = LED_0_PIN_CFG           ;
			LED_ptr->LED_PinOutputType  = LED_0_PinOutputType_CFG ;
			LED_ptr->LED_PinOutputSpeed = LED_0_PinOutputSpeed_CFG;
			LED_ptr->LED_PinPullType    = LED_0_PinPullType_CFG   ;
		break;
	#else
	#endif
	#if LED_1_ENABLE		== 	ENABLE_LED
		case LED_1_:
			LED_ptr->LED_PORT           = LED_1_PORT_CFG          ;
			LED_ptr->LED_PIN            = LED_1_PIN_CFG           ;
			LED_ptr->LED_PinOutputType  = LED_1_PinOutputType_CFG ;
			LED_ptr->LED_PinOutputSpeed = LED_1_PinOutputSpeed_CFG;
			LED_ptr->LED_PinPullType    = LED_1_PinPullType_CFG   ;
		break;
	#else
	#endif
	#if LED_2_ENABLE		== 	ENABLE_LED
		case LED_2_:
			LED_ptr->LED_PORT           = LED_2_PORT_CFG          ;
			LED_ptr->LED_PIN            = LED_2_PIN_CFG           ;
			LED_ptr->LED_PinOutputType  = LED_2_PinOutputType_CFG ;
			LED_ptr->LED_PinOutputSpeed = LED_2_PinOutputSpeed_CFG;
			LED_ptr->LED_PinPullType    = LED_2_PinPullType_CFG   ;
		break;
	#else
	#endif
		default:		break;
	}
	MRCC_vEnableBusClock(Bus_AHB1, LED_ptr->LED_PORT);
	MGPIO_vSetPinMode(LED_ptr->LED_PORT, LED_ptr->LED_PIN, OUTPUT_MODE);
	MGPIO_vSetPinOutputType(LED_ptr->LED_PORT, LED_ptr->LED_PIN, LED_ptr->LED_PinOutputType);
	MGPIO_vSetPinOutputSpeed(LED_ptr->LED_PORT, LED_ptr->LED_PIN, LED_ptr->LED_PinOutputSpeed);
	MGPIO_vSetPinPullType(LED_ptr->LED_PORT, LED_ptr->LED_PIN, LED_ptr->LED_PinPullType);
}

void HLED_vLEDStateControl(U8 LED_Name, U8 LED_State)
{
	LED_Stag *LED_ptr = NULL;
	LED_ptr = HLED_Sptr_LEDSelect(LED_Name);

	MGPIO_vWritePinData(LED_ptr->LED_PORT, LED_ptr->LED_PIN, LED_State);
}

void HLED_vToggelLED(U8 LED_Name)
{
	LED_Stag *LED_ptr = NULL;
	LED_ptr = HLED_Sptr_LEDSelect(LED_Name);
	MGPIO_vToggle_Pin(LED_ptr->LED_PORT, LED_ptr->LED_PIN);
}
