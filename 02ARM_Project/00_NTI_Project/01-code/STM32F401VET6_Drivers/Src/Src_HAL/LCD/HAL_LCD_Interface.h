/*
 * HAL_LCD_Interface.h
 *
 *  Created on: May 30, 2022
 *      Author: Group Three
 */

#ifndef SRC_HAL_LCD_HAL_LCD_INTERFACE_H_
#define SRC_HAL_LCD_HAL_LCD_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/
#include "HAL_LCD_Private.h"
#include "HAL_LCD_Config.h"
#include "HAL_LCD_Commands.h"

/***************_MCAL_INCLUDES_****************************/
#include "..\..\Src_MCAL\RCC\MCAL_RCC_Interface.h"
#include "..\..\Src_MCAL\GPIO\MCAL_GPIO_Interface.h"

/*FLOAT_RESELUTION options:
[1]->0,						[0 point]
[10]->0.0,					[1 point]
[100]->0.00,				[2 point]
[1000]->0.000,				[3 point]
[10000]->0.0000				[4 point]
Max[100000000]->0.000000	[6 point]*/
#define FLOAT_RESELUTION		100

#define CHAR_HEART		    1U
#define CHAR_BATTARY	    2U
#define CHAR_RING		    3U
#define CHAR_SPEAKER	    4U
#define CHAR_MUSIC		    5U
#define CHAR_POWER_CABLE	6U
#define CHAR_HAPPY_FACE		7U


/*============================================================================
  ==================_APIs Supported by "HAL_LCD DRIVER"_======================
  ============================================================================*/
void HLCD_vInitiate(void);
void HLCD_vWriteCommand(U8 loc_U8_LCD_COMMAND);
void HLCD_vClearScreen(void);
void HLCD_vGoTo(U8 loc_U8_Row, U8 loc_U8_Col);
void HLCD_vBuildCustomChar (U8 MemoryLocation, U8 CChar_Name);
/***********************************************************************/
void HLCD_vWriteCharacter(U8 loc_U8_CHARACTER);
void HLCD_vWriteString(U8 *loc_U8_PTR_STRING);
void HLCD_vWriteNumber(S32 loc_S32_NUMBER);
void HLCD_vWriteNumber_Bin(U8 loc_U8_NUMBER);
void HLCD_vWriteNumber_Hex(U8 loc_U8_NUMBER);

#endif /* SRC_HAL_LCD_HAL_LCD_INTERFACE_H_ */
