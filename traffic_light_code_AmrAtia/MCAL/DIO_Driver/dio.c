/*
 * dio.c
 *
 * Created: 08-Aug-22 7:01:17 PM
 *  Author: Amr Atia
 */ 
#include "dio.h"
// Global Variables (Static / Extern)
// Function Definitions
//---------------------------------------------------------------------------------------------------------------------- DIO INIT
void DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction){
	switch(portNumber){
		case PORT_A:
		if(direction == IN){
			DDRA &= ~(1<<pinNumber); // Input
		}
		else if(direction == OUT){
			DDRA |= (1<<pinNumber); // Output
		}
		else{
			// Error Handling
		}
		break;
		case PORT_B:
		if(direction == IN){
			DDRB &= ~(1<<pinNumber); // Input
		}
		else if(direction == OUT){
			DDRB |= (1<<pinNumber); // Output
		}
		else{
			// Error Handling
		}
		break;
		case PORT_C:
		if(direction == IN){
			DDRC &= ~(1<<pinNumber); // Input
		}
		else if(direction == OUT){
			DDRC |= (1<<pinNumber); // Output
		}
		else{
			// Error Handling
		}
		break;
		case PORT_D:
		if(direction == IN){
			DDRD &= ~(1<<pinNumber); // Input
		}
		else if(direction == OUT){
			DDRD |= (1<<pinNumber); // Output
		}
		else{
			// Error Handling
		}
		break;
	}
}
//---------------------------------------------------------------------------------------------------------------------- DIO WRITE
void DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value){
	switch(portNumber){
		case PORT_A:
		if(value == LOW){
			PORTA &= ~(1<<pinNumber); // Write 0
		}
		else if(value == HIGH){
			PORTA |= (1<<pinNumber); // Write 1
		}
		else{
			// Error Handling
		}
		break;
		case PORT_B:
		if(value == LOW){
			PORTB &= ~(1<<pinNumber); // Write 0
		}
		else if(value == HIGH){
			PORTB |= (1<<pinNumber); // Write 1
		}
		else{
			// Error Handling
		}
		break;
		case PORT_C:
		if(value == LOW){
			PORTC &= ~(1<<pinNumber); // Write 0
		}
		else if(value == HIGH){
			PORTC |= (1<<pinNumber); // Write 1
		}
		else{
			// Error Handling
		}
		break;
		case PORT_D:
		if(value == LOW){
			PORTD &= ~(1<<pinNumber); // Write 0
		}
		else if(value == HIGH){
			PORTD |= (1<<pinNumber); // Write 1
		}
		else{
			// Error Handling
		}
		break;
	}
}
//---------------------------------------------------------------------------------------------------------------------- DIO Toggle
void DIO_toggle(uint8_t pinNumber, uint8_t portNumber){
	
}
//---------------------------------------------------------------------------------------------------------------------- DIO READ
void DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t *value){
	switch(portNumber){
		case PORT_A:
		*value = (PINA & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_B:
		*value = (PINB & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_C:
		*value = (PINC & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_D:
		*value = (PIND & (1<<pinNumber))>>pinNumber;
		break;
		default:
		//Error Handling
		break;
		
	}
}
