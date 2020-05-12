#pragma once

#include "ActionCommandEvent.h"
#include "Buttons/ButtonDataChangedEvent.h"
#include <memory>

class IAction
{
    public:
    virtual ActionCommandEvent processButtonEvent(const ButtonDataChangedEvent& buttonEvent) = 0;
};