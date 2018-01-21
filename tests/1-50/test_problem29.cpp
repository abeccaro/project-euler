//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/29/problem29.hpp"

using problems::problem29;

TEST(Problem29, example) {
    auto res = problem29::solve(5, 5);
    EXPECT_EQ(res, 15);
}

TEST(Problem29, solution) {
    auto res = problem29::solve();
    EXPECT_EQ(res, 9183);
}