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
    LED_DDR |= _BV(LED_DDR_PIN);

}


void LED_On(void) {

    LED_PORT |= _BV(LED_PORT_PIN);

}


void LED_Off(void) {

    LED_PORT &= ~_BV(LED_PORT_PIN);

}