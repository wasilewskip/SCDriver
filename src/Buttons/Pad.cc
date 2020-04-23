#include "Pad.h"
#include <iostream>

ButtonState Pad::processPacket(const SteamInputPacket& steamInputPacket)
{
    ButtonState newState = state;

    switch (type)
    {
    case ButtonType::LEFT_PAD :
        newState = processLeftPad(steamInputPacket);
        break;
    
    case ButtonType::RIGHT_PAD :
        newState = processRightPad(steamInputPacket);
        break;

    case ButtonType::JOYSTICK :
        newState = processJoystick(steamInputPacket);
        break;

    default:
        break;
    }

    getPadData(newState, steamInputPacket);

    return newState;
}

ButtonState Pad::checkPadState(short touchedIndex, short pressedIndex, const SteamInputPacket& steamInputPacket)
{
    if(steamInputPacket.buttons[touchedIndex] && steamInputPacket.buttons[pressedIndex])
    {
        return ButtonState::PRESSED;
    }
    else if(steamInputPacket.buttons[touchedIndex])
    {
        return ButtonState::TOUCHED;
    }
    else
    {
        return ButtonState::RELEASED;
    }
    
}

void Pad::getPadData(const ButtonState newState, const SteamInputPacket& steamInputPacket)
{
    if(isPadUsed(newState) || isJoystickUsed(steamInputPacket))
    {
        getTouchPoint(steamInputPacket);
    }
    else if(isPadReleased(newState) || isJoystickReleased(steamInputPacket))
    {
        std::cout << "Size of touchPath: " << touchPath.size() << "\n";
        touchPath.clear();
    } 
}

bool Pad::isPadUsed(const ButtonState newState)
{
    if(newState == ButtonState::TOUCHED || newState == ButtonState::PRESSED)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Pad::isPadReleased(const ButtonState newState)
{
    if(((state == ButtonState::TOUCHED || state == ButtonState::PRESSED) && newState == ButtonState::RELEASED))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Pad::isJoystickUsed(const SteamInputPacket& steamInputPacket)
{
    if((steamInputPacket.lpadX != 0 || steamInputPacket.lpadY != 0) && type == ButtonType::JOYSTICK)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Pad::isJoystickReleased(const SteamInputPacket& steamInputPacket)
{
    if(!touchPath.empty() && (steamInputPacket.lpadX == 0 || steamInputPacket.lpadY == 0) && type == ButtonType::JOYSTICK)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Pad::getTouchPoint(const SteamInputPacket& steamInputPacket)
{
    switch (type)
    {
    case ButtonType::LEFT_PAD :
    case ButtonType::JOYSTICK :
        touchPath.emplace_back(steamInputPacket.lpadX, steamInputPacket.lpadY);
        break;

    case ButtonType::RIGHT_PAD :
        touchPath.emplace_back(steamInputPacket.rpadX, steamInputPacket.rpadY);
        break;
    
    default:
        break;
    }
}

ButtonState Pad::processLeftPad(const SteamInputPacket& steamInputPacket)
{
    constexpr short TOUCHED_INDEX = 3;
    constexpr short PRESSED_INDEX = 1;

    return checkPadState(TOUCHED_INDEX, PRESSED_INDEX, steamInputPacket);
}

ButtonState Pad::processRightPad(const SteamInputPacket& steamInputPacket)
{
    constexpr short TOUCHED_INDEX = 4;
    constexpr short PRESSED_INDEX = 2;

    return checkPadState(TOUCHED_INDEX, PRESSED_INDEX, steamInputPacket);
}

ButtonState Pad::processJoystick(const SteamInputPacket& steamInputPacket)
{
    constexpr short TOUCHED_INDEX = 6;
    constexpr short PRESSED_INDEX = 1;

    return checkPadState(TOUCHED_INDEX, PRESSED_INDEX, steamInputPacket);
}