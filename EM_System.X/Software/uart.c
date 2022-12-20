/* Includes ------------------------------------------------------------------*/
#include "uart.h"
#include "calib.h"

/* State Machine -------------------------------------------------------------*/
#define INIT 0
#define IDLE 1
#define SEND_VALUE 2
#define SEND_ALERT 3
#define SEND_THRESHOLD 4
#define SEND_CMAX 5
#define SEND_CMIN 6
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
      if(is_Timer_Out(UART_TIMER) == 1)
      {
        uart_state = SEND_VALUE;
      }
      else if(Error_flag == 1)
      {
        uart_state = SEND_ALERT;
        set_Timer(UART_TIMER, 1000);
      }
      else if(check_Setting() == 1)
      {
        uart_state = SEND_THRESHOLD;
        send = 0;
      }
      else if(check_Setting() == 2) {
        uart_state = SEND_CMAX;
        send = 0;
      }
      else if (check_Setting() == 3) {
        uart_state = SEND_CMIN;
        send = 0;
      }
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
      PIC_UART_TRANSMIT_STRING(" m3/h \r\n");
      set_Timer(UART_TIMER, 1000);
      uart_state = IDLE;
      break;
    case SEND_ALERT:
      index = 0;
      if(is_Timer_Out(UART_TIMER) == 1)
      {
        PIC_UART_TRANSMIT_STRING("SENSOR ALERT!!!\r");
        PIC_UART_TRANSMIT_STRING("Over threshold!!!\r");
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
      }
      if(Error_flag == 0)
      {
        uart_state = IDLE;
        set_Timer(UART_TIMER, 10);
      }
      break;
    case SEND_THRESHOLD:
      if(send == 0)
      {
        PIC_UART_TRANSMIT_STRING("pH= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(pH_Sensor));
        PIC_UART_TRANSMIT_STRING(" pH SS= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(SS_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l CSB= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(COD_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l TMP= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(TEMP_Sensor));
        PIC_UART_TRANSMIT_STRING(" C NH4= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(NH4_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l NO3= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(NO3_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l FLOW= ");
        PIC_UART_TRANSMIT_FLOAT(Sensor_Get_Threshold(FLOW_Sensor));
        PIC_UART_TRANSMIT_STRING(" m3/h \r\n");
        uart_state = SEND_THRESHOLD;
      }
      if(check_Setting() != 1)
      {
        uart_state = IDLE;
      }
      break;
    case SEND_CMAX:
      if(send == 0)
      {
        PIC_UART_TRANSMIT_STRING("pH= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MAX, pH_Sensor));
        PIC_UART_TRANSMIT_STRING(" pH SS= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MAX, SS_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l CSB= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MAX, COD_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l TMP= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MAX, TEMP_Sensor));
        PIC_UART_TRANSMIT_STRING(" C NH4= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MAX, NH4_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l NO3= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MAX, NO3_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l FLOW= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MAX, FLOW_Sensor));
        PIC_UART_TRANSMIT_STRING(" m3/h \r\n");
        uart_state = SEND_CMAX;
      }
      if(check_Setting() != 2)
      {
        uart_state = IDLE;
      }
      break;
    case SEND_CMIN:
      if(send == 0)
      {
        PIC_UART_TRANSMIT_STRING("pH= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MIN, pH_Sensor));
        PIC_UART_TRANSMIT_STRING(" pH SS= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MIN, SS_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l CSB= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MIN, COD_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l TMP= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MIN, TEMP_Sensor));
        PIC_UART_TRANSMIT_STRING(" C NH4= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MIN, NH4_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l NO3= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MIN, NO3_Sensor));
        PIC_UART_TRANSMIT_STRING(" mg/l FLOW= ");
        PIC_UART_TRANSMIT_FLOAT(get_calib(CALIB_MIN, FLOW_Sensor));
        PIC_UART_TRANSMIT_STRING(" m3/h \r\n");
        uart_state = SEND_CMIN;
      }
      if(check_Setting() != 3)
      {
        uart_state = IDLE;
      }
      break;
  }
}
