#pragma once

#include "DeviceType.h"
#include "Actions/ActionCommandEvent.h"

class IDevice
{
    public:
    virtual void triggerAction(const ActionCommandEvent& actionCommand) = 0;
    virtual DeviceType getType() = 0;
};