#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MCAL/GIE_Driver/GIE_interface.h"
#include "MCAL/Interrupt_Driver/Interrupt_interface.h"
#include "MCAL/Interrupt_Driver/Interrupt_registers.h"
#include "MCAL/Timer_Driver/Timer_interface.h"

#include "ECUAL/LED_Driver/LED_interface.h"
#include "ECUAL/LED_Driver/LED_config.h"
#include "ECUAL/TrafficLight_Driver/Traffic_interface.h"
#include "ECUAL/Button_Driver/Button_interface.h"
#include "ECUAL/Button_Driver/Button_config.h"

void NormalModevoid(void);
void pedestrianModevoid(void);

/*for compiler optimization*/
  u8 pedestrian=0;
  u8 LED = LED_Green;
int main(void)
{
    /*Initialize Timer*/
    MTIMER0_voidInitialize();

    /*Initialize LEDS for cars */
	HLED_voidInitialize(LED_PORT1,LED1_PIN);
	HLED_voidInitialize(LED_PORT1,LED2_PIN);
	HLED_voidInitialize(LED_PORT1,LED3_PIN);

    /*Initialize  Port LEDS for pedestrians */
     MDIO_voidSetPortDirection(PORTB,OUTPUT);

	/*Initialize Button*/
	HButton_voidInit(ButtonPort, ButtonPIN);
	MDIO_voidWritePinValue(ButtonPort,ButtonPIN,HIGH);

	/*enable PIE (EXTI0)*/
	MEXTI_voidEXTINT_Enable(EXIT_INF0);
	MEXTI_voidEXTINT_SenseControl(EXIT_ANY_FALLING_EDGE_MODE, EXIT_INF0);

	/*enable general interrupt  GIE*/
	MGIE_voidGIEEnable();

	 while(1)
	 {
		    LED = LED_Green;
			HTrafficLightMove();
			LED = LED_1stYellow;
			blinkYellowLED();
			LED = LED_Red;
			HTrafficLightStop();
			LED = LED_2stYellow;
			blinkYellowLED();
    }
}

void NormalModevoid(void)
{
	HTrafficLightMove();
	blinkYellowLED();
	HTrafficLightStop();
	blinkYellowLED();
}
void pedestrianModevoid(void)
{
	 switch(LED)
	 {
	 case LED_Green:
		 HLED_voidTurnOn(LED_PORT2,LED3_PIN);
		 blinkYellowLED();
		 HLED_voidTurnOff(LED_PORT1,LED1_PIN);
		 HLED_voidTurnOff(LED_PORT2,LED3_PIN);
		 HTrafficLightStop();
		 break;
	 case LED_1stYellow:
		 blinkYellowLED();
		 HTrafficLightStop();
		 break;
	 case LED_Red:
		 HTrafficLightStop();
		 LED=LED_2stYellow;
		 break;
	 case LED_2stYellow:
		 blinkYellowLED();
		 HTrafficLightStop();
		 NormalModevoid();
		 break;
	 default:
		 //error
		 break;
	 }
}




void __vector_1(void)  __attribute__((signal,used));
void __vector_1(void)
{
	pedestrianModevoid();

}



