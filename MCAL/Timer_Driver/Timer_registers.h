#ifndef MCAL_TIMER_DRIVER_TIMER_REGISTERS_H_
#define MCAL_TIMER_DRIVER_TIMER_REGISTERS_H_


/*TIMER COUNTER REGISTER*/
#define TCCR0_REG              *((volatile u8*)0x53)
#define TCCR0_FOC0               7                     /*Force Compare output*/
#define TCCR0_WGM00              6                     /* Wave form generation Mode*/
#define TCCR0_COM01              5                     /*compare match Output Mode*/
#define TCCR0_COM00              4                     /*compare match Output Mode*/
#define TCCR0_WGM01              3                     /* Wave form generation Mode*/
#define TCCR0_CS02               2                     /*clock select 2:0*/
#define TCCR0_CS01               1
#define TCCR0_CS00               0

/* TIMER COUNTER0 OUTPUT COMPARE REGISTER*/
#define OCR0_REG               *((volatile u8*)0x5C)


/* TIMER COUNTER0*/
#define TCNT0_REG              *((volatile u8*)0x52)
#define TCNT7                    7
#define TCNT6                    6
#define TCNT5                    5
#define TCNT4                    4
#define TCNT3                    3
#define TCNT2                    2
#define TCNT1                    1
#define TCNT0                    0

/*TIMER COUNTER INTERRUPT MASK REGISTER*/
#define TIMSK_REG              *((volatile u8*)0x59)
/* Bits 7:2 are reserved
TIMSK_OCIE2              7
TIMSK_TOIE2              6
TIMSK_TICIE1             5
TIMSK_OCIE1A             4
TIMSK_OCIE1B             3
TIMSK_TOIE1              2
*/
#define TIMSK_OCIE0              1           /*Timer/Counter0 Output compare match interrupt enable*/
#define TIMSK_TOIE0              0           /* Timer/Counter0 overflow interrupt enable*/


/*TIMER COUNTER INTERRUPT FLAG REGISTER*/
#define TIFR_REG              *((volatile u8*)0x58)
/* Bits 7:2 are reserved
TIFR_OCF2               7
TIFR_TOV2               6
TIFR_ICF1               5
TIFR_OCF1A              4
TIFR_OCF1B              3
TIFR_TOV1               2
*/
#define TIFR_OCF0               1                 /*Output compare flag 0*/
#define TIFR_TOV0               0                 /*Timer/Counter0 overflow flag*/

//*Clock select Bit Description*/
#define NO_CLK                  0
#define CLK_NOPRESCALER         1
#define CLK_PRESCALER_8         2
#define CLK_PRESCALER_64        3
#define CLK_PRESCALER_256       4
#define CLK_PRESCALER_1024      5
#define EXTCLK_FALLING_EDGE     6
#define EXTCLK_RISING_EDGE      7

/*Bit mask for clock select*/
#define MASK_CLK        0XF8       // 0b11111000



#endif /* MCAL_TIMER_DRIVER_TIMER_REGISTERS_H_ */
