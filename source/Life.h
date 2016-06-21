#ifndef LIFE_INCLUDED
#define LIFE_INCLUDED

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>

class Life
{
private:
    std::vector< std::vector<int> > m_life_grid;
    std::array<int, 8> m_current_surroundings;
    int m_size_x;
    int m_size_y;
    char m_scan_cells_current_location_contents;

    void InitaliseGrid();
    void ToggleCell(int y, int x);
    void InitalValues();
    void UserChosenStartLocations();

    int ReturnLiveNeighboursCount(int, int);

    bool ScanCells();
    bool CheckForOneOrLessLiveNeighbours(int, int);
    bool CheckForFourOrMoreLiveNeighbours(int, int);
    bool CheckForThreeLiveNeighboursIfDead(int, int);

public:
    Life(int y, int x, bool default_values = false); //Bool = true is to use default values
    ~Life();
    void Start(int num_of_generations = 1); //if no variable, assume 1 for testing purposes
    void PrintGrid();
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