/*
 @module: SPI
 @author: Abdullah Bagyapan
 @date:   11/04/2024
*/


/*================================== Libraries ==================================*/


// Module's own header
#include "spi.h"

// AVR libraries
#include <avr/interrupt.h>

// Standart libraries
#include <stdint.h>



/*================================== Functions ==================================*/



void SPI_MasterInit() {

    // Enable SPI module
    PRR &= ~_BV(PRSPI);

    // @note: Arduino UNO's default SPI I/O ports are PORTB
    // Set MOSI and SCK as output, all others as input
    DDRB = _BV(SPI_MOSI_PIN) | _BV(SPI_SCK_PIN);

    // Enable SPI, Master, set clock rate F_CPU / 16
    SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR0);

    // Set Clock Polarity and Clock Phase
    SPCR &= ~_BV(CPOL) | ~_BV(CPHA);

    // Set chip select HIGH
    PORTB |=  _BV(SPI_CS_PIN);
    
    
}


void SPI_SlaveInit() {

    // Enable SPI module
    PRR &= ~_BV(PRSPI);

    // @note: Arduino UNO's default SPI I/O ports are PORTB
    // Set MISO output, all others input
    DDRB = _BV(DDB4);

    // Enable SPI
    SPCR = _BV(SPE);

}


void SPI_PutChar(uint8_t ui8Data) {

    // Start transmission
    SPDR = ui8Data;

    // Wait for transmission complete
    while(!(SPSR & _BV(SPIF)));

}


void SPI_PutString(uint8_t *ui8pData) {

    // Iterate until string termination character('\0')
    while (*ui8pData != '\0') {

        SPI_PutChar(*ui8pData);

        ui8pData++;
    }

}


uint8_t SPI_GetChar() {

    // Wait for reception complete
    while(!(SPSR & _BV(SPIF)));

    return SPDR;

}
