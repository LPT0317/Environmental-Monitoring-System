/* Includes ------------------------------------------------------------------*/
#include "timer_software.h"

/* Variables -----------------------------------------------------------------*/
unsigned int flag[NO_TIMER] = {0};
unsigned int counter[NO_TIMER] = {0};

/* Function prototypes -------------------------------------------------------*/
// Timer Run
void timer_Run(void)
{
  int i = 0;
  for(i = 0; i < NO_TIMER; i++)
  {
    if(counter[i] > 0)
    {
      counter[i]--;
      if(counter[i] <= 0)
      {
            counter[i] = 0;
            flag[i] = 1;
      }
    }
  }
}

//Set timer
int set_Timer(unsigned timer, unsigned int duration)
{
  if(timer < 0 || timer >= NO_TIMER)
    return 0;
  counter[timer] = duration / TIME_CYCLE;
  flag[timer] = 0;
  return 1;
}
//check Timer flag
int is_Timer_Out(unsigned timer)
{
  if(timer < 0 || timer >= NO_TIMER)
    return 0;
  if(flag[timer] == 1) {
    flag[timer] = 0;
    return 1;
  }
  return 0;
}