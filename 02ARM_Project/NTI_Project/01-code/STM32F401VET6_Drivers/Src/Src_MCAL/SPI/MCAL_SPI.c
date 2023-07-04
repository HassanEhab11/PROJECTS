/*
 * MCAL_SPI.c
 *
 *  Created on: Jun 1, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "MCAL_SPI_Interface.h"

void (* MSPI1_CallBack)(void) = NULL ;

void MSPI_vInit(U8 Copy_u8SPIx)
{
	volatile Reg_32Bit_Utag SPI_Config_Holder ; // to hold SPIx Config

	/* 1.SET PHASE */
	SPI_Config_Holder.BitAccess.BIT0 = SPI_PHASE;

	/* 2.SET PLO */
	SPI_Config_Holder.BitAccess.BIT1 = GET_BIT(SPI_POLARITY, 0);

	/* 3.SET MASTER OR SLAVE */
	SPI_Config_Holder.BitAccess.BIT2 = GET_BIT(SPI_MASTER_SLAVE, 0);

	/* 4.SET BOUD RATE */
	SPI_Config_Holder.BitAccess.BIT3 = GET_BIT(BUAD_RATE, 0);
	SPI_Config_Holder.BitAccess.BIT4 = GET_BIT(BUAD_RATE, 1);
	SPI_Config_Holder.BitAccess.BIT5 = GET_BIT(BUAD_RATE, 2);

	/* 5.SET DATA ORDER */
	SPI_Config_Holder.BitAccess.BIT7 = GET_BIT(DATA_ORDER, 0);

	/* 6.SET SSI */
	SPI_Config_Holder.BitAccess.BIT8 = GET_BIT(SSI_STATE, 0);

	/* 7.SET SSM */
	SPI_Config_Holder.BitAccess.BIT9 = GET_BIT(SSM_STATE, 0);

	/* 8.SET DATA FORMAT */
	SPI_Config_Holder.BitAccess.BIT11 = GET_BIT(DATA_FORMAT, 0);

	switch (Copy_u8SPIx)
	{
	case SPI_1_ : SPI1_SPTR->REG_SPI_CR1 = SPI_Config_Holder; break;
	case SPI_2_ : SPI2_SPTR->REG_SPI_CR1 = SPI_Config_Holder; break;
	case SPI_3_ : SPI3_SPTR->REG_SPI_CR1 = SPI_Config_Holder; break;
	case SPI_4_ : SPI4_SPTR->REG_SPI_CR1 = SPI_Config_Holder; break;
	default     : /*ERROR*/ break;
	}
}

void MSPI_vEnable(U8 Copy_u8SPIx)
{
	switch (Copy_u8SPIx)
	{
	    case SPI_1_ : SPI1_SPTR->REG_SPI_CR1.BitAccess.BIT6 = 1U; break;
		case SPI_2_ : SPI1_SPTR->REG_SPI_CR1.BitAccess.BIT6 = 1U; break;
		case SPI_3_ : SPI1_SPTR->REG_SPI_CR1.BitAccess.BIT6 = 1U; break;
		case SPI_4_ : SPI1_SPTR->REG_SPI_CR1.BitAccess.BIT6 = 1U; break;
		default      : /*ERROR*/ break;
	}
}

void MSPI_vDisable(U8 Copy_u8SPIIndex)
{
	switch (Copy_u8SPIIndex)
	{
		case SPI_1_ : SPI1_SPTR->REG_SPI_CR1.BitAccess.BIT6 = 0U; break;
		case SPI_2_ : SPI1_SPTR->REG_SPI_CR1.BitAccess.BIT6 = 0U; break;
		case SPI_3_ : SPI1_SPTR->REG_SPI_CR1.BitAccess.BIT6 = 0U; break;
		case SPI_4_ : SPI1_SPTR->REG_SPI_CR1.BitAccess.BIT6 = 0U; break;
		default      : /*ERROR*/ break;
	}
}

U16 MSPI1_u16TrasRes(U16 Copy_u16Data)
{
	U16 L_u16Data =0;
	while (GET_BIT(SPI1_SPTR->REG_SPI_SR.RegisterAccess, 7));
	SPI1_SPTR->REG_SPI_DR.RegisterAccess = Copy_u16Data;
	while (GET_BIT(SPI1_SPTR->REG_SPI_SR.RegisterAccess, 7));
	L_u16Data = SPI1_SPTR->REG_SPI_DR.RegisterAccess;
	return L_u16Data;
}

void MSPI1_vSetCallBack(void(*ptr)(void))
{
	/* Set CallBack */
	MSPI1_CallBack = ptr ;
}

void SPI1_IRQHandler(void)
{
	/* Excute Call Back*/
	MSPI1_CallBack();
}

