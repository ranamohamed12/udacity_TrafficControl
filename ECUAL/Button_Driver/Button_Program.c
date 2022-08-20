#include"../../STD_TYPES.h"
#include"../../BIT_MATH.h"
#include "Button_interface.h"

void HButton_voidInit(u8 copy_u8PortId, u8 copy_u8PIN)
{
	 MDIO_voidInitPinDirection(copy_u8PortId,copy_u8PIN,INPUT);
}

void HButton_voidRead(u8 copy_u8PortId, u8 copy_u8PIN, u8 *ptr_u8StateButton)
{
	 MDIO_voidReadPinValue(copy_u8PortId,copy_u8PIN,ptr_u8StateButton);

}
