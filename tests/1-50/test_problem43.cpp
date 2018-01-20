//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/43/problem43.hpp"

using problems::problem43;

TEST(Problem43, solution) {
    auto res = problem43::solve();
    EXPECT_EQ(res, 16695334890);
}