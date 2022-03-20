#pragma once

#include <unordered_map>
#include <vector>
#include <memory>
#include "IAction.h"
#include "Buttons/ButtonDataChangedEvent.h"
#include "Devices/IDeviceFactory.h"

class ActionListener
{
    std::unordered_map<ButtonType, std::unique_ptr<IAction>> actionMap;
    std::unique_ptr<IDeviceFactory> deviceFactory;

    public:
    ActionListener(std::unique_ptr<IDeviceFactory> deviceFactory);

    void processButtonEvents(const std::vector<ButtonDataChangedEvent>& buttonEvents);

    void registerAction();
    void deregisterAction();
};