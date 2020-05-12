#include "Keyboard.h"

void Keyboard::triggerAction(const ActionCommandEvent& actionCommand)
{
    switch (actionCommand.actionResultType)
    {
    case ActionResultType::PRESS :
        keyboardApi->pressKey(actionCommand.keyboardKeyType);
        break;
    
    case ActionResultType::RELEASE :
        keyboardApi->releaseKey(actionCommand.keyboardKeyType);
        break;

    case ActionResultType::PRESS_AND_RELEASE :
        keyboardApi->pressKey(actionCommand.keyboardKeyType);
        keyboardApi->releaseKey(actionCommand.keyboardKeyType);
        break;
        
    default:
        break;
    }
}