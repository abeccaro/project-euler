//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/71/problem71.hpp"

using problems::problem71;

TEST(Problem71, example) {
    auto res = problem71::solve(8);
    EXPECT_EQ(res, 2);
}

TEST(Problem71, solution) {
    auto res = problem71::solve();
    EXPECT_EQ(res, 428570);
}