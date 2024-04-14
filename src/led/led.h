/*
 @module: LED
 @author: Abdullah Bagyapan
 @date:   14/04/2024
*/


/*================================== Libraries ==================================*/


// AVR libraries
#include "avr/io.h"


/*================================== Defined Variables ==================================*/


#define LED_PORT                PORTD
#define LED_PORT_PIN            PORTD7

#define LED_DDR                 DDRD
#define LED_DDR_PIN             DDD7


/*================================== Functions ==================================*/



/*
 @brief:  Initialize led

 @author  Abdullah Bagyapan

 @date    14/04/2024

 @note    Initialize led on PORTD-7 which is not built-in led port

 @param   None

 @return  None
*/
void LED_Init(void);



/*
 @brief:  Turn on led

 @author  Abdullah Bagyapan

 @date    14/04/2024

 @param   None

 @return  None
*/
void LED_On(void);



/*
 @brief:  Turn off led

 @author  Abdullah Bagyapan

 @date    14/04/2024

 @param   None

 @return  None
*/
void LED_Off(void);