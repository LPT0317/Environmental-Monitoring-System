/* Includes ------------------------------------------------------------------*/
#include "buzzer.h"

/* Defines -------------------------------------------------------------------*/
#define INIT 0
#define BUZZER_ON 1
#define BUZZER_OFF 2

/* Variables -----------------------------------------------------------------*/
unsigned int buzzer_state = INIT;
unsigned int blink_time = 50;

/* Function prototypes -------------------------------------------------------*/
void buzzer_blink(void)
{
  switch(buzzer_state)
  {
    case INIT:
      PIC_PWM_SET(0);
      buzzer_state = BUZZER_ON;
      set_Timer(BUZZER_TIMER, blink_time);
      break;
    case BUZZER_ON:
      PIC_PWM_SET(50);
      if(is_Timer_Out(BUZZER_TIMER) == 1)
      {
        buzzer_state = BUZZER_OFF;
        set_Timer(BUZZER_TIMER, blink_time);
      }
      break;
    case BUZZER_OFF:
      PIC_PWM_SET(0);
      if(is_Timer_Out(BUZZER_TIMER) == 1)
      {
        buzzer_state = BUZZER_ON;
        set_Timer(BUZZER_TIMER, blink_time);
      }
      break;
  }
}
void buzzer_off(void)
{
  PIC_PWM_SET(0);
}