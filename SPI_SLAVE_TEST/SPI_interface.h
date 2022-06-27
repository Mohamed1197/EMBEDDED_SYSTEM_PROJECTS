/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    : 10/10/2020          ********************/
/**************** SWC     :     SPI             ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_voidInit(void);

u8   SPI_u8TransRecive(u8 Copy_u8SendDataByte ,u8 * Copy_pu8RecievedDataByte);

u8   SPI_u8TransReciveStringSync(u8 * Copy_u8SendDataString ,u8 * Copy_pu8RecievedDataString);

u8   SPI_u8TransReciveStringASync();

#endif
