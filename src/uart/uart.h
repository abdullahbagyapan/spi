/*
 @module: UART
 @author: Abdullah Bagyapan
 @date:   20/04/2024
*/


/*================================== Libraries ==================================*/


// Standart libraries
#include <stdint.h>


/*================================== Defined Variables ==================================*/

#define BAUD        38400
#define F_CPU       16000000UL
#define UBRR        F_CPU / 16U / BAUD - 1U

#define UART_RING_BUFFER_SIZE    255

struct UART_RING_BUFFER
{
    uint8_t buffer[UART_RING_BUFFER_SIZE];
    uint8_t ui8Head;
    uint8_t ui8Tail;
};


/*================================== Functions ==================================*/


/*
 @brief:  Initialize UART module

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   None

 @return  None
*/
void UART_Init();



/*
 @brief:  Send char to TX buffer

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   The character to send to TX buffer

 @return  None
*/
void UART_PutChar(char cData);


/*
 @brief:  Send string to TX buffer

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   The string to send to TX buffer

 @return  None
*/
void UART_PutString(char *pData);


/*
 @brief:  Get char from RX buffer

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   None

 @return  The character from RX buffer
*/
uint8_t UART_GetChar(void);



/*
 @brief:  Get character from ring buffer

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   pRingBuffer, the ring buffer

 @return  The character from ring buffer
*/
uint8_t UART_RingBufferGet(struct UART_RING_BUFFER *pRingBuffer);



/*
 @brief:  Put character to ring buffer

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   pRingBuffer, the ring buffer
 @param   ui8Data    , the character to put into ring buffer

 @return  None
*/
void UART_RingBufferPut(struct UART_RING_BUFFER *pRingBuffer, uint8_t ui8Data);


/*
 @brief:  Check if ring buffer is full or not

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   pRingBuffer, the ring buffer

 @return  If ring buffer is not full return 0, otherwise 1 
*/
uint8_t UART_RingBufferFull(const struct UART_RING_BUFFER *pRingBuffer);


/*
 @brief:  Check if ring buffer is empty or not

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   pRingBuffer, the ring buffer

 @return  If ring buffer is not empty return 0, otherwise 1 
*/
uint8_t UART_RingBufferEmpty(const struct UART_RING_BUFFER *pRingBuffer);
