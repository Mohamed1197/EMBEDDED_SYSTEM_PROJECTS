/*******************************************************************/
/**************** Name    : Mohamed Ahmed Hafiz ********************/
/**************** Date    : 10/10/2020          ********************/
/**************** SWC     :     SPI             ********************/
/**************** Version :     1.0             ********************/
/*******************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_voidInit(void)
{
	#if (SPI_u8_MODE == SPI_u8_MASTER_MODE)
	/* Data Order = MSB First */
	CLR_BIT(SPI_u8_SPCR_REG,5);
	/* Select Master Mode */
	SET_BIT(SPI_u8_SPCR_REG,4);
    /* Clock Polatity Falling/Rising  Clock Phase Setup/Sample */
	SET_BIT(SPI_u8_SPCR_REG,3);
	SET_BIT(SPI_u8_SPCR_REG,2);
	/* Select Clock Fosc/64 */
	SET_BIT(SPI_u8_SPCR_REG,1);
	CLR_BIT(SPI_u8_SPCR_REG,0);
		
	#elif (SPI_u8_MODE == SPI_u8_SLAVE_MODE)
	/* Data Order = MSB First */
	CLR_BIT(SPI_u8_SPCR_REG,5);
	/* Select Slave Mode */
	CLR_BIT(SPI_u8_SPCR_REG,4);
	/* Clock Polatity Falling/Rising  Clock Phase Setup/Sample */
	SET_BIT(SPI_u8_SPCR_REG,3);
	SET_BIT(SPI_u8_SPCR_REG,2);
	#else
		#error "Wrong Choice"
	#endif

    /* Enable SPI */
	SET_BIT(SPI_u8_SPCR_REG,6);
	
}

u8    SPI_u8TransRecive(u8 Copy_u8SendDataByte ,u8 * Copy_pu8RecievedDataByte)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	if(Copy_pu8RecievedDataByte != NULL)
	{
		/* Send Data Byte */
		SPI_u8_SPDR_REG = Copy_u8SendDataByte;
		/* Check The Flag */
		while(!GET_BIT(SPI_u8_SPSR_REG,7));
		/* Read The Input Data */
		*Copy_pu8RecievedDataByte = SPI_u8_SPDR_REG;
		Local_u8ErrorState = STD_TYPES_OK;
	}
	return Local_u8ErrorState;
}

u8   SPI_u8TransReciveStringSync(u8 * Copy_pu8SendDataString ,u8 * Copy_pu8RecievedDataString)
{
	u8 Local_u8ErrorState = STD_TYPES_NOK;
	u8 * Local_u8ReceivedData;
	if(Copy_pu8SendDataString != NULL )
	{
	    u8 character = 0;
	    u8 i = 0;
		while(Copy_pu8SendDataString[character] != '\0')
		{
			character++ ;
		 for(  ; i < character; i++)
		 {
		  /* Write String  */
			 SPI_u8TransRecive (Copy_pu8SendDataString[i],&Local_u8ReceivedData);
		 }

		}
		Local_u8ErrorState = STD_TYPES_OK;
	}
}
