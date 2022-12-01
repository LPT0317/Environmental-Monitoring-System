/* Includes ------------------------------------------------------------------*/
#include "p18f4620_uart.h"

/* Variables -----------------------------------------------------------------*/
char data_receive = ' ';

/* Function prototypes -------------------------------------------------------*/
void PIC_UART_INIT(void)
{
  SPBRGH = 0;
  SPBRG = 129;
  TXSTAbits.TXEN = 1;     //Transmit enabled
  TXSTAbits.BRGH = 0;     //Low Speed
  BAUDCONbits.BRG16 = 1;  //16-bit Baud Rate Generator

  TXSTAbits.SYNC = 0;     //Asynchronous mode
  RCSTAbits.SPEN = 1;     //Enables
  RCSTAbits.CREN = 1;     //Enables receive

  PIR1bits.RCIF = 0;      // clear interrupt flag uart
  PIE1bits.RCIE = 1;      //enable interrupt uart
  IPR1bits.RCIP = 0;      // Priority: low
  TRISCbits.RC6 = 0;      // RC6 output
  TRISCbits.RC7 = 1;      // RC7 input
}
char PIC_UART_RECEIVE(void)
{
  return data_receive;
}
void PIC_UART_TRANSMIT_CHAR(char data)
{
  //while(PIR1bits.TXIF == 0);
  PIR1bits.TXIF = 1;
  TXREG = data;
  PIR1bits.TXIF = 0;
}
void PIC_UART_TRANSMIT_STRING(const rom char *data)
{
  while(*data)
  {
    PIC_UART_TRANSMIT_CHAR(*data);
    *data++;
  }
}
void PIC_UART_ISR(void)
{
  data_receive = RCREG;
}
