/*******************************************************************/
/*******************************************************************/
/***  - Created  : 18/6/2023                                     ***/
/***  - Author   : ITI Embedded Team                             ***/
/***  - Version  : V01                                           ***/
/***               ITI_IMT_ADVANCED EMBEDDED SYSTEM DIPLOMA      ***/
/*******************************************************************/
/*******************************************************************/


#ifndef APARSER_INTERFACE_H_
#define APARSER_INTERFACE_H_

u8 APARSER_u8AsciiToHex(u8 Copy_u8Asci) ;



void APARSER_voidParseRecord(volatile u8 * Copy_u8BufRecord) ;




void APARSE_voidParseData(volatile u8* Copy_u8BufData) ;

#endif /* APARSER_INTERFACE_H_ */
