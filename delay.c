#include <reg52.h>
#include "delay.h"

void DelayMs(unsigned int ms)
{
    unsigned int i, j;
    for(i = ms; i > 0; i--)
        for(j = 110; j > 0; j--);
}