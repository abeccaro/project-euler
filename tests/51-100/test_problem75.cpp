//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/75/problem75.hpp"

using problems::problem75;

TEST(Problem75, example) {
    auto res = problem75::solve(48);
    EXPECT_EQ(res, 6);
}

TEST(Problem75, solution) {
    auto res = problem75::solve();
    EXPECT_EQ(res, 161667);
}