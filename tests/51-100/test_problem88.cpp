//
// Created by Alex Beccaro on 27/02/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/88/problem88.hpp"

using problems::problem88;

TEST(Problem88, example1) {
    auto res = problem88::solve(6);
    EXPECT_EQ(res, 30);
}

TEST(Problem88, example2) {
    auto res = problem88::solve(12);
    EXPECT_EQ(res, 61);
}

TEST(Problem88, solution) {
    auto res = problem88::solve();
    EXPECT_EQ(res, 7587457);
}