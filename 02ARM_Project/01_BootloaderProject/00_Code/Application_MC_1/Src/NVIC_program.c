/*******************************************************************/
/*******************************************************************/
/***  - Created  : 18/6/2023                                     ***/
/***  - Author   : ITI Embedded Team                             ***/
/***  - Version  : V01                                           ***/
/***               ITI_IMT_ADVANCED EMBEDDED SYSTEM DIPLOMA      ***/
/*******************************************************************/
/*******************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"

#include "NVIC_config.h"
#include "NVIC_interface.h"
#include "NVIC_private.h"

void MNVIC_vEnableIRQ(IRQn_t Copy_tIRQ)
{
	SET_BIT(NVIV_REG->NVIC_ISER[Copy_tIRQ/32], (Copy_tIRQ % 32));

}

void MNVIC_vDisableIRQ(IRQn_t Copy_tIRQ)
{
	SET_BIT(NVIV_REG->NVIC_ICER[Copy_tIRQ/32], (Copy_tIRQ % 32));

}

void MNVIC_vSetPending(IRQn_t Copy_tIRQ)
{
	SET_BIT(NVIV_REG->NVIC_ISPR[Copy_tIRQ/32], (Copy_tIRQ % 32));

}

void MNVIC_vClearPending(IRQn_t Copy_tIRQ)
{
	SET_BIT(NVIV_REG->NVIC_ICPR[Copy_tIRQ/32], (Copy_tIRQ % 32));

}

u8 MNVIC_u8GetActiveFlag(IRQn_t Copy_tIRQ)
{
	return (GET_BIT(NVIV_REG->NVIC_IABR[Copy_tIRQ/32], (Copy_tIRQ % 32)));
}
