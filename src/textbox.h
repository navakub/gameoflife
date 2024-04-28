#pragma once

class TextBox
{
public:
    TextBox(char* _text, int _font_size, int _x, int _y, int _w, int _h, Color _color);
    

private:
    char* text;
    int font_size;
    int x;
    int y;
    int w;
    int h;
    Color color;
};