#include <raylib.h>
#include "grid.h"
#include "screen.h"
#include "text.h"

Color BG_COLOR = Color(WHITE);
int FPS = 12;

int OFFSET = 20;

int SCREEN_WIDTH = 1024;
int SCREEN_HEIGHT = SCREEN_WIDTH * 3/4;
int GRID_SIZE = 10;

int BOARD_WIDTH = SCREEN_HEIGHT - 2*OFFSET;
int BOARD_HEIGHT = SCREEN_HEIGHT - 2*OFFSET;
int NUM_ROW = BOARD_HEIGHT/GRID_SIZE;
int NUM_COL = BOARD_WIDTH/GRID_SIZE;

int TEXT_SPACING = 30;
int FONT_SIZE = 20;
int NUM_EVOLUTIONS = 0;

bool isRunning = false;
bool isPaused = false;

double t1, t2, ts, tp, speedup;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "CONWAY'S GAME OF LIFE");
    SetTargetFPS(FPS);

    Grid grid(GRID_SIZE, NUM_ROW, NUM_COL);
    grid.initialiseCells();


    while (!WindowShouldClose())
    {
        grid.update();    
        
        BeginDrawing();
            ClearBackground(BG_COLOR);
            grid.draw();
            showKeyBinds(isRunning, isPaused);
        showInfo(isRunning, isPaused);
            
        EndDrawing();
    }

    CloseWindow();
    return 0;
}