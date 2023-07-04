/*
 * MCAL_SYSTIK.c
 *
 *  Created on: May 31, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "MCAL_SYSTIK_Interface.h"

/*=====================================*/
static U32 STK_CLK_Ms_Ticks;
static U32 STK_RequiredOnTime;
static U32 STK_RequiredOffTime;
//static U32 L_RequiredIntervalTime;
static void(*STK_pAppFun)(void)=NULL;
//static void*STK_pAppFunParameter=NULL;
static volatile U8 STK_CallBackMode;
static volatile U8 G_u8ReadFlag;
static U32 counter;
/*=====================================*/

void MSTK_Init(STK_CLK_SRC_t STK_CLK_SRC)
{
	/*Clear Val & Count flag*/
	STK_SPTR->REG_STK_VAL.RegisterAccess = 0;
	/*Select CLK Source*/
	switch(STK_CLK_SRC)
	{
		case STK_CLK_SRC_HCLK:
			STK_SPTR->REG_STK_CTRL.RegisterAccess = 0x00000004;
			STK_CLK_Ms_Ticks=16000U;
			break;
		case STK_CLK_SRC_HCLK_Div8:
			STK_SPTR->REG_STK_CTRL.RegisterAccess = 0;
			STK_CLK_Ms_Ticks=2000U;
			break;
		default :/*error*/	break;
	}
}

void MSTK_Stop(void)
{
	STK_SPTR->REG_STK_CTRL.RegisterAccess &=~ STK_SPTR->REG_STK_CTRL.RegisterAccess;
	STK_SPTR->REG_STK_LOAD.RegisterAccess =0;
	STK_SPTR->REG_STK_VAL.RegisterAccess =0;
	STK_SPTR->REG_STK_CTRL.RegisterAccess &=~ STK_CTRL_TICKINT;
}

void MSTK_DelayMs(U32 Copy_u32RequiredMs)
{
	STK_SPTR->REG_STK_LOAD.RegisterAccess = (STK_CLK_Ms_Ticks*Copy_u32RequiredMs)-1;
	STK_SPTR->REG_STK_VAL.RegisterAccess =0;
	STK_SPTR->REG_STK_CTRL.RegisterAccess |= STK_CTRL_ENABLE;
	while((STK_SPTR->REG_STK_CTRL.RegisterAccess & STK_CTRL_COUNTFLAG) == 0);
	STK_SPTR->REG_STK_CTRL.RegisterAccess &=~ STK_CTRL_ENABLE;

}

void MSTK_DelayUs(U32 Copy_u32RequiredUs)
{
	STK_SPTR->REG_STK_LOAD.RegisterAccess = ((STK_CLK_Ms_Ticks/1000U)*Copy_u32RequiredUs)-1;
	STK_SPTR->REG_STK_VAL.RegisterAccess =0;
	STK_SPTR->REG_STK_CTRL.RegisterAccess |= STK_CTRL_ENABLE;
	while((STK_SPTR->REG_STK_CTRL.RegisterAccess & STK_CTRL_COUNTFLAG) == 0);
	STK_SPTR->REG_STK_CTRL.RegisterAccess &=~ STK_CTRL_ENABLE;

}

void MSTK_PeriodicCallBackMs(U32 Copy_u32RequiredDelay,void(*pAppFun)(void))
{
	if(pAppFun!=NULL)
	{
		STK_pAppFun =pAppFun;
		STK_SPTR->REG_STK_LOAD.RegisterAccess = (STK_CLK_Ms_Ticks*Copy_u32RequiredDelay)-1;
		STK_SPTR->REG_STK_VAL.RegisterAccess =0;
		STK_SPTR->REG_STK_CTRL.RegisterAccess |= 3U;
		STK_CallBackMode = PERIODIC;
	}
	else{/*error*/}
}

void MSTK_SingleCallBackMs(U32 Copy_u32RequiredDelay,void(*pAppFun)(void))
{
	if(pAppFun!=NULL)
	{
		STK_pAppFun =pAppFun;
		STK_SPTR->REG_STK_LOAD.RegisterAccess = (STK_CLK_Ms_Ticks*Copy_u32RequiredDelay)-1;
		STK_SPTR->REG_STK_VAL.RegisterAccess =0;
		STK_SPTR->REG_STK_CTRL.RegisterAccess |= 3U;
		STK_CallBackMode = ONE_TIME;
	}
	else{/*error*/}
}

U32 MSTK_GetRemainingTime(void)
{
	U32 L_ReadValR;
	L_ReadValR= STK_SPTR->REG_STK_VAL.RegisterAccess;
	return L_ReadValR;
}

U32 MSTK_GetElapsedTime(void)
{
	U32 L_ReadElapsedTime;
	L_ReadElapsedTime= (STK_SPTR->REG_STK_LOAD.RegisterAccess) - (STK_SPTR->REG_STK_VAL.RegisterAccess);
	return L_ReadElapsedTime;
}

void MSTK_PWM(U8 Freq,U16 Duty,void(*pAppFun)(void))
{
	U32 L_RequiredTime  = ((1000U/Freq)*2U);//how 0.5ms in this freq
	STK_RequiredOnTime  = (Duty*L_RequiredTime/1000);
	STK_RequiredOffTime = ((1000-Duty)*L_RequiredTime/1000);
	STK_pAppFun = pAppFun;
	STK_SPTR->REG_STK_LOAD.RegisterAccess = (8000U-1);		//.5ms
	STK_SPTR->REG_STK_VAL.RegisterAccess  =0;
	STK_CallBackMode = PWM;
	STK_pAppFun();
	STK_SPTR->REG_STK_CTRL.RegisterAccess |= 3U;
}

void SysTick_Handler(void)
{
	if(STK_CallBackMode != PWM)
	{
		if(STK_CallBackMode == ONE_TIME)
		{
			STK_SPTR->REG_STK_CTRL.RegisterAccess &=~ STK_CTRL_ENABLE;
			STK_SPTR->REG_STK_LOAD.RegisterAccess =0;
			STK_SPTR->REG_STK_VAL.RegisterAccess  =0;
			STK_SPTR->REG_STK_CTRL.RegisterAccess &=~ STK_CTRL_TICKINT;
		}
		else{/*error*/}
		STK_pAppFun();
	}else
	{
		counter++;
		if(counter == (STK_RequiredOnTime))
		{
			STK_pAppFun();
		}else if(counter == (STK_RequiredOnTime+STK_RequiredOffTime))
		{
			STK_pAppFun();
			counter=0;
		}
	}
	G_u8ReadFlag = GET_BIT(STK_SPTR->REG_STK_CTRL.RegisterAccess, 16U);
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*void STK_PWM(U8 Freq,U16 Duty,void(*pAppFun)(void))
{ //void STK_PWM(U8 Freq, U16 Duty, void(*pAppFun)(void));
	U32 L_RequiredTime = (1000U*1000U/Freq);//how us in this freq
	 L_RequiredOnTime = (Duty*(L_RequiredTime/1000));
	 L_RequiredOffTime = ((1000-Duty)*(L_RequiredTime/1000));
	STK_pAppFun = pAppFun;
	STK->LOAD = (16U-1);		//1us
	STK->VAL=0;
	STK->CTRL |= 3U;
	STK_CallBackMode = PERIODIC;
}*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*For PWM*/
/*
void SysTick_Handler(void)
{
	u8 L_u8ReadFlag;
	static u8 flag;
	static u32 counter;
	counter++;

	if(flag == 0)
	{
		flag=1;
		STK_pAppFun();
	}else if(counter == L_RequiredOnTime)
	{
		STK_pAppFun();
		counter=0;
	}else if (counter == (L_RequiredOnTime+L_RequiredOffTime-1))
	{
		flag=0;
	}

	L_u8ReadFlag = GET_BIT(STK->CTRL,16U);
}*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
