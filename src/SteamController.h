#pragma once

#include <memory>
#include "Connection/IConnection.h"
#include "Buttons/ButtonCollection.h"
#include "Actions/ActionListener.h"
#include "Devices/DeviceManager.h"

class SteamController
{
    private:
    std::unique_ptr<IConnection> connectionPtr;
    std::unique_ptr<ButtonCollection> buttons;
    ActionListener actionListener;
    DeviceManager deviceManager;

    public:
    SteamController(std::unique_ptr<IConnection> connection, std::unique_ptr<ButtonCollection> buttons, ActionListener actionListener);
    void run();
};