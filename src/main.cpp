#include <Arduino.h>
#include <SPI.h>
#include <MD_MAX72xx.h>
#include <MD_Parola.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DECIVES 1
#define CS_PIN 5


MD_Parola myDispaly = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DECIVES);

void setup() {
  myDispaly.begin();
  myDispaly.displayClear();
  Serial.begin(9600);
  
}

void loop() {
  myDispaly.print("S");
  delay(1000);
  myDispaly.print("V");
  delay(1000);
  myDispaly.print("E");
  delay(1000);
  myDispaly.print("N");
  delay(1000);
}
