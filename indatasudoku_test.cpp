#include"datasudoku.h"
#include"constraint.h"
#include <bits/stdc++.h>

using namespace std;
#include "sudoku.cpp"
#include <gtest/gtest.h>

using namespace std;

TEST(sudoku,DefaultConstructor) {
    sudoku<int> stest;
    EXPECT_EQ(0,stest.getrow());
    EXPECT_EQ(0,stest.getcol());
}
int main(int argc, char **argv) 
    {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    }
