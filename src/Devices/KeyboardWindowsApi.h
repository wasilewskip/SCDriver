#pragma once

#include "KeyboardPlatformApi.h"
#include "KeyboardKeyType.h"
#include "WindowsApiWrapper.h"
#include <memory>

class KeyboardWindowsApi : public KeyboardPlatformApi
{
    private:
    std::unique_ptr<WindowsApiWrapper> apiWrapper;

    INPUT buildInputStruct(bool isKeyReleased, KeyboardKeyType key);
    WORD mapInternalKeyToScanCode(KeyboardKeyType key);

    public:
    KeyboardWindowsApi(std::unique_ptr<WindowsApiWrapper> apiWrapper) : apiWrapper(std::move(apiWrapper)) { };
    virtual void pressKey(const KeyboardKeyType key) override;
    virtual void releaseKey(const KeyboardKeyType key) override;
};