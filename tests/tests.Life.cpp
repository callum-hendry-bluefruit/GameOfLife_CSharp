#include "..\source\Life.h"
#include "gtest/gtest.h"
#include <cassert>
#include <iostream>

TEST(testLife, allocate_array_in_correct_size_and_initalise)
{
    int x = 5, y = 5;
    Life AllocateAndInitalise(y,x);

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
    char expected_dead = '.';
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(1, 1));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(1, 2));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(2, 1));
    EXPECT_EQ(expected_alive, EndResultTest.GetGridValue(2, 2));
}