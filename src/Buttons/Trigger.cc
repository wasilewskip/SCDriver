#include "Trigger.h"

ButtonState Trigger::processPacket(const SteamInputPacket& steamInputPacket)
{
    switch(type)
    {
        case ButtonType::LEFT_TRIGGER :
            if(steamInputPacket.leftTrigger > 0)
            {
                input = steamInputPacket.leftTrigger;
                return ButtonState::PRESSED;
            }
            else
            {
                input = 0;
                return ButtonState::RELEASED;
            }
            break;

        case ButtonType::RIGHT_TRIGGER :
            if(steamInputPacket.rightTrigger > 0)
            {
                input = steamInputPacket.rightTrigger;
                return ButtonState::PRESSED;
            }
            else
            {
                input = 0;
                return ButtonState::RELEASED;
            }
            break;

        default:
            break;
    }
}