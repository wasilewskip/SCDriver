#pragma once

#include "IButton.h"
#include "ButtonType.h"
#include <string>

class Button : public IButton
{
    private:
    void printButtonState();
    std::string getTypeString();

    protected:
    ButtonType type;
    ButtonState state;
    virtual ButtonState processPacket(const SteamInputPacket& steamInputPacket);

    public:
    Button(ButtonType type);
    virtual void updateState(const SteamInputPacket& steamInputPacket);
};