/*
 * MCAL_NVIC_Register.h
 *
 *  Created on: May 17, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef INC_MCAL_NVIC_MCAL_NVIC_REGISTER_H_
#define INC_MCAL_NVIC_MCAL_NVIC_REGISTER_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

/**********************************************************/
/*      _   ___      _______ _____       _____          _       _                    _
 *     | \ | \ \    / /_   _/ ____|     |  __ \        (_)     | |                  | |
 *     |  \| |\ \  / /  | || |          | |__) |__ _ __ _ _ __ | |__   ___ _ __ __ _| |
 *     | . ` | \ \/ /   | || |          |  ___/ _ \ '__| | '_ \| '_ \ / _ \ '__/ _` | |
 *     | |\  |  \  /   _| || |____   _  | |  |  __/ |  | | |_) | | | |  __/ | | (_| | |
 *     |_| \_|   \/   |_____\_____| (_) |_|   \___|_|  |_| .__/|_| |_|\___|_|  \__,_|_|
 *                                                       | |
 *                                                       |_|
 */
		         #define NVIC_PERIPHERAL_BASE_ADDRESS   0xE000E100
				 #define SCB_PERIPHERAL_BASE_ADDRESS    0xE000ED00
/*==========================================================================================
	-----> Register Map
============================================================================================*/
typedef struct
{
  volatile Reg_32Bit_Utag REG_NVIC_ISER[8U];          /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
  volatile U32 			  RESERVED_0_[24U];
  volatile Reg_32Bit_Utag REG_NVIC_ICER[8U];          /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
  volatile U32 			  RESERVED_1_[24U];
  volatile Reg_32Bit_Utag REG_NVIC_ISPR[8U];          /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
  volatile U32 			  RESERVED_2_[24U];
  volatile Reg_32Bit_Utag REG_NVIC_ICPR[8U];          /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
  volatile U32 			  RESERVED_3_[24U];
  volatile Reg_32Bit_Utag REG_NVIC_IABR[8U];          /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
  volatile U32 			  RESERVED_4_[56U];
  volatile Reg_8Bit_Utag  REG_NVIC_IP[240U];          /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
  volatile U32 			  RESERVED_5_[644U];
  volatile Reg_32Bit_Utag REG_NVIC_STIR;              /*!< Offset: 0xE00 (W/O)  Software Trigger Interrupt Register */
} NVIC_PERIPHERAL_Stag;

typedef struct
{
  volatile Reg_32Bit_Utag REG_SCB_CPUID   ;          /*!< Offset: 0x00 (R/W)  CPUID base register  */
  volatile Reg_32Bit_Utag REG_SCB_ICSR    ;          /*!< Offset: 0x04 (R/O)  Interrupt control and state register  */
  volatile Reg_32Bit_Utag REG_SCB_VTOR    ;          /*!< Offset: 0x08 (R/W)  Vector table offset register  */
  volatile Reg_32Bit_Utag REG_SCB_AIRCR   ;          /*!< Offset: 0x0C (R/W)  Application interrupt and reset control register  */
  volatile Reg_8Bit_Utag  REG_SCB_SCR     ;
  volatile Reg_32Bit_Utag REG_SCB_CCR     ;
  volatile Reg_32Bit_Utag REG_SCB_SHPR[3U];
  volatile Reg_32Bit_Utag REG_SCB_SHCSR   ;
  volatile Reg_32Bit_Utag REG_SCB_CFSR    ;
  volatile Reg_32Bit_Utag REG_SCB_HFSR    ;
  volatile U32 			  RESERVED_0_[1U] ;
  volatile Reg_32Bit_Utag REG_SCB_MMAR    ;
  volatile Reg_32Bit_Utag REG_SCB_BFAR    ;
  volatile Reg_32Bit_Utag REG_SCB_AFSR    ;
} SCB_PERIPHERAL_Stag;

/*============================================================================================
	-)	Struct Pointer :	Base_Address ->	NVIC
  ============================================================================================*/
#define NVIC_SPTR     ((NVIC_PERIPHERAL_Stag *)(NVIC_PERIPHERAL_BASE_ADDRESS))
/*============================================================================================
	-)	Struct Pointer :	Base_Address ->	SCB
  ============================================================================================*/
#define SCB_SPTR      ((SCB_PERIPHERAL_Stag  *)(SCB_PERIPHERAL_BASE_ADDRESS))


//#define SCB_AIRCR   (*((volatile U32 *)(SCB_BASE_ADDRESS + 0X0C )))
#define SCB_AIRCR    (*((volatile U32 *)(SCB_BASE_ADDRESS + 0X0C )))


#endif /* INC_MCAL_NVIC_MCAL_NVIC_REGISTER_H_ */

/***
 *      _   ___      _______ _____     _____  _____ ______ _____             _____            _     _
 *     | \ | \ \    / /_   _/ ____|   |_   _|/ ____|  ____|  __ \           |  __ \          (_)   | |
 *     |  \| |\ \  / /  | || |          | | | (___ | |__  | |__) |  ______  | |__) |___  __ _ _ ___| |_ ___ _ __
 *     | . ` | \ \/ /   | || |          | |  \___ \|  __| |  _  /  |______| |  _  // _ \/ _` | / __| __/ _ \ '__|
 *     | |\  |  \  /   _| || |____ _   _| |_ ____) | |____| | \ \           | | \ \  __/ (_| | \__ \ ||  __/ |
 *     |_| \_|   \/   |_____\_____(_) |_____|_____/|______|_|  \_\          |_|  \_\___|\__, |_|___/\__\___|_|
 *                                                                                       __/ |
 *                                                                                      |___/
 */


/***
 *      _   ___      _______ _____     _____ _____ ______ _____             _____            _     _
 *     | \ | \ \    / /_   _/ ____|   |_   _/ ____|  ____|  __ \           |  __ \          (_)   | |
 *     |  \| |\ \  / /  | || |          | || |    | |__  | |__) |  ______  | |__) |___  __ _ _ ___| |_ ___ _ __
 *     | . ` | \ \/ /   | || |          | || |    |  __| |  _  /  |______| |  _  // _ \/ _` | / __| __/ _ \ '__|
 *     | |\  |  \  /   _| || |____ _   _| || |____| |____| | \ \           | | \ \  __/ (_| | \__ \ ||  __/ |
 *     |_| \_|   \/   |_____\_____(_) |_____\_____|______|_|  \_\          |_|  \_\___|\__, |_|___/\__\___|_|
 *                                                                                      __/ |
 *                                                                                     |___/
 */


/***
 *      _   ___      _______ _____     _____  _____ _____  _____             _____            _     _
 *     | \ | \ \    / /_   _/ ____|   |_   _|/ ____|  __ \|  __ \           |  __ \          (_)   | |
 *     |  \| |\ \  / /  | || |          | | | (___ | |__) | |__) |  ______  | |__) |___  __ _ _ ___| |_ ___ _ __
 *     | . ` | \ \/ /   | || |          | |  \___ \|  ___/|  _  /  |______| |  _  // _ \/ _` | / __| __/ _ \ '__|
 *     | |\  |  \  /   _| || |____ _   _| |_ ____) | |    | | \ \           | | \ \  __/ (_| | \__ \ ||  __/ |
 *     |_| \_|   \/   |_____\_____(_) |_____|_____/|_|    |_|  \_\          |_|  \_\___|\__, |_|___/\__\___|_|
 *                                                                                       __/ |
 *                                                                                      |___/
 */


/***
 *      _   ___      _______ _____     _____ _____ _____  _____             _____            _     _
 *     | \ | \ \    / /_   _/ ____|   |_   _/ ____|  __ \|  __ \           |  __ \          (_)   | |
 *     |  \| |\ \  / /  | || |          | || |    | |__) | |__) |  ______  | |__) |___  __ _ _ ___| |_ ___ _ __
 *     | . ` | \ \/ /   | || |          | || |    |  ___/|  _  /  |______| |  _  // _ \/ _` | / __| __/ _ \ '__|
 *     | |\  |  \  /   _| || |____ _   _| || |____| |    | | \ \           | | \ \  __/ (_| | \__ \ ||  __/ |
 *     |_| \_|   \/   |_____\_____(_) |_____\_____|_|    |_|  \_\          |_|  \_\___|\__, |_|___/\__\___|_|
 *                                                                                      __/ |
 *                                                                                     |___/
 */


/***
 *      _   ___      _______ _____     _____          ____  _____             _____            _     _
 *     | \ | \ \    / /_   _/ ____|   |_   _|   /\   |  _ \|  __ \           |  __ \          (_)   | |
 *     |  \| |\ \  / /  | || |          | |    /  \  | |_) | |__) |  ______  | |__) |___  __ _ _ ___| |_ ___ _ __
 *     | . ` | \ \/ /   | || |          | |   / /\ \ |  _ <|  _  /  |______| |  _  // _ \/ _` | / __| __/ _ \ '__|
 *     | |\  |  \  /   _| || |____ _   _| |_ / ____ \| |_) | | \ \           | | \ \  __/ (_| | \__ \ ||  __/ |
 *     |_| \_|   \/   |_____\_____(_) |_____/_/    \_\____/|_|  \_\          |_|  \_\___|\__, |_|___/\__\___|_|
 *                                                                                        __/ |
 *                                                                                       |___/
 */


/***
 *      _   ___      _______ _____      _____ _______ _____ _____             _____            _     _
 *     | \ | \ \    / /_   _/ ____|    / ____|__   __|_   _|  __ \           |  __ \          (_)   | |
 *     |  \| |\ \  / /  | || |        | (___    | |    | | | |__) |  ______  | |__) |___  __ _ _ ___| |_ ___ _ __
 *     | . ` | \ \/ /   | || |         \___ \   | |    | | |  _  /  |______| |  _  // _ \/ _` | / __| __/ _ \ '__|
 *     | |\  |  \  /   _| || |____ _   ____) |  | |   _| |_| | \ \           | | \ \  __/ (_| | \__ \ ||  __/ |
 *     |_| \_|   \/   |_____\_____(_) |_____/   |_|  |_____|_|  \_\          |_|  \_\___|\__, |_|___/\__\___|_|
 *                                                                                        __/ |
 *                                                                                       |___/
 */


/***
 *      _   ___      _______ _____     _____ _____             _____            _     _
 *     | \ | \ \    / /_   _/ ____|   |_   _|  __ \           |  __ \          (_)   | |
 *     |  \| |\ \  / /  | || |          | | | |__) |  ______  | |__) |___  __ _ _ ___| |_ ___ _ __
 *     | . ` | \ \/ /   | || |          | | |  ___/  |______| |  _  // _ \/ _` | / __| __/ _ \ '__|
 *     | |\  |  \  /   _| || |____ _   _| |_| |               | | \ \  __/ (_| | \__ \ ||  __/ |
 *     |_| \_|   \/   |_____\_____(_) |_____|_|               |_|  \_\___|\__, |_|___/\__\___|_|
 *                                                                         __/ |
 *                                                                        |___/
 */
