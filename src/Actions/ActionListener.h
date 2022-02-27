#pragma once

#include <unordered_map>
#include <vector>
#include <memory>
#include "IAction.h"
#include "Buttons/ButtonDataChangedEvent.h"

class ActionListener
{
    std::unordered_map<ButtonType, std::unique_ptr<IAction>> actionMap;

    public:
    ActionListener();

    void processButtonEvents(const std::vector<ButtonDataChangedEvent>& buttonEvents);

    void registerAction();
    void deregisterAction();
};