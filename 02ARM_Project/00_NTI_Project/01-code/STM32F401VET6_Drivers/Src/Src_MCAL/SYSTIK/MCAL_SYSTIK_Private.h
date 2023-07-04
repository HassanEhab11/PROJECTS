/*
 * MCAL_SYSTIK_Private.h
 *
 *  Created on: May 31, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef SRC_MCAL_SYSTIK_MCAL_SYSTIK_PRIVATE_H_
#define SRC_MCAL_SYSTIK_MCAL_SYSTIK_PRIVATE_H_

#define STK_CTRL_ENABLE		(1U<<0)
#define STK_CTRL_TICKINT	(1U<<1)
#define STK_CTRL_CLKSOURCE	(1U<<2)
#define STK_CTRL_COUNTFLAG	(1U<<16)

#define PERIODIC	1
#define ONE_TIME	0
#define PWM			2

#endif /* SRC_MCAL_SYSTIK_MCAL_SYSTIK_PRIVATE_H_ */
