#pragma once
#include <memory>
#include "IConnection.h"
#include "Usb.h"

class DongleConnection : public IConnection
{
    private:
    std::unique_ptr<Usb> usbPtr;
    libusb_device_handle* deviceHandlePtr;

    void init();

    public:
    DongleConnection(std::unique_ptr<Usb> usb);
    DongleConnection(const DongleConnection&) = delete;
    DongleConnection& operator=(const DongleConnection&) = delete;
    ~DongleConnection();

    virtual SteamInputPacket read();
    virtual void write();
};