#include <raylib.h>
#include "grid.h"
#include "button.h"
#include "screen.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "CONWAY'S GAME OF LIFE");
    SetTargetFPS(FPS);

    Grid grid(GRID_SIZE, NUM_ROW, NUM_COL);
    grid.initialiseCells();
    
    Button btn_start(txt_start, 16, BOARD_WIDTH + OFFSET, OFFSET, BTN_WIDTH, BTN_HEIGHT, LIGHTGRAY);
    Button btn_stop(txt_stop, 16, BOARD_WIDTH + OFFSET, BTN_HEIGHT + 2*OFFSET, BTN_WIDTH, BTN_HEIGHT, LIGHTGRAY);
    Button btn_clear(txt_clear, 16, BOARD_WIDTH + OFFSET, 2*BTN_HEIGHT + 2*OFFSET, BTN_WIDTH, BTN_HEIGHT, LIGHTGRAY);

    while (!WindowShouldClose())
    {
        grid.update();

        BeginDrawing();
            ClearBackground(BG_COLOR);
            
            grid.draw();

            btn_start.drawButton();
            btn_stop.drawButton();
            btn_clear.drawButton();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}