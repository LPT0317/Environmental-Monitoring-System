/* Includes ------------------------------------------------------------------*/
#include "p18f4620_adc.h"

/* Function prototypes -------------------------------------------------------*/
void PIC_PWM_INIT(void)
{
  T2CONbits.TMR2ON = 0;   //turn off timer2
  T2CONbits.T2CKPS0 = 0;
  T2CONbits.T2CKPS1 = 1;  //prescaler 1:16

  PR2 = 255;              //PWM period
  CCP1CONbits.DC1B0 = 0;  //PWM duty cycle
  CCP1CONbits.DC1B1 = 0;  //2 bits LSB
  CCPR1L = 0x00;          //8bits MSB

  CCP1CONbits.P1M0 = 0;   //PWM single mode
  CCP1CONbits.P1M1 = 0;
  CCP1CONbits.CCP1M0 = 0; //select PWM function
  CCP1CONbits.CCP1M1 = 0;
  CCP1CONbits.CCP1M2 = 1;
  CCP1CONbits.CCP1M3 = 1;

  TRISCbits.RC2 = 0;      //config RC2 output
  T2CONbits.TMR2ON = 1;   //start timer2
}
void PIC_PWM_SET(unsigned char value)
{
  CCPR1L = value;
}
