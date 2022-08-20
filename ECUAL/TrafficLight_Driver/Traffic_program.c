#include "../../STD_TYPES.h"
#include "../../BIT_MATH.h"
#include "../../MCAL/Timer_Driver/Timer_interface.h"
#include "../LED_Driver/LED_interface.h"
#include "../LED_Driver/LED_config.h"
#include"Traffic_interface.h"

Traffic_Error blinkYellowLED(void)
{
	u8 blink=0;
	for(blink=0;blink<5*2;blink++)
	{
		HLED_voidBlinkYellow();

	}
	return success;
}
Traffic_Error HTrafficLightMove(void)
{
	 HLED_voidTurnOn(LED_PORT1,LED1_PIN);
	 HLED_voidTurnOn(LED_PORT2,LED3_PIN);
	 MTIMER0_voidStart();
	 MTIMER0_voidGetTimer(5);
	 MTIMER0_voidStop();
	 HLED_voidTurnOff(LED_PORT1,LED1_PIN);
	 HLED_voidTurnOff(LED_PORT2,LED3_PIN);

    return success;
}


Traffic_Error HTrafficLightStop(void)
{
	 HLED_voidTurnOn(LED_PORT1,LED3_PIN);
	 HLED_voidTurnOn(LED_PORT2,LED1_PIN);
	 MTIMER0_voidStart();
	 MTIMER0_voidGetTimer(5);
	 MTIMER0_voidStop();
	 HLED_voidTurnOff(LED_PORT1,LED3_PIN);
	 HLED_voidTurnOff(LED_PORT2,LED1_PIN);



	   return success;
}

Traffic_Error HTrafficLightPressedButton(void)
{
	/*check the condition ( pedestrians can cross the street while the pedestrian's Green LED is on.)(User story two)*/
	if(GET_BIT(LED_PORT1,LED3_PIN) == HIGH)
	{
		 blinkYellowLED();
		 HLED_voidTurnOn(LED_PORT1,LED1_PIN);
		 HLED_voidTurnOn(LED_PORT2,LED3_PIN);
		 MTIMER0_voidStart();
		 MTIMER0_voidGetTimer(5);
		 MTIMER0_voidStop();
		 HLED_voidTurnOff(LED_PORT1,LED1_PIN);
		 HLED_voidTurnOff(LED_PORT2,LED3_PIN);

		   return success;
	}

	/*check the condition(pedestrian must wait until the Green LED is on) (USER STORY ONE)*/
	/*Blinking transfer to green in pedestrian*/
	else if((GET_BIT(LED_PORT1,LED1_PIN) == LOW) && ((GET_BIT(LED_PORT2,LED3_PIN) ==LOW)))
	{

		 HLED_voidTurnOn(LED_PORT2,LED3_PIN);
		 blinkYellowLED();
		 /*Red and Green ON*/
		 HTrafficLightStop();
		   return success;

	}

	/*Blinking transfer to Red in pedestrian*/
	else if((GET_BIT(LED_PORT1,LED1_PIN) == LOW) && ((GET_BIT(LED_PORT2,LED3_PIN) ==LOW)))
	{

		 HLED_voidTurnOn(LED_PORT2,LED1_PIN);
		 blinkYellowLED();
		 HTrafficLightMove();
		   return success;

	}
	else if(GET_BIT(LED_PORT1,LED1_PIN) == HIGH)
	{
		 HLED_voidTurnOn(LED_PORT2,LED3_PIN);
		 blinkYellowLED();
		 /*Red and Green ON*/
		 HTrafficLightStop();

		   return success;
	}
	else
	{
		return fail;
	}
}


