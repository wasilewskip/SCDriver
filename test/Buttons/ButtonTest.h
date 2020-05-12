#pragma once

#include <gtest/gtest.h>
#include <memory>
#include <optional>
#include "SteamInputPacketBuilder.h"
#include "Buttons/IButton.h"
#include "Buttons/Button.h"
#include "Buttons/Trigger.h"


class ButtonTest : public ::testing::Test {

    protected:
    SteamInputPacketBuilder builder;
    std::unique_ptr<IButton> testButtonPtr;

    virtual void TearDown() override;

    void verifyButtonDataChangedEvent(const ButtonDataChangedEvent& event, ButtonType type, ButtonState state);
    void testEmptyPacket(const ButtonType buttonType);
    void testButtonPress(const ButtonType buttonType);
};