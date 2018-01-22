//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/73/problem73.hpp"

using problems::problem73;

TEST(Problem73, example) {
    auto res = problem73::solve(8);
    EXPECT_EQ(res, 3);
}

TEST(Problem73, solution) {
    auto res = problem73::solve();
    EXPECT_EQ(res, 7295372);
}