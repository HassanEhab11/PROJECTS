/*******************************************************************/
/*******************************************************************/
/***  - Created  : 18/6/2023                                     ***/
/***  - Author   : ITI Embedded Team                             ***/
/***  - Version  : V01                                           ***/
/***               ITI_IMT_ADVANCED EMBEDDED SYSTEM DIPLOMA      ***/
/*******************************************************************/
/*******************************************************************/

/****************************************************/
/*   guard of file will call one time in .c file    */
/****************************************************/
             
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/****************************************************/
/*                   Standard Types                 */
/****************************************************/

typedef unsigned char      u8   ;
typedef unsigned short int u16  ;
typedef unsigned long  int u32  ;
typedef signed   char      s8   ;
typedef signed   short int s16  ;
typedef signed   long int  s32  ;
typedef float              f32  ;    
typedef double             f64  ;

/****************************************************/
/*                    BOOLEAN Values                */
/****************************************************/


#ifndef FALSE 
#define FALSE    (0U) 
#endif 

#ifndef TRUE 
#define TRUE     (1U)
#endif

#ifndef NULL
#define NULL    ((void*)0)
#endif

#endif /*STD_TYPES*/			 
