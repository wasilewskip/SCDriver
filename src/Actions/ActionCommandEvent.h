#pragma once
#include "Devices/DeviceType.h"
#include "Actions/ActionType.h"

class ActionCommandEvent
{
    public:
    DeviceType deviceType;
    ActionType actionType;
};