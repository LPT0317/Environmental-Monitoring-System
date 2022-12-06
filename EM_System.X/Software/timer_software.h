/* 
 * File:   timer_software.h
 * Author: lephu
 *
 * Created on November 25, 2022, 10:10 PM
 */

#ifndef TIMER_SOFTWARE_H
#define	TIMER_SOFTWARE_H

#ifdef	__cplusplus
extern "C"
{
#endif
  
/* Defines -------------------------------------------------------------------*/
#define NO_TIMER 1
#define TIME_CYCLE 10
  
#define UART_TIMER 0

/* Function prototypes -------------------------------------------------------*/
// Timer Run
void timer_Run(void);

//Set timer
int set_Timer(unsigned timer, unsigned int duration);

//check Timer flag
int is_Timer_Out(unsigned timer);


#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_SOFTWARE_H */

