#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

typedef void (*callbackFunction)(void);

class Button
{
private:
    callbackFunction Click = NULL;
    int _outPin;
    bool _activeHigh, buttonState, prevButtonState;

public:
    Button(const int pin, const bool pullupResistor, const bool activeHigh);
    void attachClickFunc(callbackFunction myFunction);
    void tick();
};

#endif