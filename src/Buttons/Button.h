#pragma once

#include "IButton.h"
#include "ButtonType.h"
#include "ButtonState.h"
#include <string>

class Button : public IButton
{
    private:
    void printButtonState();
    std::string getTypeString();

    protected:
    ButtonType type;
    ButtonState state;
    virtual void processPacket(const SteamInputPacket& steamInputPacket, ButtonDataChangedEvent& event);
    virtual bool hasDataChanged(const ButtonDataChangedEvent& event);

    public:
    Button(ButtonType type);
    virtual std::optional<ButtonDataChangedEvent> updateState(const SteamInputPacket& steamInputPacket) override;
};