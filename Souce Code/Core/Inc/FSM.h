/*
 * FSM.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Admin
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

#include "main.h"
#include "string.h"
#include "software_Timer.h"

#define MAX_BUFFER_SIZE   30

#define WAIT              1
#define COMMAND           2

#define WAIT_SENDER       5
#define RESPONSE           6
#define REPEAT            7

ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;

uint8_t temp;
uint8_t buffer_flag;

extern int command_Status;
extern int uart_Status;

void HAL_UART_RxCptlCallback(UART_HandleTypeDef* huart);
void fsm_command();
void fsm_uart();

#endif /* INC_FSM_H_ */
