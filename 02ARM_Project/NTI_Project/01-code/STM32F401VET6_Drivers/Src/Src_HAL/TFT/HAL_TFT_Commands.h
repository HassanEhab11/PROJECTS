/*
 * HAL_TFT_Commands.h
 *
 *  Created on: Jun 1, 2022
 *      Author: Group Three
 */

#ifndef SRC_HAL_TFT_HAL_TFT_COMMANDS_H_
#define SRC_HAL_TFT_HAL_TFT_COMMANDS_H_

#define SLPOUT	        0x11	           /* Sleep Out */
#define COLMOD	        0x3A	           /* Enable Color Mode */
#define RGB444	        0x03               /*Enable RGB444 Mode */
#define RGB565	        0x05               /*Enable RGB565 Mode */
#define RGB666	        0x06               /*Enable RGB666 Mode */
#define DISON	        0x29               /*Enable TFT Display*/
#define SET_X_ADDRESS	0x2A               /* Set X Address Command*/
#define SET_Y_ADDRESS	0x2B               /* Set Y Address Command*/
#define RAM_WRITE		0x2C               /*Command To Write Data*/

#endif /* SRC_HAL_TFT_HAL_TFT_COMMANDS_H_ */
