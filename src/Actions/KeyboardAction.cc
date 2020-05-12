#include "KeyboardAction.h"

ActionCommandEvent KeyboardAction::processButtonEvent(const ButtonDataChangedEvent& buttonEvent)
{
    ActionCommandEvent actionEvent;
    actionEvent.deviceType = DeviceType::KEYBOARD;

    if(buttonEvent.state == ButtonState::PRESSED)
    {
        actionEvent.actionResultType = ActionResultType::PRESS;
    }
    else if(buttonEvent.state == ButtonState::RELEASED)
    {
        actionEvent.actionResultType = ActionResultType::RELEASE;
    }
    
    actionEvent.keyboardKeyType = KeyboardKeyType::A;
    return actionEvent;
}