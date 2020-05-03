#include "TriggerTest.h"

void TriggerTest::verifyButtonDataChangedEvent(std::unique_ptr<ButtonDataChangedEvent> eventPtr, ButtonType type, ButtonState state, uint16_t triggerInput)
{
    ASSERT_NE(eventPtr, nullptr);
    EXPECT_EQ(eventPtr->type, type);
    EXPECT_EQ(eventPtr->state, state);
    EXPECT_EQ(eventPtr->triggerInput, triggerInput);
    EXPECT_EQ(eventPtr->touchPoint, TouchPoint{});
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

    auto eventPtr = testButtonPtr->updateState(packet);

    verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, ButtonState::PRESSED, FULLY_PRESSED_TRIGGER);
}

TEST_F(TriggerTest, EmptyPacketButtonLeftTriggerExpectNoEvent)
{
    testButtonPtr = std::make_unique<Trigger>(ButtonType::LEFT_TRIGGER);

    auto packet = builder
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    ASSERT_EQ(eventPtr, nullptr);
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

    auto eventPtr = testButtonPtr->updateState(packet);

    verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, ButtonState::PRESSED, FULLY_PRESSED_TRIGGER);
}

TEST_F(TriggerTest, EmptyPacketButtonRightTriggerExpectNoEvent)
{
    testButtonPtr = std::make_unique<Trigger>(ButtonType::RIGHT_TRIGGER);

    auto packet = builder
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    ASSERT_EQ(eventPtr, nullptr);
}

TEST_F(TriggerTest, PressAndReleaseTriggerExpectTwoEvents)
{
    constexpr auto buttonType = ButtonType::LEFT_TRIGGER;
    testButtonPtr = std::make_unique<Trigger>(buttonType);

    constexpr auto HALF_PRESSED_TRIGGER = 127;
    auto packet = builder
                    .pressLeftTrigger(HALF_PRESSED_TRIGGER)
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, ButtonState::PRESSED, HALF_PRESSED_TRIGGER);

    builder.reset();
    packet = builder
                .build();

    eventPtr = testButtonPtr->updateState(packet);
    ButtonTest::verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, ButtonState::RELEASED);
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

    auto eventPtr = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, ButtonState::PRESSED, FULLY_PRESSED_TRIGGER);

    packet = builder
                .pressRightTrigger(HALF_PRESSED_TRIGGER)
                .build();

    eventPtr = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, ButtonState::PRESSED, HALF_PRESSED_TRIGGER);
}

TEST_F(TriggerTest, PressTriggerTwiceSameValuesExpectOneEvent)
{
    constexpr auto buttonType = ButtonType::RIGHT_TRIGGER;
    testButtonPtr = std::make_unique<Trigger>(buttonType);

    constexpr auto HALF_PRESSED_TRIGGER = 127;

    auto packet = builder
                    .pressRightTrigger(HALF_PRESSED_TRIGGER)
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, ButtonState::PRESSED, HALF_PRESSED_TRIGGER);

    packet = builder
                .pressRightTrigger(HALF_PRESSED_TRIGGER)
                .build();

    eventPtr = testButtonPtr->updateState(packet);
    ASSERT_EQ(eventPtr, nullptr);
}