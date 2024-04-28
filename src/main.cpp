#include <raylib.h>
#include "grid.h"
#include "button.h"
#include "screen.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "game of life");
    SetTargetFPS(FPS);

    Grid grid(GRID_SIZE, NUM_ROW, NUM_COL);
    grid.initialiseCells();
    
    const char* txt_start ="START";
    Button btn_start(txt_start, 16, BOARD_WIDTH + OFFSET, OFFSET, BTN_WIDTH, BTN_HEIGHT, LIGHTGRAY);
    const char* txt_stop = "STOP";
    Button btn_stop(txt_stop, 16, BOARD_WIDTH + OFFSET, BTN_HEIGHT + 2*OFFSET, BTN_WIDTH, BTN_HEIGHT, LIGHTGRAY);

    while (!WindowShouldClose())
    {
        

        BeginDrawing();
            ClearBackground(BG_COLOR);
            
            grid.update();
            grid.draw();

            btn_start.drawButton();
            btn_stop.drawButton();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}