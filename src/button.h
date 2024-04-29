#pragma once

#include <raylib.h>
#include "screen.h"


class Button
{
public:
    Button(Rectangle _bounds, char* _text);
    void drawButton();
    bool isButtonClicked();

private:
    Rectangle bounds;
    char* text;
};