#pragma once

#include "IDevice.h"

class Device : public IDevice
{
    protected:
    DeviceType type;
    Device(DeviceType type) : type(type) { };

    public:
    Device() = delete;
    virtual DeviceType getType() final override { return type; };
};