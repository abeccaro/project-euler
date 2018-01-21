//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/30/problem30.hpp"

using problems::problem30;

TEST(Problem30, example) {
    auto res = problem30::solve(4);
    EXPECT_EQ(res, 19316);
}

TEST(Problem30, solution) {
    auto res = problem30::solve();
    EXPECT_EQ(res, 443839);
}