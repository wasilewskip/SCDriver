#include "DeviceManager.h"
#include "Keyboard.h"
#include "KeyboardPlatformApi.h"
#include "KeyboardWindowsApi.h"
#include "WindowsApiWrapper.h"

DeviceManager::DeviceManager()
{
    // TODO: remove it. Temp soltion for tests
    std::unique_ptr<WindowsApiWrapper> windowsApiWrapper = std::make_unique<WindowsApiWrapper>();
    std::unique_ptr<KeyboardPlatformApi> keyboardApi = std::make_unique<KeyboardWindowsApi>(std::move(windowsApiWrapper));
    std::unique_ptr<IDevice> keyboard = std::make_unique<Keyboard>(std::move(keyboardApi));
    deviceMap.insert(std::make_pair(DeviceType::KEYBOARD, std::move(keyboard)));
}

void DeviceManager::processActionCommands(std::vector<ActionCommandEvent> actionCommands)
{
    for(auto& actionCommand : actionCommands)
    {
        deviceMap[actionCommand.deviceType]->triggerAction(actionCommand);
    }
}