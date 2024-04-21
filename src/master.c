#include "spi.h"

#include "avr/interrupt.h"


int main(void) {

    SPI_MasterInit();


    while (1) {

        SPI_PutString("Hello World !\r\n");

    }

    return 0;
} 