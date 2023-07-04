/*
 * MCAL_GPIO_Interface.h
 *
 *  Created on: May 16, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef INC_MCAL_GPIO_MCAL_GPIO_INTERFACE_H_
#define INC_MCAL_GPIO_MCAL_GPIO_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

/***************_HAL_INCLUDES_*****************************/

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_GPIO_Private.h"
#include "MCAL_GPIO_Config.h"
#include "MCAL_GPIO_Register.h"

/***************_MACROS_CONFIGURATION_*********************/
/*======== Macros Of Port ========*/
#define GPIOA_PORT   		      ((U8)0U)            /*!< GPIO (A) PORT  */
#define GPIOB_PORT   		      ((U8)1U)            /*!< GPIO (B) PORT  */
#define GPIOC_PORT   		      ((U8)2U)            /*!< GPIO (C) PORT  */
#define GPIOD_PORT   		      ((U8)3U)            /*!< GPIO (D) PORT  */
#define GPIOE_PORT   		      ((U8)4U)            /*!< GPIO (E) PORT  */
#define GPIOH_PORT   		      ((U8)5U)            /*!< GPIO (H) PORT  */

/*======== Macros Of Pins ========*/
#define GPIO_PIN_0               ((U8)0U)       /*!< Pin 0 selected    */
#define GPIO_PIN_1               ((U8)1U)       /*!< Pin 1 selected    */
#define GPIO_PIN_2               ((U8)2U)       /*!< Pin 2 selected    */
#define GPIO_PIN_3               ((U8)3U)       /*!< Pin 3 selected    */
#define GPIO_PIN_4               ((U8)4U)       /*!< Pin 4 selected    */
#define GPIO_PIN_5               ((U8)5U)       /*!< Pin 5 selected    */
#define GPIO_PIN_6               ((U8)6U)       /*!< Pin 6 selected    */
#define GPIO_PIN_7               ((U8)7U)       /*!< Pin 7 selected    */
#define GPIO_PIN_8               ((U8)8U)       /*!< Pin 8 selected    */
#define GPIO_PIN_9               ((U8)9U)       /*!< Pin 9 selected    */
#define GPIO_PIN_10              ((U8)10U)       /*!< Pin 10 selected   */
#define GPIO_PIN_11              ((U8)11U)       /*!< Pin 11 selected   */
#define GPIO_PIN_12              ((U8)12U)       /*!< Pin 12 selected   */
#define GPIO_PIN_13              ((U8)13U)       /*!< Pin 13 selected   */
#define GPIO_PIN_14              ((U8)14U)       /*!< Pin 14 selected   */
#define GPIO_PIN_15              ((U8)15U)       /*!< Pin 15 selected   */
//#define GPIO_PIN_All            ((U16)0xFFFF)    /*!< All pins selected */  ####################

/*======== Macros Of Pin Mode ========*/
#define INPUT_MODE  	         ((U8)0U)          /*!< MODE ---> INPUT     */
#define OUTPUT_MODE   	         ((U8)1U)          /*!< MODE ---> OUTPUT    */
#define ALTERNATE_FUNCTION_MODE  ((U8)2U)          /*!< MODE ---> ALTF      */
#define ANALOG_MODE   	         ((U8)3U)          /*!< MODE ---> ANALOG    */

#define INPUT_PORT_MODE			 ((U32)0x00000000)  //0b0000 0000 0000 0000 0000 0000 0000 0000
#define OUTPUT_PORT_MODE		 ((U32)0x55555555)  //0b0101 0101 0101 0101 0101 0101 0101 0101
#define ANALOG_PORT_MODE         ((U32)0xFFFFFFFF)  //0b1111 1111 1111 1111 1111 1111 1111 1111

/*======== Macros Of Output Type ========*/
#define OUTPUT_PUSH_PULL_TYPE    ((U8)0U)          /*!< OUTPUT TYPE ---> PUSH PULL   */
#define OUTPUT_OPEN_DRAIN_TYPE   ((U8)1U)          /*!< OUTPUT TYPE ---> OPEN DRAIN  */

/*======== Macros Of Pin Speed ========*/
#define OUTPUT_LOW_SPEED         ((U8)0U)  /*!< IO works at 2 MHz, please refer to the product datasheet */
#define OUTPUT_MEDUIM_SPEED      ((U8)1U)  /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
#define OUTPUT_HIGH_SPEED        ((U8)2U)  /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
#define OUTPUT_VERY_HIGH_SPEED   ((U8)3U)  /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */

/*======== Macros Of Pin PULL  ========*/
#define PULL_OFF_STATE           ((U8)0U)   /*!< No Pull-up or Pull-down activation  */
#define PULL_UP_STATE            ((U8)1U)   /*!< Pull-up activation                  */
#define PULL_DOWN_STATE          ((U8)2U)   /*!< Pull-down activation                */

/*======== Macros Write Data  ========*/
#define LOW_STATE                ((U8)0U)
#define HIGH_STATE	             ((U8)1U)

/*======== Macros ALTFUN  ========*/
#define ALTFUN_0            (U8)(0U)
#define ALTFUN_1            (U8)(1U)
#define ALTFUN_2            (U8)(2U)
#define ALTFUN_3            (U8)(3U)
#define ALTFUN_4            (U8)(4U)
#define ALTFUN_5            (U8)(5U)
#define ALTFUN_6            (U8)(6U)
#define ALTFUN_7            (U8)(7U)
#define ALTFUN_8            (U8)(8U)
#define ALTFUN_9            (U8)(9U)
#define ALTFUN_10           (U8)(10U)
#define ALTFUN_11           (U8)(11U)
#define ALTFUN_12           (U8)(12U)
#define ALTFUN_13           (U8)(13U)
#define ALTFUN_14           (U8)(14U)
#define ALTFUN_15           (U8)(15U)

/*============================================================================
  ==================_APIs Supported by "MCAL_GPIO DRIVER"_====================
  ============================================================================*/
void MGPIO_vSetPinMode(U8 PortName ,U8 PinNum ,U8 DirectionMode);
void MGPIO_vFastPortConfigMode(U8 PortName, U32 PortDirectionMode);

void MGPIO_vSetPinOutputType(U8 PortName ,U8 PinNum ,U8 OutPutType);
void MGPIO_vSetPinOutputSpeed(U8 PortName ,U8 PinNum ,U8 OutputSpeed);

void MGPIO_vSetPinPullType(U8 PortName ,U8 PinNum ,U8 PullType);

U8 MGPIO_U8ReadPinData(U8 PortName ,U8 PinNum);
U16 MGPIO_U16ReadPortData(U8 PortName);

void MGPIO_vWritePinData(U8 PortName ,U8 PinNum, U8 OutputState);
void MGPIO_vWritePortByteData(U8 PortName, U8 Data, U8 StartBit);
void MGPIO_vWritePortNibbleData(U8 PortName, U8 Data, U8 StartBit);
void MGPIO_vWritePortData(U8 PortName, U16 Data);

void MGPIO_vToggle_Pin(U8 PortName, U8 PinNum);

void MGPIO_vPinLock(U8 PortName, U8 PinNum );
void MGPIO_vSetPinAltFun(U8 PortName, U8 PinNum, U8 ALTFUN);

#endif /* INC_MCAL_GPIO_MCAL_GPIO_INTERFACE_H_ */
