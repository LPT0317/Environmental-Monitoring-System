/* Includes ------------------------------------------------------------------*/
#include <p18f4620.h>

#include "p18f4620_gpio.h"

/* Variables -----------------------------------------------------------------*/
unsigned char scan_output[4] = {0x10, 0x20, 0x80};
unsigned char scan_input[4] = {0x01, 0x02, 0x08};

unsigned int button_res[NO_BUTTON] = {0};

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
    PORTC = PORTC | 0x30;
    PORTC = PORTC & ~scan_output[i];
    PORTC = PORTC | 0x0f;
    for(j = 0; j < MAX_COL; j++)
    {
        if((PORTC & scan_input[j]) == 0)
        {
            button_res[i * 3 + j] = 1;
        }
        else
        {
            button_res[i * 3 + j] = 0;
        }
    }
  }
}
unsigned int PIC_GPIO_ReadPin(unsigned int button)
{
  if(button < 0 || button >= NO_BUTTON)
    return 0;
  return button_res[button];
}