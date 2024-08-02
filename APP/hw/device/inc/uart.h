/*
 * uart_rx.h
 *
 *  Created on: Jul 22, 2024
 *      Author: USER
 */

#ifndef HW_DEVICE_UART_H_
#define HW_DEVICE_UART_H_

#include "hw.h"

extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_usart2_rx;
extern DMA_HandleTypeDef hdma_usart2_tx;
extern UART_HandleTypeDef huart6;


void uart_init();

void uart_re();

void uart_tr();





#endif /* HW_DEVICE_UART_H_ */
