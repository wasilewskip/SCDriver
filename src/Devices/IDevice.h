#pragma once

#include "DeviceType.h"

class IDevice
{
    public:
    virtual DeviceType getType() = 0;
};