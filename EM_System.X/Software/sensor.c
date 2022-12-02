/* Includes ------------------------------------------------------------------*/
#include "sensor.h"

/* Variables -----------------------------------------------------------------*/
float Sensor[7];

float adc_min = 0;
float adc_max = 1023;

/*
 * pH Sensor
 */
float pH_max = 12;
float pH_min = 0;
float pH_value = 0;
int pH_raw = 0;

/* Function prototypes -------------------------------------------------------*/
float Sensor_Get_Value(unsigned int sensor_name)
{
  if(sensor_name < 0 || sensor_name >= 7)
    return 0.0;
  return Sensor[sensor_name];
}
void Sensor_Calc_pH(void)
{
  pH_raw = PIC_GET_ADC(0);
  pH_value = (float)(pH_raw);
  Sensor[pH_Sensor] = pH_min + (pH_value - adc_min) * (pH_max - pH_min) / (adc_max - adc_min);
}