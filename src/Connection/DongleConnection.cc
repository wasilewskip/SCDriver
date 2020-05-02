#include "DongleConnection.h"
#include <iostream>

DongleConnection::DongleConnection(std::unique_ptr<Usb> usb) : usbPtr(std::move(usb))
{
    const auto x = usbPtr->init();
    // TODO: add proper way to open device
    usbPtr->openDeviceWithVidPid(0x28de, 0x1142);
    auto ret = usbPtr->claimInterface(1);
}

DongleConnection::~DongleConnection()
{
    usbPtr->releaseInterface(1);
    usbPtr->closeDevice();
    usbPtr->exit();
}

SteamInputPacket DongleConnection::read()
{
    constexpr auto PACKET_SIZE = 64;
    constexpr auto TIMEOUT_MS = 100;
    constexpr auto ENDPOINT = 0x82;

    int bytesRead;
    uint8_t data[PACKET_SIZE] = {0};
    auto ret = usbPtr->interruptTransfer(ENDPOINT, data, PACKET_SIZE, &bytesRead, TIMEOUT_MS);
    SteamInputPacket packet = SteamInputPacket(data);
    return packet;
}

void DongleConnection::write()
{

}