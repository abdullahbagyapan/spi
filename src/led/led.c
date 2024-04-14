/*
 @module: LED
 @author: Abdullah Bagyapan
 @date:   14/04/2024
*/


/*================================== Libraries ==================================*/


// Module's own header
#include "led.h"


// AVR libraries
#include "avr/io.h"


/*================================== Functions ==================================*/


void LED_Init(void) {

    // Set Data Direction Register to output
    DDRD |= _BV(DDD7);

}


void LED_On(void) {

    PORTD |= _BV(PORTD7);

}


void LED_Off(void) {

    PORTD &= ~_BV(PORTD7);

}