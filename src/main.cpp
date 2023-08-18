#include <Arduino.h>
#include <SPI.h>

#define CS_PIN 5

// MAX7219 Registers
#define DECODE_MODE 9
#define INTENSITY 10
#define SCAN_LIMIT 11
#define SHUTDOWN 12
#define DISPLAY_TEST 16



void SendData(uint8_t address, uint8_t value);

void setup(void) {
  pinMode(CS_PIN, OUTPUT);
  SPI.setBitOrder(MSBFIRST);
  SPI.begin();

  SendData(DISPLAY_TEST, 0x01);
  delay(1000);
  SendData(DISPLAY_TEST, 0x00);
  SendData(DECODE_MODE, 0x00);
  SendData(INTENSITY, 0x02);
  SendData(SCAN_LIMIT, 0x0f);
  SendData(SHUTDOWN, 0x01);
}

void loop(void) {
  SendData(1, B00100000);
  delay(10000);
  SendData(3, B00000001);
  delay(100000);
  
}

void SendData(uint8_t address, uint8_t value) {
  digitalWrite(CS_PIN, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(CS_PIN, HIGH);
}