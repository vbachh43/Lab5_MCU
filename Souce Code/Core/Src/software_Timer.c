/*
 * software_Timer.c
 *
 *  Created on: Dec 21, 2023
 *      Author: Admin
 */

#include "software_Timer.h"

int timer0_counter = 0;
int timer1_counter = 0;

int timer0_flag = 0;
int timer1_flag = 0;

void setTimer0(int duration){
	timer0_counter = duration;
	timer0_flag = 0;
}
void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag = 0;
}

void timerRun(){
	if(timer0_counter > 0){
		timer0_counter--;
		if(timer0_counter == 0) timer0_flag = 1;
	}
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter == 0) timer1_flag = 1;
	}
}
