//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/5/problem5.hpp"

using problems::problem5;

TEST(Problem5, example) {
    auto res = problem5::solve(10);
    EXPECT_EQ(res, 2520);
}

TEST(Problem5, solution) {
    auto res = problem5::solve();
    EXPECT_EQ(res, 232792560);
}