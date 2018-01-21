//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/4/problem4.hpp"

using problems::problem4;

TEST(Problem4, example) {
    auto res = problem4::solve(2);
    EXPECT_EQ(res, 9009);
}

TEST(Problem4, solution) {
    auto res = problem4::solve();
    EXPECT_EQ(res, 906609);
}