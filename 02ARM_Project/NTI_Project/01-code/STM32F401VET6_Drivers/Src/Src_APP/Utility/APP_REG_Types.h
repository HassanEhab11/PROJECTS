/*
 * APP_REG_Types.h
 *
 *  Created on: May 13, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef INC_APP_UTILITY_APP_REG_TYPES_H_
#define INC_APP_UTILITY_APP_REG_TYPES_H_

/* 8_bit Register Typedef ***************************************************************/
typedef union
{
	struct{
		U8 BIT0:1;
		U8 BIT1:1;
		U8 BIT2:1;
		U8 BIT3:1;
		U8 BIT4:1;
		U8 BIT5:1;
		U8 BIT6:1;
		U8 BIT7:1;
		}BitAccess;
	U8 RegisterAccess;
}Reg_8Bit_Utag;

/* 16_bit Register Typedef **************************************************************/
typedef union
{
	struct Bit_Order{
		U16 BIT0:1;
		U16 BIT1:1;
		U16 BIT2:1;
		U16 BIT3:1;
		U16 BIT4:1;
		U16 BIT5:1;
		U16 BIT6:1;
		U16 BIT7:1;
		U16 BIT8:1;
		U16 BIT9:1;
		U16 BIT10:1;
		U16 BIT11:1;
		U16 BIT12:1;
		U16 BIT13:1;
		U16 BIT14:1;
		U16 BIT15:1;
		}BitAccess;
	struct{
		U16 BYTE0:8;
		U16 BYTE1:8;
		}ByteAccess;
	U16 RegisterAccess;
}Reg_16Bit_Utag;

/* 32_bit Register Typedef **************************************************************/
typedef union
{
	struct{
		U32 BIT0:1;
		U32 BIT1:1;
		U32 BIT2:1;
		U32 BIT3:1;
		U32 BIT4:1;
		U32 BIT5:1;
		U32 BIT6:1;
		U32 BIT7:1;
		U32 BIT8:1;
		U32 BIT9:1;
		U32 BIT10:1;
		U32 BIT11:1;
		U32 BIT12:1;
		U32 BIT13:1;
		U32 BIT14:1;
		U32 BIT15:1;
		U32 BIT16:1;
		U32 BIT17:1;
		U32 BIT18:1;
		U32 BIT19:1;
		U32 BIT20:1;
		U32 BIT21:1;
		U32 BIT22:1;
		U32 BIT23:1;
		U32 BIT24:1;
		U32 BIT25:1;
		U32 BIT26:1;
		U32 BIT27:1;
		U32 BIT28:1;
		U32 BIT29:1;
		U32 BIT30:1;
		U32 BIT31:1;
		}BitAccess;
	struct{
		U32 BYTE0:8;
		U32 BYTE1:8;
		U32 BYTE2:8;
		U32 BYTE3:8;
		}ByteAccess;
	U32 RegisterAccess;
}Reg_32Bit_Utag;

#endif /* INC_APP_UTILITY_APP_REG_TYPES_H_ */
