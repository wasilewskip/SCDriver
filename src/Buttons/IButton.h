#pragma once

#include "Connection/SteamInputPacket.h"
#include "ButtonDataChangedEvent.h"
#include <memory>
#include <optional>

class IButton
{
    public:
    virtual std::optional<ButtonDataChangedEvent> updateState(const SteamInputPacket& steamInputPacket) = 0;
};