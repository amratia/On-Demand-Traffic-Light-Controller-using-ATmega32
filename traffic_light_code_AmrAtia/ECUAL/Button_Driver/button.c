/*
 * button.c
 *
 * Created: 08-Aug-22 6:59:45 PM
 *  Author: Amr Atia
 */ 
#include "button.h"

void button_init(uint8_t buttonPort, uint8_t buttonPin){
	DIO_init(buttonPin, buttonPort, IN);
}
void button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *buttonValue){
	DIO_read(buttonPin, buttonPort, buttonValue);
}
