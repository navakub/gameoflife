#include <raylib.h>
#include "screen.h"
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

            if(cells[idx_2d_to_1d(ix, iy)] == 1){
                DrawRectangle(OFFSET + ix*gridSize, OFFSET + iy*gridSize, gridSize, gridSize, BLACK);
            }
        }
    }
}

void Grid::update(){
    int x = GetMouseX();
    int y = GetMouseY();
    // int* cells_neighbour = new int[8];
    
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOnBoard(x, y)) {
        int index = idx_2d_to_1d((x - OFFSET)/GRID_SIZE, (y - OFFSET)/GRID_SIZE);
        if(cells[index] == 0) {
            cells[index] = 1;
        }else{
            cells[index] = 0;
        }
    }
    
        /*for(int i=0; i<size; i++){            
            int topmid = cells[i];
            int topleft = cells[topmid - 1];
            int topright = cells[topmid + 1];
            int left = cells[i - 1];
            int self = cells[i];
            int right = cells[i + 1];
            int botmid = cells[i];
            int botleft = cells[botmid - 1];
            int botright = cells[botmid + 1];

            cells_neighbour = {topleft, topmid, topright, left, right, botleft, botmid, botright};
            int countAlive = 0;
            int countDead = 0;
            for(int j=0; j<8; j++){
                if(cells_neighbour[j] == 0) countDead += 1;
                if(cells_neighbour[j] == 1) countAlive += 1;
            }
        }*/
    
}