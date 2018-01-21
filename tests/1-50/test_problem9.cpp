//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/9/problem9.hpp"

using problems::problem9;

TEST(Problem9, example) {
    auto res = problem9::solve(12);
    EXPECT_EQ(res, 60);
}

TEST(Problem9, solution) {
    auto res = problem9::solve();
    EXPECT_EQ(res, 31875000);
}