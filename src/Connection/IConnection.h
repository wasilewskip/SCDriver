#pragma once

#include <memory>
#include "SteamInputPacket.h"

class IConnection
{
    public:
    virtual SteamInputPacket read() = 0;
    virtual void write() = 0;  
};