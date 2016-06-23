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

/*TEST(testLife, larger_grid)
{

}*/

/*TEST(testLife, small_grid)
{//1x1?

}*/

/*TEST(testLife, rectangular_grid)
{

}*/