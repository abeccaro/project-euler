//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/66/problem66.hpp"

using problems::problem66;

TEST(Problem66, example) {
    auto res = problem66::solve(7);
    EXPECT_EQ(res, 5);
}

TEST(Problem66, solution) {
    auto res = problem66::solve();
    EXPECT_EQ(res, 661);
}