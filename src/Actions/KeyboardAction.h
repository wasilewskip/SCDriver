#pragma once

#include "IAction.h"

class KeyboardAction : public IAction
{

    public:
    virtual ActionCommandEvent processButtonEvent(std::unique_ptr<ButtonDataChangedEvent> buttonEvent) override;
};