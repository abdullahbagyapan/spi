#include "spi.h"


int main(void) {

    SPI_SlaveInit();

    

    while (1) {

        uint8_t ui8Data = SPI_GetChar();

    }

    return 0;
} 