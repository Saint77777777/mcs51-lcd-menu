#ifndef __LCD_H__
#define __LCD_H__

void LCD_Init(void);
void LCD_Clear(void);
void LCD_ShowChar(unsigned char pos, unsigned char ch);
void LCD_ShowString(unsigned char pos, char *str);

#endif
