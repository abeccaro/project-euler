//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/34/problem34.hpp"

using problems::problem34;

TEST(Problem34, solution) {
    auto res = problem34::solve();
    EXPECT_EQ(res, 40730);
}