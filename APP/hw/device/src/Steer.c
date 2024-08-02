/*
 * Steer.c
 *
 *  Created on: Jul 31, 2024
 *      Author: USER
 */


#include "Steer.h"


extern uint16_t value_x;
extern uint16_t value_y;

extern int16_t value_x_div;
extern int16_t value_y_div;

extern uint8_t distance;

void steer_init(){

}

// 01 우회전 10  좌회전
void steer_right_left_stop(uint8_t right_0_left_1, uint8_t right_1_left_0){

	HAL_GPIO_WritePin(ST_PORT_R, ST_PIN_R_IN3, right_1_left_0);
	HAL_GPIO_WritePin(ST_PORT_R, ST_PIN_R_IN4, right_0_left_1);
	HAL_GPIO_WritePin(ST_PORT_L0, ST_PIN_L_IN1, right_1_left_0);
	HAL_GPIO_WritePin(ST_PORT_L1, ST_PIN_L_IN2, right_0_left_1);

}

void st_back_stop(uint8_t st_1_back_0,uint8_t st_0_back_1 ){

	HAL_GPIO_WritePin(ST_PORT_R, ST_PIN_R_IN3, st_1_back_0);
	HAL_GPIO_WritePin(ST_PORT_R, ST_PIN_R_IN4, st_0_back_1);
	HAL_GPIO_WritePin(ST_PORT_L0, ST_PIN_L_IN1, st_0_back_1);
	HAL_GPIO_WritePin(ST_PORT_L1, ST_PIN_L_IN2, st_1_back_0);

}


void steer_joy(){
    HCSR04_read();

	if(value_y <= 1500){
		if(value_x <= 1500){
		    if(distance <= 10){
				st_back_stop(1, 1);
			}
		    else{
		    	pwm_con(1000, 500 + (1000-value_x_div));
		    	steer_right_left_stop(0, 1);
		    }
		}
		else if (value_x <= 2500){
		    if(distance <= 10){
				st_back_stop(1, 1);
			}
		    else {
		    	pwm_con(1000, 500 + (1000-value_y_div));
		    	st_back_stop(1, 0);
		    }
		}
		else if (value_x <= 4096){
		    if(distance <= 10){
				st_back_stop(1, 1);
			}
		    else{
		    	pwm_con(1000, (value_x_div));
		    	steer_right_left_stop(1, 0);
		    }
		}
	}
	else if (value_y <= 2500){
		if(value_x <= 1500){
		    	pwm_con(1000, 500 + (1000-value_x_div));
		    	steer_right_left_stop(0, 1);
		}
		else if (value_x <= 2500){
		    	pwm_con(0, 0);
		    	st_back_stop(0, 0);
		}
		else if (value_x <= 4096){
		    	pwm_con(1000, (value_x_div));
		    	steer_right_left_stop(1, 0);
		}
	}
	else if (value_y <= 4096){
		if(value_x <= 1500){
		    	pwm_con(1000, 500 + (1000-value_x_div));
		    	steer_right_left_stop(0, 1);
		}
		else if (value_x <= 2500){
		    	pwm_con(1000, (value_y_div));
		    	st_back_stop(0, 1);
		}
		else if (value_x <= 4096){
		    	pwm_con(1000, (value_x_div));
		    	steer_right_left_stop(1, 0);
		}
	}


}
