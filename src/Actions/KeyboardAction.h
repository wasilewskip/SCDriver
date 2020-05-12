#pragma once

#include "IAction.h"

class KeyboardAction : public IAction
{

    public:
    virtual ActionCommandEvent processButtonEvent(const ButtonDataChangedEvent& buttonEvent) override;
};