#include "Pad.h"
#include <iostream>

void Pad::processPacket(const SteamInputPacket& steamInputPacket, ButtonDataChangedEvent& event)
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

    event.state = newState;
    event.touchPoint = getTouchPointFromPacket(steamInputPacket);
}

ButtonState Pad::checkPadState(uint8_t touchedIndex, uint8_t pressedIndex, const SteamInputPacket& steamInputPacket)
{
    ButtonState newState = ButtonState::RELEASED;

    if(steamInputPacket.buttons[touchedIndex] && steamInputPacket.buttons[pressedIndex])
    {
        newState = ButtonState::PRESSED;
    }
    else if(steamInputPacket.buttons[touchedIndex])
    {
        newState = ButtonState::TOUCHED;
    }
    else
    {
        newState = ButtonState::RELEASED;
    }

    return newState;
}

bool Pad::hasDataChanged(const ButtonDataChangedEvent& event)
{
    bool hasDataChanged = false;
    if(state != event.state || touchPoint != event.touchPoint)
    {
        state = event.state;
        touchPoint = event.touchPoint;
        hasDataChanged = true;
    }
    else
    {
        hasDataChanged = false;
    }
    return hasDataChanged;
}

TouchPoint Pad::getTouchPointFromPacket(const SteamInputPacket& steamInputPacket)
{
    switch (type)
    {
    case ButtonType::LEFT_PAD :
    {
        auto leftPadState = processLeftPad(steamInputPacket);
        if(leftPadState == ButtonState::TOUCHED || leftPadState == ButtonState::PRESSED)
        {
            return TouchPoint{steamInputPacket.lpadX, steamInputPacket.lpadY};
        }
        else
        {
            return TouchPoint{};
        }
        break;
    }
    case ButtonType::JOYSTICK :
    {
        ButtonState leftPadState = processLeftPad(steamInputPacket);
        if(leftPadState == ButtonState::RELEASED)
        {
            return TouchPoint{steamInputPacket.lpadX, steamInputPacket.lpadY};
        }
        else
        {
            return TouchPoint{};
        }
        break;
    }
    case ButtonType::RIGHT_PAD :
    {
        return TouchPoint{steamInputPacket.rpadX, steamInputPacket.rpadY};
        break;
    }
    default:
        return TouchPoint{};
        break;
    }
}

ButtonState Pad::processLeftPad(const SteamInputPacket& steamInputPacket)
{
    constexpr auto TOUCHED_INDEX = 3;
    constexpr auto PRESSED_INDEX = 1;

    return checkPadState(TOUCHED_INDEX, PRESSED_INDEX, steamInputPacket);
}

ButtonState Pad::processRightPad(const SteamInputPacket& steamInputPacket)
{
    constexpr auto TOUCHED_INDEX = 4;
    constexpr auto PRESSED_INDEX = 2;

    return checkPadState(TOUCHED_INDEX, PRESSED_INDEX, steamInputPacket);
}

ButtonState Pad::processJoystick(const SteamInputPacket& steamInputPacket)
{
    constexpr auto TOUCHED_INDEX = 6;
    constexpr auto PRESSED_INDEX = 1;

    return checkPadState(TOUCHED_INDEX, PRESSED_INDEX, steamInputPacket);
}