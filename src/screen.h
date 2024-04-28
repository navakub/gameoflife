#include <raylib.h>

const Color BG_COLOR = Color(WHITE);
const int FPS = 60;

const int OFFSET = 20;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int GRID_SIZE = 50;

const int BOARD_WIDTH = SCREEN_HEIGHT - 2*OFFSET;
const int BOARD_HEIGHT = SCREEN_HEIGHT - 2*OFFSET;
const int NUM_ROW = BOARD_HEIGHT/GRID_SIZE;
const int NUM_COL = BOARD_WIDTH/GRID_SIZE;

const int BTN_WIDTH = SCREEN_WIDTH - BOARD_WIDTH - 2*OFFSET;
const int BTN_HEIGHT = 50;

bool isRunning = false;