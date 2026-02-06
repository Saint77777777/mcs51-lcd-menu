#include <reg52.h>

void Timer0_Init(void)
{
    TMOD |= 0x01;
    TH0 = (65536 - 10000) / 256;
    TL0 = (65536 - 10000) % 256;
    ET0 = 1;
    EA  = 1;
    TR0 = 1;
}

void Timer0_ISR(void) interrupt 1
{
    TH0 = (65536 - 10000) / 256;
    TL0 = (65536 - 10000) % 256;
}
