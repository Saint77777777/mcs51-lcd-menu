#include <reg52.h>
#include "delay.h"
#include <intrins.h>


/* STC89 IAP EEPROM ??? */
sfr IAP_DATA  = 0xC2;
sfr IAP_ADDRH = 0xC3;
sfr IAP_ADDRL = 0xC4;
sfr IAP_CMD   = 0xC5;
sfr IAP_TRIG  = 0xC6;
sfr IAP_CONTR = 0xC7;

#define ENABLE_IAP 0x80

void IAP_Idle(void)
{
    IAP_CONTR = 0;
    IAP_CMD = 0;
    IAP_TRIG = 0;
    IAP_ADDRH = 0;
    IAP_ADDRL = 0;
}

unsigned char EEPROM_ReadByte(unsigned char addr)
{
    unsigned char dat;

    IAP_CONTR = ENABLE_IAP;
    IAP_CMD = 1;              // ???
    IAP_ADDRL = addr;
    IAP_ADDRH = 0;
    IAP_TRIG = 0x5A;
    IAP_TRIG = 0xA5;
    _nop_();
    dat = IAP_DATA;
    IAP_Idle();

    return dat;
}

void EEPROM_WriteByte(unsigned char addr, unsigned char dat)
{
    IAP_CONTR = ENABLE_IAP;
    IAP_CMD = 2;              // ???
    IAP_ADDRL = addr;
    IAP_ADDRH = 0;
    IAP_DATA = dat;
    IAP_TRIG = 0x5A;
    IAP_TRIG = 0xA5;
    _nop_();
    IAP_Idle();

    DelayMs(10);              // ????
}
