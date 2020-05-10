#include "KeyboardAction.h"

ActionCommandEvent KeyboardAction::processButtonEvent(ButtonDataChangedEvent buttonEvent)
{
    ActionCommandEvent actionEvent;
    actionEvent.deviceType = DeviceType::KEYBOARD;

    if(buttonEvent.state == ButtonState::PRESSED)
    {
        actionEvent.actionType = ActionType::PRESS;
    }
    else if(buttonEvent.state == ButtonState::RELEASED)
    {
        actionEvent.actionType = ActionType::RELEASE;
    }
    
    actionEvent.keyboardKeyType = KeyboardKeyType::A;
    return actionEvent;
}