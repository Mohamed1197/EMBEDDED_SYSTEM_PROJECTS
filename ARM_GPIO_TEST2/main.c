#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"


#define   GPIOA_CRL      *((volatile u32*)0x40010800+0x00)
#define   GPIOA_ODR      *((volatile u32*)0x40010800+0x0C)

int main(void)
{
	MRCC_voidInit();
	MRCC_voidEnableClock(RCC_APB2,2);
	GPIOA_CRL = 0x00000002;
	GPIOA_ODR = 0x0000000F;

	while(1)
	{

	}

	return 0;
}

