#include <raylib.h>
#include "grid.h"
#include "button.h"
#include "screen.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

Color BG_COLOR = Color(WHITE);
int FPS = 60;

int OFFSET = 20;

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
int GRID_SIZE = 50;

int BOARD_WIDTH = SCREEN_HEIGHT - 2*OFFSET;
int BOARD_HEIGHT = SCREEN_HEIGHT - 2*OFFSET;
int NUM_ROW = BOARD_HEIGHT/GRID_SIZE;
int NUM_COL = BOARD_WIDTH/GRID_SIZE;

char* TXT_START ="START";
char* TXT_STOP = "STOP";
char* TXT_CLEAR = "CLEAR";
int BTN_WIDTH = SCREEN_WIDTH - BOARD_WIDTH - 2*OFFSET;
int BTN_HEIGHT = 50;

bool isRunning = false;

int main()
{
    InitWindow(800, 600, "CONWAY'S GAME OF LIFE");
    SetTargetFPS(60);

    Grid grid(GRID_SIZE, NUM_ROW, NUM_COL);
    grid.initialiseCells();
    
    Button btn_start(TXT_START, 16, BOARD_WIDTH + OFFSET, OFFSET, BTN_WIDTH, BTN_HEIGHT, LIGHTGRAY);
    Button btn_stop(TXT_STOP, 16, BOARD_WIDTH + OFFSET, BTN_HEIGHT + 2*OFFSET, BTN_WIDTH, BTN_HEIGHT, LIGHTGRAY);
    Button btn_clear(TXT_CLEAR, 16, BOARD_WIDTH + OFFSET, 2*BTN_HEIGHT + 2*OFFSET, BTN_WIDTH, BTN_HEIGHT, LIGHTGRAY);

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

        /*
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(200,200,100,BLACK);
        EndDrawing();*/
    }

    CloseWindow();
    return 0;
}