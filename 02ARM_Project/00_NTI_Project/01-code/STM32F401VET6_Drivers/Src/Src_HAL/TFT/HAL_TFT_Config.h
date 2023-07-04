/*
 * HAL_TFT_Config.h
 *
 *  Created on: Jun 1, 2022
 *      Author: Group Three
 */

#ifndef SRC_HAL_TFT_HAL_TFT_CONFIG_H_
#define SRC_HAL_TFT_HAL_TFT_CONFIG_H_



/*
--> A0 Command Data PIN
*/
/*
#define TFT_A0_PIN		    _GPIOA_PORT,GPIO_PIN_1
#define TFT_RESET_PIN       _GPIOA_PORT,GPIO_PIN_2
#define TFT_CS_PIN		    _GPIOA_PORT,3
#define TFT_SDA_PIN		    _GPIOA_PORT,GPIO_PIN_7
#define TFT_SCK_PIN		    _GPIOA_PORT,GPIO_PIN_5
#define TFT_LED_PIN		    _GPIOA_PORT,1
*/

/*Write Pin in pair Port,Pin*/
/***************_MACROS_CONFIGURATION_*********************/
#define TFT_A0_PORT     GPIOA_PORT
#define TFT_A0_PIN      GPIO_PIN_1

#define TFT_RST_PORT    GPIOA_PORT
#define TFT_RST_PIN     GPIO_PIN_2

#define TFT_CLK_PORT    GPIOA_PORT  /*SCK Pin*/
#define TFT_CLK_PIN     GPIO_PIN_5

#define TFT_MOSI_PORT   GPIOA_PORT 	/*SDA Pin*/
#define TFT_MOSI_PIN    GPIO_PIN_7

#endif /* SRC_HAL_TFT_HAL_TFT_CONFIG_H_ */
