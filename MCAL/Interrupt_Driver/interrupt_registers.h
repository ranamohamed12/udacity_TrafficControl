#ifndef MCAL_INTERRUPT_DRIVER_GIE_INTERRUPT_H_
#define MCAL_INTERRUPT_DRIVER_GIE_INTERRUPT_H_

#define  MCUCR_REG       *((volatile u8*)0x55)     /*FOR CONTROL SENSE TO INT0 & INT1*/
#define  MCUCR_ISC00      0
#define  MCUCR_ISC01      1
#define  MCUCR_ISC10      2
#define  MCUCR_ISC11      3


#define  MCUCSR_REG      *((volatile u8*)0x54)
#define  MCUCSR_INT2     6

#define  GICR_REG        *((volatile u8*)0x5B)
#define  GICR_INT0       6
#define  GICR_INT1       7
#define  GICR_INT2       5

#define  GIFR_REG        *((volatile u8*)0x5A)

/*MACROS FOR INTERRUPT NUM */
#define EXIT_INF0    0
#define EXIT_INF1    1
#define EXIT_INF2    2

/* MACROCS*/
#define EXIT_LOW_LEVEL_MODE               1
#define EXIT_ANY_LOGICAL_CHANGE_MODE      2
#define EXIT_ANY_FALLING_EDGE_MODE        3
#define EXIT_ANY_RISING_EDGE_MODE         4

#define ENABLED    1
#define DISABLED   0

/**************************************************************************/
///*Set Global interrupts ,set the i bit in status register to 1*/
//#define sei() __asm__ __volatile__ ("sei" ::: "memory")
//
///*Clear Global interrupts ,set the i bit in status register to 1*/
//#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/**************************************************************************/




#endif
