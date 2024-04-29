#pragma once

class Grid
{
public:
    Grid(int _gridSize, int _numRow, int _numCol);
    void initialiseCells();
    int* copyCells(int* c);

    int* idx_1d_to_2d(int index);
    int idx_2d_to_1d(int ix, int iy);

    int gridWidth();
    int gridHeight();

    bool isOnBoard(int pos_x, int pos_y);

    void draw();
    void update();

private:
    int gridSize;
    int numRow;
    int numCol;

    int size;
    int* initial_cells;
    int* cells;
    int* new_cells;
};