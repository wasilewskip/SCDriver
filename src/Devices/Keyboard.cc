#include "Keyboard.h"

void Keyboard::triggerAction(const ButtonDataChangedEvent& event)
{
    if(event.state == ButtonState::PRESSED)
    {
        keyboardApi->pressKey(keyType);
    }
    else if(event.state == ButtonState::RELEASED)
    {
        keyboardApi->releaseKey(keyType);
    }
}