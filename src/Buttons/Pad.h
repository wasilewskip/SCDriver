#pragma once

#include "Button.h"
#include "ButtonType.h"
#include "TouchPoint.h"
#include <vector>


class Pad : public Button
{
    private:
    std::vector<TouchPoint> touchPath;

    ButtonState processLeftPad(const SteamInputPacket& steamInputPacket);
    ButtonState processRightPad(const SteamInputPacket& steamInputPacket);
    ButtonState processJoystick(const SteamInputPacket& steamInputPacket);

    ButtonState checkPadState(short touchedIndex, short pressedIndex, const SteamInputPacket& steamInputPacket);
    void getPadData(const ButtonState newState, const SteamInputPacket& steamInputPacket);
    void getTouchPoint(const SteamInputPacket& steamInputPacket);

    bool isPadUsed(const ButtonState newState);
    bool isPadReleased(const ButtonState newState);
    bool isJoystickUsed(const SteamInputPacket& steamInputPacket);
    bool isJoystickReleased(const SteamInputPacket& steamInputPacket);

    protected:
    virtual ButtonState processPacket(const SteamInputPacket& steamInputPacket);

    public:
    Pad(ButtonType type) : Button(type) { };
};