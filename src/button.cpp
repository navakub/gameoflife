#include <raylib.h>
#include "button.h"
#include "screen.h"
#include <string.h>


Button::Button(const char* _text, int _font_size, int _x, int _y, int _w, int _h, Color _color){ 
    text = _text;
    font_size = _font_size;
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    color = _color;
}

void Button::drawButton(){
    DrawRectangle(x, y, w, h, color);
    Vector2 text_dim = MeasureTextEx(GetFontDefault(), text, font_size, 0.1);
    int text_width = text_dim.x; int text_height = text_dim.y; 
    DrawText(text, x + w/2 - text_width, y + text_height/2, 25, BLACK);
}

bool Button::isOnButton(){
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    return mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y +h;
}

void Button::onButtonClicked(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && isOnButton()){
        if(strcmp(text, txt_start) == 0 && !isRunning){
            isRunning = true;
        }else if(strcmp(text, txt_stop) == 0 && isRunning){
            isRunning = false;
        }else if(strcmp(text, txt_clear) == 0 && isRunning){
            isRunning = false;
        }
    }
}
