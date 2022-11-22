/*
 * led.c
 *
 * Created: 08-Aug-22 6:59:59 PM
 *  Author: Amr Atia
 */ 
#include "led.h"

void led_init(uint8_t ledport, uint8_t ledpin){
	DIO_init(ledpin,ledport,OUT);
}
void led_on(uint8_t ledport, uint8_t ledpin){
	DIO_write(ledpin, ledport, HIGH);
}
void led_off(uint8_t ledport, uint8_t ledpin){
	DIO_write(ledpin, ledport, LOW);
}
void led_toggle(uint8_t ledport, uint8_t ledpin){
	uint8_t ledState;
	DIO_read(ledpin, ledport, &ledState);
	if (ledState == 0){
		led_on(ledport, ledpin);
	}
	if (ledState == 1){
		led_off(ledport, ledpin);
	}

}
void led_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value){
	DIO_read(pinNumber, portNumber, value);
}