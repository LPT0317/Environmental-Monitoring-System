/* Includes ------------------------------------------------------------------*/
#include "sensor.h"

/* Variables -----------------------------------------------------------------*/
long Sensor[7];

unsigned int adc_min = 0;
unsigned int adc_max = 1023;
long adc_value = 0;
int adc_raw = 0;
unsigned int adc_total = 0;
unsigned int adc_data[50];
int adc_index = 0;

/*
 * pH Sensor
 */
unsigned int pH_max = 1000;
unsigned int pH_min = 400;

/*
 * SS Sensor
 */
unsigned int SS_max = 10000;
unsigned int SS_min = 0;

/*
 * COD Sensor
 */
unsigned int COD_max = 10000;
unsigned int COD_min = 0;

/*
 * TEMP Sensor
 */
unsigned int TEMP_max = 5000;
unsigned int TEMP_min = 2500;

/*
 * NH4 Sensor
 */
unsigned int NH4_max = 5000;
unsigned int NH4_min = 1000;

/*
 * NO3 Sensor
 */
unsigned int NO3_max = 10000;
unsigned int NO3_min = 2000;

/*
 * FLOW Sensor
 */
unsigned int FLOW_max = 36000;
unsigned int FLOW_min = 0;
/* Function prototypes -------------------------------------------------------*/
float Sensor_Get_Value(unsigned int sensor_name)
{
  if(sensor_name < 0 || sensor_name >= 7)
    return 0.0;
  return Sensor[sensor_name];
}
void Sensor_Calc(void)
{
  Sensor[pH_Sensor] = pH_min + (adc_value - adc_min) * (pH_max - pH_min) 
                                                          / (adc_max - adc_min);
  Sensor[SS_Sensor] = SS_min + (adc_value - adc_min) * (SS_max - SS_min) 
                                                          / (adc_max - adc_min);
  Sensor[COD_Sensor] = COD_min + (adc_value - adc_min) * (COD_max - COD_min) 
                                                          / (adc_max - adc_min);
  Sensor[TEMP_Sensor] = TEMP_min + (adc_value - adc_min) * (TEMP_max - TEMP_min) 
                                                          / (adc_max - adc_min);
  Sensor[NH4_Sensor] = NH4_min + (adc_value - adc_min) * (NH4_max - NH4_min) 
                                                          / (adc_max - adc_min);
  Sensor[NO3_Sensor] = NO3_min + (adc_value - adc_min) * (NO3_max - NO3_min) 
                                                          / (adc_max - adc_min);
  Sensor[FLOW_Sensor] = FLOW_min + (adc_value - adc_min) * (FLOW_max - FLOW_min) 
                                                          / (adc_max - adc_min);
}
void Var_Resistor_Get_Value(void)
{
  int adc_idx = 0;
  int i = 0;
  adc_raw = PIC_GET_ADC(0);
  adc_data[adc_index] = adc_raw;
  adc_index = (adc_index + 1) % 50;
  adc_idx = adc_index;
  adc_total = 0;
  for(i = 0; i < 50; i++)
  {
    adc_total += adc_data[adc_idx];
    if(adc_idx == 0)
      adc_idx = 49;
    else
      adc_idx--;
  }
  adc_value = (long)(adc_total) / 50;
}