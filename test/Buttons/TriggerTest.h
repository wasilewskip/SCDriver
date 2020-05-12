#pragma once

#include "ButtonTest.h"

class TriggerTest : public ButtonTest
{
    protected:
    void verifyButtonDataChangedEvent(const ButtonDataChangedEvent& eventPtr, ButtonType type, ButtonState state, uint16_t triggerInput);
};