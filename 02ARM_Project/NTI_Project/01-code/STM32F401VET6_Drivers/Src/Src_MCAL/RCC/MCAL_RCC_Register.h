/*
 * MCAL_RCC_Register.h
 *
 *  Created on: May 13, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef INC_MCAL_RCC_MCAL_RCC_REGISTER_H_
#define INC_MCAL_RCC_MCAL_RCC_REGISTER_H_

/***************_APP_INCLUDES_*****************************/
#include "..\..\Src_APP\Utility\APP_Utility.h"

/**********************************************************/
/*      _____   _____ _____       _____          _       _                    _
 *     |  __ \ / ____/ ____|     |  __ \        (_)     | |                  | |
 *     | |__) | |   | |          | |__) |__ _ __ _ _ __ | |__   ___ _ __ __ _| |
 *     |  _  /| |   | |          |  ___/ _ \ '__| | '_ \| '_ \ / _ \ '__/ _` | |
 *     | | \ \| |___| |____   _  | |  |  __/ |  | | |_) | | | |  __/ | | (_| | |
 *     |_|  \_\\_____\_____| (_) |_|   \___|_|  |_| .__/|_| |_|\___|_|  \__,_|_|
 *                                                | |
 *                                                |_|
 */
				#define RCC_PERIPHERAL_BASE_ADDRESS     0x40023800
/*==========================================================================================
	-----> Register Map
============================================================================================*/
/*
 **********************_Mechanic_Style_***********************************************************
#define RCC_REG_CR                      (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x00)))
#define RCC_REG_PLLCFGR                 (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x04)))
#define RCC_REG_CFGR                    (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x08)))
#define RCC_REG_CIR                     (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x0C)))
#define RCC_REG_AHB1RSTR                (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x10)))
#define RCC_REG_AHB2RSTR                (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x14)))
#define RCC_REG_APB1RSTR                (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x20)))
#define RCC_REG_APB2RSTR                (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x24)))
#define RCC_REG_AHB1ENR                 (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x30)))
#define RCC_REG_AHB2ENR                 (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x34)))
#define RCC_REG_APB1ENR                 (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x40)))
#define RCC_REG_APB2ENR                 (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x44)))
#define RCC_REG_AHB1LPENR               (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x50)))
#define RCC_REG_AHB2LPENR               (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x54)))
#define RCC_REG_APB1LPENR               (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x60)))
#define RCC_REG_APB2LPENR               (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x64)))
#define RCC_REG_BDCR                    (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x70)))
#define RCC_REG_CSR                     (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x74)))
#define RCC_REG_SSCGR                   (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x80)))
#define RCC_REG_PLLI2SCFGR              (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x84)))
#define RCC_REG_DCKCFGR                 (*(( volatile u32* )(RCC_PERIPHERAL_BASE_ADDRESS + 0x8c)))
*/
/*
 *  **********************_Someone_Who_Finally_Understands_***************************************
typedef struct {
	volatile U32 REG_RCC_CR;                //!< RCC clock control register,                                  Address offset: 0x00
	volatile U32 REG_RCC_PLLCFGR;           //!< RCC PLL configuration register,                              Address offset: 0x04
	volatile U32 REG_RCC_CFGR;              //!< RCC clock configuration register,                            Address offset: 0x08
	volatile U32 REG_RCC_CIR;               //!< RCC clock interrupt register,                                Address offset: 0x0C
	volatile U32 REG_RCC_AHB1RSTR;          //!< RCC AHB1 peripheral reset register,                          Address offset: 0x10
	volatile U32 REG_RCC_AHB2RSTR;          //!< RCC AHB2 peripheral reset register,                          Address offset: 0x14
	volatile U32 REG_RCC_RESERVED_1_[2];    //!< Reserved, 0x28-0x2C
	volatile U32 REG_RCC_APB1RSTR;          //!< RCC APB1 peripheral reset register,                          Address offset: 0x20
	volatile U32 REG_RCC_APB2RSTR;          //!< RCC APB2 peripheral reset register,                          Address offset: 0x24
	volatile U32 REG_RCC_RESERVED_2_[2];    //!< Reserved, 0x28-0x2C
	volatile U32 REG_RCC_AHB1ENR;           //!< RCC AHB1 peripheral clock register,                          Address offset: 0x30
	volatile U32 REG_RCC_AHB2ENR;           //!< RCC AHB2 peripheral clock register,                          Address offset: 0x34
	volatile U32 REG_RCC_RESERVED_3_[2];	//!< Reserved,
	volatile U32 REG_RCC_APB1ENR;           //!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40
	volatile U32 REG_RCC_APB2ENR;           //!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44
	volatile U32 REG_RCC_RESERVED_4_[2];    //!< Reserved, 0x48-0x4C
	volatile U32 REG_RCC_AHB1LPENR;         //!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50
	volatile U32 REG_RCC_AHB2LPENR;         //!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54
	volatile U32 REG_RCC_RESERVED_5_[2];    //!< Reserved, 0x48-0x4C
	volatile U32 REG_RCC_APB1LPENR;         //!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60
	volatile U32 REG_RCC_APB2LPENR;         //!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64
	volatile U32 REG_RCC_RESERVED_6_[2];    //!< Reserved, 0x68-0x6C
	volatile U32 REG_RCC_BDCR;              //!< RCC Backup domain control register,                          Address offset: 0x70
	volatile U32 REG_RCC_CSR;               //!< RCC clock control & status register,                         Address offset: 0x74
	volatile U32 REG_RCC_RESERVED_7_[2];    //!< Reserved, 0x78-0x7C
	volatile U32 REG_RCC_SSCGR;             //!< RCC spread spectrum clock generation register,               Address offset: 0x80
	volatile U32 REG_RCC_PLLI2SCFGR;        //!< RCC PLLI2S configuration register,                           Address offset: 0x84
	volatile U32 REG_RCC_RESERVED_8_[1];    //!< Reserved, 0x88
	volatile U32 REG_RCC_DCKCFGR;           //!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C
} RCC_PERIPHERAL_Stag;
*/
 /***********************_Expert_Mode_*********************************************************/
typedef struct {
	volatile Reg_32Bit_Utag REG_RCC_CR;                /*!< RCC clock control register,                                  Address offset: 0x00 */
	volatile Reg_32Bit_Utag REG_RCC_PLLCFGR;           /*!< RCC PLL configuration register,                              Address offset: 0x04 */
	volatile Reg_32Bit_Utag REG_RCC_CFGR;              /*!< RCC clock configuration register,                            Address offset: 0x08 */
	volatile Reg_32Bit_Utag REG_RCC_CIR;               /*!< RCC clock interrupt register,                                Address offset: 0x0C */
	volatile Reg_32Bit_Utag REG_RCC_AHB1RSTR;          /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
	volatile Reg_32Bit_Utag REG_RCC_AHB2RSTR;          /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
	volatile U32            REG_RCC_RESERVED_1_[2];    /*!< Reserved, 0x28-0x2C                                                               */
	volatile Reg_32Bit_Utag REG_RCC_APB1RSTR;          /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
	volatile Reg_32Bit_Utag REG_RCC_APB2RSTR;          /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
	volatile U32            REG_RCC_RESERVED_2_[2];    /*!< Reserved, 0x28-0x2C                                                               */
	volatile Reg_32Bit_Utag REG_RCC_AHB1ENR;           /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
	volatile Reg_32Bit_Utag REG_RCC_AHB2ENR;           /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
	volatile U32            REG_RCC_RESERVED_3_[2];	/*!< Reserved,                                                                */
	volatile Reg_32Bit_Utag REG_RCC_APB1ENR;           /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
	volatile Reg_32Bit_Utag REG_RCC_APB2ENR;           /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
	volatile U32            REG_RCC_RESERVED_4_[2];    /*!< Reserved, 0x48-0x4C                                                               */
	volatile Reg_32Bit_Utag REG_RCC_AHB1LPENR;         /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
	volatile Reg_32Bit_Utag REG_RCC_AHB2LPENR;         /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
	volatile U32            REG_RCC_RESERVED_5_[2];    /*!< Reserved, 0x48-0x4C                                                               */
	volatile Reg_32Bit_Utag REG_RCC_APB1LPENR;         /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
	volatile Reg_32Bit_Utag REG_RCC_APB2LPENR;         /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
	volatile U32            REG_RCC_RESERVED_6_[2];    /*!< Reserved, 0x68-0x6C                                                               */
	volatile Reg_32Bit_Utag REG_RCC_BDCR;              /*!< RCC Backup domain control register,                          Address offset: 0x70 */
	volatile Reg_32Bit_Utag REG_RCC_CSR;               /*!< RCC clock control & status register,                         Address offset: 0x74 */
	volatile U32            REG_RCC_RESERVED_7_[2];    /*!< Reserved, 0x78-0x7C                                                               */
	volatile Reg_32Bit_Utag REG_RCC_SSCGR;             /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
	volatile Reg_32Bit_Utag REG_RCC_PLLI2SCFGR;        /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
	volatile U32            REG_RCC_RESERVED_8_[1];    /*!< Reserved, 0x88                                                                    */
	volatile Reg_32Bit_Utag REG_RCC_DCKCFGR;           /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
} RCC_PERIPHERAL_Stag;


#define	CR_HSION     0U
#define	CR_HSIRDY    1U
#define	CR_HSEON     16U
#define	CR_HSERDY    17U
#define	CR_HSEBYP    18U
#define	CR_CSSON     19U
#define	CR_PLLON     24U
#define	CR_PLLRDY    25U

#define	PLLCFGR_PLLSRC  22U

#define	CFGR_SW0        0U
#define	CFGR_SW1        1U
#define	CFGR_MCO1_1     21U
#define	CFGR_MCO1_2     22U
#define	CFGR_MCO1PRE_1  24U
#define	CFGR_MCO1PRE_2  25U
#define	CFGR_MCO1PRE_3  26U

#define	AHB1ENR_GPIOAEN     0U
#define	AHB1ENR_GPIOBEN     1U
#define	AHB1ENR_GPIOCEN     2U
#define	AHB1ENR_GPIODEN     3U
#define	AHB1ENR_GPIOEEN     4U
#define	AHB1ENR_GPIOFEN     5U
#define	AHB1ENR_GPIOGEN     6U
#define	AHB1ENR_GPIOHEN     7U
#define	AHB1ENR_GPIOIEN     8U
#define	AHB1ENR_CRCEN       12U
#define	AHB1ENR_DMA1EN      21U
#define	AHB1ENR_DMA2EN      22U

#define AHB2ENR_OTGFSEN     7U

#define APB1ENR_TIM2EN      0U
#define APB1ENR_TIM3EN      1U
#define APB1ENR_TIM4EN      2U
#define APB1ENR_TIM5EN      3U
#define APB1ENR_WWDGEN      11U
#define APB1ENR_SPI2EN      14U
#define APB1ENR_SPI3EN      15U
#define APB1ENR_USART2      17U
#define APB1ENR_I2C1        21U
#define APB1ENR_I2C2        22U
#define APB1ENR_I2C3        23U
#define APB1ENR_PWR         28U

#define APB2ENR_TIM1EN      0U
#define APB2ENR_USART1EN    4U
#define APB2ENR_USART6EN    5U
#define APB2ENR_ADC1EN      8U
#define APB2ENR_SDIOEN      11U
#define APB2ENR_SPI1EN      12U
#define APB2ENR_SPI4EN      13U
#define APB2ENR_SYSCFGEN    14U
#define APB2ENR_TIM9EN      16U
#define APB2ENR_TIM10EN     17U
#define APB2ENR_TIM11EN     18U

/*============================================================================================
	-)	Struct Pointer :	Base_Address ->	RRC
  ============================================================================================*/
#define RCC_SPTR      ((volatile RCC_PERIPHERAL_Stag *)RCC_PERIPHERAL_BASE_ADDRESS)

#endif /* INC_MCAL_RCC_MCAL_RCC_REGISTER_H_ */

/**********************************************************************************************
***     _____   _____ _____      _____ _____             _____            _     _
 *     |  __ \ / ____/ ____|    / ____|  __ \           |  __ \          (_)   | |
 *     | |__) | |   | |        | |    | |__) |  ______  | |__) |___  __ _ _ ___| |_ ___ _ __
 *     |  _  /| |   | |        | |    |  _  /  |______| |  _  // _ \/ _` | / __| __/ _ \ '__|
 *     | | \ \| |___| |____ _  | |____| | \ \           | | \ \  __/ (_| | \__ \ ||  __/ |
 *     |_|  \_\\_____\_____(_)  \_____|_|  \_\          |_|  \_\___|\__, |_|___/\__\___|_|
 *                                                                   __/ |
 *                                                                  |___/
 * [RCC_CR] -> Clock Control Register
 * 		Every flag is set by "Hardware", Configuration is set by "Software"
 * REGISTER MISSION:
 *             [1]  PLLI2S clock ready #flag                  [unlocked / locked]
 *             [2]  PLLI2S enable                             [OFF / ON]
 *             ----------------------------------------------------------------------------------
 *             [3]  Main PLL (PLL) clock ready #flag          [unlocked / locked]
 *             [4]  Main PLL (PLL) enable                     [OFF / ON]
 *                     note: PLL cannot be OFF if PLL clock is used as the system clock.
 *             [5]  CCS - Clock security system enable        [OFF / ON]
 *                     note: When CSSON is ON, the clock detector is enabled by hardware
 *                           when the HSE oscillator is ready, and disabled by hardware
 *                           if an oscillator failure is detected
 *             ----------------------------------------------------------------------------------
 *             [6]  External high-speed clock bypass control  [not bypassed / bypassed]
 *                     note: The HSEBYP can be controlled only if the HSE oscillator is disabled
 *             [7]  External high-speed clock ready flag      [not ready / ready]
 *             [8]  External high-speed clock enable          [OFF / ON]
 *                     note: HSE cannot be OFF if HSE clock is used as the system clock.
 *             ----------------------------------------------------------------------------------
 *             [9]  Internal high-speed clock calibration     [initialized automatically at startup]
 *             [10] Internal high-speed clock trimming        [provide an additional programmable trimming]
 *             [11] Internal high-speed clock ready flag      [not ready / ready]
 *             [12] Internal high-speed clock enable          [OFF / ON]
 *                     note: HSI cannot be OFF if HSI clock is used as the system clock.
 *******************************************************************************************************************
***  _____   _____ _____     _____  _      _      _____ ______ _____ _____             _____            _     _
 *  |  __ \ / ____/ ____|   |  __ \| |    | |    / ____|  ____/ ____|  __ \           |  __ \          (_)   | |
 *  | |__) | |   | |        | |__) | |    | |   | |    | |__ | |  __| |__) |  ______  | |__) |___  __ _ _ ___| |_ ___ _ __
 *  |  _  /| |   | |        |  ___/| |    | |   | |    |  __|| | |_ |  _  /  |______| |  _  // _ \/ _` | / __| __/ _ \ '__|
 *  | | \ \| |___| |____ _  | |    | |____| |___| |____| |   | |__| | | \ \           | | \ \  __/ (_| | \__ \ ||  __/ |
 *  |_|  \_\\_____\_____(_) |_|    |______|______\_____|_|    \_____|_|  \_\          |_|  \_\___|\__, |_|___/\__\___|_|
 *                                                                                                 __/ |
 *                                                                                                |___/
 * [RCC_PLLCFGR] -> Clock PLL configuration register
 * 		Every flag is set by "Hardware", Configuration is set by "Software"
 * REGISTER MISSION:
 *             [1]  PLL division factor for USB OTG FS, SDIO and random number generator clocks
 *             [2]  PLL and audio PLLI2S entry clock source
 *             [3]  PLL division factor for main system clock
 *             [4]  PLL multiplication factor for VCO
 *             [5]  Division factor for the main PLL and audio PLLI2S input clock
 *******************************************************************************************************************
***     _____   _____ _____      _____ ______ _____ _____             _____            _     _
 *     |  __ \ / ____/ ____|    / ____|  ____/ ____|  __ \           |  __ \          (_)   | |
 *     | |__) | |   | |        | |    | |__ | |  __| |__) |  ______  | |__) |___  __ _ _ ___| |_ ___ _ __
 *     |  _  /| |   | |        | |    |  __|| | |_ |  _  /  |______| |  _  // _ \/ _` | / __| __/ _ \ '__|
 *     | | \ \| |___| |____ _  | |____| |   | |__| | | \ \           | | \ \  __/ (_| | \__ \ ||  __/ |
 *     |_|  \_\\_____\_____(_)  \_____|_|    \_____|_|  \_\          |_|  \_\___|\__, |_|___/\__\___|_|
 *                                                                                __/ |
 *                                                                               |___/
 * [RCC_CFGR] -> Clock configuration register
 * 		Every flag is set by "Hardware", Configuration is set by "Software"
 * REGISTER MISSION:
 *             [1]  Microcontroller clock output_2 selection         [SYSCLK, PLLI2S, HSE, PLL]
 *             [2]  Microcontroller clock output_1 selection         [HSI, LSE, HSE, PLL]
 *             [3]  Microcontroller clock output_2 prescaler         [2, 3, 4, 5]
 *             [4]  Microcontroller clock output_1 prescaler         [2, 3, 4, 5]
 *             ----------------------------------------------------------------------------------
 *             [5]  I2S clock selection
 *             ----------------------------------------------------------------------------------
 *             [6]  HSE division factor for RTC clock                [HSE/2, ..., HSE/31]
 *             ----------------------------------------------------------------------------------
 *             [7]  APB high-speed prescaler (APB2)                  [None, 2, 4, 8, 16]
 *             [8]  APB Low-speed prescaler (APB1)                   [None, 2, 4, 8, 16]
 *             [9]  AHB prescaler                                    [None, 2, 4, 8, 16, 64, 128, 256, 512]
 *             ----------------------------------------------------------------------------------
 *             [10] System clock switch status #flag                 [HSI, HSE, PLL]
 *             [11] System clock switch                              [HSI, HSE, PLL]
 *******************************************************************************************************************
***     _____   _____ _____      _____ _____ _____             _____            _     _
 *     |  __ \ / ____/ ____|    / ____|_   _|  __ \           |  __ \          (_)   | |
 *     | |__) | |   | |        | |      | | | |__) |  ______  | |__) |___  __ _ _ ___| |_ ___ _ __
 *     |  _  /| |   | |        | |      | | |  _  /  |______| |  _  // _ \/ _` | / __| __/ _ \ '__|
 *     | | \ \| |___| |____ _  | |____ _| |_| | \ \           | | \ \  __/ (_| | \__ \ ||  __/ |
 *     |_|  \_\\_____\_____(_)  \_____|_____|_|  \_\          |_|  \_\___|\__, |_|___/\__\___|_|
 *                                                                         __/ |
 *                                                                        |___/
 * [RCC_CIR] -> Clock interrupt register
 * 		Every flag is set by "Hardware", Configuration is set by "Software"
 * REGISTER MISSION:
 *             [1]  Clock security system interrupt clear        [0: No effect, 1: Clear CSSF flag]
 *             [2]  PLLI2S ready interrupt clear                 [0: No effect, 1: Clear PLLI2SRDYF flag]
 *             [3]  Main PLL ready interrupt clear               [0: No effect, 1: Clear PLLRDYF flag]
 *             [4]  HSE ready interrupt clear                    [0: No effect, 1: Clear HSERDYF flag]
 *             [5]  HSI ready interrupt clear                    [0: No effect, 1: Clear HSIRDYF flag]
 *             [6]  LSE ready interrupt clear                    [0: No effect, 1: Clear LSERDYF flag]
 *             [7]  LSI ready interrupt clear                    [0: No effect, 1: Clear LSIRDYF flag]
 *             ----------------------------------------------------------------------------------
 *             [8]  PLLI2S ready interrupt enable            [interrupt disabled / interrupt enabled]
 *             [9]  Main PLL ready interrupt enable          [interrupt disabled / interrupt enabled]
 *             [10] HSE ready interrupt enable               [interrupt disabled / interrupt enabled]
 *             [11] HSI ready interrupt enable               [interrupt disabled / interrupt enabled]
 *             [12] LSE ready interrupt enable               [interrupt disabled / interrupt enabled]
 *             [13] LSI ready interrupt enable               [interrupt disabled / interrupt enabled]
 *             ----------------------------------------------------------------------------------
 *             [14] Clock security system interrupt flag
 *             [15] PLLI2S ready interrupt flag
 *             [16] Main PLL ready interrupt flag
 *             [17] HSE ready interrupt flag
 *             [18] HSI ready interrupt flag
 *             [19] LSE ready interrupt flag
 *             [20] LSI ready interrupt flag
 *********************************************************************************************/
