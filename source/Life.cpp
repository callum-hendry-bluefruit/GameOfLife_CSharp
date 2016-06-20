#include "Life.h"

Life::Life(int size_y, int size_x)
{
    m_size_x = size_x;
    m_size_y = size_y;
    std::vector< std::vector< int > > temp_grid(m_size_x, std::vector<int>(m_size_y));
    m_life_grid = temp_grid;
    InitaliseGrid();
}

Life::~Life()
{

}

void Life::Start()
{

}

char Life::GetGridValue(int location_y, int location_x)
{
    return m_life_grid[location_y][location_x];
}

void Life::InitaliseGrid()
{
    for (int i = 0; i < m_size_y; i++)
    {
        for (int j = 0; j < m_size_x; j++)
        {
            m_life_grid[i][j] = '.';
        }
    }
}

void Life::ToggleCell(int y, int x)
{
    if (m_life_grid[y][x] == '.')
    {
        m_life_grid[y][x] = '*';
    }
    else
    {
        m_life_grid[y][x] = '.';
    }
}

void Life::ScanCells()
{
    //Not yet implemented; uncomment when testing class and variables are implemented
    /*if (test_mode == true)
    {

    }
    else
    {
        for (int i = 0; i < m_size_y; i++)
        {
            for (int j = 0; j < m_size_x; j++)
            {

            }
        }
    }*/
}

void Life::CheckForOneOrLessLiveNeighbours()
{

}

void Life::CheckForFourOrMoreLiveNeighbours()
{

}

void Life::CheckForThreeLiveNeighboursIfDead()
{

}