#include "PadTest.h"

void PadTest::verifyButtonDataChangedEvent(const ButtonDataChangedEvent& event, ButtonType type, ButtonState state, const TouchPoint& touchPoint)
{
    EXPECT_EQ(event.type, type);
    EXPECT_EQ(event.state, state);
    EXPECT_EQ(event.triggerInput, 0);
    EXPECT_EQ(event.touchPoint, touchPoint);
}

// Button left pad
TEST_F(PadTest, TouchLeftPadExpectEvent)
{
    constexpr auto buttonType = ButtonType::LEFT_PAD;
    testButtonPtr = std::make_unique<Pad>(buttonType);

    auto packet = builder
                    .touchLeftPad()
                    .build();

    auto event = testButtonPtr->updateState(packet);

    ButtonTest::verifyButtonDataChangedEvent(*event, buttonType, ButtonState::TOUCHED);
}

TEST_F(PadTest, PressLeftPadExpectEvent)
{
    constexpr auto buttonType = ButtonType::LEFT_PAD;
    testButtonPtr = std::make_unique<Pad>(buttonType);

    auto packet = builder
                    .pressLeftPad()
                    .build();

    auto event = testButtonPtr->updateState(packet);

    ButtonTest::verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED);
}

TEST_F(PadTest, EmptyPacketLeftPadExpectNoEvent)
{
    testButtonPtr = std::make_unique<Pad>(ButtonType::LEFT_PAD);

    auto packet = builder
                    .build();

    auto event = testButtonPtr->updateState(packet);

    ASSERT_EQ(event, std::nullopt);
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

    auto event = testButtonPtr->updateState(packet);

    verifyButtonDataChangedEvent(*event, buttonType, buttonState, TouchPoint{X_VALUE, Y_VALUE});
}

// Button right pad
TEST_F(PadTest, TouchRightPadExpectEvent)
{
    constexpr auto buttonType = ButtonType::RIGHT_PAD;
    testButtonPtr = std::make_unique<Pad>(buttonType);

    auto packet = builder
                    .touchRightPad()
                    .build();

    auto event = testButtonPtr->updateState(packet);

    ButtonTest::verifyButtonDataChangedEvent(*event, buttonType, ButtonState::TOUCHED);
}

TEST_F(PadTest, PressRightPadExpectEvent)
{
    constexpr auto buttonType = ButtonType::RIGHT_PAD;
    testButtonPtr = std::make_unique<Pad>(buttonType);

    auto packet = builder
                    .pressRightPad()
                    .build();

    auto event = testButtonPtr->updateState(packet);

    ButtonTest::verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED);
}

TEST_F(PadTest, EmptyPacketRightPadExpectNoEvent)
{
    testButtonPtr = std::make_unique<Pad>(ButtonType::RIGHT_PAD);

    auto packet = builder
                    .build();

    auto event = testButtonPtr->updateState(packet);

    ASSERT_EQ(event, std::nullopt);
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

    auto event = testButtonPtr->updateState(packet);

    verifyButtonDataChangedEvent(*event, buttonType, buttonState, TouchPoint{X_VALUE, Y_VALUE});
}

// Button joystick
TEST_F(PadTest, PressJoystickExpectEvent)
{
    constexpr auto buttonType = ButtonType::JOYSTICK;
    testButtonPtr = std::make_unique<Pad>(buttonType);

    auto packet = builder
                    .pressJoystick()
                    .build();

    auto event = testButtonPtr->updateState(packet);

    ButtonTest::verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED);
}

TEST_F(PadTest, EmptyPacketJoystickExpectNoEvent)
{
    testButtonPtr = std::make_unique<Pad>(ButtonType::JOYSTICK);

    auto packet = builder
                    .build();

    auto event = testButtonPtr->updateState(packet);

    ASSERT_EQ(event, std::nullopt);
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

    auto event = testButtonPtr->updateState(packet);

    verifyButtonDataChangedEvent(*event, buttonType, buttonState, TouchPoint{X_VALUE, Y_VALUE});
}

TEST_F(PadTest, MovePadTwiceAndReleaseExpectThreeEvents)
{
    constexpr auto buttonType = ButtonType::LEFT_PAD;

    testButtonPtr = std::make_unique<Pad>(buttonType);

    constexpr auto X_INITIAL_VALUE = 500;
    constexpr auto Y_INITIAL_VALUE = 0;

    auto packet = builder
                    .moveLeftPad(X_INITIAL_VALUE, Y_INITIAL_VALUE)
                    .build();

    auto event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::TOUCHED, TouchPoint{X_INITIAL_VALUE, Y_INITIAL_VALUE});

    constexpr auto X_SECOND_VALUE = 500;
    constexpr auto Y_SECOND_VALUE = 200;

    packet = builder
                .moveLeftPad(X_SECOND_VALUE, Y_SECOND_VALUE)
                .build();

    event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::TOUCHED, TouchPoint{X_SECOND_VALUE, Y_SECOND_VALUE});

    builder.reset();
    packet = builder
                .build();

    event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::RELEASED, TouchPoint{});
}

TEST_F(PadTest, MovePadTwiceToSamePointExpectOneEvent)
{
    constexpr auto buttonType = ButtonType::LEFT_PAD;

    testButtonPtr = std::make_unique<Pad>(buttonType);

    constexpr auto X_INITIAL_VALUE = 0;
    constexpr auto Y_INITIAL_VALUE = -32768;

    auto packet = builder
                    .moveLeftPad(X_INITIAL_VALUE, Y_INITIAL_VALUE)
                    .build();

    auto event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::TOUCHED, TouchPoint{X_INITIAL_VALUE, Y_INITIAL_VALUE});

    event = testButtonPtr->updateState(packet);
    ASSERT_EQ(event, std::nullopt);
}

TEST_F(PadTest, MoveJoystickPressAndReleaseExpectThreeEvents)
{
    constexpr auto buttonType = ButtonType::JOYSTICK;

    testButtonPtr = std::make_unique<Pad>(buttonType);

    constexpr auto X_INITIAL_VALUE = -500;
    constexpr auto Y_INITIAL_VALUE = -500;

    auto packet = builder
                    .moveJoystick(X_INITIAL_VALUE, Y_INITIAL_VALUE)
                    .build();

    auto event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::RELEASED, TouchPoint{X_INITIAL_VALUE, Y_INITIAL_VALUE});

    packet = builder
                .pressJoystick()
                .build();

    event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED, TouchPoint{X_INITIAL_VALUE, Y_INITIAL_VALUE});

    builder.reset();
    packet = builder
                .build();

    event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::RELEASED, TouchPoint{});
}