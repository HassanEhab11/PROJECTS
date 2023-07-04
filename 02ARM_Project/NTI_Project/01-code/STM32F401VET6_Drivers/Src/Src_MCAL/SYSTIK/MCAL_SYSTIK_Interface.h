/*
 * MCAL_SYSTIK_Interface.h
 *
 *  Created on: May 31, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef SRC_MCAL_SYSTIK_MCAL_SYSTIK_INTERFACE_H_
#define SRC_MCAL_SYSTIK_MCAL_SYSTIK_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_SYSTIK_Private.h"
#include "MCAL_SYSTIK_Config.h"
#include "MCAL_SYSTIK_Register.h"

/***************_MACROS_CONFIGURATION_*********************/
typedef enum
{
	STK_CLK_SRC_HCLK       =0U,
	STK_CLK_SRC_HCLK_Div8  =1U
}STK_CLK_SRC_t;

/*============================================================================
  ==================_APIs Supported by "MCAL_SYSTIK DRIVER"_====================
  ============================================================================*/

void MSTK_Init(STK_CLK_SRC_t STK_CLK_SRC);
void MSTK_Stop(void);

void MSTK_DelayMs(U32 Copy_u32RequiredMs);
void MSTK_DelayUs(U32 Copy_u32RequiredUs);

void MSTK_PeriodicCallBackMs(U32 Copy_u32RequiredDelay,void(*pAppFun)(void));
void MSTK_SingleCallBackMs(U32 Copy_u32RequiredDelay,void(*pAppFun)(void));

U32 MSTK_GetRemainingTime(void);
U32 MSTK_GetElapsedTime(void);

void MSTK_PWM(U8 Freq,U16 Duty,void(*pAppFun)(void));
void SysTick_Handler(void);

#endif /* SRC_MCAL_SYSTIK_MCAL_SYSTIK_INTERFACE_H_ */
