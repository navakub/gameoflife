#include <raylib.h>
#include "grid.h"
#include "screen.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

Color BG_COLOR = Color(WHITE);
int FPS = 10;

int OFFSET = 20;

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
int GRID_SIZE = 40;

int BOARD_WIDTH = SCREEN_HEIGHT - 2*OFFSET;
int BOARD_HEIGHT = SCREEN_HEIGHT - 2*OFFSET;
int NUM_ROW = BOARD_HEIGHT/GRID_SIZE;
int NUM_COL = BOARD_WIDTH/GRID_SIZE;

char* TXT_START = "START";
char* TXT_STOP = "STOP";
char* TXT_CLEAR = "CLEAR";
int BTN_WIDTH = SCREEN_WIDTH - BOARD_WIDTH - 3*OFFSET;
int BTN_HEIGHT = 60;

Rectangle bounds_start;
Rectangle bounds_stop;
Rectangle bounds_clear;

bool isRunning = false;

void initialiseButtons(){
    bounds_start.x = BOARD_WIDTH + 2*OFFSET; bounds_start.y = OFFSET;
    bounds_start.width = BTN_WIDTH; bounds_start.height = BTN_HEIGHT;

    bounds_stop.x = BOARD_WIDTH + 2*OFFSET; bounds_stop.y = BTN_HEIGHT + 2*OFFSET;
    bounds_stop.width = BTN_WIDTH; bounds_stop.height = BTN_HEIGHT;

    bounds_clear.x = BOARD_WIDTH + 2*OFFSET; bounds_clear.y = 2*BTN_HEIGHT + 3*OFFSET;
    bounds_clear.width = BTN_WIDTH; bounds_clear.height = BTN_HEIGHT;
}

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "CONWAY'S GAME OF LIFE");
    SetTargetFPS(FPS);

    Grid grid(GRID_SIZE, NUM_ROW, NUM_COL);
    grid.initialiseCells();

    initialiseButtons();
    Button btnStart(bounds_start, TXT_START);
    Button btnStop(bounds_stop, TXT_STOP);
    Button btnClear(bounds_clear, TXT_CLEAR);

    while (!WindowShouldClose())
    {
        grid.update();
        /*if(btnStart.isButtonClicked() && !isRunning) isRunning = true; 
        if(btnStop.isButtonClicked() && isRunning) isRunning = false; 
        if(btnClear.isButtonClicked()) grid.initialiseCells(); */

        BeginDrawing();
            ClearBackground(BG_COLOR);
            
            // DrawText(!isRunning ? "TRUE" : "FALSE", 650, 450, 16, BLACK);
            grid.draw();
            
            btnStart.drawButton();
            btnStop.drawButton();
            btnClear.drawButton();
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