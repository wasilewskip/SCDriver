#pragma once
#include "Devices/DeviceType.h"
#include "Actions/ActionType.h"
#include "Devices/KeyboardKeyType.h"

class ActionCommandEvent
{
    public:
    DeviceType deviceType;
    ActionType actionType;
    KeyboardKeyType keyboardKeyType;
};