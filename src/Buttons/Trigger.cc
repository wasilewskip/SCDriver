#include "Trigger.h"

void Trigger::processPacket(const SteamInputPacket& steamInputPacket, ButtonDataChangedEvent& event)
{
    switch(type)
    {
        case ButtonType::LEFT_TRIGGER :
            event.triggerInput = steamInputPacket.leftTrigger;
            if(steamInputPacket.leftTrigger > 0)
                event.state = ButtonState::PRESSED;
            else
                event.state = ButtonState::RELEASED;
            break;

        case ButtonType::RIGHT_TRIGGER :
            event.triggerInput = steamInputPacket.rightTrigger;
            if(steamInputPacket.rightTrigger > 0)
                event.state = ButtonState::PRESSED;
            else
                event.state = ButtonState::RELEASED;
            break;

        default:
            break;
    }
}

bool Trigger::hasDataChanged(const ButtonDataChangedEvent& event)
{
    if(input != event.triggerInput)
    {
        state = event.state;
        input = event.triggerInput;
        return true;
    }
    else
    {
        return false;
    }
}