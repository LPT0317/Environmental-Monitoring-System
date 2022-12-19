/* Includes ------------------------------------------------------------------*/
#include "sensor.h"
#include "menu_set.h"
#include "calib.h"

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

/* Function prototypes -------------------------------------------------------*/
long Sensor_Get_Value(unsigned int sensor_name)
{
  if(sensor_name < 0 || sensor_name >= 7)
    return 0;
  return Sensor[sensor_name];
}
void Sensor_Calc(void)
{
    unsigned int index, calib_max, calib_min;
    long temp_adc_value;
    for (index = 0; index < 7; index++) {
        calib_max = get_calib(CALIB_MAX, index);
        calib_min = get_calib(CALIB_MIN, index);
        switch (index) {
            case 0:
            case 1:
            case 2:
                temp_adc_value = adc0_value;
                break;
            case 3:
                temp_adc_value = adc1_value;
                break;
            case 4:
            case 5:
                temp_adc_value = adc2_value;
                break;
            case 6:
                temp_adc_value = adc3_value;
                break;
        }
        Sensor[index] = calib_min + (temp_adc_value - adc_min) * 
                        (calib_max - calib_min) / (adc_max - adc_min);
//        Sensor[index] = calib_min;
    }
//  Sensor[pH_Sensor] = pH_min + (adc0_value - adc_min) * (pH_max - pH_min) 
//                                                          / (adc_max - adc_min);
//  Sensor[SS_Sensor] = SS_min + (adc0_value - adc_min) * (SS_max - SS_min) 
//                                                          / (adc_max - adc_min);
//  Sensor[COD_Sensor] = COD_min + (adc0_value - adc_min) * (COD_max - COD_min) 
//                                                          / (adc_max - adc_min);
//  Sensor[TEMP_Sensor] = TEMP_min + (adc1_value - adc_min) * (TEMP_max - TEMP_min) 
//                                                          / (adc_max - adc_min);
//  Sensor[NH4_Sensor] = NH4_min + (adc2_value - adc_min) * (NH4_max - NH4_min) 
//                                                          / (adc_max - adc_min);
//  Sensor[NO3_Sensor] = NO3_min + (adc2_value - adc_min) * (NO3_max - NO3_min) 
//                                                          / (adc_max - adc_min);
//  Sensor[FLOW_Sensor] = FLOW_min + (adc3_value - adc_min) * (FLOW_max - FLOW_min) 
//                                                          / (adc_max - adc_min);
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