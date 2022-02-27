#include "Device.h"
#include "KeyboardPlatformApi.h"
#include <memory>

class Keyboard : public Device
{
    private:
    std::unique_ptr<KeyboardPlatformApi> keyboardApi;
    KeyboardKeyType keyType;

    public:
    Keyboard(std::unique_ptr<KeyboardPlatformApi> keyboardApi, KeyboardKeyType keyType) : Device(DeviceType::KEYBOARD), keyboardApi(std::move(keyboardApi)), keyType(keyType) { };

    virtual void triggerAction(const ButtonDataChangedEvent& event) override;
};