#pragma once

#include "Action.h"
#include "Devices/IKeyboard.h"
#include <memory>

class KeyboardAction : public Action
{
    std::unique_ptr<IKeyboard> keyboard;

    public:
    KeyboardAction(std::unique_ptr<IKeyboard> keyboard) : Action(ActionType::KEYBOARD_ACTION), keyboard(std::move(keyboard))  { };
    virtual void processButtonEvent(const ButtonDataChangedEvent& buttonEvent) override;
};