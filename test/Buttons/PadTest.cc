#include "PadTest.h"

void PadTest::verifyButtonDataChangedEvent(std::unique_ptr<ButtonDataChangedEvent> eventPtr, ButtonType type, ButtonState state, const TouchPoint& touchPoint)
{
    ASSERT_NE(eventPtr, nullptr);
    EXPECT_EQ(eventPtr->type, type);
    EXPECT_EQ(eventPtr->state, state);
    EXPECT_EQ(eventPtr->triggerInput, 0);
    EXPECT_EQ(eventPtr->touchPoint, touchPoint);
}

// Button left pad
TEST_F(PadTest, TouchLeftPadExpectEvent)
{
    constexpr auto buttonType = ButtonType::LEFT_PAD;
    testButtonPtr = std::make_unique<Pad>(buttonType);

    auto packet = builder
                    .touchLeftPad()
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    ButtonTest::verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, ButtonState::TOUCHED);
}

TEST_F(PadTest, PressLeftPadExpectEvent)
{
    constexpr auto buttonType = ButtonType::LEFT_PAD;
    testButtonPtr = std::make_unique<Pad>(buttonType);

    auto packet = builder
                    .pressLeftPad()
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    ButtonTest::verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, ButtonState::PRESSED);
}

TEST_F(PadTest, EmptyPacketLeftPadExpectNoEvent)
{
    testButtonPtr = std::make_unique<Pad>(ButtonType::LEFT_PAD);

    auto packet = builder
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    ASSERT_EQ(eventPtr, nullptr);
}

TEST_F(PadTest, MoveLeftPadExepctEvent)
{
    constexpr auto buttonType = ButtonType::LEFT_PAD;
    constexpr auto buttonState = ButtonState::TOUCHED;

    testButtonPtr = std::make_unique<Pad>(buttonType);

    constexpr auto X_VALUE = 32767;
    constexpr auto Y_VALUE = -23456;

    auto packet = builder
                    .moveLeftPad(X_VALUE, Y_VALUE)
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, buttonState, TouchPoint{X_VALUE, Y_VALUE});
}

// Button right pad
TEST_F(PadTest, TouchRightPadExpectEvent)
{
    constexpr auto buttonType = ButtonType::RIGHT_PAD;
    testButtonPtr = std::make_unique<Pad>(buttonType);

    auto packet = builder
                    .touchRightPad()
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    ButtonTest::verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, ButtonState::TOUCHED);
}

TEST_F(PadTest, PressRightPadExpectEvent)
{
    constexpr auto buttonType = ButtonType::RIGHT_PAD;
    testButtonPtr = std::make_unique<Pad>(buttonType);

    auto packet = builder
                    .pressRightPad()
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    ButtonTest::verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, ButtonState::PRESSED);
}

TEST_F(PadTest, EmptyPacketRightPadExpectNoEvent)
{
    testButtonPtr = std::make_unique<Pad>(ButtonType::RIGHT_PAD);

    auto packet = builder
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    ASSERT_EQ(eventPtr, nullptr);
}

TEST_F(PadTest, MoveRightPadExepctEvent)
{
    constexpr auto buttonType = ButtonType::RIGHT_PAD;
    constexpr auto buttonState = ButtonState::TOUCHED;

    testButtonPtr = std::make_unique<Pad>(buttonType);

    constexpr auto X_VALUE = 32767;
    constexpr auto Y_VALUE = -23456;

    auto packet = builder
                    .moveRightPad(X_VALUE, Y_VALUE)
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, buttonState, TouchPoint{X_VALUE, Y_VALUE});
}

// Button joystick
TEST_F(PadTest, PressJoystickExpectEvent)
{
    constexpr auto buttonType = ButtonType::JOYSTICK;
    testButtonPtr = std::make_unique<Pad>(buttonType);

    auto packet = builder
                    .pressJoystick()
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    ButtonTest::verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, ButtonState::PRESSED);
}

TEST_F(PadTest, EmptyPacketJoystickExpectNoEvent)
{
    testButtonPtr = std::make_unique<Pad>(ButtonType::JOYSTICK);

    auto packet = builder
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    ASSERT_EQ(eventPtr, nullptr);
}

TEST_F(PadTest, MoveJoystickExepctEvent)
{
    constexpr auto buttonType = ButtonType::JOYSTICK;
    constexpr auto buttonState = ButtonState::RELEASED;

    testButtonPtr = std::make_unique<Pad>(buttonType);

    constexpr auto X_VALUE = 32767;
    constexpr auto Y_VALUE = -23456;

    auto packet = builder
                    .moveJoystick(X_VALUE, Y_VALUE)
                    .build();

    auto eventPtr = testButtonPtr->updateState(packet);

    verifyButtonDataChangedEvent(std::move(eventPtr), buttonType, buttonState, TouchPoint{X_VALUE, Y_VALUE});
}