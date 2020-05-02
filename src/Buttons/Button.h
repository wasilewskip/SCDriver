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
    virtual void processPacket(const SteamInputPacket& steamInputPacket, ButtonDataChangedEvent& event);
    virtual bool hasDataChanged(const ButtonDataChangedEvent& event);

    public:
    Button(ButtonType type);
    virtual std::unique_ptr<ButtonDataChangedEvent> updateState(const SteamInputPacket& steamInputPacket) override;
};