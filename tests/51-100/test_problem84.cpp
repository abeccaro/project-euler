//
// Created by Alex Beccaro on 25/02/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/84/problem84.hpp"

using problems::problem84;

TEST(Problem84, example) {
    auto res = problem84::solve(6);
    EXPECT_EQ(res, "102400");
}

TEST(Problem84, solution) {
    auto res = problem84::solve();
    EXPECT_EQ(res, "101524");
}