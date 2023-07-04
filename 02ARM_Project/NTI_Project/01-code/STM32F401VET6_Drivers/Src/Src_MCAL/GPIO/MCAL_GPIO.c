/*
 * MCAL_GPIO.c
 *
 *  Created on: May 16, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "MCAL_GPIO_Interface.h"

void MGPIO_vSetPinMode(U8 PortName, U8 PinNum, U8 DirectionMode)
{
	/* INPUT_MODE, OUTPUT_MODE, ALTERNATE_FUNCTION_MODE, ANALOG_MODE */
	switch(PortName)
	{
	    //GIVE_BIT(GPIOA_SPTR->GPIO_MODER.RegisterAccess, 2U* PinNum, (U32)DirectionMode) ; break;
		case GPIOA_PORT :GPIOA_SPTR->GPIO_MODER.RegisterAccess |= (U32)(DirectionMode<<(2U* PinNum)) ; break;
		case GPIOB_PORT :GPIOB_SPTR->GPIO_MODER.RegisterAccess |= (U32)(DirectionMode<<(2U* PinNum)) ; break;
		case GPIOC_PORT :GPIOC_SPTR->GPIO_MODER.RegisterAccess |= (U32)(DirectionMode<<(2U* PinNum)) ; break;
		case GPIOD_PORT :GPIOD_SPTR->GPIO_MODER.RegisterAccess |= (U32)(DirectionMode<<(2U* PinNum)) ; break;
		case GPIOE_PORT :GPIOE_SPTR->GPIO_MODER.RegisterAccess |= (U32)(DirectionMode<<(2U* PinNum)) ; break;
		case GPIOH_PORT :GPIOH_SPTR->GPIO_MODER.RegisterAccess |= (U32)(DirectionMode<<(2U* PinNum)) ; break;
		default : /*ERROR*/ break ;
    }
}

void MGPIO_vFastPortConfigMode(U8 PortName, U32 PortDirectionMode)
{
	/* INPUT_PORT_MODE, OUTPUT_PORT_MODE, ANALOG_PORT_MODE*/
	switch(PortName)
	{
		case GPIOA_PORT :GPIOA_SPTR->GPIO_MODER.RegisterAccess = (U32)PortDirectionMode ; break;
		case GPIOB_PORT :GPIOB_SPTR->GPIO_MODER.RegisterAccess = (U32)PortDirectionMode ; break;
		case GPIOC_PORT :GPIOC_SPTR->GPIO_MODER.RegisterAccess = (U32)PortDirectionMode ; break;
		case GPIOD_PORT :GPIOD_SPTR->GPIO_MODER.RegisterAccess = (U32)PortDirectionMode ; break;
		case GPIOE_PORT :GPIOE_SPTR->GPIO_MODER.RegisterAccess = (U32)PortDirectionMode ; break;
		case GPIOH_PORT :GPIOH_SPTR->GPIO_MODER.RegisterAccess = (U32)PortDirectionMode ; break;
		default : /*ERROR*/ break ;
    }
}

void MGPIO_vSetPinOutputType(U8 PortName, U8 PinNum, U8 OutPutType)
{
	/*OUTPUT_PUSH_PULL_TYPE, OUTPUT_OPEN_DRAIN_TYPE*/
	switch(PortName)
	{
		case GPIOA_PORT :GPIOA_SPTR->GPIO_OTYPER.RegisterAccess |= (U32)(OutPutType<<(PinNum)) ; break;
		case GPIOB_PORT :GPIOB_SPTR->GPIO_OTYPER.RegisterAccess |= (U32)(OutPutType<<(PinNum)) ; break;
		case GPIOC_PORT :GPIOC_SPTR->GPIO_OTYPER.RegisterAccess |= (U32)(OutPutType<<(PinNum)) ; break;
		case GPIOD_PORT :GPIOD_SPTR->GPIO_OTYPER.RegisterAccess |= (U32)(OutPutType<<(PinNum)) ; break;
		case GPIOE_PORT :GPIOE_SPTR->GPIO_OTYPER.RegisterAccess |= (U32)(OutPutType<<(PinNum)) ; break;
		case GPIOH_PORT :GPIOH_SPTR->GPIO_OTYPER.RegisterAccess |= (U32)(OutPutType<<(PinNum)) ; break;
		default : /*ERROR*/ break ;
     }
}

void MGPIO_vSetPinOutputSpeed(U8 PortName, U8 PinNum, U8 OutputSpeed)
{
	/*OUTPUT_LOW_SPEED, OUTPUT_MEDUIM_SPEED, OUTPUT_HIGH_SPEED, OUTPUT_VERY_HIGH_SPEED*/
	switch(PortName)
	{
		case GPIOA_PORT :GPIOA_SPTR->GPIO_OSPEEDR.RegisterAccess |= (U32)(OutputSpeed<<(2U* PinNum)) ; break;
		case GPIOB_PORT :GPIOB_SPTR->GPIO_OSPEEDR.RegisterAccess |= (U32)(OutputSpeed<<(2U* PinNum)) ; break;
		case GPIOC_PORT :GPIOC_SPTR->GPIO_OSPEEDR.RegisterAccess |= (U32)(OutputSpeed<<(2U* PinNum)) ; break;
		case GPIOD_PORT :GPIOD_SPTR->GPIO_OSPEEDR.RegisterAccess |= (U32)(OutputSpeed<<(2U* PinNum)) ; break;
		case GPIOE_PORT :GPIOE_SPTR->GPIO_OSPEEDR.RegisterAccess |= (U32)(OutputSpeed<<(2U* PinNum)) ; break;
		case GPIOH_PORT :GPIOH_SPTR->GPIO_OSPEEDR.RegisterAccess |= (U32)(OutputSpeed<<(2U* PinNum)) ; break;
		default : /*ERROR*/ break ;
	}
}

void MGPIO_vSetPinPullType(U8 PortName, U8 PinNum, U8 PullType)
{
	/*PULL_OFF_STATE, PULL_UP_STATE, PULL_DOWN_STATE*/
	switch(PortName)
	{
		case GPIOA_PORT :GPIOA_SPTR->GPIO_PUPDR.RegisterAccess |= (U32)(PullType<<(2U* PinNum)) ; break;
		case GPIOB_PORT :GPIOB_SPTR->GPIO_PUPDR.RegisterAccess |= (U32)(PullType<<(2U* PinNum)) ; break;
		case GPIOC_PORT :GPIOC_SPTR->GPIO_PUPDR.RegisterAccess |= (U32)(PullType<<(2U* PinNum)) ; break;
		case GPIOD_PORT :GPIOD_SPTR->GPIO_PUPDR.RegisterAccess |= (U32)(PullType<<(2U* PinNum)) ; break;
		case GPIOE_PORT :GPIOE_SPTR->GPIO_PUPDR.RegisterAccess |= (U32)(PullType<<(2U* PinNum)) ; break;
		case GPIOH_PORT :GPIOH_SPTR->GPIO_PUPDR.RegisterAccess |= (U32)(PullType<<(2U* PinNum)) ; break;
		default : /*ERROR*/ break ;
	}
}

U8 MGPIO_U8ReadPinData(U8 PortName, U8 PinNum)
{
	U8 L_U8Pin_Read_Data =0;
	switch(PortName)
	{
		case GPIOA_PORT :L_U8Pin_Read_Data = GET_BIT(GPIOA_SPTR->GPIO_IDR.RegisterAccess, PinNum) ; break;
		case GPIOB_PORT :L_U8Pin_Read_Data = GET_BIT(GPIOB_SPTR->GPIO_IDR.RegisterAccess, PinNum) ; break;
		case GPIOC_PORT :L_U8Pin_Read_Data = GET_BIT(GPIOC_SPTR->GPIO_IDR.RegisterAccess, PinNum) ; break;
		case GPIOD_PORT :L_U8Pin_Read_Data = GET_BIT(GPIOD_SPTR->GPIO_IDR.RegisterAccess, PinNum) ; break;
		case GPIOE_PORT :L_U8Pin_Read_Data = GET_BIT(GPIOE_SPTR->GPIO_IDR.RegisterAccess, PinNum) ; break;
		case GPIOH_PORT :L_U8Pin_Read_Data = GET_BIT(GPIOH_SPTR->GPIO_IDR.RegisterAccess, PinNum) ; break;
		default : /*ERROR*/ break ;
	}
	return L_U8Pin_Read_Data;
}

U16 MGPIO_U16ReadPortData(U8 PortName)
{
	U8 L_U8Pin_Read_Data =0;
	switch(PortName)
	{
		case GPIOA_PORT :L_U8Pin_Read_Data = GET_REG(GPIOA_SPTR->GPIO_IDR.RegisterAccess) ; break;
		case GPIOB_PORT :L_U8Pin_Read_Data = GET_REG(GPIOB_SPTR->GPIO_IDR.RegisterAccess) ; break;
		case GPIOC_PORT :L_U8Pin_Read_Data = GET_REG(GPIOC_SPTR->GPIO_IDR.RegisterAccess) ; break;
		case GPIOD_PORT :L_U8Pin_Read_Data = GET_REG(GPIOD_SPTR->GPIO_IDR.RegisterAccess) ; break;
		case GPIOE_PORT :L_U8Pin_Read_Data = GET_REG(GPIOE_SPTR->GPIO_IDR.RegisterAccess) ; break;
		case GPIOH_PORT :L_U8Pin_Read_Data = GET_REG(GPIOH_SPTR->GPIO_IDR.RegisterAccess) ; break;
		default : /*ERROR*/ break ;
	}
	return L_U8Pin_Read_Data;
}

void MGPIO_vWritePinData(U8 PortName, U8 PinNum, U8 OutputState)
{
	/*LOW_STATE, HIGH_STATE*/
	switch(OutputState)
	{
		case LOW_STATE:
			switch(PortName)
			{
				case GPIOA_PORT :CLR_BIT(GPIOA_SPTR->GPIO_ODR.RegisterAccess, PinNum); break;
				case GPIOB_PORT :CLR_BIT(GPIOB_SPTR->GPIO_ODR.RegisterAccess, PinNum); break;
				case GPIOC_PORT :CLR_BIT(GPIOC_SPTR->GPIO_ODR.RegisterAccess, PinNum); break;
				case GPIOD_PORT :CLR_BIT(GPIOD_SPTR->GPIO_ODR.RegisterAccess, PinNum); break;
				case GPIOE_PORT :CLR_BIT(GPIOE_SPTR->GPIO_ODR.RegisterAccess, PinNum); break;
				case GPIOH_PORT :CLR_BIT(GPIOH_SPTR->GPIO_ODR.RegisterAccess, PinNum); break;
				default : /*ERROR*/ break ;
			}
		break ;
		case HIGH_STATE:
			switch(PortName)
			{
				case GPIOA_PORT :SET_BIT(GPIOA_SPTR->GPIO_ODR.RegisterAccess, PinNum); ; break;
				case GPIOB_PORT :SET_BIT(GPIOB_SPTR->GPIO_ODR.RegisterAccess, PinNum); ; break;
				case GPIOC_PORT :SET_BIT(GPIOC_SPTR->GPIO_ODR.RegisterAccess, PinNum); ; break;
				case GPIOD_PORT :SET_BIT(GPIOD_SPTR->GPIO_ODR.RegisterAccess, PinNum); ; break;
				case GPIOE_PORT :SET_BIT(GPIOE_SPTR->GPIO_ODR.RegisterAccess, PinNum); ; break;
				case GPIOH_PORT :SET_BIT(GPIOH_SPTR->GPIO_ODR.RegisterAccess, PinNum); ; break;
				default : /*ERROR*/ break ;
			}
		break ;
		default : /*ERROR*/ break ;
	}
}

void MGPIO_vWritePortData(U8 PortName, U16 Data)
{
	/*LOW_STATE, HIGH_STATE*/
	switch(PortName)
	{
	    case GPIOA_PORT :GIVE_REG(GPIOA_SPTR->GPIO_ODR.RegisterAccess, Data)  ; break;
	    case GPIOB_PORT :GIVE_REG(GPIOB_SPTR->GPIO_ODR.RegisterAccess, Data)  ; break;
	    case GPIOC_PORT :GIVE_REG(GPIOC_SPTR->GPIO_ODR.RegisterAccess, Data)  ; break;
	    case GPIOD_PORT :GIVE_REG(GPIOD_SPTR->GPIO_ODR.RegisterAccess, Data)  ; break;
	    case GPIOE_PORT :GIVE_REG(GPIOE_SPTR->GPIO_ODR.RegisterAccess, Data)  ; break;
	    case GPIOH_PORT :GIVE_REG(GPIOH_SPTR->GPIO_ODR.RegisterAccess, Data)  ; break;
		default : /*ERROR*/ break ;
	}
}

void MGPIO_vWritePortByteData(U8 PortName, U8 Data, U8 StartBit)
{
	/* In ODR  Pass and Shift ( 0000 0000 ) to the start bit & sheft data to that start bit
	 * == Dynamic Data Assigning																*/
	switch(PortName)
	{
	//Register = (((Register &(0xFF00)))|(((Data)&(0x00FF))));
		case GPIOA_PORT :
			GPIOA_SPTR->GPIO_ODR.RegisterAccess = ((((GPIOA_SPTR->GPIO_ODR.RegisterAccess) &(0xFF00)))|(((Data)&(0x00FF)))); break;
		case GPIOB_PORT :
			GPIOB_SPTR->GPIO_ODR.RegisterAccess = ((((GPIOB_SPTR->GPIO_ODR.RegisterAccess) &(0xFF00)))|(((Data)&(0x00FF)))); break;
		case GPIOC_PORT :
			GPIOC_SPTR->GPIO_ODR.RegisterAccess = ((((GPIOC_SPTR->GPIO_ODR.RegisterAccess) &(0xFF00)))|(((Data)&(0x00FF)))); break;
		case GPIOD_PORT :
			GPIOD_SPTR->GPIO_ODR.RegisterAccess = ((((GPIOD_SPTR->GPIO_ODR.RegisterAccess) &(0xFF00)))|(((Data)&(0x00FF)))); break;
		case GPIOE_PORT :
			GPIOE_SPTR->GPIO_ODR.RegisterAccess = ((((GPIOE_SPTR->GPIO_ODR.RegisterAccess) &(0xFF00)))|(((Data)&(0x00FF)))); break;
		case GPIOH_PORT :
			GPIOH_SPTR->GPIO_ODR.RegisterAccess = ((((GPIOH_SPTR->GPIO_ODR.RegisterAccess) &(0xFF00)))|(((Data)&(0x00FF)))); break;
		default : /*ERROR*/ break ;
	}
}
/*
 	 	case GPIOA_PORT :
			GPIOA_SPTR->GPIO_ODR.RegisterAccess =(((GPIOA_SPTR->GPIO_ODR.RegisterAccess) &~(0xFF<<(StartBit)))|(Data<<(StartBit))); break;
		case GPIOB_PORT :
			GPIOB_SPTR->GPIO_ODR.RegisterAccess =(((GPIOB_SPTR->GPIO_ODR.RegisterAccess) &~(0xFF<<(StartBit)))|(Data<<(StartBit))); break;
		case GPIOC_PORT :
			GPIOC_SPTR->GPIO_ODR.RegisterAccess =(((GPIOC_SPTR->GPIO_ODR.RegisterAccess) &~(0xFF<<(StartBit)))|(Data<<(StartBit))); break;
		case GPIOD_PORT :
			GPIOD_SPTR->GPIO_ODR.RegisterAccess =(((GPIOD_SPTR->GPIO_ODR.RegisterAccess) &~(0xFF<<(StartBit)))|(Data<<(StartBit))); break;
		case GPIOE_PORT :
			GPIOE_SPTR->GPIO_ODR.RegisterAccess =(((GPIOE_SPTR->GPIO_ODR.RegisterAccess) &~(0xFF<<(StartBit)))|(Data<<(StartBit))); break;
		case GPIOH_PORT :
			GPIOH_SPTR->GPIO_ODR.RegisterAccess =(((GPIOH_SPTR->GPIO_ODR.RegisterAccess) &~(0xFF<<(StartBit)))|(Data<<(StartBit))); break;
		default :  break ;
 * */

void MGPIO_vWritePortNibbleData(U8 PortName, U8 Data, U8 StartBit)
{
	/* In ODR  Pass and Shift ( 0000 0000 ) to the start bit & sheft data to that start bit
	 * == Dynamic Data Assigning																*/
	switch(PortName)
	{
		case GPIOA_PORT :
			GPIOA_SPTR->GPIO_ODR.RegisterAccess =(((GPIOA_SPTR->GPIO_ODR.RegisterAccess) &~(0xF<<(StartBit)))|(Data<<(StartBit))); break;
		case GPIOB_PORT :
			GPIOB_SPTR->GPIO_ODR.RegisterAccess =(((GPIOB_SPTR->GPIO_ODR.RegisterAccess) &~(0xF<<(StartBit)))|(Data<<(StartBit))); break;
		case GPIOC_PORT :
			GPIOC_SPTR->GPIO_ODR.RegisterAccess =(((GPIOC_SPTR->GPIO_ODR.RegisterAccess) &~(0xF<<(StartBit)))|(Data<<(StartBit))); break;
		case GPIOD_PORT :
			GPIOD_SPTR->GPIO_ODR.RegisterAccess =(((GPIOD_SPTR->GPIO_ODR.RegisterAccess) &~(0xF<<(StartBit)))|(Data<<(StartBit))); break;
		case GPIOE_PORT :
			GPIOE_SPTR->GPIO_ODR.RegisterAccess =(((GPIOE_SPTR->GPIO_ODR.RegisterAccess) &~(0xF<<(StartBit)))|(Data<<(StartBit))); break;
		case GPIOH_PORT :
			GPIOH_SPTR->GPIO_ODR.RegisterAccess =(((GPIOH_SPTR->GPIO_ODR.RegisterAccess) &~(0xF<<(StartBit)))|(Data<<(StartBit))); break;
		default : /*ERROR*/ break ;
	}
}

void MGPIO_vToggle_Pin(U8 PortName, U8 PinNum)
{
	/*LOW_STATE, HIGH_STATE*/
		switch(PortName)
		{
		    case GPIOA_PORT :GPIOA_SPTR->GPIO_ODR.RegisterAccess ^= (U16)(1 <<(PinNum)) ; break;
		    case GPIOB_PORT :GPIOB_SPTR->GPIO_ODR.RegisterAccess ^= (U16)(1 <<(PinNum)) ; break;
		    case GPIOC_PORT :GPIOC_SPTR->GPIO_ODR.RegisterAccess ^= (U16)(1 <<(PinNum)) ; break;
		    case GPIOD_PORT :GPIOD_SPTR->GPIO_ODR.RegisterAccess ^= (U16)(1 <<(PinNum)) ; break;
		    case GPIOE_PORT :GPIOE_SPTR->GPIO_ODR.RegisterAccess ^= (U16)(1 <<(PinNum)) ; break;
		    case GPIOH_PORT :GPIOH_SPTR->GPIO_ODR.RegisterAccess ^= (U16)(1 <<(PinNum)) ; break;
			default : /*ERROR*/ break ;
		}
}


void MGPIO_vPinLock(U8 PortName, U8 PinNum)
{
	switch(PortName)
	{
		case GPIOA_PORT  :
			  SET_BIT(GPIOA_SPTR->GPIO_LCKR.RegisterAccess, (U32)(PinNum)) ; break;
			  ASSIGN_BIT_TO(GPIOA_SPTR->GPIO_LCKR.BitAccess.BIT16, 1U)     ; break;
			  while(!(GPIOA_SPTR->GPIO_LCKR.RegisterAccess, (U32)(16U)));
			  break ;
		case GPIOB_PORT  :
			  SET_BIT(GPIOB_SPTR->GPIO_LCKR.RegisterAccess, (U32)(PinNum)) ; break;
			  ASSIGN_BIT_TO(GPIOB_SPTR->GPIO_LCKR.BitAccess.BIT16, 1U);    ; break;
			  while(!(GPIOB_SPTR->GPIO_LCKR.RegisterAccess, (U32)(16U)));
			  break ;
		case GPIOC_PORT  :
			  SET_BIT(GPIOC_SPTR->GPIO_LCKR.RegisterAccess, (U32)(PinNum)) ; break;
			  ASSIGN_BIT_TO(GPIOC_SPTR->GPIO_LCKR.BitAccess.BIT16, 1U)     ; break;
			  while(!(GPIOC_SPTR->GPIO_LCKR.RegisterAccess, (U32)(16U)));
			  break ;
		case GPIOD_PORT  :
			  SET_BIT(GPIOD_SPTR->GPIO_LCKR.RegisterAccess, (U32)(PinNum)) ; break;
			  ASSIGN_BIT_TO(GPIOD_SPTR->GPIO_LCKR.BitAccess.BIT16, 1U)     ; break;
			  while(!(GPIOD_SPTR->GPIO_LCKR.RegisterAccess, (U32)(16U)));
			  break ;
		case GPIOE_PORT  :
			  SET_BIT(GPIOE_SPTR->GPIO_LCKR.RegisterAccess, (U32)(PinNum)) ; break;
			  ASSIGN_BIT_TO(GPIOE_SPTR->GPIO_LCKR.BitAccess.BIT16, 1U)     ; break;
			  while(!(GPIOE_SPTR->GPIO_LCKR.RegisterAccess, (U32)(16U)));
			  break ;
		case GPIOH_PORT  :
			  SET_BIT(GPIOH_SPTR->GPIO_LCKR.RegisterAccess, (U32)(PinNum)) ; break;
			  ASSIGN_BIT_TO(GPIOH_SPTR->GPIO_LCKR.BitAccess.BIT16, 1U)     ; break;
			  while(!(GPIOH_SPTR->GPIO_LCKR.RegisterAccess, (U32)(16U)));
			  break ;
		default : /*ERROR*/ break ;
	}
}

void MGPIO_vSetPinAltFun(U8 PortName, U8 PinNum, U8 ALTFUN )
{
	if(PinNum <=7U)
	{
		switch(PortName)
		{
			 case GPIOA_PORT  : GPIOA_SPTR->GPIO_AFRL.RegisterAccess |= (U32)(ALTFUN<<(4U*PinNum)) ; break ;
			 case GPIOB_PORT  : GPIOB_SPTR->GPIO_AFRL.RegisterAccess |= (U32)(ALTFUN<<(4U*PinNum)) ; break ;
			 case GPIOC_PORT  : GPIOC_SPTR->GPIO_AFRL.RegisterAccess |= (U32)(ALTFUN<<(4U*PinNum)) ; break ;
			 case GPIOD_PORT  : GPIOD_SPTR->GPIO_AFRL.RegisterAccess |= (U32)(ALTFUN<<(4U*PinNum)) ; break ;
			 case GPIOE_PORT  : GPIOE_SPTR->GPIO_AFRL.RegisterAccess |= (U32)(ALTFUN<<(4U*PinNum)) ; break ;
			 case GPIOH_PORT  : GPIOH_SPTR->GPIO_AFRL.RegisterAccess |= (U32)(ALTFUN<<(4U*PinNum)) ; break ;
			 default : /*ERROR*/ break ;
		}
	}
	else
	{
		PinNum %=8;
		switch(PortName)
		{
			 case GPIOA_PORT  : GPIOA_SPTR->GPIO_AFRH.RegisterAccess |= (U32)(ALTFUN<<(4U*PinNum)) ; break ;
			 case GPIOB_PORT  : GPIOB_SPTR->GPIO_AFRH.RegisterAccess |= (U32)(ALTFUN<<(4U*PinNum)) ; break ;
			 case GPIOC_PORT  : GPIOC_SPTR->GPIO_AFRH.RegisterAccess |= (U32)(ALTFUN<<(4U*PinNum)) ; break ;
			 case GPIOD_PORT  : GPIOD_SPTR->GPIO_AFRH.RegisterAccess |= (U32)(ALTFUN<<(4U*PinNum)) ; break ;
			 case GPIOE_PORT  : GPIOE_SPTR->GPIO_AFRH.RegisterAccess |= (U32)(ALTFUN<<(4U*PinNum)) ; break ;
			 case GPIOH_PORT  : GPIOH_SPTR->GPIO_AFRH.RegisterAccess |= (U32)(ALTFUN<<(4U*PinNum)) ; break ;
			 default : /*ERROR*/ break ;
		}
	}
}
