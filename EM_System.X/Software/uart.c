/* Includes ------------------------------------------------------------------*/
#include "uart.h"

/* State Machine -------------------------------------------------------------*/
#define INIT 0
#define IDLE 1
#define SEND_VALUE 2
#define SEND_ALERT 3
#define SEND_SETTING 4

/* Variables -----------------------------------------------------------------*/
int uart_state = INIT;
int index = 0;
int send = 0;

/* Function prototypes -------------------------------------------------------*/
void UART_DATA(void)
{
  int i = 0;
  switch(uart_state)
  {
    case INIT:
      set_Timer(UART_TIMER, 1000);
      uart_state = IDLE;
      break;
    case IDLE:
      send = 0;
      if(is_Timer_Out(UART_TIMER) == 1)
      {
        uart_state = SEND_VALUE;
      }
      if(Error_flag == 1)
      {
        uart_state = SEND_ALERT;
        set_Timer(UART_TIMER, 1000);
      }
      if(check_SETTING() == 1)
        uart_state = SEND_SETTING;
      break;
    case SEND_VALUE:
      PIC_UART_TRANSMIT_STRING("pH= ");
      PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Value(pH_Sensor));
      PIC_UART_TRANSMIT_STRING(" pH SS= ");
      PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Value(SS_Sensor));
      PIC_UART_TRANSMIT_STRING(" mg/l CSB= ");
      PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Value(COD_Sensor));
      PIC_UART_TRANSMIT_STRING(" mg/l TMP= ");
      PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Value(TEMP_Sensor));
      PIC_UART_TRANSMIT_STRING(" C NH4= ");
      PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Value(NH4_Sensor));
      PIC_UART_TRANSMIT_STRING(" mg/l NO3= ");
      PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Value(NO3_Sensor));
      PIC_UART_TRANSMIT_STRING(" mg/l FLOW= ");
      PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Value(FLOW_Sensor));
      PIC_UART_TRANSMIT_STRING(" m3/h \r");
      set_Timer(UART_TIMER, 1000);
      uart_state = IDLE;
      break;
    case SEND_ALERT:
      index = 0;
      if(is_Timer_Out(UART_TIMER) == 1)
      {
        if(send == 0)
        {
          PIC_UART_TRANSMIT_STRING("SENSOR ALERT!!!\r");
          PIC_UART_TRANSMIT_STRING("Over threshold!!!\r");
          send = 1;
        }
        PIC_UART_TRANSMIT_STRING("SENSOR LIST: ");
        for(i = 0; i < 7; i++)
        {
          if(check_Sensor_threshold(i) == 1)
          {
            if(index != 0)
              PIC_UART_TRANSMIT_CHAR(',');
            PIC_UART_TRANSMIT_STRING(sensor_list[i]);
            index = 1;
          }
        }
        PIC_UART_TRANSMIT_CHAR('\r');
        set_Timer(UART_TIMER, 5000);
        uart_state = SEND_ALERT;
      }
      if(Error_flag == 0)
      {
        uart_state = IDLE;
        set_Timer(UART_TIMER, 10);
      }
      break;
    case SEND_SETTING:
      if(send == 0)
      {
        PIC_UART_TRANSMIT_STRING("SENSOR SETTING\r");
        PIC_UART_TRANSMIT_STRING("pH= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(pH_Sensor));
        PIC_UART_TRANSMIT_STRING(" pH\rSS= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(SS_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l\rCSB= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(COD_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l\rTMP= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(TEMP_Sensor));
        PIC_UART_TRANSMIT_STRING(" C\rNH4= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(NH4_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l\rNO3= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(NO3_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l\rFLOW= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(FLOW_Sensor));
        PIC_UART_TRANSMIT_STRING(" m3/h\r");
        send = 1;
      }
      if(check_SETTING() == 0)
      {
        uart_state = IDLE;
        set_Timer(UART_TIMER, 10);
      }
      break;
  }
}
