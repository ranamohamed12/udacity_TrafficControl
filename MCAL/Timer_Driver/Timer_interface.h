#ifndef MCAL_TIMER_DRIVER_TIMER_INTERFACE_H_
#define MCAL_TIMER_DRIVER_TIMER_INTERFACE_H_


void MTIMER0_voidInitialize(void);
void MTIMER0_voidStart(void);
void MTIMER0_voidGetTimer(u8 Delay);
void MTIMER0_voidStop(void);

#endif /* MCAL_TIMER_DRIVER_TIMER_INTERFACE_H_ */
