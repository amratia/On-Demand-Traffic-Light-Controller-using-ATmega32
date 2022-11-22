/*
 * timer.c
 *
 * Created: 08-Aug-22 8:09:11 PM
 *  Author: Amr Atia
 */ 
#include "timer.h"
#define fiveSecondDelayOverFlows 19532
#define halfSecondDelayOverFlows 1954
unsigned int overflowsCounter  = 0;


void timer_init(void){
	//Choose Timer Mode
	TCCR0 = 0x00; // Normal Mode
	// Set Timer initial value
	TCNT0 = 0; 
	
}

void timer_delay_five_seconds(void){
	// Timer Start --> setting the clock source
	TCCR0 |= (1<<0); // Set bit 0 equal 1 --> no prescaling

	// One overflow is 256 microseconds because it is 256 ticks and each tick is 1 microseconds because the F(CPU) is 1 MHz
	// 2000 overflows is (2000 * 256 us) which is 512 milliseconds
	while(overflowsCounter < fiveSecondDelayOverFlows){
		while((TIFR & (1<<0)) == 0){/*DO NOTHING*/} // wait until the overflow flag is set
		TIFR |= (1<<0); //Clear the overflow flag
		overflowsCounter++;
	}
	overflowsCounter = 0;
	TCCR0 = 0x00; // timer stop 
}

void timer_delay_half_second(void){
	// Timer Start --> setting the clock source
	TCCR0 |= (1<<0); // Set bit 0 equal 1 --> no prescaling

	// One overflow is 256 microseconds because it is 256 ticks and each tick is 1 microseconds because the F(CPU) is 1 MHz
	// 2000 overflows is (2000 * 256 us) which is 512 milliseconds
	while(overflowsCounter < halfSecondDelayOverFlows){
		while((TIFR & (1<<0)) == 0){/*DO NOTHING*/} // wait until the overflow flag is set
		TIFR |= (1<<0); //Clear the overflow flag
		overflowsCounter++;
	}
	overflowsCounter = 0;
	TCCR0 = 0x00; // timer stop
}


