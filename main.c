#include <reg52.h>
#include "lcd.h"
#include "key.h"
#include "delay.h"

/* ========== ???? ========== */
typedef enum
{
    PAGE_MENU = 0,
    PAGE_WELCOME,
    PAGE_KEYTEST
} Page_t;

/* ========== ???? ========== */
Page_t currentPage = PAGE_MENU;
unsigned char menuIndex = 0;
unsigned char lastKey = 0;

unsigned char key = 0;
unsigned char key_last = 0;
unsigned char key_event = 0;

bit ui_need_refresh = 1;

/* ========== UI ???? ========== */
void ShowMenu(void)
{
    LCD_Clear();
    LCD_ShowString(0,  menuIndex == 0 ? ">Welcome"  : " Welcome");
    LCD_ShowString(16, menuIndex == 1 ? ">Key Test" : " Key Test");
}

void ShowWelcome(void)
{
    LCD_Clear();
    LCD_ShowString(0,  "Hello World!");
    LCD_ShowString(16, "OK Back");
}

void ShowKeyTest(unsigned char key)
{
    LCD_Clear();
    LCD_ShowString(0, "Key Pressed:");

    if(key == 1)      LCD_ShowString(16, "UP");
    else if(key == 2) LCD_ShowString(16, "DOWN");
    else if(key == 3) LCD_ShowString(16, "OK");
    else              LCD_ShowString(16, "---");
}

/* ========== ??? ========== */
void main(void)
{
    LCD_Init();
    ui_need_refresh = 1;

    while(1)
    {
        /* ---- ?????? ---- */
        key = GetKey();
        key_event = 0;

        if(key != 0 && key_last == 0)
            key_event = key;

        key_last = key;

        if(key_event != 0)
            lastKey = key_event;

        /* ---- ??? ---- */
        switch(currentPage)
        {
            case PAGE_MENU:
                if(key_event == 1 && menuIndex > 0)
                {
                    menuIndex--;
                    ui_need_refresh = 1;
                }
                else if(key_event == 2 && menuIndex < 1)
                {
                    menuIndex++;
                    ui_need_refresh = 1;
                }
                else if(key_event == 3)
                {
                    if(menuIndex == 0)
                        currentPage = PAGE_WELCOME;
                    else
                        currentPage = PAGE_KEYTEST;

                    ui_need_refresh = 1;
                }
                break;

            case PAGE_WELCOME:
                if(key_event == 3)
                {
                    currentPage = PAGE_MENU;
                    menuIndex = 0;
                    ui_need_refresh = 1;
                }
                break;

            case PAGE_KEYTEST:
                if(key_event == 3)
                {
                    currentPage = PAGE_MENU;
                    menuIndex = 0;
                    ui_need_refresh = 1;
                }
                else if(key_event != 0)
                {
                    ui_need_refresh = 1;
                }
                break;
        }

        /* ---- UI ?? ---- */
        if(ui_need_refresh)
        {
            ui_need_refresh = 0;

            if(currentPage == PAGE_MENU)
                ShowMenu();
            else if(currentPage == PAGE_WELCOME)
                ShowWelcome();
            else if(currentPage == PAGE_KEYTEST)
                ShowKeyTest(lastKey);
        }

        DelayMs(10);
    }
}
