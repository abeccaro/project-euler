//
// Created by Alex Beccaro on 18/01/18.
//

#include <gtest/gtest.h>
#include "../../src/problems/51-100/70/problem70.hpp"

using problems::problem70;

TEST(Problem70, solution) {
    auto res = problem70::solve();
    EXPECT_EQ(res, 8319823);
}