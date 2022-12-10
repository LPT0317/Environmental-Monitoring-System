/* 
 * File:   sensor.h
 * Author: lephu
 *
 * Created on December 1, 2022, 7:43 PM
 */

#ifndef SENSOR_H
#define	SENSOR_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "../Drivers/p18f4620_adc.h"
  
/* Defines -------------------------------------------------------------------*/
#define pH_Sensor 0
#define SS_Sensor 1
#define COD_Sensor 2
#define TEMP_Sensor 3
#define NH4_Sensor 4
#define NO3_Sensor 5
#define FLOW_Sensor 6
  
/* Function prototypes -------------------------------------------------------*/
long Sensor_Get_Value(unsigned int sensor_name);
void Sensor_Calc(void);
void ADC_Channel0(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_H */

