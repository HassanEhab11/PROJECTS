/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Group Three
 * @brief          : Main program body
 ******************************************************************************
 ******************************************************************************
 */

#include "main.h"
U8 G_key = 0;
U8 G_Fail_Counter =0;
int main(void)
{
	MRCC_vInitSystemClock();
	MSTK_Init(STK_CLK_SRC_HCLK_Div8);
	MRCC_vEnableBusClock(Bus_AHB1, PHB1_GPIOA);
	MRCC_vEnableBusClock(Bus_AHB1, PHB1_GPIOB);
	MRCC_vEnableBusClock(Bus_AHB1, PHB1_GPIOC);
	MRCC_vEnableBusClock(Bus_AHB1, PHB1_GPIOD);
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	MRCC_vEnableBusClock(Bus_APB2, PPB2_SPI1);
	MRCC_vEnableBusClock(Bus_APB2, PPB2_SYSCFG);
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

	//ADC
	//MRCC_vEnableBusClock(Bus_APB2, PPB2_ADC1);
	//MGPIO_vSetPinMode(GPIOC_PORT, GPIO_PIN_5, ANALOG_MODE);
	//MADC_vInit();
	//MADC_vSetADCPrescaler(DIVIDE_2);
	//MADC_vRegularSequenceChoice(SEQ_1, CONV_15);
	//MADC_vNumberOfChannels(CONV_0);
	//MADC_vEnableDisable(ENABLE);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	HKEYPAD_vInitiate();
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	HLCD_vInitiate();
	HLCD_vGoTo(0, 0);
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	MSPI_vInit(SPI_1_);
	MSPI_vEnable(SPI_1_);
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	HTFT_vInit();
	HTFT_vDrawPic(0, 240, 0, 320, NTI_Logo);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	MGPIO_vSetPinMode(GPIOB_PORT, GPIO_PIN_7, OUTPUT_MODE); // LED 1
	MGPIO_vSetPinMode(GPIOB_PORT, GPIO_PIN_1, OUTPUT_MODE); // LED 2
	MGPIO_vSetPinMode(GPIOB_PORT, GPIO_PIN_2, OUTPUT_MODE); // LED 3
	MGPIO_vSetPinMode(GPIOB_PORT, GPIO_PIN_3, OUTPUT_MODE); // LED 4
	MGPIO_vSetPinOutputSpeed(GPIOB_PORT, GPIO_PIN_7, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputSpeed(GPIOB_PORT, GPIO_PIN_1, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputSpeed(GPIOB_PORT, GPIO_PIN_2, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputSpeed(GPIOB_PORT, GPIO_PIN_3, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputType(GPIOB_PORT, GPIO_PIN_7, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputType(GPIOB_PORT, GPIO_PIN_1, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputType(GPIOB_PORT, GPIO_PIN_2, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputType(GPIOB_PORT, GPIO_PIN_3, OUTPUT_PUSH_PULL_TYPE);

	MGPIO_vSetPinMode(GPIOB_PORT, GPIO_PIN_4, OUTPUT_MODE); // Buzzer
	MGPIO_vSetPinOutputSpeed(GPIOB_PORT, GPIO_PIN_4, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputType(GPIOB_PORT, GPIO_PIN_4, OUTPUT_PUSH_PULL_TYPE);

	MGPIO_vSetPinMode(GPIOB_PORT, GPIO_PIN_5, OUTPUT_MODE); // Motor pin1
	MGPIO_vSetPinMode(GPIOB_PORT, GPIO_PIN_6, OUTPUT_MODE); // Motor pin2
	MGPIO_vSetPinOutputSpeed(GPIOB_PORT, GPIO_PIN_5, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputSpeed(GPIOB_PORT, GPIO_PIN_6, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputType(GPIOB_PORT, GPIO_PIN_5, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputType(GPIOB_PORT, GPIO_PIN_6, OUTPUT_PUSH_PULL_TYPE);
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	HLCD_vGoTo(0,1);
	HLCD_vWriteString((U8*)"Enter Password:");
	HLCD_vGoTo(1,5);


	while(1)
	{
		GetPasswordFromUser();


		/*Debuging ADC
		static U32 ADC_read = 0 ;
		ADC_read=	MADC_u32ReadRegularData();
		HLCD_vGoTo(0, 0);
		HLCD_vWriteNumber(ADC_read);*/
	}
}

void GetPasswordFromUser(void)
{
	S8 static Input_Incrementer=0 ;
	S8 static Default_Password [5]="0777";
	S8 static EnteredPassword[5] ={0};
	G_key = 'P';
	Delay_vMilliSecond16MHzoscillator(2);
	G_key = HKEYPAD_U8READ();

	if (G_key != 'P')
	{
		if(G_key >= '0' && G_key <='9')
		{
			BuzzerSound();
			//HLCD_vWriteCharacter('*');
			HLCD_vWriteCharacter(G_key);
			EnteredPassword[Input_Incrementer] = G_key;
			Input_Incrementer++;
		}
		else if('=' == G_key)
		{
			HLCD_vClearScreen();
			HLCD_vWriteString((U8*)"OK");
			Delay_vMilliSecond16MHzoscillator(500);
			HLCD_vGoTo(1,1);
			BuzzerSound();
			if((StringCompare(EnteredPassword , Default_Password) == 1))
			{
				G_Fail_Counter =0;
				HTFT_vFillColor(0xFFFF);
				HTFT_vDrawPic(0+WELCOME_X_SHIFT,240+WELCOME_X_SHIFT,  0+WELCOME_Y_SHIFT, 50+WELCOME_Y_SHIFT, WELCOME);
				HLCD_vWriteString((U8*)"Accepted Pass");
				Delay_vMilliSecond16MHzoscillator(500);
				DefineUserCommand();
			}
			else{
				G_Fail_Counter++;
				HLCD_vGoTo(1,3);
				HLCD_vWriteString((U8*)"Denied Pass");
				HLCD_vGoTo(1,0);
				Delay_vMilliSecond16MHzoscillator(500);
				HLCD_vWriteString((U8*)"Renter Password");
				HLCD_vGoTo(2,5);
				Input_Incrementer=0;
				EnteredPassword[0] = 0;
				EnteredPassword[1] = 0;
				EnteredPassword[2] = 0;
				EnteredPassword[3] = 0;
				EnteredPassword[4] = 0;
				if (G_Fail_Counter == 2)
				{
					HTFT_vFillColor(0xFFFF);
					HTFT_vDrawPic(0+CAT_X_SHIFT,240+CAT_X_SHIFT,  0+CAT_Y_SHIFT, 180+CAT_Y_SHIFT, CAT);
				}
				else{	}
			}
		}
		else{	}
	}
	else{	}
}

U8 StringCompare(S8* String1 , S8 * String2)
{
	while(*String1 != 0 || *String2 != 0)
	{
		Delay_vMilliSecond16MHzoscillator(5);
		if(*String1 == *String2){
			String1++;
			String2++;
		}
		else{
			return 0;
		}
	}
	return 1;
}

void BuzzerSound(void)
{
	MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_4, HIGH_STATE);
	Delay_vMilliSecond16MHzoscillator(100);
	MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_4, LOW_STATE);
}

void DefineUserCommand(void)
{
	HLCD_vClearScreen();
	HLCD_vGoTo(1,2);
	HLCD_vWriteString((U8*)"Welcome Home");
	Delay_vMilliSecond16MHzoscillator(500);
	HLCD_vClearScreen();
	HTFT_vFillColor(0xFFFF);
	HTFT_vDrawPic(0+LED_ORN_X_SHIFT,40+LED_ORN_X_SHIFT, 0+LED_ORGN_Y_SHIFT,50+LED_ORGN_Y_SHIFT,LED_WHT);
	HTFT_vDrawRectangle(0+LED_ORN_X_SHIFT-1,LED_ORN_X_SHIFT   , 0+LED_ORGN_Y_SHIFT,91+LED_ORGN_Y_SHIFT,0XFFFF);
	HTFT_vDrawPic(0+LED_BLU_X_SHIFT,40+LED_BLU_X_SHIFT, 0+LED_ORGN_Y_SHIFT,50+LED_ORGN_Y_SHIFT,LED_WHT);
	HTFT_vDrawRectangle(0+LED_BLU_X_SHIFT-1,LED_BLU_X_SHIFT   , 0+LED_ORGN_Y_SHIFT,91+LED_ORGN_Y_SHIFT,0XFFFF);
	HTFT_vDrawPic(0+LED_GRN_X_SHIFT,40+LED_GRN_X_SHIFT, 0+LED_ORGN_Y_SHIFT,50+LED_ORGN_Y_SHIFT,LED_WHT);
	HTFT_vDrawRectangle(0+LED_GRN_X_SHIFT-1,LED_GRN_X_SHIFT   , 0+LED_ORGN_Y_SHIFT,91+LED_ORGN_Y_SHIFT,0XFFFF);
	HTFT_vDrawPic(0+LED_YLW_X_SHIFT,40+LED_YLW_X_SHIFT, 0+LED_ORGN_Y_SHIFT,50+LED_ORGN_Y_SHIFT,LED_WHT);
	HTFT_vDrawRectangle(0+LED_YLW_X_SHIFT-1,LED_YLW_X_SHIFT   , 0+LED_ORGN_Y_SHIFT,91+LED_ORGN_Y_SHIFT,0XFFFF);
	HTFT_vDrawPic(0+AC_X_SHIFT, 80+AC_X_SHIFT, 0+AC_Y_SHIFT, 80+AC_Y_SHIFT, AC_OFF);
	HTFT_vDrawRectangle(0+AC_X_SHIFT-1,AC_X_SHIFT   , 0+AC_Y_SHIFT,153+AC_Y_SHIFT,0XFFFF);

	HLCD_vWriteString((U8*)"Pressed Key-> ");
	while(1)
	{
		G_key = 'P';
		G_key = HKEYPAD_U8READ();
		if (G_key != 'P')
		{
			static U8 EXE_LED_0_ON_OFF =0;
			static U8 EXE_LED_1_ON_OFF =0;
			if('7'==G_key || '8'==G_key || '9'==G_key || '/'==G_key)
			{
				switch(G_key) //Ligting control
				{
				case '7': //LED1
					TOG_BIT(EXE_LED_0_ON_OFF , 0);
					HLCD_vGoTo(0,0);
					HLCD_vWriteString((U8*)"Pressed Key-> ");
					HLCD_vGoTo(0,15);
					HLCD_vWriteCharacter(G_key);
					HLCD_vWriteCharacter(' ');
					HLCD_vGoTo(1,0);
					if(EXE_LED_0_ON_OFF== 0)
					{
						HLCD_vWriteString((U8*)"LED 0 is OFF        ");
						MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_7 ,LOW_STATE);
						HTFT_vDrawPic(0+LED_ORN_X_SHIFT,40+LED_ORN_X_SHIFT, 0+LED_ORGN_Y_SHIFT,50+LED_ORGN_Y_SHIFT,LED_WHT);
						HTFT_vDrawRectangle(0+LED_ORN_X_SHIFT-1,LED_ORN_X_SHIFT   , 0+LED_ORGN_Y_SHIFT,91+LED_ORGN_Y_SHIFT,0XFFFF);
					}
					else if(EXE_LED_0_ON_OFF == 1){
						HLCD_vWriteString((U8*)"LED 0 is ON         ");
						MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_7 ,HIGH_STATE);
						HTFT_vDrawPic(0+LED_ORN_X_SHIFT,40+LED_ORN_X_SHIFT, 0+LED_ORGN_Y_SHIFT,50+LED_ORGN_Y_SHIFT,LED_BLU);
						HTFT_vDrawRectangle(0+LED_ORN_X_SHIFT-1,LED_ORN_X_SHIFT   , 0+LED_ORGN_Y_SHIFT,91+LED_ORGN_Y_SHIFT,0XFFFF);

					}
					else{	}
					HLCD_vGoTo(2,0);
					HLCD_vWriteString((U8*)"                          ");
				break;
				case '8': //LED2
					TOG_BIT(EXE_LED_1_ON_OFF , 0);
					HLCD_vGoTo(0,0);
					HLCD_vWriteString((U8*)"Pressed Key-> ");
					HLCD_vGoTo(0,15);
					HLCD_vWriteCharacter(G_key);
					HLCD_vWriteCharacter(' ');
					HLCD_vGoTo(1,0);
					if(EXE_LED_1_ON_OFF== 0)
					{
						HLCD_vWriteString((U8*)"LED 1 is OFF        ");
						MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_1 ,LOW_STATE);
						HTFT_vDrawPic(0+LED_BLU_X_SHIFT,40+LED_BLU_X_SHIFT, 0+LED_ORGN_Y_SHIFT,50+LED_ORGN_Y_SHIFT,LED_WHT);
						HTFT_vDrawRectangle(0+LED_BLU_X_SHIFT-1,LED_BLU_X_SHIFT   , 0+LED_ORGN_Y_SHIFT,91+LED_ORGN_Y_SHIFT,0XFFFF);
					}
					else if(EXE_LED_1_ON_OFF == 1){
						HLCD_vWriteString((U8*)"LED 1 is ON         ");
						MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_1 ,HIGH_STATE);
						HTFT_vDrawPic(0+LED_BLU_X_SHIFT,40+LED_BLU_X_SHIFT, 0+LED_ORGN_Y_SHIFT,50+LED_ORGN_Y_SHIFT,LED_GRN);
						HTFT_vDrawRectangle(0+LED_BLU_X_SHIFT-1,LED_BLU_X_SHIFT   , 0+LED_ORGN_Y_SHIFT,91+LED_ORGN_Y_SHIFT,0XFFFF);
					}
					else{	}
					HLCD_vGoTo(2,0);
					HLCD_vWriteString((U8*)"                          ");
				break;
				case '9': //LED3
					HLCD_vGoTo(0,0);
					HLCD_vWriteString((U8*)"Pressed Key-> ");
					HLCD_vGoTo(0,15);
					HLCD_vWriteCharacter(G_key);
					HLCD_vWriteCharacter(' ');
					HLCD_vGoTo(1,0);
					HLCD_vWriteString((U8*)"LED3          ");
					HLCD_vGoTo(2,0);
					HLCD_vWriteString((U8*)"                          ");
					MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_2 ,HIGH_STATE);
					HTFT_vDrawPic(0+LED_GRN_X_SHIFT,40+LED_GRN_X_SHIFT, 0+LED_ORGN_Y_SHIFT,50+LED_ORGN_Y_SHIFT,LED_ORN);
					HTFT_vDrawRectangle(0+LED_GRN_X_SHIFT-1,LED_GRN_X_SHIFT   , 0+LED_ORGN_Y_SHIFT,91+LED_ORGN_Y_SHIFT,0XFFFF);
				break;
				case '/': //LED4
					HLCD_vGoTo(0,0);
					HLCD_vWriteString((U8*)"Pressed Key-> ");
					HLCD_vGoTo(0,15);
					HLCD_vWriteCharacter(G_key);
					HLCD_vWriteCharacter(' ');
					HLCD_vGoTo(1,0);
					HLCD_vWriteString((U8*)"LED4          ");
					HLCD_vGoTo(2,0);
					HLCD_vWriteString((U8*)"                          ");
					MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_3 ,HIGH_STATE);
					HTFT_vDrawPic(0+LED_YLW_X_SHIFT,40+LED_YLW_X_SHIFT, 0+LED_ORGN_Y_SHIFT,50+LED_ORGN_Y_SHIFT,LED_YLW);
					HTFT_vDrawRectangle(0+LED_YLW_X_SHIFT-1,LED_YLW_X_SHIFT   , 0+LED_ORGN_Y_SHIFT,91+LED_ORGN_Y_SHIFT,0XFFFF);
				break;
				default:/*MESRA*/
					break;
				}
			}

			if('4'==G_key || '5'==G_key || '6'==G_key)
			{

				switch(G_key)	//Motor control
				{
				case '4' ://Motor Left Move
					HLCD_vGoTo(0,0);
					HLCD_vWriteString((U8*)"Pressed Key-> ");
					HLCD_vGoTo(0,15);
					HLCD_vWriteCharacter(G_key);
					HLCD_vWriteCharacter(' ');
				    HLCD_vGoTo(1,0);
					HLCD_vWriteString((U8*)"Motor left <-         ");
					HLCD_vGoTo(2,0);
					HLCD_vWriteString((U8*)"                          ");
					MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_5 ,LOW_STATE);
					MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_6 ,HIGH_STATE);
					break;
				case '5':  //Motor Stop Move
					HLCD_vGoTo(0,0);
					HLCD_vWriteString((U8*)"Pressed Key-> ");
					HLCD_vGoTo(0,15);
					HLCD_vWriteCharacter(G_key);
					HLCD_vWriteCharacter(' ');
					HLCD_vGoTo(1,0);
					HLCD_vWriteString((U8*)"Motor stop            ");
					HLCD_vGoTo(2,0);
					HLCD_vWriteString((U8*)"                          ");
					MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_5 ,LOW_STATE);
					MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_6 ,LOW_STATE);
					break;
				case '6':  //Motor Right Move
					HLCD_vGoTo(0,0);
					HLCD_vWriteString((U8*)"Pressed Key-> ");
					HLCD_vGoTo(0,15);
					HLCD_vWriteCharacter(G_key);
					HLCD_vWriteCharacter(' ');
					HLCD_vGoTo(1,0);
					HLCD_vWriteString((U8*)"Motor right ->         ");
					HLCD_vGoTo(2,0);
					HLCD_vWriteString((U8*)"                          ");
					MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_5 ,HIGH_STATE);
				    MGPIO_vWritePinData(GPIOB_PORT, GPIO_PIN_6 ,LOW_STATE);
					break;
				default:
					break;
				}
			}
			static U8 EXE_AC_ON_OFF = 0b0;
			//static U32 ADC_read=0;

			if('1'==G_key || '2'==G_key )
			{
				switch(G_key) //AC control
				{
					case '1': //AC ON\OFF
						TOG_BIT(EXE_AC_ON_OFF , 0);
						HLCD_vGoTo(0,0);
						HLCD_vWriteString((U8*)"Pressed Key-> ");
						HLCD_vGoTo(0,15);
						HLCD_vWriteCharacter(G_key);
						HLCD_vWriteCharacter(' ');
						HLCD_vGoTo(2,0);
						HLCD_vWriteString((U8*)"                          ");
						HLCD_vGoTo(1,0);
						if(EXE_AC_ON_OFF== 0){
							HLCD_vWriteString((U8*)"AC is OFF        ");
							HTFT_vDrawPic(0+AC_X_SHIFT, 80+AC_X_SHIFT, 0+AC_Y_SHIFT, 80+AC_Y_SHIFT, AC_OFF);
							HTFT_vDrawRectangle(0+AC_X_SHIFT-1,AC_X_SHIFT   , 0+AC_Y_SHIFT,153+AC_Y_SHIFT,0XFFFF);
						}
						else if(EXE_AC_ON_OFF == 1){
							HLCD_vWriteString((U8*)"AC is ON        ");
							HTFT_vDrawPic(0+AC_X_SHIFT, 80+AC_X_SHIFT, 0+AC_Y_SHIFT, 80+AC_Y_SHIFT, AC_ON);
							HTFT_vDrawRectangle(0+AC_X_SHIFT-1,AC_X_SHIFT   , 0+AC_Y_SHIFT,153+AC_Y_SHIFT,0XFFFF);
						}
						else{	}
					break;
					case '2': //TEMP CHK
						HLCD_vGoTo(0,0);
						HLCD_vWriteString((U8*)"Pressed Key-> ");
						HLCD_vGoTo(0,15);
						HLCD_vWriteCharacter(G_key);
						HLCD_vWriteCharacter(' ');
						HLCD_vGoTo(1,0);
						HLCD_vWriteString((U8*)"Temp. Check        ");
						HLCD_vGoTo(2,0);
						HLCD_vWriteString((U8*)"Temp =  27.8");

						/*DEBUGING ADC*/
				//		ADC_read = MADC_u32ReadRegularData();
				//		HLCD_vWriteNumber(ADC_read );
					break;
					default:
					break;
					}
			}

			if(EXE_AC_ON_OFF == 1)
			{
				//ADC Read ->>>>> Value
				/*if(Value >25)
				 * {
				 * 	// AC ON
				 * }
				 * else{
				 * 	// AC OFF
				 * }
				 * */
				//Value to be compared with 25 C-degree
				// if value <=25 ->>>>> AC OFF
				// if value > 25 ->>>>> AC ON
			}
		}
	}
}
