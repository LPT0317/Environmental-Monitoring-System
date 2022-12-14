/* Includes ------------------------------------------------------------------*/
#include "uart.h"

/* State Machine -------------------------------------------------------------*/
#define INIT 0
#define IDLE 1
#define SEND_VALUE 2
#define SEND_ALERT 3
int uart_state = INIT;

/* Function prototypes -------------------------------------------------------*/
void UART_DATA(void)
{
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
  }
}
