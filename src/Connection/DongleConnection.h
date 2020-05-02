#pragma once
#include <memory>
#include "IConnection.h"
#include "Usb.h"

class DongleConnection : public IConnection
{
    private:
    std::unique_ptr<Usb> usbPtr;

    public:
    DongleConnection(std::unique_ptr<Usb> usb);
    ~DongleConnection();

    virtual SteamInputPacket read();
    virtual void write();
};