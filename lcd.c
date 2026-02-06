#include <reg52.h>
#include "lcd.h"
#include "delay.h"

#define LCD_DATA P0

sbit RS = P2^6;
sbit RW = P2^5;
sbit EN = P2^7;

void LCD_WriteCmd(unsigned char cmd)
{
    RS = 0;
    RW = 0;
    LCD_DATA = cmd;
    EN = 1;
    DelayMs(1);
    EN = 0;
}

void LCD_WriteData(unsigned char dat)
{
    RS = 1;
    RW = 0;
    LCD_DATA = dat;
    EN = 1;
    DelayMs(1);
    EN = 0;
}

void LCD_Init(void)
{
    DelayMs(15);
    LCD_WriteCmd(0x38);
    LCD_WriteCmd(0x0C);
    LCD_WriteCmd(0x06);
    LCD_WriteCmd(0x01);
}

void LCD_Clear(void)
{
    LCD_WriteCmd(0x01);
    DelayMs(2);
}

void LCD_ShowString(unsigned char pos, char *str)
{
    LCD_WriteCmd(0x80 + pos);
    while(*str)
    {
        LCD_WriteData(*str++);
    }
}