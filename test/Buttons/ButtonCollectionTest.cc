#include "ButtonCollectionTest.h"

void ButtonCollectionTest::SetUp() {
    buttonCollectionPtr = std::make_unique<ButtonCollection>();
}

void ButtonCollectionTest::TearDown() {
    builder.reset();
    buttonCollectionPtr.reset();
}

auto ButtonCollectionTest::findEvent(const std::vector<ButtonDataChangedEvent>& events, ButtonType buttonType)
{
    auto findEventWithGivenType =
    [&buttonType] (const auto& event) { return event.type == buttonType; };
    return std::find_if(events.begin(), events.end(), findEventWithGivenType);
}

void ButtonCollectionTest::verifyEventByType(const std::vector<ButtonDataChangedEvent>& events, ButtonType buttonType, ButtonState state, TouchPoint touchPoint)
{
    const auto& eventIt = findEvent(std::move(events), buttonType);
    if(eventIt != events.end())
    {
        EXPECT_EQ((*eventIt).type, buttonType);
        EXPECT_EQ((*eventIt).state, state);
        EXPECT_EQ((*eventIt).touchPoint, touchPoint);
    }
}

TEST_F(ButtonCollectionTest, PressAllButtonsExpectAllEvents)
{
    constexpr auto FULLY_PRESSED_TRIGGER = 255;
    constexpr auto EXPECTED_NUMBER_OF_EVENTS = 16;

    auto packet = builder
                    .pressA()
                    .pressB()
                    .pressX()
                    .pressY()
                    .pressLeftBumper()
                    .pressRightBumper()
                    .pressLeftTrigger(FULLY_PRESSED_TRIGGER)
                    .pressRightTrigger(FULLY_PRESSED_TRIGGER)
                    .pressLeftGrip()
                    .pressRightGrip()
                    .pressSelect()
                    .pressStart()
                    .pressSteam()
                    .touchLeftPad()
                    .touchRightPad()
                    .pressJoystick()
                    .build();

    auto events = buttonCollectionPtr->update(packet);

    EXPECT_EQ(events.size(), EXPECTED_NUMBER_OF_EVENTS);
}

TEST_F(ButtonCollectionTest, MoveLeftAndRightPadExpectEvents)
{
    constexpr auto X_LEFT_PAD_INITIAL = 500;
    constexpr auto Y_LEFT_PAD_INITIAL = -500;
    constexpr auto X_RIGHT_PAD_INITIAL = 1000;
    constexpr auto Y_RIGHT_PAD_INITIAL = 1500;
    constexpr auto INITIAL_NUMBER_OF_EVENTS = 3;

    auto packet = builder
                    .pressX()
                    .moveLeftPad(X_LEFT_PAD_INITIAL, Y_LEFT_PAD_INITIAL)
                    .moveRightPad(X_RIGHT_PAD_INITIAL, Y_RIGHT_PAD_INITIAL)
                    .build();
    
    auto events = buttonCollectionPtr->update(packet);

    EXPECT_EQ(events.size(), INITIAL_NUMBER_OF_EVENTS);
    verifyEventByType(events, ButtonType::X, ButtonState::PRESSED, TouchPoint{});
    verifyEventByType(events, ButtonType::LEFT_PAD, ButtonState::TOUCHED, TouchPoint{X_LEFT_PAD_INITIAL, Y_LEFT_PAD_INITIAL});
    verifyEventByType(events, ButtonType::RIGHT_PAD, ButtonState::TOUCHED, TouchPoint{X_RIGHT_PAD_INITIAL, Y_RIGHT_PAD_INITIAL});

    constexpr auto X_LEFT_PAD_SECOND = 1500;
    constexpr auto Y_LEFT_PAD_SECOND = -1500;
    constexpr auto SECOND_NUMBER_OF_EVENTS = 2;

    builder.reset();
    packet = builder
                .pressX()
                .moveLeftPad(X_LEFT_PAD_SECOND, Y_LEFT_PAD_SECOND)
                .build();

    events = buttonCollectionPtr->update(packet);

    EXPECT_EQ(events.size(), SECOND_NUMBER_OF_EVENTS);
    verifyEventByType(events, ButtonType::LEFT_PAD, ButtonState::TOUCHED, TouchPoint{X_LEFT_PAD_SECOND, Y_LEFT_PAD_SECOND});
    verifyEventByType(events, ButtonType::RIGHT_PAD, ButtonState::RELEASED, TouchPoint{});
}

TEST_F(ButtonCollectionTest, MoveLeftPadAndJoystickExpectOneEvent)
{
    constexpr auto X_LEFT_PAD_INITIAL = 500;
    constexpr auto Y_LEFT_PAD_INITIAL = -500;
    constexpr auto INITIAL_NUMBER_OF_EVENTS = 1;

    auto packet = builder
                .moveLeftPad(X_LEFT_PAD_INITIAL, Y_LEFT_PAD_INITIAL)
                .moveJoystick(X_LEFT_PAD_INITIAL, Y_LEFT_PAD_INITIAL)
                .build();

    auto events = buttonCollectionPtr->update(packet);

    EXPECT_EQ(events.size(), INITIAL_NUMBER_OF_EVENTS);
    verifyEventByType(events, ButtonType::LEFT_PAD, ButtonState::TOUCHED, TouchPoint{X_LEFT_PAD_INITIAL, Y_LEFT_PAD_INITIAL});
}

TEST_F(ButtonCollectionTest, MoveJoystickExpectNoLeftPadEvent)
{
    constexpr auto X_LEFT_PAD_INITIAL = 500;
    constexpr auto Y_LEFT_PAD_INITIAL = -500;
    constexpr auto INITIAL_NUMBER_OF_EVENTS = 1;

    auto packet = builder
                .moveJoystick(X_LEFT_PAD_INITIAL, Y_LEFT_PAD_INITIAL)
                .build();

    auto events = buttonCollectionPtr->update(packet);

    EXPECT_EQ(events.size(), INITIAL_NUMBER_OF_EVENTS);
    verifyEventByType(events, ButtonType::JOYSTICK, ButtonState::RELEASED, TouchPoint{X_LEFT_PAD_INITIAL, Y_LEFT_PAD_INITIAL});
}