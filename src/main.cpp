#include <Arduino.h>
#include <SPI.h>
#include <Display.h>

#define CS_PIN 5
const int buttons[] = {17,16,4,2};
int buttonstate[4];
Display d = Display(CS_PIN);

void setup(void) {
  for(int i = 0; i<4; ++i) pinMode(buttons[i], INPUT_PULLUP);
  d.init();
}

void loop(void) {
  for(int i = 0; i<4; ++i) buttonstate[i] = digitalRead(buttons[i]);
  if(buttonstate[0] != 1){
    d.changeVal(1,1);
  }else if(buttonstate[1] != 1){
    d.changeVal(3,3);
  }
}
