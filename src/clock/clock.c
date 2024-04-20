/*
 @module: CLOCK
 @author: Abdullah Bagyapan
 @date:   20/04/2024
*/


/*================================== Libraries ==================================*/


// Module's own header
#include "clock.h"

// AVR libraries
#include <avr/io.h>
#include <avr/interrupt.h>


/*================================== Defined Variables ==================================*/


static volatile uint16_t _CLOCK_Timer_milliseconds;
static volatile uint16_t _CLOCK_TimerFuture_milliseconds;


/*================================== Functions ==================================*/



/******************** Private Functions ********************/



/*
 @brief:  Reset timer

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   None

 @return  None
*/
static void _CLOCK_ResetTimer(void) {

    _CLOCK_Timer_milliseconds = 0;

}



/******************** Public Functions ********************/


void CLOCK_Init() {


    // Enable Timer/Counter0 module
    PRR &= ~_BV(PRTIM0);

    // Set Timer/Counter as clocked directly by the system clock
    TCCR0B |= _BV(CS01);

    // Set Timer/Counter operation to CTC
    TCCR0A |= _BV(WGM01);

    // Set prescaler to 64
    TCCR0B |= _BV(CS01) | _BV(CS00);

    // Set timer frequency to 1 kHz (~1 millisecond)
    OCR0A = F_CPU / 1000 / T_PRESCALER;

    // Enable Timer/Counter Output Compare Match Interrupt
    TIMSK0 |= _BV(OCIE0A);

}



uint8_t CLOCK_Timeout() {

    uint8_t ui8Timeout;

    ui8Timeout = 0;

    if (CLOCK_GetTimer() > _CLOCK_TimerFuture_milliseconds) {

        return ui8Timeout = 1;
    }

    return ui8Timeout;

}



uint16_t CLOCK_GetTimer() {

    return _CLOCK_Timer_milliseconds;
}



void CLOCK_SetTimer(uint16_t ui16TimeoutMs) {

    _CLOCK_ResetTimer();

    _CLOCK_TimerFuture_milliseconds = ui16TimeoutMs;
}



void CLOCK_DelayMs(uint16_t ui16TimeoutMs) {

    _CLOCK_ResetTimer();

    // wait until clock reach given timeout
    while (ui16TimeoutMs >= CLOCK_GetTimer()) {};

}



/******************** Interrupt Handlers ********************/


// Timer/Counter Output Compare Match Interrupt Handler
ISR(TIMER0_COMPA_vect) {

    // Increase timer on every 1 ms 
    _CLOCK_Timer_milliseconds++;

}