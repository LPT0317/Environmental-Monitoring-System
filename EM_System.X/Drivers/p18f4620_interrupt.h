/* 
 * File:   p18f4620_interrupt.h
 * Author: lephu
 *
 * Created on November 25, 2022, 9:31 PM
 */

#ifndef P18F4620_INTERRUPT_H
#define	P18F4620_INTERRUPT_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <p18f4620.h>
#include "p18f4620_tim.h"
#include "p18f4620_uart.h"

/* Function prototypes -------------------------------------------------------*/
void PIC_INTERRUPT_INIT(void);
void PIC_EXT_INIT(void);
void PIC_LOW_ISR(void);
void PIC_HIGH_ISR(void);

#ifdef	__cplusplus
}
#endif

#endif	/* P18F4620_INTERRUPT_H */

