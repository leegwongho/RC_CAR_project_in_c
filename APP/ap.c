
#include "ap.h"

//uint8_t txData[10];
//uint8_t rxData[10];
extern uint8_t rxData[4];
extern uint16_t pwm_duty;
 uint8_t distance;

//extern uint16_t IC_VALUE1 = 0;  	//rising edge
//extern uint16_t IC_VALUE2 = 0;		//falling edge
//extern uint16_t echoTime = 0;		//falling time - rising time
//extern uint8_t captureFlag = 0;	// capture ?

uint16_t IC_VALUE1 = 0;  	//rising edge
uint16_t IC_VALUE2 = 0;		//falling edge
uint16_t echoTime = 0;		//falling time - rising time
uint8_t captureFlag = 0;

void apInit(void){
	hwInit();

}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1){
		if(captureFlag == 0){
			IC_VALUE1 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);
			captureFlag = 1;
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
		}
		else if (captureFlag == 1){
			IC_VALUE2 = HAL_TIM_ReadCapturedValue(&htim3, TIM_CHANNEL_1);

			__HAL_TIM_SET_COUNTER(&htim3, 0);
			if (IC_VALUE2>IC_VALUE1){
				echoTime = IC_VALUE2 - IC_VALUE1;
			}
			else if (IC_VALUE1 > IC_VALUE2){
				echoTime = ((0xffff) - IC_VALUE1 ) + IC_VALUE2;
			}
			distance = echoTime / 58;
			captureFlag = 0;
			__HAL_TIM_SET_CAPTUREPOLARITY(&htim3, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING);
			__HAL_TIM_DISABLE_IT(&htim3, TIM_IT_CC1);
		}
	}


}


uint16_t value_x;
uint16_t value_y;

int16_t value_x_div;
int16_t value_y_div;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	HAL_UART_AbortReceive_IT(&huart6);

	if(huart->Instance == USART6 ){


			value_y = rxData[0] | (rxData[1]<< 4) ;
			value_x = rxData[2] | (rxData[3]<< 4) ;

			value_y_div = value_y / 4;
			value_x_div = value_x / 4;


//			if(rxData == 'R'){
//				pwm_con(1000, pwm_duty);
//				steer_right_left_stop(1, 0);
//			}
//			if(rxData == 'L'){
//				pwm_con(1000, pwm_duty);
//				steer_right_left_stop(0, 1);
//			}
//			if(rxData == 'S'){
//				pwm_con(1000, pwm_duty);
//				st_back_stop(1, 1);
//			}
//			if(rxData == 'B'){
//				pwm_con(1000, pwm_duty);
//				st_back_stop(0, 1);
//			}
//			if(rxData == 'T'){
//				pwm_up(50);
//				pwm_con(1000, pwm_duty);
//			}
//			if(rxData == 'X'){
//				pwm_down(50);
//				pwm_con(1000, pwm_duty);
//			}




	}


	HAL_UART_Receive_IT(&huart6, rxData, sizeof(rxData));

}


void apMain(void){



	ultrasonic_init();
	uart_re();

	while (1)
	{



        steer_joy();


	}

}


