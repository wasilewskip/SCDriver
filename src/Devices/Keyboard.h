#include "IKeyboard.h"
#include "KeyboardPlatformApi.h"
#include <memory>

class Keyboard : public IKeyboard
{
    private:
    std::unique_ptr<KeyboardPlatformApi> keyboardApi;

    public:
    Keyboard(std::unique_ptr<KeyboardPlatformApi> keyboardApi) : IKeyboard(), keyboardApi(std::move(keyboardApi)){ };

    virtual void pressKey(KeyboardKeyType key) override;
    virtual void releaseKey(KeyboardKeyType key) override;
};