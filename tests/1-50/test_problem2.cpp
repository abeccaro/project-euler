//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/2/problem2.hpp"

using problems::problem2;

TEST(Problem2, solution) {
    auto res = problem2::solve();
    EXPECT_EQ(res, 4613732);
}