/*
 * MCAL_SYSTIK_Register.h
 *
 *  Created on: May 31, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef SRC_MCAL_SYSTIK_MCAL_SYSTIK_REGISTER_H_
#define SRC_MCAL_SYSTIK_MCAL_SYSTIK_REGISTER_H_

#define STK_PERIPHERAL_BASE_ADDRESS     0xE000E010

typedef struct
{
	volatile Reg_32Bit_Utag REG_STK_CTRL  ;
	volatile Reg_32Bit_Utag REG_STK_LOAD  ;
	volatile Reg_32Bit_Utag REG_STK_VAL   ;
	volatile Reg_32Bit_Utag REG_STK_CALIB ;
}STK_PERIPHERAL_Stag;

/*============================================================================================
	-)	Struct Pointer :	Base_Address ->	STK
  ============================================================================================*/
#define STK_SPTR      ((volatile STK_PERIPHERAL_Stag *)STK_PERIPHERAL_BASE_ADDRESS)



#endif /* SRC_MCAL_SYSTIK_MCAL_SYSTIK_REGISTER_H_ */
