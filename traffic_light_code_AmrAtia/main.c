/*
 * main.c
 *
 * Created: 08-Aug-22 7:08:03 PM
 *  Author: Amr Atia
 */ 
#include "Application/app.h"

#define F_CPU 1000000U // 1MHz

int main(void){
	App_init();
	while(1){
		normal_mode();
	}
	
}

ISR(EXT_INT_0){
	if (isNormalMode == 1){
		pedestrian_mode();
		PORTA = 0x00;
		PORTB = 0x00;
		reset();
	}
	else{
		//do nothing
	}
}