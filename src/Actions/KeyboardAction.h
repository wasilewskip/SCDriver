#pragma once

#include "Action.h"
#include "Devices/IDevice.h"
#include <memory>

class KeyboardAction : public Action
{
    std::unique_ptr<IDevice> device;

    public:
    KeyboardAction(std::unique_ptr<IDevice> device) : Action(ActionType::KEYBOARD_ACTION), device(std::move(device))  { };
    virtual void processButtonEvent(const ButtonDataChangedEvent& buttonEvent) override;
};