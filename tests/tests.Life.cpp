#include "..\source\Life.h"
#include "gtest/gtest.h"
#include <cassert>
#include <iostream>

class TestLife
{
public:
    void ManuallyToggleCellForTesting(int y, int x)
    {
        Life::ToggleCell(y, x);
    }
};

TEST(testLife, allocate_array_in_correct_size_and_initalise)
{
    int x = 5, y = 5, inital_state = 2;
    Life AllocateAndInitalise(y, x, inital_state);

    char expected = '.';

    EXPECT_EQ(expected, AllocateAndInitalise.GetGridValue((x - 1),(y - 1)));

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            EXPECT_EQ(expected, AllocateAndInitalise.GetGridValue(i, j));
        }
    }
}

TEST(testLife, end_result)
{
    int x = 5, y = 5;
    Life EndResultTest(y, x, true);
    EndResultTest.Start(1);

    char expected_alive = '*';
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(1, 1));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(1, 2));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(2, 1));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(2, 2));
}

TEST(testLife, end_result_2)
{
    int x = 5, y = 5, inital_state = 2;
    Life EndResultTest(y, x, inital_state);
    TestLife ToggleCellForTesting;

    ToggleCellForTesting.ManuallyToggleCellForTesting(4, 3);
    ToggleCellForTesting.ManuallyToggleCellForTesting(4, 4);
    ToggleCellForTesting.ManuallyToggleCellForTesting(3, 4);

    EndResultTest.Start(1);

    char expected_alive = '*';
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(4, 3));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(4, 4));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(3, 4));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(3, 3));
}

TEST(testLife, larger_grid)
{
    int x = 10, y = 10, initial_state = 2;
    Life EndResultTestWithLargerGrid(y, x, initial_state);
    TestLife ToggleCellForTesting;

    ToggleCellForTesting.ManuallyToggleCellForTesting(4, 3);
    ToggleCellForTesting.ManuallyToggleCellForTesting(4, 4);
    ToggleCellForTesting.ManuallyToggleCellForTesting(3, 4);

    EndResultTestWithLargerGrid.Start(1);

    char expected_alive = '*';
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(4, 3));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(4, 4));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(3, 4));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(3, 3));
}

TEST(testLife, larger_grid_edges)
{
    int x = 10, y = 10, initial_state = 2;
    Life EndResultTestWithLargerGrid(y, x, initial_state);
    TestLife ToggleCellForTesting;

    ToggleCellForTesting.ManuallyToggleCellForTesting(9, 3);
    ToggleCellForTesting.ManuallyToggleCellForTesting(9, 4);
    ToggleCellForTesting.ManuallyToggleCellForTesting(8, 4);
    ToggleCellForTesting.ManuallyToggleCellForTesting(8, 5);
    ToggleCellForTesting.ManuallyToggleCellForTesting(5, 2);
    ToggleCellForTesting.ManuallyToggleCellForTesting(4, 3);
    ToggleCellForTesting.ManuallyToggleCellForTesting(3, 4);

    char expected_alive = '*';

    EndResultTestWithLargerGrid.Start(1);
    
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(8, 3));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(9, 3));
    EXPECT_EQ(expected_alive, EndResultTestWithLargerGrid.GetGridValue(9, 4));
}

TEST(testLife, small_grid)
{//1x1?
    int x = 1, y = 1, initial_state = 2;
    Life EndResultTestWith1x1Grid(y, x, initial_state);
    TestLife ToggleCellForTesting;

    ToggleCellForTesting.ManuallyToggleCellForTesting(0, 0);

    EndResultTestWith1x1Grid.Start(1);

    char expected_dead = '.';
    EXPECT_EQ(expected_dead, EndResultTestWith1x1Grid.GetGridValue(0, 0));
}

TEST(testLife, rectangular_grid)
{
    int x = 8, y = 4, initial_state = 2;
    Life EndResultTestWithRectangularGrid(y, x, initial_state);
    TestLife ToggleCellForTesting;

    ToggleCellForTesting.ManuallyToggleCellForTesting(0, 0);
    ToggleCellForTesting.ManuallyToggleCellForTesting(0, 1);
    ToggleCellForTesting.ManuallyToggleCellForTesting(1, 0);

    ToggleCellForTesting.ManuallyToggleCellForTesting(3, 6);
    ToggleCellForTesting.ManuallyToggleCellForTesting(3, 7);
    ToggleCellForTesting.ManuallyToggleCellForTesting(2, 7);

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