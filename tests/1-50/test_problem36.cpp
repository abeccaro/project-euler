//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/36/problem36.hpp"

using problems::problem36;

TEST(Problem36, solution) {
    auto res = problem36::solve();
    EXPECT_EQ(res, 872187);
}