/*
 * app.h
 *
 * Created: 08-Aug-22 6:59:13 PM
 *  Author: Amr Atia
 */ 


#ifndef APP_H_
#define APP_H_

#include "../ECUAL/Button_Driver/button.h"
#include "../ECUAL/LED_Driver/led.h"
#include "../MCAL/Timer_Driver/timer.h"
#include "../MCAL/Interrupt_Library/interrupt.h"

#define reset() __asm__ __volatile__ ("jmp 0x00")

int isNormalMode;

void App_init();
void normal_mode();
void pedestrian_mode();
void yellow_car_blink();
void yellow_walk_blink();

#endif /* APP_H_ */