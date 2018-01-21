//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/1-50/27/problem27.hpp"

using problems::problem27;

TEST(Problem27, solution) {
    auto res = problem27::solve();
    EXPECT_EQ(res, -59231);
}