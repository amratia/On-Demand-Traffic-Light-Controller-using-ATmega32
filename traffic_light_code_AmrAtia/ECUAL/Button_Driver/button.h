/*
 * button.h
 *
 * Created: 08-Aug-22 6:59:34 PM
 *  Author: Amr Atia
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO_Driver/dio.h"


void button_init(uint8_t buttonPort, uint8_t buttonPin);
void button_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *buttonValue);


#endif /* BUTTON_H_ */