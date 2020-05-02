#pragma once

#include "ButtonTest.h"
#include "Buttons/Pad.h"

class PadTest : public ButtonTest
{
    public:
    void verifyButtonDataChangedEvent(std::unique_ptr<ButtonDataChangedEvent> eventPtr, ButtonType type, ButtonState state, const TouchPoint& touchPoint);
};