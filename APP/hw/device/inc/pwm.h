/*
 * pwm.h
 *
 *  Created on: Jul 31, 2024
 *      Author: USER
 */

#ifndef HW_DEVICE_INC_PWM_H_
#define HW_DEVICE_INC_PWM_H_

#include "hw.h"

extern TIM_HandleTypeDef htim4;

void pwm_init();

void pwm_con(uint16_t psc, uint16_t CCR);

void pwm_up(uint16_t up);

void pwm_down(uint16_t down);



#endif /* HW_DEVICE_INC_PWM_H_ */
