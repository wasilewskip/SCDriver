#include "KeyboardAction.h"

void KeyboardAction::processButtonEvent(const ButtonDataChangedEvent& buttonEvent)
{
    const auto key = KeyboardKeyType::A;
    if(buttonEvent.state == ButtonState::PRESSED)
    {
        keyboard->pressKey(key);
    }
    else if(buttonEvent.state == ButtonState::RELEASED)
    {
        keyboard->releaseKey(key);
    }
}