#include "Button.h"
#include <iostream>

Button::Button(ButtonType type)
{
    this->type = type;
    this->state = ButtonState::RELEASED;
}

std::unique_ptr<ButtonDataChangedEvent> Button::updateState(const SteamInputPacket& steamInputPacket)
{
    ButtonDataChangedEvent event{type, state};

    processPacket(steamInputPacket, event);
    
    if(hasDataChanged(event))
    {
        printButtonState();
        return std::make_unique<ButtonDataChangedEvent>(event);
    }
    else
    {
        return nullptr;
    }
}

void Button::processPacket(const SteamInputPacket& steamInputPacket, ButtonDataChangedEvent& event)
{
    event.state = static_cast<ButtonState>(steamInputPacket.buttons[static_cast<uint8_t>(type)]);
}

bool Button::hasDataChanged(const ButtonDataChangedEvent& event)
{
    if (state != event.state)
    {
        state = event.state;
        return true;
    }
    else
    {
        return false;
    }
}

void Button::printButtonState()
{
    switch (state)
    {
    case ButtonState::RELEASED :
        std::cout << getTypeString() << " released\n";
        break;
    
    case ButtonState::PRESSED :
        std::cout << getTypeString() << " pressed\n";
        break;

    case ButtonState::TOUCHED :
        std::cout << getTypeString() << " touched\n";
        break;

    default:
        std::cout << getTypeString() << "Unknown state!\n";
        break;
    }
}

std::string Button::getTypeString()
{
    switch (type)
    {
    case ButtonType::X :
        return "X";
        break;

    case ButtonType::Y :
        return "Y";
        break;

    case ButtonType::B :
        return "B";
        break;

    case ButtonType::A :
        return "A";
        break;

    case ButtonType::JOYSTICK :
        return "Joystick";
        break;

    case ButtonType::LEFT_PAD :
        return "Left pad";
        break;

    case ButtonType::RIGHT_PAD :
        return "Right pad";
        break;

    case ButtonType::SELECT :
        return "Select";
        break;

    case ButtonType::STEAM :
        return "Steam";
        break;

    case ButtonType::START :
        return "Start";
        break;

    case ButtonType::LEFT_BUMPER :
        return "Left bumper";
        break;

    case ButtonType::RIGHT_BUMPER :
        return "Right bumper";
        break;

    case ButtonType::LEFT_TRIGGER :
        return "Left trigger";
        break;

    case ButtonType::RIGHT_TRIGGER :
        return "Right trigger";
        break;

    case ButtonType::LEFT_GRIP :
        return "Left grip";
        break;

    case ButtonType::RIGHT_GRIP :
        return "Right grip";
        break;
    
    default:
        return "Unknown button!";
        break;
    }
}