#include "spi.h"
#include "uart.h"


int main(void) {

    SPI_SlaveInit();
    UART_Init();

    while (1) {

        uint8_t ui8Data = SPI_GetChar();
        
        UART_PutChar(ui8Data);
        
    }

    return 0;
} 