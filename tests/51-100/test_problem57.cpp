//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/57/problem57.hpp"

using problems::problem57;

TEST(Problem57, example) {
    auto res7 = problem57::solve(7);
    EXPECT_EQ(res7, 0);
    auto res8 = problem57::solve(8);
    EXPECT_EQ(res8, 1);
}

TEST(Problem57, solution) {
    auto res = problem57::solve();
    EXPECT_EQ(res, 153);
}