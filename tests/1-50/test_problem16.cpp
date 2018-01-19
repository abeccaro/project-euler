//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/16/problem16.hpp"

using problems::problem16;

TEST(Problem16, example) {
    auto res = problem16::solve(15);
    EXPECT_EQ(res, 26);
}

TEST(Problem16, solution) {
    auto res = problem16::solve();
    EXPECT_EQ(res, 1366);
}