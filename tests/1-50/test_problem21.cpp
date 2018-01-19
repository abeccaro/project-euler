//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/21/problem21.hpp"

using problems::problem21;

TEST(Problem21, solution) {
    auto res = problem21::solve();
    EXPECT_EQ(res, 31626);
}