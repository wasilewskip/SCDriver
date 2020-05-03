#pragma once

#include <gtest/gtest.h>
#include <memory>
#include "SteamInputPacketBuilder.h"
#include "Buttons/IButton.h"
#include "Buttons/Button.h"
#include "Buttons/Trigger.h"


class ButtonTest : public ::testing::Test {

    protected:
    SteamInputPacketBuilder builder;
    std::unique_ptr<IButton> testButtonPtr;

    virtual void TearDown() override;

    void verifyButtonDataChangedEvent(std::unique_ptr<ButtonDataChangedEvent> eventPtr, ButtonType type, ButtonState state);
    void testEmptyPacket(const ButtonType buttonType);
    void testButtonPress(const ButtonType buttonType);
};