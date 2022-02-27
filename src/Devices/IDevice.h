#pragma once

#include "DeviceType.h"
#include "Buttons/ButtonDataChangedEvent.h"

class IDevice
{
    public:
    virtual void triggerAction(const ButtonDataChangedEvent& event) = 0;
    virtual DeviceType getType() = 0;
};