/*
 * software_Timer.h
 *
 *  Created on: Dec 21, 2023
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer0_flag;
extern int timer1_flag;

void setTimer0(int duration);
void setTimer1(int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
