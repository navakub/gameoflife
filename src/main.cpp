#include <raylib.h>
#include "grid.h"
#include "gui.h"
#include "screen.h"

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "game of life");
    SetTargetFPS(FPS);

    Grid grid(GRID_SIZE, NUM_ROW, NUM_COL);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BG_COLOR);
            grid.update();
            grid.draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}