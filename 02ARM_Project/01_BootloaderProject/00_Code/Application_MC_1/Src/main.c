/*******************************************************************/
/*******************************************************************/
/***  - Created  : 18/6/2023                                     ***/
/***  - Author   : ITI Embedded Team                             ***/
/***  - Version  : V01                                           ***/
/***               ITI_IMT_ADVANCED EMBEDDED SYSTEM DIPLOMA      ***/
/*******************************************************************/
/*******************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MRCC_Interface.h"

#include "MGPIO_Interface.h"
#include "MUSART_Interface.h"
#include "MSTK_Interface.h"


#include "NVIC_interface.h"
#include "EXTI_interface.h"

#include "hex.h"

u8 * data ;

void EXTI_Func(void);

void main(void)
{

	/*Step 1 : System Clock is 16 MHz From HSI*/
	MRCC_voidInitSystemClk();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERAL_EN_GPIOA);

	/*Step 2 : Enable USART1 Peripherial Clock */
	MRCC_voidEnablePeripheralClock(APB2,MRCC_PERIPHERAL_EN_USART1);

	/*Step 3 :  Enable SYSCFG */
	MRCC_voidEnablePeripheralClock(APB2,MRCC_PERIPHERAL_EN_SYSCFG);

	/*Step 4 : Enable EXTI_PORTB_0  */
	MNVIC_vEnableIRQ(EXTI0_IRQn);
	MEXTI_vEventTriggerType(_EXTI_LINE_0 , _RAISE_STATE );
	MEXTI_vSelectPort(PORTB_EXTI ,  _EXTI_LINE_0);
	MEXTI_vSetCallBack( _EXTI_LINE_0,  EXTI_Func);
	MEXTI_vEnableLine(_EXTI_LINE_0);

	/*Step 5 : Set Pin Mode For Pins 9 , 10 -> Alternative Function */
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN9,MGPIO_MODE_ALTF) ;    //TX-> USART1
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN10,MGPIO_MODE_ALTF) ;   //RX-> USART1

	/*Step 6 : Set Pin Alternative function For Pins 9 , 10  */
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN9,7) ;                //TX-> USART1
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN10,7) ;               //RX-> USART1

	/*Step 7 : MUSART Initialization*/
	MUSART_voidInit() ; /*9600bps , 1 stop bits  , no parity , 8  bit data*/

	/*Step 8 : Enable MUSART */
	MUSART_voidEnable() ;



	/*Step 9: init Systick*/
	MSTK_voidInit() ; /*disable STK , Interrupt , Tick = 0.5 Micro second --> HSI/8 --> 2MHz*/



	while(1)
	{

	}

}


void EXTI_Func(void)
{
	MUSART_voidSendData((u8*)GLB_u16Data1[0] , 44);
	for(int count = 0  ; count< 134 ; count++)
	{
		MUSART_voidSendData((u8*)GLB_u16Data1[count] , 44);


		while(data[0] != 'O' && data[1] != 'K' )
		{
			MUSART_u8ReadDataSynch(data) ;

		}
	}

}
