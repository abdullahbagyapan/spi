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
