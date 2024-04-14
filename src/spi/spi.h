/*
 @module: SPI
 @author: Abdullah Bagyapan
 @date:   11/04/2024
*/


/*================================== Libraries ==================================*/


// Standart libraries
#include <stdint.h>


/*================================== Defined Variables ==================================*/


#define SPI_RING_BUFFER_SIZE    255

struct SPI_RING_BUFFER
{
    uint8_t buffer[SPI_RING_BUFFER_SIZE];
    uint8_t ui8Head;
    uint8_t ui8Tail;
};


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
 @brief:  Receive data

 @author  Abdullah Bagyapan

 @date    11/04/2024

 @details Receive data from slave

 @param   None

 @return  None
*/
uint8_t SPI_Receive();



/*
 @brief:  Transmit data

 @author  Abdullah Bagyapan

 @date    11/04/2024

 @details Transmit data to slave

 @param   None

 @return  None
*/
void SPI_Transmit(uint8_t ui8Data);



/*
 @brief:  Get character from ring buffer

 @author  Abdullah Bagyapan

 @date    14/04/2024

 @param   pRingBuffer, the ring buffer

 @return  The character from ring buffer
*/
uint8_t SPI_RingBufferGet(struct SPI_RING_BUFFER *pRingBuffer);



/*
 @brief:  Put character to ring buffer

 @author  Abdullah Bagyapan

 @date    14/04/2024

 @param   pRingBuffer, the ring buffer
 @param   ui8Data    , the character to put into ring buffer

 @return  None
*/
void SPI_RingBufferPut(struct SPI_RING_BUFFER *pRingBuffer, uint8_t ui8Data);


/*
 @brief:  Check if ring buffer is full or not

 @author  Abdullah Bagyapan

 @date    14/04/2024

 @param   pRingBuffer, the ring buffer

 @return  If ring buffer is not full return 0, otherwise 1 
*/
uint8_t SPI_RingBufferFull(const struct SPI_RING_BUFFER *pRingBuffer);


/*
 @brief:  Check if ring buffer is empty or not

 @author  Abdullah Bagyapan

 @date    14/04/2024

 @param   pRingBuffer, the ring buffer

 @return  If ring buffer is not empty return 0, otherwise 1 
*/
uint8_t SPI_RingBufferEmpty(const struct SPI_RING_BUFFER *pRingBuffer);
