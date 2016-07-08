#include "..\source\Life.h"
#include "gtest/gtest.h"
#include <cassert>
#include <iostream>

TEST(testLife, allocate_array_in_correct_size_and_initalise)
{
    int x = 5, y = 5;

    Grid GameGrid(y, x);

    char expected = '.';

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            EXPECT_EQ(expected, GameGrid.GetGridValue(i, j));
        }
    }
}

TEST(testLife, end_result)
{
    int x = 5, y = 5;

    Grid GameGrid(y, x);
    GameGrid.ToggleCell(1, 1);
    GameGrid.ToggleCell(1, 2);
    GameGrid.ToggleCell(2, 1);

    Life EndResultTest(GameGrid.return_grid(), y, x);

    EndResultTest.Start(1);

    char expected_alive = '*';
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(1, 1));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(1, 2));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(2, 1));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(2, 2));
}

TEST(testLife, end_result_2)
{
    int x = 5, y = 5;
    Grid GameGrid(y, x);
    
    GameGrid.ToggleCell(4, 3);
    GameGrid.ToggleCell(4, 4);
    GameGrid.ToggleCell(3, 4);

    Life EndResultTest(GameGrid.return_grid(), y, x);
    EndResultTest.Start(1);

    char expected_alive = '*';
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(4, 3));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(4, 4));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(3, 4));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(3, 3));
}

TEST(testLife, larger_grid)
{
    int x = 10, y = 10;
    Grid GameGrid(y, x);

    GameGrid.ToggleCell(4, 3);
    GameGrid.ToggleCell(4, 4);
    GameGrid.ToggleCell(3, 4);

    Life EndResultTestWithLargerGrid(GameGrid.return_grid(), y, x);
    EndResultTestWithLargerGrid.Start(1);

    char expected_alive = '*';
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(4, 3));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(4, 4));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(3, 4));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(3, 3));
}

TEST(testLife, larger_grid_edges)
{
    int x = 10, y = 10;
    Grid GameGrid(y, x);

    GameGrid.ToggleCell(9, 3);
    GameGrid.ToggleCell(9, 4);
    GameGrid.ToggleCell(8, 4);
    GameGrid.ToggleCell(8, 5);
    GameGrid.ToggleCell(5, 2);
    GameGrid.ToggleCell(4, 3);
    GameGrid.ToggleCell(3, 4);

    Life EndResultTestWithLargerGrid(GameGrid.return_grid(), y, x);
    char expected_alive = '*';

    EndResultTestWithLargerGrid.Start(1);
    
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(4, 3));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(8, 3));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(8, 4));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(8, 5));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(9, 3));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(9, 4));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(9, 5));
}

TEST(testLife, small_grid)
{//1x1?
    int x = 1, y = 1;
    Grid GameGrid(y, x);

    GameGrid.ToggleCell(0, 0);
    Life EndResultTestWith1x1Grid(GameGrid.return_grid(), y, x);

    EndResultTestWith1x1Grid.Start(1);

    char expected_dead = '.';
    EXPECT_EQ(expected_dead, EndResultTestWith1x1Grid.GetGridValue(0, 0));
}

TEST(testLife, rectangular_grid)
{
    int x = 8, y = 4;
    Grid GameGrid(y, x);
    
    GameGrid.ToggleCell(0, 0);
    GameGrid.ToggleCell(0, 1);
    GameGrid.ToggleCell(1, 0);

    GameGrid.ToggleCell(3, 6);
    GameGrid.ToggleCell(3, 7);
    GameGrid.ToggleCell(2, 7);

    Life EndResultTestWithRectangularGrid(GameGrid.return_grid(), y, x);
    EndResultTestWithRectangularGrid.Start(1);

    char expected_alive = '*';
    EXPECT_EQ(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(0, 0));
    EXPECT_EQ(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(0, 1));
    EXPECT_EQ(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(1, 0));
    EXPECT_EQ(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(1, 1));

    EXPECT_EQ(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(3, 6));
    EXPECT_EQ(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(3, 7));
    EXPECT_EQ(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(2, 7));
    EXPECT_EQ(expected_alive, EndResultTestWithRectangularGrid.GetGridValue(2, 6));
}