#include"../../STD_TYPES.h"
#include"../../BIT_MATH.h"
#include "../../MCAL/Timer_Driver/Timer_interface.h"
#include"LED_config.h"
#include"LED_interface.h"



void HLED_voidInitialize(u8 copy_u8PortId,u8 copy_u8PIN)
{
	 MDIO_voidInitPinDirection(copy_u8PortId,copy_u8PIN,OUTPUT);
}

void HLED_voidTurnOn(u8 copy_u8PortId,u8 copy_u8PIN)
{
	MDIO_voidWritePinValue(copy_u8PortId,copy_u8PIN, HIGH);
}


void HLED_voidTurnOff(u8 copy_u8PortId,u8 copy_u8PIN)
{
	MDIO_voidWritePinValue(copy_u8PortId,copy_u8PIN, LOW);
}

void HLED_voidToggle(u8 copy_u8PortId,u8 copy_u8PinId)
{

	MDIO_voidTogglePinValue(copy_u8PortId,copy_u8PinId);

}
void HLED_voidBlinkYellow(void)
{
	MTIMER0_voidStart();
	MDIO_voidTogglePinValue(LED_PORT1,LED2_PIN);
	MDIO_voidTogglePinValue(LED_PORT2,LED2_PIN);
	MTIMER0_voidGetTimer(1);
	MTIMER0_voidStop();
}


