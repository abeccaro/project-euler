//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/76/problem76.hpp"

using problems::problem76;

TEST(Problem76, example) {
    auto res = problem76::solve(5);
    EXPECT_EQ(res, 6);
}

TEST(Problem76, solution) {
    auto res = problem76::solve();
    EXPECT_EQ(res, 190569291);
}