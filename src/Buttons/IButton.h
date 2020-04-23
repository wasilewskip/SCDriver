#pragma once

#include "../Connection/SteamInputPacket.h"
#include <memory>

class IButton
{
    public:
    virtual void updateState(const SteamInputPacket& steamInputPacket) = 0;
};