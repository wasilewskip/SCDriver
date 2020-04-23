#include "DongleConnection.h"
#include <iostream>

DongleConnection::DongleConnection(std::unique_ptr<Usb> usb) : usbPtr(std::move(usb))
{
    init();
}

DongleConnection::~DongleConnection()
{
    std::cout << "Destroying object";
}

void DongleConnection::init()
{
    int x = usbPtr->init();
    this->deviceHandlePtr = usbPtr->openDeviceWithVidPid(0x28de, 0x1142);
    int ret = usbPtr->claimInterface(this->deviceHandlePtr, 1);
}

SteamInputPacket DongleConnection::read()
{
    int bytesRead;
    unsigned char data[64] = {0};
    int ret = usbPtr->interruptTransfer(this->deviceHandlePtr, 0x82, data, 64, &bytesRead, 0);
    SteamInputPacket packet = SteamInputPacket(data);
    return packet;
}

void DongleConnection::write()
{
    usbPtr->releaseInterface(this->deviceHandlePtr, 1);
    usbPtr->closeDevice(this->deviceHandlePtr);
    usbPtr->exit();
}