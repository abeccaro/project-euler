//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/67/problem67.hpp"

using problems::problem67;

TEST(Problem67, solution) {
    auto res = problem67::solve();
    EXPECT_EQ(res, 7273);
}