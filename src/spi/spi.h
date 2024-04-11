/*
 @module: SPI
 @author: Abdullah Bagyapan
 @date:   11/04/2024
*/


/*================================== Libraries ==================================*/


// Standart libraries
#include <stdint.h>


/*================================== Functions ==================================*/



/*
 @brief:  Initialize SPI system

 @author  Abdullah Bagyapan

 @date    11/04/2024

 @details Initialize SPI as a master

 @param   None

 @return  None
*/
void SPI_Init();



/*
 @brief:  Receive data

 @author  Abdullah Bagyapan

 @date    11/04/2024

 @details Receive data from slave

 @param   None

 @return  None
*/
uint8_t SPI_MasterReceive();



/*
 @brief:  Transmit data

 @author  Abdullah Bagyapan

 @date    11/04/2024

 @details Transmit data to slave

 @param   None

 @return  None
*/
void SPI_MasterTransmit(uint8_t ui8Data);