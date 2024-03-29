/*******************************************************************/
/*******************************************************************/
/***  - Created  : 18/6/2023                                     ***/
/***  - Author   : ITI Embedded Team                             ***/
/***  - Version  : V01                                           ***/
/***               ITI_IMT_ADVANCED EMBEDDED SYSTEM DIPLOMA      ***/
/*******************************************************************/
/*******************************************************************/




/***********************************************************************/

/***********************************************************************/
/*    *What i sell To Customer                                         */
/*        * The Archictect Give The API                                */
/*            - The Name of Function                                   */
/*            - Macros                                                 */
/*            - What is  The Input                                     */
/*            - What is  The output                                    */
/**********************************************************************/

/***********************************************************************/
/*             guard of file will call one time in .c file             */
/***********************************************************************/

             
#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_


/*******************************Bus Name *******************************/

typedef enum
{
	AHB1 = 0 ,
	AHB2     ,
	APB1     ,
	APB2     ,
	AHB1LP   ,
	AHB2LP   ,
	APB1LP   ,
	APB2LP
}BusName_t ; 



/***********************************************************************/
/*                        Function Prototypes                          */
/***********************************************************************/

/*#####################################################################*/

/*
   @fu MRCC_voidEnablePeripheralClock 
   @brief   This Function used To Enable Peripheral clock  
   @param[in]   Copy_uddtBusName  : The Bus of The Peripheral [AHB1 , AHB2 , APB1 ,APB2] Every one  Detect 
   Which REG to Choise Peripherial From It   
   @param[in]   Copy_u8PerNum  : The order of Peripheral On The Selected Register
*/
void MRCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName,u8 Copy_u8PerNum);

/*#####################################################################*/

/*
   @fu MRCC_voidDisablePeripheralClock 
   @brief   This Function used To Disable Peripheral clock  
   @param[in]   Copy_uddtBusName  : The Bus of The Peripheral [AHB1 , AHB2 , APB1 ,APB2] Every one  Detect 
   Which REG to Choise Peripherial From It   
   @param[in]   Copy_u8PerNum  : The order of Peripheral On The Selected Register
*/
void MRCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName,u8 Copy_u8PerNum);

/*
   @fu MRCC_voidInitSystemClk 
   @brief   This Function used To Initializaion for System clock   
*/
void MRCC_voidInitSystemClk(void);         

/*******************Macros of : RCC AHB1 Clk Enable **********************/

#define MRCC_PERIPHERAL_EN_GPIOA     0U 
#define MRCC_PERIPHERAL_EN_GPIOB     1U 
#define MRCC_PERIPHERAL_EN_GPIOC     2U 
#define MRCC_PERIPHERAL_EN_GPIOD     3U 
#define MRCC_PERIPHERAL_EN_GPIOE     4U 
#define MRCC_PERIPHERAL_EN_GPIOH     7U 
#define MRCC_PERIPHERAL_EN_CRCEN     12U
#define MRCC_PERIPHERAL_EN_DMA1      21U 
#define MRCC_PERIPHERAL_EN_DMA2      22U 

#define MRCC_PERIPHERAL_EN_SYSCFG    14U

#define  MRCC_PERIPHERAL_EN_USART1    4U


#define MRCC_PERIPHERAL_EN_FDI       15U
#endif /*MRCC_INTERFACE_H_*/
/*#####################################################################*/
