//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../src/problems/1-50/20/problem20.hpp"

using problems::problem20;

TEST(Problem20, example) {
    auto res = problem20::solve(10);
    EXPECT_EQ(res, 27);
}

TEST(Problem20, solution) {
    auto res = problem20::solve();
    EXPECT_EQ(res, 648);
}