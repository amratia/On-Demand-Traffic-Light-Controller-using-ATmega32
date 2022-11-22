/*
 * registers.h
 *
 * Created: 08-Aug-22 7:03:15 PM
 *  Author: Amr Atia
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"
/************************************************************************/
/* DIO                                                                  */
/************************************************************************/
// PORTA
#define PORTA  *((volatile uint8_t*)0x3B)
// PORTA is an 8-bit register whose address is (0x3B)
// 0X3B is the address
// (uint8_t*) 0x3B --> casting the adress from int to a pointer to char
// the first (*) is the de-referencing operator to write inside the register and not overwrite the address

#define DDRA  *((volatile uint8_t*)0x3A)
#define PINA  *((volatile uint8_t*)0x39)

// PORTB
#define PORTB  *((volatile uint8_t*)0x38)
#define DDRB  *((volatile uint8_t*)0x37)
#define PINB  *((volatile uint8_t*)0x36)

// PORTC
#define PORTC  *((volatile uint8_t*)0x35)
#define DDRC  *((volatile uint8_t*)0x34)
#define PINC  *((volatile uint8_t*)0x33)

// PORTD
#define PORTD  *((volatile uint8_t*)0x32)
#define DDRD  *((volatile uint8_t*)0x31)
#define PIND  *((volatile uint8_t*)0x30)

/************************************************************************/
/* TIMERs                                                               */
/************************************************************************/
#define TCCR0  *((volatile uint8_t*)0x53)
#define TCNT0  *((volatile uint8_t*)0x52)
#define TIFR  *((volatile uint8_t*)0x58)  // Timer Interrupt Flag Register

/************************************************************************/
/* INTERRUPTs                                                           */
/************************************************************************/
#define MCUCR *((volatile uint8_t*)0x55)
#define MCUCSR *((volatile uint8_t*)0x54)
#define GICR *((volatile uint8_t*)0x5B)
#define GIFR *((volatile uint8_t*)0x5A)


#endif /* REGISTERS_H_ */