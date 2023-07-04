/*
 * HAL_TFT_Private.h
 *
 *  Created on: Jun 1, 2022
 *      Author: Group Three
 */

#ifndef SRC_HAL_TFT_HAL_TFT_PRIVATE_H_
#define SRC_HAL_TFT_HAL_TFT_PRIVATE_H_

#define LED_ORGN_Y_SHIFT 	272
#define LED_ORN_X_SHIFT		173
#define LED_BLU_X_SHIFT		LED_ORN_X_SHIFT-50		//40
#define LED_GRN_X_SHIFT		LED_BLU_X_SHIFT-50
#define LED_YLW_X_SHIFT		LED_GRN_X_SHIFT-50

#define AC_Y_SHIFT 			130
#define AC_X_SHIFT			80

#define WELCOME_X_SHIFT		0
#define WELCOME_Y_SHIFT		130

#define CAT_X_SHIFT		0
#define CAT_Y_SHIFT		80

#endif /* SRC_HAL_TFT_HAL_TFT_PRIVATE_H_ */
