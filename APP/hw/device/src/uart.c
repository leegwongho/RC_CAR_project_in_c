/*
 * uart_rx.c
 *
 *  Created on: Jul 22, 2024
 *      Author: USER
 */

#include "uart.h"

uint8_t rxData[4];





void uart_init(){

}


void uart_re(){

	HAL_UART_Receive_IT(&huart6, rxData, sizeof(rxData));

}


void uart_tr(){
	//HAL_UART_Transmit_IT(&huart6, rxData, sizeof(rxData));
}



