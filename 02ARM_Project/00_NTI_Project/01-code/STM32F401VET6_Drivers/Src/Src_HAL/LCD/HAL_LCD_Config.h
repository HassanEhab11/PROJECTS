/*
 * HAL_LCD_Config.h
 *
 *  Created on: May 30, 2022
 *      Author: Group Three
 */

#ifndef SRC_HAL_LCD_HAL_LCD_CONFIG_H_
#define SRC_HAL_LCD_HAL_LCD_CONFIG_H_

// LCD_MODE options -> [ _8_BIT_MODE , _4_BIT_MODE ]
#define LCD_MODE       		_8_BIT_MODE
// LCD_DIMENSIONS options -> [ LCD_2_BY_16 , LCD_4_BY_16 ]
#define LCD_DIMENSIONS		LCD_4_BY_16
/***************************************************/
#define LCD_BUS		PHB1_GPIOD
#define LCD_PORT 	GPIOD_PORT
/*--------------------------------------*/
#define LCD_RS_PIN         LCD_PORT, GPIO_PIN_10
#define LCD_RW_PIN	   	   LCD_PORT, GPIO_PIN_9
#define LCD_EN_PIN         LCD_PORT, GPIO_PIN_8
/*--------------------------------------*/
#define LCD_DATA_7_PIN     LCD_PORT, GPIO_PIN_7
#define LCD_DATA_6_PIN	   LCD_PORT, GPIO_PIN_6
#define LCD_DATA_5_PIN	   LCD_PORT, GPIO_PIN_5
#define LCD_DATA_4_PIN	   LCD_PORT, GPIO_PIN_4

#define LCD_DATA_3_PIN     LCD_PORT, GPIO_PIN_3
#define LCD_DATA_2_PIN     LCD_PORT, GPIO_PIN_2
#define LCD_DATA_1_PIN     LCD_PORT, GPIO_PIN_1
#define LCD_DATA_0_PIN     LCD_PORT, GPIO_PIN_0
/***************************************************/
#endif /* SRC_HAL_LCD_HAL_LCD_CONFIG_H_ */

/************	HARDWARE CFG	**************
VSS:	This is a ground pin of LCD
VDD:	This is the supply voltage pin of LCD [VCC/VDD]
VEE:	Adjusts the contrast of the LCD [VEE/Vo]
--------------------------------------------------------------------
RS:		Register Select -> Toggles between Command/Data Register
		0 -> Command Mode		1-> Data Mode
--------------------------------------------------------------------
RW:		Read/Write	->	Toggles the LCD between Read/Write Operation
		0 -> Write Operation		1-> Read Operation
--------------------------------------------------------------------
EN:		Enable	->	Must be held high to perform Read/Write Operation
		Connected to MCU and always held high.
--------------------------------------------------------------------
Data[0]
  ...		Data/Command Pin
  ...		In 4-Wire Mode Only 4 pins (4-7) is connected to MCU
  ...		In 8-Wire Mode All 8 pins(0-7) are connected to MCU
Data[7]
--------------------------------------------------------------------
A, LEDA:	LED Positive	-> Common Anode LED		-> Connected to +5V
K, LEDK:	LED Negative	-> Common Cathode LED	-> Connected to ground
*/
