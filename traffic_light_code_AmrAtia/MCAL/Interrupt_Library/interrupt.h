/*
 * interrupt.h
 *
 * Created: 08-Aug-22 7:02:44 PM
 *  Author: Amr Atia
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
/************************************************************************/
/* INTERRUPT VECTORs                                                    */
/************************************************************************/
// External interrupt vector 
// External interrupt request 0
#define EXT_INT_0 __vector_1
// External interrupt request 1
#define EXT_INT_1 __vector_2
// External interrupt request 2
#define EXT_INT_2 __vector_3

// set global interrupts , set the I-bit in status register to 1
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

// clear global interrupts , set the I-bit in status register to 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

// ISR definition 
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)


#endif /* INTERRUPT_H_ */