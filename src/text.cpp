#include <raylib.h>
#include "screen.h"

void showKeyBinds(bool run, bool pause){
    if(!isRunning){
        DrawText("LMB: mark", 2*OFFSET + BOARD_WIDTH, OFFSET, FONT_SIZE, BLACK);
        DrawText("RMB: unmark", 2*OFFSET + BOARD_WIDTH, OFFSET + TEXT_SPACING, FONT_SIZE, BLACK);
        DrawText("C: clear", 2*OFFSET + BOARD_WIDTH, OFFSET + 2*TEXT_SPACING, FONT_SIZE, BLACK);
        DrawText("ENTER: start", 2*OFFSET + BOARD_WIDTH, OFFSET + 3*TEXT_SPACING, FONT_SIZE, BLACK);
    }else if(!isPaused){
        DrawText("SPACE: pause", 2*OFFSET + BOARD_WIDTH, OFFSET, FONT_SIZE, BLACK);
    }else{
        DrawText("SPACE: continue", 2*OFFSET + BOARD_WIDTH, OFFSET, FONT_SIZE, BLACK);
        DrawText("R: reset", 2*OFFSET + BOARD_WIDTH, OFFSET + TEXT_SPACING, FONT_SIZE, BLACK);
    }
}

void showInfo(bool run, bool pause){
    
}