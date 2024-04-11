/*
 @module: SPI
 @author: Abdullah Bagyapan
 @date:   11/04/2024
*/


/*================================== Libraries ==================================*/

// Module's own header
#include "spi.h"

// AVR libraries
#include <avr/io.h>

// Standart libraries
#include <stdint.h>


/*================================== Functions ==================================*/


void SPI_Init() {

    // Enable SPI module
    PRR &= ~_BV(PRSPI);

    // @note: Arduino UNO's default SPI I/O ports are PORTB
    // Set MOSI and SCK as output, all others as input
    DDRB = _BV(DDB3) | _BV(DDB5);

    // Enable SPI, Master, set clock rate F_CPU / 16
    SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR0);

    // TODO: Set Clock Polarity and Clock Phase
    
}
