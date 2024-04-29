#include <raylib.h>
#include "screen.h"
#include "button.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

Button::Button(Rectangle _bounds, char* _text){
    bounds = _bounds;
    text = _text;
}

void Button::drawButton(){
    GuiButton(bounds, text);
}

bool Button::isButtonClicked(){
    return GuiButton(bounds, text) == 1;
}