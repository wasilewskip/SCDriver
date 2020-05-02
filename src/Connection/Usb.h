#pragma once

#include "libusb.h"

class Usb {

    private:
    libusb_device_handle* deviceHandlePtr;

    public:
    
    int init() { return libusb_init(nullptr); }
    void exit() { libusb_exit(nullptr); }

    void openDeviceWithVidPid(int vendorId, int productId) { deviceHandlePtr = libusb_open_device_with_vid_pid(nullptr, vendorId, productId); }
    void closeDevice() { libusb_close(deviceHandlePtr); }

    int claimInterface(int interfaceNumber) { return libusb_claim_interface(deviceHandlePtr, interfaceNumber); }
    int releaseInterface(int interfaceNumber) { return libusb_release_interface(deviceHandlePtr, interfaceNumber); }

    int interruptTransfer(unsigned char endpoint, unsigned char *data, int length, int *actual_length, unsigned int timeout)
    { return libusb_interrupt_transfer(deviceHandlePtr, endpoint, data, length, actual_length, timeout); }
    

};