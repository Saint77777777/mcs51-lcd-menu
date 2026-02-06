#ifndef __EEPROM_H__
#define __EEPROM_H__

unsigned char EEPROM_ReadByte(unsigned char addr);
void EEPROM_WriteByte(unsigned char addr, unsigned char dat);

#endif
