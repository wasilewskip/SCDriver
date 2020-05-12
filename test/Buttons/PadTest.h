#pragma once

#include "ButtonTest.h"
#include "Buttons/Pad.h"

class PadTest : public ButtonTest
{
    protected:
    void verifyButtonDataChangedEvent(const ButtonDataChangedEvent& eventPtr, ButtonType type, ButtonState state, const TouchPoint& touchPoint);
};