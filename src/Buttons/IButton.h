#pragma once

#include "Connection/SteamInputPacket.h"
#include "ButtonDataChangedEvent.h"
#include <memory>

class IButton
{
    public:
    virtual std::unique_ptr<ButtonDataChangedEvent> updateState(const SteamInputPacket& steamInputPacket) = 0;
};