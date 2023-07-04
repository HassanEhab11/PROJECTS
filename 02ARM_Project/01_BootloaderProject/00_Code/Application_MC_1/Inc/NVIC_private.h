/*******************************************************************/
/*******************************************************************/
/***  - Created  : 18/6/2023                                     ***/
/***  - Author   : ITI Embedded Team                             ***/
/***  - Version  : V01                                           ***/
/***               ITI_IMT_ADVANCED EMBEDDED SYSTEM DIPLOMA      ***/
/*******************************************************************/
/*******************************************************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS 0xE000E100

typedef struct
{
	volatile u32 NVIC_ISER[8];
	volatile u32 Rserved_0[24];
	volatile u32 NVIC_ICER[8];
	volatile u32 Rserved_1[24];
	volatile u32 NVIC_ISPR[8];
	volatile u32 Rserved_2[24];
	volatile u32 NVIC_ICPR[8];
	volatile u32 Rserved_3[24];
	volatile u32 NVIC_IABR[8];
	volatile u32 NVIC_IPR[60];

}NVIC_REG_s;

#define NVIV_REG ((NVIC_REG_s *)NVIC_BASE_ADDRESS)


#endif
