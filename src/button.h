#pragma once

class Button
{
public:
    Button(const char* _text, int _font_size, int _x, int _y, int _w, int _h, Color _color);
    void drawButton();
    
    bool isOnButton();
    void onButtonClicked();

private:
    const char* text;
    int font_size;
    int x;
    int y;
    int w;
    int h;
    Color color;
};