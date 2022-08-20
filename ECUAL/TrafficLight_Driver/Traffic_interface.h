#ifndef ECUAL_TRAFFICLIGHT_DRIVER_TRAFFIC_INTERFACE_H_
#define ECUAL_TRAFFICLIGHT_DRIVER_TRAFFIC_INTERFACE_H_

typedef enum
		{
	     success,
		 fail
		}
Traffic_Error;

Traffic_Error blinkYellowLED(void);
Traffic_Error HTrafficLightMove(void);
Traffic_Error HTrafficLightWait(void);
Traffic_Error HTrafficLightStop(void);
Traffic_Error HTrafficLightPressedButton(void);

#define LED_Green       1
#define LED_1stYellow   2
#define LED_Red         3
#define LED_2stYellow   4


#endif /* ECUAL_TRAFFICLIGHT_DRIVER_TRAFFIC_INTERFACE_H_ */
