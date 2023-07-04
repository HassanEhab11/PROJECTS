/*
 * MCAL_EXTI_Register.h
 *
 *  Created on: May 26, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef SRC_MCAL_EXTIX_MCAL_EXTI_REGISTER_H_
#define SRC_MCAL_EXTIX_MCAL_EXTI_REGISTER_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

			#define EXTI_PERIPHERAL_BASE_ADDRESS  		0x40013C00
			#define SYSCFG_PERIPHERAL_BASE_ADDRESS      0x40013800

/*==========================================================================================
	-----> Register Map
============================================================================================*/
typedef struct
{

	volatile Reg_32Bit_Utag REG_SYSCFG_MEMRMP     ;
	volatile Reg_32Bit_Utag REG_SYSCFG_PMC        ;
	volatile Reg_32Bit_Utag REG_SYSCFG_EXTICR[4]  ;
	volatile Reg_32Bit_Utag REG_SYSCFG_CMPCR      ;

}SYSCFG_PERIPHERAL_Stag;

typedef struct
{
	volatile Reg_32Bit_Utag REG_EXTI_IMR   ;	   /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
	volatile Reg_32Bit_Utag REG_EXTI_EMR   ;       /*!< EXTI Event mask register,                Address offset: 0x04 */
	volatile Reg_32Bit_Utag REG_EXTI_RTSR  ;       /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
	volatile Reg_32Bit_Utag REG_EXTI_FTSR  ;       /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
	volatile Reg_32Bit_Utag REG_EXTI_SWIER ;       /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
	volatile Reg_32Bit_Utag REG_EXTI_PR    ;       /*!< EXTI Pending register,                   Address offset: 0x14 */
}EXTI_PERIPHERAL_Stag;

/*============================================================================================
	-)	Struct Pointer :	Base_Address ->	SYSCFG
  ============================================================================================*/
#define SYSCFG_SPTR          ((SYSCFG_PERIPHERAL_Stag  *)(SYSCFG_PERIPHERAL_BASE_ADDRESS))
/*============================================================================================
	-)	Struct Pointer :	Base_Address ->	EXTI
  ============================================================================================*/
#define EXTI_SPTR 		     ((EXTI_PERIPHERAL_Stag *)(EXTI_PERIPHERAL_BASE_ADDRESS))

#endif /* SRC_MCAL_EXTIX_MCAL_EXTI_REGISTER_H_ */
