
#include "hw.h"


void hwInit(){
	pwm_init();
}

// 할 딜레이 함수 대체
void delay(uint32_t time_ms){
	HAL_Delay(time_ms);
}

// 전원 입력후에 키운트 값을 반환하는 함수
uint32_t millis(void){
	return HAL_GetTick();
}




