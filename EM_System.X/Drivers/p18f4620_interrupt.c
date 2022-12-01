/* Includes ------------------------------------------------------------------*/
#include "p18f4620_interrupt.h"

/* Function prototypes -------------------------------------------------------*/
void PIC_INTERRUPT_INIT(void)
{
  INTCONbits.GIE = 1;       //enable global interrupt
  RCONbits.IPEN = 1;        //enable interrupt priority
  INTCONbits.PEIE = 1;      //Peripheral External Interupt Enable
}
void PIC_EXT_INIT(void)
{
  INTCON2bits.INTEDG0 = 0;  //Interrupt0 on falling edge
  INTCONbits.INT0IF = 0;    //Clear Interrupt Flag bit
  INTCONbits.INT0IE = 1;    // Enable INT0
}

#pragma code InterruptVectorLow	= 0x18
void InterruptVectorLow(void)
{
    _asm
            GOTO PIC_LOW_ISR
    _endasm
}

#pragma code InterruptVectorHigh = 0x08
void InterruptVectorHigh(void)
{
    _asm
            GOTO PIC_HIGH_ISR
    _endasm
}

#pragma code
#pragma interruptlow PIC_LOW_ISR
void PIC_LOW_ISR(void)
{
  // Timer 0
  if(INTCONbits.T0IF) 
  {
    PIC_TIM0_STOP();
    INTCONbits.T0IF = 0;
    PIC_TIM0_START();
    TIM0_CALLBACK();
  }
  
  // Timer 1
  if(PIR1bits.TMR1IF) 
  {
    PIC_TIM1_STOP();
    PIR1bits.TMR1IF = 0;
    PIC_TIM1_START();
    TIM1_CALLBACK();
  }

  // Timer 3
  if(PIR2bits.TMR3IF) 
  {
    PIC_TIM3_STOP();
    PIR2bits.TMR3IF = 0;
    PIC_TIM3_START();
    TIM3_CALLBACK();
  }

  // Ext_interupt 0
  if(INTCONbits.INT0IF) 
  {
    INTCONbits.INT0IF = 0;
    //add code here
  }
  
  // UART Interrupt Receive
  if(PIR1bits.RCIF == 1)
  {
    PIR1bits.RCIF = 0;
    PIC_UART_ISR();
  }
}

#pragma code
#pragma interrupt PIC_HIGH_ISR
void PIC_HIGH_ISR(void)
{
  // Timer 0
  if(INTCONbits.T0IF)
  {
    PIC_TIM0_STOP();
    INTCONbits.T0IF = 0;
    PIC_TIM0_START();
    TIM0_CALLBACK();
  }

  // Timer 1
  if(PIR1bits.TMR1IF)
  {
    PIC_TIM1_STOP();
    PIR1bits.TMR1IF = 0;
    PIC_TIM1_START();
    TIM1_CALLBACK();
  }

	
  // Timer 3
  if(PIR2bits.TMR3IF)
  {
    PIC_TIM3_STOP();
    PIR2bits.TMR3IF = 0;
    PIC_TIM3_START();
    TIM3_CALLBACK();
  }

  // Ext_interupt 0
  if(INTCONbits.INT0IF)
  {
    INTCONbits.INT0IF = 0;
    //add code here
  }
  
  // UART Interrupt Receive
  if(PIR1bits.RCIF == 1)
  {
    PIR1bits.RCIF = 0;
    PIC_UART_ISR();
  }
}
