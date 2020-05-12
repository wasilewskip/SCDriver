#pragma once

enum class ButtonType
{
    RIGHT_GRIP = 0,
    LEFT_PAD = 3,
    RIGHT_PAD = 4,
    JOYSTICK = 6,
    LEFT_TRIGGER,
    RIGHT_TRIGGER,
    SELECT = 12,
    STEAM = 13,
    START = 14,
    LEFT_GRIP = 15,
    RIGHT_BUMPER = 18,
    LEFT_BUMPER = 19,
    Y = 20,
    B = 21,
    X = 22,
    A = 23,
};

enum class ButtonState
{
    RELEASED,
    PRESSED,
    TOUCHED,
    MOVED
};