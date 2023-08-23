#include <Arduino.h>
#include <SPI.h>
#include "Display.h"

// MAX7219 Registers
#define DECODE_MODE 9
#define INTENSITY 10
#define SCAN_LIMIT 11
#define SHUTDOWN 12
#define DISPLAY_TEST 15


Display::Display(int cs_pin)
{
  CS_Pin = cs_pin;
  maxRows = 8;  // TODO: No hard coding
  maxColumns = 8;
}

void Display::init()
{
  pinMode(CS_Pin, OUTPUT);
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE1);
  SPI.begin();
  sendData(DECODE_MODE, 0x00); // disable BCD code
  sendData(INTENSITY, 0x07);   // set default display intensity
  sendData(SCAN_LIMIT, 0x07);  // scan all 8 pixel
  sendData(SHUTDOWN, 0x01);    // disable shutdown mode
  clear();
}

void Display::updateDisplay() {
  for(int i = 1; i<9; ++i) sendData(i, binaryrows[i-1]);
}

void Display::sendData(uint8_t address, uint8_t value) {
  digitalWrite(CS_Pin, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS_Pin, HIGH);
}

void Display::clear() {
  for(int i = 0; i<8; ++i) binaryrows[i] = 0b00000000;
  updateDisplay();
}

bool Display::changeVal(int x, int y) {
  byte mask = 0b10000000;
  if(!(0 < y < maxRows+1 && 0 < x < maxColumns+1)) return false;
  binaryrows[y-1] ^= (mask >> (x-1)); // shift mask to x position and xor it with binary row on y position
  updateDisplay();
  return true;
}