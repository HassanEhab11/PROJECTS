/*
 * MCAL_SPI_Register.h
 *
 *  Created on: Jun 1, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef SRC_MCAL_SPI_MCAL_SPI_REGISTER_H_
#define SRC_MCAL_SPI_MCAL_SPI_REGISTER_H_

#define SPI_1_PERIPHERAL_BASE_ADDRESS    0x40013000
#define SPI_2_PERIPHERAL_BASE_ADDRESS    0x40003800
#define SPI_3_PERIPHERAL_BASE_ADDRESS    0x40003C00
#define SPI_4_PERIPHERAL_BASE_ADDRESS    0x40013400

typedef struct
{
	volatile Reg_32Bit_Utag  REG_SPI_CR1		; /*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
	volatile Reg_32Bit_Utag  REG_SPI_CR2		; /*!< SPI control register 2,                             Address offset: 0x04 */
	volatile Reg_32Bit_Utag  REG_SPI_SR		 	; /*!< SPI status register,                                Address offset: 0x08 */
	volatile Reg_32Bit_Utag  REG_SPI_DR		 	; /*!< SPI data register,                                  Address offset: 0x0C */
	volatile Reg_32Bit_Utag  REG_SPI_CRCPR		; /*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
	volatile Reg_32Bit_Utag  REG_SPI_RXCRCR	 	; /*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
	volatile Reg_32Bit_Utag  REG_SPI_TXCRCR	 	; /*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
	volatile Reg_32Bit_Utag  REG_SPI_I2SCFGR	; /*!< SPI_I2S configuration register,                     Address offset: 0x1C */
	volatile Reg_32Bit_Utag  REG_SPI_I2SPR		; /*!< SPI_I2S prescaler register,                         Address offset: 0x20 */

}SPI_PERIPHERAL_Stag;
// Config {(UN_DIR OR BI_DIR , (CRC :for check) , (DFF : data size (8,16) , (SSM : SS MODE By hardware or software ), (SSI : value of ss by software) ,  (data order) , (EN),(Boud rate ) , ( MASTER OR SLAVE ),  CPOL , CPHA }

/*============================================================================================
	-)	Struct Pointer :	Base_Address ->	SPIx
  ============================================================================================*/
#define    SPI1_SPTR	((volatile SPI_PERIPHERAL_Stag *)SPI_1_PERIPHERAL_BASE_ADDRESS)
#define    SPI2_SPTR	((volatile SPI_PERIPHERAL_Stag *)SPI_2_PERIPHERAL_BASE_ADDRESS)
#define    SPI3_SPTR	((volatile SPI_PERIPHERAL_Stag *)SPI_3_PERIPHERAL_BASE_ADDRESS)
#define    SPI4_SPTR	((volatile SPI_PERIPHERAL_Stag *)SPI_4_PERIPHERAL_BASE_ADDRESS)

#endif /* SRC_MCAL_SPI_MCAL_SPI_REGISTER_H_ */
