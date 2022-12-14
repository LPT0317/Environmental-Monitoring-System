/* Includes ------------------------------------------------------------------*/
#include "sensor.h"

#define DEBOUNCE_DATA 20

/* Variables -----------------------------------------------------------------*/
long Sensor[7];

unsigned int adc_min = 0;
unsigned int adc_max = 1023;

/*
 * Channel 0
 */
long adc0_value = 0;
int adc0_raw = 0;
unsigned int adc0_total = 0;
unsigned int adc0_data[20];
int adc0_index = 0;

/*
 * Channel 1
 */
long adc1_value = 0;
int adc1_raw = 0;
unsigned int adc1_total = 0;
unsigned int adc1_data[20];
int adc1_index = 0;

/*
 * Channel 2
 */
long adc2_value = 0;
int adc2_raw = 0;
unsigned int adc2_total = 0;
unsigned int adc2_data[20];
int adc2_index = 0;

/*
 * Channel 3
 */
long adc3_value = 0;
int adc3_raw = 0;
unsigned int adc3_total = 0;
unsigned int adc3_data[20];
int adc3_index = 0;

/*
 * Sensor max min value
 */
unsigned int Sensor_Max[7] = {1000, 10000, 10000, 5000, 5000, 10000, 36000};
unsigned int Sensor_Min[7] = {400, 0, 0, 2500, 1000, 2000, 0};

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
long Sensor_Get_Value(unsigned int sensor_name)
{
  if(sensor_name < 0 || sensor_name >= 7)
    return 0;
  return Sensor[sensor_name];
}
void Sensor_Calc(void)
{
  Sensor[pH_Sensor] = pH_min + (adc0_value - adc_min) * (pH_max - pH_min) 
                                                          / (adc_max - adc_min);
  Sensor[SS_Sensor] = SS_min + (adc0_value - adc_min) * (SS_max - SS_min) 
                                                          / (adc_max - adc_min);
  Sensor[COD_Sensor] = COD_min + (adc0_value - adc_min) * (COD_max - COD_min) 
                                                          / (adc_max - adc_min);
  Sensor[TEMP_Sensor] = TEMP_min + (adc1_value - adc_min) * (TEMP_max - TEMP_min) 
                                                          / (adc_max - adc_min);
  Sensor[NH4_Sensor] = NH4_min + (adc2_value - adc_min) * (NH4_max - NH4_min) 
                                                          / (adc_max - adc_min);
  Sensor[NO3_Sensor] = NO3_min + (adc2_value - adc_min) * (NO3_max - NO3_min) 
                                                          / (adc_max - adc_min);
  Sensor[FLOW_Sensor] = FLOW_min + (adc3_value - adc_min) * (FLOW_max - FLOW_min) 
                                                          / (adc_max - adc_min);
}
void ADC_Channel0(void)
{
  int adc0_idx = 0;
  int i = 0;
  adc0_raw = PIC_GET_ADC(0);
  adc0_data[adc0_index] = adc0_raw;
  adc0_index = (adc0_index + 1) % DEBOUNCE_DATA;
  adc0_idx = adc0_index;
  adc0_total = 0;
  for(i = 0; i < DEBOUNCE_DATA; i++)
  {
    adc0_total += adc0_data[adc0_idx];
    if(adc0_idx == 0)
      adc0_idx = DEBOUNCE_DATA - 1;
    else
      adc0_idx--;
  }
  adc0_value = (long)(adc0_total) / DEBOUNCE_DATA;
}
void ADC_Channel1(void)
{
  int adc1_idx = 0;
  int i = 0;
  adc1_raw = PIC_GET_ADC(1);
  adc1_data[adc1_index] = adc1_raw;
  adc1_index = (adc1_index + 1) % DEBOUNCE_DATA;
  adc1_idx = adc1_index;
  adc1_total = 0;
  for(i = 0; i < DEBOUNCE_DATA; i++)
  {
    adc1_total += adc1_data[adc1_idx];
    if(adc1_idx == 0)
      adc1_idx = DEBOUNCE_DATA - 1;
    else
      adc1_idx--;
  }
  adc1_value = (long)(adc1_total) / DEBOUNCE_DATA;
}
void ADC_Channel2(void)
{
  int adc2_idx = 0;
  int i = 0;
  adc2_raw = PIC_GET_ADC(2);
  adc2_data[adc2_index] = adc2_raw;
  adc2_index = (adc2_index + 1) % DEBOUNCE_DATA;
  adc2_idx = adc2_index;
  adc2_total = 0;
  for(i = 0; i < DEBOUNCE_DATA; i++)
  {
    adc2_total += adc2_data[adc2_idx];
    if(adc2_idx == 0)
      adc2_idx = DEBOUNCE_DATA - 1;
    else
      adc2_idx--;
  }
  adc2_value = (long)(adc2_total) / DEBOUNCE_DATA;
}
void ADC_Channel3(void)
{
  int adc3_idx = 0;
  int i = 0;
  adc3_raw = PIC_GET_ADC(3);
  adc3_data[adc3_index] = adc3_raw;
  adc3_index = (adc3_index + 1) % DEBOUNCE_DATA;
  adc3_idx = adc3_index;
  adc3_total = 0;
  for(i = 0; i < DEBOUNCE_DATA; i++)
  {
    adc3_total += adc3_data[adc3_idx];
    if(adc3_idx == 0)
      adc3_idx = DEBOUNCE_DATA - 1;
    else
      adc3_idx--;
  }
  adc3_value = (long)(adc3_total) / DEBOUNCE_DATA;
}
unsigned int Sensor_Get_Max(unsigned int sensor_name)
{
  if(sensor_name < 0 || sensor_name >= 7)
    return 0;
  return Sensor_Max[sensor_name];
}
unsigned int Sensor_Get_Min(unsigned int sensor_name)
{
  if(sensor_name < 0 || sensor_name >= 7)
    return 0;
  return Sensor_Min[sensor_name];
}