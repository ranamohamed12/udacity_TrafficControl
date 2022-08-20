#ifndef  LED_INTERFACE_H
#define  LED_INTERFACE_H
#include"../../MCAL/DIO_Driver/DIO_interface.h"

/*
Options of pins :-
PIN0
PIN1
PIN2
PIN3
PIN4
PIN5
PIN6
PIN7

*/





void HLED_voidInitialize(u8 copy_u8PortId,u8 copy_u8PIN);
void HLED_voidTurnOn(u8 copy_u8PortId,u8 copy_u8PIN);
void HLED_voidTurnOff(u8 copy_u8PortId,u8 copy_u8PIN);
void HLED_voidToggle(u8 copy_u8PortId,u8 copy_u8PinId);
void HLED_voidBlinkYellow(void);








#endif
