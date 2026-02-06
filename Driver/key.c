#include <reg52.h>
#include "delay.h"

/* === ???? === */
sbit KEY1 = P3^1;
sbit KEY2 = P3^0;
sbit KEY3 = P3^2;

unsigned char GetKey(void)
{
    if(KEY1 == 0)
    {
        DelayMs(10);
        if(KEY1 == 0)
            return 1;
    }

    if(KEY2 == 0)
    {
        DelayMs(10);
        if(KEY2 == 0)
            return 2;
    }

    if(KEY3 == 0)
    {
        DelayMs(10);
        if(KEY3 == 0)
            return 3;
    }

    return 0;
}
