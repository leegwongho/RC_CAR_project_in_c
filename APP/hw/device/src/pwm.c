/*
 * pwm.c
 *
 *  Created on: Jul 31, 2024
 *      Author: USER
 */

#include "pwm.h"

uint16_t pwm_duty = 600;

void pwm_init(){

	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);

}

void pwm_con(uint16_t psc, uint16_t CCR){

	TIM4->PSC = psc;
	TIM4->CCR2 = CCR;
}

void pwm_up(uint16_t up){
	if(pwm_duty >= 1000){
		pwm_duty = 600;
	}
	else{
		pwm_duty = pwm_duty + up;
	}

}

void pwm_down(uint16_t down){

	if(pwm_duty <= 350){
		pwm_duty = 400;
	}
	else{
		pwm_duty = pwm_duty - down;
	}
}

