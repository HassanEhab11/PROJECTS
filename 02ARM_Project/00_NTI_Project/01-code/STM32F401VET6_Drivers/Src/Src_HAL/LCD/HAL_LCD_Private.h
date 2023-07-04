/*
 * HAL_LCD_Private.h
 *
 *  Created on: May 30, 2022
 *      Author: Group Three
 */

#ifndef SRC_HAL_LCD_HAL_LCD_PRIVATE_H_
#define SRC_HAL_LCD_HAL_LCD_PRIVATE_H_

#define _4_BIT_MODE       4U
#define _8_BIT_MODE       8U

#define LCD_2_BY_16		  26U
#define LCD_4_BY_16		  46U

#define ASCII_NUM_INIT		   '0'

#endif /* SRC_HAL_LCD_HAL_LCD_PRIVATE_H_ */

/***************************************************
 * LCD Storage Memory
 * The LCD that we use has a Hitachi HD44780 LCD controller. It has three main storage locations:
 * 1- DDRAM
 * 2- CGROM
 * 3- CGRAM
 ***** DDRAM or “Data Display Random Access Memory”
 ***** is the working data buffer of the display. Each character on the display has a corresponding
 ***** DDRAM location and the byte loaded in DDRAM controls which character is displayed.
 *****
 ***** CGROM or “Character Generation Read Only Memory” holds all the standard patterns for the 5 x 7
 ***** dot matrix characters. For instance, if you want to display character “A”, you would send ASCII
 ***** code 65 (decimal) to the DDRAM. The display controller looks up the pattern of dots to display for
 ***** this code in the CGROM and lights up the ones appropriate for “A”. The CGROM contents depend on
 ***** the particular character set and model of display, US, Chinese etc. and cannot be changed.
 *****
 ***** CGRAM or “Character Generation Random Access Memory” allows the user to define special supplementary
 ***** non-standard character types that are not in the CGROM. You can load your own dot pattern shapes and
 ***** call these up for display.
 ****************************************************/
