#pragma once

class TouchPoint
{
    public:
    short x;
    short y;

    TouchPoint() : x(0), y(0) { };
    TouchPoint(short x, short y) : x(x), y(y) { };
};
