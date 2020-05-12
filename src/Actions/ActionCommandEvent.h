#pragma once
#include "Devices/DeviceType.h"
#include "Actions/ActionResultType.h"
#include "Devices/KeyboardKeyType.h"

class ActionCommandEvent
{
    public:
    DeviceType deviceType;
    ActionResultType actionResultType;
    KeyboardKeyType keyboardKeyType;
};