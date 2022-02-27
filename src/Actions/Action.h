#pragma once

#include "IAction.h"

class Action : public IAction
{
    protected:
    ActionType actionType;
    Action(ActionType actionType) : actionType(actionType) { };

    public:
    Action() = delete;
    virtual ActionType getType() final override { return actionType; };
};