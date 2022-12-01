/* Includes ------------------------------------------------------------------*/
#include "sensor.h"

/* Variables -----------------------------------------------------------------*/
float Sensor[7] = {0.0};
int raw_value[7] = {0};
unsigned char SENSOR_CHANNEL[7] = {0, 1, 2, 3, 0, 1, 2};

/* Function ------------------------------------------------------------------*/
void calc_Sensor(void)
{
  
}

/* Function prototypes -------------------------------------------------------*/
float Sensor_Get_Value(unsigned int sensor_name)
{
  if(sensor_name < 0 || sensor_name >= 7)
    return 0.0;
  return Sensor[sensor_name];
}
void Analog_Raw_Value(void)
{
  int i = 0;
  for(i = 0; i < 7; i++)
  {
    raw_value[i] = PIC_GET_ADC(SENSOR_CHANNEL[i]);
  }
}
