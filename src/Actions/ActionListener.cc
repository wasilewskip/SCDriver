#include "ActionListener.h"
#include "KeyboardAction.h"

ActionListener::ActionListener(std::unique_ptr<IDeviceFactory> deviceFactory)
{
    deviceFactory = std::move(deviceFactory);
    std::unique_ptr<IKeyboard> keyboard = deviceFactory->createKeyboard();
    actionMap[ButtonType::Y] = std::make_unique<KeyboardAction>(std::move(keyboard));
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