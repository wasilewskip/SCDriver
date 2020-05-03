#pragma once

#include <gtest/gtest.h>
#include <memory>
#include "SteamInputPacketBuilder.h"
#include "Buttons/ButtonCollection.h"
#include <tuple>

using EventsVector = std::vector<std::unique_ptr<ButtonDataChangedEvent>>;

class ButtonCollectionTest : public ::testing::Test
{
    protected:
    SteamInputPacketBuilder builder;
    std::unique_ptr<ButtonCollection> buttonCollectionPtr;

    virtual void SetUp() override;
    virtual void TearDown() override;
    
    void removeNullptrEvents(EventsVector& events);
    auto findEvent(const EventsVector& events, ButtonType buttonType);
    void verifyEventByType(const EventsVector& events, ButtonType buttonType, ButtonState state, TouchPoint touchPoint);
};