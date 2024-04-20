/*
 @module: CLOCK
 @author: Abdullah Bagyapan
 @date:   20/04/2024
*/


/*================================== Libraries ==================================*/


// Standart libraries
#include <stdint.h>


/*================================== Defined Variables ==================================*/


#define F_CPU           16000000
#define T_PRESCALER     64


/*================================== Functions ==================================*/



/*
 @brief:  Initialize CLOCK system

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   None

 @return  None
*/
void CLOCK_Init();




/*
 @brief:  Return timer is timeout or not

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   None

 @return  uint8_t, if it is timeout return 1, otherwise return 0
*/
uint8_t CLOCK_Timeout();



/*
 @brief:  Return timer

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   None

 @return  uint16_t, CLOCK_Timer_milliseconds, the timer
*/
uint16_t CLOCK_GetTimer();



/*
 @brief:  Set timer

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   uint16_t ui16TimeoutMs, the time to set in milliseconds format

 @return  None
*/
void CLOCK_SetTimer(uint16_t ui16TimeoutMs);



/*
 @brief:  Delay until given time out

 @author  Abdullah Bagyapan

 @date    20/04/2024

 @param   uint16_t ui16TimeoutMs, the time to set in milliseconds format

 @return  None
*/
void CLOCK_DelayMs(uint16_t ui16TimeoutMs);