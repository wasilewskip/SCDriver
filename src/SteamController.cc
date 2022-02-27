#include "SteamController.h"
#include <iostream>

SteamController::SteamController(std::unique_ptr<IConnection> connection, std::unique_ptr<ButtonCollection> buttons, ActionListener actionListener) 
    : connectionPtr(std::move(connection)), buttons(std::move(buttons)), actionListener(std::move(actionListener))
{ }

void SteamController::run()
{
    while (true)
    {
        const auto& packet = connectionPtr->read();
        auto buttonEvents = buttons->update(packet);
        actionListener.processButtonEvents(buttonEvents);
    }
}