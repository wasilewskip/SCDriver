#pragma once

#include <memory>
#include "Connection/IConnection.h"
#include "Buttons/ButtonCollection.h"

class SteamController
{
    private:
    std::unique_ptr<IConnection> connectionPtr;
    std::unique_ptr<ButtonCollection> buttons;

    public:
    SteamController(std::unique_ptr<IConnection> connection, std::unique_ptr<ButtonCollection> buttons);
    void run();
};