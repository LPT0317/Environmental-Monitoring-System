/* 
 * File:   p18f4620_tim.h
 * Author: lephu
 *
 * Created on November 22, 2022, 6:38 PM
 */

#ifndef P18F4620_TIM_H
#define	P18F4620_TIM_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <p18f4620.h>
  
/* Defines -------------------------------------------------------------------*/
#define COUNT 4965
  
/* Variables -----------------------------------------------------------------*/
extern unsigned int PIC_TIM0;
extern unsigned int PIC_TIM1;
extern unsigned int PIC_TIM3;

/* Function prototypes -------------------------------------------------------*/
//Timer 0
void PIC_TIM0_INIT(void);
void PIC_TIM0_START(void);
void PIC_TIM0_STOP(void);
void TIM0_CALLBACK(void);

//Timer 1
void PIC_TIM1_INIT(void);
void PIC_TIM1_START(void);
void PIC_TIM1_STOP(void);
void TIM1_CALLBACK(void);

//Timer 3
void PIC_TIM3_INIT(void);
void PIC_TIM3_START(void);
void PIC_TIM3_STOP(void);
void TIM3_CALLBACK(void);

#ifdef	__cplusplus
}
#endif

#endif	/* P18F4620_TIM_H */

