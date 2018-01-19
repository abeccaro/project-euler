//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/25/problem25.hpp"

using problems::problem25;

TEST(Problem25, example) {
    auto res = problem25::solve(3);
    EXPECT_EQ(res, 12);
}

TEST(Problem25, solution) {
    auto res = problem25::solve();
    EXPECT_EQ(res, 4782);
}