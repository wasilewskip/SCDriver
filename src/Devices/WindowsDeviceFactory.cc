#include "WindowsDeviceFactory.h"
#include "Keyboard.h"
#include "KeyboardPlatformApi.h"
#include "KeyboardWindowsApi.h"
#include "WindowsApiWrapper.h"

std::unique_ptr<IKeyboard> WindowsDeviceFactory::createKeyboard()
{
    std::unique_ptr<WindowsApiWrapper> windowsKeyboardApiWrapper = std::make_unique<WindowsApiWrapper>();
    std::unique_ptr<KeyboardPlatformApi> keyboardApi = std::make_unique<KeyboardWindowsApi>(std::move(windowsKeyboardApiWrapper));
    std::unique_ptr<IKeyboard> device = std::make_unique<Keyboard>(std::move(keyboardApi));
    return std::move(device);
}