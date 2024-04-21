#include "spi.h"

#include "avr/interrupt.h"


int main(void) {

    SPI_MasterInit();

    SPI_BeginTransaction();

    while (1) {

        SPI_PutChar('A');
            
    }

    return 0;
} 