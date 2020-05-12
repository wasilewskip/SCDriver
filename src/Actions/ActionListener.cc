#include "ActionListener.h"
#include "KeyboardAction.h"

ActionListener::ActionListener()
{
    // TODO: remove it later. Temporary solution just for tests
    std::unique_ptr<IAction> action = std::make_unique<KeyboardAction>();
    actionMap.insert(std::make_pair(ActionType::KEYBOARD, std::move(action)));
}

std::vector<ActionCommandEvent> ActionListener::processButtonEvents(std::vector<std::unique_ptr<ButtonDataChangedEvent>> buttonEvents)
{
    std::vector<ActionCommandEvent> actions;

    for(auto& buttonEvent : buttonEvents)
    {
        // TODO: find proper action based on config (each button should have defined action type)
        if(buttonEvent != nullptr)
        {
            auto action = actionMap[ActionType::KEYBOARD]->processButtonEvent(std::move(buttonEvent));
            actions.emplace_back(action);
        }
    }
    return actions;
}
