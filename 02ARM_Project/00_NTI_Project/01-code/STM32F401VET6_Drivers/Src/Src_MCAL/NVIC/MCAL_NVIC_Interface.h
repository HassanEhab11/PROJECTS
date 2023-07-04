/*
 * MCAL_NVIC_Interface.h
 *
 *  Created on: May 17, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef INC_MCAL_NVIC_MCAL_NVIC_INTERFACE_H_
#define INC_MCAL_NVIC_MCAL_NVIC_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_NVIC_Private.h"
#include "MCAL_NVIC_Config.h"
#include "MCAL_NVIC_Register.h"

/***************_MACROS_CONFIGURATION_*********************/

typedef enum
{
/******  STM32 specific Interrupt Numbers **********************************************************************/
  IRQn_WWDG                   = 0U,      /*!< Window WatchDog Interrupt                                         */
  IRQn_PVD                    = 1U,      /*!< PVD through EXTI Line detection Interrupt                         */
  IRQn_TAMP_STAMP             = 2U,      /*!< Tamper and TimeStamp interrupts through the EXTI line             */
  IRQn_RTC_WKUP               = 3U,      /*!< RTC Wakeup interrupt through the EXTI line                        */
  IRQn_FLASH                  = 4U,      /*!< FLASH global Interrupt                                            */
  IRQn_RCC                    = 5U,      /*!< RCC global Interrupt                                              */
  IRQn_EXTI0                  = 6U,      /*!< EXTI Line0 Interrupt                                              */
  IRQn_EXTI1                  = 7U,      /*!< EXTI Line1 Interrupt                                              */
  IRQn_EXTI2                  = 8U,      /*!< EXTI Line2 Interrupt                                              */
  IRQn_EXTI3                  = 9U,      /*!< EXTI Line3 Interrupt                                              */
  IRQn_EXTI4                  = 10U,     /*!< EXTI Line4 Interrupt                                              */
  IRQn_DMA1_Stream0           = 11U,     /*!< DMA1 Stream 0 global Interrupt                                    */
  IRQn_DMA1_Stream1           = 12U,     /*!< DMA1 Stream 1 global Interrupt                                    */
  IRQn_DMA1_Stream2           = 13U,     /*!< DMA1 Stream 2 global Interrupt                                    */
  IRQn_DMA1_Stream3           = 14U,     /*!< DMA1 Stream 3 global Interrupt                                    */
  IRQn_DMA1_Stream4           = 15U,     /*!< DMA1 Stream 4 global Interrupt                                    */
  IRQn_DMA1_Stream5           = 16U,     /*!< DMA1 Stream 5 global Interrupt                                    */
  IRQn_DMA1_Stream6           = 17U,     /*!< DMA1 Stream 6 global Interrupt                                    */
  IRQn_ADC                    = 18U,     /*!< ADC1, ADC2 and ADC3 global Interrupts                             */
  IRQn_EXTI_5_9                = 23U,     /*!< External Line[9:5] Interrupts                                     */
  IRQn_TIM1_BRK_TIM9          = 24U,     /*!< TIM1 Break interrupt and TIM9 global interrupt                    */
  IRQn_TIM1_UP_TIM10          = 25U,     /*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
  IRQn_TIM1_TRG_COM_TIM11     = 26U,     /*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
  IRQn_TIM1_CC                = 27U,     /*!< TIM1 Capture Compare Interrupt                                    */
  IRQn_TIM2                   = 28U,     /*!< TIM2 global Interrupt                                             */
  IRQn_TIM3                   = 29U,     /*!< TIM3 global Interrupt                                             */
  IRQn_TIM4                   = 30U,     /*!< TIM4 global Interrupt                                             */
  IRQn_I2C1_EV                = 31U,     /*!< I2C1 Event Interrupt                                              */
  IRQn_I2C1_ER                = 32U,     /*!< I2C1 Error Interrupt                                              */
  IRQn_I2C2_EV                = 33U,     /*!< I2C2 Event Interrupt                                              */
  IRQn_I2C2_ER                = 34U,     /*!< I2C2 Error Interrupt                                              */
  IRQn_SPI1                   = 35U,     /*!< SPI1 global Interrupt                                             */
  IRQn_SPI2                   = 36U,     /*!< SPI2 global Interrupt                                             */
  IRQn_USART1                 = 37U,     /*!< USART1 global Interrupt                                           */
  IRQn_USART2                 = 38U,     /*!< USART2 global Interrupt                                           */
  IRQn_EXTI_10_15              = 40U,     /*!< External Line[15:10] Interrupts                                   */
  IRQn_RTC_Alarm              = 41U,     /*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
  IRQn_OTG_FS_WKUP            = 42U,     /*!< USB OTG FS Wakeup through EXTI line interrupt                     */
  IRQn_DMA1_Stream7           = 47U,     /*!< DMA1 Stream7 Interrupt                                            */
  IRQn_SDIO                   = 49U,     /*!< SDIO global Interrupt                                             */
  IRQn_TIM5                   = 50U,     /*!< TIM5 global Interrupt                                             */
  IRQn_SPI3                   = 51U,     /*!< SPI3 global Interrupt                                             */
  IRQn_DMA2_Stream0           = 56U,     /*!< DMA2 Stream 0 global Interrupt                                    */
  IRQn_DMA2_Stream1           = 57U,     /*!< DMA2 Stream 1 global Interrupt                                    */
  IRQn_DMA2_Stream2           = 58U,     /*!< DMA2 Stream 2 global Interrupt                                    */
  IRQn_DMA2_Stream3           = 59U,     /*!< DMA2 Stream 3 global Interrupt                                    */
  IRQn_DMA2_Stream4           = 60U,     /*!< DMA2 Stream 4 global Interrupt                                    */
  IRQn_OTG_FS                 = 67U,     /*!< USB OTG FS global Interrupt                                       */
  IRQn_DMA2_Stream5           = 68U,     /*!< DMA2 Stream 5 global interrupt                                    */
  IRQn_DMA2_Stream6           = 69U,     /*!< DMA2 Stream 6 global interrupt                                    */
  IRQn_DMA2_Stream7           = 70U,     /*!< DMA2 Stream 7 global interrupt                                    */
  IRQn_USART6                 = 71U,     /*!< USART6 global interrupt                                           */
  IRQn_I2C3_EV                = 72U,     /*!< I2C3 event interrupt                                              */
  IRQn_I2C3_ER                = 73U,     /*!< I2C3 error interrupt                                              */
  IRQn_FPU                    = 81U,     /*!< FPU global interrupt                                              */
} IRQn_Etag;

#define			_ALL_BITS_GROUP			    0U
#define			_3_BIT_GROUP_1_BIT_SUB		1U
#define			_2_BIT_GROUP_2_BIT_SUB		2U
#define			_1_BIT_GROUP_3_BIT_SUB		3U
#define			_ALL_BITS_SUB			    4U

/*============================================================================
  ==================_APIs Supported by "MCAL_NVIC DRIVER"_====================
  ============================================================================*/
/*Enables/Disables an interrupt .*/
void MNVIC_vEnableInterruptRequest_IRQ(IRQn_Etag Copy_tIRQ);
void MNVIC_vDisableInterruptRequest_IRQ(IRQn_Etag Copy_tIRQ);
/*Sets/Clears the pending status of interrupt or exception to 1.*/
void MNVIC_vSet_IRQPendingInterrupt(IRQn_Etag Copy_tIRQ);
void MNVIC_vClear_IRQPendingInterrupt(IRQn_Etag Copy_tIRQ);
/*Return the IRQ number of the active interrupt*/
U8 MNVIC_U8Get_IRQ_ActiveFlag(IRQn_Etag Copy_tIRQ);

void MNVIC_vASetGroupSubgroupPriority(IRQn_Etag Copy_tIRQ, U8 Copy_u8GroupPri, U8 Copy_u8SubGroupPri);

#endif /* INC_MCAL_NVIC_MCAL_NVIC_INTERFACE_H_ */
