#pragma once

#include <vector>
#include "IButton.h"

class ButtonCollection
{
    std::vector<std::unique_ptr<IButton>> buttons;

    public:
    ButtonCollection();

    std::vector<std::unique_ptr<ButtonDataChangedEvent>> update(const SteamInputPacket& packet);
};