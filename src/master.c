#include "spi.h"

#include "avr/interrupt.h"


int main(void) {

    SPI_MasterInit();


    while (1) {

        SPI_BeginTransaction();
        
        SPI_PutChar('A');
        
        SPI_EndTransaction();
            
    }

    return 0;
} 