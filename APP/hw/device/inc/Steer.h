/*
 * Steer.h
 *
 *  Created on: Jul 31, 2024
 *      Author: USER
 */

#ifndef HW_DEVICE_INC_STEER_H_
#define HW_DEVICE_INC_STEER_H_

#include "hw.h"

#define ST_PORT_R	GPIOC
#define ST_PIN_R_IN4 	GPIO_PIN_0
#define ST_PIN_R_IN3 	GPIO_PIN_1

#define ST_PORT_L0	GPIOC
#define ST_PORT_L1	GPIOB
#define ST_PIN_L_IN1 	GPIO_PIN_9
#define ST_PIN_L_IN2 	GPIO_PIN_8


void steer_init();

void steer_right_left_stop(uint8_t right_0_left_1, uint8_t right_1_left_0);

void st_back_stop(uint8_t st_1_back_0,uint8_t st_0_back_1 );

void steer_joy();

#endif /* HW_DEVICE_INC_STEER_H_ */
