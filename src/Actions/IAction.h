#pragma once

#include "ActionCommandEvent.h"
#include "Buttons/ButtonDataChangedEvent.h"

class IAction
{
    public:
    virtual ActionCommandEvent processButtonEvent(ButtonDataChangedEvent buttonEvent) = 0;
};