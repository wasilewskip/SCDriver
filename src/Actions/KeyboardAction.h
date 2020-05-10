#pragma once

#include "IAction.h"

class KeyboardAction : public IAction
{

    public:
    virtual ActionCommandEvent processButtonEvent(ButtonDataChangedEvent buttonEvent) override;
};