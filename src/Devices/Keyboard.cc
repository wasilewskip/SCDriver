#include "Keyboard.h"

void Keyboard::triggerAction(const ActionCommandEvent& actionCommand)
{
    switch (actionCommand.actionType)
    {
    case ActionType::PRESS :
        keyboardApi->pressKey(actionCommand.keyboardKeyType);
        break;
    
    case ActionType::RELEASE :
        keyboardApi->releaseKey(actionCommand.keyboardKeyType);
        break;

    case ActionType::PRESS_AND_RELEASE :
        keyboardApi->pressKey(actionCommand.keyboardKeyType);
        keyboardApi->releaseKey(actionCommand.keyboardKeyType);
        break;
        
    default:
        break;
    }
}