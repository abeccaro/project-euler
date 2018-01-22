//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/74/problem74.hpp"

using problems::problem74;

TEST(Problem74, solution) {
    auto res = problem74::solve();
    EXPECT_EQ(res, 402);
}