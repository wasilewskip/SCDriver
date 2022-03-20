#pragma once

#include <memory>
#include "Connection/IConnection.h"
#include "Buttons/ButtonCollection.h"
#include "Actions/ActionListener.h"

class SteamController
{
    private:
    std::unique_ptr<IConnection> connectionPtr;
    std::unique_ptr<ButtonCollection> buttons;
    std::unique_ptr<ActionListener> actionListener;
    
    public:
    SteamController(std::unique_ptr<IConnection> connection, std::unique_ptr<ButtonCollection> buttons, std::unique_ptr<ActionListener> actionListener);
    void run();
};