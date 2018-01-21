//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/51/problem51.hpp"

using problems::problem51;

TEST(Problem51, solution) {
    auto res = problem51::solve();
    EXPECT_EQ(res, 121313);
}