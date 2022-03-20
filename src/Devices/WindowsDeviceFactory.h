#pragma once

#include "IDeviceFactory.h"

class WindowsDeviceFactory : public IDeviceFactory
{
    public:
    virtual std::unique_ptr<IKeyboard> createKeyboard() override;
};