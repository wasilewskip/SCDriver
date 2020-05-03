#pragma once

#include "ButtonTest.h"

class TriggerTest : public ButtonTest
{
    protected:
    void verifyButtonDataChangedEvent(std::unique_ptr<ButtonDataChangedEvent> eventPtr, ButtonType type, ButtonState state, uint16_t triggerInput);
};