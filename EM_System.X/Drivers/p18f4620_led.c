/* Includes ------------------------------------------------------------------*/
#include "p18f4620_led.h"

/* Function prototypes -------------------------------------------------------*/
void PIC_LED_INIT(void)
{
  TRISE = 0x00;
  PORTE = 0x00;
}
void PIC_LED_ON(unsigned int color)
{
  if(color == GREEN)
  {
    PIC_LED_OFF();
    PORTEbits.RE0 = 1;
  }
  if(color == RED)
  {
    PIC_LED_OFF();
    PORTEbits.RE1 = 1;
  }
  if(color == BLUE)
  {
    PIC_LED_OFF();
    PORTEbits.RE2 = 1;
  }
}
void PIC_LED_OFF(void)
{
  PORTE = 0x00;
}


