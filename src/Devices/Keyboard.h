#include "Device.h"
#include "KeyboardPlatformApi.h"
#include <memory>

class Keyboard : public Device
{
    private:
    std::unique_ptr<KeyboardPlatformApi> keyboardApi;

    public:
    Keyboard(std::unique_ptr<KeyboardPlatformApi> keyboardApi) : Device(DeviceType::KEYBOARD), keyboardApi(std::move(keyboardApi)) { };

    virtual void triggerAction(ActionCommandEvent actionCommand) override;
};