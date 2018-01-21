//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/56/problem56.hpp"

using problems::problem56;

TEST(Problem56, solution) {
    auto res = problem56::solve();
    EXPECT_EQ(res, 972);
}