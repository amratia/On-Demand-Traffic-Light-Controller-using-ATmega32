/*
 * led.h
 *
 * Created: 08-Aug-22 7:00:09 PM
 *  Author: Amr Atia
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO_Driver/dio.h"

void led_init(uint8_t ledport, uint8_t ledpin);
void led_on(uint8_t ledport, uint8_t ledpin);
void led_off(uint8_t ledport, uint8_t ledpin);
void led_toggle(uint8_t ledport, uint8_t ledpin);
void led_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);


#endif /* LED_H_ */