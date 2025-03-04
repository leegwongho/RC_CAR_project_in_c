/*
 * ultrasonic.c
 *
 *  Created on: Aug 1, 2024
 *      Author: USER
 */

#include "ultrasonic.h"

//uint16_t IC_VALUE1 = 0;  	//rising edge
//uint16_t IC_VALUE2 = 0;		//falling edge
//uint16_t echoTime = 0;		//falling time - rising time
//uint8_t captureFlag = 0;	// capture ?
//uint8_t distance;		// distance




void ultrasonic_init(){

	  HAL_TIM_Base_Start(&htim11); // for delay func
	  HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);  // for ultrasonic

}


void HCSR04_read(){		//trig func

	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, 1);
	delay_us(12);
	HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, 0);

	__HAL_TIM_ENABLE_IT(&htim3, TIM_IT_CC1);
}

//void HCSR04_distance(){
//
//	if(captureFlag == 0){
//		IC_VALUE1 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
//		captureFlag = 1;
//		__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
//	}
//	else if (captureFlag == 1){
//		IC_VALUE2 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
//
//		__HAL_TIM_SET_COUNTER(&htim3, 0);
//		if (IC_VALUE2>IC_VALUE1){
//			echoTime = IC_VALUE2 - IC_VALUE1;
//		}
//		else if (IC_VALUE1 > IC_VALUE2){
//			echoTime = ((0xffff) - IC_VALUE1 ) + IC_VALUE2;
//		}
//		distance = echoTime / 58;
//		captureFlag = 0;
//		__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
//		__HAL_TIM_DISABLE_IT(&htim3, TIM_IT_CC1);
//	}
//
//}
