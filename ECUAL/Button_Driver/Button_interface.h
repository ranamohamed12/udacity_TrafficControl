
#ifndef BUTTON_DRIVER_BUTTON_INTERFACE_H_
#define BUTTON_DRIVER_BUTTON_INTERFACE_H_
#include"../../MCAL/DIO_Driver/DIO_interface.h"


void HButton_voidInit(u8 copy_u8PortId, u8 copy_u8PIN);
void HButton_voidRead(u8 copy_u8PortId, u8 copy_u8PIN, u8 *ptr_u8StateButton);


#endif /* BUTTON_DRIVER_BUTTON_INTERFACE_H_ */
