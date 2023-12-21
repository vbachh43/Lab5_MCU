/*
 * FSM.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Admin
 */

#include "main.h"
#include "FSM.h"
#include "stdio.h"

uint8_t buffer[MAX_BUFFER_SIZE];

uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

int command_Status = WAIT;
int uart_Status = WAIT_SENDER;

uint32_t ADC_value;
uint8_t str[30];

char* get_command(){
	return (char*) buffer;
}

char* clear_command(){
	for (int i = 0; i < MAX_BUFFER_SIZE; i++) buffer[i] = '\0';
	index_buffer = 0;
}

void HAL_UART_RxCptlCallback(UART_HandleTypeDef* huart){
	if (huart -> Instance == USART2){
		buffer_flag = 1;
		HAL_UART_Transmit(&huart2, &temp, 1, 50);
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}

void fsm_command(){
	switch (command_Status){
	case WAIT:
		if (temp == '!') command_Status = COMMAND;
		break;

	case COMMAND:
		if (temp == '#'){
			command_Status = WAIT;
			uart_Status = RESPONSE;
		}
		else{
			buffer[index_buffer++] = temp;
			if (index_buffer >= MAX_BUFFER_SIZE){
				command_Status = WAIT;
				clear_command();
			}
		}
		break;

	default:
		break;
	}
}

void fsm_uart(){
	switch(uart_Status){
	case WAIT_SENDER:
		break;

	case RESPONSE:
		if (strcmp(get_command(), "RST") == 0){
			ADC_value = HAL_ADC_GetValue(&hadc1);
			HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n!ADC=%d#", ADC_value), 100);

			uart_Status = REPEAT;
			clear_command;
			setTimer0(300);
		}
		else{
			uart_Status = WAIT_SENDER;
		}

		clear_command();
		break;

	case REPEAT:
		if (timer0_flag == 1){
			ADC_value = HAL_ADC_GetValue(&hadc1);
			HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n!ADC=%d#", ADC_value), 1000);

			setTimer0(300);
		}

		if (strcmp(get_command(), "OK") == 0){
			uart_Status = WAIT_SENDER;
		}
		break;

	default:
		break;
	}
}

















