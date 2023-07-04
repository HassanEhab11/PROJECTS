/*******************************************************************/
/*******************************************************************/
/***  - Created  : 18/6/2023                                     ***/
/***  - Author   : ITI Embedded Team                             ***/
/***  - Version  : V01                                           ***/
/***               ITI_IMT_ADVANCED EMBEDDED SYSTEM DIPLOMA      ***/
/*******************************************************************/
/*******************************************************************/

#ifndef MFDI_INTERFACE_H_
#define MFDI_INTERFACE_H_

void MFDI_voidEraseAppArea(void) ;
void MFDI_voidFlashWrite(u32 Copy_u32Address ,u16* Copy_PtrData, u8 Copy_u8DataLength) ;
void MFDI_voidSectorErase(u8 Copy_u8SectorNumber) ;



#endif /* MFDI_INTERFACE_H_ */
