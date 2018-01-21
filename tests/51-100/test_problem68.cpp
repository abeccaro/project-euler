//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/68/problem68.hpp"

using problems::problem68;

TEST(Problem68, solution) {
    auto res = problem68::solve();
    EXPECT_EQ(res.size(), 16);
    EXPECT_EQ(res, "6531031914842725");
}