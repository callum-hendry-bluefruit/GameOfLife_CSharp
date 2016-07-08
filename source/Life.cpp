#include "Life.h"

Life::Life(std::vector< std::vector<int>> temp_grid, int size_y, int size_x)
{
    m_size_x = size_x;
    m_size_y = size_y;

    m_staging_grid = temp_grid;
    StagingToActual();
}

Life::~Life()
{

}

void Life::Start(int number_of_loops)
{   
    int number_of_generations = 0;

    system("cls");
    PrintGrid();
    waitForOneSecond();

    if (number_of_loops == 0)
    {
        while (ScanCells() == true)
        {
            number_of_generations += 1;

            system("cls");
            PrintGrid();
            std::cout << std::endl;
            std::cout << "Number of generations: " << number_of_generations << std::endl;
            waitForOneSecond();
        }
        std::cout << std::endl;
        std::cout << "Simulation stopped; end of possible generations" << std::endl;
        std::cout << "Number of generations: " << number_of_generations << std::endl;
        return;
    }
    else
    {
        for (int i = 0; i < number_of_loops; i++)
        {
            if (ScanCells() == true)
            {
                number_of_generations += 1;

                system("cls");
                PrintGrid();
                std::cout << std::endl;
                std::cout << "Number of generations: " << number_of_generations << std::endl;
                waitForOneSecond();
            }


            system("cls");
            PrintGrid();
            std::cout << std::endl;
            std::cout << "Simulation stopped; end of possible generations" << std::endl;
            std::cout << "Number of generations: " << number_of_generations << std::endl;
            return;
        }
    }
}

char Life::GetGridValue(int location_y, int location_x)
{
    return m_life_grid[location_y][location_x];
}

char Life::GetStagingGridValue(int location_y, int location_x)
{
    return m_staging_grid[location_y][location_x];
}

void Life::ToggleCell(int y, int x)
{
    if (m_life_grid[y][x] == '.')
    {
        m_staging_grid[y][x] = '*';
    }
    else
    {
        m_staging_grid[y][x] = '.';
    }
}

bool Life::ScanCells()
{
    bool change_made = false;
    
    for (int i = 0; i < m_size_y; i++)
    {
        for (int j = 0; j < m_size_x; j++)
        {
            if (m_life_grid[i][j] == '*')
            {
                if (CheckForOneOrLessLiveNeighbours(i, j) == true)
                {
                    change_made = true;
                }

                if (CheckForFourOrMoreLiveNeighbours(i, j) == true)
                {
                    change_made = true;
                }
            }
            else
            {
                if (CheckForThreeLiveNeighboursIfDead(i, j) == true)
                {
                    change_made = true;
                }
            }
        }
    }

    StagingToActual();

    if (change_made == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Life::CheckForOneOrLessLiveNeighbours(int y, int x)
{
    int live_neighbours_count = ReturnLiveNeighboursCount(y, x);
    if (live_neighbours_count <= 1)
    {
        ToggleCell(y, x);
        return true;
    }
    else
    {
        return false;
    }
}

bool Life::CheckForFourOrMoreLiveNeighbours(int y, int x)
{
    ReturnLiveNeighboursCount(y, x);
    int live_neighbours_count = 0;
    for (int i = 0; i < 8; i++)
    {
        if (m_current_surroundings[i] == '*')
        {
            live_neighbours_count += 1;
        }
    }
    if (live_neighbours_count >= 4)
    {
        ToggleCell(y, x);
        return true;
    }
    else
    {
        return false;
    }
}

bool Life::CheckForThreeLiveNeighboursIfDead(int y, int x)
{
    ReturnLiveNeighboursCount(y, x);
    int live_neighbours_count = 0;
    for (int i = 0; i < 8; i++)
    {
        if (m_current_surroundings[i] == '*')
        {
            live_neighbours_count += 1;
        }
    }
    if (live_neighbours_count == 3)
    {
        ToggleCell(y, x);
        return true;
    }
    else
    {
        return false;
    }
}

int Life::ReturnLiveNeighboursCount(int y, int x)
{
    for (int i = 0; i < 8; i++)
    {
        m_current_surroundings[i] = '.';
    }

    if ((y - 1) >= 0)
    { //Up
        m_current_surroundings[0] = m_life_grid[(y - 1)][x];
    }

    if ((y + 1) <= (m_size_y - 1))
    { //Down
        m_current_surroundings[1] = m_life_grid[(y + 1)][x];
    }

    if ((x - 1) >= 0)
    { //Left
        m_current_surroundings[2] = m_life_grid[y][(x - 1)];
    }

    if ((x + 1) <= (m_size_x - 1))
    { //Right
        m_current_surroundings[3] = m_life_grid[y][(x + 1)];
    }

    if (((y - 1) >= 0) && ((x - 1) >= 0))
    { //Up-left
        m_current_surroundings[4] = m_life_grid[(y - 1)][(x - 1)];
    }

    if (((y + 1) <= (m_size_y - 1)) && ((x - 1) >= 0))
    { //Down-left
        m_current_surroundings[5] = m_life_grid[(y + 1)][(x - 1)];
    }

    if (((y - 1) >= 0) && ((x + 1) <= (m_size_x - 1)))
    { //Up-right
        m_current_surroundings[6] = m_life_grid[(y - 1)][(x + 1)];
    }

    if (((y + 1) <= (m_size_y - 1)) && ((x + 1) <= (m_size_x - 1)))
    { //Down-right
        m_current_surroundings[7] = m_life_grid[(y + 1)][(x + 1)];
    }

    int live_neighbours_count = 0;
    for (int i = 0; i < 8; i++)
    {
        if (m_current_surroundings[i] == '*')
        {
            live_neighbours_count += 1;
        }
    }
    return live_neighbours_count;
}

void Life::PrintGrid()
{
    using namespace std;
    for (int i = 0; i < m_size_y; i++)
    {
        cout << '|';
        for (int j = 0; j < m_size_x; j++)
        {
            if (m_life_grid[i][j] == '.')
            {
                cout << ' ' << '|';
            }
            else
            {
                cout << '*' << '|';
            }
        }
        cout << endl;
    }
}

void Life::PrintStagingGrid()
{
    using namespace std;
    for (int i = 0; i < m_size_y; i++)
    {
        cout << '|';
        for (int j = 0; j < m_size_x; j++)
        {
            if (m_staging_grid[i][j] == '.')
            {
                cout << ' ' << '|';
            }
            else
            {
                cout << '*' << '|';
            }
        }
        cout << endl;
    }
}

void Life::StagingToActual()
{
    m_life_grid = m_staging_grid;
}

//Above Life
//Below Grid

Grid::Grid(int size_y, int size_x)
{
    m_size_y = size_y;
    m_size_x = size_x;
    
    std::vector< std::vector< int > > temp_grid(size_y, std::vector<int>(size_x));
    m_grid = temp_grid;

    InitaliseGrid();
}

void Grid::InitaliseGrid()
{
    for (int i = 0; i < m_size_y; i++)
    {
        for (int j = 0; j < m_size_x; j++)
        {
            m_grid[i][j] = '.';
        }
    }
}

std::vector< std::vector<int>> Grid::return_grid()
{
    return m_grid;
}

char Grid::GetGridValue(int y, int x)
{
    return m_grid[y][x];
}

int Grid::GetSizeY()
{
    return m_size_y;
}

int Grid::GetSizeX()
{
    return m_size_x;
}

void Grid::ToggleCell(int y, int x)
{
    if (m_grid[y][x] == '.')
    {
        m_grid[y][x] = '*';
    }
    else
    {
        m_grid[y][x] = '.';
    }
}

void Grid::UserChosenStartLocations()
{
    using namespace std;
    int y, x;
    cout << endl;
    cout << "User Inputted Starting Cells" << endl;
    cout << "----------------------------" << endl;
    for (;;)
    {
        try
        {
            cout << "Enter a Y and a X coordinate to toggle the cell" << endl;
            cout << "Enter a character to exit" << endl;

            cout << "Y: ";
            string y_preconversion;
            cin >> y_preconversion;
            cout << endl;
            y = stoi(y_preconversion);

            cout << "X: ";
            string x_preconversion;
            cin >> x_preconversion;
            cout << endl;
            x = stoi(x_preconversion);

            if (y >= m_size_y || y < 0 || x >= m_size_x || x < 0)
            {
                throw out_of_range("");
            }

            ToggleCell(y, x);
            cout << "Current Grid: " << endl;
            PrintGrid();
        }
        catch (out_of_range)
        {
            cerr << "Out of Range Error. Please enter number equal to or less than: " << endl;
            cout << "Y: " << (m_size_y - 1) << endl;
            cout << "X: " << (m_size_x - 1) << endl;
            cout << "But equal or more than 0" << endl;
        }
        catch (invalid_argument)
        {
            cerr << "Invalid character was entered" << " " << endl;
            cout << "Finished entering custom start locations?" << endl;

            cout << "Y/N?" << "  > ";
            char input;
            cin >> input;

            if (input == 'Y' || input == 'y')
            {
                break;
            }
            else if (input == 'N' || input == 'n')
            {

            }
            else
            {
                throw invalid_argument("");
            }
        }
    }
}

void Grid::PrintGrid()
{
    using namespace std;
    for (int i = 0; i < m_size_y; i++)
    {
        cout << '|';
        for (int j = 0; j < m_size_x; j++)
        {
            if (m_grid[i][j] == '.')
            {
                cout << ' ' << '|';
            }
            else
            {
                cout << '*' << '|';
            }
        }
        cout << endl;
    }
}