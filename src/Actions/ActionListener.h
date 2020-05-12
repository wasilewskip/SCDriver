#pragma once

#include <unordered_map>
#include <vector>
#include <memory>
#include "IAction.h"
#include "ActionType.h"
#include "Buttons/ButtonDataChangedEvent.h"

class ActionListener
{
    std::unordered_map<ActionType, std::unique_ptr<IAction>> actionMap;

    public:
    ActionListener();

    std::vector<ActionCommandEvent> processButtonEvents(std::vector<std::unique_ptr<ButtonDataChangedEvent>> buttonEvents);

    void registerAction();
    void deregisterAction();
};