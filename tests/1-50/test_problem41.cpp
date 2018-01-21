//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/41/problem41.hpp"

using problems::problem41;

TEST(Problem41, solution) {
    auto res = problem41::solve();
    EXPECT_EQ(res, 7652413);
}