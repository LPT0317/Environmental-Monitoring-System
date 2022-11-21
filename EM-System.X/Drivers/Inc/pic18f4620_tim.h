/* 
 * File:   pic18f4620_tim.h
 * Author: lephu
 *
 * Created on November 21, 2022, 10:05 AM
 */

#ifndef PIC18F4620_TIM_H
#define	PIC18F4620_TIM_H

#ifdef	__cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/*
 * Timer structures definition  
 */
  typedef struct {
  int Period;
  } TIM_Base_InitTypeDef;
  
  
#ifdef	__cplusplus
}
#endif

#endif	/* PIC18F4620_TIM_H */

