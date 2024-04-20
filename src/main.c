#include "spi.h"
#include "led.h"
#include "clock.h"



int main(void) {

    CLOCK_Init();
    LED_Init();
    SPI_MasterInit();

    SPI_BeginTransaction();

    while (1) {

        LED_On();
        CLOCK_DelayMs(1000);

        SPI_PutChar('A');
            
        LED_Off();
        CLOCK_DelayMs(1000);    
    }

    return 0;
} 