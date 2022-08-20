#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include"Timer_registers.h"
#include"Timer_interface.h"
#include"Timer_config.h"
#include"math.h"

#define F_CPU     1000000UL
#define NumBits    256
void MTIMER0_voidInitialize(void)
{

	/*Choose which waveform generation mode*/
	#if (WAVEFORM_GENERATION_MODE == NORMAL_WAVEFORM)
		CLR_BIT(TCCR0_REG, TCCR0_WGM00);
		CLR_BIT(TCCR0_REG, TCCR0_WGM01);


	#elif(WAVEFORM_GENERATION_MODE == PWM_PHASECORRECT_WAVEFORM )
		SET_BIT(TCCR0_REG, TCCR0_WGM00);
		CLR_BIT(TCCR0_REG, TCCR0_WGM01);


	#elif(WAVEFORM_GENERATION_MODE == CTC_WAVEFORM )
		CLR_BIT(TCCR0_REG,TCCR0_WGM00);
		SET_BIT(TCCR0_REG,TCCR0_WGM01);
		/*Set compare match value */
		OCR0_REG = TIMER0_COMPARE_VAL;
		/*Set Initial value */
		//TCNT0_REG = TIMER0_PRELOAD;


	#elif(WAVEFORM_GENERATION_MODE == FAST_PWM_WAVEFORM)
		SET_BIT(TCCR0_REG, TCCR0_WGM00);
		SET_BIT(TCCR0_REG, TCCR0_WGM01);
	#else
	#error wrong waveform generation mode
	#endif

	/*ENABLE which compare match mode*/
	#if ((COMPARE_OUTPUTMODE == NON_PWM_NORMAL_PORT_OPERATION_OC0) || (COMPARE_OUTPUTMODE == FAST_PWM_NORMAL_PORT_OPERATION_OC0) ||( COMPARE_OUTPUTMODE ==PHASE_PWM_NORMAL_PORT_OPERATION_OC0))
		CLR_BIT(TCCR0_REG, TCCR0_COM00);
		CLR_BIT(TCCR0_REG, TCCR0_COM01);

	#elif (COMPARE_OUTPUTMODE ==NON_PWM_TOGGLE_OC0_ONCOMPARE_MATCH)
		SET_BIT(TCCR0_REG, TCCR0_COM00);
		CLR_BIT(TCCR0_REG, TCCR0_COM01);

	#elif ((COMPARE_OUTPUTMODE == NON_PWM_CLEAR_OC0_ONCOMPARE_MATCH)|| (COMPARE_OUTPUTMODE == FAST_PWM_CLEAR_OC0_ONCOMPARE_MATCH) || (COMPARE_OUTPUTMODE == PHASE_PWM_CLEAR_OC0_ONCOMPARE_MATCH))
		CLR_BIT(TCCR0_REG, TCCR0_COM00);
		SET_BIT(TCCR0_REG, TCCR0_COM01);

	#elif ((COMPARE_OUTPUTMODE == NON_PWM_SET_OC0_ONCOMPARE_MATCH) || (COMPARE_OUTPUTMODE == FAST_PWM_SET_OC0_ONCOMPARE_MATCH) || (COMPARE_OUTPUTMODE == PHASE_PWM_SET_OC0_ONCOMPARE_MATCH))
		SET_BIT(TCCR0_REG, TCCR0_COM00);
		SET_BIT(TCCR0_REG, TCCR0_COM01);
	#else
	#error wrong compare match mode
	#endif

}

void MTIMER0_voidStart(void)
{
	/*CHOOSE CLOCK SELECT*/
	TCCR0_REG &=MASK_CLK;
	TCCR0_REG |=CLOCK_SELECT;

}

void MTIMER0_voidGetTimer(u8 Delay)
{

   u8 InitialValue=0;
   u16 NumOfOverflow=0,counter =0,value=0;
   f32 TimeMaxDelay=0,TimeTick =0;

   /*Calculations for Delay*/
   TimeTick = Prescalar/F_CPU;
   TimeMaxDelay = NumBits*TimeTick;
   value =(u16)(Delay/TimeTick);
   NumOfOverflow = ceil (Delay/TimeMaxDelay);
   InitialValue = NumBits - ( value % NumOfOverflow);

	/*Set Initial value */
	TCNT0_REG = InitialValue;

   while(counter < NumOfOverflow)
   	{
   		while((TIFR_REG & (1<<TIFR_TOV0)) == 0);
   		SET_BIT(TIFR_REG,TIFR_TOV0);
   		counter++;
   	}

}

void MTIMER0_voidStop(void)
{
		CLR_BIT(TCCR0_REG,TCCR0_CS00);
		CLR_BIT(TCCR0_REG,TCCR0_CS01);
		CLR_BIT(TCCR0_REG,TCCR0_CS02);


}






