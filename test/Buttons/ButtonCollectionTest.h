#pragma once

#include <gtest/gtest.h>
#include <memory>
#include "SteamInputPacketBuilder.h"
#include "Buttons/ButtonCollection.h"
#include <tuple>

class ButtonCollectionTest : public ::testing::Test
{
    protected:
    SteamInputPacketBuilder builder;
    std::unique_ptr<ButtonCollection> buttonCollectionPtr;

    virtual void SetUp() override;
    virtual void TearDown() override;
    
    auto findEvent(const std::vector<ButtonDataChangedEvent>& events, ButtonType buttonType);
    void verifyEventByType(const std::vector<ButtonDataChangedEvent>& events, ButtonType buttonType, ButtonState state, TouchPoint touchPoint);
};