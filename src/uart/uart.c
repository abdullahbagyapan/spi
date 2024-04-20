/*
 @module: UART
 @author: Abdullah Bagyapan
 @date:   20/04/2024
*/


/*================================== Libraries ==================================*/


// Module's own header
#include "uart.h"

// AVR libraries
#include <avr/io.h>
#include <avr/interrupt.h>


/*================================== Variables ==================================*/


static struct UART_RING_BUFFER _UART_RING_BUFFER = {.ui8Head = 0, .ui8Tail = 0};


/*================================== Functions ==================================*/


/************ Private Functions ************/


/*
 @brief:  Start UART transmission

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   None

 @details Get data from ring buffer, then put it into TX register

 @return  None
*/
static void _UART_TX_Start(void) {

    uint8_t ui8Data;

    ui8Data = UART_RingBufferGet(&_UART_RING_BUFFER);

    // wait until transmission complete
    while (!( UCSR0A & (1<<UDRE0)));

    // Put data into buffer
    UDR0 = ui8Data;

}



/************ Public Functions ************/


void UART_Init() {

    // Operation mode: Asynchronous USART
    UCSR0C &= ~_BV(UMSEL00) | ~_BV(UMSEL01);
    
    // Set baudrate
    UBRR0H = (uint8_t)((UBRR - 8) >> 8);
    UBRR0L = (uint8_t)(UBRR);

    // Set frame format: 8data, 1stop bit
    UCSR0C |= _BV(UCSZ00) | _BV(UCSZ01) | _BV(USBS0);
    
    // Enable transmitter and receiver
    UCSR0B |= _BV(TXEN0) | _BV(RXEN0);

    // Enable TX interrupt
    UCSR0B |= _BV(TXCIE0);

    // Enable RX interrupt
    UCSR0B |= _BV(RXCIE0);

}



void UART_PutChar(char cData) {

    const uint8_t ui8IsTXOngoing = !UART_RingBufferEmpty(&_UART_RING_BUFFER);

    UART_RingBufferPut(&_UART_RING_BUFFER,cData);

    // if transmit is not happening, start transmitting
    if (!ui8IsTXOngoing) {

        _UART_TX_Start();
    }

}



void UART_PutString(char *pData) {

    // Iterate until string termination character('\0')
    while (*pData != '\0') {

        UART_PutChar(*pData);

        pData++;
    }

}



uint8_t UART_GetChar(void) {

    // Wait for data to be received
    while (!(UCSR0A & (1<<RXC0)));

    // Get received data from buffer
    return UDR0;

}



uint8_t UART_RingBufferGet(struct UART_RING_BUFFER *pRingBuffer) {

    const uint8_t ui8data = pRingBuffer->buffer[pRingBuffer->ui8Tail];
    pRingBuffer->ui8Tail++;

    // if tail points end of the buffer, set tail to index 0
    if (pRingBuffer->ui8Tail == UART_RING_BUFFER_SIZE) {
        pRingBuffer->ui8Tail = 0;
    }

    return ui8data;
}


void UART_RingBufferPut(struct UART_RING_BUFFER *pRingBuffer, uint8_t ui8Data) {
    
    pRingBuffer->buffer[pRingBuffer->ui8Head] = ui8Data;
    pRingBuffer->ui8Head++;

    // if head points end of the buffer, set head to index 0
    if (pRingBuffer->ui8Head == UART_RING_BUFFER_SIZE) {
        pRingBuffer->ui8Head = 0;
    }
}


uint8_t UART_RingBufferFull(const struct UART_RING_BUFFER *pRingBuffer) {

    uint8_t ui8IsRingBufferFull;

    uint8_t ui8IndexAfterHead = pRingBuffer->ui8Head;

    // if next index of head points end of the buffer, set it to index 0
    if (ui8IndexAfterHead == UART_RING_BUFFER_SIZE) {
        ui8IndexAfterHead = 0;
    }

    // if next index of head equals tail, there is no space for more character
    ui8IsRingBufferFull = ui8IndexAfterHead == pRingBuffer->ui8Tail;

    return ui8IsRingBufferFull;
}


uint8_t UART_RingBufferEmpty(const struct UART_RING_BUFFER *pRingBuffer) {

    uint8_t ui8IsRingBufferEmpty;

    // if head index and tail index same, there is no characters to put ring buffer before
    ui8IsRingBufferEmpty = pRingBuffer->ui8Head == pRingBuffer->ui8Tail;

    return ui8IsRingBufferEmpty;

}


/************ Interrupt Handler Functions ************/


// UART RX Complete
ISR(USART_RX_vect)
{
	uint8_t ui8Data = UDR0;

    // loopback
    UART_PutChar(ui8Data);
}


// UART TX Complete
ISR(USART_TX_vect)
{

}