/*
 * dio.h
 *
 * Created: 08-Aug-22 7:01:07 PM
 *  Author: Amr Atia
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"

// All driver Macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
// Direction Defines
#define IN 0
#define OUT 1
// Value Defines
#define LOW 0
#define HIGH 1

// All Function Prototypes (External / Internal)
void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction); // Initialize the DIO Direction
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);   // Write data to DIO
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber);                  // turn 0 to 1 or 1 to 0
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value);    // Read data from DIO

#endif /* DIO_H_ */