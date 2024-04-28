#include <raylib.h>
#include "textbox.h"
#include "screen.h"

TextBox::TextBox(char* _text, int _font_size, int _x, int _y, int _w, int _h, Color _color){
    text = _text;
    font_size = _font_size;
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    color = _color;
}
