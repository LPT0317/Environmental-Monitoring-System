/* Includes ------------------------------------------------------------------*/
#include <p18f4620.h>

#include "p18f4620_gpio.h"

/* Variables -----------------------------------------------------------------*/
unsigned char scan_output[MAX_ROW] = {0x10,0x20};
unsigned char scan_input[MAX_COL] = {0x01,0x02,0x04,0x08};

unsigned int button_res[NO_BUTTON] = {1};

/* Function prototypes -------------------------------------------------------*/
void PIC_BUTTON_INIT(void)
{
  TRISC = TRISC & 0xcf;             //RC5 & RC4 Output
  PORTC = 0xff;
}
void PIC_SCAN_BUTTON(void)
{
  int i = 0;
  int j = 0;
  for(i = 0; i < MAX_ROW; i++)
  {
    PORTC = PORTC & ~scan_output[i];
    PORTC = PORTC | 0x0f;
    for(j = 0; j < MAX_COL; j++)
    {
        if((PORTC & scan_input[j]) == 0)
        {
            button_res[i * MAX_ROW + j] = 0;
        }
        else
        {
            button_res[i * MAX_ROW + j] = 1;
        }
    }
  }
}
int PIC_GPIO_ReadPin(int button)
{
  if(button < 0 || button >= NO_BUTTON)
    return 0;
  return button_res[button];
}