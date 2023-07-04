/*
 * MCAL_NVIC.c
 *
 *  Created on: May 17, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "MCAL_NVIC_Interface.h"

void MNVIC_vEnableInterruptRequest_IRQ(IRQn_Etag Copy_tIRQ)  /*#TESTED#*/
{
	SET_BIT(NVIC_SPTR->REG_NVIC_ISER[Copy_tIRQ /32].RegisterAccess, (Copy_tIRQ %32));
}
void MNVIC_vDisableInterruptRequest_IRQ(IRQn_Etag Copy_tIRQ) /*#TESTED#*/
{
	SET_BIT(NVIC_SPTR->REG_NVIC_ICER[Copy_tIRQ /32].RegisterAccess, (Copy_tIRQ %32));
}
void MNVIC_vSet_IRQPendingInterrupt(IRQn_Etag Copy_tIRQ) /*#TESTED#*/
{
	SET_BIT(NVIC_SPTR->REG_NVIC_ISPR[Copy_tIRQ /32].RegisterAccess, (Copy_tIRQ %32));
}
void MNVIC_vClear_IRQPendingInterrupt(IRQn_Etag Copy_tIRQ)
{
	SET_BIT(NVIC_SPTR->REG_NVIC_ICPR[Copy_tIRQ /32].RegisterAccess, (Copy_tIRQ %32));
}

U8 MNVIC_U8Get_IRQ_ActiveFlag(IRQn_Etag Copy_tIRQ)
{
	U8 L_U8GetActiveFlag = 0U ;
	L_U8GetActiveFlag = GET_BIT(NVIC_SPTR->REG_NVIC_IABR[Copy_tIRQ /32].RegisterAccess, (Copy_tIRQ %32));
	return L_U8GetActiveFlag ;
}

void MNVIC_vASetGroupSubgroupPriority(IRQn_Etag Copy_tIRQ, U8 Copy_u8GroupPri, U8 Copy_u8SubGroupPri)
{
	#if		PRIORITY_MODE  ==	_ALL_BITS_GROUP
	/*1) CONFIG SCB_AIRCR */
		SCB_SPTR->REG_SCB_AIRCR.RegisterAccess = 0x05FA0300;	/*0x05FA + 0b0RRR 011R RRRR R000*/
	/*2)SET GROUP P	 */
		NVIC_SPTR->REG_NVIC_IP[Copy_tIRQ].RegisterAccess = Copy_u8GroupPri <<4; /* 7 6 5 4 RRRR*/
	#elif 	PRIORITY_MODE  ==	_3_BIT_GROUP_1_BIT_SUB
	/*1) CONFIG SCB_AIRCR */
		SCB_SPTR->REG_SCB_AIRCR.RegisterAccess = 0x05FA0400;	/*0x05FA + 0b0RRR 100R RRRR R000*/
	/*2)SET GROUP P	 */
		NVIC_SPTR->REG_NVIC_IP[Copy_tIRQ].RegisterAccess = (Copy_u8GroupPri <<5)|(Copy_u8SubGroupPri <<4);
	#elif 	PRIORITY_MODE  ==	_2_BIT_GROUP_2_BIT_SUB
	/*1) CONFIG SCB_AIRCR */
		SCB_SPTR->REG_SCB_AIRCR.RegisterAccess = 0x05FA0500;	/*0x05FA + 0b0RRR 101R RRRR R000*/
	/*2)SET GROUP P	 */
		NVIC_SPTR->REG_NVIC_IP[Copy_tIRQ].RegisterAccess = (Copy_u8GroupPri <<6)|(Copy_u8SubGroupPri <<4);
	#elif 	PRIORITY_MODE  ==	_1_BIT_GROUP_3_BIT_SUB
	/*1) CONFIG SCB_AIRCR */
		SCB_SPTR->REG_SCB_AIRCR.RegisterAccess = 0x05FA0600;	/*0x05FA + 0b0RRR 110R RRRR R000*/
	/*2)SET GROUP P	 */
		NVIC_SPTR->REG_NVIC_IP[Copy_tIRQ].RegisterAccess = (Copy_u8GroupPri <<7)|(Copy_u8SubGroupPri <<4);
	#elif 	PRIORITY_MODE  ==	_ALL_BITS_SUB
	/*1) CONFIG SCB_AIRCR */
		SCB_SPTR->REG_SCB_AIRCR.RegisterAccess = 0x05FA0700;	/*0x05FA + 0b0RRR 111R RRRR R000*/
	/*2)SET GROUP P	 */
		NVIC_SPTR->REG_NVIC_IP[Copy_tIRQ].RegisterAccess = Copy_u8SubGroupPri <<4;
	#endif
}

