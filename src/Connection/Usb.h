#pragma once

#include "libusb.h"

class Usb {

    public:
    
    int init() { return libusb_init(nullptr); }
    void exit() { libusb_exit(nullptr); }

    libusb_device_handle* openDeviceWithVidPid(int vendorId, int productId) { return libusb_open_device_with_vid_pid(nullptr, vendorId, productId); }
    void closeDevice(libusb_device_handle* deviceHandlePtr) { libusb_close(deviceHandlePtr); }

    int claimInterface(libusb_device_handle* deviceHandlePtr, int interfaceNumber) { return libusb_claim_interface(deviceHandlePtr, interfaceNumber); }
    int releaseInterface(libusb_device_handle* deviceHandlePtr, int interfaceNumber) { return libusb_release_interface(deviceHandlePtr, interfaceNumber); }

    int interruptTransfer(libusb_device_handle *deviceHandlePtr, unsigned char endpoint, unsigned char *data, int length, int *actual_length, unsigned int timeout)
    { return libusb_interrupt_transfer(deviceHandlePtr, endpoint, data, length, actual_length, timeout); }
    

};