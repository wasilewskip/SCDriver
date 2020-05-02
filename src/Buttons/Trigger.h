#pragma once

#include "Button.h"
#include "ButtonType.h"

class Trigger : public Button
{
    private:
    uint16_t input;

    protected:
    virtual void processPacket(const SteamInputPacket& steamInputPacket, ButtonDataChangedEvent& event) override;
    virtual bool hasDataChanged(const ButtonDataChangedEvent& event) override;

    public:
    Trigger(ButtonType type) : Button(type), input(0) { };
};