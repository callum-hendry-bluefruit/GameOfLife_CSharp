#include "..\source\Life.h"
#include "gtest/gtest.h"
#include <cassert>
#include <iostream>

extern bool test_mode;

TEST(testLife, allocate_array_in_correct_size_and_initalise)
{
    int x = 5, y = 5;
    Life AllocateAndInitalise(x,y);

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