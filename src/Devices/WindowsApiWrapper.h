#pragma once

#define WINVER 0x0500
#include <windows.h>
#include <memory>

class WindowsApiWrapper
{
    public:
    void sendInput(INPUT* input, int size) { SendInput(size, input, sizeof(input)); };
    void sendInput(INPUT& input) { SendInput(1, &input, sizeof(input)); };
};