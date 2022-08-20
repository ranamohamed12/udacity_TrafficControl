#ifndef MCAL_INTERRUPT_DRIVER_INTERRUPT_INTERFACE_H_
#define MCAL_INTERRUPT_DRIVER_INTERRUPT_INTERFACE_H_

#define EXIT_LOW_LEVEL_MODE               1
#define EXIT_ANY_LOGICAL_CHANGE_MODE      2
#define EXIT_ANY_FALLING_EDGE_MODE        3
#define EXIT_ANY_RISING_EDGE_MODE         4

/*
void MEXTI_voidEXTI0_Enable(void);
void MEXTI_voidEXTI1_Enable(void);
void MEXTI_voidEXTI2_Enable(void);
*/
/*  CHOOSE WHICH SENSE CONTROL:
 *  1- FALLING_EDGE_MODE
 *  2- RISING_EDGE_MODE
 *  3- LOW_LEVEL_MODE
 *  4-HIGH_LEVEL_MODE
 *  5- ANY_LOGICAL_CHANGE_MODE

 */

u8 MEXTI_voidEXTINT_SenseControl(u8 copy_u8ControlSense, u8 copy_u8Num_INT);
u8 MEXTI_voidEXTINT_Enable(u8 copy_u8Num_INT);
u8 MEXTI_voidEXTINT_Disable(u8 copy_u8Num_INT);

//u8 MEXTI_voidEXTINT0_SetCallBack(void *copy_address_ISR (void));
//void MEXTI_voidEXTINT0_SetCallBack(void);

#endif /* MCAL_INTERRUPT_DRIVER_INTERRUPT_INTERFACE_H_ */
