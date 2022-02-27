#include "ActionListener.h"
#include "KeyboardAction.h"
#include "Devices/Keyboard.h"
#include "Devices/KeyboardPlatformApi.h"
#include "Devices/KeyboardWindowsApi.h"
#include "Devices/WindowsApiWrapper.h"

ActionListener::ActionListener()
{
    std::unique_ptr<WindowsApiWrapper> windowsKeyboardApiWrapper = std::make_unique<WindowsApiWrapper>();
    std::unique_ptr<KeyboardPlatformApi> keyboardApi = std::make_unique<KeyboardWindowsApi>(std::move(windowsKeyboardApiWrapper));
    std::unique_ptr<IDevice> device = std::make_unique<Keyboard>(std::move(keyboardApi), KeyboardKeyType::A);
    actionMap[ButtonType::Y] = std::make_unique<KeyboardAction>(std::move(device));
}

void ActionListener::processButtonEvents(const std::vector<ButtonDataChangedEvent>& buttonEvents)
{
    for(const auto& buttonEvent : buttonEvents)
    {
        if(actionMap.count(buttonEvent.type))
        {
            actionMap[buttonEvent.type]->processButtonEvent(buttonEvent);
        }
    }
}
