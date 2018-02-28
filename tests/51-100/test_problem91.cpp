//
// Created by Alex Beccaro on 28/02/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/91/problem91.hpp"

using problems::problem91;

TEST(Problem91, example) {
    auto res = problem91::solve(2, 2);
    EXPECT_EQ(res, 14);
}

TEST(Problem91, solution) {
    auto res = problem91::solve();
    EXPECT_EQ(res, 14234);
}