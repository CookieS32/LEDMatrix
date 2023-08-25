#include <Arduino.h>
#include <SPI.h>
#include <Display.h>
#include <Button.h>

#define CS_PIN 5

Display d = Display(CS_PIN);
Button xButton = Button(17, true, false);
Button yButton = Button(16, true, false);
Button changeButton = Button(4, true, false);
Button clearButton = Button(2, true, false);

unsigned long int blinkMillis;
int xPos = 1, yPos = 1;
bool changed = false, currentState = false;

void xButtonCb(){
  if(!currentState == changed){
    d.changeVal(xPos, yPos);
    currentState = !currentState;
  }
  if(xPos == 8) xPos = 1; else ++xPos;
}

void yButtonCb(){
  if(!currentState == changed){
    d.changeVal(xPos, yPos);
    currentState = !currentState;
  }
  if(yPos == 8) yPos = 1; else ++yPos;
}

void changeButtonCb(){
  changed = !changed;
}

void clearButtonCb(){
  d.clear();
  currentState = false;
  changed = false;
}

void setup(void) {
  d.init();
  xButton.attachClickFunc(xButtonCb);
  yButton.attachClickFunc(yButtonCb);
  changeButton.attachClickFunc(changeButtonCb);
  clearButton.attachClickFunc(clearButtonCb);
  blinkMillis = millis();
}

void loop(void) {
  if((millis() - blinkMillis) > 500){
    currentState = !currentState;
    blinkMillis = millis();
    d.changeVal(xPos, yPos);
  }
  delay(10);
  xButton.tick();
  yButton.tick();
  changeButton.tick();
  clearButton.tick();
}
