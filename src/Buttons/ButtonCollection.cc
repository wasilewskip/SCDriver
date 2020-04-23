#include "ButtonCollection.h"
#include "Button.h"
#include "ButtonType.h"
#include "Trigger.h"
#include "Pad.h"

ButtonCollection::ButtonCollection()
{
    buttons.push_back(std::make_unique<Button>(ButtonType::A));
    buttons.push_back(std::make_unique<Button>(ButtonType::B));
    buttons.push_back(std::make_unique<Button>(ButtonType::X));
    buttons.push_back(std::make_unique<Button>(ButtonType::Y));
    buttons.push_back(std::make_unique<Button>(ButtonType::SELECT));
    buttons.push_back(std::make_unique<Button>(ButtonType::STEAM));
    buttons.push_back(std::make_unique<Button>(ButtonType::START));
    buttons.push_back(std::make_unique<Button>(ButtonType::LEFT_BUMPER));
    buttons.push_back(std::make_unique<Button>(ButtonType::RIGHT_BUMPER));
    buttons.push_back(std::make_unique<Button>(ButtonType::LEFT_GRIP));
    buttons.push_back(std::make_unique<Button>(ButtonType::RIGHT_GRIP));
    buttons.push_back(std::make_unique<Trigger>(ButtonType::LEFT_TRIGGER));
    buttons.push_back(std::make_unique<Trigger>(ButtonType::RIGHT_TRIGGER));
    buttons.push_back(std::make_unique<Pad>(ButtonType::LEFT_PAD));
    buttons.push_back(std::make_unique<Pad>(ButtonType::RIGHT_PAD));
    buttons.push_back(std::make_unique<Pad>(ButtonType::JOYSTICK));
}

void ButtonCollection::update(const SteamInputPacket& packet)
{
    for(auto& button : buttons)
    {
        button->updateState(packet);
    }
}