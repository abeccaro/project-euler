//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/45/problem45.hpp"

using problems::problem45;

TEST(Problem45, example) {
    auto res = problem45::solve(2);
    EXPECT_EQ(res, 40755);
}

TEST(Problem45, solution) {
    auto res = problem45::solve();
    EXPECT_EQ(res, 1533776805);
}