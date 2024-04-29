#include <raylib.h>
#include "screen.h"
#include "button.h"
#include "grid.h"


Grid::Grid(int _gridSize, int _numRow, int _numCol){
    gridSize = _gridSize;
    numRow = _numRow;
    numCol = _numCol;

    size = numRow * numCol;
    cells = new int[size];
    new_cells = new int[size];
}

void Grid::initialiseCells(){
    for(int i=0; i<size; i++) {
        cells[i] = 0;
        new_cells[i] = 0;
    }
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
    return pos_x >= OFFSET && pos_x <= OFFSET + BOARD_WIDTH && pos_y >= OFFSET && pos_y <= OFFSET + BOARD_HEIGHT;
}

void Grid::draw(){
    for(int iy=0; iy<numRow; iy++){
        for(int ix=0; ix<numCol; ix++){
            DrawRectangleLines(OFFSET + ix*gridSize, OFFSET + iy*gridSize, gridSize, gridSize, BLACK);

            if(new_cells[idx_2d_to_1d(ix, iy)] == 1){
                DrawRectangle(OFFSET + ix*gridSize, OFFSET + iy*gridSize, gridSize, gridSize, BLACK);
            }
        }
    }
}

void Grid::update(){
    int x = GetMouseX();
    int y = GetMouseY();
    //int cells_neighbour[8];
    //int topmid, botmid, self;
    /*
    if(!isRunning)
    {
        int index = idx_2d_to_1d((x - OFFSET)/GRID_SIZE, (y - OFFSET)/GRID_SIZE);
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOnBoard(x, y)) {
            if(cells[index] == 0) {
                cells[index] = 1;
            }
        }else if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT) && isOnBoard(x, y)) {
            if(cells[index] == 1) {
                cells[index] = 0;
            }
        }   
    }
    else if(isRunning)
    {
        for(int time=0; time<10; time++)
        {
            for(int i=0; i<size; i++){
                topmid = i - NUM_ROW;
                botmid = i + NUM_ROW;
                self = i;
                cells_neighbour[0] = topmid - 1 >= 0 ? cells[topmid + 1] : 0; // topleft
                cells_neighbour[1] = topmid >= 0 ? cells[topmid] : 0; // topmid
                cells_neighbour[2] = topmid + 1 >= 0 ? cells[topmid + 1] : 0; // topright
                cells_neighbour[3] = (self - 1)%NUM_ROW != 0 ? cells[self - 1] : 0; // left
                cells_neighbour[4] = (self)%NUM_ROW != 0 ? cells[self + 1] : 0; // right
                cells_neighbour[5] = botmid - 1 <= size ? cells[botmid - 1] : 0; // botleft
                cells_neighbour[6] = botmid <= size ? cells[botmid] : 0; // botmid
                cells_neighbour[7] = botmid + 1 <= size ? cells[botmid + 1] : 0; // botright
                

                int countAlive = 0;
                int countDead = 0;
                for(int j=0; j<8; j++){
                    if(cells_neighbour[j] == 0) countDead += 1;
                    if(cells_neighbour[j] == 1) countAlive += 1;
                }

                if(countAlive == 3 && cells[i] == 0) new_cells[i] = 1;
                if((countAlive == 2 || countAlive == 3) && cells[i] == 1) new_cells[i] = 1;
                if((countAlive != 2 || countAlive != 3) && cells[i] == 1) new_cells[i] = 0;   
            }
            
            for(int i=0; i<size; i++){
                cells[i] = new_cells[i];
            }
        }
    } */
    int index = idx_2d_to_1d((x - OFFSET)/GRID_SIZE, (y - OFFSET)/GRID_SIZE);
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOnBoard(x, y)) {
            if(cells[index] == 0) {
                cells[index] = 1;
            }
        }else if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT) && isOnBoard(x, y)) {
            if(cells[index] == 1) {
                cells[index] = 0;
            }
        }   
}