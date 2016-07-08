#ifndef LIFE_INCLUDED
#define LIFE_INCLUDED

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <chrono>
#include <thread>

class Grid
{
protected:
    std::vector< std::vector<int>> m_grid;

private:
    void InitaliseGrid();
    void PrintGrid();
    int m_size_y;
    int m_size_x;
public:
    Grid(int size_y, int size_x);

    std::vector< std::vector<int>> return_grid();

    char GetGridValue(int y, int x);
    int GetSizeY();
    int GetSizeX();
    
    void ToggleCell(int y, int x);
    void UserChosenStartLocations();
};



class Life
{
protected:
    std::vector< std::vector<int> > m_life_grid;
    std::vector< std::vector<int> > m_staging_grid;
    void ToggleCell(int y, int x);

private:
    std::array<int, 8> m_current_surroundings;
    int m_size_x;
    int m_size_y;
    char m_scan_cells_current_location_contents;

    void InitaliseGrid();
    void InitalValues();
    void StagingToActual();

    int ReturnLiveNeighboursCount(int, int);

    bool ScanCells();
    bool CheckForOneOrLessLiveNeighbours(int, int);
    bool CheckForFourOrMoreLiveNeighbours(int, int);
    bool CheckForThreeLiveNeighboursIfDead(int, int);

public:
    Life(std::vector< std::vector<int> >, int size_y, int size_x);
    ~Life();
    void Start(int num_of_generations = 1); //if no variable, assume 1 for testing purposes
    void PrintGrid();
    void PrintStagingGrid();
    char GetGridValue(int, int);
    char GetStagingGridValue(int, int);
};

static void waitForOneSecond()
{
    using namespace std::this_thread;
    using namespace std::chrono;
    sleep_until(system_clock::now() + milliseconds(500));
}

#endif