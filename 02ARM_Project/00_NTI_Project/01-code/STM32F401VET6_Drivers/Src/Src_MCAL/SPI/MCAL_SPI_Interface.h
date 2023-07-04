/*
 * MCAL_SPI_Interface.h
 *
 *  Created on: Jun 1, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef SRC_MCAL_SPI_MCAL_SPI_INTERFACE_H_
#define SRC_MCAL_SPI_MCAL_SPI_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_SPI_Private.h"
#include "MCAL_SPI_Config.h"
#include "MCAL_SPI_Register.h"

/***************_MACROS_CONFIGURATION_*********************/
 #define SPI_1_      1U
 #define SPI_2_      2U
 #define SPI_3_      3U
 #define SPI_4_      4U

/*============================================================================
  ==================_APIs Supported by "MCAL_SPI DRIVER"_====================
  ============================================================================*/
void MSPI_vInit(U8 Copy_u8SPIx);
void MSPI_vEnable(U8 Copy_u8SPIx);
U16 MSPI1_u16TrasRes(U16 Copy_u16Data);
void MSPI1_vSetCallBack( void (*ptr)(void));


#endif /* SRC_MCAL_SPI_MCAL_SPI_INTERFACE_H_ */
