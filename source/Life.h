#ifndef LIFE_INCLUDED
#define LIFE_INCLUDED

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include <chrono>
#include <thread>

class TestLife;

class Life
{
protected:
    friend class TestLife;
    static std::vector< std::vector<int> > m_life_grid;
    static void ToggleCell(int y, int x);

private:
    std::array<int, 8> m_current_surroundings;
    int m_size_x;
    int m_size_y;
    char m_scan_cells_current_location_contents;

    void InitaliseGrid();
    void InitalValues();
    void UserChosenStartLocations();

    int ReturnLiveNeighboursCount(int, int);

    bool ScanCells();
    bool CheckForOneOrLessLiveNeighbours(int, int);
    bool CheckForFourOrMoreLiveNeighbours(int, int);
    bool CheckForThreeLiveNeighboursIfDead(int, int);

public:
    Life(int y, int x, int initalisation_state = 1); //initalisation_state; 1 or not provided for default start cells; 0 for user chosen; anything else (preferably 2) for only dead cells
    ~Life();
    void Start(int num_of_generations = 1); //if no variable, assume 1 for testing purposes
    void PrintGrid();
    char GetGridValue(int, int);
};

static void waitForOneSecond()
{
    using namespace std::this_thread;
    using namespace std::chrono;
    sleep_until(system_clock::now() + milliseconds(1000));
}

#endif