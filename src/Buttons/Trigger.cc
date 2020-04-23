#include "Trigger.h"

ButtonState Trigger::processPacket(const SteamInputPacket& steamInputPacket)
{
    switch(type)
    {
        case ButtonType::LEFT_TRIGGER :
            if(steamInputPacket.leftTrigger > 0)
                return ButtonState::PRESSED;
            else
                return ButtonState::RELEASED;
            break;

        case ButtonType::RIGHT_TRIGGER :
            if(steamInputPacket.rightTrigger > 0)
                return ButtonState::PRESSED;
            else
                return ButtonState::RELEASED;
            break;

        default:
            break;
    }
}