/* 
 * File:   communication.h
 * Author: lephu
 *
 * Created on December 19, 2022, 10:05 PM
 */

#ifndef COMMUNICATION_H
#define	COMMUNICATION_H

#ifdef	__cplusplus
extern "C"
{
#endif

#include "../Drivers/p18f4620_uart.h"
#include "../Drivers/p18f4620_lcd.h"
  
void uart_communication(void);


#ifdef	__cplusplus
}
#endif

#endif	/* COMMUNICATION_H */

