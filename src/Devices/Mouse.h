#include "Device.h"

class Mouse : public Device
{
    public:
    Mouse() : Device(DeviceType::MOUSE) { };
    virtual void triggerAction(const ButtonDataChangedEvent& event) override;
};