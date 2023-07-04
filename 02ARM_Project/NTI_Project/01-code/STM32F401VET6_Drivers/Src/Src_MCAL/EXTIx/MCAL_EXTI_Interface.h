/*
 * MCAL_EXTI_Interface.h
 *
 *  Created on: May 26, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef SRC_MCAL_EXTIX_MCAL_EXTI_INTERFACE_H_
#define SRC_MCAL_EXTIX_MCAL_EXTI_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_EXTI_Private.h"
#include "MCAL_EXTI_Config.h"
#include "MCAL_EXTI_Register.h"

/***************_MACROS_CONFIGURATION_*********************/

typedef enum
{
	EXTI_LINE_0  = 0U ,
	EXTI_LINE_1  = 1U ,
	EXTI_LINE_2  = 2U ,
	EXTI_LINE_3  = 3U ,
	EXTI_LINE_4  = 4U ,
	EXTI_LINE_5  = 5U ,
	EXTI_LINE_6  = 6U ,
	EXTI_LINE_7  = 7U ,
	EXTI_LINE_8  = 8U ,
	EXTI_LINE_9  = 9U ,
	EXTI_LINE_10 = 10U,
	EXTI_LINE_11 = 11U,
	EXTI_LINE_12 = 12U,
	EXTI_LINE_13 = 13U,
	EXTI_LINE_14 = 14U,
	EXTI_LINE_15 = 15U
}EXTI_LINE_Etag;

typedef enum
{
	EXTI_PORT_A = 0U ,
	EXTI_PORT_B = 1U ,
	EXTI_PORT_C = 2U ,
	EXTI_PORT_D = 3U ,
	EXTI_PORT_E = 4U ,
	EXTI_PORT_F = 5U ,
	EXTI_PORT_G = 6U ,
	EXTI_PORT_H = 7U
}PORT_Etag;

typedef enum
{
	TRIGGER_FALLING   = 0,
	TRIGGER_RISING    = 1,
	TRIGGER_ON_CHANGE = 2
}TRIGGER_Etag;
/*============================================================================
  ==================_APIs Supported by "MCAL_EXTI DRIVER"_====================
  ============================================================================*/
void MEXTI_vEnableInterruptLine(EXTI_LINE_Etag Copy_ELineNum);
void MEXTI_vDisableInterruptLine(EXTI_LINE_Etag Copy_ELineNum);
void MEXTI_vSelectEventTrigger(EXTI_LINE_Etag Copy_ELineNum, TRIGGER_Etag Copy_EventState);
void MEXTI_vSoftwareTrigger(EXTI_LINE_Etag Copy_ELineNum);
U8 MEXTI_U8GetPendingInterrupt(EXTI_LINE_Etag Copy_ELineNum);
void MEXTI_vSelectPort(PORT_Etag Copy_ePortNum, EXTI_LINE_Etag Copy_eLineNUM);
void MEXTI_vSetCallBack(void (*ptr)(void), EXTI_LINE_Etag Copy_eLineNUM);

#endif /* SRC_MCAL_EXTIX_MCAL_EXTI_INTERFACE_H_ */
