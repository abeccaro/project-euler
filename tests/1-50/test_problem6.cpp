//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/6/problem6.hpp"

using problems::problem6;

TEST(Problem6, example) {
    auto res = problem6::solve(10);
    EXPECT_EQ(res, 2640);
}

TEST(Problem6, solution) {
    auto res = problem6::solve();
    EXPECT_EQ(res, 25164150);
}