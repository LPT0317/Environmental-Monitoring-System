#include "communication.h"

#define NONE 0
#define SET 1

#define WAIT 0
#define END 1
#define WAIT_END 2
#define WAIT_S 3
#define WAIT_E 4
#define WAIT_T 5

char data = ' ';
int command = NONE;
int command_state = WAIT;

void uart_communication(void)
{
  data = RCREG;
  PIC_UART_TRANSMIT_CHAR(data);
  switch(command_state)
  {
    case WAIT:
      command = NONE;
      if(data == '!')
        command_state = WAIT_S;
      break;
    case WAIT_S:
      if(data == 'S')
        command_state = WAIT_E;
      break;
    case WAIT_E:
      if(data == 'E')
        command_state = WAIT_T;
      break;
    case WAIT_T:
      if(data == 'T')
        command_state = WAIT_END;
      break;
    case WAIT_END:
      if(data == '#')
        command_state = END;
      break;
    case END:
      LCD_Print_Char(0, 0, 'T');
      command_state = WAIT;
      break;
  }
}

