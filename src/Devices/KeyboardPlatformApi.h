#pragma once

class KeyboardPlatformApi
{
    public:
    virtual void pressKey() = 0;
    virtual void releaseKey() = 0;
};