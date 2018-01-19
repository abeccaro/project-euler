//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../src/problems/1-50/12/problem12.hpp"

using problems::problem12;

TEST(Problem12, example) {
    auto res = problem12::solve(5);
    EXPECT_EQ(res, 28);
}

TEST(Problem12, solution) {
    auto res = problem12::solve();
    EXPECT_EQ(res, 76576500);
}