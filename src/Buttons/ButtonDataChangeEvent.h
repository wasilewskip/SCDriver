#pragma once

#include "ButtonType.h"
#include "TouchPoint.h"
#include <vector>

class ButtonDataChangeEvent
{
    public:
    ButtonType type;
    ButtonState state;
    short triggerInput;
    std::vector<TouchPoint>* touchPath;

    ButtonDataChangeEvent(ButtonType type, ButtonState state);
    ButtonDataChangeEvent(ButtonType type, ButtonState state, short triggerInput);
    ButtonDataChangeEvent(ButtonType type, ButtonState state, std::vector<TouchPoint>& touchPath);
};