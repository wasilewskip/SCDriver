#include "SteamInputPacketBuilder.h"
#include <bitset>
#include <iostream>

void SteamInputPacketBuilder::setBitInPacket(int packetIndex, int bitIndex)
{
    constexpr auto BITSET_SIZE = 8;
    auto packetDataBits = std::bitset<BITSET_SIZE>(packetData[packetIndex]);
    packetDataBits.set(bitIndex);
    packetData[packetIndex] = static_cast<unsigned char>(packetDataBits.to_ulong());
}

void SteamInputPacketBuilder::setTriggerValueInPacket(int packetIndex, unsigned short value)
{
    packetData[packetIndex] = value;
}

std::tuple<uint8_t, uint8_t> SteamInputPacketBuilder::splitValueToPacketFormat(uint16_t value)
{
    return { value & 0xff, value >> 8 };
}

SteamInputPacketBuilder& SteamInputPacketBuilder::press(ButtonType buttonType)
{
    switch (buttonType)
    {
    case ButtonType::A :
        pressA();
        break;

    case ButtonType::B :
        pressB();
        break;

    case ButtonType::X :
        pressX();
        break;

    case ButtonType::Y :
        pressY();
        break;

    case ButtonType::LEFT_GRIP :
        pressLeftGrip();
        break;

    case ButtonType::RIGHT_GRIP :
        pressRightGrip();
        break;

    case ButtonType::LEFT_BUMPER :
        pressLeftBumper();
        break;

    case ButtonType::RIGHT_BUMPER :
        pressRightBumper();
        break;

    case ButtonType::SELECT :
        pressSelect();
        break;

    case ButtonType::STEAM :
        pressSteam();
        break;

    case ButtonType::START :
        pressStart();
        break;
    
    default:
        break;
    }

    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressA()
{
    constexpr auto PACKET_INDEX = 8;
    constexpr auto BIT_INDEX = 7;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressB()
{
    constexpr auto PACKET_INDEX = 8;
    constexpr auto BIT_INDEX = 5;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressX()
{
    constexpr auto PACKET_INDEX = 8;
    constexpr auto BIT_INDEX = 6;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressY()
{
    constexpr auto PACKET_INDEX = 8;
    constexpr auto BIT_INDEX = 4;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressLeftBumper()
{
    constexpr auto PACKET_INDEX = 8;
    constexpr auto BIT_INDEX = 3;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressRightBumper()
{
    constexpr auto PACKET_INDEX = 8;
    constexpr auto BIT_INDEX = 2;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressLeftGrip()
{
    constexpr auto PACKET_INDEX = 9;
    constexpr auto BIT_INDEX = 7;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressRightGrip()
{
    constexpr auto PACKET_INDEX = 10;
    constexpr auto BIT_INDEX = 0;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressSelect()
{
    constexpr auto PACKET_INDEX = 9;
    constexpr auto BIT_INDEX = 4;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressSteam()
{
    constexpr auto PACKET_INDEX = 9;
    constexpr auto BIT_INDEX = 5;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressStart()
{
    constexpr auto PACKET_INDEX = 9;
    constexpr auto BIT_INDEX = 6;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressLeftTrigger(unsigned short triggerInput)
{
    constexpr auto PACKET_INDEX = 11;
    setTriggerValueInPacket(PACKET_INDEX, triggerInput);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressRightTrigger(unsigned short triggerInput)
{
    constexpr auto PACKET_INDEX = 12;
    setTriggerValueInPacket(PACKET_INDEX, triggerInput);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::touchLeftPad()
{
    constexpr auto PACKET_INDEX = 10;
    constexpr auto BIT_INDEX = 3;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;    
}

SteamInputPacketBuilder& SteamInputPacketBuilder::touchRightPad()
{
    constexpr auto PACKET_INDEX = 10;
    constexpr auto BIT_INDEX = 4;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;    
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressLeftPad()
{
    // Pad have to be touched before press
    touchLeftPad();
    constexpr auto PACKET_INDEX = 10;
    constexpr auto BIT_INDEX = 1;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;  
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressRightPad()
{
    // Pad have to be touched before press
    touchRightPad();
    constexpr auto PACKET_INDEX = 10;
    constexpr auto BIT_INDEX = 2;
    setBitInPacket(PACKET_INDEX, BIT_INDEX);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::pressJoystick()
{
    constexpr auto PACKET_INDEX = 10;
    constexpr auto BIT_INDEX_TOUCH = 6;
    constexpr auto BIT_INDEX_PRESS = 1;
    setBitInPacket(PACKET_INDEX, BIT_INDEX_TOUCH);
    setBitInPacket(PACKET_INDEX, BIT_INDEX_PRESS);
    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::moveLeftPad(int16_t x, int16_t y)
{
    touchLeftPad();

    constexpr auto X_LOW_PACKET_INDEX = 16;
    constexpr auto X_HIGH_PACKET_INDEX = 17;
    constexpr auto Y_LOW_PACKET_INDEX = 18;
    constexpr auto Y_HIGH_PACKET_INDEX = 19;

    auto [ xlow , xhigh ] = splitValueToPacketFormat(x);
    packetData[X_LOW_PACKET_INDEX] = xlow;
    packetData[X_HIGH_PACKET_INDEX] = xhigh;
    auto [ ylow , yhigh ] = splitValueToPacketFormat(y);
    packetData[Y_LOW_PACKET_INDEX] = ylow;
    packetData[Y_HIGH_PACKET_INDEX] = yhigh;

    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::moveRightPad(int16_t x, int16_t y)
{
    touchRightPad();

    constexpr auto X_LOW_PACKET_INDEX = 20;
    constexpr auto X_HIGH_PACKET_INDEX = 21;
    constexpr auto Y_LOW_PACKET_INDEX = 22;
    constexpr auto Y_HIGH_PACKET_INDEX = 23;

    auto [ xlow , xhigh ] = splitValueToPacketFormat(x);
    packetData[X_LOW_PACKET_INDEX] = xlow;
    packetData[X_HIGH_PACKET_INDEX] = xhigh;
    auto [ ylow , yhigh ] = splitValueToPacketFormat(y);
    packetData[Y_LOW_PACKET_INDEX] = ylow;
    packetData[Y_HIGH_PACKET_INDEX] = yhigh;

    return *this;
}

SteamInputPacketBuilder& SteamInputPacketBuilder::moveJoystick(int16_t x, int16_t y)
{
    constexpr auto X_LOW_PACKET_INDEX = 16;
    constexpr auto X_HIGH_PACKET_INDEX = 17;
    constexpr auto Y_LOW_PACKET_INDEX = 18;
    constexpr auto Y_HIGH_PACKET_INDEX = 19;

    auto [ xlow , xhigh ] = splitValueToPacketFormat(x);
    packetData[X_LOW_PACKET_INDEX] = xlow;
    packetData[X_HIGH_PACKET_INDEX] = xhigh;
    auto [ ylow , yhigh ] = splitValueToPacketFormat(y);
    packetData[Y_LOW_PACKET_INDEX] = ylow;
    packetData[Y_HIGH_PACKET_INDEX] = yhigh;

    return *this;
}

SteamInputPacket SteamInputPacketBuilder::build()
{
    return SteamInputPacket{packetData};
}