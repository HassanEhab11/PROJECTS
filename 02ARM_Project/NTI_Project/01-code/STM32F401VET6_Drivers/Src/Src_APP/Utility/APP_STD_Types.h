/*
 * APP_STD_Types.h
 *
 *  Created on: May 13, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef INC_APP_UTILITY_APP_STD_TYPES_H_
#define INC_APP_UTILITY_APP_STD_TYPES_H_

/* Pointer Typedef *********************************************************************/
#define NULL				((void *)0)
/* Signed Number Typedef ***************************************************************/
typedef signed char         	S8;
typedef signed short int    	S16;
typedef signed long int     	S32;
typedef signed long long		S64;
/* Unsigned Number Typedef *************************************************************/
typedef unsigned char			U8;
typedef unsigned short int  	U16;
typedef unsigned long int   	U32;
typedef unsigned long long  	U64;
/* Floating-Point Number Typedef *******************************************************/
typedef float               	F32;		// 4_Byte	6  decimal places floating point
typedef double              	F64;		// 8_Byte	14 decimal places floating point
typedef long double         	F96;		// 12_Byte	19 decimal places floating point

#endif /* INC_APP_UTILITY_APP_STD_TYPES_H_ */
