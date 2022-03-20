#pragma once

#include "IKeyboard.h"
#include <memory>

class IDeviceFactory {

    public:
    virtual std::unique_ptr<IKeyboard> createKeyboard() = 0;
};