//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/81/problem81.hpp"

using problems::problem81;

TEST(Problem81, solution) {
    auto res = problem81::solve();
    EXPECT_EQ(res, 427337);
}