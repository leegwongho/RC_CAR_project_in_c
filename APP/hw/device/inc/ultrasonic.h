/*
 * ultrasonic.h
 *
 *  Created on: Aug 1, 2024
 *      Author: USER
 */

#ifndef HW_DEVICE_INC_ULTRASONIC_H_
#define HW_DEVICE_INC_ULTRASONIC_H_

#include "hw.h"

#define TRIG_PORT 	GPIOA
#define TRIG_PIN	GPIO_PIN_5



extern TIM_HandleTypeDef htim3;

void ultrasonic_init();

void HCSR04_read();

void HCSR04_distance();


#endif /* HW_DEVICE_INC_ULTRASONIC_H_ */
