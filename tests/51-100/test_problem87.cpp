//
// Created by Alex Beccaro on 26/02/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/87/problem87.hpp"

using problems::problem87;

TEST(Problem87, example) {
    auto res = problem87::solve(50);
    EXPECT_EQ(res, 4);
}

TEST(Problem87, solution) {
    auto res = problem87::solve();
    EXPECT_EQ(res, 1097343);
}