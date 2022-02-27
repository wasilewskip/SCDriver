#pragma once

#include "Buttons/ButtonDataChangedEvent.h"
#include "ActionType.h"

class IAction
{
    public:
    virtual ActionType getType() = 0;
    virtual void processButtonEvent(const ButtonDataChangedEvent& buttonEvent) = 0;
};