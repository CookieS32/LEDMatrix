#include <Arduino.h>

int ButtonInputs[] = {17,16,4,5}, ButtonStates[4];


void setup() {
  for(int i = 0; i<4; ++i)
    pinMode(ButtonInputs[i], INPUT_PULLUP);
  Serial.begin(9600);
  
}

void loop() {
  for(int i = 0; i < 4; ++i)
    ButtonStates[i] = digitalRead(ButtonInputs[i]);
  
  for(int i = 0; i < 4; ++i)
    Serial.printf("Button %d: %d\n", i, ButtonStates[i]);
  delay(500);
}
