#pragma once

#include <bitset>

class SteamInputPacket
{  
    public:
    std::bitset<24> buttons;
    
    short leftTrigger;
    short rightTrigger;

    short lpadX;
    short lpadY;
    short rpadX;
    short rpadY;

    SteamInputPacket(unsigned char* data);

    void print();
};
