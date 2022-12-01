/* 
 * File:   p18f4620_adc.h
 * Author: lephu
 *
 * Created on December 1, 2022, 11:53 AM
 */

#ifndef P18F4620_ADC_H
#define	P18F4620_ADC_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <p18f4620.h>
  
/* Defines -------------------------------------------------------------------*/
#define ADC_CHANNEL 13

/* Function prototypes -------------------------------------------------------*/
void PIC_ADC_INIT(void);
int PIC_GET_ADC(unsigned char channel);

#ifdef	__cplusplus
}
#endif

#endif	/* P18F4620_ADC_H */

