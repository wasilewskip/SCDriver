#pragma once

class TouchPoint
{
    public:
    int16_t x;
    int16_t y;

    TouchPoint() : x(0), y(0) { };
    TouchPoint(int16_t x, int16_t y) : x(x), y(y) { };
};

inline bool operator==(const TouchPoint& lhs, const TouchPoint& rhs){ return (lhs.x == rhs.x && lhs.y == rhs.y); }
inline bool operator!=(const TouchPoint& lhs, const TouchPoint& rhs){return !operator==(lhs,rhs);}
// inline bool operator< (const X& lhs, const X& rhs){ /* do actual comparison */ }
// inline bool operator> (const X& lhs, const X& rhs){return  operator< (rhs,lhs);}
// inline bool operator<=(const X& lhs, const X& rhs){return !operator> (lhs,rhs);}
// inline bool operator>=(const X& lhs, const X& rhs){return !operator< (lhs,rhs);}
