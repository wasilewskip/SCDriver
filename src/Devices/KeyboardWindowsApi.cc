#include "KeyboardWindowsApi.h"

void KeyboardWindowsApi::pressKey(const KeyboardKeyType key)
{
    constexpr auto KEY_PRESSED = 0;
    INPUT input = buildInputStruct(KEY_PRESSED, key);
    apiWrapper->sendInput(input);
}

void KeyboardWindowsApi::releaseKey(const KeyboardKeyType key)
{
    constexpr auto KEY_RELEASED = 1;
    INPUT input = buildInputStruct(KEY_RELEASED, key);
    apiWrapper->sendInput(input);
}

INPUT KeyboardWindowsApi::buildInputStruct(bool isKeyReleased, KeyboardKeyType key)
{
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = mapInternalKeyToScanCode(key);
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = 0;
    input.ki.dwFlags = KEYEVENTF_SCANCODE | (isKeyReleased ? KEYEVENTF_KEYUP : 0);
    return input;
}

WORD KeyboardWindowsApi::mapInternalKeyToScanCode(KeyboardKeyType key)
{
    WORD mappedKey = 0x04; // A
    switch (key)
    {
    case KeyboardKeyType::A :
        mappedKey = MapVirtualKeyEx(0x41, MAPVK_VSC_TO_VK_EX, GetKeyboardLayout(0)); 
        break;
    
    default:
        break;
    }
    return mappedKey;
}