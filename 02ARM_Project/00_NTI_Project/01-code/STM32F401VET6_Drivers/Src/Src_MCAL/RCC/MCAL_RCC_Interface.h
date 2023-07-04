/*
 * MCAL_RCC_Interface.h
 *
 *  Created on: May 13, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef INC_MCAL_RCC_MCAL_RCC_INTERFACE_H_
#define INC_MCAL_RCC_MCAL_RCC_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_RCC_Private.h"
#include "MCAL_RCC_Config.h"
#include "MCAL_RCC_Register.h"

/***************_MACROS_CONFIGURATION_*********************/
/*********        **********/
#define   Bus_AHB1   0U  /**/
#define   Bus_AHB2   1U  /**/
#define   Bus_APB1   2U  /**/
#define   Bus_APB2   3U  /**/
/***************************/
/*********                **********/
#define   MCO_1_SOURCE_LSE   0U
#define   MCO_1_SOURCE_HSE   1U
#define   MCO_1_SOURCE_HSI   2U
#define   MCO_1_SOURCE_PLL   3U
/***********************************/
/*********                 **********/
#define   MCO_1_PRESCALER_1   0U
#define   MCO_1_PRESCALER_2   1U
#define   MCO_1_PRESCALER_3   2U
#define   MCO_1_PRESCALER_4   3U
#define   MCO_1_PRESCALER_5   4U
/************************************/
#define	  PHB1_GPIOA     0U
#define	  PHB1_GPIOB     1U
#define	  PHB1_GPIOC     2U
#define	  PHB1_GPIOD     3U
#define	  PHB1_GPIOE     4U
#define	  PHB1_GPIOF     5U
#define	  PHB1_GPIOG     6U
#define	  PHB1_GPIOH     7U
#define	  PHB1_GPIOI     8U
#define	  PHB1_CRC       12U
#define	  PHB1_DMA1      21U
#define	  PHB1_DMA2      22U

/*-----------------------------------*/
#define   PHB2_OTGFS     7U
/*-----------------------------------*/
#define   PPB1_TIM2      0U
#define   PPB1_TIM3      1U
#define   PPB1_TIM4      2U
#define   PPB1_TIM5      3U
#define   PPB1_WWDG      11U
#define   PPB1_SPI2      14U
#define   PPB1_SPI3      15U
#define   PPB1_USART2    17U
#define   PPB1_I2C1      21U
#define   PPB1_I2C2      22U
#define   PPB1_I2C3      23U
#define   PPB1_PWR       28U
/*-----------------------------------*/
#define   PPB2_TIM1      0U
#define   PPB2_USART1    4U
#define   PPB2_USART6    5U
#define   PPB2_ADC1      8U
#define   PPB2_SDIO      11U
#define   PPB2_SPI1      12U
#define   PPB2_SPI4      13U
#define   PPB2_SYSCFG    14U
#define   PPB2_TIM9      16U
#define   PPB2_TIM10     17U
#define   PPB2_TIM11     18U
/*============================================================================
  ==================_APIs Supported by "MCAL_RCC DRIVER"_====================
  ============================================================================*/
void MRCC_vInitSystemClock(void);

void MRCC_vEnableBusClock(U8 AxBxENR_RCC_Bus ,U8 Peripheral_PPxx);
void MRCC_vDisableBusClock(U8 AxBxENR_RCC_Bus , U8 Peripheral_PPxx);

void MRCC_vEnableSecuritySystem(void);
void MRCC_vDisableSecuritySystem(void);

void MRCC_vOutMCO_1(U8 MCO_1_Source);
void MRCC_vOutMCO_1_Prescaler(U8 MCO_1_Prescaler);

#endif /* INC_MCAL_RCC_MCAL_RCC_INTERFACE_H_ */
