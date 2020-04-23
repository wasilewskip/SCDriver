#pragma once

#include "Button.h"
#include "ButtonType.h"

class Trigger : public Button
{
    protected:
    virtual ButtonState processPacket(const SteamInputPacket& steamInputPacket);

    public:
    Trigger(ButtonType type) : Button(type) { };
};