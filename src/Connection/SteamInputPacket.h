#pragma once

#include <bitset>

class SteamInputPacket
{  
    public:
    std::bitset<24> buttons;
    
    uint16_t leftTrigger;
    uint16_t rightTrigger;

    int16_t lpadX;
    int16_t lpadY;
    int16_t rpadX;
    int16_t rpadY;

    SteamInputPacket(uint8_t* data);

    void print();
};
