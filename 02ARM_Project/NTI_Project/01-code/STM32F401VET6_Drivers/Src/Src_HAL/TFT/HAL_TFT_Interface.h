/*
 * HAL_TFT_Interface.h
 *
 *  Created on: Jun 1, 2022
 *      Author: Group Three
 */

#ifndef SRC_HAL_TFT_HAL_TFT_INTERFACE_H_
#define SRC_HAL_TFT_HAL_TFT_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/
#include "HAL_TFT_Private.h"
#include "HAL_TFT_Config.h"
#include "HAL_TFT_Commands.h"

/***************_MCAL_INCLUDES_****************************/
#include "../../Src_MCAL/RCC/MCAL_RCC_Interface.h"
#include "../../Src_MCAL/GPIO/MCAL_GPIO_Interface.h"
#include "../../Src_MCAL/SYSTIK/MCAL_SYSTIK_Interface.h"
#include "../../Src_MCAL/SPI/MCAL_SPI_Interface.h"

/***************_MACROS_CONFIGURATION_*********************/


/*============================================================================
  ==================_APIs Supported by "HAL_TFT DRIVER"_======================
  ============================================================================*/
/*Function to Initialize TFT*/
void HTFT_vInit(void);

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function to TFT System*/
void HTFT_vWrite_Command(U8 Copy_u8Command);
void HTFT_vWrite_Data(U16 Copy_u8Data);
void HTFT_vSetCursorPosition(U16 X_Start, U16 Y_Start, U16 X_End, U16 Y_End);

/****************************************************************************/
/*Function to Display Image TFT*/
void HTFT_vDisplay_Image(const U16* Copy_Image); /*Const to go to flash memory not Ram memory*/ //ERROR

void HTFT_vDrawPic(U16 X_Start,U16 X_End, U16 Y_Start, U16 Y_End, const U16* Copy_Image);
void HTFT_vFillColor(U16 Copy_Color);

void HTFT_vDrawRectangle(U16 X_Start,U16 X_End, U16 Y_Start, U16 Y_End, U16 Copy_u16Color);
void HTFT_vClearScreen();

void HTFT_vDrawPixel(U8 x,U16 y, U16 color);
void HTFT_vDrawPicturesPixels(U8 x1,U8 x2,U16 y1,U16 y2, const U16*Copy_Image);
void HTFT_vDrawHLine(U8 x1, U16 y1, U8 lenght, U16 color);


#endif /* SRC_HAL_TFT_HAL_TFT_INTERFACE_H_ */
