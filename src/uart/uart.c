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


/*================================== Functions ==================================*/



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

    // Put data into buffer
    UDR0 = cData;

    // wait until transmission complete
    while (!( UCSR0A & (1<<UDRE0)));

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
