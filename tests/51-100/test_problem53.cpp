//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/53/problem53.hpp"

using problems::problem53;

TEST(Problem53, example) {
    auto res22 = problem53::solve(22);
    EXPECT_EQ(res22, 0);
    auto res23 = problem53::solve(23);
    EXPECT_GT(res23, 0);
}

TEST(Problem53, solution) {
    auto res = problem53::solve();
    EXPECT_EQ(res, 4075);
}