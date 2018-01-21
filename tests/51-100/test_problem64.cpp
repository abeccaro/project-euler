//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/64/problem64.hpp"

using problems::problem64;

TEST(Problem64, example) {
    auto res = problem64::solve(13);
    EXPECT_EQ(res, 4);
}

TEST(Problem64, solution) {
    auto res = problem64::solve();
    EXPECT_EQ(res, 1322);
}