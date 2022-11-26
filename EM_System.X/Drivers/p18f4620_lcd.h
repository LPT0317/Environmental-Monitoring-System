/* 
 * File:   p18f4620_lcd.h
 * Author: lephu
 *
 * Created on November 26, 2022, 12:19 PM
 */

#ifndef P18F4620_LCD_H
#define	P18F4620_LCD_H

#ifdef	__cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <p18f4620.h>
  
/* Defines PORT --------------------------------------------------------------*/
#define RS PORTBbits.RB2
#define EN PORTBbits.RB3
#define LCD_PORT PORTB
#define LCD_DDR TRISB
  
/* Function prototypes -------------------------------------------------------*/
void LCD_Command(unsigned char cmd);
void LCD_INIT(void);
void LCD_Print_String_x_y(char row, char pos, unsigned char *data);
void LCD_Clear();


#ifdef	__cplusplus
}
#endif

#endif	/* P18F4620_LCD_H */

