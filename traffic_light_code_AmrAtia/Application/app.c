/*
 * app.c
 *
 * Created: 08-Aug-22 6:58:55 PM
 *  Author: Amr Atia
 */ 
#include "app.h"
#define NUMBER_OF_OVERFLOWS 19532



uint8_t ledState;

void App_init(void){
	
	button_init(PORT_D,2);
	led_init(PORT_A,0); // car green
	led_init(PORT_A,1); // car yellow
	led_init(PORT_A,2); // car red
	led_init(PORT_B,0); // pedestrian green
	led_init(PORT_B,1); // pedestrian yellow
	led_init(PORT_B,2); // pedestrian red
	sei();              // enable global interrupts
	MCUCR |= (1<<0) | (1<<1); // choose external interrupt sense - sense on rising edge 
	GICR |= (1<<6);     // Enable external interrupt 0
	timer_init();
	

}

void normal_mode(void){ // THIS IS NORMAL MODE
	
		isNormalMode = 1; //true
		led_on(PORT_A,0); // car GREEN
		timer_delay_five_seconds();
		led_off(PORT_A,0);
		yellow_car_blink();
		led_on(PORT_A,2); // car red 
		timer_delay_five_seconds();
		led_off(PORT_A,2);
		yellow_car_blink();
}

void pedestrian_mode(void){
	isNormalMode = 0; //false
	// write pedestrian mode
	led_read(2,PORT_A,&ledState);       //read car red
	if (ledState == 1){                 // car RED was on when button pressed
		led_on(PORT_B,0);               // walk GREEN
		led_off(PORT_B,2);              // Turn OFF walk RED 
		led_on(PORT_A,2);               // car RED
		timer_delay_five_seconds();     // 5 seconds 
		led_off(PORT_A,2);              // Turn OFF car RED
	}
	if (ledState == 0){                 // car is GREEN or YELLOW when button pressed 
		led_on(PORT_B,2);               // walk RED
		
		yellow_walk_blink();
		
		led_off(PORT_B,2); 
		led_off(PORT_A,0);
		led_on(PORT_B,0);               // walk GREEN
		led_on(PORT_A,2);               // car RED
		timer_delay_five_seconds();
		led_off(PORT_A,2);
		
	}
	
	yellow_walk_blink();
	
	led_off(PORT_B,0);
	led_on(PORT_B,2);
	led_on(PORT_A,0);
	
	
}

void yellow_car_blink(void){
	for(int i=0; i<5; i++){
		led_on(PORT_A,1);
		timer_delay_half_second();
		led_off(PORT_A,1);
		timer_delay_half_second();
	}
}

void yellow_walk_blink(void){
	for(int i=0; i<5; i++){
		led_on(PORT_B,1);
		led_on(PORT_A,1);
		timer_delay_half_second();
		led_off(PORT_B,1);
		led_off(PORT_A,1);
		timer_delay_half_second();
	}
}



