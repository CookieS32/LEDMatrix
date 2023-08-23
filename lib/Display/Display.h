#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>

class Display
{
private:
  int CS_Pin, maxRows, maxColumns;
  byte binaryrows[8];
  void sendData(uint8_t address, uint8_t value);
  void updateDisplay();
public:
  Display(int cs_pin);
  void init();
  void clear();
  bool changeVal(int x, int y);
};

#endif