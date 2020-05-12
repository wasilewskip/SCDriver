#include "ButtonTest.h"

void ButtonTest::TearDown() 
{
    builder.reset();
    testButtonPtr.reset();
}

void ButtonTest::verifyButtonDataChangedEvent(const ButtonDataChangedEvent& event, ButtonType type, ButtonState state)
{
    EXPECT_EQ(event.type, type);
    EXPECT_EQ(event.state, state);
    EXPECT_EQ(event.triggerInput, 0);
    EXPECT_EQ(event.touchPoint, TouchPoint{});
}

void ButtonTest::testEmptyPacket(const ButtonType buttonType)
{
    testButtonPtr = std::make_unique<Button>(buttonType);

    auto emptyPacket = builder.build();
    auto event = testButtonPtr->updateState(emptyPacket);

    ASSERT_EQ(event, std::nullopt);
}

void ButtonTest::testButtonPress(const ButtonType buttonType)
{
    testButtonPtr = std::make_unique<Button>(buttonType);

    auto packet = builder
                    .press(buttonType)
                    .build();

    auto event = testButtonPtr->updateState(packet);

    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED);
}

// Button A
TEST_F(ButtonTest, PressButtonAExpectEvent)
{
    constexpr auto buttonType = ButtonType::A;
    testButtonPress(buttonType);
}

TEST_F(ButtonTest, EmptyPacketButtonAExpectNoEvent)
{
    constexpr auto buttonType = ButtonType::A;
    testEmptyPacket(buttonType);
}
 
// Button B
TEST_F(ButtonTest, PressButtonBExpectEvent)
{
    constexpr auto buttonType = ButtonType::B;
    testButtonPress(buttonType);
}

TEST_F(ButtonTest, EmptyPacketButtonBExpectNoEvent)
{
    constexpr auto buttonType = ButtonType::B;
    testEmptyPacket(buttonType);
}

// Button X
TEST_F(ButtonTest, PressButtonXExpectEvent)
{
    constexpr auto buttonType = ButtonType::X;
    testButtonPress(buttonType);
}

TEST_F(ButtonTest, EmptyPacketButtonXExpectNoEvent)
{
    constexpr auto buttonType = ButtonType::X;
    testEmptyPacket(buttonType);
}

// Button Y
TEST_F(ButtonTest, PressButtonYExpectEvent)
{
    constexpr auto buttonType = ButtonType::Y;
    testButtonPress(buttonType);
}

TEST_F(ButtonTest, EmptyPacketButtonYExpectNoEvent)
{
    constexpr auto buttonType = ButtonType::Y;
    testEmptyPacket(buttonType);
}

// Button left grip
TEST_F(ButtonTest, PressButtonLeftGripExpectEvent)
{
    constexpr auto buttonType = ButtonType::LEFT_GRIP;
    testButtonPress(buttonType);
}

TEST_F(ButtonTest, EmptyPacketButtonLeftGripExpectNoEvent)
{
    constexpr auto buttonType = ButtonType::LEFT_GRIP;
    testEmptyPacket(buttonType);
}

// Button right grip
TEST_F(ButtonTest, PressButtonRightGripExpectEvent)
{
    constexpr auto buttonType = ButtonType::RIGHT_GRIP;
    testButtonPress(buttonType);
}

TEST_F(ButtonTest, EmptyPacketButtonRightGripExpectNoEvent)
{
    constexpr auto buttonType = ButtonType::RIGHT_GRIP;
    testEmptyPacket(buttonType);
}

// Button select
TEST_F(ButtonTest, PressButtonSelectExpectEvent)
{
    constexpr auto buttonType = ButtonType::SELECT;
    testButtonPress(buttonType);
}

TEST_F(ButtonTest, EmptyPacketButtonSelectExpectNoEvent)
{
    constexpr auto buttonType = ButtonType::SELECT;
    testEmptyPacket(buttonType);
}

// Button steam
TEST_F(ButtonTest, PressButtonSteamExpectEvent)
{
    constexpr auto buttonType = ButtonType::STEAM;
    testButtonPress(buttonType);
}

TEST_F(ButtonTest, EmptyPacketButtonSteamExpectNoEvent)
{
    constexpr auto buttonType = ButtonType::STEAM;
    testEmptyPacket(buttonType);
}

// Button start
TEST_F(ButtonTest, PressButtonStartExpectEvent)
{
    constexpr auto buttonType = ButtonType::START;
    testButtonPress(buttonType);
}

TEST_F(ButtonTest, EmptyPacketButtonStartExpectNoEvent)
{
    constexpr auto buttonType = ButtonType::START;
    testEmptyPacket(buttonType);
}

// Button left bumper
TEST_F(ButtonTest, PressButtonLeftBumperExpectEvent)
{
    constexpr auto buttonType = ButtonType::LEFT_BUMPER;
    testButtonPress(buttonType);
}

TEST_F(ButtonTest, EmptyPacketButtonLeftBumperExpectNoEvent)
{
    constexpr auto buttonType = ButtonType::LEFT_BUMPER;
    testEmptyPacket(buttonType);
}

// Button right bumper
TEST_F(ButtonTest, PressButtonRightBumperExpectEvent)
{
    constexpr auto buttonType = ButtonType::RIGHT_BUMPER;
    testButtonPress(buttonType);
}

TEST_F(ButtonTest, EmptyPacketButtonRightBumperExpectNoEvent)
{
    constexpr auto buttonType = ButtonType::RIGHT_BUMPER;
    testEmptyPacket(buttonType);
}

TEST_F(ButtonTest, PressButtonTwiceExpectOneEvent)
{
    constexpr auto buttonType = ButtonType::A;

    testButtonPtr = std::make_unique<Button>(buttonType);

    auto packet = builder
                    .pressA()
                    .build();

    auto event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED);

    event = testButtonPtr->updateState(packet);
    ASSERT_EQ(event, std::nullopt);
}

TEST_F(ButtonTest, PressAndReleaseButtonExpectTwoEvents)
{
    constexpr auto buttonType = ButtonType::A;

    testButtonPtr = std::make_unique<Button>(buttonType);

    auto packet = builder
                    .pressA()
                    .build();

    auto event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::PRESSED);

    // Build empty packet to release the button
    builder.reset();
    packet = builder
                .build();

    event = testButtonPtr->updateState(packet);
    verifyButtonDataChangedEvent(*event, buttonType, ButtonState::RELEASED);
}