#ifndef MCAL_INTERRUPT_DRIVER_INTERRUPT_CONFIG_H_
#define MCAL_INTERRUPT_DRIVER_INTERRUPT_CONFIG_H_

/*  CHOOSE WHICH SENSE CONTROL:
 *  1- FALLING_EDGE_MODE
 *  2- RISING_EDGE_MODE
 *  3- LOW_LEVEL_MODE
 *  4-HIGH_LEVEL_MODE
 *  5- ANY_LOGICAL_CHANGE_MODE     // used configration  file if i write code in rebuild method

 */
/*using Falling edge because the button is pull up
 *  pressed  ---> Low
 * unpressed ---> High*/
#define INT0_SENSE     FALLING_EDGE_MODE

#endif /* MCAL_INTERRUPT_DRIVER_INTERRUPT_CONFIG_H_ */
