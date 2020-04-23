#pragma once

#include <vector>
#include "IButton.h"
#include "../Connection/SteamInputPacket.h"

class ButtonCollection
{
    std::vector<std::unique_ptr<IButton>> buttons;

    public:
    ButtonCollection();

    void update(const SteamInputPacket& packet);
};