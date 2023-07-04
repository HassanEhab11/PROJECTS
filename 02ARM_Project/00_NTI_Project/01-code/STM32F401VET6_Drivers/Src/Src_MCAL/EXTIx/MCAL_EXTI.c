/*
 * MCAL_EXTI.c
 *
 *  Created on: May 18, 2022
 *      Author: Eng- Mohamed Mokhtar
 */


#include "MCAL_EXTI_Interface.h"

void (*EXTI_CallBack_Ptr[16])(void)= {NULL};


void MEXTI_vEnableInterruptLine(EXTI_LINE_Etag Copy_ELineNum)
{
	SET_BIT(EXTI_SPTR->REG_EXTI_IMR.RegisterAccess, Copy_ELineNum);
}

void MEXTI_vDisableInterruptLine(EXTI_LINE_Etag Copy_ELineNum)
{
	CLR_BIT(EXTI_SPTR->REG_EXTI_IMR.RegisterAccess, Copy_ELineNum);
}

void MEXTI_vSelectEventTrigger(EXTI_LINE_Etag Copy_ELineNum, TRIGGER_Etag Copy_EventState)
{
	switch (Copy_EventState)
	{
		case TRIGGER_FALLING:
			SET_BIT(EXTI_SPTR->REG_EXTI_FTSR.RegisterAccess, Copy_ELineNum);
			CLR_BIT(EXTI_SPTR->REG_EXTI_RTSR.RegisterAccess, Copy_ELineNum);
		break;
		case TRIGGER_RISING:
			CLR_BIT(EXTI_SPTR->REG_EXTI_FTSR.RegisterAccess, Copy_ELineNum);
			SET_BIT(EXTI_SPTR->REG_EXTI_RTSR.RegisterAccess, Copy_ELineNum);
		break;
		case TRIGGER_ON_CHANGE:
			SET_BIT(EXTI_SPTR->REG_EXTI_RTSR.RegisterAccess, Copy_ELineNum);
			SET_BIT(EXTI_SPTR->REG_EXTI_FTSR.RegisterAccess, Copy_ELineNum);
		break;
		default:		break;
	}
}

void MEXTI_vSoftwareTrigger(EXTI_LINE_Etag Copy_ELineNum)
{
	SET_BIT(EXTI_SPTR->REG_EXTI_SWIER.RegisterAccess, Copy_ELineNum);
}

U8 MEXTI_U8GetPendingInterrupt(EXTI_LINE_Etag Copy_ELineNum)
{
	U8 L_U8GetPending =0;
	L_U8GetPending = GET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, Copy_ELineNum);
	return L_U8GetPending;
}

void MEXTI_vSelectPort(PORT_Etag Copy_ePortNum, EXTI_LINE_Etag Copy_eLineNUM)
{
	/* FOR Safty clear 4 bit */
	SYSCFG_SPTR->REG_SYSCFG_EXTICR[Copy_eLineNUM /4].RegisterAccess &=~(0b1111<<(4U*(Copy_eLineNUM %4)));
	/* Set the value of port */
	SYSCFG_SPTR->REG_SYSCFG_EXTICR[Copy_eLineNUM /4].RegisterAccess |= (Copy_ePortNum<<(4U*(Copy_eLineNUM %4)));
}

void MEXTI_vSetCallBack(void (*ptr)(void), EXTI_LINE_Etag Copy_eLineNUM)
{
	EXTI_CallBack_Ptr[Copy_eLineNUM] = ptr;
}

static void EXTI0_IRQHandler(void)
{
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 0);
	EXTI_CallBack_Ptr[0]();
}
static void EXTI1_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 1);
	EXTI_CallBack_Ptr[1]();
}
static void EXTI2_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 2);
	EXTI_CallBack_Ptr[2]();
}
static void EXTI3_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 3);
	EXTI_CallBack_Ptr[3]();
}
static void EXTI4_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 4);
	EXTI_CallBack_Ptr[4]();
}
static void EXTI5_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 5);
	EXTI_CallBack_Ptr[5]();
}
static void EXTI6_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 6);
	EXTI_CallBack_Ptr[6]();
}
static void EXTI7_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 7);
	EXTI_CallBack_Ptr[7]();
}
static void EXTI8_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 8);
	EXTI_CallBack_Ptr[8]();
}
static void EXTI9_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 9);
	EXTI_CallBack_Ptr[9]();
}
static void EXTI10_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 10);
	EXTI_CallBack_Ptr[10]();
}
static void EXTI11_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 11);
	EXTI_CallBack_Ptr[11]();
}
static void EXTI12_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 12);
	EXTI_CallBack_Ptr[12]();
}
static void EXT13_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 13);
	EXTI_CallBack_Ptr[13]();
}
static void EXTI14_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 14);
	EXTI_CallBack_Ptr[14]();
}
static void EXTI15_IRQHandler(void)
{
	/* Set Pending Interrupt */
	SET_BIT(EXTI_SPTR->REG_EXTI_PR.RegisterAccess, 15);
	EXTI_CallBack_Ptr[15]();
}
