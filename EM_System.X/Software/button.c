/* Includes ------------------------------------------------------------------*/
#include "button.h"

/* Defines -------------------------------------------------------------------*/
#define NORMAL 0
#define PRESSED 1

/* Variables -----------------------------------------------------------------*/
unsigned int button_flag[6] = {0, 0, 0, 0, 0, 0};
unsigned int button_reg0[6] = {0, 0, 0, 0, 0, 0};
unsigned int button_reg1[6] = {0, 0, 0, 0, 0, 0};
unsigned int button_reg2[6] = {0, 0, 0, 0, 0, 0};
unsigned int button_reg3[6] = {0, 0, 0, 0, 0, 0};
unsigned int time_out[6] = {200, 200, 200, 200, 200, 200};

/* Function prototypes -------------------------------------------------------*/
void button_Input(void)
{
  int i = 0;
  for(i = 0; i < NO_BUTTON; i++)
  {
    button_reg2[i] = button_reg1[i];
    button_reg1[i] = button_reg0[i];
    button_reg0[i] = PIC_GPIO_ReadPin(i);
    if((button_reg0[i] == button_reg1[i]) && (button_reg1[i] == button_reg2[i]))
    {
      if(button_reg3[i] != button_reg2[i])
      {
        button_reg3[i] = button_reg2[i];
        if(button_reg3[i] == PRESSED)
        {
          time_out[i] = 200;
          button_flag[i] = 1;
        }
      }
      else
      {
        time_out[i]--;
        if(time_out[i] == 0)
        {
          if(button_reg3[i] == PRESSED)
          {
            time_out[i] = 50;
            button_flag[i] = 1;
          }
        }
      }
    }
  }
}
unsigned int button_Pressed(unsigned int button_name)
{
  if(button_name < 0 || button_name > 6)
    return 0;
  if(button_flag[button_name] == 1)
  {
    button_flag[button_name] = 0;
    return 1;
  }
  return 0;
}