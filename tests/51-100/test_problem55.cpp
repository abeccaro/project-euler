//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/55/problem55.hpp"

using problems::problem55;

TEST(Problem55, solution) {
    auto res = problem55::solve();
    EXPECT_EQ(res, 249);
}