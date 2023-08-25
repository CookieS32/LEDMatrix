#include "Button.h"
#include <Arduino.h>

Button::Button(const int pin, const bool pullupResistor = true, const bool activeHigh = true){
    _outPin = pin;
    if(pullupResistor) pinMode(pin, INPUT_PULLUP); else pinMode(pin, INPUT);
    _activeHigh = activeHigh;
    prevButtonState = !_activeHigh;
}

void Button::attachClickFunc(callbackFunction newFunction){
    Click = newFunction;
}

void Button::tick(){
    buttonState = digitalRead(_outPin);
    if(buttonState == _activeHigh && prevButtonState == !_activeHigh){
        if(Click != NULL) Click();
        prevButtonState = _activeHigh;
    }else if(buttonState == !_activeHigh && prevButtonState == _activeHigh){
        prevButtonState = !_activeHigh;
    }
}