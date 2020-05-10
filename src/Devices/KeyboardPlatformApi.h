#pragma once

#include "KeyboardKeyType.h"

class KeyboardPlatformApi
{
    public:
    virtual void pressKey(const KeyboardKeyType key) = 0;
    virtual void releaseKey(const KeyboardKeyType key) = 0;
};