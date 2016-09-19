using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameOfLifeSharp
{
    public class Grid
    {
        //Private
        private char[,] m_grid;

        private int m_size_y;
        private int m_size_x;

        private void InitaliseGrid()
        {
            for (int i = 0; i < m_size_y; i++)
            {
                for (int j = 0; j < m_size_x; j++)
                {
                    m_grid[i,j] = '.';
                }
            }
        }

        private void PrintGrid()
        {
            for (int i = 0; i < m_size_y; i++)
            {
                Console.WriteLine("|");
                for (int j = 0; j < m_size_x; j++)
                {
                    if (m_grid[i,j] == '.')
                    {
                        Console.Write(' ');
                        Console.WriteLine('|');
                    }
                    else
                    {
                        Console.Write('*');
                        Console.WriteLine('|');
                    }
                }
                Console.WriteLine();
            }
        }

        //Public
        public Grid(int size_y, int size_x)
        {
            m_size_y = size_y;
            m_size_x = size_x;

            char[,] temp_grid = new char[size_y, size_x];
            m_grid = temp_grid;

            InitaliseGrid();
        }

        ~Grid()
        {

        }

        public char[,] ReturnGrid()
        {
            return m_grid;
        }

        public char GetGridValue(int y, int x)
        {
            return m_grid[y,x];
        }

        public int GetSizeY()
        {
            return m_size_y;
        }

        public int GetSizeX()
        {
            return m_size_x;
        }

        public void ToggleCell(int y, int x)
        {
            if (m_grid[y, x] == '.')
            {
                m_grid[y, x] = '*';
            }
            else
            {
                m_grid[y, x] = '.';
            }
        }

        public void UserChosenStartLocations()
        {
            int y, x;
            Console.WriteLine();
            Console.WriteLine("User Inputted Starting Cells");
            Console.WriteLine("----------------------------");
            for (;;)
            {
                try
                {
                    Console.WriteLine("Enter a Y and a X coordinate to toggle the cell");
                    Console.WriteLine("Enter a character to exit");

                    Console.Write("Y: ");
                    string y_preconversion;
                    y_preconversion = Console.ReadLine();
                    Console.WriteLine();

                    if (y_preconversion != "0" || y_preconversion != "1" || y_preconversion != "2" ||
                        y_preconversion != "3" || y_preconversion != "4" || y_preconversion != "5" ||
                        y_preconversion != "6" || y_preconversion != "7" || y_preconversion != "8" ||
                        y_preconversion != "9")
                    {
                        throw new FormatException();
                    }

                    y = Int32.Parse(y_preconversion);

                    Console.Write("X: ");
                    string x_preconversion;
                    x_preconversion = Console.ReadLine();
                    Console.WriteLine();

                    if (x_preconversion != "0" || x_preconversion != "1" || x_preconversion != "2" ||
                        x_preconversion != "3" || x_preconversion != "4" || x_preconversion != "5" ||
                        x_preconversion != "6" || x_preconversion != "7" || x_preconversion != "8" ||
                        x_preconversion != "9")
                    { //Horrid, refactor to something better. Convert from string to int before checking value is within confines of grid?
                        throw new FormatException();
                    }

                    x = Int32.Parse(x_preconversion);

                    if (y >= m_size_y || y < 0 || x >= m_size_x || x < 0)
                    {
                        throw new OverflowException();
                    }

                    ToggleCell(y, x);
                    Console.WriteLine("Current Grid: ");
                    PrintGrid();
                }
                catch (OverflowException)
                {
                    Console.WriteLine("Out of Range Error. Please enter number equal to or less than: ");
                    Console.Write("Y: ");
                    Console.WriteLine((m_size_y - 1));
                    Console.Write("X: ");
                    Console.WriteLine((m_size_x - 1));
                    Console.WriteLine("But equal or more than 0");
                }
                catch (FormatException)
                {
                    Console.WriteLine("Invalid character was entered");
                    Console.WriteLine("Finished entering custom start locations?");

                    Console.Write("Y/N?  > ");
                    char input = (char)Console.Read();

                    if (input == 'Y' || input == 'y')
                    {
                        break;
                    }
                    else if (input == 'N' || input == 'n')
                    {

                    }
                    else
                    {
                        throw new FormatException();
                    }
                }
            }
        }

    }

    public class Life
    {
        //Private
        private char[,] m_life_grid;
        private char[,] m_staging_grid;
        private void ToggleCell(int y, int x)
        {//Toggles cell in both life and staging grids? wtf? Something to do with the inital StagingToActual() setting up some sort of link between the two so they get mirrored?
            if (m_life_grid[y, x] == '.')
            {
                m_staging_grid[y, x] = '*';
            }
            else
            {
                m_staging_grid[y, x] = '.';
            }
        }

        private char[] m_current_surroundings = new char [8];
        private int m_size_x;
        private int m_size_y;
        
        private void StagingToActual()
        {
            Array.Copy(m_staging_grid, m_life_grid, (m_size_x * m_size_y));
        }

        private int ReturnLiveNeighboursCount(int y, int x)
        {
            for (int i = 0; i < 8; i++)
            {
                m_current_surroundings[i] = '.';
            }

            if ((y - 1) >= 0)
            { //Up
                m_current_surroundings[0] = m_life_grid[(y - 1), x];
            }

            if ((y + 1) <= (m_size_y - 1))
            { //Down
                m_current_surroundings[1] = m_life_grid[(y + 1), x];
            }

            if ((x - 1) >= 0)
            { //Left
                m_current_surroundings[2] = m_life_grid[y, (x - 1)];
            }

            if ((x + 1) <= (m_size_x - 1))
            { //Right
                m_current_surroundings[3] = m_life_grid[y, (x + 1)];
            }

            if (((y - 1) >= 0) && ((x - 1) >= 0))
            { //Up-left
                m_current_surroundings[4] = m_life_grid[(y - 1), (x - 1)];
            }

            if (((y + 1) <= (m_size_y - 1)) && ((x - 1) >= 0))
            { //Down-left
                m_current_surroundings[5] = m_life_grid[(y + 1), (x - 1)];
            }

            if (((y - 1) >= 0) && ((x + 1) <= (m_size_x - 1)))
            { //Up-right
                m_current_surroundings[6] = m_life_grid[(y - 1), (x + 1)];
            }

            if (((y + 1) <= (m_size_y - 1)) && ((x + 1) <= (m_size_x - 1)))
            { //Down-right
                m_current_surroundings[7] = m_life_grid[(y + 1), (x + 1)];
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

        private bool ScanCells()
        {
            bool change_made = false;

            for (int i = 0; i < m_size_y; i++)
            {
                for (int j = 0; j < m_size_x; j++)
                {
                    if (m_life_grid[i, j] == '*')
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

        private bool CheckForOneOrLessLiveNeighbours(int y, int x)
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

        private bool CheckForFourOrMoreLiveNeighbours(int y, int x)
        {
            int live_neighbours_count = ReturnLiveNeighboursCount(y, x);
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

        private bool CheckForThreeLiveNeighboursIfDead(int y, int x)
        {
            int live_neighbours_count = ReturnLiveNeighboursCount(y, x);
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

        private void WaitForHalfSecond()
        {
            System.Threading.Thread.Sleep(500);
        }


        //Public
        public Life(char[,] temp_grid, int size_y, int size_x)
        {
            m_size_x = size_x;
            m_size_y = size_y;

            m_staging_grid = temp_grid;
            m_life_grid = new char[m_size_y, m_size_x];
            StagingToActual();
        }

         ~Life()
        {

        }

        public void Start(int number_of_loops)
        {
            int number_of_generations = 0;

            Console.Clear();
            PrintGrid();
            WaitForHalfSecond();

            if (number_of_loops == 0)
            {
                while (ScanCells() == true)
                {
                    number_of_generations += 1;

                    Console.Clear();
                    PrintGrid();
                    Console.WriteLine();
                    Console.Write("Number of generations: ");
                    Console.WriteLine(number_of_generations);
                    WaitForHalfSecond();
                }
                Console.WriteLine();
                Console.WriteLine("Simulation stopped; end of possible generations");
                Console.Write("Number of generations: ");
                Console.WriteLine(number_of_generations);
                return;
            }
            else
            {
                for (int i = 0; i < number_of_loops; i++)
                {
                    if (ScanCells() == true)
                    {
                        number_of_generations += 1;

                        Console.Clear();
                        PrintGrid();
                        Console.WriteLine();
                        Console.Write("Number of generations: ");
                        Console.WriteLine(number_of_generations);
                        WaitForHalfSecond();
                    }


                    Console.Clear();
                    PrintGrid();
                    Console.WriteLine();
                    Console.WriteLine("Simulation stopped; end of possible generations");
                    Console.Write("Number of generations: ");
                    Console.WriteLine(number_of_generations);
                    return;
                }
            }
        }
        public void PrintGrid()
        {
            for (int i = 0; i < m_size_y; i++)
            {
                Console.WriteLine("|");
                for (int j = 0; j < m_size_x; j++)
                {
                    if (m_life_grid[i, j] == '.')
                    {
                        Console.Write(' ');
                        Console.WriteLine('|');
                    }
                    else
                    {
                        Console.Write('*');
                        Console.WriteLine('|');
                    }
                }
                Console.WriteLine();
            }
        }

        public void PrintStagingGrid()
        {
            for (int i = 0; i < m_size_y; i++)
            {
                Console.WriteLine("|");
                for (int j = 0; j < m_size_x; j++)
                {
                    if (m_staging_grid[i, j] == '.')
                    {
                        Console.Write(' ');
                        Console.WriteLine('|');
                    }
                    else
                    {
                        Console.Write('*');
                        Console.WriteLine('|');
                    }
                }
                Console.WriteLine();
            }
        }

        public char GetGridValue(int y, int x)
        {
            return m_life_grid[y, x];
        }

        public char GetStagingGridValue(int y, int x)
        {
            return m_staging_grid[y, x];
        }
    }
}
