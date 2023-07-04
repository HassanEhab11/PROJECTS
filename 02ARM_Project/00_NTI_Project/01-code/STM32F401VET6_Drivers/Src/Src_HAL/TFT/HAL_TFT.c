/*
 * HAL_TFT.c
 *
 *  Created on: Jun 1, 2022
 *      Author: Group Three
 */

#include "HAL_TFT_Interface.h"

void HTFT_vWrite_Command(U8 Copy_u8Command)
{
	/*Set Pin A0  to Low*/
	MGPIO_vWritePinData(TFT_A0_PORT, TFT_A0_PIN, LOW_STATE);
	/* Send Command over SPI*/
	MSPI1_u16TrasRes(Copy_u8Command);
}

 void HTFT_vWrite_Data(U16 Copy_u8Data)
{
	/*Set Pin A0  to High*/
	MGPIO_vWritePinData(TFT_A0_PORT, TFT_A0_PIN, HIGH_STATE);
	/* Send Data over SPI*/
	MSPI1_u16TrasRes(Copy_u8Data);
}

void HTFT_vInit(void)
{
	/* PIN Initialization */
	MGPIO_vSetPinMode(TFT_A0_PORT, TFT_A0_PIN, OUTPUT_MODE);  					/*A0*/
	MGPIO_vSetPinOutputType(TFT_A0_PORT, TFT_A0_PIN, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputSpeed(TFT_A0_PORT, TFT_A0_PIN, OUTPUT_LOW_SPEED);

	MGPIO_vSetPinMode(TFT_RST_PORT, TFT_RST_PIN, OUTPUT_MODE);			/*RESET*/
	MGPIO_vSetPinOutputType(TFT_RST_PORT, TFT_RST_PIN, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputSpeed(TFT_RST_PORT, TFT_RST_PIN, OUTPUT_LOW_SPEED);

	MGPIO_vSetPinMode(TFT_CLK_PORT, TFT_CLK_PIN, ALTERNATE_FUNCTION_MODE);			/*CLK*/
	MGPIO_vSetPinAltFun(TFT_CLK_PORT, TFT_CLK_PIN, ALTFUN_5);
	MGPIO_vSetPinOutputType(TFT_CLK_PORT, TFT_CLK_PIN, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputSpeed(TFT_CLK_PORT, TFT_CLK_PIN, OUTPUT_MEDUIM_SPEED);

	MGPIO_vSetPinMode(TFT_MOSI_PORT, TFT_MOSI_PIN, ALTERNATE_FUNCTION_MODE);				/*MOSI*/
	MGPIO_vSetPinAltFun(TFT_MOSI_PORT, TFT_MOSI_PIN, ALTFUN_5);
	MGPIO_vSetPinOutputType(TFT_MOSI_PORT, TFT_MOSI_PIN, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputSpeed(TFT_MOSI_PORT, TFT_MOSI_PIN, OUTPUT_MEDUIM_SPEED);

	/*Reset Pulse*/
	MGPIO_vWritePinData(TFT_RST_PORT,TFT_RST_PIN, HIGH_STATE);
	MSTK_DelayMs(100);
	//_delay_us(100);
	MGPIO_vWritePinData(TFT_RST_PORT,TFT_RST_PIN, LOW_STATE);
	//_delay_us(1);
	MSTK_DelayMs(1);
	MGPIO_vWritePinData(TFT_RST_PORT,TFT_RST_PIN, HIGH_STATE);
	//_delay_us(100);
	MSTK_DelayMs(100);
	MGPIO_vWritePinData(TFT_RST_PORT,TFT_RST_PIN, LOW_STATE);
	/* Wait 100 us */
	//_delay_us(100);
	MSTK_DelayMs(100);
	MGPIO_vWritePinData(TFT_RST_PORT,TFT_RST_PIN, HIGH_STATE);
	/* Wait 120 ms */
	//_delay_ms(120);
	MSTK_DelayMs(120000);
	/* Sleep Out Command */
	HTFT_vWrite_Command(SLPOUT);
	/* Wait 150 ms */
	//_delay_ms(150);
	MSTK_DelayMs(150000);
	/* Enable Color Mode  */
	HTFT_vWrite_Command(COLMOD);
	/* Enable RGB565 Command Parameter*/
	HTFT_vWrite_Data(RGB565);
	/* Enable Display*/
	HTFT_vWrite_Command(DISON);
}

void HTFT_vSetCursorPosition(U16 X_Start, U16 Y_Start, U16 X_End, U16 Y_End)
{
	/*	Set X_ADRESS  */
	HTFT_vWrite_Command(SET_X_ADDRESS);
	/* X Start Position*/
	HTFT_vWrite_Data(X_Start >>8);      		/*send higher byte*/
	HTFT_vWrite_Data(X_Start & 0x00ff);		/*send lower Byte */
	/* X End Position*/
	HTFT_vWrite_Data(X_End >>8);          /*send higher byte*/
	HTFT_vWrite_Data(X_End & 0x00ff);    /*send lower Byte */

	/*	Set Y_ADRESS */
	HTFT_vWrite_Command(SET_Y_ADDRESS);
	/* Y Start Position*/
	HTFT_vWrite_Data(Y_Start >>8);      		/*send higher byte*/
	HTFT_vWrite_Data(Y_Start & 0x00ff);		/*send lower Byte */
	/* Y End Position*/
	HTFT_vWrite_Data(Y_End >>8);          /*send higher byte*/
	HTFT_vWrite_Data(Y_End & 0x00ff);    /*send lower Byte */
}


void HTFT_vDisplay_Image(const U16* Copy_Image)
{
	U32 Counter =0;
	U32 Local_u32Size = (240) * (320); 	/*calculate image element numbers*/
	HTFT_vSetCursorPosition(0, 0, 240, 320);    /*set addresses of x and y */

	/* RAM Write Command Every thing is coming After This Command Display on TFT*/
	HTFT_vWrite_Command(RAM_WRITE);
	for(Counter = 0 ; Counter < Local_u32Size+5; Counter ++)	/*5 for protus*/
	{
		/* Write For One Pixel The High Byte Then Low Byte For Each Pixel */
		HTFT_vWrite_Data(Copy_Image[Counter] >> 8);		/* Write The High Byte */
		HTFT_vWrite_Data(Copy_Image[Counter] & 0x00ff);	/* Write The LOW  Byte */
	}
}

void HTFT_vDrawPic(U16 X_Start,U16 X_End, U16 Y_Start, U16 Y_End, const U16* Copy_Image)
{
	U32 Counter =0;
	U32 Local_u32Size = (X_End - X_Start) * (Y_End - Y_Start); 	/*calculate image element numbers*/
	HTFT_vSetCursorPosition(X_Start, Y_Start, X_End, Y_End);    /*set addresses of x and y */

	/* RAM Write Command Every thing is coming After This Command Display on TFT*/
	HTFT_vWrite_Command(RAM_WRITE);
	for(Counter = 0 ; Counter < Local_u32Size+5; Counter ++)	/*5 for protus*/
	{
		/* Write For One Pixel The High Byte Then Low Byte For Each Pixel */
		HTFT_vWrite_Data(Copy_Image[Counter] >> 8);		/* Write The High Byte */
		HTFT_vWrite_Data(Copy_Image[Counter] & 0x00ff);	/* Write The LOW  Byte */
	}
}

 void HTFT_vFillColor(U16 Copy_u16Color)
  {
	U32 Loc_u32Counter = 0;
	U32 Local_u32Size =( 240 ) * ( 320+5 ) ; /*calculate image element numbers*/
	HTFT_vSetCursorPosition(0, 0, 240, 320);    /*set addresses of x and y */

	/* RAM Write  */
	HTFT_vWrite_Command(RAM_WRITE);
	for(Loc_u32Counter=0;  Loc_u32Counter < Local_u32Size; Loc_u32Counter++)
	{
		/* Write For One Pixel The High Byte Then Low Byte For Each Pixel */
		/* Write The High Byte */
		HTFT_vWrite_Data(Copy_u16Color >> 8);
		/* Write The LOW Byte */
		HTFT_vWrite_Data(Copy_u16Color &0x00ff);
	}
}


void HTFT_vDrawRectangle(U16 X_Start,U16 X_End, U16 Y_Start, U16 Y_End, U16 Copy_u16Color)
{
	U32 Counter =0;
	U32 Local_u32Size =( X_End - X_Start ) * ( Y_End - Y_Start ) ; /*calculate image element numbers*/
	HTFT_vSetCursorPosition(X_Start, Y_Start, X_End, Y_End);	   /*set addresses of x and y */

	/* RAM Write Command Every thing is coming After This Command Display on TFT*/
	HTFT_vWrite_Command(RAM_WRITE);
	for(Counter = 0 ; Counter < Local_u32Size+5 ; Counter ++)
	{
		/* Write For One Pixel The High Byte Then Low Byte For Each Pixel */
		/* Write The High Byte */
		HTFT_vWrite_Data(Copy_u16Color >> 8);
		/* Write The LOW Byte */
		HTFT_vWrite_Data(Copy_u16Color &0x00ff);
	}
}

void HTFT_vClearScreen()
{
	HTFT_vDrawRectangle(0, 240, 0, 320, 0xffff); /* if used all scren it should be 240 X 320 */
}

void HTFT_vDrawPixel(U8 x,U16 y, U16 color)
{
	HTFT_vSetCursorPosition(x,y,x,y);
	/* RAM Write Command Every thing is coming After This Command Display on TFT*/
	HTFT_vWrite_Command(0x2C);
	/* Write The High Byte */
	HTFT_vWrite_Data(color >> 8);
	/* Write The LOW Byte */
	HTFT_vWrite_Data(color &0x00ff);
}

void HTFT_vDrawHLine(U8 x1, U16 y1, U8 lenght, U16 color)
{
	U16 i = 0 ;
	for(i=0; i <lenght; i++)
	{
		HTFT_vDrawPixel(x1+i ,y1 ,color);
	}
}

void HTFT_vDrawPicturesPixels(U8 x1,U8 x2,U16 y1,U16 y2,const U16*Copy_Image)
{
 	U32 Counter =0 ;
 	U16 x_max =( x2 - x1 );
 	U16 y_max =( y2 - y1 );
 	U16 xi=0;
 	U16 yi=0;
 	for (yi = 0 ; yi < y_max ; yi++)
 	{
 		for (xi = 0 ; xi < x_max ; xi++)
 		{
 			HTFT_vDrawPixel(x1+xi, y1+yi, Copy_Image[Counter]);
 			Counter++;
 		}
 	}
}
