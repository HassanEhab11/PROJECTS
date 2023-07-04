/*
 * HAL_LCD.c
 *
 *  Created on: May 30, 2022
 *      Author: Group Three
 */

#include "HAL_LCD_Interface.h"

U8 Char1[8] = {0x0, 0xa, 0x1f, 0x1f, 0x1f, 0xe, 0x4, 0x0};
// Folded Heart = 0x0, 0xa, 0x1f, 0x1f, 0x1f, 0xe, 0x4, 0x0
// Right Arrow  = 0x0, 0x4, 0x2, 0x1f, 0x2, 0x4, 0x0, 0x0
// Left Arrow   = 0x0, 0x4, 0x8, 0x1f, 0x8, 0x4, 0x0, 0x0
//
U8 Char2[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };
U8 Char3[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00 };
U8 Char4[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 };
U8 Char5[8] = { 0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18 };
U8 Char6[8] = { 0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04 };
U8 Char7[8] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 };
U8 Char8[8] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 };

void HLCD_vInitiate(void)
{
	MRCC_vEnableBusClock(Bus_AHB1, LCD_BUS);
	/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	MGPIO_vSetPinMode(LCD_RS_PIN, OUTPUT_MODE);
	MGPIO_vSetPinMode(LCD_RW_PIN, OUTPUT_MODE);
	MGPIO_vSetPinMode(LCD_EN_PIN, OUTPUT_MODE);
	MGPIO_vSetPinOutputSpeed(LCD_RS_PIN, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputSpeed(LCD_RW_PIN, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputSpeed(LCD_EN_PIN, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputType(LCD_RS_PIN, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputType(LCD_RW_PIN, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputType(LCD_EN_PIN, OUTPUT_PUSH_PULL_TYPE);
	/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	#if LCD_MODE     ==   _8_BIT_MODE
	MGPIO_vSetPinMode(LCD_DATA_0_PIN, OUTPUT_MODE);
	MGPIO_vSetPinMode(LCD_DATA_1_PIN, OUTPUT_MODE);
	MGPIO_vSetPinMode(LCD_DATA_2_PIN, OUTPUT_MODE);
	MGPIO_vSetPinMode(LCD_DATA_3_PIN, OUTPUT_MODE);
	MGPIO_vSetPinOutputSpeed(LCD_DATA_0_PIN, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputSpeed(LCD_DATA_1_PIN, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputSpeed(LCD_DATA_2_PIN, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputSpeed(LCD_DATA_3_PIN, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputType(LCD_DATA_0_PIN, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputType(LCD_DATA_1_PIN, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputType(LCD_DATA_2_PIN, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputType(LCD_DATA_3_PIN, OUTPUT_PUSH_PULL_TYPE);

	#elif LCD_MODE    ==   _4_BIT_MODE
				/**NOTHING**/
	#endif
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	MGPIO_vSetPinMode(LCD_DATA_4_PIN, OUTPUT_MODE);
	MGPIO_vSetPinMode(LCD_DATA_5_PIN, OUTPUT_MODE);
	MGPIO_vSetPinMode(LCD_DATA_6_PIN, OUTPUT_MODE);
	MGPIO_vSetPinMode(LCD_DATA_7_PIN, OUTPUT_MODE);
	MGPIO_vSetPinOutputSpeed(LCD_DATA_4_PIN, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputSpeed(LCD_DATA_5_PIN, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputSpeed(LCD_DATA_6_PIN, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputSpeed(LCD_DATA_7_PIN, OUTPUT_LOW_SPEED);
	MGPIO_vSetPinOutputType(LCD_DATA_4_PIN, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputType(LCD_DATA_5_PIN, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputType(LCD_DATA_6_PIN, OUTPUT_PUSH_PULL_TYPE);
	MGPIO_vSetPinOutputType(LCD_DATA_7_PIN, OUTPUT_PUSH_PULL_TYPE);

/*==============================================================================*/
	Delay_vMilliSecond16MHzoscillator(50); //Wait for H/W init...
	#if LCD_MODE     ==   _8_BIT_MODE
	HLCD_vWriteCommand(LCD_COMMAND_ACTIVATE_8_BITMODE);
	Delay_vMilliSecond16MHzoscillator(5);
	#elif LCD_MODE    ==   _4_BIT_MODE
	Delay_vMilliSecond16MHzoscillator(5);
	HLCD_vWriteCommand(LCD_COMMAND_1_ACTIVATE_4_BITMODE);
	Delay_vMilliSecond16MHzoscillator(5);
	HLCD_vWriteCommand(LCD_COMMAND_2_ACTIVATE_4_BITMODE);
	Delay_vMilliSecond16MHzoscillator(5);
	HLCD_vWriteCommand(LCD_COMMAND_3_ACTIVATE_4_BITMODE);
	Delay_vMilliSecond16MHzoscillator(5);
	#endif
	HLCD_vWriteCommand(LCD_COMMAND_DISPLAY_ON_CURSOR_OFF);
	Delay_vMilliSecond16MHzoscillator(1);
	HLCD_vWriteCommand(LCD_COMMAND_CLEAR_SCREEN);
	Delay_vMilliSecond16MHzoscillator(1);
	HLCD_vWriteCommand(LCD_COMMAND_RETURN_HOME_CLEAR_SCREEN);
	Delay_vMilliSecond16MHzoscillator(1);
	HLCD_vWriteCommand(LCD_COMMAND_CURSOR_INCREMENT);
	Delay_vMilliSecond16MHzoscillator(1);
}

void HLCD_vWriteCommand(U8 loc_U8_LCD_COMMAND)
{
	MGPIO_vWritePinData(LCD_RS_PIN, LOW_STATE); // Fetal operation if High while "Command Transfer"
	MGPIO_vWritePinData(LCD_RW_PIN, LOW_STATE); // Held Low for "Write Operation"
	/**********************	_8_BIT_MODE	*************************/
	#if LCD_MODE    ==   _8_BIT_MODE
	MGPIO_vWritePinData(LCD_DATA_0_PIN, GET_BIT(loc_U8_LCD_COMMAND, 0));
	MGPIO_vWritePinData(LCD_DATA_1_PIN, GET_BIT(loc_U8_LCD_COMMAND, 1));
	MGPIO_vWritePinData(LCD_DATA_2_PIN, GET_BIT(loc_U8_LCD_COMMAND, 2));
	MGPIO_vWritePinData(LCD_DATA_3_PIN, GET_BIT(loc_U8_LCD_COMMAND, 3));
	MGPIO_vWritePinData(LCD_DATA_4_PIN, GET_BIT(loc_U8_LCD_COMMAND, 4));
	MGPIO_vWritePinData(LCD_DATA_5_PIN, GET_BIT(loc_U8_LCD_COMMAND, 5));
	MGPIO_vWritePinData(LCD_DATA_6_PIN, GET_BIT(loc_U8_LCD_COMMAND, 6));
	MGPIO_vWritePinData(LCD_DATA_7_PIN, GET_BIT(loc_U8_LCD_COMMAND, 7));
	MGPIO_vWritePinData(LCD_EN_PIN, HIGH_STATE);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_vWritePinData(LCD_EN_PIN, LOW_STATE);
	Delay_vMilliSecond16MHzoscillator(2);
	/**********************	_4_BIT_MODE	*************************/
	#elif LCD_MODE    ==   _4_BIT_MODE
	/***   Sending HIGH Nibble of 8 Bits Data   ***/
	MGPIO_vWritePinData(LCD_DATA_4_PIN, GET_BIT(loc_U8_LCD_COMMAND, 4U));
	MGPIO_vWritePinData(LCD_DATA_5_PIN, GET_BIT(loc_U8_LCD_COMMAND, 5U));
	MGPIO_vWritePinData(LCD_DATA_6_PIN, GET_BIT(loc_U8_LCD_COMMAND, 6U));
	MGPIO_vWritePinData(LCD_DATA_7_PIN, GET_BIT(loc_U8_LCD_COMMAND, 7U));
	MGPIO_vWritePinData(LCD_EN_PIN, HIGH_STATE);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_vWritePinData(LCD_EN_PIN, LOW_STATE);
	Delay_vMilliSecond16MHzoscillator(2);
	/***   Sending LOW Nibble of 8 Bits Data    ***/
	MGPIO_vWritePinData(LCD_DATA_4_PIN, GET_BIT(loc_U8_LCD_COMMAND, 0U));
	MGPIO_vWritePinData(LCD_DATA_5_PIN, GET_BIT(loc_U8_LCD_COMMAND, 1U));
	MGPIO_vWritePinData(LCD_DATA_6_PIN, GET_BIT(loc_U8_LCD_COMMAND, 2U));
	MGPIO_vWritePinData(LCD_DATA_7_PIN, GET_BIT(loc_U8_LCD_COMMAND, 3U));
	MGPIO_vWritePinData(LCD_EN_PIN, HIGH_STATE);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_vWritePinData(LCD_EN_PIN, LOW_STATE);
	Delay_vMilliSecond16MHzoscillator(2);
	#endif
}

void HLCD_vClearScreen(void)
{
	HLCD_vWriteCommand(LCD_COMMAND_CLEAR_SCREEN); //Refer to the command sheet "HAL_LCD_COMMANDS"
}

void HLCD_vGoTo(U8 loc_U8_Row, U8 loc_U8_Col)
{
	#if   LCD_DIMENSIONS   ==   LCD_2_BY_16
	U8 loc_Arr_RC_Commands[2] = {LCD_COMMAND_GOTO_1stLINE_POS_0,
							     LCD_COMMAND_GOTO_2ndLINE_POS_0 };
	#elif LCD_DIMENSIONS   ==   LCD_4_BY_16
	U8 loc_Arr_RC_Commands[4] = {LCD_COMMAND_GOTO_1stLINE_POS_0,
								 LCD_COMMAND_GOTO_2ndLINE_POS_0,
								 LCD_COMMAND_GOTO_3ndLINE_POS_0,
							     LCD_COMMAND_GOTO_4ndLINE_POS_0 };
	#endif
	//Refer to the command sheet "HAL_LCD_COMMANDS"
	HLCD_vWriteCommand(loc_Arr_RC_Commands[loc_U8_Row]+loc_U8_Col);
}

void HLCD_vBuildCustomChar (U8 MemoryLocation, U8 CChar_Name)
{
    U8 i =0;
    U8 *CC_msg_Ptr =NULL;
    if(MemoryLocation < 8)
    {
		switch(CChar_Name)
		{
			case CHAR_HEART:
				CC_msg_Ptr = Char1;
			break;
			case CHAR_BATTARY:
				CC_msg_Ptr = Char2;
			break;
			case CHAR_RING:
				CC_msg_Ptr = Char3;
			break;
			case CHAR_SPEAKER:
				CC_msg_Ptr = Char4;
			break;
			case CHAR_MUSIC:
				CC_msg_Ptr = Char5;
			break;
			case CHAR_POWER_CABLE:
				CC_msg_Ptr = Char6;
			break;
			case CHAR_HAPPY_FACE:
				CC_msg_Ptr = Char7;
			break;
			default:
			break;
		}
    	HLCD_vWriteCommand(0x40 + (MemoryLocation*8));
    	/* Command 0x40 and onwards forces the device to point CGRAM address */
       for(i =0; i <8; i++)  /* Write 8 byte for generation of 1 character */
       {
    	   HLCD_vWriteCharacter(CC_msg_Ptr[i]);
       }
    }
    /******************************************************************
     * 1- You have to build your custom char directly after LCD init
     * 2- CGRAM can contaion only 8 CChar starting from location (0, to 7)
     * 3- break operation wiht CGRAM by going Home or GoTo(0,0)
     * 4- Calling the CC from CGRAM by sending 0 to 7
     * HLCD_vInitiate();
     * HLCD_vWriteCustomChar(0, Character1);
     * HLCD_vWriteCustomChar(1, Character2);
     ****************************************************************/
}


/************************************************************************************************/
void HLCD_vWriteCharacter(U8 loc_U8_CHARACTER)
{
	MGPIO_vWritePinData(LCD_RS_PIN, HIGH_STATE); // Fetal operation if Low while "Data Transfer"
	MGPIO_vWritePinData(LCD_RW_PIN, LOW_STATE);  // Held Low for "Write Operation"
	/**********************	_8_BIT_MODE	*************************/
	#if LCD_MODE    ==   _8_BIT_MODE
	MGPIO_vWritePinData(LCD_DATA_0_PIN, GET_BIT(loc_U8_CHARACTER, 0));
	MGPIO_vWritePinData(LCD_DATA_1_PIN, GET_BIT(loc_U8_CHARACTER, 1));
	MGPIO_vWritePinData(LCD_DATA_2_PIN, GET_BIT(loc_U8_CHARACTER, 2));
	MGPIO_vWritePinData(LCD_DATA_3_PIN, GET_BIT(loc_U8_CHARACTER, 3));
	MGPIO_vWritePinData(LCD_DATA_4_PIN, GET_BIT(loc_U8_CHARACTER, 4));
	MGPIO_vWritePinData(LCD_DATA_5_PIN, GET_BIT(loc_U8_CHARACTER, 5));
	MGPIO_vWritePinData(LCD_DATA_6_PIN, GET_BIT(loc_U8_CHARACTER, 6));
	MGPIO_vWritePinData(LCD_DATA_7_PIN, GET_BIT(loc_U8_CHARACTER, 7));
	MGPIO_vWritePinData(LCD_EN_PIN, HIGH_STATE);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_vWritePinData(LCD_EN_PIN, LOW_STATE);
	Delay_vMilliSecond16MHzoscillator(2);
	/**********************	_4_BIT_MODE	*************************/
	#elif LCD_MODE    ==   _4_BIT_MODE
	/***   Sending HIGH Nibble of 8 Bits Data   ***/
	MGPIO_vWritePinData(LCD_DATA_4_PIN, GET_BIT(loc_U8_CHARACTER, 4U));
	MGPIO_vWritePinData(LCD_DATA_5_PIN, GET_BIT(loc_U8_CHARACTER, 5U));
	MGPIO_vWritePinData(LCD_DATA_6_PIN, GET_BIT(loc_U8_CHARACTER, 6U));
	MGPIO_vWritePinData(LCD_DATA_7_PIN, GET_BIT(loc_U8_CHARACTER, 7U));
	MGPIO_vWritePinData(LCD_EN_PIN, HIGH_STATE);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_vWritePinData(LCD_EN_PIN, LOW_STATE);
	Delay_vMilliSecond16MHzoscillator(2);
	/***   Sending LOW Nibble of 8 Bits Data    ***/
	MGPIO_vWritePinData(LCD_DATA_4_PIN, GET_BIT(loc_U8_CHARACTER, 0U));
	MGPIO_vWritePinData(LCD_DATA_5_PIN, GET_BIT(loc_U8_CHARACTER, 1U));
	MGPIO_vWritePinData(LCD_DATA_6_PIN, GET_BIT(loc_U8_CHARACTER, 2U));
	MGPIO_vWritePinData(LCD_DATA_7_PIN, GET_BIT(loc_U8_CHARACTER, 3U));
	MGPIO_vWritePinData(LCD_EN_PIN, HIGH_STATE);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_vWritePinData(LCD_EN_PIN, LOW_STATE);
	Delay_vMilliSecond16MHzoscillator(2);
	#endif
}

void HLCD_vWriteString(U8 *loc_U8_PTR_STRING)
{
	U8 loc_U8_Counter =0;
	while(loc_U8_PTR_STRING[loc_U8_Counter] != '\0')
	{
		HLCD_vWriteCharacter(loc_U8_PTR_STRING[loc_U8_Counter]);
		loc_U8_Counter++;
	}
}

void HLCD_vWriteNumber(S32 loc_S32_NUMBER)
{
	U8 i =0;
	U8 Storing_Array[10] ={0}; //no. of digits for U32 Number
	U32 loc_U32_Number_Copy = loc_S32_NUMBER;

	if(loc_S32_NUMBER <0)
	{ //CHK for '-Ve' state
		HLCD_vWriteCharacter('-');
		loc_S32_NUMBER = loc_S32_NUMBER*(-1);	// -Ve ~ +Ve
		loc_U32_Number_Copy = loc_S32_NUMBER;
	}
	else if(loc_U32_Number_Copy == 0){ //CHK for '0' state
		HLCD_vWriteCharacter('0');
	}
	else {/*NOTHING*/}

	while(loc_U32_Number_Copy)
	{//*STORING PROCCES*//
		Storing_Array[i] = (loc_U32_Number_Copy % 10)+'0';
		loc_U32_Number_Copy /= 10;
		i++;
	}
	while(i)
	{
		HLCD_vWriteCharacter(Storing_Array[i-1]);
		i--;
	}
}

void HLCD_vWriteNumber_Bin(U8 loc_U8_NUMBER)
{
	S8 i =0;
	HLCD_vWriteCharacter('0');
	HLCD_vWriteCharacter('B');

	for(i =7; i >=0; i--)
	{
		if(1 == GET_BIT(loc_U8_NUMBER, i))
		{
			HLCD_vWriteCharacter('1');
		}
		else{
			HLCD_vWriteCharacter('0');
		}
	}
}

void HLCD_vWriteNumber_Hex(U8 loc_U8_NUMBER)
{
	U8 HEX_Holder =0;
	HLCD_WriteCharacter('0');
	HLCD_WriteCharacter('x');

	HEX_Holder =loc_U8_NUMBER /16;
	if(HEX_Holder<10)
	{
		HLCD_vWriteCharacter(HEX_Holder+'0');
	}
	else{
		HLCD_vWriteCharacter(HEX_Holder+'7');
	}

	HEX_Holder =loc_U8_NUMBER %16;
	if(HEX_Holder<10)
	{
		HLCD_vWriteCharacter(HEX_Holder+'0');
	}
	else{
		HLCD_vWriteCharacter(HEX_Holder+'7');
	}
}


