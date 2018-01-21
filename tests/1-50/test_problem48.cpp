//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/48/problem48.hpp"

using problems::problem48;

TEST(Problem48, example) {
    auto res = problem48::solve(10);
    vector<uint> sol = {0, 4, 0, 5, 0, 7, 1, 3, 1, 7};
    EXPECT_EQ(res, sol);
}

TEST(Problem48, solution) {
    auto res = problem48::solve();
    vector<uint> sol = {9, 1, 1, 0, 8, 4, 6, 7, 0, 0};
    EXPECT_EQ(res, sol);
}