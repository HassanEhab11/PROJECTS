/*
 * MCAL_GPIO_Register.h
 *
 *  Created on: May 16, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef INC_MCAL_GPIO_MCAL_GPIO_REGISTER_H_
#define INC_MCAL_GPIO_MCAL_GPIO_REGISTER_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

#define GPIOA_PERIPHERAL_BASE_ADDRESS     0x40020000
#define GPIOB_PERIPHERAL_BASE_ADDRESS     0x40020400
#define GPIOC_PERIPHERAL_BASE_ADDRESS     0x40020800
#define GPIOD_PERIPHERAL_BASE_ADDRESS     0x40020C00
#define GPIOE_PERIPHERAL_BASE_ADDRESS     0x40021000
#define GPIOH_PERIPHERAL_BASE_ADDRESS     0x40021C00

typedef struct {
	volatile Reg_32Bit_Utag GPIO_MODER   ;    /*!< GPIO port mode register,               Address offset: 0x00      */
	volatile Reg_32Bit_Utag GPIO_OTYPER  ;    /*!< GPIO port output type register,        Address offset: 0x04      */
	volatile Reg_32Bit_Utag GPIO_OSPEEDR ;    /*!< GPIO port output speed register,       Address offset: 0x08      */
	volatile Reg_32Bit_Utag GPIO_PUPDR   ;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	volatile Reg_32Bit_Utag GPIO_IDR     ;    /*!< GPIO port input data register,         Address offset: 0x10      */
	volatile Reg_32Bit_Utag GPIO_ODR     ;    /*!< GPIO port output data register,        Address offset: 0x14      */
	volatile Reg_32Bit_Utag GPIO_BSRR    ;    /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
	volatile Reg_32Bit_Utag GPIO_LCKR    ;    /*!< GPIO port configuration lock register, Address offset: 0x1C      */
	volatile Reg_32Bit_Utag GPIO_AFRL    ;    /*!< GPIO alternate function low registers, Address offset: 0x20-0x24 */
	volatile Reg_32Bit_Utag GPIO_AFRH    ;    /*!< GPIO alternate function high registers 							*/
} GPIO_PERIPHERAL_Stag;

/*============================================================================================
	-)	Struct Pointer :	Base_Address ->	GPIOx
  ============================================================================================*/
#define GPIOA_SPTR      ((volatile GPIO_PERIPHERAL_Stag *)GPIOA_PERIPHERAL_BASE_ADDRESS)
#define GPIOB_SPTR      ((volatile GPIO_PERIPHERAL_Stag *)GPIOB_PERIPHERAL_BASE_ADDRESS)
#define GPIOC_SPTR      ((volatile GPIO_PERIPHERAL_Stag *)GPIOC_PERIPHERAL_BASE_ADDRESS)
#define GPIOD_SPTR      ((volatile GPIO_PERIPHERAL_Stag *)GPIOD_PERIPHERAL_BASE_ADDRESS)
#define GPIOE_SPTR      ((volatile GPIO_PERIPHERAL_Stag *)GPIOE_PERIPHERAL_BASE_ADDRESS)
#define GPIOH_SPTR      ((volatile GPIO_PERIPHERAL_Stag *)GPIOH_PERIPHERAL_BASE_ADDRESS)

#endif /* INC_MCAL_GPIO_MCAL_GPIO_REGISTER_H_ */
