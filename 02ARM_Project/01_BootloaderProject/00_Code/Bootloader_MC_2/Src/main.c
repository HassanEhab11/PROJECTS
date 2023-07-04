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
#include "MFDI_Interface.h"

#include "APARSER_Interface.h"



volatile u8 TimeOutFlag = 0 ;
volatile u8 ReceiveBuffer[100] ;
volatile u8 u8RecCounter = 0 ;
volatile u8 u8WriteReq = 1  ;

typedef void (*APP_Call)(void) ;

APP_Call Add_To_Call = 0 ; /*void (*Add_To_Call)(void)*/

void App_voidTest(void)
{

	TimeOutFlag = 1 ;

	/*Move Vector Table*/
#define SCB_VTOR *((volatile u32*)0xE000ED08)

	SCB_VTOR = 0x08004000 ; //Starting of Sector 1 [Application]

	/*Set Address to call with Reset Handeler_ISR [startup code of Application]*/
	Add_To_Call = *(APP_Call*) 0x08004004 ;//0x08004004

	Add_To_Call() ; //jump Reset handler [startup code]
	MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN0,MGPIO_HIGH) ;

}

void main(void)
{

	u8 LOC_u8RecStatus = 0 ;
	/*Step 1 : System Clock is 16 MHz From HSI*/
	MRCC_voidInitSystemClk();

	/*Step 2 : Enable GPIO Peripherial Clock For Port A*/
	MRCC_voidEnablePeripheralClock(AHB1,MRCC_PERIPHERAL_EN_GPIOA);

	/*Step 3 : Enable USART1 Peripherial Clock */
	MRCC_voidEnablePeripheralClock(APB2,MRCC_PERIPHERAL_EN_USART1);

	/*Step 4 : Enable FDI Peripherial Clock */
	MRCC_voidEnablePeripheralClock(AHB1LP,MRCC_PERIPHERAL_EN_FDI);

	/*Step 5 : Set Pin Direction ->> Output*/
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN0,MGPIO_MODE_OUTPUT) ;
	/*Set Pin Speed*/
	MGPIO_voidSetOutputSpeed(MGPIOA_PORT,MGPIO_PIN0,MGPIO_OUTPUT_SPEED_MEDUIM) ;
	/*Pull Output Type*/
	MGPIO_voidSetOutputType(MGPIOA_PORT,MGPIO_PIN0,MGPIO_OUTPUT_TYPE_PUSH_PULL) ;

	/*Step 6 : indicate to i am in Boot loader */
	MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN0,MGPIO_HIGH) ;


	/*Step 5 : Set Pin Mode For Pins 9 , 10 -> Alternative Function */
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN9,MGPIO_MODE_ALTF) ;    //TX-> USART1
	MGPIO_voidSetPinMode(MGPIOA_PORT,MGPIO_PIN10,MGPIO_MODE_ALTF) ;   //RX-> USART1

	/*Step 6 : Set Pin Alternative function For Pins 9 , 10  */
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN9,7) ;                //TX-> USART1
	MGPIO_voidSetPinAltFun(MGPIOA_PORT,MGPIO_PIN10,7) ;               //RX-> USART1
	/*Step 8 : MUSART Initialization*/
	MUSART_voidInit() ; /*9600bps , 1 stop bits  , no parity , 8  bit data*/

	/*Step 9 : Enable MUSART */
	MUSART_voidEnable() ;



	/*Step 10: init Systick*/
	//MSTK_voidInit() ; /*disable STK , Interrupt , Tick = 0.5 Micro second --> HSI/8 --> 2MHz*/

	MSTK_voidSetIntervalSingle(300000000,App_voidTest) ;

	/* Loop forever */
	while(TimeOutFlag == 0)
	{
		LOC_u8RecStatus = MUSART_u8ReadDataSynch(&ReceiveBuffer[u8RecCounter]) ;
		if(LOC_u8RecStatus == 1)
		{
			/*Stop Timer Because Application Code In Processing*/
			MSTK_voidInit(); //Stop Timer
			/*indicate The end Of the Record*/
			if(ReceiveBuffer[u8RecCounter] == '\0')
			{
				if(u8WriteReq == 1)
				{
					/*Erase The Application Code*/
					MFDI_voidEraseAppArea() ;
					u8WriteReq = 0 ; // reset all the App code secotrs in one time
				}
				/*Parse The Record and Write it to flash*/
				APARSER_voidParseRecord(ReceiveBuffer) ;
				/*Send ok to tool to send the next Record */
				MUSART_voidSendData((u8*)"OK",2) ;
				/*Reset Buffer Counter*/
				u8RecCounter = 0 ;
			}
			else
			{
				u8RecCounter++ ;
			}

			/*End Of File*/
			if(ReceiveBuffer[8] == '1')
			{
				/*Wait 1 sec then jump to Application*/
				//MSTK_voidSetIntervalSingle(1000000,App_voidTest) ;
				/*Indicate to Successful Flashing*/
				MGPIO_voidSetPinValue(MGPIOA_PORT,MGPIO_PIN0,MGPIO_LOW) ;
				App_voidTest();
			}




		}
		else
		{
			//MSTK_voidSetIntervalSingle(15000000,App_voidTest) ;
		}


	}

}

