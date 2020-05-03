#pragma once

#include "Connection/SteamInputPacket.h"
#include "Buttons/ButtonType.h"
#include <tuple>

class SteamInputPacketBuilder
{
private:
    static constexpr int PACKET_SIZE = 64;
    uint8_t packetData[PACKET_SIZE] = {0};

    void setBitInPacket(int packetIndex, int bitIndex);
    void setTriggerValueInPacket(int packetIndex, uint16_t value);
    std::tuple<uint8_t, uint8_t> splitValueToPacketFormat(uint16_t value);
    

public:

    SteamInputPacketBuilder& press(ButtonType buttonType);

    SteamInputPacketBuilder& pressA();
    SteamInputPacketBuilder& pressB();
    SteamInputPacketBuilder& pressX();
    SteamInputPacketBuilder& pressY();
    SteamInputPacketBuilder& pressLeftGrip();
    SteamInputPacketBuilder& pressRightGrip();
    SteamInputPacketBuilder& pressSelect();
    SteamInputPacketBuilder& pressSteam();
    SteamInputPacketBuilder& pressStart();
    SteamInputPacketBuilder& pressLeftBumper();
    SteamInputPacketBuilder& pressRightBumper();
    SteamInputPacketBuilder& pressLeftTrigger(uint16_t triggerInput);
    SteamInputPacketBuilder& pressRightTrigger(uint16_t triggerInput);
    SteamInputPacketBuilder& touchLeftPad();
    SteamInputPacketBuilder& touchRightPad();
    SteamInputPacketBuilder& pressLeftPad();
    SteamInputPacketBuilder& pressRightPad();
    SteamInputPacketBuilder& pressJoystick();
    SteamInputPacketBuilder& moveLeftPad(int16_t x, int16_t y);
    SteamInputPacketBuilder& moveRightPad(int16_t x, int16_t y);
    SteamInputPacketBuilder& moveJoystick(int16_t x, int16_t y);

    SteamInputPacket build();
    void reset();
};