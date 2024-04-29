#include <raylib.h>
#include <random>
#include <omp.h>
#include "screen.h"
#include "grid.h"

Grid::Grid(int _gridSize, int _numRow, int _numCol){
    gridSize = _gridSize;
    numRow = _numRow;
    numCol = _numCol;

    size = numRow * numCol;
    initial_cells = new int[size];
    cells = new int[size];
    new_cells = new int[size];
}

void Grid::initialiseCells(){
    for(int i=0; i<size; i++) {
        initial_cells[i] = 0;
        cells[i] = 0;
        new_cells[i] = 0;
    }
}

void Grid::initialiseRandomCells(){
    for(int i=0; i<size; i++) {
        initial_cells[i] = rand() % 2;
        cells[i] = initial_cells[i];
        new_cells[i] = initial_cells[i];
    }
}

int* Grid::copyCells(int* c){
    int* nc = new int[size];
    for(int i=0; i<size; i++){
        nc[i] = c[i];
    }
    return nc;
}

int* Grid::idx_1d_to_2d(int index){
    int* indices = new int[2];
    indices[0] = index/numCol; indices[1] = index%numCol;
    return indices;
}

int Grid::idx_2d_to_1d(int ix, int iy){
    return iy*numRow + ix;
}

int Grid::gridWidth(){
    return numCol*gridSize;
}

int Grid::gridHeight(){
    return numRow*gridSize;
}

bool Grid::isOnBoard(int pos_x, int pos_y){
    return pos_x >= OFFSET && pos_x <= OFFSET + this->gridWidth() && pos_y >= OFFSET && pos_y <= OFFSET + this->gridHeight();
}

void Grid::draw(){
    int index;
    for(int iy=0; iy<numRow; iy++){
        for(int ix=0; ix<numCol; ix++){
            DrawRectangleLines(OFFSET + ix*gridSize, OFFSET + iy*gridSize, gridSize, gridSize, BLACK);

            index = idx_2d_to_1d(ix, iy);
            if(initial_cells[index] == 1 && !isRunning){
                DrawRectangle(OFFSET + ix*gridSize, OFFSET + iy*gridSize, gridSize, gridSize, BLACK);
            }else if(cells[index] == 1  && isRunning){
                DrawRectangle(OFFSET + ix*gridSize, OFFSET + iy*gridSize, gridSize, gridSize, BLACK);
            }
        }
    }
}

void Grid::update(){
    
    if(!isRunning)
    {
        int x = GetMouseX();
        int y = GetMouseY();
        int index = idx_2d_to_1d((x - OFFSET)/GRID_SIZE, (y - OFFSET)/GRID_SIZE);
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOnBoard(x, y)) {
            if(initial_cells[index] == 0) {
                initial_cells[index] = 1;
            }
        }else if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT) && isOnBoard(x, y)) {
            if(initial_cells[index] == 1) {
                initial_cells[index] = 0;
            }
        }
        if(IsKeyPressed(KEY_R)) initialiseRandomCells();
        if(IsKeyPressed(KEY_C)) initialiseCells();
        if(IsKeyPressed(KEY_ENTER)) isRunning = true;
    }
    else if(isRunning && !isPaused)
    {
        if(IsKeyPressed(KEY_SPACE)) isPaused = true;

        if(NUM_EVOLUTIONS == 0) cells = copyCells(initial_cells);

        int cells_neighbour[8];
        int topmid, botmid, self;
        int countAlive, countDead;

        for(int i=0; i<size; i++)
        {
            topmid = i - NUM_ROW;
            botmid = i + NUM_ROW;
            self = i;
            cells_neighbour[0] = topmid - 1 >= 0 ? cells[topmid - 1] : 0; // topleft
            cells_neighbour[1] = topmid >= 0 ? cells[topmid] : 0; // topmid
            cells_neighbour[2] = topmid + 1 >= 0 ? cells[topmid + 1] : 0; // topright
            cells_neighbour[3] = (self) % NUM_COL != 0 ? cells[self - 1] : 0; // left
            cells_neighbour[4] = (self + 1) % NUM_COL != 0 ? cells[self + 1] : 0; // right
            cells_neighbour[5] = botmid - 1 <= size ? cells[botmid - 1] : 0; // botleft
            cells_neighbour[6] = botmid <= size ? cells[botmid] : 0; // botmid
            cells_neighbour[7] = botmid + 1 <= size ? cells[botmid + 1] : 0; // botright
            

            countAlive = 0;
            countDead = 0;
            for(int j=0; j<8; j++){
                if(cells_neighbour[j] == 0) countDead += 1;
                if(cells_neighbour[j] == 1) countAlive += 1;
            }

            if(countAlive == 3 && cells[i] == 0) new_cells[i] = 1; // a new cell is born
            else if((countAlive == 2 || countAlive == 3) && cells[i] == 1) new_cells[i] = 1; // a cell is alive
            else if((countAlive != 2 || countAlive != 3) && cells[i] == 1) new_cells[i] = 0;  // a cell dies
        }
    
        cells = copyCells(new_cells);
        NUM_EVOLUTIONS += 1;
        
    }
    else if(isRunning && isPaused)
    {
        if(IsKeyPressed(KEY_SPACE)) {
            isPaused = false;
        }
        if(IsKeyPressed(KEY_R)){
            isRunning = false;
            isPaused = false;
            NUM_EVOLUTIONS = 0;
        }
    }

}