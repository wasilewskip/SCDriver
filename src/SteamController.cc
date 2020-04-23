#include "SteamController.h"

SteamController::SteamController(std::unique_ptr<IConnection> connection, std::unique_ptr<ButtonCollection> buttons) 
    : connectionPtr(std::move(connection)), buttons(std::move(buttons)) 
{ }

void SteamController::run()
{
    while (true)
    {
        const auto& packet = connectionPtr->read();
        buttons->update(packet);
    }
    
}