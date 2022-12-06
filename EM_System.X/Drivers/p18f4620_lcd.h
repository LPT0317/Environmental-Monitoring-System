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
#include <stdio.h>
  
/* Defines PORT --------------------------------------------------------------*/
#define RS PORTBbits.RB2
#define EN PORTBbits.RB3
#define LCD_PORT PORTB
#define LCD_DDR TRISB
  
/* Function prototypes -------------------------------------------------------*/
void LCD_Command(unsigned char cmd);
void LCD_INIT(void);
void LCD_Print_String_x_y(unsigned char row, unsigned char pos, const rom unsigned char *data);
void LCD_Print_Char(unsigned int row, unsigned int col, unsigned char data);
void LCD_Print_String(unsigned int row, unsigned int col, const rom unsigned char *data);
void LCD_Print_Num(unsigned int row, unsigned int col, long number);
void LCD_Print_Float(unsigned int row, unsigned int col, long number);
void LCD_Switch_Line(unsigned row_clear);
void LCD_Clear_Buffer(unsigned int row, unsigned int col);
void LCD_Clear_Line(unsigned int row);
void LCD_Clear_Buffer_All(void);
void LCD_Clear();
void LCD_Dislay(void);

#ifdef	__cplusplus
}
#endif

#endif	/* P18F4620_LCD_H */

