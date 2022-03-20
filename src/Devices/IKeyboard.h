#pragma once

#include "Device.h"
#include "KeyboardKeyType.h"

class IKeyboard : public Device
{
    public:
    virtual void pressKey(KeyboardKeyType key) = 0;
    virtual void releaseKey(KeyboardKeyType key) = 0;

    IKeyboard() : Device(DeviceType::KEYBOARD) { };
};