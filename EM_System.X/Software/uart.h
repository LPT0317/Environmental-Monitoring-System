/* 
 * File:   uart.h
 * Author: lephu
 *
 * Created on December 6, 2022, 11:32 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Software/timer_software.h"
#include "../Drivers/p18f4620_uart.h"
#include "../Software/sensor.h"
#include "../Software/threshold.h"
#include "../Software/menu_var.h"
  
/* Function prototypes -------------------------------------------------------*/
void UART_DATA(void);


#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

