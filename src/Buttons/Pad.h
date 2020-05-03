#pragma once

#include "Button.h"
#include "ButtonType.h"
#include "TouchPoint.h"
#include <vector>


class Pad : public Button
{
    private:
    TouchPoint touchPoint;

    ButtonState processLeftPad(const SteamInputPacket& steamInputPacket);
    ButtonState processRightPad(const SteamInputPacket& steamInputPacket);
    ButtonState processJoystick(const SteamInputPacket& steamInputPacket);

    ButtonState checkPadState(uint8_t touchedIndex, uint8_t pressedIndex, const SteamInputPacket& steamInputPacket);
    TouchPoint getTouchPointFromPacket(const SteamInputPacket& steamInputPacket);

    protected:
    virtual void processPacket(const SteamInputPacket& steamInputPacket, ButtonDataChangedEvent& event) override;
    virtual bool hasDataChanged(const ButtonDataChangedEvent& event) override;

    public:
    Pad(ButtonType type) : Button(type) { };
};