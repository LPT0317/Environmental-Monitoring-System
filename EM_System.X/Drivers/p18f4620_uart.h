/* 
 * File:   p18f4620_uart.h
 * Author: lephu
 *
 * Created on November 30, 2022, 1:20 PM
 */

#ifndef P18F4620_UART_H
#define	P18F4620_UART_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <p18f4620.h>
#include "p18f4620_lcd.h"
#include "../Software/communication.h"

/* Function prototypes -------------------------------------------------------*/
void PIC_UART_INIT(void);
void PIC_UART_ISR(void);
char PIC_UART_RECEIVE(void);
void PIC_UART_TRANSMIT_CHAR(char data);
void PIC_UART_TRANSMIT_STRING(const rom char *data);
void PIC_UART_TRANSMIT_NUM(long num);
void PIC_UART_TRANSMIT_FLOAT(long num);

#ifdef	__cplusplus
}
#endif

#endif	/* P18F4620_UART_H */

