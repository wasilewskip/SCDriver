#include "KeyboardAction.h"

void KeyboardAction::processButtonEvent(const ButtonDataChangedEvent& buttonEvent)
{
    device->triggerAction(buttonEvent);
}