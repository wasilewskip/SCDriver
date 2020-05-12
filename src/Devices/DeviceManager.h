#pragma once

#include <vector>
#include <unordered_map>
#include <memory>
#include "Actions/ActionCommandEvent.h"
#include "IDevice.h"

class DeviceManager
{
    private:
    std::unordered_map<DeviceType, std::unique_ptr<IDevice>> deviceMap;

    public:
    DeviceManager();
    void processActionCommands(std::vector<ActionCommandEvent> actionCommands);

    void registerDevice(DeviceType deviceType);
    void deregisterDevice(DeviceType deviceType);
};