#include "spi.h"

#include "avr/interrupt.h"


int main(void) {

    SPI_MasterInit();

    char *pMessage = "Hello World!\r\n"; 

    while (1) {

        SPI_PutString(pMessage);

    }

    return 0;
} 