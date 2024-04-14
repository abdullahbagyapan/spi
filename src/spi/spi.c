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
#include <avr/interrupt.h>

// Standart libraries
#include <stdint.h>



/*================================== Defined Variables ==================================*/


static struct SPI_RING_BUFFER _spi_tx_ring_buffer = {.ui8Head = 0, .ui8Tail = 0};
static struct SPI_RING_BUFFER _spi_rx_ring_buffer = {.ui8Head = 0, .ui8Tail = 0};



/*================================== Functions ==================================*/



/************ Private Functions ************/


/*
 @brief:  Start SPI transmission

 @author  Abdullah Bagyapan

 @date    14/04/2024

 @param   None

 @details Get data from tx ring buffer, then put it into TX register

 @return  None
*/
static void _SPI_TX_Start(void) {

    uint8_t ui8Data;

    ui8Data = SPI_RingBufferGet(&_spi_tx_ring_buffer);

    // Wait for transmission complete
    while(!(SPSR & _BV(SPIF)));

    // Start transmission
    SPDR = ui8Data;

}


/************ Public Functions ************/



void SPI_MasterInit() {

    // Enable SPI module
    PRR &= ~_BV(PRSPI);

    // @note: Arduino UNO's default SPI I/O ports are PORTB
    // Set MOSI and SCK as output, all others as input
    DDRB = _BV(DDB3) | _BV(DDB5);

    // Enable SPI, Master, set clock rate F_CPU / 16
    SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR0);

    // Set Clock Polarity and Clock Phase
    SPCR &= ~_BV(CPOL) | ~_BV(CPHA);
    
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

    const uint8_t ui8IsTXOngoing = !SPI_RingBufferEmpty(&_spi_tx_ring_buffer);

    SPI_RingBufferPut(&_spi_tx_ring_buffer,ui8Data);

    // if transmit is not happening, start transmitting
    if (!ui8IsTXOngoing) {

        _SPI_TX_Start();
    }

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


uint8_t SPI_RingBufferGet(struct SPI_RING_BUFFER *pRingBuffer) {

    const uint8_t ui8data = pRingBuffer->buffer[pRingBuffer->ui8Tail];
    pRingBuffer->ui8Tail++;

    // if tail points end of the buffer, set tail to index 0
    if (pRingBuffer->ui8Tail == SPI_RING_BUFFER_SIZE) {
        pRingBuffer->ui8Tail = 0;
    }

    return ui8data;
}


void SPI_RingBufferPut(struct SPI_RING_BUFFER *pRingBuffer, uint8_t ui8Data) {
    
    pRingBuffer->buffer[pRingBuffer->ui8Head] = ui8Data;
    pRingBuffer->ui8Head++;

    // if head points end of the buffer, set head to index 0
    if (pRingBuffer->ui8Head == SPI_RING_BUFFER_SIZE) {
        pRingBuffer->ui8Head = 0;
    }
}


uint8_t SPI_RingBufferFull(const struct SPI_RING_BUFFER *pRingBuffer) {

    uint8_t ui8IsRingBufferFull;

    uint8_t ui8IndexAfterHead = pRingBuffer->ui8Head;

    // if next index of head points end of the buffer, set it to index 0
    if (ui8IndexAfterHead == SPI_RING_BUFFER_SIZE) {
        ui8IndexAfterHead = 0;
    }

    // if next index of head equals tail, there is no space for more character
    ui8IsRingBufferFull = ui8IndexAfterHead == pRingBuffer->ui8Tail;

    return ui8IsRingBufferFull;
}


uint8_t SPI_RingBufferEmpty(const struct SPI_RING_BUFFER *pRingBuffer) {

    uint8_t ui8IsRingBufferEmpty;

    // if head index and tail index same, there is no characters to put ring buffer before
    ui8IsRingBufferEmpty = pRingBuffer->ui8Head == pRingBuffer->ui8Tail;

    return ui8IsRingBufferEmpty;

}



/************ Interrupt Handler Functions ************/


// SPI Serial Transfer Complete
// If a data received, put it into rx buffer
ISR(SPI_STC_vect)
{

    uint8_t ui8Data = SPDR;

    SPI_RingBufferPut(&_spi_rx_ring_buffer,ui8Data);
    
}