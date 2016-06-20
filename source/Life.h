#ifndef LIFE_INCLUDED
#define LIFE_INCLUDED

#include <iostream>
#include <vector>
#include <array>

class Life
{
private:
    std::vector< std::vector<int> > m_life_grid;
    int m_size_x;
    int m_size_y;
    char m_scan_cells_current_location_contents;

    void InitaliseGrid();
    void ToggleCell(int, int);
    void ScanCells();
    void CheckForOneOrLessLiveNeighbours();
    void CheckForFourOrMoreLiveNeighbours();
    void CheckForThreeLiveNeighboursIfDead();

public:
    Life(int, int);
    ~Life();
    void Start();
    char GetGridValue(int, int);
};

#endif

/*
1. Any live cell with fewer than two live neighbours
dies, as if caused by underpopulation.
2. Any live cell with more than three live neighbours
dies, as if by overcrowding.
3. Any live cell with two or three live neighbours
lives on to the next generation.
4. Any dead cell with exactly three live neighbours
becomes a live cell.
*/