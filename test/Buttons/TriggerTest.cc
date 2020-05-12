#include "TriggerTest.h"

void TriggerTest::verifyButtonDataChangedEvent(const ButtonDataChangedEvent& event, ButtonType type, ButtonState state, uint16_t triggerInput)
{
    EXPECT_EQ(event.type, type);
    EXPECT_EQ(event.state, state);
    EXPECT_EQ(event.triggerInput, triggerInput);
    EXPECT_EQ(event.touchPoint, TouchPoint{});
}

// Button left trigger
TEST_F(TriggerTest, PressButtonLeftTriggerExpectEvent)
{
    auto buttonType = ButtonType::LEFT_TRIGGER;
    testButtonPtr = std::make_unique<Trigger>(buttonType);

    constexpr auto FULLY_PRESSED_TRIGGER = 255;
    auto packet = builder
                    .pressLeftTrigger(FULLY_PRESSED_TRIGGER)
                    .build();

    auto event = testButtonPtr->updateState(packet);

    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED, FULLY_PRESSED_TRIGGER);
}

TEST_F(TriggerTest, EmptyPacketButtonLeftTriggerExpectNoEvent)
{
    testButtonPtr = std::make_unique<Trigger>(ButtonType::LEFT_TRIGGER);

    auto packet = builder
                    .build();

    auto event = testButtonPtr->updateState(packet);

    ASSERT_EQ(event, std::nullopt);
}

// Button right trigger
TEST_F(TriggerTest, PressButtonRightTriggerExpectEvent)
{
    auto buttonType = ButtonType::RIGHT_TRIGGER;
    testButtonPtr = std::make_unique<Trigger>(buttonType);

    constexpr auto FULLY_PRESSED_TRIGGER = 255;
    auto packet = builder
                    .pressRightTrigger(FULLY_PRESSED_TRIGGER)
                    .build();

    auto event = testButtonPtr->updateState(packet);

    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED, FULLY_PRESSED_TRIGGER);
}

TEST_F(TriggerTest, EmptyPacketButtonRightTriggerExpectNoEvent)
{
    testButtonPtr = std::make_unique<Trigger>(ButtonType::RIGHT_TRIGGER);

    auto packet = builder
                    .build();

    auto event = testButtonPtr->updateState(packet);

    ASSERT_EQ(event, std::nullopt);
}

TEST_F(TriggerTest, PressAndReleaseTriggerExpectTwoEvents)
{
    constexpr auto buttonType = ButtonType::LEFT_TRIGGER;
    testButtonPtr = std::make_unique<Trigger>(buttonType);

    constexpr auto HALF_PRESSED_TRIGGER = 127;
    auto packet = builder
                    .pressLeftTrigger(HALF_PRESSED_TRIGGER)
                    .build();

    auto event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED, HALF_PRESSED_TRIGGER);

    builder.reset();
    packet = builder
                .build();

    event = testButtonPtr->updateState(packet);
    ButtonTest::verifyButtonDataChangedEvent(*event, buttonType, ButtonState::RELEASED);
}

TEST_F(TriggerTest, PressTriggerTwiceDifferentValuesExpectTwoEvents)
{
    constexpr auto buttonType = ButtonType::RIGHT_TRIGGER;
    testButtonPtr = std::make_unique<Trigger>(buttonType);

    constexpr auto FULLY_PRESSED_TRIGGER = 255;
    constexpr auto HALF_PRESSED_TRIGGER = 127;

    auto packet = builder
                    .pressRightTrigger(FULLY_PRESSED_TRIGGER)
                    .build();

    auto event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED, FULLY_PRESSED_TRIGGER);

    packet = builder
                .pressRightTrigger(HALF_PRESSED_TRIGGER)
                .build();

    event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED, HALF_PRESSED_TRIGGER);
}

TEST_F(TriggerTest, PressTriggerTwiceSameValuesExpectOneEvent)
{
    constexpr auto buttonType = ButtonType::RIGHT_TRIGGER;
    testButtonPtr = std::make_unique<Trigger>(buttonType);

    constexpr auto HALF_PRESSED_TRIGGER = 127;

    auto packet = builder
                    .pressRightTrigger(HALF_PRESSED_TRIGGER)
                    .build();

    auto event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED, HALF_PRESSED_TRIGGER);

    packet = builder
                .pressRightTrigger(HALF_PRESSED_TRIGGER)
                .build();

    event = testButtonPtr->updateState(packet);
    ASSERT_EQ(event, std::nullopt);
}