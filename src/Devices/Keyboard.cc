#include "Keyboard.h"

void Keyboard::pressKey(KeyboardKeyType key)
{
    keyboardApi->pressKey(key);
}

void Keyboard::releaseKey(KeyboardKeyType key)
{
    keyboardApi->releaseKey(key);
}