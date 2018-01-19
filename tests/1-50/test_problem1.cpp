//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/1/problem1.hpp"

using problems::problem1;

TEST(Problem1, example) {
    auto res = problem1::solve(10);
    EXPECT_EQ(res, 23);
}

TEST(Problem1, solution) {
    auto res = problem1::solve(1000);
    EXPECT_EQ(res, 233168);
}