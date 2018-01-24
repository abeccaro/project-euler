//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/77/problem77.hpp"

using problems::problem77;

TEST(Problem77, example) {
    auto res = problem77::solve(4);
    EXPECT_EQ(res, 10);
}

TEST(Problem77, solution) {
    auto res = problem77::solve();
    EXPECT_EQ(res, 71);
}