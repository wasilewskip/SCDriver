#pragma once

#include "ButtonType.h"
#include "ButtonState.h"
#include "TouchPoint.h"
#include <vector>

class ButtonDataChangedEvent
{
    public:
    ButtonType type;
    ButtonState state;
    uint16_t triggerInput;
    TouchPoint touchPoint;

    ButtonDataChangedEvent(ButtonType type, ButtonState state) : type(type), state(state), triggerInput(0), touchPoint{} { };
};