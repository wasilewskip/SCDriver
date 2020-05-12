#pragma once

#include "ActionCommandEvent.h"
#include "Buttons/ButtonDataChangedEvent.h"
#include <memory>

class IAction
{
    public:
    virtual ActionCommandEvent processButtonEvent(std::unique_ptr<ButtonDataChangedEvent> buttonEvent) = 0;
};