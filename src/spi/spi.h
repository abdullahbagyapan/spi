/*
 @module: SPI
 @author: Abdullah Bagyapan
 @date:   11/04/2024
*/


/*================================== Libraries ==================================*/


// Standart libraries
#include <stdint.h>


// AVR libraries
#include <avr/io.h>



/*================================== Defined Variables ==================================*/


// SPI pin ports
#define SPI_SCK_PIN             PORTB5
#define SPI_MISO_PIN            PORTB4
#define SPI_MOSI_PIN            PORTB3
#define SPI_CS_PIN              PORTB2



/*================================== Functions ==================================*/



/*
 @brief:  Initialize SPI system

 @author  Abdullah Bagyapan

 @date    14/04/2024

 @details Initialize SPI as a master

 @param   None

 @return  None
*/
void SPI_MasterInit();


/*
 @brief:  Initialize SPI system

 @author  Abdullah Bagyapan

 @date    14/04/2024

 @details Initialize SPI as a slave

 @param   None

 @return  None
*/
void SPI_SlaveInit();



/*
 @brief:  Set CS pin low

 @author  Abdullah Bagyapan

 @date    15/04/2024

 @param   None

 @return  None
*/
void SPI_BeginTransaction();



/*
 @brief:  Set CS pin high

 @author  Abdullah Bagyapan

 @date    15/04/2024

 @param   None

 @return  None
*/
void SPI_EndTransaction();



/*
 @brief:  Receive data

 @author  Abdullah Bagyapan

 @date    11/04/2024

 @details Receive data from slave

 @param   None

 @return  None
*/
uint8_t SPI_GetChar();



/*
 @brief:  Transmit data

 @author  Abdullah Bagyapan

 @date    11/04/2024

 @details Transmit data to slave

 @param   None

 @return  None
*/
void SPI_PutChar(uint8_t ui8Data);



/*
 @brief:  Transmit string

 @author  Abdullah Bagyapan

 @date    14/04/2024

 @details Transmit data to slave

 @param   None

 @return  None
*/
void SPI_PutString(uint8_t *ui8pData);
