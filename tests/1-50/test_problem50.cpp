//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/50/problem50.hpp"

using problems::problem50;

TEST(Problem50, example) {
    auto res = problem50::solve(100);
    EXPECT_EQ(res, 41);
}

TEST(Problem50, solution) {
    auto res = problem50::solve();
    EXPECT_EQ(res, 997651);
}